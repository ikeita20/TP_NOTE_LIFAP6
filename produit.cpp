#include <stdlib.h>
#include <iostream>
#include "produit.h"

using namespace std ;

produit::produit()
{
    NumeroProduit = 0 ;
    Prix = 0.0 ;
    essai = 0 ;
    statut = 0 ;

}

produit::produit(unsigned int numero , double prix )
{
    NumeroProduit = numero ;
    Prix = prix ;
}

produit::~produit()
{
    // je sais pas
}

