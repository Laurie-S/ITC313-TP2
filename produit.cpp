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

ostream& operator << (ostream &output, produit *prod) {
	string titre = prod->getTitre(); 		// pour que chaque parametre soit au bon endroit lors de l'affichage
	int n = titre.size();
	n=13-n;
	for(int i=0;i<n ;i++){
		titre+=" ";
	}
	string desc = prod->getDescr();
	n = desc.size();
	n=35-n;
	for(int i=0;i<n ;i++){
		desc+=" ";
	}
	string quant = to_string(prod->getQuantite());
	n = quant.size();
	n=16-n;
	for(int i=0;i<n ;i++){
		quant+=" ";
	}
	string prix = to_string(prod->getPrix());
	n = prix.size();			
	for(int i=0;i<n ;i++){						//pour ne pas qu'il y ai trop de chiffre apres la virgule
		if(prix[i]=='.'){
			prix.resize(i+3);
			i=n;
		}
	}
	n = prix.size();
	n=9-n;
	for(int i=0;i<n ;i++){
		prix+=" ";
	}

	output << "| " << titre << desc << quant << prix << "€ |" << endl;
	return output; 
}
