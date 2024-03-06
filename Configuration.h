/**
* @file Configuration.h
* @brief in this file are implemented the methods used to work with Configuration file
* @author Salvatore Muoio
*/
#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#include"Types.h"
#include <string>

#define max_size_tab 10000
/**
* @namespace config_
* @brief the namespace by Configuration file
*/
namespace config_
{
   typedef struct
    {
        std::string line;
        std::string title;
		type_::CHAR filename[20];
        type_::CHAR column[60];
        type_::UINT64 numberboardTeloc[20]; /*!< number of board of Teloc  */
        type_:: CHAR assemblycode[20][20];  /*!< assembly code */
        //char *kindofTeloc;
    }t_configstruct;

    /**
    * @struct
    * @brief the teloc structure
    */
	typedef struct
	{
		std::string kindofTeloc; /*!< kinf of teloc */
		type_::UINT64 Teloc;     /*!< 0->Teloc1500; 1->Teloc2500 */
	}t_telocstrcut;
}

/**
* @class config
* @brief the class manages the methods to parser the configuration file
*/
class config
{
    protected:
    static config_::t_configstruct *getconfigstruct(void);
    static config_::t_telocstrcut *gettelocstruct(void);
    private:
	class configimpl;
	configimpl *pimpl;
    config();
    virtual ~config(){};
    config(const config &);
    const config &operator = (const config &);
    std::string whoamI(std::string line);
    public:
    static config &getinstance();
    void readfileconfig(void);
};


#endif
