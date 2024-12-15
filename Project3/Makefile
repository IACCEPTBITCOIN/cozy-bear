prog : driver_phase1.o Customer.o CustomerUI.o Package.o UPS.o UPSUI.o
	g++ -std=c++11 -o prog driver_phase1.o Customer.o CustomerUI.o Package.o UPS.o UPSUI.o

driver_phase1.o: driver_phase1.cpp Customer.h CustomerUI.h Package.h UPS.h UPSUI.h
	g++ -std=c++11 -c driver_phase1.cpp

Customer.o : Customer.cpp Customer.h
	g++ -std=c++11 -c Customer.cpp

CustomerUI.o : CustomerUI.cpp CustomerUI.h Customer.h
	g++ -std=c++11 -c CustomerUI.cpp

Package.o : Package.cpp Package.h
	g++ -std=c++11 -c Package.cpp

UPS.o : UPS.cpp UPS.h
	g++ -std=c++11 -c UPS.cpp

UPSUI.o : UPSUI.cpp UPSUI.h
	g++ -std=c++11 -c UPSUI.cpp

clean:
	rm -f *.o 
	rm prog
