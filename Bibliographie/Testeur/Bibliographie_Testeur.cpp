/**
 * \file Bibliographie_Testeur.cpp
 * \brief Tests unitaires de la classe Bibliographie
 * \author Etienne Marcoux
 * \version 1.0
 * \date 2019-04-09
 */

#include "Bibliographie.h"
#include "Ouvrage.h"
#include "Journal.h"
#include "ContratException.h"
#include <gtest/gtest.h>

using namespace std;
using namespace biblio;

/**
 * \brief Test du constructeur
 *  	  Cas valides: Creation d'un objet Bibliographie et verification de l'assignation de l'attribut
 *  	  Cas invalides:
 *  	  				nom == ""
 *  	  				nom == " "
 */
TEST(Bibliographie, ConstructeurValide)
{
	Bibliographie uneBibliographie("nom de la bibliographie");
	ASSERT_EQ("nom de la bibliographie", uneBibliographie.reqNom());
}
//Cas invalides
TEST(Bibliographie, ConstructeurInvalideVide)
{
	ASSERT_THROW(Bibliographie uneBibliographie(""), PreconditionException);
}

TEST(Bibliographie, ConstructeurInvalideEspace)
{
	ASSERT_THROW(Bibliographie uneBibliographie(" "), PreconditionException);
}

/**
 * \brief Creation d'une fixture a utiliser pour les methodes public de la classe test
 */
class BibliographieValide: public ::testing::Test
{
public:
	BibliographieValide() :
			bibliographie("nom de la bibliographie")
	{
	}
	;
	Bibliographie bibliographie;
};

/**
 * \test Test de la methode reqNom()
 * 		 Cas valide: verifier le retour du nom
 * 		 Cas invalide: aucun
 */
TEST_F(BibliographieValide, reqNom)
{
	ASSERT_EQ("nom de la bibliographie", bibliographie.reqNom());
}

/**
 * \test Test de la methode reqReferenceFormatee()
 * 		 Cas valide: verifier le retour des informations sur l'objet Bibliographie formate
 * 		 Cas invalide: aucun
 */
TEST_F(BibliographieValide, reqBibliographieFormatee)
{
	Ouvrage unOuvrage("etienne marcoux", "mon livre", 2019,
			"ISBN 0-13-235088-2", "mon editeur", "ma ville");
	Journal unJournal("etienne marcoux", "mon livre", 2019, "ISSN 0032-1478",
			"le nom", 1, 2, 3);
	bibliographie.ajouterReference(unOuvrage);
	bibliographie.ajouterReference(unJournal);

	ASSERT_EQ(
			"[1] etienne marcoux. mon livre. ma ville : mon editeur, 2019. ISBN 0-13-235088-2.\n[2] etienne marcoux. mon livre. le nom, vol. 1, no. 2, pp. 3, 2019. ISSN 0032-1478.\n",
			bibliographie.reqBibliographieFormate());
}

/**
 * \test Test de la methode reqReferenceFormatee()
 * 		 Cas valide: verifier le retour des informations sur l'objet Bibliographie formate
 * 		 Cas invalide: aucun
 */
TEST_F(BibliographieValide, ajouterReferenceNonPresente)
{
	Ouvrage unOuvrage("etienne marcoux", "mon livre", 2019,
			"ISBN 0-13-235088-2", "mon editeur", "ma ville");
	Journal unJournal("etienne marcoux", "mon livre", 2019, "ISSN 0032-1478",
			"le nom", 1, 2, 3);
	bibliographie.ajouterReference(unOuvrage);
	bibliographie.ajouterReference(unJournal);

	ASSERT_EQ(
			"[1] etienne marcoux. mon livre. ma ville : mon editeur, 2019. ISBN 0-13-235088-2.\n[2] etienne marcoux. mon livre. le nom, vol. 1, no. 2, pp. 3, 2019. ISSN 0032-1478.\n",
			bibliographie.reqBibliographieFormate());
}

/**
 * \test Test de la methode reqReferenceFormatee()
 * 		 Cas valide: verifier le retour des informations sur l'objet Bibliographie formate
 * 		 Cas invalide: aucun
 */
TEST_F(BibliographieValide, ajouterReferenceDejaPresente)
{
	Ouvrage unOuvrage("etienne marcoux", "mon livre", 2019,
			"ISBN 0-13-235088-2", "mon editeur", "ma ville");
	bibliographie.ajouterReference(unOuvrage);
	Ouvrage unAutreOuvrage("etienne marcoux", "mon livre", 2019,
			"ISBN 0-13-235088-2", "mon editeur", "ma ville");
	bibliographie.ajouterReference(unAutreOuvrage);

	ASSERT_EQ(
			"[1] etienne marcoux. mon livre. ma ville : mon editeur, 2019. ISBN 0-13-235088-2.\n",
			bibliographie.reqBibliographieFormate());
}

