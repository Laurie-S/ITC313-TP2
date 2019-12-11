#ifndef _produit_h
#define _produit_h
#include <iostream>
#include <string>
#include <vector>


using namespace std;


class produit {
public:
	produit(string titre_, string description_, int quantite_, float prix_ );
	float getPrix();
	string getTitre();
	string getDescr();
	int getQuantite();
	void setDescr(string Descr);
	void setQuantite(int newQuantite);
	void setPrix(float newPrix);

private:
	string titre;
	string description;
	int quantite;
	float prix;
};


#endif 