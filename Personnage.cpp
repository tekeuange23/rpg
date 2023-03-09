#include "personnage.h"
using namespace std;

//CONSTRUCTEURS-DESTRUCTEURS
Personnage::Personnage() : a_nomP("PATOU"),a_vie(100),a_mana(100),a_arme(0){
    a_arme=new Arme();
}
Personnage::Personnage(std::string nomP,std::string nomArme,int degatsArme) : a_nomP(nomP),a_vie(100),a_mana(100),a_arme(0){
    a_arme=new Arme(nomArme,degatsArme);
}
Personnage::Personnage(std::string nomP,int vie,int mana,std::string nomArme,int degatsArme) : a_nomP(nomP), a_vie(vie),a_mana(mana),a_arme(0){
    a_arme=new Arme(nomArme,degatsArme);
}
Personnage::Personnage(Personnage const& p1):a_nomP(p1.a_nomP),a_vie(p1.a_vie),a_mana(p1.a_mana),a_arme(0){
    a_arme=new Arme(p1.a_arme->getNom()  ,  p1.a_arme->getDegats());
}
Personnage::~Personnage(){
    delete a_arme;  a_arme=0;
}

//METHODES
void Personnage::recevoirDegats(int nbreDegats){
    a_vie =a_vie - nbreDegats;
    if(a_vie<0)
        a_vie=0;
}
bool Personnage::recevoirMana(int mana){
    if(mana>a_mana)
    {
        cout<<"veillez recharger votre mana"<<endl;

        return false;
    }
    else
    {
        a_vie=a_vie-mana;
        if (a_vie<0)
            a_vie=0;
        return true;

    }
}
void Personnage::attaquer(Personnage &cible){
    cible.recevoirDegats(a_arme->getDegats());
    cout<<cible.a_nomP<<" est entrain de se faire massacre par "<<a_nomP<<" a coup de "<<a_arme->getNom()<<endl;
}
void Personnage::attaquerMana(Personnage &cible){
    if (cible.recevoirMana()==true)
    {
        a_mana=a_mana-20;
        cible.recevoirMana();
        cout<<cible.a_nomP<<" est entrain de se faire massacre par "<<a_nomP<<" qui utilise toute sa magie "<<endl;
    }

}
void Personnage::boirePotion(int qtePotion){
    a_vie =a_vie + qtePotion;
    if(a_vie>100)
        a_vie=100;
        cout<<"++++ votre vie a augmentee de + "<<qtePotion<<endl;
}
void Personnage::changerArme(std::string nomArme, int degatsArme){
    a_arme->changer(nomArme,degatsArme);
    cout<<"changement d'arme reussi"<<endl;
}
void Personnage::changerNom(string nomP){
    a_nomP=nomP;
    cout<<"changement de nom reussi"<<endl;
}
bool Personnage::estVivant() const{
    return a_vie>0;
}
void Personnage::affichePoucentageDeVie()const{
    cout<<"Vie :: "<<a_vie<<"% ))";
}
void Personnage::afficherEtat()const{
    cout<<"Nom: "<<a_nomP<<endl;
    cout<<"Vie: "<<a_vie<<endl;
    cout<<"Mana: "<<a_mana<<endl;
    a_arme->afficher();
}
void Personnage::affiche() const{
    cout<<" ||NOM:"<<a_nomP<<endl;
        cout<<" ||VIE:"<<a_vie<<endl;
        cout<<" ||POWER:"<<a_mana<<endl;
        cout<<" ||ARME:"<<a_arme->getNom()<<endl;
        cout<<" ||DEGATS:"<<a_arme->getDegats()<<endl;
}

//ACCESSEURS
string Personnage::getNomP()const  {
    return a_nomP;
}
int Personnage::getVie()const   {
    return a_vie;
}
int Personnage::getMana()const  {
    return a_mana;
}
Arme* Personnage::getArm()const{
    return a_arme;
}

