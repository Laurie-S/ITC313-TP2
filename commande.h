#ifndef _commande_h
#define _commande_h
<<<<<<< HEAD
=======

>>>>>>> Question3
#include <iostream>
#include <string>
#include <vector>
#include "produit.h"
<<<<<<< HEAD
//#include "client.h"
=======
#include "client.h"
>>>>>>> Question3


using namespace std;


class commande {
public:
<<<<<<< HEAD
	commande(/*client client1,*/ bool status_commande = false );
	int tailleProd();
	void addProduit(produit prod1);
	produit getProduit(int i);

	friend ostream& operator<<(ostream &out, produit *commande);

private:
	//client client1_;
=======
	commande(client client1,vector<produit> produits);
	int tailleProd();
	void addProduit(produit prod1);
	produit getProduit(int i);
	client getClient();
	
	friend ostream& operator<<(ostream &out, commande *com1);

private:
	client client1_;
>>>>>>> Question3
	vector<produit> produit_;
	bool statusCommande_;

};

#endif 