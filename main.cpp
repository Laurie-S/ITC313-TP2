#include <iostream>
#include <string>
#include <fstream>
#include "magasin.h"
#include "client.h"
#include "commande.h"
#include "produit.h"

using namespace std;
/*
vector<produit> recSauvPdt(){
	int param = 1,par = 0, n, m ;
	vector<produit> v;
	string line;
	string a = "magasin.txt";
	ifstream lect(a);
	string tmp="";
	string titre, descr;
	int quant;
	float prix;


	if(lect){
		getline(lect, line);
		n=atoi((line).c_str());

		for (int i = 0; i < n; i++){
			param=1;
			getline(lect, line);
			int j=0;

			while(line[j]!=';'){
				if(line[j]!=','){
					tmp+=line[j];
				}
				else{
					if(param==1){
						titre = tmp;
						param++;
						tmp="";
					}
					else if(param==2){
						descr=tmp;
						param++;
						tmp="";
					}
					else if(param==3){
						quant=atoi(tmp.c_str());
						param++;
						tmp="";
					}
					else if(param==4){
						prix=strtof((tmp).c_str(),0);
						param++;
						tmp="";
					}
				}
				j++;
			}
			tmp="";
			produit prod(titre,descr,quant,prix);
			v.push_back(prod);	
		}
	}
	return v;

}

vector<client> recSauvClt(){
	int param = 1,par = 0, n, m ;
	string line;
	string a = "magasin.txt";
	ifstream lect(a);
	string tmp="";
	string titre, descr, Nom,Prenom;
	int Id, quant;
	float prix;
	vector<produit> produ;
	vector<client> v;

	if(lect){
		getline(lect, line);
		n=atoi((line).c_str());
		while(line[0]!='/'){
			getline(lect, line);
		}


		getline(lect, line);
		n=atoi((line).c_str());
		for (int i = 0; i < n; i++){

			vector<produit> produ;

			param=1;
			getline(lect, line);
			int j=0;
			int param2=0;
			while(line[j]!='/'){
				if(line[j]!=',' && line[j]!=';'){
					tmp+=line[j];
				}
				else{
					if (param<5){
						if(param==1){
							Id=atoi(tmp.c_str());
							param++;
							tmp="";
						}
						else if(param==2){
							Nom = tmp;
							param2++;
							tmp="";
						}
						else if(param==3){
							Prenom = tmp;
							param2++;
							tmp="";
						}
						else if(param==4){
							quant=atoi(tmp.c_str());
							param2++;
							tmp="";
						}
					}
					else{
						if(param2==1){
							titre = tmp;
							param2++;
							tmp="";
						}
						else if(param2==2){
							descr=tmp;
							param2++;
							tmp="";
						}
						else if(param2==3){
							quant=atoi(tmp.c_str());
							param2++;
							tmp="";
						}
						else if(param2==4){
							prix=strtof((tmp).c_str(),0);
							param2++;
							tmp="";
						}
					}
					if(param2==5){
						produit prod(titre,descr,quant,prix);
						produ.push_back(prod);	
					}
				}
				j++;
			}
			tmp="";
			client cli(Id,Nom,Prenom);
			cli.setPanier(produ);
			v.push_back(cli);
		}
	}
	return v;

}

*/



int main(){
	magasin mag1(0);
	int choix=-1;

	vector<produit> prod;
	vector<client> cl;
	vector<commande> com;
	vector<produit> v;

	bool fini = false;
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

	while(fini==false){
		choix = -1;
		while(choix < 0 || choix > 3){
			cout << " ____________________________________________________________________________" << endl;
			cout << "|                                                                            |" << endl;
			cout << "|  MENU PRINCIPAL                                                            |" << endl;
			cout << "|                                                                            |" << endl;
			cout << "|   Que voulez-vous faire ?                                                  |" << endl;
			cout << "|                                                                            |" << endl;
			cout << "|      1. Gestion du magasin                                                 |" << endl;
			cout << "|      2. Gestion des commandes                                              |" << endl;
			cout << "|      3. Gestion des clients                                                |" << endl;
			cout << "|                                                                            |" << endl;
			cout << "|      0. Quitter                                                            |" << endl;
			cout << "|____________________________________________________________________________|" << endl;
			cout << "|  ";
			cin >> choix;
		}

		if(choix == 1){
			cout << " ____________________________________________________________________________" << endl;
			cout << "|                                                                            |" << endl;
			cout << "|                                                                            |" << endl;
			cout << "|   Que voulez-vous faire ?                                                  |" << endl;
			cout << "|                                                                            |" << endl;
			cout << "|      1. Ajouter un produit                                                 |" << endl;
			cout << "|      2. Changer la Quantité d'un produit                                   |" << endl;
			cout << "|      3. Voir les produits                                                  |" << endl;
			cout << "|      4. Voir un Produit                                                    |" << endl;
			cout << "|                                                                            |" << endl;
			cout << "|____________________________________________________________________________|" << endl;
			cout << "|  ";
			cin >> choix;

			if(choix==1){
				int quant;
				float prix;
				string titre,descr;
				cout << " ____________________________________________________________________________" << endl;
				cout << "|                                                                            |" << endl;
				cout << "|   Entrez, séparés d'un espace, le titre, la description (en un seul mot),  |" << endl;
				cout << "|    la quantité et le prix.                                                 |" << endl;
				cout << "|                                                                            |" << endl;
				cout << "|____________________________________________________________________________|" << endl;
				cout << "|  ";
				cin >> titre;
				cin >> descr;
				cin >> quant;
				cin >>  prix;
				produit p(titre,descr,quant,prix);
				prod.push_back(p);
				mag1.addProduit(&prod.at(prod.size()-1));
			}
			else if(choix==2){
				int quant;
				string titre;
				cout << " ____________________________________________________________________________" << endl;
				cout << "|                                                                            |" << endl;
				cout << "|    Entrez, séparé d'un espace, le titre du produit et la nouvelle quantité |" << endl;
				cout << "|                                                                            |" << endl;
				cout << "|                                                                            |" << endl;
				cout << "|____________________________________________________________________________|" << endl;
				cout << "|  ";
				cin >> titre ;
				cin >> quant;
				mag1.modifQuantite(titre,quant);
			}
			else if(choix==4){
				int quant;
				string titre;
				cout << " ____________________________________________________________________________" << endl;
				cout << "|                                                                            |" << endl;
				cout << "|    Entrez le titre du produit                                              |" << endl;
				cout << "|                                                                            |" << endl;
				cout << "|                                                                            |" << endl;
				cout << "|____________________________________________________________________________|" << endl;
				cout << "|  ";
				cin >> titre ;
				mag1.displayProduitChoisi(titre);
			}
			else if(choix==3){
				mag1.displayProduit();
			}
		}

		else if(choix == 2){
			cout << " ____________________________________________________________________________" << endl;
			cout << "|                                                                            |" << endl;
			cout << "|                                                                            |" << endl;
			cout << "|   Que voulez-vous faire ?                                                  |" << endl;
			cout << "|                                                                            |" << endl;
			cout << "|      1. Transmettre la commande d'un client                                |" << endl;
			cout << "|      2. Accuser la reception de la commande d'un client                    |" << endl;
			cout << "|      3. Afficher les commandes                                             |" << endl;
			cout << "|      4. Afficher les commandes d'un client  (par son nom)                  |" << endl;
			cout << "|      5. Afficher les commandes d'un client  (par son Id)                   |" << endl;
			cout << "|                                                                            |" << endl;
			cout << "|____________________________________________________________________________|" << endl;
			cout << "|  ";
			cin >> choix;

			if(choix==1){
				int quant;
				float prix;
				string titre,descr;
				cout << " ____________________________________________________________________________" << endl;
				cout << "|                                                                            |" << endl;
				cout << "|    Entrez le Nom du client                                                 |" << endl;
				cout << "|                                                                            |" << endl;
				cout << "|____________________________________________________________________________|" << endl;
				cout << "|  ";
				cin >> titre ;
				client cli = mag1.findClient(titre);
				commande c(cli,v);
				com.push_back(c);
				mag1.validerCommande(cli,&com.at(com.size()-1));
			}
			else if(choix==2){
				int quant;
				string titre;
				cout << " ____________________________________________________________________________" << endl;
				cout << "|                                                                            |" << endl;
				cout << "|    Entrez le Nom du client                                                 |" << endl;
				cout << "|                                                                            |" << endl;
				cout << "|                                                                            |" << endl;
				cout << "|____________________________________________________________________________|" << endl;
				cout << "|  ";
				cin >> titre ;
				client cli = mag1.findClient(titre);
				mag1.livre(&cli);
			}
			else if(choix==4){
				int quant;
				string titre;
				cout << " ____________________________________________________________________________" << endl;
				cout << "|                                                                            |" << endl;
				cout << "|    Entrez le Nom du client                                                 |" << endl;
				cout << "|                                                                            |" << endl;
				cout << "|                                                                            |" << endl;
				cout << "|____________________________________________________________________________|" << endl;
				cout << "|  ";
				cin >> titre ;
				client cli = mag1.findClient(titre);
				mag1.displayCommandeClient(cli);
			}
			else if(choix==5){
				int quant;
				int titre;
				cout << " ____________________________________________________________________________" << endl;
				cout << "|                                                                            |" << endl;
				cout << "|    Entrez le Nom du client                                                 |" << endl;
				cout << "|                                                                            |" << endl;
				cout << "|                                                                            |" << endl;
				cout << "|____________________________________________________________________________|" << endl;
				cout << "|  ";
				cin >> titre ;
				client cli = mag1.findClient(titre);
				mag1.displayCommandeClient(cli);
			}

			else if(choix==3){
				mag1.displayCommandes();
			}
		}

		else if(choix == 3){
				cout << " ____________________________________________________________________________" << endl;
				cout << "|                                                                            |" << endl;
				cout << "|                                                                            |" << endl;
				cout << "|   Que voulez-vous faire ?                                                  |" << endl;
				cout << "|                                                                            |" << endl;
				cout << "|      1. Ajouter un produit au panier d'un client                           |" << endl;
				cout << "|      2. Changer la Quantité d'un produit                                   |" << endl;
				cout << "|      3. Supprimer un produit                                               |" << endl;
				cout << "|      4. Ajouter un client                                                  |" << endl;
				cout << "|      5. Afficher un client    (par son nom)                                |" << endl;
				cout << "|      6. Afficher un client     (par son Id)                                |" << endl;
				cout << "|      7. Afficher la liste des clients                                      |" << endl;
				cout << "|                                                                            |" << endl;
				cout << "|____________________________________________________________________________|" << endl;
				cout << "|  ";
				cin >> choix;

				if(choix==1){
					int quant,i;
					string titre,clien;
					cout << " ____________________________________________________________________________" << endl;
					cout << "|                                                                            |" << endl;
					cout << "|    Entrez le Nom du produit, du client et la quantité separé par un espace |" << endl;
					cout << "|                                                                            |" << endl;
					cout << "|____________________________________________________________________________|" << endl;
					cout << "|  ";
					cin >> titre ;
					cin >> clien;
					cin >> quant;
					client cli = mag1.findClient(clien);
					i = mag1.findProduct(titre);

					mag1.addProduitClient(cli, prod.at(i), quant);

				}
				else if(choix==3){
					int quant,i;
					string titre,clien;
					cout << " ____________________________________________________________________________" << endl;
					cout << "|                                                                            |" << endl;
					cout << "|    Entrez le Nom du produit et du client    separé par un espace           |" << endl;
					cout << "|                                                                            |" << endl;
					cout << "|____________________________________________________________________________|" << endl;
					cout << "|  ";
					cin >> titre ;
					cin >> clien;
					cin >> quant;
					client cli = mag1.findClient(clien);
					i = mag1.findProduct(titre);
					mag1.supProduitClient(cli, prod.at(i));


				}
				else if(choix==2){
					int quant,i;
					string titre,clien;
					cout << " ____________________________________________________________________________" << endl;
					cout << "|                                                                            |" << endl;
					cout << "|    Entrez le Nom du produit, du client et la quantité separé par un espace |" << endl;
					cout << "|                                                                            |" << endl;
					cout << "|____________________________________________________________________________|" << endl;
					cout << "|  ";
					cin >> titre ;
					cin >> clien;
					cin >> quant;
					client cli = mag1.findClient(clien);
					i = mag1.findProduct(titre);

					mag1.addProduitClient(cli, prod.at(i), quant);

				}
				else if(choix==4){
					int quant;
					string titre, pre;
					cout << " ____________________________________________________________________________" << endl;
					cout << "|                                                                            |" << endl;
					cout << "|    Entrez le Nom du client et son Prenom separé par un espace              |" << endl;
					cout << "|                                                                            |" << endl;
					cout << "|                                                                            |" << endl;
					cout << "|____________________________________________________________________________|" << endl;
					cout << "|  ";
					cin >> titre ;
					cin >> pre;
					client cli(cl.size()+1, pre , titre);
					cl.push_back(cli);
					mag1.addClient(&cl.at(cl.size()-1));
				}
				else if(choix==5){
					string titre;
					cout << " ____________________________________________________________________________" << endl;
					cout << "|                                                                            |" << endl;
					cout << "|    Entrez le Nom du client                                                 |" << endl;
					cout << "|                                                                            |" << endl;
					cout << "|                                                                            |" << endl;
					cout << "|____________________________________________________________________________|" << endl;
					cout << "|  ";
					cin >> titre ;
					mag1.displayClientChoisi( titre);
				}
				else if(choix==6){
					int titre;
					cout << " ____________________________________________________________________________" << endl;
					cout << "|                                                                            |" << endl;
					cout << "|    Entrez le Nom du client                                                 |" << endl;
					cout << "|                                                                            |" << endl;
					cout << "|                                                                            |" << endl;
					cout << "|____________________________________________________________________________|" << endl;
					cout << "|  ";
					cin >> titre ;
					mag1.displayClientChoisi( titre);
				}
				else if(choix==7){
					mag1.displayClient();
				}
			}
		}
		else{
			cout << "fin du programme " << endl;
			fini = true;
		}
	}

