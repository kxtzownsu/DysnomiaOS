C_COMP = gcc
CPP_COMP = g++

main:
	g++ -c -o build/input.o readinput.cpp
	gcc -o build/main main.c build/input.o -lstdc++

clean:
	rm -rf build/*