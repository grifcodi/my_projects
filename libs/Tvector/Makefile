
CXX = g++
CXXFLAGS = -Wall -std=c++17

SRC = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, build/%.o, $(SRC))
TARGET = main.out

all: $(TARGET)

build/%.o: %.cpp | builddir
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

builddir:
	mkdir -p build

clean:
	rm -rf build $(TARGET)

print:
	@echo "Source files: $(SRC)"
	@echo "Object files: $(OBJS)"

-include $(OBJS:.o=.d)
