#include "arbre.h"
#include <iostream>
using namespace std;

int main(){
cout  << "=========================================Question 3========================================="<<endl;
    cout << "entrez une expression infixe" << endl;
    string expinf;
    cin >> expinf;
    arbre *A = new arbre (expinf);
    cout << endl;
    A->afficher();
    cout << endl;
    cout << "l'expression donnee est egale a : " << A->evaluer() << endl;
    cout << endl;
    A->afficherInfixe();
    cout << endl;
    delete A;
}