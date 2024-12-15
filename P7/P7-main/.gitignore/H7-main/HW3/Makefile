prog : driver.o square.o rectangle.o triangle.o
	g++ -std=c++11 -o prog driver.o square.o rectangle.o triangle.o

driver.o : square.h rectangle.h triangle.h
	g++ -std=c++11 -c driver.cpp
	
square.o : square.h
	g++ -std=c++11 -c square.cpp

rectangle.o : rectangle.h
	g++ -std=c++11 -c rectangle.cpp

triangle.o : triangle.h
	g++ -std=c++11 -c triangle.cpp

clean: 
	rm -f *.o
	rm prog