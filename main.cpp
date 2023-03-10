#include "personnage.h"
#include "fonctions.h"

using namespace std;


int main()
{
    string const f("E:/ANGE/Projets/C++/jeu RPG/Save.txt");
    ifstream fluxO(f.c_str());
    string const g("E:/ANGE/Projets/C++/jeu RPG/Load.txt");
    ofstream loadI(g.c_str());

    cloon(loadI,fluxO);

    ofstream fluxI(f.c_str());
    ifstream loadO(g.c_str());

    menu(fluxI,loadO);

    return 0;
}
