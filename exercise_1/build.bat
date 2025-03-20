:: Prevents commands from being displayed in the command prompt
@echo off

:: Check if the build folder exists, otherwise create it
if not exist build mkdir build

:: Change directory to the build folder
pushd build

:: Check if a number was provided as an argument, otherwise default to 8
if "%1"=="" (
  set NUMBER=8
) else (
  set NUMBER=%1
)

:: Compile with NUMBER defined
cl /DNUMBER=%NUMBER% ../main.cpp /Fe:main.exe

:: Return to the previous directory
popd
