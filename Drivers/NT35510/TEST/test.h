 /* @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, QD electronic SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
**************************************************************************************************/				
#ifndef __TEST_H__
#define __TEST_H__

#include "stdint.h"

void drawtestpage(uint8_t *str);
void test_color(void);
void test_fillrec(void);
void test_circle(void);
void test_triangle(void);
void english_font_test(void);
void chinese_font_test(void);
void pic_test(void);
void load_drow_dialog(void);
void touch_test(void);
void main_test(void);
void rotate_test(void);
void test_read(void);
#endif
