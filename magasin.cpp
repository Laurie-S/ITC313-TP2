#include <iostream>
#include <string>
#include <vector>
#include "magasin.h"
#include "produit.h"

using namespace std;

ostream& operator << (ostream &output, produit prod1) {
	string titre = prod1.getTitre(); // pour que le titre la description et la quantite soit au bon endroit
	int n = titre.size();
	n=13-n;
	for(int i=0;i<n ;i++){
		titre+=" ";
	}
	string Desc = prod1.getDescr();
	n = Desc.size();
	n=35-n;
	for(int i=0;i<n ;i++){
		Desc+=" ";
	}

	output << "| " << titre << Desc << prod1.getQuantite() << "                 " << prod1.getPrix() << "€ |" << endl;
	return output; 
}

magasin::magasin(int nb_produit_ = 0){
	nb_produit=nb_produit_;
}

void magasin::addProduit(produit *prod1){
	m_produit.push_back(prod1);
}

produit* magasin::getProduit(int n){
	return m_produit.at(n);
}

void magasin::displayProduit(){
	int n=m_produit.size();
	cout << " ____________________________________________________________________________" << endl;
	cout << "|  PRODUITS                                                                  |" << endl;
	cout << "|----------------------------------------------------------------------------|" << endl;
	cout << "| Nom          Description                        Quantite           Prix    |" << endl;
	cout << "|----------------------------------------------------------------------------| " << endl;

	for(int i =0; i<n ; i++){
		cout << *m_produit.at(i);
	}

	cout << "|____________________________________________________________________________| " << endl << endl;
}