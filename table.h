#include <stdlib.h>
#include <iostream>
#include "produit.h"
using namespace std ;

#define TAILLE 100

 typedef unsigned int (*PTR_Fonction) (unsigned int Numero_Produit , int i ) ;
 typedef int (*PTR_Fonction_PAS) (int i ) ;

class tableHachage
{
    private:

        produit tableaux[TAILLE] ;
        PTR_Fonction choix_hachage ;
        static PTR_Fonction_PAS pas_rehachage ;



    public:

        tableHachage() ;
        ~tableHachage() ;

        static unsigned int  hachage_Modulo( const unsigned int Numero_Produit ) ;

        static unsigned int  Re_Hachage_Lineaire(unsigned int Numero_Produit , int i);
        static unsigned int  Re_hachage_quadratique( unsigned int Numero_Produit, int i ) ;
        static unsigned int  Double_hachage( unsigned int Numero_Produit, int i ) ;

        static int  pas_rehachage_lineaire(int i) ;

        static int  pas_rehachage_quadratique( int i ) ;
        static int  pas_double_rehachage( int i ) ;


        int  Recherche_Produit(const produit p ) ;
        void insererProduit( const produit p ) ;
        void Modifier_CLE( const produit p , unsigned int numero ) ;
        void Modifier_PRIX( const produit p , double prix ) ;
        void Supprimer_Produit(const produit p ) ;

        void affiche() const ;
        void Affiche_Produit(const int indice) ;

};
