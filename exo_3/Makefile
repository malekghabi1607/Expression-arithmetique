output : noeud.o main pile.o ChaineDeSortie.o arbre.o
	./main

main : main.cpp pile.o noeud.o ChaineDeSortie.o arbre.o
	g++ -o main pile.o noeud.o ChaineDeSortie.o arbre.o main.cpp

arbre.o : arbre.cpp arbre.h
	g++ -c arbre.cpp

outputChain.o : ChaineDeSortie.cpp ChaineDeSortie.h
	g++ -c ChaineDeSortie.cpp

pile.o : pile.cpp pile.h
	g++ -c pile.cpp

noeud.o : noeud.cpp noeud.h
	g++ -c noeud.cpp
