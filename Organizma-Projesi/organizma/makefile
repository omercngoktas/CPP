all: compile run

compile:
	g++ -I ./include/ -o ./lib/Doku.o -c ./src/Doku.cpp
	g++ -I ./include/ -o ./lib/Hucre.o -c ./src/Hucre.cpp
	g++ -I ./include/ -o ./lib/IkiliAramaAgaci.o -c ./src/IkiliAramaAgaci.cpp
	g++ -I ./include/ -o ./lib/Organ.o -c ./src/Organ.cpp
	g++ -I ./include/ -o ./lib/Organizma.o -c ./src/Organizma.cpp
	g++ -I ./include/ -o ./lib/Radix.o -c ./src/Radix.cpp
	g++ -I ./include/ -o ./lib/Sistem.o -c ./src/Sistem.cpp
	g++ -I ./include/ -o ./lib/Split.o -c ./src/Split.cpp
	g++ -I ./include/ -o ./bin/Organizma ./lib/Doku.o ./lib/Hucre.o ./lib/IkiliAramaAgaci.o ./lib/Organ.o ./lib/Organizma.o ./lib/Radix.o ./lib/Sistem.o ./lib/Split.o ./src/main.cpp

run:
	./bin/Organizma