/**
* @file Compare.h
* @brief in this file are implmented the methods used to comapre the dirrent telocs read
* @author Salvatore Muoio
*/
#ifndef __COMPARE_H__
#define __COMPARE_H__
#include "Types.h"
#include "BuildTeloc.h"

/**
@def TABLE_MATCH_VALUE
@brief the table manages the difference of board in the checking
 */
#define TABLE_MATCH_VALUE {{"POSU","10"},\
	                       {"IOCO","10"},\
	                       {"CORE","10"},\
	                       {"DAIO","10"},\
	                       {"REBO","10"},\
	                       {"MVB","10"},\
	                       {"CPM","10"},\
	                       {"SRAM","10"},\
	                       {"SABOA","10"},\
	                       {"BAPLB","10"},\
	                       {"BAPLI","10"},\
						   {"FLASH","10"},\
      				       }\




namespace compare_
{
	// create a structure for the Compare module


}

/*!
* @fn type_::UINT64 plausibilitycheck_numberboard(buildteloc_::t_buildtelocstruct ptrbuildtelocstruc[][20], type_::UINT64 len, type_::UINT64 jj);
* @brief the function checks if the number of boards between two teloc under compare
* @param ptrbuildtelocstruc, bidimensional array used to store the BOM of Teloc
* @param len, kength of array
* @param jj number of Teloc
* @return number of boards
*/
type_::UINT64 plausibilitycheck_numberboard(buildteloc_::t_buildtelocstruct ptrbuildtelocstruc[][TELOC_BOARD], type_::UINT64 len, type_::UINT64 jj);

/*!
* @fn type_::UINT64 plausibilitycheck_boards(buildteloc_::t_buildtelocstruct ptrbuildtelocstruc[][20], type_::UINT64 len, type_::UINT64 jj);
* @brief the function checks withch boards match between the Teloc UUC and the other
* @param ptrbuildtelocstruc, bidimensional array used to store the BOM of Teloc
* @param len, kength of array
* @param jj number of Teloc
* @return value of not match
*/
type_::UINT64 plausibilitycheck_boards(buildteloc_::t_buildtelocstruct ptrbuildtelocstruc[][TELOC_BOARD], type_::UINT64 len, type_::UINT64 jj);


#endif
