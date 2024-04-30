TARGET = program


CXX = g++
CXXFLAGS = -Wall -g


SOURCES = program.cpp swap.cpp


OBJECTS = $(SOURCES:.cpp=.o)


all: $(TARGET)


$(TARGET): $(OBJECTS)
        $(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)


%.o: %.cpp
        $(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
        rm -f $(OBJECTS) $(TARGET)
