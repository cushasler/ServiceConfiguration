/**
* @file buildTeloc
* @brief the file implements all methods use in config impl to build a teloc
* @author Salvatore Muoio
*/

#ifndef __BUILD_TELOC_H__
#define __BUILD_TELOC_H__
#include <iostream>
#include <fstream>
#include "Types.h"
#include "Util.h"
/**
 * @def TELOC_BOARD
 * @brief maximum boards of Teloc
 */
#define TELOC_BOARD 20

#define DATABASE_FAMILY_T1500_SIZE 38

#define DATABASE_FAMILY_T1500 {{"1.341", "POSU"},\
							   {"0.360", "POSU"},\
							   {"0.361", "POSU"},\
							   {"0.260", "POSU"},\
							   {"0.362", "POSU"},\
							   {"0.200", "CORE"},\
							   {"0.201", "CORE"},\
							   {"0.300", "CORE"},\
							   {"0.301", "CORE"},\
							   {"1.212", "DAIO"},\
							   {"0.312", "DAIO"},\
                               {"1.226", "REBO"},\
							   {"1.326", "REBO"},\
							   {"0.205", "IOCO"},\
							   {"0.206", "IOCO"},\
							   {"0.306", "IOCO"},\
							   {"5.200", "SABO"},\
							   {"5.201", "SABO"},\
							   {"1.347", "MVB"}, \
							   {"1.348", "MVB"}, \
							   {"0.315", "SRAM"},\
							   {"0.310", "FLASH"},\
							   {"0.320", "BACKPLANE"},\
							   {"0.321", "BACKPLANE"},\
							   {"0.322", "BACKPLANE"},\
							   {"0.323", "BACKPLANE"},\
							   {"0.324", "BACKPLANE"},\
							   {"0.365", "BACKPLANE"},\
							   {"0.366", "BACKPLANE"},\
							   {"0.367", "BACKPLANE"},\
							   {"0.548", "CPM"},\
							   {"1.137", "CPM"},\
							   {"1.053", "CPM"},\
							   {"1.159", "CPM"},\
							   {"1.160", "CPM"},\
							   {"0.566", "CPM"},\
							   {"0.138", "CPM"},\
							   {"0.548", "CPM"},\
	}\

#define POSITION_TO_WRITING_SIZE 11

#define POSITION_TO_WRITING {{"POSU", "3"},\
                             {"CORE", "4"},\
							 {"IOCO", "5"},\
							 {"DAIO", "6"},\
                             {"REBO", "7"},\
							 {"SABO", "8"},\
							 {"MVB", "9"}, \
							 {"CPM", "10"},\
							 {"SRAM", "11"},\
							 {"FLASH", "12"},\
							 {"BACKPLANE", "13"},\
							 }\

/**
 * @def DATABASE_BOARD_T1500
 * @brief database of Teloc 1500
 */
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
							  {"5.2420.310/05","FLASH"},\
							 }\

/**
 * @def DATABASE_BOARD_T2500
 * @brief database of Teloc 2500
 */
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
		std::string board_name;      /*!< name of board */
		type_::ebool active;         /*!< present or not */
		type_::UINT64 numberofboard; /*!< how many board */
	}t_buildtelocstruct;
	typedef struct
	{
		type_::UINT64 matchvalue;  /*!< value match */
		type_::UINT64 posu;
		type_::UINT64 core;
		type_::UINT64 ioco;
		type_::UINT64 daio;
		type_::UINT64 rebo;
		type_::UINT64 sabo;
		type_::UINT64 mvb;
		type_::UINT64 cpm;
		type_::UINT64 sram;
		type_::UINT64 flash;
		type_::UINT64 backplane;
	}t_teloc_config;
}//namespace

extern buildteloc_::t_buildtelocstruct buildtelocstruct[TELOC_BOARD][TELOC_BOARD];
//@}
/**
* \fn void lookuptableTeloc1500(const type_::CHAR * const s)
* \brief the function build the teloc 1500
* \param *s, pointer to be string read in xlsx file
* \return
*/
void lookuptableTeloc1500(const type_::CHAR * const s, type_::UINT64 index, std::ofstream &myfile);
/**
* \fn void lookuptableTeloc2500(const type_::CHAR * const s)
* \brief the function build the teloc 1500
* \param *s, pointer to be string read in xlsx file
* \return
*/
void lookuptableTeloc2500(const type_::CHAR * const s, type_::UINT64 index, std::ofstream &myfile);

type_::ebool lookuptablefamily(const std::string family, std::string &name);

type_::UINT64 lookuptableposition(const std::string name);



#endif
