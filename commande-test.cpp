#include <iostream>
#include <string>
#include <vector>
<<<<<<< HEAD
=======
#include "client.h"
>>>>>>> Question3
#include "produit.h"
#include "commande.h"

using namespace std;

int main(void){
	produit PS4("PS4","console de SONY",18, 299.99 );
<<<<<<< HEAD
	commande com1(false);
=======
	client client1(1, "Dominique", "Ginhac");	
	vector<produit> vec;
	commande com1(client1,vec);
>>>>>>> Question3
	com1.addProduit(PS4);

	cout << &com1;

	//cout << &PS4;
}