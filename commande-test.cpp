#include <iostream>
#include <string>
#include <vector>
#include "client.h"
#include "produit.h"
#include "commande.h"

using namespace std;

int main(void){
	produit PS4("PS4","console de SONY",18, 299.99 );
	client client1(1, "Dominique", "Ginhac");	
	vector<produit> vec;
	commande com1(client1,vec);
	com1.addProduit(PS4);

	cout << &com1;

	//cout << &PS4;
}