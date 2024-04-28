@echo off

if not exist dist (
	mkdir dist
)

@REM g++ source/Main.c++ source/headers/*.h -o dist/SL.exe
@REM g++ source/*.c++ source/Main.c++ -o dist/SL.exe -std=c++17 %*
g++ source/*.c++ -o dist/SL.exe -std=c++17 %*