@echo off

set BASEDIR=%CD%

node build\scripts\copyV8Files.js x64

REM Ensure to return the user to the directory they executed the script from
chdir /d %BASEDIR%

@echo on