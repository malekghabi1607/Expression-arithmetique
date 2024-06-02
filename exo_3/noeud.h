#ifndef NOEUD_H
#define NOEUD_H


class noeud {
    char type; // 'o' pour operateur, 'f' pour valeur
    char ope;
    float val;
    noeud *fg,*fd;
    noeud *Osuivant; // Suivant dans la file de chaine de sortie (pour la transformation d'infixe en sufixe)
    noeud *Psuivant; // Suivant dans la pile
public:
    noeud(); //constructeur par défaut
    noeud(char caractere); //constructeur avec paramètre

    ~noeud(); //destructeur de noeud

    friend class arbre;
    friend class ChaineDeSortie;
    friend class pile;
};


#endif 
