#include <stdlib.h>
#include <iostream>
#include "produit.h"
using namespace std ;

#define TAILLE 10

class tableHachage
{
    private:
      // const int taille_Tableau = 50;
        produit tableaux[TAILLE] ;

    public:
        tableHachage() ;
        ~tableHachage() ;
        unsigned int hachage_Modulo( const unsigned int Numero_Produit ) ;
        void insererProduit( const produit p ) ;
        bool Produit_Existe(const produit p );
        unsigned int Recherche_Produit (const produit p ) ;
        unsigned int  Re_Hachage_Lineaire( const unsigned int indice );
        void affiche() const ;







};
