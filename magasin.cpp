#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "magasin.h"
#include "produit.h"
#include "client.h"
#include "commande.h"

using namespace std;

magasin::magasin(int nb_produit_ = 0){ // pour pouvoir creer un magasin vide
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

void magasin::validerCommande(client cli, commande *comm){
	client cli2= findClient(cli.getId());
	vector<produit> v = cli.getPanier();
	for (int i = 0; i < v.size(); i++)
	{
		comm->addProduit(v.at(i));
	}
	addCommande(comm);
	cli2.videPanier();
	cout << "Commande Valide " << endl << "Compte rendu de la commande : " << endl; 

	cout << comm << endl; 
}

void magasin::addCommande(commande *comm){
	m_commande.push_back(comm);
}

void magasin::livre(client *cli){
	for (int i = 0; i < m_commande.size(); ++i)
	{
		client cl=m_commande.at(i)->getClient();
		if(cl.getId()==cli->getId()){
			if(m_commande.at(i)->getStatus()==false){
				m_commande.at(i)->livre();
				cout << "Commande livre avec succes " << endl;
				i = 1+m_commande.size();
			}
		}
	}
}

void magasin::displayCommandes(){
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "AFFICHAGE DE TOUTES LES COMMANDES DU MAGASIN" << endl;
	for (int i = 0; i < m_commande.size(); ++i)
	{
		cout << m_commande.at(i);
	}
}


void magasin::displayCommandeClient(client cli){
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "AFFICHAGE DES COMMANDES DU CLIENT" << endl;
	for (int i = 0; i < m_commande.size(); ++i)
	{
		client cli2 = m_commande.at(i)->getClient();
		if(cli2.getId()==cli.getId()){
			cout << m_commande.at(i);
		}
	}		
}

void magasin::sauvegarde(){
	string a = "magasin.txt";
	remove("magasin.txt");

	ofstream save(a, ios::app); // on ouvre le fichier
	if (save){ // si on a reussi a l'ouvrir
		cout << "Sauvegarde en cours" << endl; // informe l'utilisateur
		save << m_produit.size() << endl;
		for (int i = 0; i < m_produit.size(); i++){
			save<<m_produit.at(i)->getTitre()<<",";
			save<<m_produit.at(i)->getDescr()<<",";
			save<<m_produit.at(i)->getQuantite()<<",";
			save<<m_produit.at(i)->getPrix()<<";"<<endl;
		}
		save << "/" << endl;
		save << m_client.size() << endl;
		for (int i = 0; i < m_client.size(); i++){
			save<<m_client.at(i)->getId()<<",";
			save<<m_client.at(i)->getNom()<<",";
			save<<m_client.at(i)->getPrenom()<<",";
			vector<produit> v = m_client.at(i)->getPanier();
			save << v.size()<<",";
			for (int j = 0; j < v.size(); j++){
				save<<(v.at(i)).getTitre()<<",";
				save<<(v.at(i)).getDescr()<<",";
				save<<(v.at(i)).getQuantite()<<",";
				save<<(v.at(i)).getPrix()<<";";
			}
			save << endl;
		}

		save << "/" << endl;
		save << m_commande.size() << endl;
		for (int i = 0; i < m_commande.size(); i++){
			save<<m_commande.at(i)->getStatus()<<",";
			save<<(m_commande.at(i)->getClient()).getId()<<",";
			save<<(m_commande.at(i)->getClient()).getNom()<<",";
			save<<(m_commande.at(i)->getClient()).getPrenom()<<",";

			vector<produit> v = m_commande.at(i)->getPdtCom();
			save << v.size()<<",";
			for (int j = 0; j < v.size(); j++){
				save<<(v.at(i)).getTitre()<<",";
				save<<(v.at(i)).getDescr()<<",";
				save<<(v.at(i)).getQuantite()<<",";
				save<<(v.at(i)).getPrix()<<",";
			}
			save << endl;
		}

		save << endl; // on revient a la ligne dans le fichier
		save.close(); // on ferme le fichier 
		cout << "Sauvegarde réussie" << endl;
	}
	
	else{
		cout << "Echec de la Sauvegarde" << endl;  //on informe que la sauvegarde n'as pas marché
	}
}