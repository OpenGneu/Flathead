@echo off
set BASEDIR=%CD%

echo The project is currently semi-automatically built. Please consult the readme.md file for further information.

REM Ensure to return the user to the directory they executed the script from
chdir /d %BASEDIR%

@echo on