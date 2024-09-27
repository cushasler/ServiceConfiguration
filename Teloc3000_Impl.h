/**
 * @file Teloc3000_Impl.h
 * @brief file used to manage the methods for Teloc3000
 * @author: Salvatore Muoio
 */

#ifndef INCLUDE_TELOC3000_IMPL_H_
#define INCLUDE_TELOC3000_IMPL_H_


#include "Types.h"

///namspaxe teloc3000impl_
namespace teloc3000impl_
{
/**
 @enum eT3Code
 @brief the structure manage the boards for the Teloc 3000
 */

	typedef enum
	{
		NO_BOARD_ENABLED   = 0,    /*!< NO_BOARD_ENABLED */
		DATRA_ENABLED      = 0x04, /*!< DATRA_ENABLED */
		CAN_ENABLED        = 0x08, /*!< CAN_ENABLED */
		USCOA_ENABLED      = 0x10, /*!< USCOA_ENABLED*/
		DAIOD_ENABLED      = 0x20, /*!< DAIOD_ENABLED*/
		REBO_ENABLED       = 0x40, /*!< REBO_ENABLED */
		TACHA_ENABLED      = 0x80, /*!< TACHA_ENABLED */
		USCOA_TACHA_ENABLED = 0x90, /*!< USCOA_TACHA_ENABLED*/
		SABO_ENABLED       = 0x100, /*!< SABO_ENABLED */
		MVB_ENABLED        = 0x200, /*!< SABO_ENABLED */
		CPM_ENABLED        = 0x400, /*!< CPM_ENABLED */
	}eT3Code;
	/*!
	* @fn eT3Code setSABO(type_::UINT64 maincode)
	* @brief the function set the SABO, if it's set on the old Teloc
	* @param maincode, code of assembly code under check
	* @return TRUE or FALSE
	*/
	eT3Code setSABO(type_::UINT64 maincode);
	/*!
	* @fn eT3Code setDIGITAL(type_::UINT64 maincode)
	* @brief the function set the DAIOD and DOCAA and the DRSCA, if they are set on the old Teloc
	* @param maincode, code of assembly code under check
	* @return TRUE or FALSE
	*/
	eT3Code setDIGITAL(type_::UINT64 maincode);
	/*!
	* @fn eT3Code setTACA(type_::UINT64 maincode)
	* @brief the function set the setTACA and the USCOA, if they are set on the old Teloc
	* @param maincode, code of assembly code under check
	* @return TRUE or FALSE
	*/
	eT3Code setTACA(type_::UINT64 maincode);
	/*!
	* @fn eT3Code setBUS(type_::UINT64 maincode)
	* @brief the function set the MVB or CAN bus , if they are set on the old Teloc
	* @param maincode, code of assembly code under check
	* @return TRUE or FALSE
	*/
	eT3Code setBUS(type_::UINT64 maincode);
	/**
	* @fn eT3Code setCPM(type_::UINT64 maincode)
	* @brief the function set the CPM , if it's set on the old Teloc
	* @param maincode, code of assembly code under check
	* @return TRUE or FALSE
	*/
	eT3Code setCPM(type_::UINT64 maincode);


}//namespace teloc3000impl_


#endif /* INCLUDE_TELOC3000_IMPL_H_ */
