#include <iostream>
#include <string>
#include <vector>
#include "produit.h"

using namespace std;

produit::produit(string titre_, string description_, int quantite_, float prix_ ){
	titre=titre_;
	description=description_;
	quantite=quantite_;
	prix=prix_;
}

float produit::getPrix(){
	return prix;
}

string produit::getTitre(){
	return titre;
}

string produit::getDescr(){
	return description;
}

int produit::getQuantite(){
	return quantite;
}

void produit::setDescr(string Descr){
	description=Descr;
}

void produit::setQuantite(int newQuantite){
	quantite=newQuantite;
}

void produit::setPrix(float newPrix){
	prix=newPrix;
}
