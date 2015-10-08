(function(_log, _info, _warn, _error, _assert, _exists, _loadContent, _execute, _modified, _path, _v8Version, _fhVersion) {
    "use strict";

    let console = {};
    let v8 = {};
    let flathead = {};

    let Paths = _path.split(';');

    let global = this;

    function _getRandomIndex() {
        return Math.floor(Math.random() * 10000);
    }

    let timersMap = new Map();
    let moduleCache = new Map();

    let defineSystemProperty = (obj, prop, value) => {
        Object.defineProperty(obj, prop, {
            value: value,
            writable: false,
            enumerable: false,
            configurable: false
        });
    };

    defineSystemProperty(console, 'log', _log);
    defineSystemProperty(console, 'info', _info);
    defineSystemProperty(console, 'warn', _warn);
    defineSystemProperty(console, 'error', _error);
    defineSystemProperty(console, 'assert', _assert);
    defineSystemProperty(console, 'trace', function() {
        let err = new Error();

        this.log(err.stack);
    });
    defineSystemProperty(console, 'count', (function() {
        let countInventory = new Map();

        return function(label) {

            if (!countInventory[label]) {
                countInventory[label] = 0;
            }

            countInventory[label]++;

            this.info(label + ": " + countInventory[label]);
        }
    })());

    defineSystemProperty(global, 'console', console);

    defineSystemProperty(v8, 'version', _v8Version);
    defineSystemProperty(global, 'v8', v8);

    defineSystemProperty(flathead, 'version', _fhVersion);
    defineSystemProperty(global, 'flathead', flathead);

    defineSystemProperty(global, 'setTimeout', function(func, timeout) {
        let ndx = _getRandomIndex();

        timersMap.set(ndx, {
            func: func,
            timeout: timeout,
            reset: 0
        });
    });
    defineSystemProperty(global, 'clearTimeout', function(id) {
        delete timersMap.delete(id);
    });
    defineSystemProperty(global, 'setInterval', function(func, interval) {
        let ndx = _getRandomIndex();

        timersMap.set(ndx, {
            func: func,
            timeout: interval,
            reset: interval
        });
    });
    defineSystemProperty(global, 'clearInterval', function(id) {
        delete timersMap.delete(id);
    });

    let loadModule = function(fileName) {
        let wrapper = [
            "(function (exports, require, module, __filename, __dirname) { ",
            " });"
        ];
        console.info("Loading " + fileName);

        let content = _loadContent(fileName);
        let module = {
            source: fileName,
            exports: {}
        };

        try {
            module.exports = JSON.parse(content);
            module.type = 'JSON';
        } catch (e) {
            if (content !== "") {
                let fn = _execute("" + fileName, wrapper[0] + content + wrapper[1]);
                fn.call(global, module.exports, global.require, module, fileName.name + "." + fileName.ext, fileName.path);
            }

            module.type = 'Code';
        }
        
        module.lastLoaded = Date.now();

        console.log(JSON.stringify(module));

        return module;
    };

    let resolveFileName = function(fileID) {
        console.log("Resolving " + fileID);
        let PathSuffix = "";

        // TODO: Trap reaching out of this directory...

        if (fileID.startsWith("./")) {
            // System, iterate via Paths/Core for file
            fileID = fileID.substring(2);
        } else {
            PathSuffix = "Core/";
        }

        let file = fileID.split('.');

        if (file.length === 1) {
            file = {
                name: fileID,
                ext: "js",
                path: "",
                toString: function() {
                    return this.path + this.name + "." + this.ext;
                }
            };
        } else {
            let ext = file.pop();
            file = {
                name: file.join("."),
                ext: ext,
                path: "",
                toString: function() {
                    return this.path + this.name + "." + this.ext;
                }
            };
        }

        for (let path of Paths) {

            if (_exists(path + PathSuffix + file)) {
                console.log("found module " + path + PathSuffix + file);

                file.path = path + PathSuffix;

                return file;
            }
        };
    };

    defineSystemProperty(global, 'require', function(fileID) {

        if (moduleCache.has(fileID)) {
            console.info("Loading module from cache. " + fileID);
            return moduleCache.get(fileID).exports;
        }

        let fileName = resolveFileName(fileID);

        moduleCache.set(fileID, loadModule(fileName));

        return moduleCache.get(fileID).exports;
    });

    global.module = {
        exports: {}
    };
    global.exports = global.module.exports;

    console.info("Initialized with Flathead v." + flathead.version + " V8 v." + v8.version);
    console.info("Library Path: " + Paths);

    let handleTimers = function (delta) {
        for (let timer of timersMap) {

            timer[1].timeout -= 1000 * delta;

            if (timer[1].timeout <= 0) {
                timer[1].func();
                timer[1].timeout = timer[1].reset;
            }

            if (timer[1].timeout === 0) {
                delete timersMap.delete(timer[0]);
            }
        }
    };

    let handleHotReload = function () {
        for (let module of moduleCache) {
            let lastModifiedTime = _modified(module[1].source);

            if (lastModifiedTime > module[1].lastLoaded) {
                console.log("Reloading Module: " + module[0]);

                moduleCache.set(module[0], loadModule(module[1].source));
            }
        };
    };

    return function tick(delta) {
        handleTimers(delta);
        handleHotReload(delta)
    };
});