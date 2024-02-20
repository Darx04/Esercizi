principale.o: principale.C
	g++ -c principale.C

libpart.o: libpart.C libpart.h
	g++ -c libpart.C

libbuche.o: libbuche.C libbuche.h
	g++ -c libbuche.C

principale.x: libpart.o principale.o libbuche.o 
	g++ libpart.o libbuche.o principale.o -o principale.x


compila: principale.x

esegui: compila
	./principale.x