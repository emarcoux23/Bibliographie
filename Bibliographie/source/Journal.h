/**
 * \file Journal.h
 * \brief Prototype de la classe journal
 * \author Etienne Marcoux
 * \version 1.0
 * \date 2019-04-09
 */

#ifndef JOURNAL_H_
#define JOURNAL_H_

#include <string>
#include "Reference.h"

namespace biblio
{
/**
 * \class Journal
 * \brief Classe representant les references de la categorie journal. Elle herite de Reference
 */
class Journal: public Reference
{
public:
	Journal(const std::string p_auteurs, const std::string p_titre,
			const int p_annee, const std::string p_identifiant,
			const std::string p_nom, const int p_volume, const int p_numero,
			int p_page);

	//Acesseurs
	const std::string& reqNom() const;
	const int reqVolume() const;
	const int reqNumero() const;
	const int reqPage() const;

	//Autres
	std::string reqReferenceFormate() const;
	virtual Reference* clone() const;

private:
	std::string m_nom;
	int m_volume;
	int m_numero;
	int m_page;
	void verifieInvariant() const;
};
} /* namespace biblio */

#endif /* JOURNAL_H_ */
