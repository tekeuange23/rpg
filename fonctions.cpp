#include "fonctions.h"
using namespace std;

void menu(ofstream &flux,ifstream &f){
     b1:

        cout<<"--------------------------------------"<<endl;
        cout<<"||----------------------------------||"<<endl;
        cout<<"||              MAIN MENU           ||"<<endl;
        cout<<"||----------------------------------||"<<endl;
        cout<<"||                                  ||"<<endl;
        cout<<"|| 1-CONTINUER                      ||"<<endl;
        cout<<"|| 2-NOUVELLE PARTIE                ||"<<endl;
        cout<<"|| 3-OPTIONS                        ||"<<endl;
        cout<<"|| 4-QUITTER                        ||"<<endl;
        cout<<"||                                  ||"<<endl;
        cout<<"||----------------------------------||"<<endl;
        cout<<"--------------------------------------\n\n"<<endl;

        int choix(0);
        string nom;
        cout<<"Votre choix ??? \n"; cin>>choix;

        switch (choix)
        {
        case 1:

            if(!f)
                cout<<"ERROR";
            else
            {
                string s[2];
                int E[4];
                int i1,i2;
                Personnage *p1,*p2;

                f>>i1;    f>>s[0];    f>>E[0];    f>>E[1];    f>>s[1];    f>>E[2];
                p1=new Personnage(s[0],E[0],E[1],s[1],E[2]);
                f>>i2;     f>>s[0];    f>>E[0];    f>>E[1];    f>>s[1];    f>>E[2];
                p2=new Personnage(s[0],E[0],E[1],s[1],E[2]);

            }
            break;

        case 2:
            Personnage *tj;
            int nbjoueur;

            cout<<"Entrer le nombre de joueurs (1 ou 2) ??? "; cin>>nbjoueur;

            tj=new Personnage[2];
            play(tj,nbjoueur,flux);
            break;

        case 3:
            break;

        case 4:
            exit(1);
            break;

        default:
            goto b1;

        }
}
void optionJoueur(Personnage t[],int dim,int i,ofstream &flux,int choix){
    b1:

        cout<<"--------------------------------------------------------------"<<endl;
        cout<<"||----------------------------------------------------------||"<<endl;
        cout<<"||                    LES OPTIONS DU JOUEUR                 ||"<<endl;
        cout<<"||                                                          ||"<<endl;
        cout<<"|| 1-Attaquer avec votre arme                               ||"<<endl;
        cout<<"|| 2-Attaquer avec la magie                                 ||"<<endl;
        cout<<"|| 3-Boire potion                                           ||"<<endl;
        cout<<"|| 4-Changer Nom                                            ||"<<endl;
        cout<<"|| 5-Changer Arme                                           ||"<<endl;
        cout<<"|| 6-QUITTER                                                ||"<<endl;
        cout<<"||----------------------------------------------------------||"<<endl;
        cout<<"--------------------------------------------------------------\n\n"<<endl;

        string nom;

        switch (choix)
        {
        case 1:
            if(i==0)
                t[i].attaquer(t[i+1]);
            else
                t[i].attaquer(t[i-1]);
            break;
        case 2:
            if(i==0)
                t[i].attaquerMana(t[i+1]);
            else
                t[i].attaquerMana(t[i-1]);
            break;
        case 3:
            t[i].boirePotion();
            break;
        case 4:
            cout<<"Entrer votre nouveau nom ???  ";  cin>>nom;
            t[i].changerNom(nom);
            break;
        case 5:
            cout<<"Entrer votre nouvel arme  ???  ";  cin>>nom;
            t[i].changerArme(nom,20);
            break;
        case 6:
            if(i==0) cout<<"Joueur "<<t[1].getNomP()<<" Votre advetrsaire a compris qu'il n'etais pas de taille, il se prepare."<<endl; else cout<<"Joueur "<<t[0].getNomP()<<" Votre advetrsaire a compris qu'il n'etais pas de taille, il se prepare."<<endl;


            if(!flux)
                cout<<"ERROR";
            else
            {
                flux<<0<<" "<<t[0].getNomP()<<" "<<t[0].getVie()<<" "<<t[0].getMana()<<" "<<t[0].getArm()->getNom()<<" "<<t[0].getArm()->getDegats()<<endl;
                flux<<1<<" "<<t[1].getNomP()<<" "<<t[1].getVie()<<" "<<t[1].getMana()<<" "<<t[1].getArm()->getNom()<<" "<<t[1].getArm()->getDegats()<<endl;
            }

            delete t;
            t=0;
            exit(1);
            break;

        default:
            goto b1;

        }
}
void play(Personnage *tab,int nj,ofstream &flux){

    switch (nj)
    {
    case 1:
        cout<<"Entrer vos coordonnes et ceux de votre adversaire"<<endl;
        remplir(tab,2);
        jouer1(tab,2,flux);

        delete tab;
        tab=0;
        break;
    case 2:
        remplir(tab,nj);
        jouer2(tab,nj,flux);

        delete tab;
        tab=0;
        break;

    default:
        cout<<"error"<<endl;
        exit(1);

    }
}
void jouer1(Personnage *t,int nj,ofstream &flux){
    int choix,tour;
    tour=lancePiece(nj);
    while(t[0].estVivant() && t[1].estVivant())
    {
        cout<<"Joueur "<<t[tour].getNomP()<<" c'est a vous de jouer :: soyez sans pitiee\n\n\n"<<endl;
        t[tour].afficherEtat();
        afficher(t,nj);
        cout<<endl;

        if(tour==0)
        {   cout<<"Votre choix ??? \n"; cin>>choix;
            optionJoueur(t,2,tour,flux,choix);
        }
        else
        {
            optionJoueur(t,2,tour,flux,lancePiece(3)+1);
        }
        cout<<"\n\n\n\n\n";

        if(tour==0)
            tour=1;
        else
            tour=0;
        }

        if(t[0].estVivant())
            cout<<"Joueur "<<t[0].getNomP()<<" vous sortez gagnant de se duel cruel"<<endl;
        else
            cout<<"Joueur "<<t[1].getNomP()<<" vous sortez gagnant de se duel cruel"<<endl;
}
void jouer2(Personnage *t,int nj,ofstream &flux){
    int choix,tour;
    tour=lancePiece(nj);
    while(t[0].estVivant() && t[1].estVivant())
    {
        cout<<"Joueur "<<t[tour].getNomP()<<" c'est a vous de jouer :: soyez sans pitiee\n\n\n"<<endl;
        t[tour].afficherEtat();
        afficher(t,nj);
        cout<<endl;

        cout<<"Votre choix ??? \n"; cin>>choix;
        optionJoueur(t,2,tour,flux);
        cout<<"\n\n\n\n\n";

        if(tour==0)
            tour=1;
        else
            tour=0;
        }

        if(t[0].estVivant())
            cout<<"Joueur "<<t[0].getNomP()<<" vous sortez gagnant de se duel cruel"<<endl;
        else
            cout<<"Joueur "<<t[1].getNomP()<<" vous sortez gagnant de se duel cruel"<<endl;
}
void cloon(ofstream &e ,ifstream &l){
    if(e && l)
    {
        string ligne;
        while( getline(l,ligne) )
        {
            e<<ligne<<endl;
        }
    }
    else
        cout<<"ERROR"<<endl;
}
int lancePiece(int nbre){
    srand(time(0));
    return rand() % nbre;

}
void remplir(Personnage t[],int dim){
    string nomP;
    string nomA;
    for(int i(0);i<dim;i++)
    {
        cout<<"Joueur numero"<<i+1<<" entrer votre:"<<endl;
        cout<<"Nom: "; cin>>nomP; t[i].changerNom(nomP);
        cout<<"Nom arme: "; cin>>nomA; t[i].changerArme(nomA);
        cout<<endl;
    }
}
void afficher(Personnage t[],int dim){
    for(int i(0);i<dim;i++)
    {
        t[i].affichePoucentageDeVie();
        cout<<"  Joueur numero"<<(i+1)
            <<" =>  ||NOM:"<<t[i].getNomP()
            <<" ||VIE:"<<t[i].getVie()
            <<" ||POWER:"<<t[i].getMana()
            <<" ||ARME:"<<t[i].getArm()->getNom()
            <<" ||DEGATS:"<<t[i].getArm()->getDegats()
            <<endl;
        cout<<endl;
    }
}
void afficher(Personnage p){
        cout<<"    "<<p.estVivant();
        cout<<" =>  ||NOM:"<<p.getNomP()<<" ||VIE:"<<p.getVie()<<" ||POWER:"<<p.getMana()<<" ||ARME:"<<p.getArm()->getNom()<<" ||DEGATS:"<<p.getArm()->getDegats()<<endl;
}
