/**
 * \file Ouvrage_Testeur.cpp
 * \brief Tests unitaires de la classe Ouvrage
 * \author Etienne Marcoux
 * \version 1.0
 * \date 2019-04-09
 */

#include "Ouvrage.h"
#include "ContratException.h"
#include <gtest/gtest.h>

using namespace std;
using namespace biblio;

/**
 * \brief Test du constructeur
 *  	  Cas valides: Creation d'un objet ouvrage et verification de l'assignation de tous les attributs
 *  	  Cas invalides:
 *  	  		identifiant == code ISSN != code ISBN
 *  	  		editeur == "   "
 *  	  		ville == "   "
 */
TEST(Ouvrage, ConstructeurValide)
{
	Ouvrage unOuvrage("etienne marcoux", "mon livre", 2019,
			"ISBN 0-13-235088-2", "mon editeur", "ma ville");
	ASSERT_EQ("mon editeur", unOuvrage.reqEditeur());
	ASSERT_EQ("ma ville", unOuvrage.reqVille());
}
//Cas invalides
TEST(Ouvrage, ConstructeurInvalideIdentifiant)
{
	ASSERT_THROW(
			Ouvrage unOuvrage("etienne marcoux", "mon livre", 2019, "ISSN 0378-5955", "mon editeur", "ma ville"),
			PreconditionException);
}
TEST(Ouvrage, ConstructeurInvalideEditeur)
{
	ASSERT_THROW(
			Ouvrage unOuvrage("etienne marcoux", "mon livre", 2019, "ISBN 0-13-235088-2", "mon editeur 2", "ma ville"),
			PreconditionException);
}
TEST(Ouvrage, ConstructeurInvalideVille)
{
	ASSERT_THROW(
			Ouvrage unOuvrage("etienne marcoux", "mon livre", 2019, "ISBN 0-13-235088-2", "mon editeur", "ma ville 2"),
			PreconditionException);
}

/**
 * \brief Creation d'une fixture a utiliser pour les methodes public de la classe test
 */
class OuvrageValide: public ::testing::Test
{
public:
	OuvrageValide() :
			ouvrage("etienne marcoux", "mon livre", 2019, "ISBN 0-13-235088-2",
					"mon editeur", "ma ville")
	{
	}
	;
	Ouvrage ouvrage;
};

/**
 * \test Test de la methode reqEditeur()
 * 		 Cas valide: verifier le retour de l'editeur
 * 		 Cas invalide: aucun
 */
TEST_F(OuvrageValide, reqEditeur)
{
	ASSERT_EQ("mon editeur", ouvrage.reqEditeur());
}

/**
 * \test Test de la methode reqVille()
 * 		 Cas valide: verifier le retour de la ville
 * 		 Cas invalide: aucun
 */
TEST_F(OuvrageValide, reqVille)
{
	ASSERT_EQ("ma ville", ouvrage.reqVille());
}

/**
 * \test Test de la methode reqReferenceFormatee()
 * 		 Cas valide: verifier le retour des informations sur l'objet Ouvrage formate
 * 		 Cas invalide: aucun
 */
TEST_F(OuvrageValide, reqReferenceFormatee)
{
	ASSERT_EQ(
			"etienne marcoux. mon livre. ma ville : mon editeur, 2019. ISBN 0-13-235088-2.",
			ouvrage.reqReferenceFormate());
}

/**
 * \test Test de la methode de clone de l'objet Journal
 * 		 Cas valide: verifier qu'un clone de l'objet Journal est cree et qu'il est identique a l'objet original et que l'adresse n'est pas la meme
 * 		 Cas invalide: aucun
 */
TEST_F(OuvrageValide, clone)
{
	Reference* cloneReference = ouvrage.clone();
	Ouvrage* cloneOuvrage = (Ouvrage*) cloneReference;

	ASSERT_EQ((*cloneOuvrage).reqReferenceFormate(),
			ouvrage.reqReferenceFormate());
	ASSERT_FALSE(cloneOuvrage == &ouvrage);
}

