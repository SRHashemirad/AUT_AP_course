CXX = g++-7
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = main.o myVec.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp
myVec.o: myVec.cpp myVec.h
	$(CXX) $(CXXFLAGS) myVec.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)
