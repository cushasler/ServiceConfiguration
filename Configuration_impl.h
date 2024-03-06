/**
* @file Configuration_impl.h
* @brief in this file are implemented the methods private in the pimpl
* @author Salvatore Muoio
*/

#ifndef __CONFIGURATION_IMPL_H__
#define __CONFIGURATION_IMPL_H__

#include <fstream>
#include <vector>
#include "libxl.h"
#include "Configuration.h"
#include "Types.h"

using namespace libxl;

#define FAMILY_TELOC_1500 {"POSU", "CORE", "IOCO", "DAIO", "REBO", "SABO", "MVB", "CPM", "SRAM", "FLASH", "BACKPLANE"};

/**
* @namespace configimpl_
* @brief the namespace used from the pimpl
*/
namespace configimpl_
{
	typedef struct
    {
        type_::UINT64 findcolumn; /*!< column to scroll in exel file */
    }t_configstructimpl;

     /**
    * @struct t_filestruct
    * @brief the scructure is the file row to fullfill
    */
    typedef struct
    {
    	std::string assembly_code; /*!< assembly code */
    	std::string spare;
    	std::string posu; /*!< posu code */
    	std::string core;/*!< core code */
    	std::string ioco;/*!< ioco code */
    	std::string daio;/*!< daio code */
    	std::string rebo;/*!< rebo code */
    	std::string sabo;/*!< sabo code */
    	std::string mvb;/*!< mvb code */
    	std::string cpm;/*!< cpm code */
    	std::string sram;/*!< sram code */
    	std::string flash;/*!< flash code */
    	std::string backplane;/*!< backplane code */
 	}t_filestruct;

    extern t_configstructimpl *getaccescfgimpl(void);
    extern t_filestruct *getfilestruct(void);
}

void closefile(void);

/**
* @class configimpl
* @brief the pimpl class manages the methods hide in the configuration class
*/
struct config::configimpl
{
	configimpl(){};
	virtual ~configimpl(){
	};
	void extract_filename(std::string line, type_::CHAR *filename, type_::CHAR* assemblycode);
	void extract_column_compare(std::string line, type_::CHAR *col);
	type_::ebool find_column(const type_::CHAR *title, const type_::CHAR *col);
	type_::ebool parser_kenfile(const type_:: CHAR *col, std::string filename);
	type_::UINT64 getsizeTeloc(void);
	void scroll_column(const std::string teloccode);
	void create_template(ofstream &osheet);
	void create_teloc_assembly(const char *s, Sheet *osheet,  type_::UINT64 row);
	void create_output_file(std::vector<std::string> col, ofstream &file);
	void extract_family(std::string code, ofstream &osheet, configimpl_::t_filestruct *ptr);
	void extract_version(std::string code, std::string &variant);
	void write_variant(type_::UINT64 pos, std::string variant, configimpl_::t_filestruct *ptr);
	void compare_create_configuration(ifstream &osheet);
};


#endif
