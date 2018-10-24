#include <stdlib.h>
#include <iostream>
#include "table.h"

using namespace std ;

 tableHachage::tableHachage()
 {


 }
 tableHachage::~tableHachage()
 {
    // JE SAIS PAS
 }

 unsigned int tableHachage::hachage_Modulo(const unsigned int Numero_Produit)
 {
    return Numero_Produit % TAILLE ;
 }

 unsigned int tableHachage::Re_Hachage_Lineaire( const unsigned int indice )
 {
    return ( indice+1 ) % TAILLE ;
 }

 bool tableHachage::Produit_Existe(const produit p )
 {
    int indice = hachage_Modulo( p.NumeroProduit ) ;

        if ( tableaux[indice].NumeroProduit == p.NumeroProduit )
        {
            return true ;
        }
        else
        {
            return false ;
        }

 }

 unsigned int tableHachage::Recherche_Produit(const produit p )
 {
    int indice ;

    if( Produit_Existe(p) )
    {
         indice = hachage_Modulo( p.NumeroProduit ) ;

             cout <<" Le produit est a l'indice "<< indice << " du tableau "<<endl;
            return tableaux[indice].NumeroProduit ;

    }
    else
    {
        cout <<" ce produit n'existe pas dans le tableau "<<endl;
    }

  //  return ;

 }


 void tableHachage::insererProduit(const produit p )
 {
    int compteur = 0;
    int indice ;

    indice = hachage_Modulo( p.NumeroProduit ) ;

    if(tableaux[indice].NumeroProduit == 0 )
    {
        tableaux[indice] = p ;

    }
    else
    {
        int indice_2 = indice ;
        do
        {
            indice_2 = Re_Hachage_Lineaire(indice_2) ;
            compteur++ ;


        }while (tableaux[indice_2].NumeroProduit != 0 && compteur !=TAILLE );

        if( compteur== TAILLE )
        {
            cout<<"Votre tableau est plein des ELEMENTS n'ont pas été inserer " <<endl;

        }
        else
        {
            tableaux[indice_2] = p;

        }
    }


 }



 void tableHachage::affiche() const
 {
    for (int i=0 ; i<TAILLE; i++ )
    {
       cout<<"tab["<<i<<"] : "<< tableaux[i].NumeroProduit<< " " <<endl;
    }
    cout<<endl;
 }


