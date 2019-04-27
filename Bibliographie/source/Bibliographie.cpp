/**
 * \file Bibliographie.cpp
 * \brief Classe bibliographie
 * \author Etienne Marcoux
 * \version 1.0
 * \date 2019-04-09
 */

#include "Bibliographie.h"
#include "ContratException.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
namespace biblio
{

/**
 * \brief Constructeur avec parametres.
 * 		  Creation dun objet Bibliographie a partir de son attribut
 * \param[in] p_nom; le nom de la bibliographie
 * \pre p_nom est non vide
 * \pre p_nom n'est pas un espace
 * \post m_nom prend la valeur de p_nom
 */
Bibliographie::Bibliographie(string p_nom) :
		m_nom(p_nom)
{
	PRECONDITION(!m_nom.empty());
	PRECONDITION(m_nom != " ");
	POSTCONDITION(m_nom == p_nom);
	INVARIANTS();
}

/**
 * \brief destructeur de l'objet bibliographie, delete de toutes les references dans le vecteur
 */
Bibliographie::~Bibliographie()
{
	for (unsigned int i = 0; i < m_vReferences.size(); i++)
	{
		delete m_vReferences[i];
	}
	m_vReferences.clear();
}

/**
 * \brief Accesseur du nom de la bibliographie
 * \return le nom de la bibliographie
 */
const string& Bibliographie::reqNom() const
{
	return m_nom;
}

/**
 * \brief methode qui ajoute un objet reference a la fin du vecteur, seulement si le vecteur n'existe pas deja
 */
void Bibliographie::ajouterReference(const Reference& p_nouvelleReference)
{
	if (!ReferenceEstDejaPresente(p_nouvelleReference.reqIdentifiant()))
	{
		m_vReferences.push_back(p_nouvelleReference.clone());
	}

}

/**
 * \brief Methode retournant les informations de la bibliographie de facon formate
 * \return String contenant les informations de la bibliographie formatees
 */

string Bibliographie::reqBibliographieFormate()
{
	ostringstream os;
	for (unsigned int i = 0; i < m_vReferences.size(); i++)
	{
		os << "[" << i + 1 << "] " << m_vReferences[i]->reqReferenceFormate()
				<< endl;
	}
	return os.str();
}

/**
 * \brief Methode retournant un boolean dependament si la reference existe deja ou non
 * \return true si la reference existe deja, false si la reference n'existe pas encore
 */
bool Bibliographie::ReferenceEstDejaPresente(
		const std::string& p_identifiant) const
{
	bool dejaPresente = false;
	for (unsigned int i = 0; i < m_vReferences.size(); i++)
	{
		if (m_vReferences[i]->reqIdentifiant() == p_identifiant)
		{
			dejaPresente = true;
		}
	}
	return dejaPresente;
}

/**
 * \brief Verifier les invariants de la classe
 */
void Bibliographie::verifieInvariant() const
{
	INVARIANT(!m_nom.empty());
	INVARIANT(m_nom != " ");
}
} /*namespace biblio*/

