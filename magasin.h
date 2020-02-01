#ifndef _magasin_h
#define _magasin_h
#include <iostream>
#include <string>
#include <vector>
#include "produit.h"
#include "client.h"
#include "commande.h"


using namespace std;


class magasin {
public:
	magasin(int nb_produit_);
	void addProduit(produit *prod1);
	produit* getProduit(int n);
	void displayProduit();
	void displayProduitChoisi(string prod_s);
	int findProduct(string prod_s);
	bool modifQuantite(string prod_s, int newQuantite);
	void addClient(client *cli);
	void displayClient();
	void displayClientChoisi(string nom);
	void displayClientChoisi(int Id);
	client findClient(int Id);
	client findClient(string nom);
	void addProduitClient(client clie, produit prod, int Quant);
	void supProduitClient(client clie, produit prod);
	int getQuantiteProdClient(client clie, produit prod);


private:
	int nb_produit;
	vector<produit*> m_produit;
	vector<client*> m_client;
	vector<commande*> m_commande;

};


#endif 