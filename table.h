#include <stdlib.h>
#include <iostream>
#include "produit.h"
using namespace std ;

#define TAILLE 4

 typedef unsigned int (*PTR_Fonction) (unsigned int ) ;

class tableHachage
{
    private:

        produit tableaux[TAILLE] ;
/*
        unsigned int (* Re_hachage_lineaire ) ( unsigned int NumeroP) ;
        unsigned int (* Re_hachage_quadratique) ( unsigned int NumeroP) ;
        unsigned int (* Double_hachage ) ( unsigned int NumeroP) ;
*/
         PTR_Fonction choix_hachage ;
         int pas ;


    public:
        tableHachage() ;
        ~tableHachage() ;
        unsigned int hachage_Modulo( const unsigned int Numero_Produit ) ;
static  unsigned int  Re_Hachage_Lineaire( unsigned int indice );
static  unsigned int  Re_hachage_quadratique( unsigned int indice ) ;
static  unsigned int  Double_hachage( unsigned int indice ) ;
        void insererProduit( const produit p ) ;
        void Recherche_Produit(const produit p ) ;
        void Modifier_Produit( const produit p , unsigned int numero , double prix ) ;
        void Supprimer_Produit(const produit p ) ;

        void affiche() const ;

};
