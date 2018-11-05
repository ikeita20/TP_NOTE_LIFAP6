#include <stdlib.h>
#include <iostream>
#include "table.h"
#include <string>
#include <stdexcept>
#include <random>


using namespace std;

int Conversion_NUMP(string chaine )
{
     unsigned int choix_utilisateur ;

        try {

                    choix_utilisateur = std::stoi(chaine);

                    return choix_utilisateur ;

            }

            catch (const std::invalid_argument& e)
            {

                    cout << "Veuillez écrire un nombre entier !\n";
            }
            return -1 ;
}


double Conversion_PRIX (string chaine )
{
     double prix ;
        try {

                    prix = std::stod(chaine);

                    return prix ;

            }

            catch (const std::invalid_argument& e)
            {
                    cout << "Veuillez écrire un nombre decimal !\n";
            }
            return -1 ;
}

int main()

{
    tableHachage t ;

    string choix_string ;
    int choix_utilisateur;

     unsigned int Num_produit ;
     srand (time(NULL));



    for(int i=0 ; i<50 ; i++ )
    {

  /// Remplissage de mon tableau avec random

        unsigned int Numero ;
        Numero =   (rand() % 700 ) + 100  ;
        Num_produit = Numero ;

        produit p(Num_produit , (2.5)+ i ) ;

        t.insererProduit(p) ;

    }

    bool quitter = false;

    do {

            do {
            cout <<"----------------------------"<<endl;
            cout<< " ****** Menu  ********"<<endl;

            cout <<" 1 = Ajouter un produit "<<endl;
            cout <<" 2 = Modifier un produit "<<endl;
            cout <<" 3 = Modifier un Prix "<<endl;
            cout <<" 4 = Supprimer un produit "<<endl;
            cout <<" 5 = Rechercher un produit "<<endl;
            cout <<" 6 = Afficher tous les produits "<<endl;
            cout <<" 7 = Quitter l'application "<<endl;
            cout<< "----------------------------"<<endl;
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

            } while (choix_utilisateur < 1 || choix_utilisateur > 7 );

            switch( choix_utilisateur )
            {

                    case 1 :{

                                   string Num_Produit ;
                                    int c_nump;
                                    int b;

                                    cout<<endl<<endl;
                                    cout<< "Ajout d'un produit "<<endl;
                                    produit produit_test ;

                                     do
                                     {
                                        cout<<"Saisissez le Numero du produit : ";
                                        cin>>Num_Produit;

                                            c_nump = Conversion_NUMP(Num_Produit) ;
                                            b = (int)c_nump ;

                                     }while(c_nump == -1 || b <= 0  ) ;

                                     if( c_nump > 0 )
                                     {
                                        string prix ;
                                        double c_prix ;


                                        produit *p ;

                                          cout<<"Saisissez le Prix du produit : ";
                                          cin>>prix ;
                                          c_prix = Conversion_PRIX(prix) ;
                                          p =  new produit(c_nump, c_prix) ;
                                          while( c_prix == -1 ||  c_prix <= 0 )
                                          {
                                              cout<<"PRIX ERRONE ";
                                              cout<<"Saisissez le Prix du produit : ";
                                              cin>>prix ;
                                              c_prix = Conversion_PRIX(prix) ;
                                              p =  new produit(c_nump, c_prix) ;

                                          }

                                        if( t.Recherche_Produit(*p) == -1 )
                                        {
                                            t.insererProduit(*p) ;
                                        }
                                        else
                                        {
                                            cout<< " le produit "<< p->NumeroProduit <<" existe deja , il n'a pas été inseré "<<endl;
                                        }


                                     }


                            }break ;

                     case 2 :{

                                   unsigned int numero_du_nouveau_produit ;
                                   string numero_du_produit_a_modifier ;

                                      cout<<endl<<endl;
                                      cout<< "Modification de la CLÉ d'un produit "<<endl<<endl;
                                      int a;
                                      int b ;
                                     do
                                     {
                                        cout<< "Donnez le Numero du produit a modifier : ";
                                        cin>>numero_du_produit_a_modifier ;

                                            a = Conversion_NUMP(numero_du_produit_a_modifier) ;
                                            b = (int)a ;

                                     }while(a == -1 || b <= 0  ) ;

                                      if( a > 0){

                                        produit prod(a ,0.0);

                                        if( t.Recherche_Produit(prod) != -1 )
                                        {
                                            cout<< "Donnez le Numero du nouveau produit : ";
                                            cin>> numero_du_nouveau_produit;

                                            if(numero_du_nouveau_produit > 0)
                                            {
                                              t.Modifier_CLE(prod,numero_du_nouveau_produit) ;
                                            }
                                            else
                                            {
                                              cout << "nouveau numéro de produit non valide" << '\n';
                                            }
                                        }
                                      }
                                      else
                                      {
                                        cout << "numéro de produit non valide " << '\n';
                                      }


                            }break ;

                      case 3 :{
                                   string  numero_du_nouveau_produit ;
                                   string numero_du_produit_a_modifier ;

                                      cout<<endl<<endl;
                                      cout<< "Modification du Prix  d'un Produit "<<endl;


                                        int c_nump;
                                        double  c_prix  ;
                                        int b ;

                                      do
                                     {
                                            cout<< "Donnez le Numero du produit a modifier : ";
                                            cin>>numero_du_produit_a_modifier;


                                            c_nump= Conversion_NUMP(numero_du_produit_a_modifier) ;

                                            b= (int)c_nump ;
                                     }while(c_nump == -1 || b <= 0  ) ;


                                      if(  c_nump >0 )
                                      {
                                        produit p(c_nump,0.0 ) ;

                                         if( t.Recherche_Produit(p) != -1 )
                                         {
                                            string nouveau_prix ;
                                              cout<< "Donnez le Nouveau prix du produit : ";
                                              cin>>nouveau_prix ;

                                              c_prix = Conversion_PRIX(nouveau_prix) ;

                                              if(c_prix > 0 ) {
                                               t.Modifier_PRIX(p,c_prix) ;
                                              }
                                              else
                                              {
                                                std::cout << "Nouveau prix incorrect" << '\n';
                                              }
                                         }
                                         else
                                            {
                                                cout<< " le produit "<< p.NumeroProduit <<" N'existe pas "<<endl;
                                            }
                                       }
                                       else
                                       {
                                         std::cout << "numéro de produit non valide" << '\n';
                                       }



                      } break ;

                    case 4 :{
                                        string numero_du_produit_a_supprimer ;
                                        int c_nump;
                                        int b ;

                                     cout<< "Suppression d'un Produit "<<endl<<endl;

                                      do
                                     {
                                            cout<< "Donnez le Numero du produit a Supprimer : ";
                                            cin>>numero_du_produit_a_supprimer;

                                            c_nump= Conversion_NUMP(numero_du_produit_a_supprimer) ;
                                            b= (int)c_nump ;

                                     }while(c_nump == -1 || b <= 0  ) ;

                                      if(  c_nump > 0 )
                                      {
                                        produit p(c_nump,0.0 ) ;

                                         if( t.Recherche_Produit(p) != -1 )
                                         {
                                              t.Supprimer_Produit(p) ;
                                         }
                                         else
                                        {
                                            cout<< " le produit "<< p.NumeroProduit <<" N'existe pas "<<endl;
                                        }
                                       }
                                       else
                                       {
                                         std::cout << "numéro de produit non valide" << '\n';
                                       }



                      } break ;

                      case 5 :{

                                    string numero_du_nouveau_produit_rechercher ;
                                        int c_nump;
                                        int b ;

                                     cout<< "Recherche d'un Produit "<<endl<<endl;

                                      do
                                     {
                                             cout<< "Vous Rechercher le produit N° : ? ";
                                            cin>>numero_du_nouveau_produit_rechercher;

                                            c_nump= Conversion_NUMP(numero_du_nouveau_produit_rechercher) ;
                                            b= (int)c_nump ;

                                     }while(c_nump == -1 || b <= 0  ) ;



                                    if( c_nump >0 ){

                                      produit prod2(c_nump,0.0);
                                      int indice = t.Recherche_Produit(prod2);
                                      if( indice != - 1 )
                                      {
                                         t.Affiche_Produit(indice) ;
                                      }
                                      else
                                      {
                                            cout<< " le produit "<< prod2.NumeroProduit <<" N'existe pas "<<endl;
                                      }


                                    }
                                    else
                                    {
                                      std::cout << "numéro de produit non valide" << '\n';
                                    }

                            }break ;


                    case 6 : {

                                cout << "*** Liste de tous les produits ***"<<endl<<endl;
                                    t.affiche();


                    } break ;

                    case 7:{

                            quitter = true ;
                            cout<< "AU REVOIR "<<endl;

                            }break ;

                    default :cout << "Veuillez choisir un choix dans la liste s'il vous plait\n";
                             break;

            }


    }while ( quitter == false );

  return 0 ;

}
