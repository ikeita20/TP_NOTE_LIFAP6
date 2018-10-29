#include <stdlib.h>
#include <iostream>
#include "table.h"

using namespace std;


int main()

{

    tableHachage t ;


    produit p(10,3.0), q(20,2.5), k(40,0.5), y(5, 5.2) , o(8, 5.2) , oo(7, 5.2);




    t.insererProduit(p) ;
    t.insererProduit(q) ;
    t.insererProduit(k) ;
    t.insererProduit(o) ;
    t.insererProduit(p) ;
    t.affiche();











	return 0 ;

}
