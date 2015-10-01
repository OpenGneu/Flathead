@echo off
set BASEDIR=%CD%

cd deps\v8

REM Generate x86 Projects & Solution
python build\gyp_v8 -Dcomponent=shared_library -Dv8_use_snapshot=0

REM Ensure to return the user to the directory they executed the script from
chdir /d %BASEDIR%

@echo on