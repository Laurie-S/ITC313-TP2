#include <iostream>
#include <string>
#include <vector>
#include "produit.h"

using namespace std;

int main(void){
	produit PS4("PS4","console de SONY",18, 299.99 );

	cout << PS4.getDescr() << " " << PS4.getQuantite() << endl;
	PS4.setQuantite(20);
	cout << PS4.getTitre() << " " << PS4.getQuantite() << endl;

	cout << PS4;
}