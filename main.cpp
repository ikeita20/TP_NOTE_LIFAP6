#include <stdlib.h>
#include <iostream>
#include "table.h"

using namespace std;


int main()

{


    tableHachage t ;
    produit p(10,3.0), q(20,2.5), k(30,0.5), y(40, 5.2) , o(3, 5.2) , oo(7, 5.2);

    t.insererProduit(p) ;
    t.insererProduit(q) ;
    t.insererProduit(k) ;
    t.insererProduit(y) ;
    t.insererProduit(oo) ;
    t.affiche();
   // cout<< t.Produit_Existe(oo) <<endl ;
    cout<< t.Recherche_Produit(p) <<endl ;



	return 0 ;

}
