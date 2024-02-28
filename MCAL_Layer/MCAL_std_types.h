/* 
 * File:   MCAL_std_types.h
 * Author: Mayar Mahmoud; 
 *
 * Created on January 27, 2024, 11:26 PM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/*---------------------------- INCLUDE --------------------------*/
#include "std_libraries.h"
#include "compiler.h"
//#iclude "platform_types.h"

/*----------------------------- MACROS --------------------------*/
#define STD_HIGH        0x01
#define STD_LOW         0x00

#define STD_ON          0x01
#define STD_OFF         0x00

#define STD_ACTIVE      0x01
#define STD_IDLE        0x00

#define E_OK            (Std_ReturnType)0x01
#define E_NOK           (Std_ReturnType)0x00



/*-------------------- SELF-DEFINED DATATYPES -------------------*/
typedef unsigned char         boolean;
typedef unsigned char         uint8;
typedef unsigned short        uint16;
typedef unsigned long         uint32;
typedef signed char           sint8;
typedef signed short          sint16;
typedef signed long           sint32;
typedef float                 float32;

///////////////////////////////////////
typedef uint8 Std_ReturnType;
    

#endif	/* MCAL_STD_TYPES_H */

