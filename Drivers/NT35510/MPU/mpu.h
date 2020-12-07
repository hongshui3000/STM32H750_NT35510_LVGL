#ifndef __MPU_H
#define __MPU_H
#include "sys.h"
 	

//u8 MPU_Set_Protection(u32 baseaddr,u32 size,u32 rnum,u32 ap);
u8 MPU_Set_Protection(u32 baseaddr,u32 size,u32 rnum,u8 ap,u8 sen,u8 cen,u8 ben);
void MPU_Memory_Protection(void);
#endif
