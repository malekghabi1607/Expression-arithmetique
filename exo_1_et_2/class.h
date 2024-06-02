
// class.h


#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>


using namespace std;

//----------------------------------------------  Question 1  ----------------------------------------------------------


class Maillon {
    string valeur; //valeur du Maillon
    Maillon *suivant; //pointeur vers le Maillon suivant
public:
    Maillon(); //constructeur par defaut
    Maillon(string valeur); //constructeur avec parametre (valeur)
    Maillon(string valeur, Maillon *suivant); //constructeur avec parametres (valeur et suivant)
    ~Maillon(); //destructeur
    friend class pile; //pile est une classe amie de Maillon
    friend class ChaineDeSortie ; // ChaineDeSortie est une classe amie de Maillon




};

class pile {
    Maillon *tete;//pointeur vers le premier maillon de la pile
    int nb_maillon;//nombre de maillon dans la pile

    public:
    pile(); //constructeur par defaut
    void empiler(string operande);//ajoute un maillon à la pile
    string depiler(); //supprime un maillon de la pile


    bool vide(); //verifie si la pile est vide
    Maillon *get(); //retourne le premier maillon de la pile
    void afficher(); //affiche la pile
    void evaluer(string expression); //évalue une expression arithmetique suffixée
    
};










//----------------------------------------------  Question 2   ----------------------------------------------------------


class ChaineDeSortie {
    Maillon *tete; //pointeur vers le premier Maillon de la pile
    Maillon *queue; //pointeur vers le dernier Maillon de la pile
    int nb_maillon; //nombre de Maillon dans la pile



public:
    ChaineDeSortie(); //constructeur par defaut
    void ajouter (string op); //ajoute un Maillon à la pile
    void afficher(); //affiche la pile
    void InfToSuf(string expression); //convertit une expression arithmétique infixe en suffixée
    int getcount(); //retourner le nombre de noeuds dans la chaine

};








#endif