#include "noeud.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

noeud::noeud() { //constructeur par défaut
    fg = nullptr;
    fd = nullptr;
}

noeud::noeud(char caractere) { //constructeur avec paramètre
    if (caractere != '+' && caractere != '-' && caractere != '*' && caractere != '/' && caractere != '%' && caractere != '^' && caractere != '(' && caractere != ')'){ //si le caractère est un chiffre
        this->type = 'f';
        this->val = caractere - '0'; 
        fg = nullptr;
        fd = nullptr;
    } else { //si le caractère est un opérateur
        this->type = 'o';
        this->ope = caractere; //on stocke l'opérateur dans la variable ope
        fg = nullptr;
        fd = nullptr;
    }
}

noeud::~noeud() { //destructeur de noeud
    delete fg;
    delete fd;
}
