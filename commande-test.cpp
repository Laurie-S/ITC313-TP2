#include <iostream>
#include <string>
#include <vector>
#include "produit.h"
#include "commande.h"

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

ostream& operator << (ostream &out, commande com1) {
	out << " ____________________________________________________________________________" << endl;
	out << "|  COMMANDE                                                                  |" << endl;
	out << "|----------------------------------------------------------------------------|" << endl;
	out << "| Nom du client " << /* get nom client */"                                   |" << endl;
	out << "|----------------------------------------------------------------------------| " << endl;
	for(int i=0;i<com1.tailleProd();i++){
		produit prod1=com1.getProduit(i);
		out << prod1;
	}
	out << endl << endl;
	return out; 
}

int main(void){
	produit PS4("PS4","console de SONY",18, 299.99 );
	commande com1(false);
	com1.addProduit(PS4);

	cout << com1;

	//cout << PS4;
}