(function() {
	"use strict";

	var fs = require("fs");
	var v8 = require("./v8Ext");

	var createDir = function(dir) {
		console.log("Creating directory " + dir);

		try {
			fs.mkdirSync(dir);
		} catch (e) {}
	};

	console.log("Creating V8 Directories for Flathead project...");

	console.log("Found Version v" + v8.version);

	createDir("libs");
	createDir("libs/v8");
	createDir("libs/v8/" + v8.version);
	createDir("libs/v8/" + v8.version + "/include");
	createDir("libs/v8/" + v8.version + "/include/libplatform");
	createDir("libs/v8/" + v8.version + "/x86");
	createDir("libs/v8/" + v8.version + "/x86/Debug");
	createDir("libs/v8/" + v8.version + "/x86/Debug/lib");
	createDir("libs/v8/" + v8.version + "/x86/Release");
	createDir("libs/v8/" + v8.version + "/x86/Release/lib");
	createDir("libs/v8/" + v8.version + "/x64");
	createDir("libs/v8/" + v8.version + "/x64/Debug");
	createDir("libs/v8/" + v8.version + "/x64/Debug/lib");
	createDir("libs/v8/" + v8.version + "/x64/Release");
	createDir("libs/v8/" + v8.version + "/x64/Release/lib");

	console.log("Completed.");
})();