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

ostream& operator << (ostream &out, commande *com1) {
	out << " ____________________________________________________________________________" << endl;
	out << "|  COMMANDE                                                                  |" << endl;
	out << "|----------------------------------------------------------------------------|" << endl;
	out << "| Nom du client " << /* get nom client */"                                   |" << endl;
	out << "|----------------------------------------------------------------------------| " << endl;
	for(int i=0;i<com1->tailleProd();i++){
		produit prod1=com1->getProduit(i);
		out << &prod1;
	}
	out << endl << endl;
	return out; 
}