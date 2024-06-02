//main.cpp

#include "class.h"
#include <iostream>
#include <string>
using namespace std;

int main() {



//----------------------------------------------  Question 1  ----------------------------------------------------------

    cout << "=========================================Question 1=========================================" << endl;
    pile p; //creation d'une pile
    string expression; //creation d'une chaine de caractere
    cout << "Entrez une expression arithmetique suffixee a calculer avec des espaces aprés chaque nombre : " << endl;
    getline(cin, expression); //lecture de la chaine de caractere en entier (toute la ligne)
    p.evaluer(expression); //appel de la methode évaluer qui évalue une expression suffixée


//----------------------------------------------  Question 2  ----------------------------------------------------------
cout  << "=========================================Question 2========================================="<<endl;
    cout << "entrez une expression arithmetique infixe : ";
    ChaineDeSortie o; //creation d'une chaine de sortie
    string expression2; // création d'une chaîne de caractères pour Question 2
    getline(cin, expression2); //recuperation de l'expression arithmetique
    o.InfToSuf(expression2); //appel de la methode InfToSuf qui transforme une expression infixe en expression suffixée



//----------------------------------------------  Question 3  ----------------------------------------------------------


}




