#include <iostream>
#include <string>
#include "magasin.h"
#include "client.h"
#include "commande.h"
#include "produit.h"

using namespace std;

int main(){
	magasin mag(0);
	int choix=-1;
	while(choix < 0 && choix > 3){
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << " ____________________________________________________________________________" << endl;
		cout << "|																			  |" << endl;
		cout << "|  MENU PRINCIPAL                                                            |" << endl;
		cout << "|																			  |" << endl;
		cout << "|	Que voulez-vous faire ?													  |" << endl;
		cout << "|																			  |" << endl;
		cout << "|		1. Gestion du magasin												  |" << endl;
		cout << "|		2. Gestion des commandes											  |" << endl;
		cout << "|		3. Gestion des clients												  |" << endl;
		cout << "|																			  |" << endl;
		cout << "|		0. Quitter															  |" << endl;
		cout << "|  ";
		cin >> choix;
		cout << "|____________________________________________________________________________|" << endl;
	}
	

}