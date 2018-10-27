#include <stdlib.h>
#include <iostream>
#include "table.h"

using namespace std;


int main()

{

  tableHachage t ;


    produit p(1,3.0), q(20,2.5), k(30,0.5), y(4, 5.2) , o(8, 5.2) , oo(7, 5.2);

    t.insererProduit(p) ;
    t.insererProduit(k) ;
     t.insererProduit(q) ;
    t.insererProduit(y) ;
    t.insererProduit(o) ;
    t.affiche();
    t.Supprimer_Produit(o) ;
    //t.affiche() ;




	return 0 ;

}
