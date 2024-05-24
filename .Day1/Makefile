# Compiler to use
CXX = g++
# Compiler flags
CXXFLAGS = -Wall -std=c++11

# Target executable
TARGET = main
# Object files , Source files
OBJS = src/DynamicArray.o src/main.o

# Default target
all: $(TARGET)

# Linking the target executable
$(TARGET): $(OBJS)
    $(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
# Compiling source files into object files

src/DynamicArray.o: include/DynamicArray.h src/DynamicArray.cpp
    $(CXX) $(CXXFLAGS) -c src/DynamicArray.cpp -o src/DynamicArray.o

src/main.o: include/DynamicArray.h src/main.cpp
    $(CXX) $(CXXFLAGS) -c src/main.cpp -o src/main.o
	
# Clean target to remove compiled files
clean:
    rm -f $(TARGET) src/*.o

