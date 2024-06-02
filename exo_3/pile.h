#ifndef PILE_H
#define PILE_H
#include "noeud.h"
#include <string>
using namespace std;
//premier entré premier sorti

class pile {
    noeud *tete;
    int nb_maillon;
public:
    pile();
    void empiler(noeud *n); //ajouter un noeud au sommet de la pile
    noeud* depiler(); //retirer le noeud au sommet de la pile et le retourner
    bool vide(); //retourner vrai si la pile est vide, faux sinon
    noeud *get(); //retourner le pointeur vers le premier noeud de la pile
    void afficher(); //afficher la pile
    void evaluer(string expression); //evaluer une expression arithmetique

};

#endif
