provaEsame.o: provaEsame.C
	g++ -c provaEsame.C


LibVoto.o: LibVoto.C LibVoto.h
	g++ -c LibVoto.C

LibTuplaVoto.o: LibTuplaVoto.C LibTuplaVoto.h
	g++ -c LibTuplaVoto.C


LibStudente.o: LibStudente.C LibStudente.h
	g++ -c LibStudente.C

LibTuplaStudente.o: LibTuplaStudente.C LibTuplaStudente.h
	g++ -c LibTuplaStudente.C

libAggiorna.o: libAggiorna.C libAggiorna.h
	g++ -c libAggiorna.C

provaEsame.x: LibVoto.o LibTuplaVoto.o provaEsame.o LibStudente.o LibTuplaStudente.o libAggiorna.o
	g++ -no-pie LibVoto.o LibTuplaVoto.o  LibStudente.o LibTuplaStudente.o libAggiorna.o provaEsame.o -o provaEsame.x 

compila: provaEsame.x

esegui: compila
	./provaEsame.x
