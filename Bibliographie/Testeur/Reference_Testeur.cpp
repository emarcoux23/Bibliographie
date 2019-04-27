/**

 * \file Reference_Testeur.cpp
 * \brief Tests unitaires de la classe Reference
 * \author Etienne Marcoux
 * \version 1.0
 * \date 2019-04-09
 */

#include "Reference.h"
#include "ContratException.h"
#include <gtest/gtest.h>
#include <string>

using namespace std;
using namespace biblio;

/**
 * \class TestReference
 * \brief classe de test permettant de tester la classe abstraite Reference
 */
class TestReference: public Reference
{
public:
	TestReference(const string p_auteurs, const string p_titre,
			const int p_annee, const string p_identifiant) :
			Reference(p_auteurs, p_titre, p_annee, p_identifiant)
	{
	}
	virtual string reqReferenceFormate() const
	{
		return Reference::reqReferenceFormate();
	}
	;

	virtual ~TestReference()
	{
	}
	;
	virtual Reference* clone() const
	{
		return new TestReference(*this);
	}
	;

};

/**
 * \brief Test du constructeur
 *  	  Cas valides: Creation d'un objet reference et verification de l'assignation de tous les attributs
 *  	  Cas invalides:
 *  	  		auteurs == "   "
 *  	  		titre == ""
 *  	  		annee <= 0
 */
TEST(TestReference, ConstructeurValide)
{
	TestReference uneReference("etienne marcoux", "mon livre", 2019,
			"ISBN 0-13-235088-2");
	ASSERT_EQ("etienne marcoux", uneReference.reqAuteurs());
	ASSERT_EQ("mon livre", uneReference.reqTitre());
	ASSERT_EQ(2019, uneReference.reqAnnee());
	ASSERT_EQ("ISBN 0-13-235088-2", uneReference.reqIdentifiant());
}

//cas invalides
TEST(TestReference, ConstructeurInvalideAuteurs)
{
	ASSERT_THROW(
			TestReference uneReference("etienne marcoux2", "mon livre", 2019, "ISBN 0-13-235088-2"),
			PreconditionException);
}
TEST(TestReference, ConstructeurInvalideTitre)
{
	ASSERT_THROW(
			TestReference uneReference("etienne marcoux", "", 2019, "ISBN 0-13-235088-2"),
			PreconditionException);
}
TEST(TestReference, ConstructeurInvalideAnnee)
{
	ASSERT_THROW(
			TestReference uneReference("etienne marcoux", "mon livre", 0, "ISBN 0-13-235088-2"),
			PreconditionException);
}

/**
 * \brief Creation d'une fixture a utiliser pour les methodes public de la classe test
 */
class ReferenceValide: public ::testing::Test
{
public:
	ReferenceValide() :
			reference("etienne marcoux", "mon livre", 2019,
					"ISBN 0-13-235088-2"), autreReference("etienne marcoux",
					"mon livre", 2019, "ISBN 0-13-235088-X")
	{
	}
	;
	TestReference reference;
	TestReference autreReference;
};

/**
 * \test Test de la methode reqAuteurs()
 * 		 Cas valide: verifier le retour des auteurs
 * 		 Cas invalide: aucun
 */
TEST_F(ReferenceValide, reqAuteurs)
{
	ASSERT_EQ("etienne marcoux", reference.reqAuteurs());
}

/**
 * \test Test de la methode reqTitre()
 * 		 Cas valide: verifier le retour du titre
 * 		 Cas invalide: aucun
 */
TEST_F(ReferenceValide, reqTitre)
{
	ASSERT_EQ("mon livre", reference.reqTitre());
}

/**
 * \test Test de la methode reqAnnee()
 * 		 Cas valide: verifier le retour de l'annee
 * 		 Cas invalide: aucun
 */
TEST_F(ReferenceValide, reqAnnee)
{
	ASSERT_EQ(2019, reference.reqAnnee());
}

/**
 * \test Test de la methode reqIdentifiant()
 * 		 Cas valide: verifier le retour de l'identifiant
 * 		 Cas invalide: aucun
 */
TEST_F(ReferenceValide, reqIdentifiant)
{
	ASSERT_EQ("ISBN 0-13-235088-2", reference.reqIdentifiant());
}

/**
 * \test Test de la methode reqReferenceFormatee()
 * 		 Cas valide: verifier le retour des informations sur l'objet Reference formate
 * 		 Cas invalide: aucun
 */
TEST_F(ReferenceValide, reqReferenceFormatee)
{
	ASSERT_EQ("etienne marcoux. mon livre.", reference.reqReferenceFormate());
}

/**
 * \test Test de la methode asgAuteurs()
 * 		 Cas valide: ajuste les auteurs de la reference
 * 		 Cas invalide: ajuste les auteurs par une valeur invalide
 */
TEST_F(ReferenceValide, ajusterAuteursValide)
{
	reference.asgAuteurs("marcoux etienne");
	ASSERT_EQ("marcoux etienne", reference.reqAuteurs());
}
//cas invalide
TEST_F(ReferenceValide, ajusterAuteursInvalide)
{
	ASSERT_THROW(reference.asgAuteurs("etienne marcoux2"),
			PreconditionException);
}

/**
 * \test Test du surchargeur d'operateur ==
 * 		 Cas valide: verifier l'egalite entre 2 objets Reference identiques
 * 		 Cas invalide: verifier l'inegalite entre 2 objet Reference different
 */
TEST_F(ReferenceValide, operateur_degalite_valide)
{
	ASSERT_TRUE(reference == reference);
}
//cas invalides
TEST_F(ReferenceValide, operateur_degalite_invalide)
{
	ASSERT_FALSE(reference == autreReference);
}

