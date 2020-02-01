#include <iostream>
#include <string>
#include <vector>
#include "produit.h"
#include "commande.h"
#include "client.h"

commande::commande(client client1, vector<produit> produits) : client1_(client1), produit_(produits){ 
	statusCommande_=false;
}

void commande::addProduit(produit prod1){
	produit_.push_back(prod1);
}

client commande::getClient(){
	return client1_;
}

int commande::tailleProd(){
	return produit_.size();
}

produit commande::getProduit(int i){
	return produit_.at(i);
}

ostream& operator << (ostream &out, commande *com1) {
	int n;
	client client1 = com1->getClient();
	out << " ____________________________________________________________________________" << endl;
	out << "|  COMMANDE                                                                  |" << endl;
	out << "|----------------------------------------------------------------------------|" << endl;
	out << "| Nom du client : " << client1.getNom();
	n=66-((client1.getNom()).size() + (client1.getPrenom()).size());
	for (int i =0; i<n; i++){
		out << " ";
	}
	out << "|" << endl;
	out << "|----------------------------------------------------------------------------| " << endl;

	for(int i=0;i<com1->tailleProd();i++){
		produit prod1=com1->getProduit(i);
		out << &prod1;
	}
	out << "|____________________________________________________________________________|" << endl;

	out << endl << endl;
	return out; 
}