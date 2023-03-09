#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <ctime>
#include <string>
#include "Personnage.h"

void menu(std::ofstream &flux,std::ifstream &f);
void optionJoueur(Personnage t[],int dim,int i,std::ofstream &flux,int choix=0);
void play(Personnage *tab,int nj,std::ofstream &flux);
void jouer1(Personnage *t,int nj,std::ofstream &flux);
void jouer2(Personnage *t,int nj,std::ofstream &flux);
void cloon(std::ofstream &e ,std::ifstream &l);
int lancePiece(int nbre);
void remplir(Personnage t[],int dim);
void afficher(Personnage t[],int dim);
void afficher(Personnage p);


#endif // FONCTIONS_H_INCLUDED
