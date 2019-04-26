CXX = g++
CXXFLAGS = -ansi -Wall -g
TARGET = Driver.o MMheap.o

all: $(TARGET)
	$(CXX) $(CXXFLAGS) $(TARGET) -o Driver.out

MMheap.o: MMheap.cpp
	$(CXX) $(CXXFLAGS) -c MMheap.cpp

Driver.o: Driver.cpp
	$(CXX) $(CXXFLAGS) -c Driver.cpp

run:
	./Driver.out $(FILE)
val:
	valgrind ./Driver.out $(FILE)
clean:
	rm -f *.o
	rm -f *.out
	rm -f *~ *.h.gch *#