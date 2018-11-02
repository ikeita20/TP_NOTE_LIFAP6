#include <stdlib.h>
#include <iostream>
#include "table.h"
#include <math.h>
#include <time.h>
#include<fstream>
#include <string>
#include <stdexcept>


using namespace std ;


PTR_Fonction_PAS tableHachage::pas_rehachage = NULL ;

 tableHachage::tableHachage()
 {



    int choix_utilisateur ;
    string choix_string;

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
    cin>>choix_string ;

    try {
        choix_utilisateur = std::stoi(choix_string);
    }
    catch (const std::invalid_argument& e) {
      choix_utilisateur = 45;
      cout << "Veuillez écrire un nombre entier !\n";

    }

    } while (choix_utilisateur< 1 || choix_utilisateur > 3 );

    switch( choix_utilisateur )
    {

        case 1 :
                choix_hachage = Re_Hachage_Lineaire;
                pas_rehachage = pas_rehachage_lineaire;
         break ;

         case 2 :
                choix_hachage = Re_hachage_quadratique ;
                 pas_rehachage = pas_rehachage_quadratique;
          break ;

          case 3 :
              choix_hachage = Double_hachage ;
               pas_rehachage = pas_double_rehachage;

          break ;

          default:
                choix_hachage = Re_Hachage_Lineaire;
                pas_rehachage = pas_rehachage_lineaire;
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
   int indice  = ( hachage_Modulo(Numero_Produit) + (*pas_rehachage)(i) ) % TAILLE ;

   return indice ;
 }

 unsigned int tableHachage::Re_hachage_quadratique(unsigned int Numero_Produit , int i )
 {
    int indice  = ( hachage_Modulo(Numero_Produit) + (*pas_rehachage)(i) ) % TAILLE ;

    return indice ;

 }

unsigned int tableHachage::Double_hachage( unsigned int Numero_Produit, int i)
{

    int indice =  ( hachage_Modulo(Numero_Produit) + (  (*pas_rehachage)(i) * (i-1)  )  ) % TAILLE ;
    return indice ;
 }



int tableHachage::pas_rehachage_lineaire(int i )
 {
    return (i-1) ;
 }

int tableHachage::pas_rehachage_quadratique(int i )
 {
    return ( (i-1)*(i-1) ) ;
 }

  int tableHachage::pas_double_rehachage(int i )
 {
    i = (i % TAILLE )-1 ;
    return 2*pow(2,i) +1 ;
 }



 void tableHachage::insererProduit(const produit p )
 {
       int indice ;
       int i = 1 ;

       do
       {
            indice  = (*choix_hachage)(p.NumeroProduit,i ) ;
            i++;

       }while(tableaux[indice].NumeroProduit != 0 && tableaux[indice].NumeroProduit != p.NumeroProduit && i<=TAILLE );

       if( tableaux[indice].NumeroProduit == p.NumeroProduit )
       {
            cout<< "Desolé ! Ce produit existe deja dans la table  "<<endl;

       }
       else
       {
            if (tableaux[indice].NumeroProduit == 0 )
            {
                tableaux[indice].statut = 1 ;
                tableaux[indice].NumeroProduit = p.NumeroProduit ;
                tableaux[indice].Prix = p.Prix ;
                tableaux[indice].essai =  i - 1 ;

            }

            else
            {
                cout << "Votre tableau est plein Impossible d'inserer l'element "<<endl;

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


           }while( tableaux[indice].NumeroProduit != p.NumeroProduit  && tableaux[indice].statut != 0 && i<= TAILLE );


           if( tableaux[indice].NumeroProduit == p.NumeroProduit  )
           {
              //  cout <<" Le produit "<< p.NumeroProduit << " est a l'indice "<< indice << " du tableau "<<endl;

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



void tableHachage:: Modifier_CLE ( const produit p , unsigned int numero )//recherche ici aussi
{
        int indice = Recherche_Produit(p) ;

       if (indice != -1 )
       {
            double prix = tableaux[indice].Prix ;

            Supprimer_Produit(p) ;
            produit p2(numero, prix ) ;
            insererProduit(p2) ;
             cout<< "Produit modifié avec success :) " <<endl;
       }

}

void tableHachage:: Modifier_PRIX ( const produit p , double prix )//recherche ici aussi
{

        int indice = Recherche_Produit(p) ;

       if (indice != -1 )
       {
           tableaux[indice].Prix = prix ;
            cout<< "Prix modifié avec success :) " <<endl;
       }




}

void tableHachage::Supprimer_Produit(const produit p )
 {
     int indice = Recherche_Produit(p) ;

    if (indice !=-1 )
    {
        cout<< "le produit  "<< tableaux[indice].NumeroProduit <<" a ete supprimer avec succes :) "<<endl;

        tableaux[indice].NumeroProduit = 0 ;
        tableaux[indice].Prix = 0.0 ;
        tableaux[indice].essai = 0 ;
        tableaux[indice].statut = -1 ;


    }



 }


 void tableHachage::affiche() const
 {
    for (int i=0 ; i<TAILLE; i++ )
    {
        if( tableaux[i].statut == 1 )
        {

            cout<< "----------------------------"<<endl<<endl;

                cout<<" Produit N° :    "<< tableaux[i].NumeroProduit<< " "<<endl;
                cout<<" prix  :         "<< tableaux[i].Prix<<endl;
                cout<<" Nombre d'essai : "<< tableaux[i].essai<< " " <<endl;
                cout<<" Indice dans le tableau :   "<< i << " "<<endl;
            cout<< "----------------------------"<<endl<<endl;

        }
    }
    cout<<endl;
 }
void tableHachage::Affiche_Produit(const produit p)
{
        int indice = Recherche_Produit(p);
         if( indice != -1 )
         {

            cout<<" Produit N° :    "<< tableaux[indice].NumeroProduit<< " "<<endl;
            cout<<" prix  :         "<< tableaux[indice].Prix<<endl;
            cout<<" Nombre d'essai : "<< tableaux[indice].essai<< " " <<endl;
            cout<<" Indice dans le tableau :   "<< indice << " "<<endl;
        }

}
