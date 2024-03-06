/**
* @file Util.h
* @brief In this file are implemented all methods util
* @author Salvatore Muoio
*/
#ifndef __UTIL_H__
#define __UTIL_H__
#include "Types.h"
// namespace::util_
///@{
namespace util_
{
	type_::ebool charpointer_compare(const type_::CHAR *a, const type_::CHAR *b);
	/**
    * \fn e_result CheckArg(void *pArg)
    * \brief the function checks if the pointer is addressed
    * \param *pArg, pointer to be checked
    * \return status of check
    */
	type_::e_result CheckArg(void *pArg);
	type_::UINT64 ConverTelocCode2Num(std::string teloccode);

}
//@}

#endif
