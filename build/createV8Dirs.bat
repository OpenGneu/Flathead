@echo off
set BASEDIR=%CD%

build\scripts\createV8Dirs.js

REM Ensure to return the user to the directory they executed the script from
chdir /d %BASEDIR%

@echo on