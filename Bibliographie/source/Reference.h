/**
 * \file Reference.h
 * \brief prototype de la classe Reference
 * \author Etienne Marcoux
 * \version 2.0
 * \date 2019-04-09
 */

#ifndef REFERENCE_H_
#define REFERENCE_H_

#include <string>

namespace biblio
{
/**
 * \class Reference
 * \brief Classe modelisant l'interface d'un objet reference
 */
class Reference
{
public:

	Reference(const std::string p_auteurs, const std::string p_titre,
			const int p_annee, const std::string p_identifiant);
	virtual ~Reference();

	//Acesseurs
	const std::string& reqAuteurs() const;
	const std::string& reqTitre() const;
	const int reqAnnee() const;
	const std::string& reqIdentifiant() const;

	//Mutateurs
	void asgAuteurs(const std::string& p_auteurs);

	//Autres
	virtual std::string reqReferenceFormate() const=0;
	bool operator==(const Reference& r) const;
	virtual Reference* clone() const=0;

private:
	std::string m_auteurs;
	std::string m_titre;
	int m_annee;
	std::string m_identifiant;

	void verifieInvariant() const;
};
} /* namespace biblio */

#endif /* REFERENCE_H_ */

