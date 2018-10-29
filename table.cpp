#include <stdlib.h>
#include <iostream>
#include "table.h"

using namespace std ;

 unsigned int tableHachage::pas = 0 ;


 tableHachage::tableHachage()
 {



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
            cout<< "clé presente "<<endl;

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
                cout << "tableau plein "<<endl;

            }


       }


 }




 unsigned int tableHachage::Recherche_Produit(const produit p)
 {

  unsigned int indice ;
   int i = 1 ;

           do
           {
                indice  = (*choix_hachage)(p.NumeroProduit,i ) ;
                i++;

           }while( tableaux[indice].NumeroProduit != p.NumeroProduit && i<=TAILLE );


           if( tableaux[indice].NumeroProduit == p.NumeroProduit )
           {
                cout <<" Le produit "<< p.NumeroProduit << " est a l'indice "<< indice << " du tableau "<<endl;
                return indice ;

           }
           else
           {

              cout <<" Le produit "<< p.NumeroProduit << " n'existe pas dans le tableau "<<endl;
              return -1 ;

           }











 /*
    int indice ;

         indice = hachage_Modulo( p.NumeroProduit ) ;

        if ( tableaux[indice].NumeroProduit == p.NumeroProduit  )
        {
            cout <<" Le produit "<< p.NumeroProduit << " est a l'indice "<< indice << " du tableau "<<endl;
            return indice ;
        }
        else
        {
                int compteur = 0 ;
                int indice_2 = indice ;

                do
                {
              //      indice_2 = (*choix_hachage)(indice_2) ;
                    compteur++ ;

                } while ((tableaux[indice_2].NumeroProduit != p.NumeroProduit) && compteur <= TAILLE );


                try
                {
                  if ((tableaux[indice_2].NumeroProduit != p.NumeroProduit) || (compteur >= TAILLE ))
                  {
                      throw string("ce produit n'existe pas dans le tableau");
                  }
                  else
                  {
                      cout <<" Le produit "<< p.NumeroProduit << " est a l'indice "<< indice_2 << " du tableau "<<endl;
                      return indice_2;
                  }
                }
                catch(string const& chaine)
                {
                  cerr << chaine << endl;
                }
        }

        return EXIT_FAILURE;

 }

 void tableHachage::Supprimer_Produit(const produit p )// utiliser la recherche ici aussi
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
                 //   indice_2 = (*choix_hachage)(indice_2) ;
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

   */

 }

void tableHachage:: Modifier_Produit( const produit p , unsigned int numero , double prix )//recherche ici aussi
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
                  //  indice_2 = Re_Hachage_Lineaire(indice_2) ;
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
       cout<<" prix  "<< tableaux[i].Prix<< " ";
       cout<<"Nombre d'essai "<< tableaux[i].essai<< " " <<endl;
    }
    cout<<endl;
 }
