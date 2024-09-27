/**
 * @file Teloc_3000_impl.cpp
 * @brief file used to manage the methods for Teloc3000
 *  Created on: Jun 27, 2024
 *  @author: Salvatore Muoio
 */

#include "iostream"
#include "Teloc3000_Impl.h"

using namespace teloc3000impl_;
/*!
* @fn teloc3000impl_::eT3Code teloc3000impl_::setSABO(type_::UINT64 maincode)
* @brief the function set the SABO, if it's set on the old Teloc
* @param maincode, code of assembly code under check
* @return TRUE or FALSE
*/

teloc3000impl_::eT3Code teloc3000impl_::setSABO(type_::UINT64 maincode)
{
	constexpr type_::UINT64 MASK_SABO = 0x20U;
	type_::UINT64 lmain = maincode&MASK_SABO;
	return((lmain == MASK_SABO) ? (teloc3000impl_:: SABO_ENABLED) :  (teloc3000impl_::NO_BOARD_ENABLED));
}

/*!
* @fn teloc3000impl_::eT3Code teloc3000impl_::setTACA(type_::UINT64 maincode)
* @brief the function set the setTACA and the USCOA, if they are set on the old Teloc
* @param maincode, code of assembly code under check
* @return TRUE or FALSE
*/

teloc3000impl_::eT3Code teloc3000impl_::setTACA(type_::UINT64 maincode)
{
	type_::UINT64 lret = teloc3000impl_:: NO_BOARD_ENABLED;
	constexpr type_::UINT64 MASK_IOCO = 0x04U;
	type_::UINT64 lmain = maincode&MASK_IOCO;
	if(lmain == MASK_IOCO)
	{
		if (setSABO(maincode) == teloc3000impl_:: SABO_ENABLED)
			lret = teloc3000impl_::USCOA_ENABLED;
		else
			lret = teloc3000impl_::USCOA_TACHA_ENABLED;
	}
	else
		lret = teloc3000impl_::NO_BOARD_ENABLED;
	return((teloc3000impl_::eT3Code)lret);
}
/*!
* @fn teloc3000impl_::eT3Code teloc3000impl_::setDIGITAL(type_::UINT64 maincode)
* @brief the function set the DAIOD and DOCAA and the DRSCA, if they are set on the old Teloc
* @param maincode, code of assembly code under check
* @return TRUE or FALSE
*/

teloc3000impl_::eT3Code teloc3000impl_ :: setDIGITAL(type_::UINT64 maincode)
{
	type_::UINT64 lret = teloc3000impl_:: NO_BOARD_ENABLED;
	constexpr type_::UINT64 MASK_DIGITAL = 0x18U;
	constexpr type_::UINT64 MASK_DAIOC   = 0x08U;
	constexpr type_::UINT64 MASK_REBOB   = 0x10U;
	type_::UINT64 lmain = maincode&MASK_DIGITAL;
	if(lmain == MASK_DIGITAL)
	{
		lret = (teloc3000impl_::DAIOD_ENABLED |
				teloc3000impl_::REBO_ENABLED);
	}
	else
	{
		if(lmain == MASK_DAIOC)
			lret = (teloc3000impl_::DAIOD_ENABLED);
		else if(lmain == MASK_REBOB)
			lret = (teloc3000impl_::REBO_ENABLED);
	}
	return((teloc3000impl_::eT3Code)lret);
}

teloc3000impl_::eT3Code teloc3000impl_::setBUS(type_::UINT64 maincode)
{
	type_::UINT64 lret = teloc3000impl_:: NO_BOARD_ENABLED;
	constexpr type_::UINT64 MASK_MVB = 0x40U;
	constexpr type_::UINT64 MASK_CAN = 0x80U;
	type_::UINT64 lmain = maincode&((MASK_MVB | MASK_CAN));
	//std::cout<<"main_code = "<<maincode<<std::endl;
	//std::cout<<"lmain = "<<lmain<<std::endl;
	if(lmain == (MASK_MVB | MASK_CAN))
	{
		lret = (teloc3000impl_:: MVB_ENABLED | teloc3000impl_:: CAN_ENABLED);
	}
	else
	{
		if(lmain == MASK_MVB)
			lret = (teloc3000impl_:: MVB_ENABLED);
		else if(lmain == MASK_CAN)
			lret = (teloc3000impl_:: CAN_ENABLED);
	}
	return((teloc3000impl_::eT3Code)lret);
}

teloc3000impl_::eT3Code teloc3000impl_::setCPM(type_::UINT64 maincode)
{
	type_::UINT64 lret = teloc3000impl_:: NO_BOARD_ENABLED;
	constexpr type_::UINT64 MASK_CPM = 0x200U;
	type_::UINT64 lmain = (maincode & MASK_CPM);
	return( (lmain == MASK_CPM) ? (teloc3000impl_::CPM_ENABLED) : (teloc3000impl_::NO_BOARD_ENABLED));
}

