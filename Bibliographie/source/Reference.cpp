/**
 * \file Reference.cpp
 * \brief Classe Reference
 * \author Etienne Marcoux
 * \version 2.0
 * \date 2019-04-09
 */

#include "Reference.h"
#include "validationFormat.h"
#include "ContratException.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace util;
using namespace std;
namespace biblio
{

/**
 * \brief Constructeur avec parametres.
 * 		  Creation d'un objet Reference a partir de valeurs passees en parametres
 * \param[in] p_auteurs; le ou les auteurs de la reference bibliographique
 * \param[in] p_titre; le titre de la reference bibliographique
 * \param[in] p_annee; l'annee d'edition de la reference bibliographique
 * \param[in] p_identifiant; l'identifiant de la reference bibliographique (code ISSN ou code ISBN).
 * \pre p_auteur respecte la fonction util::validerFormatNom()
 * \pre p_titre non vide
 * \pre P_annee strictement superieur a 0
 * \post m_auteurs prend la valeur de p_auteurs
 * \post m_titre prend la valeur de p_titre
 * \post m_annee prend la valeur de p_annee
 * \post m_identifiant prend la valeur de p_identifiant
 */
Reference::Reference(string p_auteurs, string p_titre, int p_annee,
		string p_identifiant) :
		m_auteurs(p_auteurs), m_titre(p_titre), m_annee(p_annee), m_identifiant(
				p_identifiant)
{
	PRECONDITION(validerFormatNom(p_auteurs));
	PRECONDITION(!p_titre.empty());
	PRECONDITION(p_annee > 0);

	POSTCONDITION(m_auteurs == p_auteurs);
	POSTCONDITION(m_titre == p_titre);
	POSTCONDITION(m_annee == p_annee);
	POSTCONDITION(m_identifiant == p_identifiant);

	INVARIANTS();
}

/**
 * \brief destructeur de l'objet reference
 */
Reference::~Reference()
{
}

/**
 * \brief Accesseur l'auteur ou les auteurs
 * \return L'auteur ou les auteurs
 */
const string& Reference::reqAuteurs() const
{
	return m_auteurs;
}

/**
 * \brief Accesseur titre de la reference
 * \return Le titre de la reference
 */
const string& Reference::reqTitre() const
{
	return m_titre;
}

/**
 * \brief Accesseur annee d'edition
 * \return L'annee d'edition
 */
const int Reference::reqAnnee() const
{
	return m_annee;
}

/**
 * \brief Accesseur identifiant de la reference
 * \return L'identifiant de la reference
 */
const string& Reference::reqIdentifiant() const
{
	return m_identifiant;
}

/**
 * \brief Mutateur de l'auteur(s) de la reference avec le nouveau auteur(s) recu en parametre
 * \param p_auteurs; le ou les auteurs contenant le ou les auteurs de la reference bibliographique.
 */
void Reference::asgAuteurs(const string& p_auteurs)
{
	PRECONDITION(util::validerFormatNom(p_auteurs));
	m_auteurs = p_auteurs;
	POSTCONDITION(p_auteurs == m_auteurs);
	INVARIANTS();
}

/**
 * \brief Methode retournant les informations de la reference de facon formate
 * \return String contenant les informations de la reference formatees
 */
string Reference::reqReferenceFormate() const
{
	ostringstream os;
	os << m_auteurs << ". " << m_titre << ".";
	return os.str();
}

/**
 * \brief Surchargeur de l'operateur == pour comparer des objets de la classe Reference entre eux.
 * \param r; un objet Reference
 * \return booleen
 */
bool Reference::operator==(const Reference& r) const
{
	return this->m_auteurs == r.reqAuteurs() && this->m_annee == r.reqAnnee()
			&& this->m_titre == r.reqTitre()
			&& this->m_identifiant == r.reqIdentifiant();
}

/**
 * \brief Verifier les invariants de la classe
 */
void Reference::verifieInvariant() const
{
	INVARIANT(validerFormatNom(m_auteurs));
	INVARIANT(!m_titre.empty());
	INVARIANT(m_annee > 0);
}

} /* namespace biblio */
