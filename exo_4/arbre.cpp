

#include <iostream>
#include "arbre.h"
#include "noeud.h"
#include "ChaineDeSortie.h"
#include "pile.h"
#include <cmath>
using namespace std;

//----------------------------------------------  Question 4 ---------------------------------------------------------


arbre::arbre() {
    racine = nullptr; // initialisation de la racine
}

arbre::arbre(noeud *racine) {
    this->racine = racine; // initialisation de la racine
}

arbre::arbre(string expinf) {
    ChaineDeSortie o; 
    o.InfToSuf(expinf);
    o.afficher(); 
    pile pi; 
    noeud* current = o.get(); 
    for (int i = 0; i < o.getcount(); i++) {
        if (current->type == 'r' || current->type == 'v') {
            pi.empiler(current);
        } else {
            current->fd = pi.depiler();
            current->fg = pi.depiler();
            pi.empiler(current);
        }
        current = current->Osuivant;
    }
    this->racine = pi.depiler(); 
}

void arbre::afficher() {
    if (racine != nullptr) {
        afficherRecursive(racine, "", true);
    }
}




void arbre::afficherRecursive(noeud *noeudActuel, string miseEnPage, bool estDernier) {
    cout << miseEnPage << "|-- ";
    if (noeudActuel->type == 'o') {
        cout << "Operateur: " << noeudActuel->ope << endl;
    } else if (noeudActuel->type == 'r') {
        cout << "Valeur: " << noeudActuel->val << endl;
    } else if (noeudActuel->type == 'v') {
        cout << "Variable: " << noeudActuel->var << endl;
    }
    string nouveauPrefixe = miseEnPage + (estDernier ? "    " : "|   ");
    if (noeudActuel->fg != nullptr) {
        afficherRecursive(noeudActuel->fg, nouveauPrefixe, false);
    }
    if (noeudActuel->fd != nullptr) {
        afficherRecursive(noeudActuel->fd, nouveauPrefixe, true);
    }
}

void arbre::afficherInfixe() {
    if (racine != nullptr) {
        afficherInfixe(racine);
        cout << endl;
    }
}

void arbre::afficherInfixe(noeud* noeudActuel) {
    if (noeudActuel != nullptr) {
        if (noeudActuel->type == 'r') {
            cout << noeudActuel->val;
        } else if (noeudActuel->type == 'v') {
            cout << noeudActuel->var;
        } else if (noeudActuel->type == 'o') {
            cout << "(";
            afficherInfixe(noeudActuel->fg);
            cout << " " << noeudActuel->ope << " ";
            afficherInfixe(noeudActuel->fd);
            cout << ")";
        }
    }
}

void arbre::deriver() {
    if (racine != nullptr) {
        cout << "L'arbre représentant votre dérivée : " << endl;
        noeud* deriveRacine = deriverRecursive(this->racine);
        arbre *deriveA = new arbre(deriveRacine);
        deriveA->afficher();
        cout << endl;
    }
}


noeud* arbre::deriverRecursive(noeud *current) {
    if (current->type == 'r') { 
        return new noeud(0.0f); // Dérivée d'un nombre est 0
    } else if (current->type == 'v') { 
        return new noeud(1.0f); // Dérivée d'une variable est 1
    } else {
        if (current->ope == '+' || current->ope == '-') { // Règle de dérivation pour l'addition et la soustraction
            noeud* deriv = new noeud(current->ope);
            deriv->fg = deriverRecursive(current->fg);
            deriv->fd = deriverRecursive(current->fd);
            return deriv;
        } else if (current->ope == '*') { // Règle de dérivation pour la multiplication
            noeud* deriv = new noeud('+');
            deriv->fg = new noeud('*');
            deriv->fg->fg = deriverRecursive(current->fg);
            deriv->fg->fd = current->fd;

            deriv->fd = new noeud('*');
            deriv->fd->fg = current->fg;
            deriv->fd->fd = deriverRecursive(current->fd);
            return deriv;
        } else if (current->ope == '/') { // Règle de dérivation pour la division
            noeud* deriv = new noeud('/');
            deriv->fg = new noeud('-');
            deriv->fg->fg = new noeud('*');
            deriv->fg->fg->fg = deriverRecursive(current->fg);
            deriv->fg->fg->fd = current->fd;

            deriv->fg->fd = new noeud('*');
            deriv->fg->fd->fg = current->fg;
            deriv->fg->fd->fd = deriverRecursive(current->fd);

            deriv->fd = new noeud('*');
            deriv->fd->fg = current->fd;
            deriv->fd->fd = current->fd;
            return deriv;
        } else if (current->ope == '^') { // Règle de dérivation pour la puissance
            float exposant = current->fd->val; 
            if (exposant == 0) { // Dérivée de la constante à la puissance 0 est 0
                return new noeud(0.0f);
            } else {
                noeud* deriv = new noeud('*');
                deriv->fg = new noeud('*');
                deriv->fg->fg = new noeud(exposant);
                deriv->fg->fd = new noeud('^');
                deriv->fg->fd->fg = current->fg;
                deriv->fg->fd->fd = new noeud(exposant - 1);
                deriv->fd = deriverRecursive(current->fg);
                return deriv;
            }
        }
    }
    return nullptr; 
}



void arbre::afficherDerivee() {
    if (racine != nullptr) {
        cout << "La dérivée exacte de l'expression est : ";
        noeud* deriveRacine = deriverRecursive(this->racine);
        arbre deriveArbre(deriveRacine);
        deriveArbre.afficherInfixe();
    }
}

arbre::~arbre() { 
    deleteTree(racine);
    cout << "Destruction de l'arbre terminée" << endl;
}

void arbre::deleteTree(noeud *noeudActuel) {
    if (noeudActuel != nullptr) {
        deleteTree(noeudActuel->fg);
        deleteTree(noeudActuel->fd);
        delete noeudActuel;
    }
}
