/**
 * @file Teloc4000_Impl.h
 * @brief file used to manage the methods for Teloc4000
 * @author: Salvatore Muoio
 */

#include "Types.h"

///namespace teloc3000impl_
namespace teloc4000impl_
{
/**
 @enum eT4Code
 @brief the structure manage the board for the TEloc 4000
 */

	typedef enum
	{
		NO_BOARD_ENABLED   = 0,    /*!< NO_BOARD_ENABLED */
		ONLY_DRSCA_ENABLED = 0x08, /*!< ONLY_DRSCA_ENABLED */
		TECA_DRSCA_ENABLED = 0x0C, /*!< TECA_DRSCA_ENABLED */
		DAIOD_ENABLED      = 0x10, /*!< DAIOD_ENABLED */
		DOCAA_ENABLED      = 0x20, /*!< DOCAA_ENABLED */
		SABOC_ENABLED      = 0x40, /*!< SABOC_ENABLED */
		MVB_ENABLED        = 0x80, /*!< MVB_ENABLED */
		CAN_ENABLED        = 0x100,/*!< CAN_ENABLED */
		GPS_ENABLED        = 0x200,/*!< GPS_ENABLED */
		CPM_ENABLED        = 0x400,/*!< CPM_ENABLED */
	}eT4Code;
	/*!
	* @fn eT4Code setDIGITAL(type_::UINT64 maincode)
	* @brief the function set the DAIOD and DOCAA and the DRSCA, if they are set on the old Teloc
	* @param maincode, code of assembly code under check
	* @return TRUE or FALSE
	*/
	eT4Code setDIGITAL(type_::UINT64 maincode);
	/*!
	* @fn eT4Code setSABO(type_::UINT64 maincode)
	* @brief the function set the SABOC, if it's set on the old Teloc
	* @param maincode, code of assembly code under check
	* @return TRUE or FALSE
	*/
	eT4Code setSABO(type_::UINT64 maincode);
	/*!
	* @fn eT4Code setTECA(type_::UINT64 maincode)
	* @brief the function set the setTECA and the DRSCA, if they are set on the old Teloc
	* @param maincode, code of assembly code under check
	* @return TRUE or FALSE
	*/
	eT4Code setTECA(type_::UINT64 maincode);
	//teloc4000impl_::eT4Code setDIGITAL(type_::UINT64 maincode);
	/*!
	* @fn eT4Code setBUS(type_::UINT64 maincode)
	* @brief the function set the MVB or CAN bus , if they are set on the old Teloc
	* @param maincode, code of assembly code under check
	* @return TRUE or FALSE
	*/
	eT4Code setBUS(type_::UINT64 maincode);
	/*!
	* @fn eT4Code setGPS(type_::UINT64 maincode)
	* @brief the function set the GPS , if it's set on the old Teloc
	* @param maincode, code of assembly code under check
	* @return TRUE or FALSE
	*/
	eT4Code setGPS(type_::UINT64 maincode);
	/*!
	* @fn eT4Code setCPM(type_::UINT64 maincode)
	* @brief the function set the CPM , if it's set on the old Teloc
	* @param maincode, code of assembly code under check
	* @return TRUE or FALSE
	*/
	eT4Code setCPM(type_::UINT64 maincode);

}

/*!
* @fn type_::ebool checkmaincode(type_::UINT64 maincode)
* @brief the function checks if the main code is different to zero
* @param maincode,code of assembly code under check
* @return TRUE or FALSE
*/
//type_::ebool checkmaincode(type_::UINT64 maincode);
