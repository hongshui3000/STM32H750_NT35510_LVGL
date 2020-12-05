
/* @attention
 *
 * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * TIME. AS A RESULT, QD electronic SHALL NOT BE HELD LIABLE FOR ANY
 * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
**************************************************************************************************/
#include "lcd.h"
#include "stdlib.h"
#include "tim.h"

//����lcd��Ҫ����
//Ĭ��Ϊ����
_lcd_dev lcddev;

//������ɫ,������ɫ
uint16_t POINT_COLOR = 0x0000,BACK_COLOR = 0xffff;
uint16_t devicecode;

uint16_t lcd_read(void)
{
    volatile uint16_t data;  //��ֹ���Ż�
    data=LCD->LCD_RAM;
    return data;
}

/*****************************************************************************
 * @name       :void lcd_wr_reg(uint16_t data)
 * @date       :
 * @function   :write an 16-bit command to the lcd screen
 * @parameters :data:command value to be written
 * @retvalue   :none
******************************************************************************/
void lcd_wr_reg(uint16_t data)
{
    LCD->LCD_REG=data; //д��Ҫд�ļĴ������
}

/*****************************************************************************
 * @name       :void lcd_wr_data(uint16_t data)
 * @date       :
 * @function   :write an 16-bit data to the lcd screen
 * @parameters :data:data value to be written
 * @retvalue   :none
******************************************************************************/
void lcd_wr_data(uint16_t data)
{
    LCD->LCD_RAM=data; //д��Ҫд������
}

/*****************************************************************************
 * @name       :uint16_t lcd_rd_data(void)
 * @date       :
 * @function   :read an 16-bit value from the lcd screen
 * @parameters :none
 * @retvalue   :read value
******************************************************************************/
uint16_t lcd_rd_data(void)
{
    return lcd_read();
}

/*****************************************************************************
 * @name       :void lcd_writereg(uint16_t lcd_reg, uint16_t lcd_regvalue)
 * @date       :
 * @function   :write data into registers
 * @parameters :lcd_reg:register address
                lcd_regvalue:data to be written
 * @retvalue   :none
******************************************************************************/
void lcd_writereg(uint16_t lcd_reg, uint16_t lcd_regvalue)
{
    LCD->LCD_REG = lcd_reg;		//д��Ҫд�ļĴ������
    LCD->LCD_RAM = lcd_regvalue;//д������
}

/*****************************************************************************
 * @name       :void lcd_readreg(uint16_t lcd_reg,uint16_t *rval,int n)
 * @date       :
 * @function   :read value from specially registers
 * @parameters :lcd_reg:register address
 * @retvalue   :read value
******************************************************************************/
void lcd_readreg(uint16_t lcd_reg,uint16_t *rval,int n)
{
    lcd_wr_reg(lcd_reg);
    while(n--)
    {
        *(rval++) = lcd_rd_data();
        delay_us(100);
    }
}

/*****************************************************************************
 * @name       :void lcd_writeram_prepare(void)
 * @date       :
 * @function   :write gram
 * @parameters :none
 * @retvalue   :none
******************************************************************************/
void lcd_writeram_prepare(void)
{
    lcd_wr_reg(lcddev.wramcmd);
}

/*****************************************************************************
 * @name       :void lcd_readram_prepare(void)
 * @date       :
 * @function   :read gram
 * @parameters :none
 * @retvalue   :none
******************************************************************************/
void lcd_readram_prepare(void)
{
    lcd_wr_reg(lcddev.rramcmd);
}

/*****************************************************************************
 * @name       :void lcd_writedata_16bit(uint16_t data)
 * @date       :
 * @function   :write an 16-bit command to the lcd screen
 * @parameters :data:data to be written
 * @retvalue   :none
******************************************************************************/
void lcd_writedata_16bit(uint16_t data)
{
    LCD->LCD_RAM = data;
}

uint16_t color_to_565(uint8_t r, uint8_t g, uint8_t b)
{
    return ((r & 0xf8) << 8) | ((g & 0xfc) << 3) | ((b & 0xf8) >> 3);
}

/*****************************************************************************
 * @name       :uint16_t lcd_readdata_16bit(void)
 * @date       :
 * @function   :read an 16-bit value from the lcd screen
 * @parameters :none
 * @retvalue   :read value
******************************************************************************/
uint16_t lcd_readdata_16bit(void)
{
    uint16_t r,g,b;
    //dummy data
    r = lcd_rd_data();
    delay_us(1);//��ʱ1us
    //red and green data
    r = lcd_rd_data();
    delay_us(1);//��ʱ1us
    //blue data
    g = lcd_rd_data();

    b = g>>8;
    g = r&0xff;
    r = r>>8;
    return color_to_565(r, g, b);
}

/*****************************************************************************
 * @name       :void lcd_drawpoint(uint16_t x,uint16_t y)
 * @date       :
 * @function   :write a pixel data at a specified location
 * @parameters :x:the x coordinate of the pixel
                y:the y coordinate of the pixel
 * @retvalue   :none
******************************************************************************/
void lcd_drawpoint(uint16_t x,uint16_t y)
{
    lcd_setcursor(x,y);//���ù��λ��
    lcd_writedata_16bit(POINT_COLOR);
}

/*****************************************************************************
 * @name       :uint16_t lcd_readpoint(uint16_t x,uint16_t y)
 * @date       :
 * @function   :read a pixel color value at a specified location
 * @parameters :x:the x coordinate of the pixel
                y:the y coordinate of the pixel
 * @retvalue   :the read color value
******************************************************************************/
uint16_t lcd_readpoint(uint16_t x,uint16_t y)
{
    uint16_t color;
    if(x>=lcddev.width||y>=lcddev.height)
    {
        return 0;	//�����˷�Χ,ֱ�ӷ���
    }
    lcd_setcursor(x,y);//���ù��λ��
    lcd_readram_prepare();
    color = lcd_readdata_16bit();
    return color;
}

/*****************************************************************************
 * @name       :void lcd_clear(uint16_t color)
 * @date       :
 * @function   :full screen filled lcd screen
 * @parameters :color:filled color
 * @retvalue   :none
******************************************************************************/
void lcd_clear(uint16_t color)
{
    unsigned int i;
    uint32_t total_point=lcddev.width*lcddev.height;
    lcd_setwindows(0,0,lcddev.width-1,lcddev.height-1);
    for(i=0; i<total_point; i++)
    {
        LCD->LCD_RAM = color;
    }
}

/*****************************************************************************
 * @name       :void lcd_init(void)
 * @date       :
 * @function   :initialization lcd screen
 * @parameters :none
 * @retvalue   :none
******************************************************************************/
void lcd_init(void)
{
	HAL_GPIO_WritePin(GPIOD, LCD_RST_Pin, GPIO_PIN_RESET);
    HAL_Delay(50); //�������ʱ����Ȼreset����Ļ�ײ�����ֺ�����
	HAL_GPIO_WritePin(GPIOD, LCD_RST_Pin, GPIO_PIN_SET);
	HAL_Delay(50);
	
	
//************* nt35510��ʼ��**********//
    lcd_wr_reg(0xf000);
    lcd_wr_data(0x55);
    lcd_wr_reg(0xf001);
    lcd_wr_data(0xaa);
    lcd_wr_reg(0xf002);
    lcd_wr_data(0x52);
    lcd_wr_reg(0xf003);
    lcd_wr_data(0x08);
    lcd_wr_reg(0xf004);
    lcd_wr_data(0x01);
    //# avdd: manual); lcd_wr_data(
    lcd_wr_reg(0xb600);
    lcd_wr_data(0x34);
    lcd_wr_reg(0xb601);
    lcd_wr_data(0x34);
    lcd_wr_reg(0xb602);
    lcd_wr_data(0x34);

    lcd_wr_reg(0xb000);
    lcd_wr_data(0x0d);//09
    lcd_wr_reg(0xb001);
    lcd_wr_data(0x0d);
    lcd_wr_reg(0xb002);
    lcd_wr_data(0x0d);
    //# avee: manual); lcd_wr_data( -6v
    lcd_wr_reg(0xb700);
    lcd_wr_data(0x24);
    lcd_wr_reg(0xb701);
    lcd_wr_data(0x24);
    lcd_wr_reg(0xb702);
    lcd_wr_data(0x24);

    lcd_wr_reg(0xb100);
    lcd_wr_data(0x0d);
    lcd_wr_reg(0xb101);
    lcd_wr_data(0x0d);
    lcd_wr_reg(0xb102);
    lcd_wr_data(0x0d);
    //#power control for
    //vcl
    lcd_wr_reg(0xb800);
    lcd_wr_data(0x24);
    lcd_wr_reg(0xb801);
    lcd_wr_data(0x24);
    lcd_wr_reg(0xb802);
    lcd_wr_data(0x24);

    lcd_wr_reg(0xb200);
    lcd_wr_data(0x00);

    //# vgh: clamp enable); lcd_wr_data(
    lcd_wr_reg(0xb900);
    lcd_wr_data(0x24);
    lcd_wr_reg(0xb901);
    lcd_wr_data(0x24);
    lcd_wr_reg(0xb902);
    lcd_wr_data(0x24);

    lcd_wr_reg(0xb300);
    lcd_wr_data(0x05);
    lcd_wr_reg(0xb301);
    lcd_wr_data(0x05);
    lcd_wr_reg(0xb302);
    lcd_wr_data(0x05);

    ///lcd_wr_reg(0xbf00); lcd_wr_data(0x01);

    //# vgl(lvgl):
    lcd_wr_reg(0xba00);
    lcd_wr_data(0x34);
    lcd_wr_reg(0xba01);
    lcd_wr_data(0x34);
    lcd_wr_reg(0xba02);
    lcd_wr_data(0x34);
    //# vgl_reg(vglo)
    lcd_wr_reg(0xb500);
    lcd_wr_data(0x0b);
    lcd_wr_reg(0xb501);
    lcd_wr_data(0x0b);
    lcd_wr_reg(0xb502);
    lcd_wr_data(0x0b);
    //# vgmp/vgsp:
    lcd_wr_reg(0xbc00);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xbc01);
    lcd_wr_data(0xa3);
    lcd_wr_reg(0xbc02);
    lcd_wr_data(0x00);
    //# vgmn/vgsn
    lcd_wr_reg(0xbd00);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xbd01);
    lcd_wr_data(0xa3);
    lcd_wr_reg(0xbd02);
    lcd_wr_data(0x00);
    //# vcom=-0.1
    lcd_wr_reg(0xbe00);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xbe01);
    lcd_wr_data(0x63);//4f
    //  vcomh+0x01;
    //#r+
    lcd_wr_reg(0xd100);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd101);
    lcd_wr_data(0x37);
    lcd_wr_reg(0xd102);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd103);
    lcd_wr_data(0x52);
    lcd_wr_reg(0xd104);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd105);
    lcd_wr_data(0x7b);
    lcd_wr_reg(0xd106);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd107);
    lcd_wr_data(0x99);
    lcd_wr_reg(0xd108);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd109);
    lcd_wr_data(0xb1);
    lcd_wr_reg(0xd10a);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd10b);
    lcd_wr_data(0xd2);
    lcd_wr_reg(0xd10c);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd10d);
    lcd_wr_data(0xf6);
    lcd_wr_reg(0xd10e);
    lcd_wr_data(0x01);
    lcd_wr_reg(0xd10f);
    lcd_wr_data(0x27);
    lcd_wr_reg(0xd110);
    lcd_wr_data(0x01);
    lcd_wr_reg(0xd111);
    lcd_wr_data(0x4e);
    lcd_wr_reg(0xd112);
    lcd_wr_data(0x01);
    lcd_wr_reg(0xd113);
    lcd_wr_data(0x8c);
    lcd_wr_reg(0xd114);
    lcd_wr_data(0x01);
    lcd_wr_reg(0xd115);
    lcd_wr_data(0xbe);
    lcd_wr_reg(0xd116);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd117);
    lcd_wr_data(0x0b);
    lcd_wr_reg(0xd118);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd119);
    lcd_wr_data(0x48);
    lcd_wr_reg(0xd11a);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd11b);
    lcd_wr_data(0x4a);
    lcd_wr_reg(0xd11c);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd11d);
    lcd_wr_data(0x7e);
    lcd_wr_reg(0xd11e);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd11f);
    lcd_wr_data(0xbc);
    lcd_wr_reg(0xd120);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd121);
    lcd_wr_data(0xe1);
    lcd_wr_reg(0xd122);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd123);
    lcd_wr_data(0x10);
    lcd_wr_reg(0xd124);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd125);
    lcd_wr_data(0x31);
    lcd_wr_reg(0xd126);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd127);
    lcd_wr_data(0x5a);
    lcd_wr_reg(0xd128);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd129);
    lcd_wr_data(0x73);
    lcd_wr_reg(0xd12a);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd12b);
    lcd_wr_data(0x94);
    lcd_wr_reg(0xd12c);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd12d);
    lcd_wr_data(0x9f);
    lcd_wr_reg(0xd12e);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd12f);
    lcd_wr_data(0xb3);
    lcd_wr_reg(0xd130);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd131);
    lcd_wr_data(0xb9);
    lcd_wr_reg(0xd132);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd133);
    lcd_wr_data(0xc1);
    //#g+
    lcd_wr_reg(0xd200);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd201);
    lcd_wr_data(0x37);
    lcd_wr_reg(0xd202);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd203);
    lcd_wr_data(0x52);
    lcd_wr_reg(0xd204);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd205);
    lcd_wr_data(0x7b);
    lcd_wr_reg(0xd206);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd207);
    lcd_wr_data(0x99);
    lcd_wr_reg(0xd208);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd209);
    lcd_wr_data(0xb1);
    lcd_wr_reg(0xd20a);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd20b);
    lcd_wr_data(0xd2);
    lcd_wr_reg(0xd20c);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd20d);
    lcd_wr_data(0xf6);
    lcd_wr_reg(0xd20e);
    lcd_wr_data(0x01);
    lcd_wr_reg(0xd20f);
    lcd_wr_data(0x27);
    lcd_wr_reg(0xd210);
    lcd_wr_data(0x01);
    lcd_wr_reg(0xd211);
    lcd_wr_data(0x4e);
    lcd_wr_reg(0xd212);
    lcd_wr_data(0x01);
    lcd_wr_reg(0xd213);
    lcd_wr_data(0x8c);
    lcd_wr_reg(0xd214);
    lcd_wr_data(0x01);
    lcd_wr_reg(0xd215);
    lcd_wr_data(0xbe);
    lcd_wr_reg(0xd216);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd217);
    lcd_wr_data(0x0b);
    lcd_wr_reg(0xd218);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd219);
    lcd_wr_data(0x48);
    lcd_wr_reg(0xd21a);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd21b);
    lcd_wr_data(0x4a);
    lcd_wr_reg(0xd21c);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd21d);
    lcd_wr_data(0x7e);
    lcd_wr_reg(0xd21e);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd21f);
    lcd_wr_data(0xbc);
    lcd_wr_reg(0xd220);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd221);
    lcd_wr_data(0xe1);
    lcd_wr_reg(0xd222);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd223);
    lcd_wr_data(0x10);
    lcd_wr_reg(0xd224);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd225);
    lcd_wr_data(0x31);
    lcd_wr_reg(0xd226);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd227);
    lcd_wr_data(0x5a);
    lcd_wr_reg(0xd228);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd229);
    lcd_wr_data(0x73);
    lcd_wr_reg(0xd22a);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd22b);
    lcd_wr_data(0x94);
    lcd_wr_reg(0xd22c);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd22d);
    lcd_wr_data(0x9f);
    lcd_wr_reg(0xd22e);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd22f);
    lcd_wr_data(0xb3);
    lcd_wr_reg(0xd230);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd231);
    lcd_wr_data(0xb9);
    lcd_wr_reg(0xd232);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd233);
    lcd_wr_data(0xc1);
    //#b+
    lcd_wr_reg(0xd300);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd301);
    lcd_wr_data(0x37);
    lcd_wr_reg(0xd302);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd303);
    lcd_wr_data(0x52);
    lcd_wr_reg(0xd304);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd305);
    lcd_wr_data(0x7b);
    lcd_wr_reg(0xd306);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd307);
    lcd_wr_data(0x99);
    lcd_wr_reg(0xd308);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd309);
    lcd_wr_data(0xb1);
    lcd_wr_reg(0xd30a);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd30b);
    lcd_wr_data(0xd2);
    lcd_wr_reg(0xd30c);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd30d);
    lcd_wr_data(0xf6);
    lcd_wr_reg(0xd30e);
    lcd_wr_data(0x01);
    lcd_wr_reg(0xd30f);
    lcd_wr_data(0x27);
    lcd_wr_reg(0xd310);
    lcd_wr_data(0x01);
    lcd_wr_reg(0xd311);
    lcd_wr_data(0x4e);
    lcd_wr_reg(0xd312);
    lcd_wr_data(0x01);
    lcd_wr_reg(0xd313);
    lcd_wr_data(0x8c);
    lcd_wr_reg(0xd314);
    lcd_wr_data(0x01);
    lcd_wr_reg(0xd315);
    lcd_wr_data(0xbe);
    lcd_wr_reg(0xd316);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd317);
    lcd_wr_data(0x0b);
    lcd_wr_reg(0xd318);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd319);
    lcd_wr_data(0x48);
    lcd_wr_reg(0xd31a);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd31b);
    lcd_wr_data(0x4a);
    lcd_wr_reg(0xd31c);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd31d);
    lcd_wr_data(0x7e);
    lcd_wr_reg(0xd31e);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd31f);
    lcd_wr_data(0xbc);
    lcd_wr_reg(0xd320);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd321);
    lcd_wr_data(0xe1);
    lcd_wr_reg(0xd322);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd323);
    lcd_wr_data(0x10);
    lcd_wr_reg(0xd324);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd325);
    lcd_wr_data(0x31);
    lcd_wr_reg(0xd326);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd327);
    lcd_wr_data(0x5a);
    lcd_wr_reg(0xd328);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd329);
    lcd_wr_data(0x73);
    lcd_wr_reg(0xd32a);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd32b);
    lcd_wr_data(0x94);
    lcd_wr_reg(0xd32c);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd32d);
    lcd_wr_data(0x9f);
    lcd_wr_reg(0xd32e);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd32f);
    lcd_wr_data(0xb3);
    lcd_wr_reg(0xd330);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd331);
    lcd_wr_data(0xb9);
    lcd_wr_reg(0xd332);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd333);
    lcd_wr_data(0xc1);

    //#r-///////////////////////////////////////////
    lcd_wr_reg(0xd400);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd401);
    lcd_wr_data(0x37);
    lcd_wr_reg(0xd402);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd403);
    lcd_wr_data(0x52);
    lcd_wr_reg(0xd404);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd405);
    lcd_wr_data(0x7b);
    lcd_wr_reg(0xd406);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd407);
    lcd_wr_data(0x99);
    lcd_wr_reg(0xd408);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd409);
    lcd_wr_data(0xb1);
    lcd_wr_reg(0xd40a);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd40b);
    lcd_wr_data(0xd2);
    lcd_wr_reg(0xd40c);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd40d);
    lcd_wr_data(0xf6);
    lcd_wr_reg(0xd40e);
    lcd_wr_data(0x01);
    lcd_wr_reg(0xd40f);
    lcd_wr_data(0x27);
    lcd_wr_reg(0xd410);
    lcd_wr_data(0x01);
    lcd_wr_reg(0xd411);
    lcd_wr_data(0x4e);
    lcd_wr_reg(0xd412);
    lcd_wr_data(0x01);
    lcd_wr_reg(0xd413);
    lcd_wr_data(0x8c);
    lcd_wr_reg(0xd414);
    lcd_wr_data(0x01);
    lcd_wr_reg(0xd415);
    lcd_wr_data(0xbe);
    lcd_wr_reg(0xd416);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd417);
    lcd_wr_data(0x0b);
    lcd_wr_reg(0xd418);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd419);
    lcd_wr_data(0x48);
    lcd_wr_reg(0xd41a);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd41b);
    lcd_wr_data(0x4a);
    lcd_wr_reg(0xd41c);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd41d);
    lcd_wr_data(0x7e);
    lcd_wr_reg(0xd41e);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd41f);
    lcd_wr_data(0xbc);
    lcd_wr_reg(0xd420);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd421);
    lcd_wr_data(0xe1);
    lcd_wr_reg(0xd422);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd423);
    lcd_wr_data(0x10);
    lcd_wr_reg(0xd424);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd425);
    lcd_wr_data(0x31);
    lcd_wr_reg(0xd426);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd427);
    lcd_wr_data(0x5a);
    lcd_wr_reg(0xd428);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd429);
    lcd_wr_data(0x73);
    lcd_wr_reg(0xd42a);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd42b);
    lcd_wr_data(0x94);
    lcd_wr_reg(0xd42c);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd42d);
    lcd_wr_data(0x9f);
    lcd_wr_reg(0xd42e);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd42f);
    lcd_wr_data(0xb3);
    lcd_wr_reg(0xd430);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd431);
    lcd_wr_data(0xb9);
    lcd_wr_reg(0xd432);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd433);
    lcd_wr_data(0xc1);

    //#g-//////////////////////////////////////////////
    lcd_wr_reg(0xd500);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd501);
    lcd_wr_data(0x37);
    lcd_wr_reg(0xd502);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd503);
    lcd_wr_data(0x52);
    lcd_wr_reg(0xd504);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd505);
    lcd_wr_data(0x7b);
    lcd_wr_reg(0xd506);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd507);
    lcd_wr_data(0x99);
    lcd_wr_reg(0xd508);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd509);
    lcd_wr_data(0xb1);
    lcd_wr_reg(0xd50a);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd50b);
    lcd_wr_data(0xd2);
    lcd_wr_reg(0xd50c);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd50d);
    lcd_wr_data(0xf6);
    lcd_wr_reg(0xd50e);
    lcd_wr_data(0x01);
    lcd_wr_reg(0xd50f);
    lcd_wr_data(0x27);
    lcd_wr_reg(0xd510);
    lcd_wr_data(0x01);
    lcd_wr_reg(0xd511);
    lcd_wr_data(0x4e);
    lcd_wr_reg(0xd512);
    lcd_wr_data(0x01);
    lcd_wr_reg(0xd513);
    lcd_wr_data(0x8c);
    lcd_wr_reg(0xd514);
    lcd_wr_data(0x01);
    lcd_wr_reg(0xd515);
    lcd_wr_data(0xbe);
    lcd_wr_reg(0xd516);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd517);
    lcd_wr_data(0x0b);
    lcd_wr_reg(0xd518);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd519);
    lcd_wr_data(0x48);
    lcd_wr_reg(0xd51a);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd51b);
    lcd_wr_data(0x4a);
    lcd_wr_reg(0xd51c);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd51d);
    lcd_wr_data(0x7e);
    lcd_wr_reg(0xd51e);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd51f);
    lcd_wr_data(0xbc);
    lcd_wr_reg(0xd520);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd521);
    lcd_wr_data(0xe1);
    lcd_wr_reg(0xd522);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd523);
    lcd_wr_data(0x10);
    lcd_wr_reg(0xd524);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd525);
    lcd_wr_data(0x31);
    lcd_wr_reg(0xd526);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd527);
    lcd_wr_data(0x5a);
    lcd_wr_reg(0xd528);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd529);
    lcd_wr_data(0x73);
    lcd_wr_reg(0xd52a);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd52b);
    lcd_wr_data(0x94);
    lcd_wr_reg(0xd52c);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd52d);
    lcd_wr_data(0x9f);
    lcd_wr_reg(0xd52e);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd52f);
    lcd_wr_data(0xb3);
    lcd_wr_reg(0xd530);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd531);
    lcd_wr_data(0xb9);
    lcd_wr_reg(0xd532);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd533);
    lcd_wr_data(0xc1);
    //#b-///////////////////////////////
    lcd_wr_reg(0xd600);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd601);
    lcd_wr_data(0x37);
    lcd_wr_reg(0xd602);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd603);
    lcd_wr_data(0x52);
    lcd_wr_reg(0xd604);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd605);
    lcd_wr_data(0x7b);
    lcd_wr_reg(0xd606);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd607);
    lcd_wr_data(0x99);
    lcd_wr_reg(0xd608);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd609);
    lcd_wr_data(0xb1);
    lcd_wr_reg(0xd60a);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd60b);
    lcd_wr_data(0xd2);
    lcd_wr_reg(0xd60c);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xd60d);
    lcd_wr_data(0xf6);
    lcd_wr_reg(0xd60e);
    lcd_wr_data(0x01);
    lcd_wr_reg(0xd60f);
    lcd_wr_data(0x27);
    lcd_wr_reg(0xd610);
    lcd_wr_data(0x01);
    lcd_wr_reg(0xd611);
    lcd_wr_data(0x4e);
    lcd_wr_reg(0xd612);
    lcd_wr_data(0x01);
    lcd_wr_reg(0xd613);
    lcd_wr_data(0x8c);
    lcd_wr_reg(0xd614);
    lcd_wr_data(0x01);
    lcd_wr_reg(0xd615);
    lcd_wr_data(0xbe);
    lcd_wr_reg(0xd616);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd617);
    lcd_wr_data(0x0b);
    lcd_wr_reg(0xd618);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd619);
    lcd_wr_data(0x48);
    lcd_wr_reg(0xd61a);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd61b);
    lcd_wr_data(0x4a);
    lcd_wr_reg(0xd61c);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd61d);
    lcd_wr_data(0x7e);
    lcd_wr_reg(0xd61e);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd61f);
    lcd_wr_data(0xbc);
    lcd_wr_reg(0xd620);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xd621);
    lcd_wr_data(0xe1);
    lcd_wr_reg(0xd622);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd623);
    lcd_wr_data(0x10);
    lcd_wr_reg(0xd624);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd625);
    lcd_wr_data(0x31);
    lcd_wr_reg(0xd626);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd627);
    lcd_wr_data(0x5a);
    lcd_wr_reg(0xd628);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd629);
    lcd_wr_data(0x73);
    lcd_wr_reg(0xd62a);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd62b);
    lcd_wr_data(0x94);
    lcd_wr_reg(0xd62c);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd62d);
    lcd_wr_data(0x9f);
    lcd_wr_reg(0xd62e);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd62f);
    lcd_wr_data(0xb3);
    lcd_wr_reg(0xd630);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd631);
    lcd_wr_data(0xb9);
    lcd_wr_reg(0xd632);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xd633);
    lcd_wr_data(0xc1);



    //#enable page0
    lcd_wr_reg(0xf000);
    lcd_wr_data(0x55);
    lcd_wr_reg(0xf001);
    lcd_wr_data(0xaa);
    lcd_wr_reg(0xf002);
    lcd_wr_data(0x52);
    lcd_wr_reg(0xf003);
    lcd_wr_data(0x08);
    lcd_wr_reg(0xf004);
    lcd_wr_data(0x00);
    //# rgb i/f setting
    lcd_wr_reg(0xb000);
    lcd_wr_data(0x08);
    lcd_wr_reg(0xb001);
    lcd_wr_data(0x05);
    lcd_wr_reg(0xb002);
    lcd_wr_data(0x02);
    lcd_wr_reg(0xb003);
    lcd_wr_data(0x05);
    lcd_wr_reg(0xb004);
    lcd_wr_data(0x02);
    //## sdt:
    lcd_wr_reg(0xb600);
    lcd_wr_data(0x08);
    lcd_wr_reg(0xb500);
    lcd_wr_data(0x50);//0x6b ???? 480x854       0x50 ???? 480x800

    //## gate eq:
    lcd_wr_reg(0xb700);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xb701);
    lcd_wr_data(0x00);

    //## source eq:
    lcd_wr_reg(0xb800);
    lcd_wr_data(0x01);
    lcd_wr_reg(0xb801);
    lcd_wr_data(0x05);
    lcd_wr_reg(0xb802);
    lcd_wr_data(0x05);
    lcd_wr_reg(0xb803);
    lcd_wr_data(0x05);

    //# inversion: column inversion (nvt)
    lcd_wr_reg(0xbc00);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xbc01);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xbc02);
    lcd_wr_data(0x00);

    //# boe's setting(default)
    lcd_wr_reg(0xcc00);
    lcd_wr_data(0x03);
    lcd_wr_reg(0xcc01);
    lcd_wr_data(0x00);
    lcd_wr_reg(0xcc02);
    lcd_wr_data(0x00);

    //# display timing:
    lcd_wr_reg(0xbd00);
    lcd_wr_data(0x01);
    lcd_wr_reg(0xbd01);
    lcd_wr_data(0x84);
    lcd_wr_reg(0xbd02);
    lcd_wr_data(0x07);
    lcd_wr_reg(0xbd03);
    lcd_wr_data(0x31);
    lcd_wr_reg(0xbd04);
    lcd_wr_data(0x00);

    lcd_wr_reg(0xba00);
    lcd_wr_data(0x01);

    lcd_wr_reg(0xff00);
    lcd_wr_data(0xaa);
    lcd_wr_reg(0xff01);
    lcd_wr_data(0x55);
    lcd_wr_reg(0xff02);
    lcd_wr_data(0x25);
    lcd_wr_reg(0xff03);
    lcd_wr_data(0x01);

    lcd_wr_reg(0x3500);
    lcd_wr_data(0x00);
    lcd_wr_reg(0x3600);
    lcd_wr_data(0x00);
    lcd_wr_reg(0x3a00);
    lcd_wr_data(0x55);  ////55=16?/////66=18?
    lcd_wr_reg(0x1100);
    HAL_Delay(120);
    lcd_wr_reg(0x2900 );
    lcd_wr_reg(0x2c00);

    lcd_direction(USE_HORIZONTAL);//����lcd��ʾ����
    lcd_clear(WHITE);
}

/*****************************************************************************
 * @name       :void lcd_setwindows(uint16_t xstar, uint16_t ystar,uint16_t xend,uint16_t yend)
 * @date       :
 * @function   :setting lcd display window
 * @parameters :xstar:the bebinning x coordinate of the lcd display window
								ystar:the bebinning y coordinate of the lcd display window
								xend:the endning x coordinate of the lcd display window
								yend:the endning y coordinate of the lcd display window
 * @retvalue   :none
******************************************************************************/
void lcd_setwindows(uint16_t xstar, uint16_t ystar,uint16_t xend,uint16_t yend)
{
    lcd_wr_reg(lcddev.setxcmd);
    lcd_wr_data(xstar>>8);
    lcd_wr_reg(lcddev.setxcmd+1);
    lcd_wr_data(xstar&0xff);
    lcd_wr_reg(lcddev.setxcmd+2);
    lcd_wr_data(xend>>8);
    lcd_wr_reg(lcddev.setxcmd+3);
    lcd_wr_data(xend&0xff);
    lcd_wr_reg(lcddev.setycmd);
    lcd_wr_data(ystar>>8);
    lcd_wr_reg(lcddev.setycmd+1);
    lcd_wr_data(ystar&0xff);
    lcd_wr_reg(lcddev.setycmd+2);
    lcd_wr_data(yend>>8);
    lcd_wr_reg(lcddev.setycmd+3);
    lcd_wr_data(yend&0xff);

    lcd_writeram_prepare();	//��ʼд��gram
}

/*****************************************************************************
 * @name       :void lcd_setcursor(uint16_t xpos, uint16_t ypos)
 * @date       :
 * @function   :set coordinate value
 * @parameters :xpos:the  x coordinate of the pixel
								ypos:the  y coordinate of the pixel
 * @retvalue   :none
******************************************************************************/
void lcd_setcursor(uint16_t xpos, uint16_t ypos)
{
    lcd_setwindows(xpos,ypos,xpos,ypos);
}

/*****************************************************************************
 * @name       :void lcd_direction(uint8_t direction)
 * @date       :
 * @function   :setting the display direction of lcd screen
 * @parameters :direction:0-0 degree
                          1-90 degree
													2-180 degree
													3-270 degree
 * @retvalue   :none
******************************************************************************/
void lcd_direction(uint8_t direction)
{
    lcddev.setxcmd=0x2a00;
    lcddev.setycmd=0x2b00;
    lcddev.wramcmd=0x2c00;
    lcddev.rramcmd=0x2e00;
    switch(direction) {
    case 0:
        lcddev.width=LCD_W;
        lcddev.height=LCD_H;
        lcd_writereg(0x3600,0x00);
        break;
    case 1:
        lcddev.width=LCD_H;
        lcddev.height=LCD_W;
        lcd_writereg(0x3600,(1<<5)|(1<<6));
        break;
    case 2:
        lcddev.width=LCD_W;
        lcddev.height=LCD_H;
        lcd_writereg(0x3600,(1<<7)|(1<<6));
        break;
    case 3:
        lcddev.width=LCD_H;
        lcddev.height=LCD_W;
        lcd_writereg(0x3600,(1<<7)|(1<<5));
        break;
    default:
        break;
    }
}

/*****************************************************************************
 * @name       :uint16_t lcd_read_id(void)
 * @date       :
 * @function   :read id
 * @parameters :none
 * @retvalue   :id value
******************************************************************************/
uint16_t lcd_read_id(void)
{
    uint16_t val;
    lcd_wr_reg(0xf000);
    lcd_wr_data(0x55);
    lcd_wr_reg(0xf001);
    lcd_wr_data(0xaa);
    lcd_wr_reg(0xf002);
    lcd_wr_data(0x52);
    lcd_wr_reg(0xf003);
    lcd_wr_data(0x08);
    lcd_wr_reg(0xf004);
    lcd_wr_data(0x01);

    lcd_readreg(0xc500,&lcddev.id,1);//����0x55
    lcddev.id<<=8;
    lcd_readreg(0xc501,&val,1);//����0x10
    lcddev.id |= val;
    return lcddev.id;
}
