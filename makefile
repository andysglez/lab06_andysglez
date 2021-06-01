CXXFLAGS: -std=c++11 -Wall
heap: heap.o examheap.o
	g++ $(CXXFLAGS) heap.o examheap.o -o heap
heap.o: heap.cpp heap.h
	g++ -c heap.cpp
examheap.o: examheap.cpp heap.h
	g++ -c examheap.cpp
clean:
	rm  -f *.o heap
