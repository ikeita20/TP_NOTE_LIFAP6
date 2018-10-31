#include <stdlib.h>
#include <iostream>
#include "table.h"
#include <time.h>
#include<fstream>

using namespace std ;

 unsigned int tableHachage::pas = 0 ;


 tableHachage::tableHachage()
 {



    int choix_utilisateur ;

    do
    {
    cout <<"--------------------------------------------------------------"<<endl;
    cout<< " ****** Choisissez votre Fonction de Ré-HACHAGE ! ********"<<endl; cout<<endl;

    cout <<" 1 = Re-Hachage lineaire "<<endl;
    cout <<" 2 = Re-Hachage quadratique  "<<endl;
    cout <<" 3 = Double Hachage  "<<endl;
    cout<< "--------------------------------------------------------------"<<endl;
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
                choix_hachage = Re_hachage_quadratique ;
          break ;

          case 3 :
              choix_hachage = Double_hachage ;
              cout<<"donnez le pas de Re_hachage  : ";
              cin>>pas ;
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

 unsigned int tableHachage::Re_Hachage_Lineaire( unsigned int Numero_Produit , int i  )
 {
   int indice  = ( hachage_Modulo(Numero_Produit) + (i-1 ) ) % TAILLE ;

   return indice ;
 }

 unsigned int tableHachage::Re_hachage_quadratique(unsigned int Numero_Produit , int i )
 {
    int indice  = ( hachage_Modulo(Numero_Produit) + ( (i-1)*(i-1)  ) ) % TAILLE ;

    return indice ;

 }

 unsigned int tableHachage::Double_hachage( unsigned int Numero_Produit, int i)
 {

    int indice =  ( hachage_Modulo(Numero_Produit) + ( pas *(i-1)  ) ) % TAILLE ;
    return indice ;
 }


 void tableHachage::insererProduit(const produit p )
 {
       int indice ;
       int i = 1 ;

       do
       {
            indice  = (*choix_hachage)(p.NumeroProduit,i ) ;
            i++;

       }while(tableaux[indice].NumeroProduit !=0 && tableaux[indice].NumeroProduit != p.NumeroProduit && i<TAILLE );

       if( tableaux[indice].NumeroProduit == p.NumeroProduit )
       {
            cout<< "Desolé ! Ce produit existe deja dans la table  "<<endl;

       }
       else
       {
            if (tableaux[indice].NumeroProduit == 0 )
            {
                tableaux[indice].NumeroProduit = p.NumeroProduit ;
                tableaux[indice].Prix = p.Prix ;
                tableaux[indice].essai =  i - 1 ;

            }

            else
            {
                cout << "Votre tableau est plein  "<<endl;

            }

       }


 }




  int tableHachage::Recherche_Produit(const produit p)
 {

     int indice ;
    int i = 1 ;
    clock_t temps ;
    double seconde ;

           do
           {
                indice  = (*choix_hachage)(p.NumeroProduit,i ) ;
                i++;
                temps = clock() ;
                seconde = (double) temps / CLOCKS_PER_SEC ;


           }while( tableaux[indice].NumeroProduit != p.NumeroProduit && i<=TAILLE );


           if( tableaux[indice].NumeroProduit == p.NumeroProduit )
           {
              //  cout <<" Le produit "<< p.NumeroProduit << " est a l'indice "<< indice << " du tableau "<<endl;
                cout<< "Numero Produit : "<< tableaux[indice].NumeroProduit  <<endl;
                cout<< "Prix: "<< tableaux[indice].Prix  <<endl;
                cout<< "Nbre essai : "<< tableaux[indice].essai  <<endl;
                cout<<endl;


                ofstream fichier("Performance.txt", ios::app );
                if(fichier.is_open() )
                {

                    cout<<endl; cout<<endl;

                    fichier<< "      "<<tableaux[indice].NumeroProduit<< "           "<< seconde <<endl;


                }
                else
                {
                    cerr<<"Impossible d'ouvrir le fichier " <<endl;
                }

                return indice ;


           }
           else
           {

              cout <<" Le produit "<< p.NumeroProduit << " n'existe pas dans le tableau "<<endl;
              return -1 ;

           }


 }

void tableHachage:: Modifier_Produit( const produit p , unsigned int numero , double prix )//recherche ici aussi
{

   int indice = Recherche_Produit(p) ;

    if ( tableaux[indice].NumeroProduit == p.NumeroProduit  )
    {

        tableaux[indice].NumeroProduit = numero;
        tableaux[indice].Prix = prix ;
        cout<< "Produit modifié avec success :) " <<endl;
    }

}

void tableHachage::Supprimer_Produit(const produit p )
 {
    unsigned int indice = Recherche_Produit(p) ;

    if (tableaux[indice].NumeroProduit ==  p.NumeroProduit )
    {
        tableaux[indice].NumeroProduit = 0 ;
        tableaux[indice].Prix = 0.0 ;
        tableaux[indice].essai = 0 ;
    }
    else
    {

    }

 }


 void tableHachage::affiche() const
 {
    for (int i=0 ; i<TAILLE; i++ )
    {
       cout<<"tab["<<i<<"] : "<< tableaux[i].NumeroProduit<< " ";
       cout<<" prix  "<< tableaux[i].Prix<< " ";
       cout<<"Nombre d'essai "<< tableaux[i].essai<< " " <<endl;
    }
    cout<<endl;
 }
