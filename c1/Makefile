# Set the CXX compiler
CXX = g++

# Set the CXXFLAGS
CXXFLAGS = -Wall -O3 -std=c++20

# Set the source files
SRC = SortOps.cxx c1.cxx

# Set the object files
OBJ = $(SRC:.cxx=.o)

# Set the executable file
EXE = c1.x

# Set the all target to buiildd the executable
all: $(EXE)

# Compile the source files into objects
%.o: %.cxx
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link the objects into the executable
$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Clean the directory
clean:
	rm -f $(OBJ) $(EXE)