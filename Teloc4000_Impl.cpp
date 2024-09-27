/**
 * @file Teloc4000_Impl.cpp
 * @brief file used to manage the methods for Teloc4000
 * @author: Salvatore Muoio
 */
#include "iostream"
#include "Teloc4000_Impl.h"

using namespace teloc4000impl_;

teloc4000impl_::eT4Code teloc4000impl_::setSABO(type_::UINT64 maincode)
{
	constexpr type_::UINT64 MASK_SABO = 0x20U;
	type_::UINT64 lmain = maincode&MASK_SABO;
	return((lmain == MASK_SABO) ? (teloc4000impl_:: SABOC_ENABLED) :  (teloc4000impl_::NO_BOARD_ENABLED));
}

teloc4000impl_::eT4Code teloc4000impl_::setTECA(type_::UINT64 maincode)
{
	type_::UINT64 lret = teloc4000impl_:: NO_BOARD_ENABLED;
	constexpr type_::UINT64 MASK_IOCO = 0x04U;
	type_::UINT64 lmain = maincode&MASK_IOCO;
	if(lmain == MASK_IOCO)
	{
		if (setSABO(maincode) == teloc4000impl_:: SABOC_ENABLED)
			lret = teloc4000impl_::ONLY_DRSCA_ENABLED;
		else
			lret = teloc4000impl_::TECA_DRSCA_ENABLED;
	}
	else
		lret = teloc4000impl_::NO_BOARD_ENABLED;
	return((teloc4000impl_::eT4Code)lret);
}

teloc4000impl_::eT4Code teloc4000impl_::setDIGITAL(type_::UINT64 maincode)
{
	type_::UINT64 lret = teloc4000impl_:: NO_BOARD_ENABLED;
	constexpr type_::UINT64 MASK_DIGITAL = 0x18U;
	constexpr type_::UINT64 MASK_DAIOC   = 0x08U;
	constexpr type_::UINT64 MASK_REBOB   = 0x10U;
	type_::UINT64 lmain = maincode&MASK_DIGITAL;
	if(lmain == MASK_DIGITAL)
	{
		lret = (teloc4000impl_::DAIOD_ENABLED |
				teloc4000impl_::DOCAA_ENABLED);
	}
	else
	{
		if(lmain == MASK_DAIOC)
			lret = (teloc4000impl_::DAIOD_ENABLED);
		else if(lmain == MASK_REBOB)
			lret = (teloc4000impl_::DOCAA_ENABLED);
	}
	return((teloc4000impl_::eT4Code)lret);
}

teloc4000impl_::eT4Code teloc4000impl_::setBUS(type_::UINT64 maincode)
{
	type_::UINT64 lret = teloc4000impl_:: NO_BOARD_ENABLED;
	constexpr type_::UINT64 MASK_MVB = 0x40U;
	constexpr type_::UINT64 MASK_CAN = 0x80U;
	type_::UINT64 lmain = maincode&((MASK_MVB | MASK_CAN));
	std::cout<<"main_code = "<<maincode<<std::endl;
	std::cout<<"lmain = "<<lmain<<std::endl;
	if(lmain == (MASK_MVB | MASK_CAN))
	{
		lret = (teloc4000impl_:: MVB_ENABLED | teloc4000impl_:: CAN_ENABLED);
	}
	else
	{
		if(lmain == MASK_MVB)
			lret = (teloc4000impl_:: MVB_ENABLED);
		else if(lmain == MASK_CAN)
			lret = (teloc4000impl_:: CAN_ENABLED);
	}
	return((teloc4000impl_::eT4Code)lret);
}

teloc4000impl_::eT4Code teloc4000impl_::setGPS(type_::UINT64 maincode)
{
	type_::UINT64 lret = teloc4000impl_:: NO_BOARD_ENABLED;
	constexpr type_::UINT64 MASK_GPS = 0x100U;
	type_::UINT64 lmain = (maincode & MASK_GPS);
	return( (lmain == MASK_GPS) ? (teloc4000impl_::GPS_ENABLED) : (teloc4000impl_::NO_BOARD_ENABLED));
}

teloc4000impl_::eT4Code teloc4000impl_::setCPM(type_::UINT64 maincode)
{
	type_::UINT64 lret = teloc4000impl_:: NO_BOARD_ENABLED;
	constexpr type_::UINT64 MASK_CPM = 0x200U;
	type_::UINT64 lmain = (maincode & MASK_CPM);
	return( (lmain == MASK_CPM) ? (teloc4000impl_::CPM_ENABLED) : (teloc4000impl_::NO_BOARD_ENABLED));
}
