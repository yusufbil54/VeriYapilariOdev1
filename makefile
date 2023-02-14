all:	derle bagla calistir
derle:
	g++ -c -I "./include" ./src/TekYonluBagilListe.cpp -o ./lib/TekYonluBagilListe.o
	g++ -c -I "./include" ./src/SatirListesi.cpp -o ./lib/SatirListesi.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/ikiYonluBagilListe.cpp -o ./lib/ikiYonluBagilListe.o
	g++ -c -I "./include" ./src/YonetimListesi.cpp -o ./lib/YonetimListesi.o

bagla:
	g++ ./lib/TekYonluBagilListe.o ./lib/SatirListesi.o ./lib/ikiYonluBagilListe.o ./lib/YonetimListesi.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program