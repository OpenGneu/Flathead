(function() {
	"use strict";

	var glob = require("glob");
	var fs = require("fs");
	var v8 = require("./v8Ext");

	var basePath = "libs/v8/" + v8.version + "/include";

	console.log("Copying V8 Includes for Flathead project...");

	var copyFile = function(source, destination) {
		console.log(source + " > " + destination);

		fs.createReadStream(source).pipe(fs.createWriteStream(destination));
	};

	glob("deps/v8/include/**/*.h", function(err, files) {
		files.forEach(function(file) {
			copyFile(file, file.replace("deps/v8/include", basePath));
		});
	});
})();