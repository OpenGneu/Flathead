(function() {
	"use strict";

	console.log("Updating Build Version");

	var fs = require("fs");
	var semver = require("semver");
	var pkg = require("../../package.json");

	var oldVersion = pkg.version;

	if (!semver.valid(pkg.version)) {
		console.warn("Invalid version found - " + pkg.version);
		console.warn("Please fix your package file.");
		process.exit(-1);
		return;
	}

	if (process.argv.length !== 3) {
		console.log("Usage: node incrementBuild.js [major|minor|patch|build]");
		return;
	}

	switch (process.argv[2]) {

		case "major":
			pkg.version = semver.inc(pkg.version, "major");
			break;

		case "minor":
			pkg.version = semver.inc(pkg.version, "minor");
			break;

		case "patch":
			pkg.version = semver.inc(pkg.version, "patch");
			break;

		case "build":
			pkg.version = semver.inc(pkg.version, "build");
			break;

		default:
			console.log("Invalid increment requested.");
			process.exit(-2);
			return;
	}

	console.log("Updating version from " + oldVersion + " to " + pkg.version);
	console.log("Saving...");

	fs.writeFile("./package.json", JSON.stringify(pkg, null, "\t"), function(err) {
		if (err) {
			return console.log(err);
		}

		console.log("Complete.");
	});
})();