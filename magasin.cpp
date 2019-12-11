#include <iostream>
#include <string>
#include <vector>
#include "magasin.h"
#include "produit.h"

using namespace std;

magasin::magasin(int nb_produit_ = 0){
	nb_produit=nb_produit_;
}

void magasin::addProduit(produit *prod1){
	m_produit.push_back(prod1);
}

produit* magasin::getProduit(int n){
	return m_produit.at(n);
}
