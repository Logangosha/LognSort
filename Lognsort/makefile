a.exe: LognSort.o main.o MergeSort.o SortingTester.o
	g++ LognSort.o main.o MergeSort.o SortingTester.o -o a.exe


LognSort.o: LognSort.cpp LognSort.h
	g++ -c -g LognSort.cpp


MergeSort.o: MergeSort.cpp MergeSort.h
	g++ -c -g MergeSort.cpp


main.o: main.cpp LognSort.h LognSort.cpp MergeSort.h MergeSort.cpp SortingTester.cpp SortingTester.h 
	g++ -c -g main.cpp


SortingTester.o: SortingTester.cpp SortingTester.h LognSort.h LognSort.cpp MergeSort.h MergeSort.cpp
	g++ -c -g SortingTester.cpp


clean:
	del *.o a.exe


run: a.exe
	./a.exe
