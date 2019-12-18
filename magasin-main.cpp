#include <iostream>
#include <string>
#include "magasin.h"

using namespace std;

/*ostream& operator << (ostream &output, produit prod1) {
	output << prod1.getTitre() << " " << prod1.getDescr() << "        " << prod1.getQuantite() << "    " << prod1.getPrix() << "€" << endl;
	return output; 
}*/

int main(){
	magasin magasin1(0);
	produit PS4("PS4","console de SONY",18, 299.99000 );
	produit PS3("PS3","console de SONY",8, 120.990000 );
	produit Switch("Switch","console de Nintendo",654, 399.90000 );
	produit Wii("Wii","console de Nintendo",2, 90 );
	magasin1.addProduit(&PS4);
	magasin1.addProduit(&PS3);
	magasin1.addProduit(&Switch);
	magasin1.addProduit(&Wii);

	magasin1.displayProduit();

	magasin1.displayProduitChoisi("Wii");
	magasin1.displayProduitChoisi("PS1");
}