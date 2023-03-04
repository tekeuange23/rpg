#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED


#include <iostream>
#include <string>

class Arme
{
public:
    Arme();
    Arme(std::string nom,int degats=10);

    void changer(std::string nom,int degats);
    void afficher()const;
    int getDegats()const;
    std::string getNom()const;

private:
    std::string a_nom;
    int a_degats;
};


#endif // FICHIER_H_INCLUDED
