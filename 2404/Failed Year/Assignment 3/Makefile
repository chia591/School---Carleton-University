a3:	main.o Control.o View.o Library.o Book.o List.o Logger.o
	g++ -o a3 main.o Control.o View.o Library.o Book.o List.o Logger.o

main.o:	main.cc Control.h
	g++ -c main.cc

Control.o:	Control.cc Control.h Library.h View.h
	g++ -c Control.cc

View.o:	View.cc View.h 
	g++ -c View.cc

Library.o: Library.cc Library.h Book.h List.h Logger.h
	g++ -c Library.cc

Book.o: Book.cc Book.h
	g++ -c Book.cc

List.o: List.cc List.h Book.h
	g++ -c List.cc

Logger.o: Logger.cc Logger.h Book.h List.h
	g++ -c Logger.cc

clean:
	rm -f *.o a3
