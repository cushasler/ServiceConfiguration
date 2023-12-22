/**
* @file Type_.h
* @brief the implements the custom typedef 
*/

#ifndef __TYPE_H__
#define __TYPE_H__

/**
* @namespace type_
* @brief namespace used to manages the typedef 
*/
namespace type_
{
	/**
	*@typedef
	*@brief definition of project typedef abstract
	*/
	typedef unsigned short UINT16;
	typedef unsigned int UINT64;
	typedef unsigned char UINT8;
	typedef char CHAR;
	/**
	*@enum
	*@brief definition of boolen value
	*/
	typedef enum
	{
		FALSE, /*!< False is 0 */
		TRUE, /*!< True is 1 */
	}ebool;
	
	/**
	* \enum e_result
 	* \brief the enum is used as validity check in the methods
    */
	typedef enum
	{
		RESULT_OK,                     /*!< Result of check ok */
		RESULT_POINTER_NOT_ADDRESSED,  /*!< Result of pointer check ko */
		RESULT_OUT_OF_RANGE,           /*!< Result of range check ko */
		RESULT_NOT_READY_UART = 4,     /*!< Result of uart not ready */
	}e_result;
}


#endif
