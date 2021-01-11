hepsi: derle test calistir

derle:
	gcc -I ./include/ -o ./lib/IMEINO.o -c ./src/IMEINO.c
	gcc -I ./include/ -o ./lib/KIMLIKNO.o -c ./src/KIMLIKNO.c
	gcc -I ./include/ -o ./lib/KISI.o -c ./src/KISI.c
	gcc -I ./include/ -o ./lib/RASTGELEKISI.o -c ./src/RASTGELEKISI.c
	gcc -I ./include/ -o ./lib/TELEFON.o -c ./src/TELEFON.c
	
test:
	gcc -I ./include/ -o ./bin/Test ./lib/IMEINO.o ./lib/KIMLIKNO.o ./lib/KISI.o ./lib/RASTGELEKISI.o ./lib/TELEFON.o ./src/Test.c

calistir:
	./bin/Test