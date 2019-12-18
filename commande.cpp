#include <iostream>
#include <string>
#include <vector>
#include "produit.h"
#include "commande.h"
//#include "client.h"

commande::commande(/*client client1,*/ bool status_commande){ 
	//client1_=client1;
	statusCommande_=status_commande;
}

void commande::addProduit(produit prod1){
	produit_.push_back(prod1);
}

int commande::tailleProd(){
	return produit_.size();
}

produit commande::getProduit(int i){
	return produit_.at(i);
}