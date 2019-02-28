CXX = g++-7
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = main.o libVec.o libArr.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

libVec.o: libVec.cpp libVec.h
	$(CXX) $(CXXFLAGS) libVec.cpp

libArr.o: libArr.cpp libArr.h
	$(CXX) $(CXXFLAGS) libArr.cpp

clean:
	rm -f $(TARGET) $(OBJECTS)
