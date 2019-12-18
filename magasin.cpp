#include <iostream>
#include <string>
#include <vector>
#include "magasin.h"
#include "produit.h"

using namespace std;

ostream& operator << (ostream &output, produit prod1) {
	string titre = prod1.getTitre(); 		// pour que chaque parametre soit au bon endroit lors de l'affichage
	int n = titre.size();
	n=13-n;
	for(int i=0;i<n ;i++){
		titre+=" ";
	}
	string desc = prod1.getDescr();
	n = desc.size();
	n=35-n;
	for(int i=0;i<n ;i++){
		desc+=" ";
	}
	string quant = to_string(prod1.getQuantite());
	n = quant.size();
	n=16-n;
	for(int i=0;i<n ;i++){
		quant+=" ";
	}
	string prix = to_string(prod1.getPrix());
	n = prix.size();			
	for(int i=0;i<n ;i++){						//pour ne pas qu'il y ai trop de chiffre apres la virgule
		if(prix[i]=='.'){
			prix.resize(i+3);
			i=n;
		}
	}
	n = prix.size();
	n=9-n;
	for(int i=0;i<n ;i++){
		prix+=" ";
	}

	output << "| " << titre << desc << quant << prix << "€ |" << endl;
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
	cout << "| Nom          Description                        Quantite        Prix       |" << endl;
	cout << "|----------------------------------------------------------------------------| " << endl;

	for(int i =0; i<n ; i++){
		cout << *m_produit.at(i);
	}

	cout << "|____________________________________________________________________________| " << endl << endl;
}

void magasin::displayProduitChoisi(string prod_s){
	int j, n=m_produit.size();
	bool trouve = false;

	for(int i =0; i<n ; i++){
		produit prod1 = *m_produit.at(i);
		if(prod1.getTitre()==prod_s){
			trouve=true;
			j=i;
			i=n;
		}
	}
	if(trouve==false){
		cout << "produit " << prod_s << " non trouve" << endl << endl;
	}
	else{
		cout << " ____________________________________________________________________________" << endl;
		cout << "|  PRODUITS                                                                  |" << endl;
		cout << "|----------------------------------------------------------------------------|" << endl;
		cout << "| Nom          Description                        Quantite        Prix       |" << endl;
		cout << "|----------------------------------------------------------------------------| " << endl;

		cout << *m_produit.at(j);

		cout << "|____________________________________________________________________________| " << endl << endl;
	}
}

