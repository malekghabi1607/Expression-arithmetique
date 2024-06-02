#include "arbre.h"
#include <string>
#include "ChaineDeSortie.h"
#include <iostream>
#include "pile.h"
#include <cmath>
using namespace std;

//----------------------------------------------  Question 3  ----------------------------------------------------------




arbre::arbre() {
    racine = nullptr; //initialisation de la racine
}

arbre::arbre(string expinf){
   ChaineDeSortie o; //création d'une nouvelleChaineDeSortie qui va nous permettre de transformer l'expression infixe en expression suffixée
    o.InfToSuf(expinf); //appel de la methode InfToSuf qui transforme une expression infixe en expression suffixée
    o.afficher(); //affichage de l'expression suffixée
    pile pi; //création d'une nouvelle pile qui va nous permettre de créer l'arbre
    noeud* current = o.get(); //on récupère le premier noeud de l'outputChain pour commencer à créer l'arbre en la lisant
    for (int i = 0; i < o.getcount();i++){
        if (current->type == 'f'){
            pi.empiler(current);//si c'est un nombre, on l'empile
        } else { //si ce n'est pas un nombre, c'est un opérateur
            current->fd = pi.depiler();//on dépile le dernier nombre empilé et on le met à droite de l'opérateur
            current->fg = pi.depiler(); //on dépile le dernier nombre empilé et on le met à gauche de l'opérateur
            pi.empiler(current); //on empile l'opérateur
        }
        current = current->Osuivant; //on passe au noeud suivant
    }
    this->racine = pi.depiler(); //on dépile le dernier noeud empilé qui est la racine de l'arbre
}

void arbre::afficher() { //méthode d'affichage de l'arbre recursive
    if (racine != nullptr) {
        cout << "L'arbre de votre expression  : " << endl;
        afficherRecursive(racine, "", true);
    }
}

void arbre::afficherRecursive(noeud *noeudActuel, string miseEnPage, bool estDernier) {
    cout << miseEnPage; //mise en page de l'affichage qui est agrémenté de | et de -- pour représenter l'arbre
    cout << "|-- ";
    if (noeudActuel->type == 'o') {
        cout << "Operateur: " << noeudActuel->ope << endl;
    } else if (noeudActuel->type == 'f') {
        cout << "Valeur: " << noeudActuel->val << endl;
    }
    string nouveauPrefixe = miseEnPage + (estDernier ? "    " : "|   ");//concaténation de la nouvelle mise en page de l'affichage avec l'ancienne
    if (noeudActuel->fg != nullptr) {//si le noeud a un fils gauche, on affiche le fils gauche
        afficherRecursive(noeudActuel->fg, nouveauPrefixe, false);
    }
    if (noeudActuel->fd != nullptr) {//si le noeud a un fils droit, on affiche le fils droit
        afficherRecursive(noeudActuel->fd, nouveauPrefixe, true);
    }
}

float arbre::evaluer() { //méthode d'évaluation de l'arbre recursive
    if (racine != nullptr) {
        return evaluer(racine);
    }
    else {
        return 0;
    }
}



float arbre::evaluer(noeud* noeudActuel) {
    if (noeudActuel->type == 'f') {
        return noeudActuel->val; // Si le nœud est une valeur, retourner la valeur
    }
    else if (noeudActuel->type == 'o') {
        float resultatGauche = evaluer(noeudActuel->fg); // Évaluer le sous-arbre gauche
        float resultatDroit = evaluer(noeudActuel->fd); // Évaluer le sous-arbre droit

        if (noeudActuel->ope == '+') {
            return resultatGauche + resultatDroit; // Retourner la somme des deux sous-arbres
        } else if (noeudActuel->ope == '-') {
            return resultatGauche - resultatDroit; // Retourner la soustraction des deux sous-arbres
        } else if (noeudActuel->ope == '*') {
            return resultatGauche * resultatDroit; // Retourner la multiplication des deux sous-arbres
        } else if (noeudActuel->ope == '/') {
            return resultatGauche / resultatDroit; // Retourner la division des deux sous-arbres
        } else if (noeudActuel->ope == '^') {
            return pow(resultatGauche, resultatDroit); // Retourner la puissance
        } else if (noeudActuel->ope == '%') {
            return fmod(resultatGauche, resultatDroit); // Retourner le modulo
        } else {
            return 0.0; // Opérateur invalide, retourner 0.0
        }
    } else {
        return 0.0; // Type de nœud invalide, retourner 0.0
    }
}



void arbre::afficherInfixe() {
    if (racine != nullptr) { //méthode d'affichage infixe de l'arbre recursive
        cout << "L'expression infixe de votre arbre : ";
        afficherInfixe(racine); //appel de la méthode recursive
        cout << endl;
    }
}

void arbre::afficherInfixe(noeud* noeudActuel) {
    if (noeudActuel != nullptr) {
        if (noeudActuel->type == 'f') {
            cout << noeudActuel->val;
        } else if (noeudActuel->type == 'o' && noeudActuel->fd->type == 'f' && noeudActuel->fg->type == 'f') { //si le noeud est un opérateur et que ses fils sont des nombres, on affiche l'opérateur et ses fils
            afficherInfixe(noeudActuel->fg);
            cout << " " << noeudActuel->ope << " ";
            afficherInfixe(noeudActuel->fd);
        } else { //sinon on affiche l'opérateur et ses fils entre parenthèses
            cout << "(";
            afficherInfixe(noeudActuel->fg);
            cout << " " << noeudActuel->ope << " ";
            afficherInfixe(noeudActuel->fd);
            cout << ")";
        }
    }
}

arbre::~arbre() { //destructeur de l'arbre
    delete racine;
    cout << "Destruction de l'arbre terminee" << endl;
}





