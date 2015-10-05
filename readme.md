# Flathead

This library is responsible for encapsulating the V8 Libraries and providing the interface to be used by Unreal or any other platform, really.

# Setup & Configuration

## Public Warning
Be warned, this project does not have a simple configuration process. There are many steps all with variations depending on your current system configuration. Please do not try to skip through any of it or take any short cuts. V8, and in turn Flathead, are complicated systems needing time and effort to build successfully. I have already taken steps to simplify this process as best I can to make the project generally useful.

If you run into any issues please follow the manual build steps from this [gist](https://gist.github.com/BobGneu/f9dc1a3ac664f5426edb)

## Automated Environment Configuration

1. Install [Node.js](https://nodejs.org/)
2. Clone Flathead project to a directory of your choice.
3. Run `build\init.bat`
4. Run `build\createV8Dirs.bat`

## Semi-Automated Build
1. Run `build\generateV8Projectsx86.bat`
2. Start MSVS and open `deps\v8\build\all.sln`
3. Build Debug
4. Build Release
5. Run `build\copyV8Filesx86.bat`
6. Run `build\generateV8Projectsx64.bat`
7. Start MSVS and open `deps\v8\build\all.sln`
8. Build Debug
9. Build Release
10. Run `build\copyV8Filesx64.bat`
11. Run `build\copyIncludes.bat`
12. Update line 8 of `libs\v8\**version**\include\libplatform\libplatform.h` from `#include "include/v8-platform.h"` to `#include "v8-platform.h"`
13. Update the `Include Directorys` and `Library Directories` to the correct v8 deployment path. 

# Contact & Contributions
**Lead Developer** - Bob Chatman <bob@gneu.org>

# License
GNU Lesser General Public License, version 3.0 (LGPL-3.0)
