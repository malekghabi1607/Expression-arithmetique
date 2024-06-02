#ifndef ARBRE_H
#define ARBRE_H
#include <string>
#include "noeud.h"
using namespace std;



//----------------------------------------------  Question 4  ----------------------------------------------------------



class arbre {
    noeud *racine;  // racine de l'arbre
public:
    arbre(); // constructeur sans argument
    arbre(noeud *racine); // constructeur à partir d'un noeud
    arbre(string expressioninf); // constructeur à partir d'une expression infixe

    void afficher(); // afficher l'arbre
    void afficherRecursive(noeud *noeudActuel, string miseEnPage, bool estDernier); // afficher l'arbre récursivement à partir d'un noeud

    void afficherInfixe(); // afficher l'arbre en notation infixe
    void afficherInfixe(noeud* noeudActuel); // afficher l'arbre en notation infixe récursivement à partir d'un noeud

    void deriver();  // dériver l'arbre
    noeud *deriverRecursive(noeud* current); // dériver l'arbre récursivement à partir d'un noeud



    void afficherDerivee(); // Afficher la dérivée exacte de l'expression



    void deleteTree(noeud *noeudActuel); // supprimer l'arbre récursivement à partir d'un noeud
    ~arbre(); // destructeur
};


#endif