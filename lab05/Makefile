# Define variables
CXX = g++               # The C++ compiler
CXXFLAGS = -Wall -std=c++20 -O3 # Compiler flags, including C++ standard
OBJ = lab05.o           # Object file

# Target: all (default target)
all: lab05

# Target: executable 'lab05'
lab05: $(OBJ)
	$(CXX) $(CXXFLAGS) -o lab05 $(OBJ)

# Target: compiling lab05.o
lab05.o: lab05.cpp
	$(CXX) $(CXXFLAGS) -c lab05.cpp

# Target: clean (removes compiled files)
clean:
	rm -f *.o lab05

