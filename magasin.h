#ifndef _magasin_h
#define _magasin_h
#include <iostream>
#include <string>
#include <vector>
#include "produit.h"


using namespace std;


class magasin {
public:
	magasin(int nb_produit_);
	void addProduit(produit *prod1);
	produit* getProduit(int n);
private:
	int nb_produit;
	vector<produit*> m_produit;
	//vector<client*> m_client;
	//vector<commande*> m_commande;

};


#endif 