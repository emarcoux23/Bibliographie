/**
 * \file Ouvrage.cpp
 * \brief Classe Ouvrage
 * \author Etienne Marcoux
 * \version 1.0
 * \date 2019-04-09
 */

#include "Ouvrage.h"
#include "ContratException.h"
#include "validationFormat.h"
#include <string>
#include <sstream>

using namespace std;
using namespace util;

namespace biblio
{
/**
 * \brief Constructeur avec parametres.
 * 		  Creation d'un objet Ouvrage a partir de valeurs passees en parametres
 * \param[in] p_auteurs; le ou les auteurs de l'ouvrage
 * \param[in] p_titre; le titre de l'ouvrage
 * \param[in] p_annee; l'annee d'edition de l'ouvrage
 * \param[in] p_identifiant; l'identifiant de l'ouvrage (code ISBN)
 * \param[in] p_editeur; l'editeur de l'ouvrage
 * \param[in] p_ville; la ville d'edition de l'ouvrage
 * \pre p_identifiant respecte la fonction util::validerFormatIsbn()
 * \pre p_editeur respecte la fonction util::validerFormatNom()
 * \pre p_ville respecte la fonction util::validerFormatNom()
 * \post m_editeur prend la valeur de p_editeur
 * \post m_ville prend la valeur de p_ville
 */
Ouvrage::Ouvrage(std::string p_auteurs, std::string p_titre, int p_annee,
		std::string p_identifiant, std::string p_editeur, std::string p_ville) :
		Reference(p_auteurs, p_titre, p_annee, p_identifiant), m_editeur(
				p_editeur), m_ville(p_ville)
{
	PRECONDITION(validerCodeIsbn(p_identifiant));
	PRECONDITION(validerFormatNom(p_editeur));
	PRECONDITION(validerFormatNom(p_ville));

	POSTCONDITION(m_editeur == p_editeur);
	POSTCONDITION(m_ville == p_ville);

	INVARIANTS();
}

/**
 * \brief Accesseur editeur de l'ouvrage
 * \return L'editeur de l'ouvrage
 */
const std::string& Ouvrage::reqEditeur() const
{
	return m_editeur;
}

/**
 * \brief Accesseur ville d'edition de l'ouvrage
 * \return La ville d'edition de l'ouvrage
 */
const std::string& Ouvrage::reqVille() const
{
	return m_ville;
}

/**
 * \brief Methode retournant les informations de l'ouvrage de facon formate
 * \return String contenant les informations de l'ouvrage formatees
 */
std::string Ouvrage::reqReferenceFormate() const
{
	ostringstream os;
	os << Reference::reqReferenceFormate();
	os << ' ' << m_ville << " : " << m_editeur << ", " << reqAnnee() << ". "
			<< reqIdentifiant() << ".";
	return os.str();
}

/**
 * \brief Methode qui fait une copie allouee sur le monceau de l'objet Ouvrage courant
 * \return Copie de l'objet Ouvrage
 */
Reference* Ouvrage::clone() const
{
	return new Ouvrage(*this);
}

/**
 * \brief Verifier les invariants de la classe
 */
void Ouvrage::verifieInvariant() const
{
	INVARIANT(validerFormatNom(m_editeur));
	INVARIANT(validerFormatNom(m_ville));
	INVARIANT(validerCodeIsbn(Ouvrage::reqIdentifiant()));
}

} /* namespace biblio */
