
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

static void lcd_write_reg(__IO uint16_t reg, __IO uint16_t data)
{
	lcd_wr_reg(reg);
	lcd_wr_data(data);
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
	HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_RESET);
    HAL_Delay(50); //�������ʱ����Ȼreset����Ļ�ײ�����ֺ�����
	HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_SET);
	HAL_Delay(50);
	
	
//************* nt35510��ʼ��**********//
			lcd_write_reg(0xF000,0x55);
			lcd_write_reg(0xF001,0xAA);
			lcd_write_reg(0xF002,0x52);
			lcd_write_reg(0xF003,0x08);
			lcd_write_reg(0xF004,0x01);
			//AVDD Set AVDD 5.2V
			lcd_write_reg(0xB000,0x0D);
			lcd_write_reg(0xB001,0x0D);
			lcd_write_reg(0xB002,0x0D);
			//AVDD ratio
			lcd_write_reg(0xB600,0x34);
			lcd_write_reg(0xB601,0x34);
			lcd_write_reg(0xB602,0x34);
			//AVEE -5.2V
			lcd_write_reg(0xB100,0x0D);
			lcd_write_reg(0xB101,0x0D);
			lcd_write_reg(0xB102,0x0D);
			//AVEE ratio
			lcd_write_reg(0xB700,0x34);
			lcd_write_reg(0xB701,0x34);
			lcd_write_reg(0xB702,0x34);
			//VCL -2.5V
			lcd_write_reg(0xB200,0x00);
			lcd_write_reg(0xB201,0x00);
			lcd_write_reg(0xB202,0x00);
			//VCL ratio
			lcd_write_reg(0xB800,0x24);
			lcd_write_reg(0xB801,0x24);
			lcd_write_reg(0xB802,0x24);
			//VGH 15V (Free pump)
			lcd_write_reg(0xBF00,0x01);
			lcd_write_reg(0xB300,0x0F);
			lcd_write_reg(0xB301,0x0F);
			lcd_write_reg(0xB302,0x0F);
			//VGH ratio
			lcd_write_reg(0xB900,0x34);
			lcd_write_reg(0xB901,0x34);
			lcd_write_reg(0xB902,0x34);
			//VGL_REG -10V
			lcd_write_reg(0xB500,0x08);
			lcd_write_reg(0xB501,0x08);
			lcd_write_reg(0xB502,0x08);
			lcd_write_reg(0xC200,0x03);
			//VGLX ratio
			lcd_write_reg(0xBA00,0x24);
			lcd_write_reg(0xBA01,0x24);
			lcd_write_reg(0xBA02,0x24);
			//VGMP/VGSP 4.5V/0V
			lcd_write_reg(0xBC00,0x00);
			lcd_write_reg(0xBC01,0x78);
			lcd_write_reg(0xBC02,0x00);
			//VGMN/VGSN -4.5V/0V
			lcd_write_reg(0xBD00,0x00);
			lcd_write_reg(0xBD01,0x78);
			lcd_write_reg(0xBD02,0x00);
			//VCOM
			lcd_write_reg(0xBE00,0x00);
			lcd_write_reg(0xBE01,0x64);
			//Gamma Setting
			lcd_write_reg(0xD100,0x00);
			lcd_write_reg(0xD101,0x33);
			lcd_write_reg(0xD102,0x00);
			lcd_write_reg(0xD103,0x34);
			lcd_write_reg(0xD104,0x00);
			lcd_write_reg(0xD105,0x3A);
			lcd_write_reg(0xD106,0x00);
			lcd_write_reg(0xD107,0x4A);
			lcd_write_reg(0xD108,0x00);
			lcd_write_reg(0xD109,0x5C);
			lcd_write_reg(0xD10A,0x00);
			lcd_write_reg(0xD10B,0x81);
			lcd_write_reg(0xD10C,0x00);
			lcd_write_reg(0xD10D,0xA6);
			lcd_write_reg(0xD10E,0x00);
			lcd_write_reg(0xD10F,0xE5);
			lcd_write_reg(0xD110,0x01);
			lcd_write_reg(0xD111,0x13);
			lcd_write_reg(0xD112,0x01);
			lcd_write_reg(0xD113,0x54);
			lcd_write_reg(0xD114,0x01);
			lcd_write_reg(0xD115,0x82);
			lcd_write_reg(0xD116,0x01);
			lcd_write_reg(0xD117,0xCA);
			lcd_write_reg(0xD118,0x02);
			lcd_write_reg(0xD119,0x00);
			lcd_write_reg(0xD11A,0x02);
			lcd_write_reg(0xD11B,0x01);
			lcd_write_reg(0xD11C,0x02);
			lcd_write_reg(0xD11D,0x34);
			lcd_write_reg(0xD11E,0x02);
			lcd_write_reg(0xD11F,0x67);
			lcd_write_reg(0xD120,0x02);
			lcd_write_reg(0xD121,0x84);
			lcd_write_reg(0xD122,0x02);
			lcd_write_reg(0xD123,0xA4);
			lcd_write_reg(0xD124,0x02);
			lcd_write_reg(0xD125,0xB7);
			lcd_write_reg(0xD126,0x02);
			lcd_write_reg(0xD127,0xCF);
			lcd_write_reg(0xD128,0x02);
			lcd_write_reg(0xD129,0xDE);
			lcd_write_reg(0xD12A,0x02);
			lcd_write_reg(0xD12B,0xF2);
			lcd_write_reg(0xD12C,0x02);
			lcd_write_reg(0xD12D,0xFE);
			lcd_write_reg(0xD12E,0x03);
			lcd_write_reg(0xD12F,0x10);
			lcd_write_reg(0xD130,0x03);
			lcd_write_reg(0xD131,0x33);
			lcd_write_reg(0xD132,0x03);
			lcd_write_reg(0xD133,0x6D);
			lcd_write_reg(0xD200,0x00);
			lcd_write_reg(0xD201,0x33);
			lcd_write_reg(0xD202,0x00);
			lcd_write_reg(0xD203,0x34);
			lcd_write_reg(0xD204,0x00);
			lcd_write_reg(0xD205,0x3A);
			lcd_write_reg(0xD206,0x00);
			lcd_write_reg(0xD207,0x4A);
			lcd_write_reg(0xD208,0x00);
			lcd_write_reg(0xD209,0x5C);
			lcd_write_reg(0xD20A,0x00);

			lcd_write_reg(0xD20B,0x81);
			lcd_write_reg(0xD20C,0x00);
			lcd_write_reg(0xD20D,0xA6);
			lcd_write_reg(0xD20E,0x00);
			lcd_write_reg(0xD20F,0xE5);
			lcd_write_reg(0xD210,0x01);
			lcd_write_reg(0xD211,0x13);
			lcd_write_reg(0xD212,0x01);
			lcd_write_reg(0xD213,0x54);
			lcd_write_reg(0xD214,0x01);
			lcd_write_reg(0xD215,0x82);
			lcd_write_reg(0xD216,0x01);
			lcd_write_reg(0xD217,0xCA);
			lcd_write_reg(0xD218,0x02);
			lcd_write_reg(0xD219,0x00);
			lcd_write_reg(0xD21A,0x02);
			lcd_write_reg(0xD21B,0x01);
			lcd_write_reg(0xD21C,0x02);
			lcd_write_reg(0xD21D,0x34);
			lcd_write_reg(0xD21E,0x02);
			lcd_write_reg(0xD21F,0x67);
			lcd_write_reg(0xD220,0x02);
			lcd_write_reg(0xD221,0x84);
			lcd_write_reg(0xD222,0x02);
			lcd_write_reg(0xD223,0xA4);
			lcd_write_reg(0xD224,0x02);
			lcd_write_reg(0xD225,0xB7);
			lcd_write_reg(0xD226,0x02);
			lcd_write_reg(0xD227,0xCF);
			lcd_write_reg(0xD228,0x02);
			lcd_write_reg(0xD229,0xDE);
			lcd_write_reg(0xD22A,0x02);
			lcd_write_reg(0xD22B,0xF2);
			lcd_write_reg(0xD22C,0x02);
			lcd_write_reg(0xD22D,0xFE);
			lcd_write_reg(0xD22E,0x03);
			lcd_write_reg(0xD22F,0x10);
			lcd_write_reg(0xD230,0x03);
			lcd_write_reg(0xD231,0x33);
			lcd_write_reg(0xD232,0x03);
			lcd_write_reg(0xD233,0x6D);
			lcd_write_reg(0xD300,0x00);
			lcd_write_reg(0xD301,0x33);
			lcd_write_reg(0xD302,0x00);
			lcd_write_reg(0xD303,0x34);
			lcd_write_reg(0xD304,0x00);
			lcd_write_reg(0xD305,0x3A);
			lcd_write_reg(0xD306,0x00);
			lcd_write_reg(0xD307,0x4A);
			lcd_write_reg(0xD308,0x00);
			lcd_write_reg(0xD309,0x5C);
			lcd_write_reg(0xD30A,0x00);

			lcd_write_reg(0xD30B,0x81);
			lcd_write_reg(0xD30C,0x00);
			lcd_write_reg(0xD30D,0xA6);
			lcd_write_reg(0xD30E,0x00);
			lcd_write_reg(0xD30F,0xE5);
			lcd_write_reg(0xD310,0x01);
			lcd_write_reg(0xD311,0x13);
			lcd_write_reg(0xD312,0x01);
			lcd_write_reg(0xD313,0x54);
			lcd_write_reg(0xD314,0x01);
			lcd_write_reg(0xD315,0x82);
			lcd_write_reg(0xD316,0x01);
			lcd_write_reg(0xD317,0xCA);
			lcd_write_reg(0xD318,0x02);
			lcd_write_reg(0xD319,0x00);
			lcd_write_reg(0xD31A,0x02);
			lcd_write_reg(0xD31B,0x01);
			lcd_write_reg(0xD31C,0x02);
			lcd_write_reg(0xD31D,0x34);
			lcd_write_reg(0xD31E,0x02);
			lcd_write_reg(0xD31F,0x67);
			lcd_write_reg(0xD320,0x02);
			lcd_write_reg(0xD321,0x84);
			lcd_write_reg(0xD322,0x02);
			lcd_write_reg(0xD323,0xA4);
			lcd_write_reg(0xD324,0x02);
			lcd_write_reg(0xD325,0xB7);
			lcd_write_reg(0xD326,0x02);
			lcd_write_reg(0xD327,0xCF);
			lcd_write_reg(0xD328,0x02);
			lcd_write_reg(0xD329,0xDE);
			lcd_write_reg(0xD32A,0x02);
			lcd_write_reg(0xD32B,0xF2);
			lcd_write_reg(0xD32C,0x02);
			lcd_write_reg(0xD32D,0xFE);
			lcd_write_reg(0xD32E,0x03);
			lcd_write_reg(0xD32F,0x10);
			lcd_write_reg(0xD330,0x03);
			lcd_write_reg(0xD331,0x33);
			lcd_write_reg(0xD332,0x03);
			lcd_write_reg(0xD333,0x6D);
			lcd_write_reg(0xD400,0x00);
			lcd_write_reg(0xD401,0x33);
			lcd_write_reg(0xD402,0x00);
			lcd_write_reg(0xD403,0x34);
			lcd_write_reg(0xD404,0x00);
			lcd_write_reg(0xD405,0x3A);
			lcd_write_reg(0xD406,0x00);
			lcd_write_reg(0xD407,0x4A);
			lcd_write_reg(0xD408,0x00);
			lcd_write_reg(0xD409,0x5C);
			lcd_write_reg(0xD40A,0x00);
			lcd_write_reg(0xD40B,0x81);

			lcd_write_reg(0xD40C,0x00);
			lcd_write_reg(0xD40D,0xA6);
			lcd_write_reg(0xD40E,0x00);
			lcd_write_reg(0xD40F,0xE5);
			lcd_write_reg(0xD410,0x01);
			lcd_write_reg(0xD411,0x13);
			lcd_write_reg(0xD412,0x01);
			lcd_write_reg(0xD413,0x54);
			lcd_write_reg(0xD414,0x01);
			lcd_write_reg(0xD415,0x82);
			lcd_write_reg(0xD416,0x01);
			lcd_write_reg(0xD417,0xCA);
			lcd_write_reg(0xD418,0x02);
			lcd_write_reg(0xD419,0x00);
			lcd_write_reg(0xD41A,0x02);
			lcd_write_reg(0xD41B,0x01);
			lcd_write_reg(0xD41C,0x02);
			lcd_write_reg(0xD41D,0x34);
			lcd_write_reg(0xD41E,0x02);
			lcd_write_reg(0xD41F,0x67);
			lcd_write_reg(0xD420,0x02);
			lcd_write_reg(0xD421,0x84);
			lcd_write_reg(0xD422,0x02);
			lcd_write_reg(0xD423,0xA4);
			lcd_write_reg(0xD424,0x02);
			lcd_write_reg(0xD425,0xB7);
			lcd_write_reg(0xD426,0x02);
			lcd_write_reg(0xD427,0xCF);
			lcd_write_reg(0xD428,0x02);
			lcd_write_reg(0xD429,0xDE);
			lcd_write_reg(0xD42A,0x02);
			lcd_write_reg(0xD42B,0xF2);
			lcd_write_reg(0xD42C,0x02);
			lcd_write_reg(0xD42D,0xFE);
			lcd_write_reg(0xD42E,0x03);
			lcd_write_reg(0xD42F,0x10);
			lcd_write_reg(0xD430,0x03);
			lcd_write_reg(0xD431,0x33);
			lcd_write_reg(0xD432,0x03);
			lcd_write_reg(0xD433,0x6D);
			lcd_write_reg(0xD500,0x00);
			lcd_write_reg(0xD501,0x33);
			lcd_write_reg(0xD502,0x00);
			lcd_write_reg(0xD503,0x34);
			lcd_write_reg(0xD504,0x00);
			lcd_write_reg(0xD505,0x3A);
			lcd_write_reg(0xD506,0x00);
			lcd_write_reg(0xD507,0x4A);
			lcd_write_reg(0xD508,0x00);
			lcd_write_reg(0xD509,0x5C);
			lcd_write_reg(0xD50A,0x00);
			lcd_write_reg(0xD50B,0x81);

			lcd_write_reg(0xD50C,0x00);
			lcd_write_reg(0xD50D,0xA6);
			lcd_write_reg(0xD50E,0x00);
			lcd_write_reg(0xD50F,0xE5);
			lcd_write_reg(0xD510,0x01);
			lcd_write_reg(0xD511,0x13);
			lcd_write_reg(0xD512,0x01);
			lcd_write_reg(0xD513,0x54);
			lcd_write_reg(0xD514,0x01);
			lcd_write_reg(0xD515,0x82);
			lcd_write_reg(0xD516,0x01);
			lcd_write_reg(0xD517,0xCA);
			lcd_write_reg(0xD518,0x02);
			lcd_write_reg(0xD519,0x00);
			lcd_write_reg(0xD51A,0x02);
			lcd_write_reg(0xD51B,0x01);
			lcd_write_reg(0xD51C,0x02);
			lcd_write_reg(0xD51D,0x34);
			lcd_write_reg(0xD51E,0x02);
			lcd_write_reg(0xD51F,0x67);
			lcd_write_reg(0xD520,0x02);
			lcd_write_reg(0xD521,0x84);
			lcd_write_reg(0xD522,0x02);
			lcd_write_reg(0xD523,0xA4);
			lcd_write_reg(0xD524,0x02);
			lcd_write_reg(0xD525,0xB7);
			lcd_write_reg(0xD526,0x02);
			lcd_write_reg(0xD527,0xCF);
			lcd_write_reg(0xD528,0x02);
			lcd_write_reg(0xD529,0xDE);
			lcd_write_reg(0xD52A,0x02);
			lcd_write_reg(0xD52B,0xF2);
			lcd_write_reg(0xD52C,0x02);
			lcd_write_reg(0xD52D,0xFE);
			lcd_write_reg(0xD52E,0x03);
			lcd_write_reg(0xD52F,0x10);
			lcd_write_reg(0xD530,0x03);
			lcd_write_reg(0xD531,0x33);
			lcd_write_reg(0xD532,0x03);
			lcd_write_reg(0xD533,0x6D);
			lcd_write_reg(0xD600,0x00);
			lcd_write_reg(0xD601,0x33);
			lcd_write_reg(0xD602,0x00);
			lcd_write_reg(0xD603,0x34);
			lcd_write_reg(0xD604,0x00);
			lcd_write_reg(0xD605,0x3A);
			lcd_write_reg(0xD606,0x00);
			lcd_write_reg(0xD607,0x4A);
			lcd_write_reg(0xD608,0x00);
			lcd_write_reg(0xD609,0x5C);
			lcd_write_reg(0xD60A,0x00);
			lcd_write_reg(0xD60B,0x81);

			lcd_write_reg(0xD60C,0x00);
			lcd_write_reg(0xD60D,0xA6);
			lcd_write_reg(0xD60E,0x00);
			lcd_write_reg(0xD60F,0xE5);
			lcd_write_reg(0xD610,0x01);
			lcd_write_reg(0xD611,0x13);
			lcd_write_reg(0xD612,0x01);
			lcd_write_reg(0xD613,0x54);
			lcd_write_reg(0xD614,0x01);
			lcd_write_reg(0xD615,0x82);
			lcd_write_reg(0xD616,0x01);
			lcd_write_reg(0xD617,0xCA);
			lcd_write_reg(0xD618,0x02);
			lcd_write_reg(0xD619,0x00);
			lcd_write_reg(0xD61A,0x02);
			lcd_write_reg(0xD61B,0x01);
			lcd_write_reg(0xD61C,0x02);
			lcd_write_reg(0xD61D,0x34);
			lcd_write_reg(0xD61E,0x02);
			lcd_write_reg(0xD61F,0x67);
			lcd_write_reg(0xD620,0x02);
			lcd_write_reg(0xD621,0x84);
			lcd_write_reg(0xD622,0x02);
			lcd_write_reg(0xD623,0xA4);
			lcd_write_reg(0xD624,0x02);
			lcd_write_reg(0xD625,0xB7);
			lcd_write_reg(0xD626,0x02);
			lcd_write_reg(0xD627,0xCF);
			lcd_write_reg(0xD628,0x02);
			lcd_write_reg(0xD629,0xDE);
			lcd_write_reg(0xD62A,0x02);
			lcd_write_reg(0xD62B,0xF2);
			lcd_write_reg(0xD62C,0x02);
			lcd_write_reg(0xD62D,0xFE);
			lcd_write_reg(0xD62E,0x03);
			lcd_write_reg(0xD62F,0x10);
			lcd_write_reg(0xD630,0x03);
			lcd_write_reg(0xD631,0x33);
			lcd_write_reg(0xD632,0x03);
			lcd_write_reg(0xD633,0x6D);
			//LV2 Page 0 enable
			lcd_write_reg(0xF000,0x55);
			lcd_write_reg(0xF001,0xAA);
			lcd_write_reg(0xF002,0x52);
			lcd_write_reg(0xF003,0x08);
			lcd_write_reg(0xF004,0x00);
			//Display control
			lcd_write_reg(0xB100, 0xCC);
			lcd_write_reg(0xB101, 0x00);
			//Source hold time
			lcd_write_reg(0xB600,0x05);
			//Gate EQ control
			lcd_write_reg(0xB700,0x70);
			lcd_write_reg(0xB701,0x70);
			//Source EQ control (Mode 2)
			lcd_write_reg(0xB800,0x01);
			lcd_write_reg(0xB801,0x03);
			lcd_write_reg(0xB802,0x03);
			lcd_write_reg(0xB803,0x03);
			//Inversion mode (2-dot)
			lcd_write_reg(0xBC00,0x02);
			lcd_write_reg(0xBC01,0x00);
			lcd_write_reg(0xBC02,0x00);
			//Timing control 4H w/ 4-delay
			lcd_write_reg(0xC900,0xD0);
			lcd_write_reg(0xC901,0x02);
			lcd_write_reg(0xC902,0x50);
			lcd_write_reg(0xC903,0x50);
			lcd_write_reg(0xC904,0x50);
			lcd_write_reg(0x3500,0x00);
			lcd_write_reg(0x3A00,0x55);  //16-bit/pixel
			lcd_wr_reg(0x1100);

    HAL_Delay(120);
    lcd_wr_reg(0x2900);
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
    lcddev.setxcmd = xpos;
    lcddev.setycmd = ypos;
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
