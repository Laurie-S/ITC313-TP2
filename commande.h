#ifndef _commande_h
#define _commande_h

#include <iostream>
#include <string>
#include <vector>
#include "produit.h"
#include "client.h"


using namespace std;


class commande {
public:
	commande(client client1,vector<produit> produits);
	int tailleProd();
	void addProduit(produit prod1);
	produit getProduit(int i);
	client getClient();
	
	friend ostream& operator<<(ostream &out, commande *com1);

private:
	client client1_;
	vector<produit> produit_;
	bool statusCommande_;

};

#endif 