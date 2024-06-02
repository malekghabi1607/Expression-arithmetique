#include "arbre.h"
#include <iostream>
using namespace std;

int main(){
cout  << "=========================================Question 4========================================="<<endl;
    cout << "Entrez une expression infixe sans espace (avec un X majuscule) : " << endl;
    string expinf;
    cin >> expinf;


    arbre *A = new arbre (expinf);
    cout << endl;
    cout << "L'arbre de votre expression : " << endl;
    A->afficher();
    cout << endl << "L'expression infixe de votre arbre : ";
    A->afficherInfixe();
    cout << endl;
    A->deriver();
    cout << endl;

    //  afficher la dérivée exacte  de l'expression
    A->afficherDerivee();
    cout << endl;

 


    delete A;  
    return 0;
}