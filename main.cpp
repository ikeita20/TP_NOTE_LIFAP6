#include <stdlib.h>
#include <iostream>
#include "table.h"

using namespace std;


int main()

{

    tableHachage t ;


    produit p(1,3.0), q(20,2.5), k(30,0.5), y(4, 5.2) , o(8, 5.2) , oo(7, 5.2);
    unsigned int n;
    double prix ;

   cout<<"donnerz numero p"<<endl;
   cin>>n;
   cout<<"donnerz le prix "<<endl;
   cin>>prix ;
   produit pr(n,prix) ;

   t.insererProduit(pr) ;
    cout<<t.Recherche_Produit(oo);

    t.affiche();






	return 0 ;

}
