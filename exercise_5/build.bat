@echo off

if not exist build mkdir build

pushd build

g++ -static -static-libgcc -static-libstdc++ ../main.cpp -o main.exe

popd build

