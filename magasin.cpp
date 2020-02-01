#include <iostream>
#include <string>
#include <vector>
#include "magasin.h"
#include "produit.h"
#include "client.h"
#include "commande.h"

using namespace std;

magasin::magasin(int nb_produit_ = 0){ // pour pouvoir creer un magasion vide
	nb_produit=nb_produit_;
}

void magasin::addProduit(produit *prod1){
	m_produit.push_back(prod1);
}

produit* magasin::getProduit(int n){
	return m_produit.at(n);
}

void magasin::displayProduit(){
	int n=m_produit.size();
	cout << " ____________________________________________________________________________" << endl;
	cout << "|  PRODUITS                                                                  |" << endl;
	cout << "|----------------------------------------------------------------------------|" << endl;
	cout << "| Nom          Description                        Quantite        Prix       |" << endl;
	cout << "|----------------------------------------------------------------------------| " << endl;

	for(int i =0; i<n ; i++){
		cout << m_produit.at(i);
	}

	cout << "|____________________________________________________________________________| " << endl << endl;
}

void magasin::displayProduitChoisi(string prod_s){
	int j = findProduct(prod_s);

	if(j>m_produit.size()){
		cout << "produit " << prod_s << " non trouve" << endl << endl;
	}
	else{
		cout << " ____________________________________________________________________________" << endl;
		cout << "|  PRODUITS                                                                  |" << endl;
		cout << "|----------------------------------------------------------------------------|" << endl;
		cout << "| Nom          Description                        Quantite        Prix       |" << endl;
		cout << "|----------------------------------------------------------------------------| " << endl;

		cout << m_produit.at(j);

		cout << "|____________________________________________________________________________| " << endl << endl;
	}
}

int magasin::findProduct(string prod_s){
	int n=m_produit.size();

	for(int i =0; i<n ; i++){
		produit prod1 = *m_produit.at(i);
		if(prod1.getTitre()==prod_s){
			return i;
		}
	}
	return n+1;
}

bool magasin::modifQuantite(string prod_s, int newQuantite){
	int j = findProduct(prod_s);
	if (newQuantite>=0){
		if(j>m_produit.size()){
			cout << "produit " << prod_s << " non trouve" << endl << endl;
		}
		else{
			produit *prod1=m_produit.at(j);
			prod1->setQuantite(newQuantite);
			return true;
		}
	}
	else{
		cout << "Impossible ! Stock trop bas !" << endl;
	}
	return false;
}

void magasin::addClient(client *cli){
	bool deja_client = false;
	for(int i =0;i< m_client.size(); i++){
		if(m_client.at(i)->getId()==cli->getId()){
			deja_client=true;
		}
	}
	if(deja_client==true){
		cout << "client deja présent dans les informations du magasin " << endl;
	}
	else {
		m_client.push_back(cli);
	}
}

void magasin::displayClient(){
	cout << " ____________________________________________________________________________" << endl;
	cout << "|Liste des clients :                                                         |" << endl;
	cout << "|----------------------------------------------------------------------------|" << endl;
	for(int i = 0; i < m_client.size(); i++){
		client cli = *m_client.at(i);
		cout << "| " << cli.getId();
		int n=5-(((to_string(cli.getId())).size()));
		for(int j = 0; j < n; j++){
			cout << " ";
		}
		cout << cli.getNom() << " " << cli.getPrenom();
		n=72-((cli.getNom()).size()+(cli.getPrenom()).size()+3);
		for(int j = 0; j < n; j++){
			cout << " ";
		}
		cout <<  "|" << endl;
	}
	cout << "|____________________________________________________________________________|" << endl;
	cout << endl << endl;
}

client magasin::findClient(string nom){
	for(int i = 0; i < m_client.size(); i++){
		client cli = *m_client.at(i);
		if(cli.getNom()==nom){
			return cli;
		}
	}
}

client magasin::findClient(int Id){
	for(int i = 0; i < m_client.size(); i++){
		client cli = *m_client.at(i);
		if(cli.getId()==Id){
			return cli;
		}
	}
}

void magasin::displayClientChoisi(string nom){
	cout << " ____________________________________________________________________________" << endl;
	cout << "|Client choisi :                                                             |" << endl;
	cout << "|----------------------------------------------------------------------------|" << endl;
	
	client cli = findClient(nom);
	cout << "| " << cli.getId();
	int n=5-(((to_string(cli.getId())).size()));
	for(int j = 0; j < n; j++){
		cout << " ";
	}
	cout << cli.getNom() << " " << cli.getPrenom();
	n=72-((cli.getNom()).size()+(cli.getPrenom()).size()+3);
	for(int j = 0; j < n; j++){
		cout << " ";
	}
	cout <<  "|" << endl;

	cout << "|____________________________________________________________________________|" << endl;
	cout << endl << endl;
}

void magasin::displayClientChoisi(int Id){
	cout << " ____________________________________________________________________________" << endl;
	cout << "|Client choisi :                                                             |" << endl;
	cout << "|----------------------------------------------------------------------------|" << endl;

	client cli = findClient(Id);
	cout << "| " << cli.getId();
	int n=5-(((to_string(cli.getId())).size()));
	for(int j = 0; j < n; j++){
		cout << " ";
	}
	cout << cli.getNom() << " " << cli.getPrenom();
	n=72-((cli.getNom()).size()+(cli.getPrenom()).size()+3);
	for(int j = 0; j < n; j++){
		cout << " ";
	}
	cout <<  "|" << endl;

	cout << "|____________________________________________________________________________|" << endl;
	cout << endl << endl;
}

void magasin::addProduitClient(client clie, produit prod, int Quant){
	int n=0;
	int pr = findProduct(prod.getTitre());
	
	for(int i = 0; i < m_client.size(); i++){
		client cli = *m_client.at(i);
		if(cli.getId()==clie.getId()){
			n++;
			int Q =getQuantiteProdClient(cli, prod);
			int Quant2=	Q+Quant;
			if (Quant2>0){
				if (pr<=m_produit.size()){
					if (m_produit.at(pr)->getQuantite()>0){
						bool marche = modifQuantite(prod.getTitre(),m_produit.at(pr)->getQuantite()-Quant);
						if (marche){ 
							produit p = prod;
							p.setQuantite(Quant+Q);
							if (Q!=0){
								m_client.at(i)->supPdtPanier(p.getTitre());
							}
							m_client.at(i)->addPdtPanier(p);
						}
					}
					else{
						cout << "Impossible ! Le produit n'est plus en stock..." << endl;
					}
				}
				else {
					cout << "Impossible ! Le magasin ne vent pas ce produit..." << endl;
				}
			}
			else if (Quant==0){
				cout << "Impossible ! essayez de suprimer le produit... " << endl;
			}
			else {
				cout << "Impossible ! Quantite invalide..." << endl;
			}	
		}
	}
	if(n==0){
		cout << "Client introuvable" << endl << " Veuillez ajouter le client avant d'ajouter un produit..." << endl << endl;
	}
	
}

int magasin::getQuantiteProdClient(client clie, produit prod){
	vector<produit> pr=clie.getPanier();
	int quant =0;
	for (int i = 0; i < pr.size(); i++)
	{
		if((pr.at(i).getTitre())==prod.getTitre()){
			quant = (pr.at(i)).getQuantite();
		}
	}
	return quant;
}

void magasin::supProduitClient(client clie, produit prod){
	int n=0;
	int pr = findProduct(prod.getTitre());

	for(int i = 0; i < m_client.size(); i++){
		client cli = *m_client.at(i);
		if(cli.getId()==clie.getId()){
			if (pr<=m_produit.size()){
				int Quant=getQuantiteProdClient(cli,prod);
				modifQuantite(prod.getTitre(),m_produit.at(pr)->getQuantite()+Quant);
				m_client.at(i)->supPdtPanier(prod.getTitre());
			}
			n++;
		}
	}
	if(n==0){
		cout << "Client introuvable" << endl << " Veuillez ajouter le client avant d'ajouter un produit " << endl << endl;
	}
}