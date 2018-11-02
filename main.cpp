#include <stdlib.h>
#include <iostream>
#include "table.h"
#include <string>
#include <stdexcept>


using namespace std;


int main()

{
    tableHachage t ;
    produit a(7,0.5) , b(15,0.0);
    t.insererProduit(a);
    string choix_string ;
    int choix_utilisateur;
    //cout<<t.Recherche_Produit(b) ;
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

                                    produit *p ;
                                    p =  new produit() ;
                                    cout<<endl<<endl;
                                    cout<< "Ajout d'un produit "<<endl;
                                    do
                                    {
                                        cout<<"Saisissez le Numero du produit : ";
                                        cin>>p->NumeroProduit ;

                                        if( (int)p->NumeroProduit <= 0 )
                                        {
                                            cout<<"Numero de produit Erronée "<<endl;



                                        }


                                    }while( (int)p->NumeroProduit <= 0  );

                                    do
                                    {
                                      cout<<"Saisissez le Prix du produit : ";
                                      cin>>p->Prix ;
                                      if( (int)p->Prix <= 0 )
                                      {
                                          cout<<"Prix erroné "<<endl;

                                      }
                                    }while ( (int)p->Prix <= 0 );

                                    t.insererProduit(*p) ;

                                    cout<<"FIN de l'ajout "<<endl;

                            }break ;

                     case 2 :{

                                   unsigned int numero_du_nouveau_produit ;
                                   unsigned int numero_du_produit_a_modifier ;

                                      cout<<endl<<endl;
                                      cout<< "Modification de la CLÉ d'un produit "<<endl<<endl;
                                      cout<< "Donnez le Numero du produit a modifier : ";
                                      cin>>numero_du_produit_a_modifier ;
                                      if( numero_du_produit_a_modifier >0){
                                        produit prod(numero_du_produit_a_modifier,0.0);
                                        if( t.Recherche_Produit(prod) != -1 )
                                        {
                                            cout<< "Donnez le Numero du nouveau produit : ";
                                            cin>> numero_du_nouveau_produit;
                                            if(numero_du_nouveau_produit >0)
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
                                        cout << "numéro de produit non valide" << '\n';
                                      }







                            }break ;

                      case 3 :{
                                    unsigned int numero_du_produit_a_modifier ;
                                    double nouveau_prix ;

                                      cout<<endl<<endl;
                                      cout<< "Modification du Prix  d'un Produit "<<endl;
                                      cout<< "Donnez le Numero du produit a modifier : ";
                                      cin>>numero_du_produit_a_modifier;
                                      if( numero_du_produit_a_modifier >0){
                                        produit p (numero_du_produit_a_modifier,0.0 ) ;

                                         if( t.Recherche_Produit(p) != -1 )
                                         {
                                              cout<< "Donnez le Nouveau prix du produit : ";
                                              cin>>nouveau_prix ;
                                              if(nouveau_prix >0){
                                               t.Modifier_PRIX(p,nouveau_prix) ;
                                              }
                                              else
                                              {
                                                std::cout << "Nouveau prix incorrect" << '\n';
                                              }
                                         }
                                       }
                                       else
                                       {
                                         std::cout << "numéro de produit non valide" << '\n';
                                       }



                      } break ;

                    case 4 :{
                                     unsigned int numero_du_produit_a_supprimer ;
                                     cout<< "Suppression d'un Produit "<<endl<<endl;
                                      cin>>numero_du_produit_a_supprimer ;
                                      if( numero_du_produit_a_supprimer >0){
                                        produit p(numero_du_produit_a_supprimer,0.0) ;
                                        t.Supprimer_Produit(p) ;
                                      }
                                      else
                                      {
                                        std::cout << "Numéro de produit non valide" << '\n';
                                      }




                      } break ;

                      case 5 :{

                                    unsigned int numero_du_nouveau_produit_rechercher ;
                                    cout<< "Vous Rechercher le produit N° : ? ";
                                    cin>>numero_du_nouveau_produit_rechercher ;
                                    if( numero_du_nouveau_produit_rechercher >0){

                                      produit prod2(numero_du_nouveau_produit_rechercher,0.0);
                                      t.Affiche_Produit(prod2) ;

                                    }
                                    else
                                    {
                                      std::cout << "numéro de produit non valide" << '\n';
                                    }

                            }break ;


                    case 6 : {

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
