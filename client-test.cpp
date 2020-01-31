#include "client.h"
#include "produit.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(){
	client client1(1, "Dominique", "Ginhac");		
	
	cout << "Le client n°" << client1.getId() << " est " << client1.getPrenom() << " " << client1.getNom() << endl;
	

	produit PS4("PS4","console de SONY",1, 299.99 );
	client1.addPdtPanier(PS4);
	
	cout << &client1 << endl;

	client1.videPanier();
	
	cout << &client1 << endl;

	produit PS3("PS3","console de SONY",1, 100 );

	client1.addPdtPanier(PS4);
	client1.addPdtPanier(PS3);

	cout << &client1 << endl;

	client1.supPdtPanier("PS4");
	client1.modifQuantitePanier("PS3", 5);

	cout << &client1 << endl;


	
	return 0;
	
	}