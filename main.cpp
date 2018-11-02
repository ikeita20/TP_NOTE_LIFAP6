#include <stdlib.h>
#include <iostream>
#include "table.h"


using namespace std;


int main()

{
    tableHachage t ;
    produit a(7,0.5) , b(15,0.0);
    t.insererProduit(a);
    int choix_utilisateur ;

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
            cin>>choix_utilisateur ;

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

                                    cout<<"Saisissez le Prix du produit : ";
                                    cin>>p->Prix ;
                                    t.insererProduit(*p) ;

                                   // cout<<"FIN de l'ajout "<<endl;

                            }break ;

                     case 2 :{

                                   unsigned int numero_du_nouveau_produit ;
                                   unsigned int numero_du_produit_a_modifier ;

                                      cout<<endl<<endl;
                                      cout<< "Modification de la CLÉ d'un produit "<<endl<<endl;
                                      cout<< "Donnez le Numero du produit a modifier : ";
                                      cin>>numero_du_produit_a_modifier ;
                                       produit prod(numero_du_produit_a_modifier,0.0);

                                       if( t.Recherche_Produit(prod) != -1 )
                                       {
                                            cout<< "Donnez le Numero du nouveau produit : ";
                                            cin>> numero_du_nouveau_produit;
                                             t.Modifier_CLE(prod,numero_du_nouveau_produit) ;
                                       }






                            }break ;

                      case 3 :{
                                    unsigned int numero_du_produit_a_modifier ;
                                    double nouveau_prix ;

                                      cout<<endl<<endl;
                                      cout<< "Modification du Prix  d'un Produit "<<endl;
                                      cout<< "Donnez le Numero du produit a modifier : ";
                                      cin>>numero_du_produit_a_modifier;
                                      produit p (numero_du_produit_a_modifier,0.0 ) ;

                                       if( t.Recherche_Produit(p) != -1 )
                                       {
                                            cout<< "Donnez le Nouveau prix du produit : ";
                                            cin>>nouveau_prix ;
                                             t.Modifier_PRIX(p,nouveau_prix) ;
                                       }



                      } break ;

                    case 4 :{
                                     unsigned int numero_du_produit_a_supprimer ;
                                     cout<< "Suppression d'un Produit "<<endl<<endl;
                                      cin>>numero_du_produit_a_supprimer ;
                                      produit p(numero_du_produit_a_supprimer,0.0) ;
                                      t.Supprimer_Produit(p) ;




                      } break ;

                      case 5 :{

                                    unsigned int numero_du_nouveau_produit_rechercher ;
                                    cout<< "Vous Rechercher le produit N° : ? ";
                                    cin>>numero_du_nouveau_produit_rechercher ;

                                    produit prod2(numero_du_nouveau_produit_rechercher,0.0);

                                    t.Affiche_Produit(prod2) ;

                            }break ;


                    case 6 : {

                                t.affiche();


                    } break ;

                    case 7:{

                            quitter = true ;
                            cout<< "AU REVOIR "<<endl;

                            }break ;



            }


    }while ( quitter == false );




	return 0 ;

}
