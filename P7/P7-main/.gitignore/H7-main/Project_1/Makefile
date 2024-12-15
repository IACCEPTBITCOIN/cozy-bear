prog : driver_phase3.o Files.o Container.o Algorithms.o
	g++ -std=c++11 -o prog driver_phase3.o Files.o Container.o Algorithms.o

driver_phase3.o : driver_phase3.cpp Files.h Container.h Algorithms.h
	g++ -std=c++11 -c driver_phase3.cpp
	
Files.o : Files.cpp Files.h 
	g++ -std=c++11 -c Files.cpp

Container.o : Container.cpp Container.h
	g++ -std=c++11 -c Container.cpp

Algorithms.o : Algorithms.cpp Algorithms.h Container.h
	g++ -std=c++11 -c Algorithms.cpp

clean: 
	rm -f *.o
	rm prog