ALL: prog run

prog:
	g++ -I ./include/ -o ./lib/test.o -c ./src/test.cpp
	g++ -I ./include/ -o ./lib/organizma.o -c ./src/organizma.cpp
	g++ -I ./include/ -o ./lib/sistem.o -c ./src/sistem.cpp
	g++ -I ./include/ -o ./lib/organ.o -c ./src/organ.cpp
	g++ -I ./include/ -o ./lib/doku.o -c ./src/doku.cpp
	g++ -I ./include/ -o ./lib/hucre.o -c ./src/hucre.cpp
	g++ -I ./include/ -o ./lib/bst.o -c ./src/bst.cpp
	g++ -I ./include/ -o ./lib/queue.o -c ./src/queue.cpp
	g++ -I ./include/ -o ./lib/radix.o -c ./src/radix.cpp
	g++ -I ./include/ -o ./lib/kontrol.o -c ./src/kontrol.cpp
	g++ -I ./include/ -o ./bin/test.exe ./lib/organizma.o ./lib/sistem.o ./lib/organ.o ./lib/doku.o ./lib/hucre.o ./lib/bst.o ./lib/queue.o ./lib/radix.o ./lib/kontrol.o ./src/test.cpp

run:
	./bin/test