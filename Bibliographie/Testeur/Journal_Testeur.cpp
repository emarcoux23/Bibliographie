/**
 * \file Journal_Testeur.cpp
 * \brief Tests unitaires de la classe Journal
 * \author Etienne Marcoux
 * \version 1.0
 * \date 2019-04-09
 */

#include "Journal.h"
#include "ContratException.h"
#include <gtest/gtest.h>

using namespace std;
using namespace biblio;

/**
 * \brief Test du constructeur
 *  	  Cas valides: Creation d'un objet journal et verification de l'assignation de tous les attributs
 *  	  Cas invalides:
 *  	  		identifiant == code ISBN != code ISSN
 *  	  		nom == "   "
 */
TEST(Journal, ConstructeurValide)
{
	Journal unJournal("etienne marcoux", "mon livre", 2019, "ISSN 0032-1478",
			"le nom", 1, 2, 3);
	ASSERT_EQ("le nom", unJournal.reqNom());
	ASSERT_EQ(1, unJournal.reqVolume());
	ASSERT_EQ(2, unJournal.reqNumero());
	ASSERT_EQ(3, unJournal.reqPage());
}
//Cas invalides
TEST(Journal, ConstructeurInvalideIdentifiant)
{
	ASSERT_THROW(
			Journal unJournal("etienne marcoux", "mon livre", 2019, "ISBN 0-13-235088-2", "le nom", 1, 2, 3),
			PreconditionException);
}
TEST(Journal, ConstructeurInvalideNom)
{
	ASSERT_THROW(
			Journal unJournal("etienne marcoux", "mon livre", 2019, "ISSN 0032-1478", "le nom 2", 1, 2, 3),
			PreconditionException);
}

/**
 * \brief Creation d'une fixture a utiliser pour les methodes public de la classe test
 */
class JournalValide: public ::testing::Test
{
public:
	JournalValide() :
			journal("etienne marcoux", "mon livre", 2019, "ISSN 0378-5955",
					"le nom", 1, 2, 3)
	{
	}
	;
	Journal journal;
};

/**
 * \test Test de la methode reqNom()
 * 		 Cas valide: verifier le retour du nom
 * 		 Cas invalide: aucun
 */
TEST_F(JournalValide, reqNom)
{
	ASSERT_EQ("le nom", journal.reqNom());
}

/**
 * \test Test de la methode reqVolume()
 * 		 Cas valide: verifier le retour du volume
 * 		 Cas invalide: aucun
 */
TEST_F(JournalValide, reqVolume)
{
	ASSERT_EQ(1, journal.reqVolume());
}

/**
 * \test Test de la methode reqNumero()
 * 		 Cas valide: verifier le retour du numero
 * 		 Cas invalide: aucun
 */
TEST_F(JournalValide, reqNumero)
{
	ASSERT_EQ(2, journal.reqNumero());
}

/**
 * \test Test de la methode reqPage()
 * 		 Cas valide: verifier le retour de la page
 * 		 Cas invalide: aucun
 */
TEST_F(JournalValide, reqPage)
{
	ASSERT_EQ(3, journal.reqPage());
}

/**
 * \test Test de la methode reqReferenceFormatee()
 * 		 Cas valide: verifier le retour des informations sur l'objet Journal formate
 * 		 Cas invalide: aucun
 */
TEST_F(JournalValide, reqReferenceFormatee)
{
	ASSERT_EQ(
			"etienne marcoux. mon livre. le nom, vol. 1, no. 2, pp. 3, 2019. ISSN 0378-5955.",
			journal.reqReferenceFormate());
}

/**
 * \test Test de la methode de clone de l'objet Journal
 * 		 Cas valide: verifier qu'un clone de l'objet Journal est cree et qu'il est identique a l'objet original et que l'adresse n'est pas la meme
 * 		 Cas invalide: aucun
 */
TEST_F(JournalValide, clone)
{
	Reference* cloneReference = journal.clone();
	Journal* cloneJournal = (Journal*) cloneReference;

	ASSERT_EQ((*cloneJournal).reqReferenceFormate(),
			journal.reqReferenceFormate());
	ASSERT_FALSE(cloneJournal == &journal);
}

