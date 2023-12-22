/**
* @file Configuration_impl.h
* @brief in this file are implmented the methods private in the pimpl
* @author Salvatore Muoio
*/

#ifndef __CONFIGURATION_IMPL_H__
#define __CONFIGURATION_IMPL_H__


#include "Configuration.h"
#include "Types.h"

namespace configimpl_
{
	typedef struct
    {
        type_::UINT64 findcolumn;
    }t_configstructimpl;
    
    t_configstructimpl *getaccescfgimpl(void);
}


struct config::configimpl
{
	configimpl(){};
	virtual ~configimpl(){
	};
	void extract_filename(std::string line, type_::CHAR *filename);
	void extract_column_compare(std::string line, type_::CHAR *col);
	type_::ebool find_column(const type_::CHAR *title, const type_::CHAR *col);
	type_::ebool parser_kenfile(const type_:: CHAR *col, std::string filename);
	void scroll_column(const std::string teloccode);
};


#endif
