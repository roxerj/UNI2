CXX = g++
CXXFLAGS = -Wall -g -std=c++17 -O3

all: main

main: main.cpp funkcijos.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

test: test.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	del /F /Q main.exe test.exe 2>NUL || true

cleanresult:
	del /F /Q malaciai.txt vargsai.txt 2>NUL || true
