a1:	main.o MovieGroup.o Movie.o
	g++ -o a1 main.o MovieGroup.o Movie.o

main.o:	main.cc MovieGroup.h Movie.h
	g++ -c main.cc

MovieGroup.o:	MovieGroup.cc MovieGroup.h Movie.h
	g++ -c MovieGroup.cc

Movie.o:	Movie.cc Movie.h
	g++ -c Movie.cc

clean:
	rm -f *.o a1
