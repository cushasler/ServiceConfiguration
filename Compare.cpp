/**
* @file Compare.cpp
* @brief in this file are implmented the methods used to comapre the dirrent telocs read
* @author Salvatore Muoio
*/
#include <iostream>
#include <string>
#include "Debug.h"
#include "Util.h"
#include "Compare.h"


#define TABEL_SIZE 12


/**
 * @fn type_::ebool isTelocUUC(type_::UINT64 index)
 * @brief the function check if the teloc is different from the UUT
 * @param index
 * @return true or false
 */
static type_::ebool isTelocUUC(type_::UINT64 index)
{
	return((index == 0) ? type_::TRUE : type_::FALSE);
}

/**
 * @fn type_::ebool isendloop(type_::UINT64 index, type_::UINT64 len)
 * @brief the function check the status of loop
 * @param index
 * @param len
 * @return
 */
static type_::ebool isendloop(type_::UINT64 index, type_::UINT64 len)
{
	return((index >= len-1) ? type_::TRUE : type_::FALSE);
}

static type_::UINT64  lookuptablevaluemacth(const std::string board)
{
	type_::UINT64 lvalue = 0x0U;
	static std::string table[TABEL_SIZE][TABEL_SIZE] = TABLE_MATCH_VALUE;
	for(type_::UINT64 ii = 0; ii <TABEL_SIZE;  ii++)
	{
		if(table[ii][0] == board)
		{
			lvalue = stoi(table[ii][1]);
			break;
		}//if
	}//for
	return(lvalue);
}

static type_::UINT64 match(std::string board)
{
	type_::UINT64 lmatch = 0x0U;
	lmatch = lookuptablevaluemacth(board);
	return(lmatch);
}

type_::UINT64 plausibilitycheck_numberboard(buildteloc_::t_buildtelocstruct ptrbuildtelocstruc[][TELOC_BOARD], type_::UINT64 len, type_::UINT64 jj)
{
	type_::UINT64 lCnt = 0;
//	if(util_::CheckArg((buildteloc_::t_buildtelocstruct*) ptrbuildtelocstruc) == type_::RESULT_OK)
	{
		std::cout<<std::endl;
		for(type_::UINT64 ii = 0; ii< len; ii++){

		//while(!ptrbuildtelocstruc){
			if(ptrbuildtelocstruc[jj][ii].active == type_::TRUE)
			{
				if(debug_::enable)
				{
					std::cout<<lCnt<<" board active = "<<ptrbuildtelocstruc[jj][ii].active<<std::endl;
					std::cout<<lCnt<<" board name = "<<ptrbuildtelocstruc[jj][ii].board_name<<std::endl;
					std::cout<<lCnt<<" number of board = "<<ptrbuildtelocstruc[jj][ii].numberofboard<<std::endl;
				}
				lCnt = lCnt + ptrbuildtelocstruc[jj][ii].numberofboard;
			}//if
		}//for
		//}//while
		std::cout<<"Teloc["<<jj<<"] under check:: number of boards = "<<lCnt<<std::endl;
	}//body
	return(lCnt);
}


type_::UINT64 plausibilitycheck_boards(buildteloc_::t_buildtelocstruct ptrbuildtelocstruc[][TELOC_BOARD], type_::UINT64 len, type_::UINT64 jj)
{
	type_::ebool lMatch = type_::TRUE;
	type_::UINT64 valuematch = 0x64U;
	if(isTelocUUC(jj) == type_::FALSE)
	{
		std::cout<<"plausibiity check boards"<<std::endl;
		for(type_::UINT64 ii = 0; ii < len; ii++)
			for(type_::UINT64 tt = 0; tt < len; tt++)
			{
				if(ptrbuildtelocstruc[jj][ii].active == type_::TRUE)
				{
					if(ptrbuildtelocstruc[jj][ii].board_name == ptrbuildtelocstruc[0][tt].board_name)
					{
						std::cout<< "Board match == "<<ptrbuildtelocstruc[jj][ii].board_name<<std::endl;
						break;
					}//if
					else if(isendloop(tt, len) == type_::TRUE)
					{
						std::cout<< "Board not matched == "<<ptrbuildtelocstruc[jj][ii].board_name<<std::endl;
						lMatch = type_::FALSE;
						std::cout<<"match =="<<match(ptrbuildtelocstruc[jj][ii].board_name)<<std::endl;
						valuematch -= match(ptrbuildtelocstruc[jj][ii].board_name);
						std::cout<<"valuematch =="<<valuematch<<std::endl;
					}//Elseif
				}//if
			}//for
	}//if
	return(valuematch);
}


