(function(module) {
	"use strict";

	var fs = require("fs");
	require("./stringExt");

	var version = {
		major: "0",
		minor: "0",
		patch: "0",
		build: "0",
		candidate: "0",
		toString: function() {
			this.load();

			return this.major.trim() + "." + this.minor.trim() + "." + this.build.trim();
		},
		load: function() {
			// find version of v8
			var contents = fs.readFileSync("deps/v8/include/v8-version.h").toString("utf8").split("\n");

			contents.forEach(function(el) {
				if (!el.startsWith("#define")) { // Ignore non define files
					return;
				}

				var define = el.split(" ", 3);

				if (define.length < 3) { // Ignore inclusion wrapper
					return;
				}

				if (define[1] === "V8_MAJOR_VERSION") {
					version.major = define[2];
				} else if (define[1] === "V8_MINOR_VERSION") {
					version.minor = define[2];
				} else if (define[1] === "V8_BUILD_NUMBER") {
					version.build = define[2];
				} else if (define[1] === "V8_PATCH_LEVEL") {
					version.patch = define[2];
				} else if (define[1] === "V8_IS_CANDIDATE_VERSION") {
					version.candidate = define[2];
				}
			});
		}
	};

	module.exports = {
		version: version.toString()
	};
})(module);