prog : driver.o IntArray.o 
	g++ -std=c++11 -o prog driver.o IntArray.o 

driver.o : IntArray.h 
	g++ -std=c++11 -c driver.cpp
	
IntArray.o : IntArray.h
	g++ -std=c++11 -c IntArray.cpp

clean: 
	rm -f *.o
	rm prog