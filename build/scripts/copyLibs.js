(function() {
	"use strict";

	var fs = require("fs");
	var v8 = require("./v8Ext");

	console.log("Copying V8 Files for Flathead project...");

	var architecture = process.argv.slice(-1)[0];
	var configuration = process.argv.slice(-2)[0];

	var targetPath = "deploy/" + configuration + "/" + architecture + "/";
	var basePath = "libs/v8/" + v8.version + "/" + architecture + "/" + configuration + "/" ;

	console.log("Copying to " + basePath);

	var copyFile = function(source, destination) {
		console.log(source + " > " + destination);
		try {
			fs.lstatSync(source);
			fs.createReadStream(source).pipe(fs.createWriteStream(destination));
		} catch (e) {
		}
	};

	var copyFiles = function(source, destination) {

		var dlls = ["icuuc", "icudt", "icui18n", "v8"];

		dlls.forEach(function(el) {
			copyFile(source + el + ".dll", destination + el + ".dll");
			copyFile(source + el + ".pdb", destination + el + ".pdb");
		});
	};

	console.log("");
	copyFiles(basePath, targetPath);
})();