#include "pile.h"
#include <iostream>
#include <string>
using namespace std;

pile::pile() { //constructeur sans argument
    this->tete = nullptr;
    this->nb_maillon = 0;
}

void pile::empiler(noeud *n) { //ajouter un noeud au sommet de la pile
    if (this->vide()) {
        this->tete = n;
    } else {
        n->Psuivant = this->tete; //le noeud suivant du noeud a empiler est le noeud au sommet de la pile
        this->tete = n; //le noeud a empiler devient le noeud au sommet de la pile
    }
    this->nb_maillon++;
}

noeud* pile::depiler(){ //retirer le noeud au sommet de la pile et le retourner
    if (this->vide()) {
        return nullptr;
    } else {
        noeud *n = this->tete;
        this->tete = this->tete->Psuivant;
        this->nb_maillon--;
        return n;
    }
}


bool pile::vide() {
    if (this->nb_maillon==0 ) {
        return true;
    } else {
        return false;
    }
}

void pile::afficher() {
    if (this->vide()) {
        cout << "La pile est vide" << endl;
    } else {
        noeud *n = this->tete;
        while (n != nullptr) {
            if (n->type == 'o') {
                cout << n->ope << endl;
            } else {
                cout << n->val << endl;
            }
            n = n->Psuivant;
        }
    }
}

noeud *pile::get() {
    if (!this->vide()) {
        return this->tete;
    } else {
        cout << "La pile est vide" << endl;
        return nullptr;
    }
}




