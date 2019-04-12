CXX = g++-7
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = main.o maxHeap.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp
maxHeap.o: maxHeap.cpp maxHeap.h
	$(CXX) $(CXXFLAGS) maxHeap.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)
