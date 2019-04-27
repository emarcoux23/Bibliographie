/**
 * \file validationFormat.h
 * \brief Protoype des fonctions de verification
 * \author Etienne Marcoux
 * \version 2.0
 * \date 2019-02-27
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_
#include <string>

namespace util
{
bool validerFormatNom(const std::string& p_nom);
bool validerCodeIssn(const std::string& p_issn);
bool validerCodeIsbn(const std::string& p_isbn);
} /*namespace util*/

#endif /* VALIDATIONFORMAT_H_ */
