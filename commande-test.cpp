#include <iostream>
#include <string>
#include <vector>
#include "produit.h"
#include "commande.h"

using namespace std;

int main(void){
	produit PS4("PS4","console de SONY",18, 299.99 );
	commande com1(false);
	com1.addProduit(PS4);

	cout << &com1;

	//cout << &PS4;
}