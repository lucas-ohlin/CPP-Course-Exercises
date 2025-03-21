@echo off

:: Check if the build folder / directory exists, otherwise it creates it
if not exist build mkdir build

:: pushd is kinda like cd, so this cd's us into the build folder
pushd build

:: Runs the microsoft compiler cl.exe to compile the main.cpp file
:: Which is outside of the build folder hence why the ../
cl ../main.cpp

:: Returns us out of the build folder
popd build