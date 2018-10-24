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
   /*
        int (* fonction_hachage_1) (int ) ;
        int (* fonction_hachage_2) (int ) ;
        int (* fonction_hachage_3) (int ) ;
  */

    public:
        tableHachage() ;
        ~tableHachage() ;
        unsigned int hachage_Modulo( const unsigned int Numero_Produit ) ;
        void insererProduit( const produit p ) ;
        void Recherche_Produit(const produit p ) ;
        void Modifier_Produit( const produit p , unsigned int numero , double prix ) ;
        void Supprimer_Produit(const produit p ) ;
        unsigned int  Re_Hachage_Lineaire( const unsigned int indice );
        void affiche() const ;

};
