@echo off
set BASEDIR=%CD%

REM Do a full build here

SET PATH=%PATH%;%CD%\deps\depot_tools
CD deps
fetch v8
cd v8
git new-branch flathead

REM Ensure to return the user to the directory they executed the script from
chdir /d %BASEDIR%

@echo on