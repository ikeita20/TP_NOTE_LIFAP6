#include <stdlib.h>
#include <iostream>
#include "table.h"

using namespace std ;



 tableHachage::tableHachage()
 {

// unsigned int (*listeFonctions[2])(unsigned int) = {Re_Hachage_Lineaire,hachage_Modulo};

    int choix_utilisateur ;

    do
    {
    cout <<"----------------------------"<<endl;
    cout<< " ****** Votre choix ********"<<endl;

    cout <<" 1 = Re-Hachage lineaire "<<endl;
    cout <<" 2 = Re-Hachage quadratique  "<<endl;
    cout <<" 3 = Double Hachage  "<<endl;
    cout<< "----------------------------"<<endl;
    cout<<endl;
    cout<< "Donnez votre choix : ";
    cin>>choix_utilisateur ;

    } while (choix_utilisateur< 1 || choix_utilisateur > 3 );

    switch( choix_utilisateur )
    {

        case 1 :
                choix_hachage = Re_Hachage_Lineaire;
         break ;

         case 2 :

         /*
                choix_hachage = Re_hachage_quadratique ;
                cout<<"Donnez le pas du Re_hachage_quadratique  : "<<endl;
                cin>>pas ;
		
		*/

          break ;

          case 3 :
              // choix_hachage = Double_hachage ;
          break ;

          default:
                choix_hachage = Re_Hachage_Lineaire;
          break ;

    }

 }

 tableHachage::~tableHachage()
 {
    // JE SAIS PAS
 }

 unsigned int tableHachage::hachage_Modulo(const unsigned int Numero_Produit)
 {
    return Numero_Produit % TAILLE ;
 }

 unsigned int tableHachage::Re_Hachage_Lineaire( unsigned int indice )
 {
    return ( indice+1 ) % TAILLE ;
 }



 void tableHachage::insererProduit(const produit p )
 {
    int compteur = 0;
    int indice ;
    int Essai = 0 ;

    for(int i= 0 ; i<TAILLE ; i++ )
    {
        if(tableaux[i].NumeroProduit == p.NumeroProduit )
        {
            cout<< "ce produit existe"<<endl;
        }
    }


    indice = hachage_Modulo( p.NumeroProduit ) ;

    if(tableaux[indice].NumeroProduit == 0 )
    {
        tableaux[indice] = p ;
       tableaux[indice].essai =  Essai + 1 ;
       Essai = tableaux[indice].essai ;

    }
    else
    {
        int indice_2 = indice ;
        do
        {
            indice_2 = (*choix_hachage)(indice_2) ;
            compteur++ ;
             tableaux[indice].essai = Essai + 1 ;
             Essai = tableaux[indice].essai ;


        }while (tableaux[indice_2].NumeroProduit != 0 && compteur !=TAILLE );


        if( compteur== TAILLE )
        {
            cout<<"Votre tableau est plein des ELEMENTS n'ont pas été inserer " <<endl;

        }
        else
        {
            tableaux[indice_2] = p;

            tableaux[indice_2].essai = Essai ;

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
                    indice_2 = (*choix_hachage)(indice_2) ;
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
                    indice_2 = (*choix_hachage)(indice_2) ;
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
       cout<<"tab["<<i<<"] : "<< tableaux[i].NumeroProduit<< " ";
       cout<<"Nombre d'essai "<< tableaux[i].essai<< " " <<endl;
    }
    cout<<endl;
 }


