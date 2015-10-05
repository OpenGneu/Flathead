(function() {
	"use strict";

	var fs = require("fs");
	var v8 = require("./v8Ext");

	var basePath = "libs/v8/" + v8.version + "/";

	console.log("Copying V8 Files for Flathead project...");

	var architecture = process.argv.slice(-1)[0];

	if (architecture === "x64" || architecture === "x86") {
		basePath += architecture + "/";
	} else {
		console.log("Not exactly sure what happened.");
		process.exit(-1);
		return;
	}

	console.log("Copying to " + basePath);

	var copyFile = function(source, destination) {
		console.log(source + " > " + destination);
		try {
			fs.lstatSync(source);
			fs.createReadStream(source).pipe(fs.createWriteStream(destination));
		} catch (e) {
		}
	};

	var copyFiles = function(source, destination, configuration) {

		var dlls = ["icuuc", "icudt", "icui18n", "v8"];
		var libs = ["icuuc", "icui18n", "v8", "v8_libbase", "v8_libplatform"];

		dlls.forEach(function(el) {
			copyFile(source + configuration + "/" + el + ".dll", destination + configuration + "/" + el + ".dll");
			copyFile(source + configuration + "/" + el + ".pdb", destination + configuration + "/" + el + ".pdb");
		});

		libs.forEach(function(el) {
			copyFile(source + configuration + "/lib/" + el + ".lib", destination + configuration + "/lib/" + el + ".lib");
		});
	};

	console.log("");
	copyFiles("deps/v8/build/", basePath, "Debug");
	console.log("");
	copyFiles("deps/v8/build/", basePath, "Release");
})();