#ifndef _commande_h
#define _commande_h
#include <iostream>
#include <string>
#include <vector>
#include "produit.h"
//#include "client.h"


using namespace std;


class commande {
public:
	commande(/*client client1,*/ bool status_commande = false );

private:
	//client client1_;
	vector<produit> produit_;
	bool statusCommande_;

};

#endif 