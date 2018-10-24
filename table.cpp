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


 void tableHachage::Recherche_Produit(const produit p )
 {
    int indice ;

         indice = hachage_Modulo( p.NumeroProduit ) ;

        if ( tableaux[indice].NumeroProduit == p.NumeroProduit  )
        {
            cout <<" Le produit "<< p.NumeroProduit << " est a l'indice "<< indice << " du tableau "<<endl;

           // return tableaux[indice].NumeroProduit ;
        }
        else
        {
            int compteur = 0 ;

            int indice_2 = indice ;
                do
                {
                    indice_2 = Re_Hachage_Lineaire(indice_2) ;
                    compteur++ ;

                } while ( ( tableaux[indice_2].NumeroProduit != p.NumeroProduit) && compteur <= TAILLE );


                if ( ( tableaux[indice_2].NumeroProduit != p.NumeroProduit) || (compteur >= TAILLE ) )
                {
                    cout<< " ce produit n'existe pas dans le tableau "<<endl;

                }
                else
                {
                    cout <<" Le produit "<< p.NumeroProduit << " est a l'indice "<< indice_2 << " du tableau "<<endl;
                     //return tableaux[indice_2].NumeroProduit ;
                }



        }


 }

 void tableHachage::Supprimer_Produit(const produit p )
 {
    int indice ;

         indice = hachage_Modulo( p.NumeroProduit ) ;

        if ( tableaux[indice].NumeroProduit == p.NumeroProduit  )
        {

           tableaux[indice].NumeroProduit = 0 ;
           tableaux[indice].Prix = 0 ;
            cout<< "Produit supprimé avec success :) " <<endl;
        }
        else
        {
            int compteur = 0 ;

            int indice_2 = indice ;
                do
                {
                    indice_2 = Re_Hachage_Lineaire(indice_2) ;
                    compteur++ ;

                } while ( ( tableaux[indice_2].NumeroProduit != p.NumeroProduit) && compteur <= TAILLE );


                if ( ( tableaux[indice_2].NumeroProduit != p.NumeroProduit) || (compteur >= TAILLE ) )
                {
                    cout<< " ce produit n'existe pas dans le tableau "<<endl;

                }
                else
                {
                    tableaux[indice].NumeroProduit = 0 ;
                    tableaux[indice].Prix = 0 ;
                    cout<< "Produit supprimé avec success :) " <<endl;
                }

        }

 }

void tableHachage:: Modifier_Produit( const produit p , unsigned int numero , double prix )
{
    int indice = hachage_Modulo( p.NumeroProduit ) ;

        if ( tableaux[indice].NumeroProduit == p.NumeroProduit  )
        {

           tableaux[indice].NumeroProduit = numero;
           tableaux[indice].Prix = prix ;
            cout<< "Produit modifié avec success :) " <<endl;
        }
        else
        {
            int compteur = 0 ;

            int indice_2 = indice ;
                do
                {
                    indice_2 = Re_Hachage_Lineaire(indice_2) ;
                    compteur++ ;

                } while ( ( tableaux[indice_2].NumeroProduit != p.NumeroProduit) && compteur <= TAILLE );


                if ( ( tableaux[indice_2].NumeroProduit != p.NumeroProduit) || (compteur >= TAILLE ) )
                {
                    cout<< " ce produit n'existe pas dans le tableau "<<endl;

                }
                else
                {
                    tableaux[indice].NumeroProduit = numero ;
                    tableaux[indice].Prix = prix ;
                    cout<< "Produit modifié avec success :) " <<endl;
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


