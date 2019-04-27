/**
 * \file Bibliographie.h
 * \brief Prototype de la classe bibliographie
 * \author Etienne Marcoux
 * \version 1.0
 * \date 2019-04-09
 */

#ifndef BIBLIOGRAPHIE_H_
#define BIBLIOGRAPHIE_H_

#include <string>
#include "Reference.h"
#include <vector>

namespace biblio
{
/**
 * \class Bibliographie
 * \brief Classe qui permet de faire la gestion des references
 */
class Bibliographie
{
public:

	Bibliographie(const std::string p_nom);
	~Bibliographie();

	const std::string& reqNom() const;
	void ajouterReference(const Reference& p_nouvelleReference);
	std::string reqBibliographieFormate();

private:
	std::string m_nom;
	std::vector<Reference*> m_vReferences;
	bool ReferenceEstDejaPresente(const std::string& p_identifiant) const;
	void verifieInvariant() const;
};
} /* namespace biblio */

#endif /* BIBLIOGRAPHIE_H_ */
