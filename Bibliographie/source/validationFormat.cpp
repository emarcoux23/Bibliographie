/**
 * \file validationFormat.cpp
 * \brief fonctions de verification
 * \author Etienne Marcoux
 * \version 2.0
 * \date 2019-02-27
 */

#include "validationFormat.h"
#include <string>
#include <iostream>

using namespace std;

namespace util
{

/**
 *
 * @param p_nom
 * @return boolean, true si c'est un nom, false si ce n'est pas un nom
 */
bool validerFormatNom(const std::string& p_nom)
{
	for (unsigned int i = 0; i < p_nom.length(); i++)
	{
		if (!isalpha(p_nom[i]) && !isspace(p_nom[i])) // verifie que chaque caractere est soit une lettre, soit un espace
		{
			return false;
		}
	}
	return true;
}

/**
 * @param p_issn
 * @return boolean, true si c'est un code issn valide, false sinon
 */
bool validerCodeIssn(const std::string& p_issn)
{

//verifie les conditions de base de l'ISSN

	if (p_issn.length() != 14)
	{
		return false;
	}
	if (p_issn[0] != 'I' || p_issn[1] != 'S' || p_issn[2] != 'S'
			|| p_issn[3] != 'N')
	{
		return false;
	}

//verifie la clef du code

	string chaineNombres = "";
	for (int i = 0; i < 13; i++)
	{
		if (isdigit(p_issn[i]))
		{
			chaineNombres += p_issn[i];
		}
	}
	int somme = 0;
	for (int i = 0; i < 7; i++)
	{
		somme += ((chaineNombres[i] - 48) * (8 - i));
	}
	int clef = 11 - (somme % 11);

	if (p_issn[13] != 'X')
	{
		if (p_issn[13] != clef + 48)
		{
			return false;
		}
	}
	if (p_issn[13] == 'X')
	{
		if (p_issn[13] != 10)
		{
			return false;
		}
	}

	return true;
}

/**
 * @param p_isbn
 * @return boolean, true si c'est un code isbn valide, false sinon
 */
bool validerCodeIsbn(const std::string& p_isbn)
{

//verifie les conditions de base de l'ISBN

	if (p_isbn.length() != 18 && p_isbn.length() != 22)
	{
		return false;
	}
	if (p_isbn[0] != 'I' || p_isbn[1] != 'S' || p_isbn[2] != 'B'
			|| p_isbn[3] != 'N')
	{
		return false;
	}

// verifie la clef du code

// si c'est un code ISBN-10

	if (p_isbn.length() == 18)
	{
		string chaineNombres1 = "";
		for (int i = 0; i < 16; i++)
		{
			if (isdigit(p_isbn[i]))
			{
				chaineNombres1 += p_isbn[i];
			}
		}
		int somme1 = 0;
		for (int i = 0; i < 9; i++)
		{
			somme1 += (chaineNombres1[i] - 48) * (10 - i);
		}
		int clef1 = 11 - (somme1 % 11);
		if (p_isbn[17] != 'X')
		{
			if (p_isbn[17] != clef1 + 48)
			{
				return false;
			}
		}
		if (p_isbn[17] == 'X')
		{
			if (clef1 != 10)
			{
				return false;
			}
		}
	}

// si c'est un code ISBN-13

	if (p_isbn.length() == 22)
	{
		if (p_isbn[8] != '-')
		{
			return false;
		}
		string chaineNombres2 = "";
		for (int i = 0; i < 20; i++)
		{
			if (isdigit(p_isbn[i]))
			{
				chaineNombres2 += p_isbn[i];
			}
		}
		int somme2 = 0;
		for (int i = 0; i < 12; i++)
		{
			if (i % 2 == 0)
			{
				somme2 += (chaineNombres2[i] - 48) * 1;
			}
			if (i % 2 == 1)
			{
				somme2 += (chaineNombres2[i] - 48) * 3;
			}
		}
		int clef2 = 10 - (somme2 % 10);
		if (p_isbn[21] != 'X')
		{
			if (p_isbn[21] != clef2 + 48)
			{
				return false;
			}
		}
		if (p_isbn[21] == 'X')
		{
			if (clef2 != 10)
			{
				return false;
			}
		}
	}

	return true;
}

} /*namespace util*/
