 /* @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, QD electronic SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
**************************************************************************************************/			
#ifndef __GUI_H__
#define __GUI_H__
#include "stdint.h"

void gui_drawpoint(uint16_t x,uint16_t y,uint16_t color);
void lcd_fill(uint16_t sx,uint16_t sy,uint16_t ex,uint16_t ey,uint16_t color);
void lcd_drawline(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void lcd_drawrectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void draw_circle(uint16_t x0,uint16_t y0,uint16_t fc,uint8_t r);
void draw_triangel(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);
void fill_triangel(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);
void lcd_showchar(uint16_t x,uint16_t y,uint16_t fc, uint16_t bc, uint8_t num,uint8_t size,uint8_t mode);
void lcd_shownum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t size);
void lcd_show2num(uint16_t x,uint16_t y,uint16_t num,uint8_t len,uint8_t size,uint8_t mode);
void lcd_showstring(uint16_t x,uint16_t y,uint8_t size,uint8_t *p,uint8_t mode);
void gui_drawfont16(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s,uint8_t mode);
void gui_drawfont24(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s,uint8_t mode);
void gui_drawfont32(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s,uint8_t mode);
void show_str(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *str,uint8_t size,uint8_t mode);
void gui_drawbmp16(uint16_t x,uint16_t y,uint16_t w,uint16_t h,const unsigned char *p); //œ‘ æ40*40 qqÕº∆¨
void gui_circle(int xc, int yc,uint16_t c,int r, int fill);
void gui_strcenter(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *str,uint8_t size,uint8_t mode);
void lcd_drawfillrectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
#endif

