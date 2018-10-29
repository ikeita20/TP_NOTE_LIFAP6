#include <stdlib.h>
#include <iostream>
#include "table.h"


using namespace std;


int main()

{
    tableHachage t ;
    produit a(7,0.5) ;
    t.insererProduit(a);
    t.affiche();

    int choix_utilisateur ;
    bool quitter = true;

    do
   {

            do
            {
            cout <<"----------------------------"<<endl;
            cout<< " ****** Menu  ********"<<endl;

            cout <<" 1 = Ajouter un produit "<<endl;
            cout <<" 2 = Modifier un produit "<<endl;
            cout <<" 3 = Rechercher un produit "<<endl;
            cout <<" 4 = Afficher tous les produits "<<endl;
            cout <<" 5 = Quitter l'application "<<endl;
            cout<< "----------------------------"<<endl;
            cout<<endl;
            cout<< "Donnez votre choix : ";
            cin>>choix_utilisateur ;

            } while (choix_utilisateur< 1 || choix_utilisateur > 3 );

            switch( choix_utilisateur )
            {

                    case 1 :{

                                    produit *p ;
                                    p =  new produit() ;
                                    cout<< "Ajout d'un produit "<<endl;
                                    do
                                    {
                                        cout<<"Saisissez le Numero du produit : ";
                                        cin>>p->NumeroProduit ;
                                        if(p->NumeroProduit <0 )
                                        {
                                            cout<<"Numero de produit Erronée "<<endl;
                                        }

                                    }while(p->NumeroProduit <= 0);


                                    cout<<"Saisissez le Prix du produit : ";
                                    cin>>p->Prix ;
                                    t.insererProduit(*p) ;

                                    cout<<"FIN de l'ajout "<<endl;

                            }break ;

                     case 2 :{

                                   unsigned int numero_du_nouveau_produit ;
                                   unsigned int numero_du_produit_a_modifier ;
                                   double prix;
                                      cout<< "Modification d'un produit "<<endl;
                                      cout<< "Donnez le Numero du produit a modifier : ";
                                      cin>>numero_du_produit_a_modifier ;
                                      cout<< "Donnez le Numero du nouveau produit : ";
                                      cin>> numero_du_nouveau_produit;
                                      cout<< "Donnez le prix du nouveau produit : ";
                                      cin>> prix;
                                      cout<<endl;
                                      produit prod(numero_du_produit_a_modifier,prix);
                                      t.Modifier_Produit(prod,numero_du_nouveau_produit,prix) ;

                            }break ;

                      case 3 :{

                                    unsigned int numero_du_nouveau_produit_rechercher ;
                                    cout<< "Vous Rechercher le produit N° : ? ";
                                    cin>>numero_du_nouveau_produit_rechercher ;
                                    produit prod2(numero_du_nouveau_produit_rechercher,0.0);
                                    t.Recherche_Produit(prod2);

                            }break ;

                    case 5:{

                            quitter = false ;
                            cout<< "AU REVOIR "<<endl;

                            }break ;


            }


    }while ( quitter != false );

    t.affiche();

	return 0 ;

}
