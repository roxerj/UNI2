CXX = g++
CXXFLAGS = -Wall -g -std=c++17 -O3

all: main

main: main.cpp funkcijos.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	del /F /Q main.exe 2>NUL || true
