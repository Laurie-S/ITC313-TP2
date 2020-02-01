#ifndef _client_h
#define _client_h

#include <iostream>
#include <string>
#include "produit.h"
#include <vector>

using namespace std;

class client {
public:
	client(int id_, string prenom_, string nom_);
	int getId();
	string getNom();
	string getPrenom();
	vector<produit> getPanier();
	void addPdtPanier(produit prod);
	void videPanier();
	void modifQuantitePanier(string nom_produit, int quantite);
	void supPdtPanier(string nom_produit);
	void setPanier(vector<produit> v);
	
	friend ostream& operator<<(ostream &flux, client *client1);

private:
	int id;
	string nom;
	string prenom;
	vector<produit> panier_achat;
};


#endif