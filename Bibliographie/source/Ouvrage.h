/**
 * \file Ouvrage.h
 * \brief Prototype de la classe Ouvrage
 * \author Etienne Marcoux
 * \version 1.0
 * \date 2019-04-09
 */

#ifndef OUVRAGE_H_
#define OUVRAGE_H_

#include <string>
#include "Reference.h"

namespace biblio
{
/**
 * \class Ouvrage
 * \brief Classe representant les references de la categorie ouvrage. Elle herite de reference
 */
class Ouvrage: public Reference
{
public:
	Ouvrage(std::string p_auteurs, std::string p_titre, int p_annee,
			std::string p_identifiant, std::string p_editeur,
			std::string p_ville);

	//Acesseurs
	const std::string& reqEditeur() const;
	const std::string& reqVille() const;

	//Autres
	std::string reqReferenceFormate() const;
	virtual Reference* clone() const;

private:
	std::string m_editeur;
	std::string m_ville;
	void verifieInvariant() const;
};
} /* namespace biblio */

#endif /* OUVRAGE_H_ */
