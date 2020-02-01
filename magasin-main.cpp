#include <iostream>
#include <string>
#include "magasin.h"
#include "client.h"
#include "commande.h"
#include "produit.h"

using namespace std;

int main(){
	magasin magasin1(0);
	produit PS4("PS4","console de SONY",18, 299.99000 );
	produit PS3("PS3","console de SONY",8, 120.990000 );
	produit Switch("Switch","console de Nintendo",654, 399.90000 );
	produit Wii("Wii","console de Nintendo",80, 90 );
	magasin1.addProduit(&PS4);
	magasin1.addProduit(&PS3);
	magasin1.addProduit(&Switch);
	magasin1.addProduit(&Wii);

	magasin1.displayProduit();

	magasin1.displayProduitChoisi("Wii");
	magasin1.displayProduitChoisi("PS1");

	magasin1.modifQuantite("PS4", 100);

	magasin1.displayProduit();


	client client1(1, "Dominique", "Ginhac");	
	client client2(2, "Albert", "Camus");

	magasin1.addClient(&client1);
	magasin1.addClient(&client2);

	magasin1.displayClientChoisi("Camus");
	magasin1.displayClientChoisi(1);

	cout << &client1 << endl;

vector<produit> v;

	magasin1.addProduitClient(client1, PS4, 50);
	magasin1.displayProduit();
	commande ABA(client1,v);
	magasin1.validerCommande(client1,&ABA);
	magasin1.livre(&client1);

	cout << (&client1) << endl;


	magasin1.addProduitClient(client2, PS4, 12);
	cout << (&client2) << endl;

	magasin1.addProduitClient(client2, PS4, 5);
	magasin1.addProduitClient(client2, PS3, -2);
	magasin1.addProduitClient(client2, PS3, 2);
	magasin1.addProduitClient(client2, PS3, 0);
	magasin1.addProduitClient(client2, Switch, 18);
	commande ABB(client2,v);
	magasin1.validerCommande(client2,&ABB);
	magasin1.livre(&client2);

	cout << (&client2) << endl;
	magasin1.supProduitClient(client2, Switch);
	cout << (&client2) << endl;
	magasin1.supProduitClient(client2, PS4);
	cout << (&client2) << endl;


	magasin1.addProduitClient(client2, PS4, 5);
	magasin1.addProduitClient(client2, PS3, 2);
	magasin1.addProduitClient(client2, PS3, 3);
	magasin1.addProduitClient(client2, Wii, 19);
	magasin1.addProduitClient(client2, Switch, 18);
	cout << (&client2) << endl;

commande AAA(client2,v);
	magasin1.validerCommande(client2,&AAA);

	cout <<&AAA;
	
magasin1.displayCommandes();

magasin1.displayCommandeClient(client2);

}