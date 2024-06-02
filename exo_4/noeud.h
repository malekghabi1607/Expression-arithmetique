#ifndef NOEUD_H
#define NOEUD_H

class noeud {
    char type; // 'o' pour operateur, 'r' pour valeur et 'v' pour variable
    char var;
    char ope;
    float val;
    noeud *fg, *fd;
    noeud *Osuivant; // Suivant dans la file d'ChaineDeSortie (pour la transformation d'infixe en sufixe)
    noeud *Psuivant; // Suivant dans la pile

public:
    noeud(); // constructeur par défaut
    noeud(char caractere); // constructeur avec paramètre
    noeud(float val); // constructeur avec valeur numérique
    void afficher(); // afficher le noeud

    ~noeud(); // destructeur de noeud

    friend class arbre;
    friend class ChaineDeSortie;
    friend class pile;
};

#endif
