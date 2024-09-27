/**
* @file buildTeloc.cpp
* @brief the file implements all methods use in config impl to build a teloc
* @author Salvatore Muoio
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include "Debug.h"
#include"BuildTeloc.h"

#define MAX_BOARD_1500 17
#define MAX_BOARD_2500 8


ofstream myfile;


buildteloc_::t_buildtelocstruct buildtelocstruct[TELOC_BOARD][TELOC_BOARD];

static buildteloc_::t_buildtelocstruct *getaccesstelocbuild(void)
{
	static buildteloc_::t_buildtelocstruct buildtelocstruct;
	return(&buildtelocstruct);
}

static buildteloc_::t_teloc_config *gettelocconfig(void)
{
	static buildteloc_::t_teloc_config teloc_config;
	return(&teloc_config);
}


static type_::UINT64 lookuptable_board(std::string board_name)
{
	type_::UINT64 lret = -1U;
	static const std::string table_board[] = {"POSU", "IOCO", "CORE", "REBO", "MVB", "CPM","DAIO","SRAM","SABOA","BAPLB","BAPLI","BUPLB","MAINC","PC104","FLASH"};
	for(type_::UINT64 index = 0;index < TELOC_BOARD; index++)
	{
		if(table_board[index] == board_name)
		{
			lret = index;
			break;
		}
	}
	return(lret);
}

static void setboard(std::string board_name, buildteloc_::t_buildtelocstruct *ptr)
{
	if(util_::CheckArg((buildteloc_::t_buildtelocstruct*) ptr) == type_::RESULT_OK)
	{
	//	std::cout<<FUNCTION_NAME<<std::endl;
		ptr->board_name = board_name;
		ptr->active = type_::TRUE;
		ptr->numberofboard++;
	}
}

/**
* \fn void lookuptableTeloc1500(const type_::CHAR * const s, type_::UINT64 index, std::ofstream &myfile)
* \brief the function build the teloc 1500
* \param *s, pointer to be string read in xlsx file
* \return
*/
void lookuptableTeloc1500(const type_::CHAR * const s, type_::UINT64 index, std::ofstream &myfile)
{
	// configure the database
	static std::string table[MAX_BOARD_1500][MAX_BOARD_1500] = DATABASE_BOARD_T1500;
	if(util_::CheckArg((type_::CHAR*) s) == type_::RESULT_OK)
	{
		std::cout<<FUNCTION_NAME<<std::endl;
		type_::UINT64 ii = 0;
		for(ii = 0; ii < MAX_BOARD_1500; ii++)
		{
			if(table[ii][0] == s)
			{
				std::cout<<table[ii][0]<< " == ";
				std::cout<<table[ii][1]<<std::endl;
				myfile <<"the "<<table[ii][1]<<" "<<table[ii][0]<<" is present"<<endl;
				setboard(
				(table[ii][1]),
				&buildtelocstruct[index][lookuptable_board(table[ii][1])]
				);
				DEBUG_ENABLE(debug_::enable)
				{
					std::cout<<"name == ";
					std::cout<<buildtelocstruct[index][lookuptable_board(table[ii][1])].board_name<<std::endl;
					std::cout<<"active == ";
					std::cout<<buildtelocstruct[index][lookuptable_board(table[ii][1])].active<<std::endl;
				}
				break;
				// set
			}//if
		}//for
	}
}
/**
* \fn void lookuptableTeloc2500(const type_::CHAR * const s, type_::UINT64 index, std::ofstream &myfile)
* \brief the function build the teloc 2500
* \param *s, pointer to be string read in xlsx file
* \return
*/
void lookuptableTeloc2500(const type_::CHAR * const s, type_::UINT64 index, std::ofstream &myfile)
{
	static std::string table[MAX_BOARD_2500][MAX_BOARD_2500] = DATABASE_BOARD_T2500;
	if(util_::CheckArg((type_::CHAR*) s) == type_::RESULT_OK)
	{
/*	std::string ss = s;
	std::cout<<ss<<endl;
	ss = ss.substr(0,10);
	std::cout<<ss<<endl;
	the engine could read the string without the version!!!!
*/
		//std::cout<<FUNCTION_NAME<<std::endl;
		for(int ii = 0; ii < MAX_BOARD_2500; ii++)
		{
			if(table[ii][0] == s)
			{
				std::cout<<table[ii][0]<< " == ";
				std::cout<<table[ii][1]<<std::endl;
				myfile <<"the "<<table[ii][1]<<" "<<table[ii][0]<<" is present"<<endl;
				setboard(
				(table[ii][1]),
				&buildtelocstruct[index][lookuptable_board(table[ii][1])]
				);
				DEBUG_ENABLE(debug_::enable)
				{
					std::cout<<"name == ";
					std::cout<<buildtelocstruct[index][lookuptable_board(table[ii][1])].board_name<<std::endl;
					std::cout<<"active == ";
					std::cout<<buildtelocstruct[index][lookuptable_board(table[ii][1])].active<<std::endl;
				}
				break;
				// set
			}//if
		}//for
	}
}
//!!!!

type_::ebool lookuptablefamily(const std::string family, std::string &name)
{
	static std::string table[DATABASE_FAMILY_TX500_SIZE][DATABASE_FAMILY_TX500_SIZE] = DATABASE_FAMILY_TX500;
	type_::ebool lfind = type_::FALSE;
	for(int jj = 0; jj < DATABASE_FAMILY_TX500_SIZE; jj++)
	{
		//std::cout<<"Table = "<<table[jj][0]<<std::endl;
		//std::cout<<"family = "<<family<<std::endl;
		if(table[jj][0] == family)
		{
			lfind = type_::TRUE;
			name = table[jj][1];
			//std::cout<getline(osheet, line);<"name = "<<name<<std::endl;
			break;
		}//if
	}//for
	//std::cout<<"lfind = "<<lfind<<std::endl;
	return(lfind);
}

type_::UINT64 lookuptableposition(const std::string name)
{
	static std::string table[POSITION_TO_WRITING_SIZE][POSITION_TO_WRITING_SIZE] = POSITION_TO_WRITING;
	type_::UINT64 lpos = 0x0U;
	for(type_::UINT64 jj = 0; jj < POSITION_TO_WRITING_SIZE; jj++)
	{
		if(table[jj][0] == name)
		{
			lpos = atoi(table[jj][1].c_str());
			break;
		}
	}
	return(lpos);
}

