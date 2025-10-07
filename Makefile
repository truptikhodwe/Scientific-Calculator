# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Google Test flags (needed for linking)
GTEST_LIBS = -lgtest -lgtest_main -pthread

# Default target: build the main application
all: scientific_calculator

# Rule to build the main calculator executable
scientific_calculator: main.cpp calculator.cpp calculator.h
	$(CXX) $(CXXFLAGS) -o scientific_calculator main.cpp calculator.cpp

# Rule to build and run the tests
test: tests.cpp calculator.cpp
	# This command compiles the test file and links it with Google Test libraries
	$(CXX) $(CXXFLAGS) -o run_tests tests.cpp calculator.cpp $(GTEST_LIBS)
	./run_tests

# Rule to clean up compiled files
clean:
	rm -f scientific_calculator run_tests *.o