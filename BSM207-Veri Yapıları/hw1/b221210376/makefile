Tum: derleme calistirma

derleme:
	g++ -I ./include/ -o ./lib/verioku.o -c ./src/verioku.cpp
	g++ -I ./include/ -o ./lib/bagli_liste.o -c ./src/bagli_liste.cpp
	g++ -I ./include/ -o ./lib/satir_listesi.o -c ./src/satir_listesi.cpp
	g++ -I ./include/ -o ./lib/yonetici_listesi.o -c ./src/yonetici_listesi.cpp
	g++ -I ./include/ -o ./lib/main.o -c ./src/main.cpp
	g++ -I ./include/ -o ./bin/main.exe ./lib/verioku.o ./lib/bagli_liste.o ./lib/satir_listesi.o ./lib/yonetici_listesi.o ./src/main.cpp

calistirma:
	./bin/main