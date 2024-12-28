# Define variables
CXX = g++               # The C++ compiler
CXXFLAGS = -Wall -std=c++20 -O3 # Compiler flags, including C++ standard
OBJ = lab10.o           # Object file

# Target: all (default target)
all: lab10

# Target: executable 'lab10'
lab10: $(OBJ)
	$(CXX) $(CXXFLAGS) -o lab10 $(OBJ)

# Target: compiling lab10.o
lab10.o: lab10.cpp
	$(CXX) $(CXXFLAGS) -c lab10.cpp

# Target: clean (removes compiled files)
clean:
	rm -f *.o lab10
