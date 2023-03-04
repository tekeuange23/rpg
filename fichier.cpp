#include "fichier.h"

using namespace std;

Arme::Arme() : a_nom("Epee"), a_degats(10){}
Arme::Arme(string nom, int degats) : a_nom(nom), a_degats(degats){}

void Arme::changer(string nom, int degats)
{
a_nom = nom;
a_degats = degats;
}
void Arme::afficher() const
{
cout <<"Arme : " << a_nom << " (Degats : " << a_degats << ")"<< endl;
cout<<endl;
}
int Arme::getDegats() const
{
    return a_degats;
}
string Arme::getNom()const
{
    return a_nom;
}
