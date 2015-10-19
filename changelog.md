# Change Log
All notable changes to this project will be documented in this file.
This project adheres to [Semantic Versioning](http://semver.org/).

For more information about how to maintain this document, [please keep a changelog](http://keepachangelog.com).

## [Unreleased][unreleased]

## [2.2.0][2.2.0]

### Added
* Module hot swapping 
* Provided unload event for hot swapping
* EnableHotReloading flag is reflected in behavior of bootstrapping
* Can retrieve all types from JS land
* Boolean, String, Number, Object, Function types have specific subclasses to retrieve value
* Can set and get Objects, Functions, Numbers, Strings, Booleans from native values. 
* Can expose a C++ object and re-reference it to allow C++ objects to be referenced by JS function calls. 

### Test Coverage

| Type                        | Coverage % |
| :-------------------------- | ---------: | 
| **Covered Lines**           |      80.3% | 
| **Uncovered Lines**         |      18.4% | 
| **Partially Covered Lines** |       1.3% | 

## [2.1.1][2.1.1]

### Added
* Including Coverage report with release notes
* Ensuring VS copys libs appropriately. 

### Changed
* Changed licenses per user feedback
* Updated build scripts with missing steps
* Trapping error in build script when copying files if paths are incorrect or when  release versions of the application. 
* Updated to **V8 v4.8.0**
* Added `npm install` to init script `build/init.bat`

### Test Coverage

| Type                        | Coverage % |
| :-------------------------- | ---------: | 
| **Covered Lines**           |      80.7% | 
| **Uncovered Lines**         |      18.0% | 
| **Partially Covered Lines** |       1.3% | 

## [2.1.0][2.1.0]

### Added
* Initial Commit

[unreleased]: https://github.com/OpenGneu/Flathead/compare/v2.2.0...HEAD
[2.1.1]: https://github.com/OpenGneu/Flathead/compare/v2.1.1...v2.2.0
[2.1.1]: https://github.com/OpenGneu/Flathead/compare/v2.1.0...v2.1.1
[2.1.0]: https://github.com/OpenGneu/flathead/tree/v2.1.0