#include <iostream>
#include <string>
#include "magasin.h"

using namespace std;

ostream& operator << (ostream &output, produit prod1) {
	output << prod1.getTitre() << " " << prod1.getDescr() << "        " << prod1.getQuantite() << "    " << prod1.getPrix() << "€" << endl;
	return output; 
}

int main(){
	magasin magasin1(0);
	produit PS4("PS4","console de SONY",18, 299.99 );
	
	magasin1.addProduit(&PS4);
	produit *test2 = magasin1.getProduit(0);
	cout << *test2;
}