#ifndef OUTPUTCHAIN_H
#define OUTPUTCHAIN_H
#include <iostream>
#include "noeud.h"
using namespace std;

class ChaineDeSortie {
    noeud *queue; //pointeur vers le dernier noeud de la chaine
    noeud *tete; //pointeur vers le premier noeud de la chaine
    int nb_noeuds; //nombre de noeuds dans la chaine
    public:
       ChaineDeSortie(); //constructeur sans argument
        void ajouter (noeud *n); //ajouter un noeud a la chaine
        void afficher(); //afficher la chaine
        void InfToSuf(string expression); //convertir une expression infixe en expression suffixe
        noeud *get(); //retourner le pointeur vers le premier noeud de la chaine
        int getcount(); //retourner le nombre de noeuds dans la chaine
};

#endif
