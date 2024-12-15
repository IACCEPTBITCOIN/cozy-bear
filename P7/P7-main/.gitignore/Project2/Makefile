prog : driver2.o Iterator.o List.o Node.o Store.o
	g++ -std=c++11 -o prog driver2.o Iterator.o List.o Node.o Store.o 

driver.o : driver2.cpp Iterator.h List.h Node.h Store.h
	g++ -std=c++11 -c driver2.cpp
	
Iterator.o : Iterator.cpp Iterator.h 
	g++ -std=c++11 -c Iterator.cpp

List.o : List.cpp List.h
	g++ -std=c++11 -c List.cpp

Node.o : Node.cpp Node.h 
	g++ -std=c++11 -c Node.cpp

Store.o : Store.cpp Store.h 
	g++ -std=c++11 -c Store.cpp

clean: 
	rm -f *.o
	rm prog