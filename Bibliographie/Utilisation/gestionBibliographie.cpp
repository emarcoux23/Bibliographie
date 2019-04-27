/**
 * \file gestionBibliographie.cpp
 * \brief Utilisation de la classe bibliographie
 * \author Etienne Marcoux
 * \version 1.0
 * \date 2019-04-09
 */

#include <iostream>
#include "Bibliographie.h"
#include "Reference.h"
#include "Ouvrage.h"
#include "Journal.h"
#include "validationFormat.h"
#include <sstream>

using namespace std;
using namespace biblio;
using namespace util;

//Programme utilisateur pour recuperer les informations de l'utilisateur et ainsi creer une bibliographie avec plusieurs elements

int main()
{
	cout << "Bienvenue dans l'outil de gestion de references bibliographiques"
			<< endl;
	cout << "================================================================"
			<< endl;

	char buffer[256]; //initialisation d'un buffer pour utiliser cin.getline

	string nomBibliographie;
	bool temp1 = false;
	do //doWhile pour recuperer le nom de la bilbiographie
	{
		if (temp1 == true)
		{
			cout << "Le nom de la bibliographie n'est pas valide, recommencez."
					<< endl;
		}
		cout << "Entrez le nom de la bibliographie: " << endl;
		cin.getline(buffer, 255);
		nomBibliographie = buffer;
		temp1 = true;
	} while (nomBibliographie[0] == ' ' || nomBibliographie.size() == 0);

	Bibliographie bibli(nomBibliographie); // creation d'un objet bibliographie

	for (int i = 0; i < 4; i++)	//Boucle pour recuperer exactement 4 references
	{
		if (i % 2 == 0) //Condition pour alterner entre les types de references --> i pair (numero de reference impaire) = ouvrage
		{
			cout
					<< "---------------------------------------------------------------------"
					<< endl;
			cout << "Entrez les informations de la reference numero " << i + 1
					<< ", l'ouvrage numero " << (i / 2) + 1 << "." << endl;
			cout
					<< "---------------------------------------------------------------------";
			cout << endl;

			// Requete des informations pour creer un objet ouvrage

			string auteurs;

			bool temp2 = false;
			do //doWhile pour recuperer les auteurs (dans un format valide) de l'ouvrage.
			{
				if (temp2 == true)
				{
					cout << "Le nom des auteurs n'est pas valide, recommencez."
							<< endl;
				}
				cout << "Entrer le nom du ou des auteurs: " << endl;
				cin.getline(buffer, 255);
				auteurs = buffer;
				temp2 = true;
			} while (!validerFormatNom(auteurs) || auteurs[0] == ' '
					|| auteurs.size() == 0);

			string titre;
			bool temp3 = false;
			do //doWhile pour recuperer le titre (dans un format valide) de l'ouvrage.
			{
				if (temp3 == true)
				{
					cout << "Le titre n'est pas valide, recommencez." << endl;
				}
				cout << "Entrez le titre: " << endl;
				cin.getline(buffer, 255);
				titre = buffer;
				temp3 = true;
			} while (titre[0] == ' ' || titre.size() == 0);

			string anneeTemp;
			bool estUneAnnee = true;
			int annee;
			bool temp4 = false;
			do //doWhile pour recuperer l'annee d'edition (dans un format valide) de l'ouvrage.
			{
				if (temp4 == true)
				{
					cout << "L'annee n'est pas valide, recommencez." << endl;
				}
				cout << "Entrez l'annee d'edition: " << endl;
				cin.getline(buffer, 255);
				anneeTemp = buffer;
				estUneAnnee = true;

				for (unsigned int i = 0; i < anneeTemp.length(); i++)
				{
					if (!isdigit(anneeTemp[i]))
					{
						estUneAnnee = false;
					}
				}

				if (anneeTemp[0] == ' ')
				{
					estUneAnnee = false;
				}

				if (anneeTemp.size() == 0)
				{
					estUneAnnee = false;
				}

				if (estUneAnnee == true)
				{
					istringstream(anneeTemp) >> annee;
				}

				if (annee <= 0)
				{
					estUneAnnee = false;
				}
				temp4 = true;
			} while (estUneAnnee == false);

			string identifiant;

			bool temp5 = false;
			do //doWhile pour recuperer l'identifiant ISBN (dans un format valide) de l'ouvrage.
			{
				if (temp5 == true)
				{
					cout << "Le code ISBN n'est pas valide, recommencez."
							<< endl;
				}
				cout << "Entrer le code ISBN: " << endl;
				cin.getline(buffer, 255);
				identifiant = buffer;
				temp5 = true;
			} while (!validerCodeIsbn(identifiant));

			string editeur;
			bool temp6 = false;
			do //doWhile pour recuperer l'editeur (dans un format valide) de l'ouvrage.
			{
				if (temp6 == true)
				{
					cout << "Le nom de l'editeur n'est pas valide, recommencez."
							<< endl;
				}
				cout << "Entrer l'editeur: " << endl;
				cin.getline(buffer, 255);
				editeur = buffer;
				temp6 = true;
			} while (!validerFormatNom(editeur) || editeur[0] == ' '
					|| editeur.size() == 0);

			string ville;
			bool temp7 = false;
			do //doWhile pour recuperer la ville (dans un format valide) de l'ouvrage.
			{
				if (temp7 == true)
				{
					cout << "Le nom de la ville n'est pas valide, recommencez."
							<< endl;
				}
				cout << "Entrez la ville d'edition: " << endl;
				cin.getline(buffer, 255);
				ville = buffer;
				temp7 = true;
			} while (!validerFormatNom(ville) || ville[0] == ' '
					|| ville.size() == 0);

			cout << endl;

			Ouvrage OuvrageUtilisateur(auteurs, titre, annee, identifiant, //creation d'un objet ouvrage avec les informations recues
					editeur, ville);

			bibli.ajouterReference(OuvrageUtilisateur); //Ajout de l'objet reference ouvrage cree dans le vecteur

		}
		else //Condition pour alterner entre les types de references --> i impair (numero de reference paire) = journal
		{

			cout
					<< "----------------------------------------------------------------------"
					<< endl;
			cout << "Entrez les informations de la reference numero " << i + 1
					<< ", le journal numero " << (3 / 2) + (i / 2) << "."
					<< endl;
			cout
					<< "----------------------------------------------------------------------";
			cout << endl;

			//requete des informations pour creer un objet journal

			string auteurs;

			bool temp8 = false;
			do //doWhile pour recuperer les auteurs (dans un format valide) du journal.
			{
				if (temp8 == true)
				{
					cout << "Le nom des auteurs n'est pas valide, recommencez."
							<< endl;
				}
				cout << "Entrer le nom du ou des auteurs: " << endl;
				cin.getline(buffer, 255);
				auteurs = buffer;
				temp8 = true;
			} while (!validerFormatNom(auteurs) || auteurs[0] == ' '
					|| auteurs.size() == 0);

			string titre;
			bool temp9 = false;
			do //doWhile pour recuperer le titre (dans un format valide) du journal.
			{
				if (temp9 == true)
				{
					cout << "Le titre n'est pas valide, recommencez." << endl;
				}
				cout << "Entrez le titre: " << endl;
				cin.getline(buffer, 255);
				titre = buffer;
				temp9 = true;
			} while (titre[0] == ' ' || titre.size() == 0);

			string anneeTemp;
			bool estUneAnnee = true;
			int annee;
			bool temp10 = false;
			do //doWhile pour recuperer l'annee d'edition (dans un format valide) du journal.
			{
				if (temp10 == true)
				{
					cout << "L'annee n'est pas valide, recommencez." << endl;
				}
				cout << "Entrez l'annee: " << endl;
				cin.getline(buffer, 255);
				anneeTemp = buffer;
				estUneAnnee = true;

				for (unsigned int i = 0; i < anneeTemp.length(); i++)
				{
					if (!isdigit(anneeTemp[i]))
					{
						estUneAnnee = false;
					}
				}

				if (anneeTemp[0] == ' ')
				{
					estUneAnnee = false;
				}

				if (anneeTemp.size() == 0)
				{
					estUneAnnee = false;
				}

				if (estUneAnnee == true)
				{
					istringstream(anneeTemp) >> annee;
				}

				if (annee <= 0)
				{
					estUneAnnee = false;
				}

				temp10 = true;
			} while (estUneAnnee == false);

			string identifiant;
			bool temp11 = false;
			do //doWhile pour recuperer l'identifiant ISSN (dans un format valide) du journal.
			{
				if (temp11 == true)
				{
					cout << "Le code ISSN n'est pas valide, recommencez."
							<< endl;
				}
				cout << "Entrez le code ISSN: " << endl;
				cin.getline(buffer, 255);
				identifiant = buffer;
				temp11 = true;
			} while (!validerCodeIssn(identifiant));

			string nom;
			bool temp12 = false;
			do //doWhile pour recuperer le nom (dans un format valide) du journal.
			{
				if (temp12 == true)
				{
					cout << "Le nom n'est pas valide, recommencez." << endl;
				}
				cout
						<< "Entrez le nom de la revue dans laquelle a ete publiee la reference: "
						<< endl;
				cin.getline(buffer, 255);
				nom = buffer;
				temp12 = true;
			} while (!validerFormatNom(nom) || nom[0] == ' ' || nom.size() == 0);

			string volumeTemp;
			bool estUnVolume = true;
			int volume;
			bool temp13 = false;
			do //doWhile pour recuperer le volume (dans un format valide) du journal.
			{
				if (temp13 == true)
				{
					cout << "Le volume n'est pas valide, recommencez." << endl;
				}
				cout << "Entrez le volume: " << endl;
				cin.getline(buffer, 255);
				volumeTemp = buffer;
				estUnVolume = true;

				for (unsigned int i = 0; i < volumeTemp.length(); i++)
				{
					if (!isdigit(volumeTemp[i]))
					{
						estUnVolume = false;
					}
				}

				if (volumeTemp[0] == ' ')
				{
					estUnVolume = false;
				}

				if (volumeTemp.size() == 0)
				{
					estUnVolume = false;
				}

				if (estUnVolume == true)
				{
					istringstream(volumeTemp) >> volume;
				}

				if (volume <= 0)
				{
					estUnVolume = false;
				}
				temp13 = true;

			} while (estUnVolume == false);

			string numeroTemp;
			bool estUnNumero = true;
			int numero;
			bool temp14 = false;
			do //doWhile pour recuperer le numero (dans un format valide) du journal.
			{
				if (temp14 == true)
				{
					cout << "Le numero n'est pas valide, recommencez." << endl;
				}
				cout << "Entrez le numero: " << endl;
				cin.getline(buffer, 255);
				numeroTemp = buffer;
				estUnNumero = true;

				for (unsigned int i = 0; i < numeroTemp.length(); i++)
				{
					if (!isdigit(numeroTemp[i]))
					{
						estUnNumero = false;
					}
				}

				if (numeroTemp[0] == ' ')
				{
					estUnNumero = false;
				}

				if (numeroTemp.size() == 0)
				{
					estUnNumero = false;
				}

				if (estUnNumero == true)
				{
					istringstream(numeroTemp) >> numero;
				}

				if (numero <= 0)
				{
					estUnNumero = false;
				}
				temp14 = true;

			} while (estUnNumero == false);

			string pageTemp;
			bool estUnePage = true;
			int page;
			bool temp15 = false;
			do //doWhile pour recuperer la page (dans un format valide) du journal.
			{
				if (temp15 == true)
				{
					cout << "La page n'est pas valide, recommencez." << endl;
				}
				cout << "Entrez la page ou commence la reference: " << endl;
				cin.getline(buffer, 255);
				pageTemp = buffer;
				estUnePage = true;

				for (unsigned int i = 0; i < pageTemp.length(); i++)
				{
					if (!isdigit(pageTemp[i]))
					{
						estUnePage = false;
					}
				}

				if (pageTemp[0] == ' ')
				{
					estUnePage = false;
				}

				if (pageTemp.size() == 0)
				{
					estUnePage = false;
				}

				if (estUnePage == true)
				{
					istringstream(pageTemp) >> page;
				}

				if (page <= 0)
				{
					estUnePage = false;
				}
				temp15 = true;

			} while (estUnePage == false);

			Journal journalUtilisateur(auteurs, titre, annee, identifiant, nom, //creation d'un objet ouvrage avec les informations recues
					volume, numero, page);

			bibli.ajouterReference(journalUtilisateur);	//Ajout de l'objet reference ouvrage cree dans le vecteur

		}
	}

	cout << endl;
	cout << "References bibliographiques enregistrees :" << endl;
	cout << nomBibliographie << endl;
	cout << "===============================" << endl;
	cout << bibli.reqBibliographieFormate();//Affichage de la bibliographie complete formate

	return 0;

}
