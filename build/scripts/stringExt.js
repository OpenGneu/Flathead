(function() {
	"use strict";

	String.prototype.startsWith = function(str) {
		return this.indexOf(str) === 0;
	};

	String.prototype.contains = function(str) {
		return this.indexOf(str) !== -1;
	};
})();