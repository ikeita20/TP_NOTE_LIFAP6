#include <stdlib.h>
#include <iostream>
#include "produit.h"
using namespace std ;

#define TAILLE 200

 typedef unsigned int (*PTR_Fonction) (unsigned int Numero_Produit , int i ) ;

class tableHachage
{
    private:

        produit tableaux[TAILLE] ;
        PTR_Fonction choix_hachage ;
        static unsigned int pas ;


    public:

        tableHachage() ;
        ~tableHachage() ;

        static unsigned int hachage_Modulo( const unsigned int Numero_Produit ) ;
        static unsigned int  Re_Hachage_Lineaire(unsigned int Numero_Produit , int i);
        static unsigned int  Re_hachage_quadratique( unsigned int Numero_Produit, int i ) ;
        static unsigned int  Double_hachage( unsigned int Numero_Produit, int i ) ;

        int  Recherche_Produit(const produit p ) ;
        void insererProduit( const produit p ) ;
        void Modifier_Produit( const produit p , unsigned int numero , double prix ) ;
        void Supprimer_Produit(const produit p ) ;

        void affiche() const ;

};
