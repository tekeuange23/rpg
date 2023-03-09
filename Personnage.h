#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

#include <iostream>
#include <string>
#include "fichier.h"

class Personnage
{
public:
    Personnage();
    Personnage(std::string nomP,std::string nomArme, int degatsArme=10);
    Personnage(std::string nomP,int vie,int mana,std::string nomArme,int degatsArme=10);
    Personnage(Personnage const& p1);
    ~Personnage();

    void recevoirDegats(int nbreDegats);
    bool recevoirMana(int mana=10);
    void attaquer(Personnage &cible);
    void attaquerMana(Personnage &cible);
    void boirePotion(int qtePotion=20);
    void changerArme(std::string nomArme, int degatsArme=20);
    void changerNom(std::string nomP);
    void affiche() const;
    bool estVivant()const;
    void affichePoucentageDeVie()const;
    void afficherEtat() const;

    std::string getNomP()const;
    int getVie()const;
    int getMana()const;
    Arme* getArm()const;


private:
    std::string a_nomP;
    int a_vie;
    int a_mana;
    Arme *a_arme;
};

#endif // PERSONNAGE_H_INCLUDED
