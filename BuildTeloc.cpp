/**
* @file buildTeloc.cpp
* @brief the file implments all methods use in config impl to build a teloc
* @author Salvatore Muoio
*/

#include "Debug.h"
#include"BuildTeloc.h"

#define MAX_BOARD 16
#define TELOC_BOARD 11

ofstream myfile;


static buildteloc_::t_buildtelocstruct buildtelocstruct[14];

static buildteloc_::t_buildtelocstruct *getaccesstelocbuild(void)
{
	static buildteloc_::t_buildtelocstruct buildtelocstruct;
	return(&buildtelocstruct);
}

static type_::UINT64 lookuptable_board(std::string board_name)
{
	type_::UINT64 lret = -1U;
	static const std::string table_board[] = {"POSU", "IOCO", "CORE", "REBO", "MVB", "CPM","DAIO","SRAM","SABOA","BAPLB","BAPLI"};
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
	}
}


void lookuptableTeloc1500(const type_::CHAR * const s, std::ofstream &myfile)
{
	// configure the database
	static std::string table[MAX_BOARD][MAX_BOARD] = DATABASE_BOARD_T1500;
	if(util_::CheckArg((type_::CHAR*) s) == type_::RESULT_OK)
	{
		//std::cout<<FUNCTION_NAME<<std::endl;	
		for(int ii = 0; ii < MAX_BOARD; ii++)
		{
			if(table[ii][0] == s)
			{
				std::cout<<table[ii][0]<< " == ";
				std::cout<<table[ii][1]<<std::endl;
				myfile <<"the "<<table[ii][1]<<" "<<table[ii][0]<<" is present"<<endl; 
				setboard(
				(table[ii][1]), 
				&buildtelocstruct[lookuptable_board(table[ii][1])]
				);
				DEBUG_ENABLE(debug_::enable)
				{
					std::cout<<"name == ";
					std::cout<<buildtelocstruct[lookuptable_board(table[ii][1])].board_name<<std::endl;
					std::cout<<"active == ";
					std::cout<<buildtelocstruct[lookuptable_board(table[ii][1])].active<<std::endl;
				}
				break;
				// set
			}//if
		}
	}
}

void lookuptableTeloc2500(const type_::CHAR * const s, std::ofstream &myfile)
{
	static std::string table[MAX_BOARD][MAX_BOARD] = DATABASE_BOARD_T1500;
	if(util_::CheckArg((type_::CHAR*) s) == type_::RESULT_OK)
	{
		
	}
}
