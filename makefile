CXX = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = red_neuronal_JoaqArenas
OBJS = main.o vectorNN.o activations.o layers.o nn.o io.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)