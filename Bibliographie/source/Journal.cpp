/**
 * \file Journal.cpp
 * \brief Classe Journal
 * \author Etienne Marcoux
 * \version 1.0
 * \date 2019-04-09
 */

#include "Journal.h"
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
 * 		  Creation dun objet Journal a partir de valeurs passees en parametres
 * \param[in] p_auteurs; le ou les auteurs du journal
 * \param[in] p_titre; le titre du journal
 * \param[in] p_annee; l'annee d'edition du journal
 * \param[in] p_identifiant; l'identifiant du journal (code ISSN)
 * \param[in] p_nom; le nom du journal
 * \param[in] p_volume; un chiffre representant le volume du journal
 * \param[in] p_numero; un chiffre representant le numero du journal
 * \param[in] p_page; un chiffre representant la page du journal
 * \pre p_identifiant respecte la fonction util::validerFormatIssn()
 * \pre m_nom respecte la fonction util::validerFormatNom()
 * \post m_nom prend la valeur de p_nom
 * \post m_volume prend la valeur de p_volume
 * \post m_numero prend la valeur de p_numero
 * \post m_page prend la valeur de p_page
 */
Journal::Journal(std::string p_auteurs, std::string p_titre, int p_annee,
		std::string p_identifiant, std::string p_nom, int p_volume,
		int p_numero, int p_page) :
		Reference(p_auteurs, p_titre, p_annee, p_identifiant), m_nom(p_nom), m_volume(
				p_volume), m_numero(p_numero), m_page(p_page)
{
	PRECONDITION(validerCodeIssn(p_identifiant));
	PRECONDITION(validerFormatNom(m_nom));

	POSTCONDITION(m_nom == p_nom);
	POSTCONDITION(m_volume == p_volume);
	POSTCONDITION(m_numero == p_numero);
	POSTCONDITION(m_page == p_page);

	INVARIANTS();
}

/**
 * \brief Accesseur nom du journal
 * \return Le nom du journal
 */
const std::string& Journal::reqNom() const
{
	return m_nom;
}

/**
 * \brief Accesseur volume du journal
 * \return Le volume du journal
 */
const int Journal::reqVolume() const
{
	return m_volume;
}

/**
 * \brief Accesseur numero du journal
 * \return Numero du journal
 */
const int Journal::reqNumero() const
{
	return m_numero;
}

/**
 * \brief Accesseur page du journal
 * \return La page du journal
 */
const int Journal::reqPage() const
{
	return m_page;
}

/**
 * \brief Methode retournant les informations du journal de facon formate
 * \return String contenant les informations du journal formatees
 */
std::string Journal::reqReferenceFormate() const
{
	ostringstream os;
	os << Reference::reqReferenceFormate();
	os << " " << m_nom << ", vol. " << m_volume << ", no. " << m_numero
			<< ", pp. " << m_page << ", " << reqAnnee() << ". "
			<< reqIdentifiant() << ".";
	return os.str();
}

/**
 * \brief Methode qui fait une copie allouee sur le monceau de l'objet Journal courant
 * \return Copie de l'objet Journal
 */
Reference* Journal::clone() const
{
	return new Journal(*this);
}

/**
 * \brief Verifier les invariants de la classe
 */
void Journal::verifieInvariant() const
{
	INVARIANT(!m_nom.empty());
	INVARIANT(validerCodeIssn(Journal::reqIdentifiant()));
}

}/* namespace biblio */

