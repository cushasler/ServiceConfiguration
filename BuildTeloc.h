/**
* @file buildTeloc
* @brief the file implments all methods use in config impl to build a teloc
* @author Salvatore Muoio
*/

#ifndef __BUILD_TELOC_H__
#define __BUILD_TELOC_H__
#include <iostream>
#include <fstream>
#include "Util.h"

#define DATABASE_BOARD_T1500 {{"5.2420.360/01","POSU"},\
	                          {"5.2420.361/01","POSU"},\
	                          {"5.2420.205/07","IOCO"},\
	                    	  {"5.2420.206/02","IOCO"},\
	                    	  {"5.2420.201/02","CORE"},\
	                    	  {"5.2621.212/02","DAIO"},\
	                    	  {"5.2621.212/05","DAIO"},\
	                    	  {"5.2621.212/12","DAIO"},\
	                    	  {"5.2621.226/08","REBO"},\
	                    	  {"5.2621.347/02","MVB"},\
	                    	  {"5.2621.347/05","MVB"},\
	                    	  {"5.2621.052/64","CPM" },\
	                    	  {"5.2420.315/04","SRAM"},\
	                    	  {"5.5005.200/01","SABOA"},\
	                    	  {"5.2420.320/01","BAPLB"},\
	                    	  {"5.2420.367/01","BAPLI"},\
							 }\


#define DATABASE_BOARD_T2500 {{"5.2420.361/01", "POSU"},\
                              {"5.2621.212/02", "DAIO"},\
                              {"5.2621.202/03", "MAINC"},\
                              {"5.2621.306/01" ,"BUPLB"},\
                              {"5.2621.226/08", "REBO" },\
                              {"5.5005.200/03", "SABOA"},\
                              {"5.2621.335/01", "PC104"},\
                              {"5.2621.050/32", "CPM" },\
                              }\

// namespace::buildteloc_
///@{
namespace buildteloc_
{
	/**
	* \struct t_buildtelocstruct
 	* \brief generic parameter for a Teloc board
    */
	typedef struct
	{
		std::string board_name; /*!< name of board */
		type_::ebool active;    /*!< present or not */
	}t_buildtelocstruct;
}
//@}
/**
* \fn void lookuptableTeloc1500(const type_::CHAR * const s)
* \brief the function build the teloc 1500
* \param *s, pointer to be string read in xlsx file
* \return 
*/
void lookuptableTeloc1500(const type_::CHAR * const s, std::ofstream &myfile);
/**
* \fn void lookuptableTeloc2500(const type_::CHAR * const s)
* \brief the function build the teloc 1500
* \param *s, pointer to be string read in xlsx file
* \return 
*/
void lookuptableTeloc2500(const type_::CHAR * const s, std::ofstream &myfile);

#endif
