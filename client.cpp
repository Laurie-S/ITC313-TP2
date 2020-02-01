#include "client.h"
#include <string>
#include <vector>
#include "produit.h"

using namespace std;

client::client(int id_, string prenom_, string nom_) : id(id_), nom(nom_), prenom(prenom_){
}																															

int client::getId(){ 
	return id;
}

string client::getNom(){
	return nom;
}	

string client::getPrenom(){
	return prenom;
}

vector<produit> client::getPanier(){
	return panier_achat;
}

void client::addPdtPanier(produit prod){ 
	panier_achat.push_back(prod);
}

void client::supPdtPanier(string nom_produit){
	for(int i=0; i< panier_achat.size(); i++){
		produit prod = panier_achat.at(i);
		if(prod.getTitre() == nom_produit){
			panier_achat.erase(panier_achat.begin() + i);
		}
	}
}

void client::videPanier(){
	panier_achat.clear();
}

void client::modifQuantitePanier(string nom_produit, int quantite){
	for(int i=0; i< panier_achat.size(); i++){
		produit prod = panier_achat.at(i);
		if(prod.getTitre() == nom_produit){
			(panier_achat.at(i)).setQuantite(quantite);
		}
	}
}
void client::setPanier(vector<produit> v){
	for (int i = 0; i < v.size(); i++)
	{
		panier_achat.push_back(v.at(i));
	}
}

ostream& operator<<(ostream &flux, client *client1){
	//////////////////////////// pour la presentation
	string taille; 
	int n;
	////////////////////////////

	vector<produit> panier;
	panier = client1->getPanier();
	flux << " ____________________________________________________________________________" << endl;
	flux << "| Information Client                                                         |" << endl;
	flux << "| Identifiant : " << client1->getId();
	taille = to_string(client1->getId());
	n=61-taille.size();
	for (int i =0; i<n; i++){
		flux << " ";
	}
	flux << "|" << endl << "| Nom : " << client1->getNom();
	taille =client1->getNom();
	n=69-taille.size();
	for (int i =0; i<n; i++){
		flux << " ";
	}

	flux << "|" << endl << "| Prenom : " << client1->getPrenom() ;
	taille =client1->getPrenom();
	n=66-taille.size();
	for (int i =0; i<n; i++){
		flux << " ";
	}

	flux << "|" << endl;
	flux << "|----------------------------------------------------------------------------|" << endl;
	flux << "| Produits  :                                                                |" << endl;
	for(int i = 0; i < panier.size(); i++){
		produit prod = panier.at(i);
		cout<< &prod;
	}

	flux << "|____________________________________________________________________________|" << endl;
	flux << endl;
	return flux;
}
