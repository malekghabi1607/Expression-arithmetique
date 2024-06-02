//projet/pile.cpp
#include <iostream>
#include <string>
#include <cmath>
#include "class.h"

using namespace std;


//----------------------------------------------  Question 1  ----------------------------------------------------------

Maillon::Maillon() {
    this->valeur = "";
    this->suivant = nullptr;
}

Maillon::Maillon(string valeur) {
    this->valeur = valeur;
    this->suivant = nullptr;
}

Maillon::Maillon(string valeur, Maillon *suivant) {
    this->valeur = valeur;
    this->suivant = suivant;
}

Maillon::~Maillon() {
    this->suivant = nullptr;
}
pile::pile() {
    this->tete = nullptr;
    this->nb_maillon = 0;
}

void pile::empiler(string val) {
    if (this->vide()) { //si la pile est vide
        Maillon *o = new Maillon(val);//on crée un nouveau Maillon
        this->tete = o;//on affecte le nouveau Maillon à la tete de la pile
    } else {
        Maillon *o = new Maillon(val, this->tete); //on crée un nouveau Maillon avec le Maillon suivant qui est la tete de la pile
        this->tete = o; //on affecte le nouveau Maillon
    }
    this->nb_maillon++; //on incrémente le nombre de Maillon
}

string pile::depiler() {
    if (this->vide()) { //si la pile est vide
        cout << "La pile est vide, la valeur renvoyee est une valeur par defaut (-1)" << endl;
        return "error";
    } else { //si la pile n'est pas vide
        string val = this->tete->valeur; //on récupère la valeur du Maillon à la tete de la pile
        Maillon *o = this->tete; //on crée un pointeur vers le Maillon à la tete de la pile
        this->tete = this->tete->suivant; //on affecte le Maillon suivant à la tete de la pile
        delete o; //on supprime le Maillon à la tete de la pile
        this->nb_maillon--; //on décrémente le nombre de Maillon
        return val; //on retourne la valeur du Maillon à la tete de la pile
    }
}

bool pile::vide() {
    if (this->tete == nullptr) {
        return true;
    } else {
        return false;
    }
}

void pile::afficher() {
    if (this->vide()) {
        return ;
    } else {
        Maillon *o = this->tete;
        while (o != nullptr) {
            cout << o->valeur << endl;
            o = o->suivant;
        }
    }
}

void pile::evaluer(string expression) {
    string op = ""; //opérande qui permet de stocker les nombres
    for (int i = 0; i < expression.length(); i++) { //on parcourt la chaine de Maillon
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^' ) { //si le Maillon est un opérateur
            int b = stoi(this->depiler()); //on dépile le premier nombre
            int a = stoi(this->depiler()); //on dépile le deuxième nombre
            cout << a << " " << expression[i] << " " << b << endl;
            if (expression[i] == '+') { //on effectue l'opération en fonction de l'opérateur et on empile le resultat
                this->empiler(to_string(a + b));
            } else if (expression[i] == '-') {
                this->empiler(to_string(a - b));
            } else if (expression[i] == '*') {
                this->empiler(to_string(a * b));
            } else if (expression[i] == '/') {
                this->empiler(to_string(a / b));
            } else if (expression[i] == '^') {
                this->empiler(to_string(pow(a, b)));
            }
        } else { //si le Maillon est un nombre
            op = expression[i];
            while (expression[i+1] != ' ') { // tant que l'opérande n'est pas fini
                 op += expression[i+1]; // on ajoute le caractère suivant à l'opérande
                 i++; // on incrémente i pour passer au caractère suivant
            }
            i++; // on incrémente i pour passer au caractére suivant sans considérer l'espace
            this->empiler(op); //string(1, expression[i]) permet de convertir un char en string
        }
    }
    cout << "Le resultat est " << this->depiler() << endl;
}

Maillon *pile::get() {
    if (this->tete != nullptr) {
        return this->tete;
    } else {
        return nullptr;
    }
}






//----------------------------------------------  Question 2  ----------------------------------------------------------




ChaineDeSortie::ChaineDeSortie() {
    this->tete = nullptr;
    this->queue = nullptr;
    this->nb_maillon = 0;
}

void ChaineDeSortie::ajouter(string op) { //ajoute un Maillon à la chaine de sortie
    if (this->tete == nullptr) {
        Maillon *o = new Maillon(op);
        this->tete = o;
        this->queue = o;
        this->nb_maillon++;
    } else {
        this->tete->suivant = new Maillon(op);
        this->nb_maillon++;
        this->tete = this->tete->suivant;
    }
}

void ChaineDeSortie::afficher() {
    Maillon *o = this->queue;
    while (o != nullptr) {
        cout << o->valeur;
        o = o->suivant;
    }
    cout << endl;
}

int getpriority (char op) { //retourne la priorité d'un opérateur
    if (op == '('){
        return 0; //parenthèse ouvrante
    }else if (op == '+' || op == '-'){
        return 1; //ajouterition, soustraction
    } else if (op == '*' || op == '/' || op == '%'){
        return 2; //multiplication, division, modulo
    } else if (op == '^'){
        return 3; //puissance (associativité à droite)
    }else if (op == ')') {
        return 4; //parenthèse fermante
    } else {
        return -1; //l'op donné est un operande
    }
}

void ChaineDeSortie::InfToSuf(string expression) { //transforme une expression infixe en expression suffixée
    pile p;
    for (int i = 0; i < expression.length()+1;i++) {
        string op = "";
        if (getpriority(expression[i]) == -1) { //si expression[i] (que l'on passe en string) est un opérande ou est vide
            if (expression[i] == '\0') { // si l'entrée est vide
                while (!p.vide()) { // tant que la pile n'est pas vide
                    this->ajouter(p.depiler()); // on ajoute les opérateurs de la pile à la chaine de sortie jusqu'à ce que la pile soit vide
                }
            } else { //si l'entrée n'est pas vide c'est un opérande
                op = expression[i];
                while (getpriority(expression[i+1]) ==-1 && expression[i+1] != '\0') { // tant que le caractére suivant est un opérande différant de vide = c'est un chiffre
                    op += expression[i+1]; // on concaténe les chiffres pour former le nombre final
                    i++;// on incrémente i pour passer au caractére suivant
                }
                this->ajouter(op + " "); //on ajoute directement le chiffre/nombre à la chaine de sortie suivit d'un espace pour séparer les opérandes
            }
        } else if (!p.vide()){ //si la pile n'est pas vide et que c'est un opérateur
            if (getpriority(expression[i])  == 3) { // si expression[i] (que l'on passe en string) est un ^ soit le seul oprérateur (utilisé ici) avec une associativité à droite en cpp
                while (getpriority(expression[i])  < getpriority(
                        p.get()->valeur[0])) { // tant que l'opérateur au sommet de la pile est strictement plus prioritaire que celui de l'expression
                    this->ajouter(p.depiler()); // on ajoute l'opérateur de la pile à la chaine de sortie
                }
                p.empiler(string(1, expression[i])); // on empile l'opérateur de l'expression
            }
            else if (getpriority(expression[i])  == 0) { // si expression[i] (que l'on passe en string) est une parenthèse ouvrante
                p.empiler(string(1, expression[i])); // on empile la parenthèse ouvrante directement
            } else if (getpriority(expression[i])  == 4) { // si expression[i] (que l'on passe en string) est une parenthèse fermante
                while (p.get()->valeur != "(") { // tant que l'opérateur au sommet de la pile n'est pas une parenthèse ouvrante
                    this->ajouter(p.depiler()); // on ajoute l'opérateur de la pile à la chaine de sortie
                }
                p.depiler(); // on dépile ensuite la parenthèse ouvrante
            } else { // pour tout les autres opérateurs qui on une associativité de gauche a droite
                while (!p.vide() && getpriority(expression[i])  <= getpriority(p.get()->valeur[0])) {// tant que l'opérateur au sommet de la pile est strictement plus prioritaire que celui de l'expression
                    this->ajouter(p.depiler()); // on ajoute l'opérateur de la pile à la chaine de sortie
                }
                p.empiler(string(1, expression[i])); // on empile l'opérateur de l'expression
            }
        } else { // si la pile est vide et que c'est un operateur
            p.empiler(string(1, expression[i])); // on empile l'opérateur de l'expression
        }
    }
    cout << "votre expression en format suffixee : ";
    this->afficher();
}




