
 /* @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, QD electronic SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
**************************************************************************************************/		
#include "touch.h" 
#include "lcd.h"
#include "tim.h"
#include "stdlib.h"
#include "math.h"
#include "gui.h"	    
//#include "test.h"

_m_tp_dev tp_dev=
{
	tp_init,
	tp_scan,
	tp_adjust,
	0,
	0,
 	0,
	0,
	0,
	0,
	0,
	0,	  	 		
	0,
	0,	  	 		
};					
//Ĭ��Ϊtouchtype=0������.
uint8_t CMD_RDX=0XD0;
uint8_t CMD_RDY=0X90;

/*****************************************************************************
 * @name       :void tp_write_byte(uint8_t num)   
 * @date       :
 * @function   :Write a byte data to the touch screen IC with SPI bus
 * @parameters :num:Data to be written
 * @retvalue   :None
******************************************************************************/  	 			    					   
void tp_write_byte(uint8_t num)    
{  
	uint8_t count=0;   
	for(count=0;count<8;count++)  
	{ 	  
		if(num&0x80)TDIN_H();
		else TDIN_L();
		num<<=1;
		TCLK_L();
		TCLK_H();		//��������Ч	        
	}
}

/*****************************************************************************
 * @name       :uint16_t tp_read_ad(uint8_t CMD)	  
 * @date       :
 * @function   :Reading adc values from touch screen IC with SPI bus
 * @parameters :CMD:Read command,0xD0 for x,0x90 for y
 * @retvalue   :Read data
******************************************************************************/    
uint16_t tp_read_ad(uint8_t CMD)	  
{ 	 
	uint8_t count=0; 	  
	uint16_t Num=0; 
	TCLK_L();		//������ʱ�� 	 
	TDIN_L(); 	//����������
	TCS_L(); 		//ѡ�д�����IC
	tp_write_byte(CMD);//����������
	delay_us(6);//ADS7846��ת��ʱ���Ϊ6us
	TCLK_L();
	delay_us(1);    	   
	TCLK_H();		//��1��ʱ�ӣ����BUSY
	TCLK_L();
	for(count=0;count<16;count++)//����16λ����,ֻ�и�12λ��Ч 
	{ 				  
		Num<<=1; 	 
		TCLK_L();	//�½�����Ч  	 
		TCLK_H();
		if(DOUT)Num++; 		 
	}  	
	Num>>=4;   	//ֻ�и�12λ��Ч.
	TCS_H();		//�ͷ�Ƭѡ	 
	return(Num);  

}

#define READ_TIMES 5 	//��ȡ����
#define LOST_VAL 1	  	//����ֵ
/*****************************************************************************
 * @name       :uint16_t tp_read_xoy(uint8_t xy)  
 * @date       :
 * @function   :Read the touch screen coordinates (x or y),
								Read the READ_TIMES secondary data in succession 
								and sort the data in ascending order,
								Then remove the lowest and highest number of LOST_VAL 
								and take the average
 * @parameters :xy:Read command(CMD_RDX/CMD_RDY)
 * @retvalue   :Read data
******************************************************************************/  
uint16_t tp_read_xoy(uint8_t xy)
{
	uint16_t i, j;
	uint16_t buf[READ_TIMES];
	uint16_t sum=0;
	uint16_t temp;
	for(i=0;i<READ_TIMES;i++)buf[i]=tp_read_ad(xy);		 		    
	for(i=0;i<READ_TIMES-1; i++)//����
	{
		for(j=i+1;j<READ_TIMES;j++)
		{
			if(buf[i]>buf[j])//��������
			{
				temp=buf[i];
				buf[i]=buf[j];
				buf[j]=temp;
			}
		}
	}	  
	sum=0;
	for(i=LOST_VAL;i<READ_TIMES-LOST_VAL;i++)sum+=buf[i];
	temp=sum/(READ_TIMES-2*LOST_VAL);
	return temp;   
} 

/*****************************************************************************
 * @name       :uint8_t tp_read_xy(uint16_t *x,uint16_t *y)
 * @date       :
 * @function   :Read touch screen x and y coordinates,
								The minimum value can not be less than 100
 * @parameters :x:Read x coordinate of the touch screen
								y:Read y coordinate of the touch screen
 * @retvalue   :0-fail,1-success
******************************************************************************/ 
uint8_t tp_read_xy(uint16_t *x,uint16_t *y)
{
	uint16_t xtemp,ytemp;			 	 		  
	xtemp=tp_read_xoy(CMD_RDX);
	ytemp=tp_read_xoy(CMD_RDY);	  												   
	//if(xtemp<100||ytemp<100)return 0;//����ʧ��
	*x=xtemp;
	*y=ytemp;
	return 1;//�����ɹ�
}

#define ERR_RANGE 50 //��Χ 
/*****************************************************************************
 * @name       :uint8_t TP_Read_XY2(uint16_t *x,uint16_t *y) 
 * @date       :
 * @function   :Read the touch screen coordinates twice in a row, 
								and the deviation of these two times can not exceed ERR_RANGE, 
								satisfy the condition, then think the reading is correct, 
								otherwise the reading is wrong.
								This function can greatly improve the accuracy.
 * @parameters :x:Read x coordinate of the touch screen
								y:Read y coordinate of the touch screen
 * @retvalue   :0-fail,1-success
******************************************************************************/ 
uint8_t tp_read_xy2(uint16_t *x,uint16_t *y) 
{
	uint16_t x1,y1;
 	uint16_t x2,y2;
 	uint8_t flag;    
    flag=tp_read_xy(&x1,&y1);   
    if(flag==0)return(0);
    flag=tp_read_xy(&x2,&y2);	   
    if(flag==0)return(0);   
    if(((x2<=x1&&x1<x2+ERR_RANGE)||(x1<=x2&&x2<x1+ERR_RANGE))//ǰ�����β�����+-50��
    &&((y2<=y1&&y1<y2+ERR_RANGE)||(y1<=y2&&y2<y1+ERR_RANGE)))
    {
        *x=(x1+x2)/2;
        *y=(y1+y2)/2;
        return 1;
    }else return 0;	  
} 

/*****************************************************************************
 * @name       :void tp_drow_touch_point(uint16_t x,uint16_t y,uint16_t color)
 * @date       :
 * @function   :Draw a touch point,Used to calibrate							
 * @parameters :x:Read x coordinate of the touch screen
								y:Read y coordinate of the touch screen
								color:the color value of the touch point
 * @retvalue   :None
******************************************************************************/  
void tp_drow_touch_point(uint16_t x,uint16_t y,uint16_t color)
{
	POINT_COLOR=color;
	lcd_drawline(x-12,y,x+13,y);//����
	lcd_drawline(x,y-12,x,y+13);//����
	lcd_drawpoint(x+1,y+1);
	lcd_drawpoint(x-1,y+1);
	lcd_drawpoint(x+1,y-1);
	lcd_drawpoint(x-1,y-1);
	gui_circle(x,y,POINT_COLOR,6,0);//������Ȧ
}	

/*****************************************************************************
 * @name       :void tp_draw_big_point(uint16_t x,uint16_t y,uint16_t color)
 * @date       :
 * @function   :Draw a big point(2*2)					
 * @parameters :x:Read x coordinate of the point
								y:Read y coordinate of the point
								color:the color value of the point
 * @retvalue   :None
******************************************************************************/   
void tp_draw_big_point(uint16_t x,uint16_t y,uint16_t color)
{	    
	POINT_COLOR=color;
	lcd_drawpoint(x,y);//���ĵ� 
	lcd_drawpoint(x+1,y);
	lcd_drawpoint(x,y+1);
	lcd_drawpoint(x+1,y+1);	 	  	
}	

/*****************************************************************************
 * @name       :uint8_t tp_scan(uint8_t tp)
 * @date       :
 * @function   :Scanning touch event				
 * @parameters :tp:0-screen coordinate 
									 1-Physical coordinates(For special occasions such as calibration)
 * @retvalue   :Current touch screen status,
								0-no touch
								1-touch
******************************************************************************/  					  
uint8_t tp_scan(uint8_t tp)
{			   
	if(PEN==0)//�а�������
	{
		if(tp)tp_read_xy2(&tp_dev.x,&tp_dev.y);//��ȡ��������
		else if(tp_read_xy2(&tp_dev.x,&tp_dev.y))//��ȡ��Ļ����
		{
	 		tp_dev.x=tp_dev.xfac*tp_dev.x+tp_dev.xoff;//�����ת��Ϊ��Ļ����
			tp_dev.y=tp_dev.yfac*tp_dev.y+tp_dev.yoff;  
	 	} 
		if((tp_dev.sta&TP_PRES_DOWN)==0)//֮ǰû�б�����
		{		 
			tp_dev.sta=TP_PRES_DOWN|TP_CATH_PRES;//��������  
			tp_dev.x0=tp_dev.x;//��¼��һ�ΰ���ʱ������
			tp_dev.y0=tp_dev.y;  	   			 
		}			   
	}else
	{
		if(tp_dev.sta&TP_PRES_DOWN)//֮ǰ�Ǳ����µ�
		{
			tp_dev.sta&=~(1<<7);//��ǰ����ɿ�	
		}else//֮ǰ��û�б�����
		{
			tp_dev.x0=0;
			tp_dev.y0=0;
			tp_dev.x=0xffff;
			tp_dev.y=0xffff;
		}	    
	}
	return tp_dev.sta&TP_PRES_DOWN;//���ص�ǰ�Ĵ���״̬
}

//��ʾ�ַ���
const char* TP_REMIND_MSG_TBL="Please use the stylus click the cross on the screen.The cross will always move until the screen adjustment is completed.";

/*****************************************************************************
 * @name       :void tp_adj_info_show(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t x3,uint16_t y3,uint16_t fac)
 * @date       :
 * @function   :Display calibration results	
 * @parameters :x0:the x coordinates of first calibration point
								y0:the y coordinates of first calibration point
								x1:the x coordinates of second calibration point
								y1:the y coordinates of second calibration point
								x2:the x coordinates of third calibration point
								y2:the y coordinates of third calibration point
								x3:the x coordinates of fourth calibration point
								y3:the y coordinates of fourth calibration point
								fac:calibration factor 
 * @retvalue   :None
******************************************************************************/ 	 					  
void tp_adj_info_show(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t x3,uint16_t y3,uint16_t fac)
{	  
	POINT_COLOR=RED;
	lcd_showstring(40,140,16,(uint8_t *)"x1:",1);
 	lcd_showstring(40+80,140,16,(uint8_t *)"y1:",1);
 	lcd_showstring(40,160,16,(uint8_t *)"x2:",1);
 	lcd_showstring(40+80,160, 16,(uint8_t *)"y2:",1);
	lcd_showstring(40,180, 16,(uint8_t *)"x3:",1);
 	lcd_showstring(40+80,180, 16,(uint8_t *)"y3:",1);
	lcd_showstring(40,200, 16,(uint8_t *)"x4:",1);
 	lcd_showstring(40+80,200, 16,(uint8_t *)"y4:",1);  
 	lcd_showstring(40,220, 16,(uint8_t *)"fac is:",1);     
	lcd_shownum(40+24,140,x0,4,16);		//��ʾ��ֵ
	lcd_shownum(40+24+80,140,y0,4,16);	//��ʾ��ֵ
	lcd_shownum(40+24,160,x1,4,16);		//��ʾ��ֵ
	lcd_shownum(40+24+80,160,y1,4,16);	//��ʾ��ֵ
	lcd_shownum(40+24,180,x2,4,16);		//��ʾ��ֵ
	lcd_shownum(40+24+80,180,y2,4,16);	//��ʾ��ֵ
	lcd_shownum(40+24,200,x3,4,16);		//��ʾ��ֵ
	lcd_shownum(40+24+80,200,y3,4,16);	//��ʾ��ֵ
 	lcd_shownum(40+56,220,fac,3,16); 	//��ʾ��ֵ,����ֵ������95~105��Χ֮��.
}

/*****************************************************************************
 * @name       :uint8_t tp_get_adjdata(void)
 * @date       :
 * @function   :Calibration touch screen and Get 4 calibration parameters
 * @parameters :None
 * @retvalue   :None
******************************************************************************/ 		 
void tp_adjust(void)
{								 
	uint16_t pos_temp[4][2];//���껺��ֵ
	uint8_t  cnt=0;	
	uint16_t d1,d2;
	uint32_t tem1,tem2;
	float fac; 	
	uint16_t outtime=0;
 	cnt=0;				
	POINT_COLOR=BLUE;
	BACK_COLOR =WHITE;
	lcd_clear(WHITE);//����   
	POINT_COLOR=RED;//��ɫ 
	lcd_clear(WHITE);//���� 	   
	POINT_COLOR=BLACK;
	lcd_showstring(10,40,16,(uint8_t *)"Please use the stylus click",1);//��ʾ��ʾ��Ϣ
	lcd_showstring(10,56,16,(uint8_t *)"the cross on the screen.",1);//��ʾ��ʾ��Ϣ
	lcd_showstring(10,72,16,(uint8_t *)"The cross will always move",1);//��ʾ��ʾ��Ϣ
	lcd_showstring(10,88,16,(uint8_t *)"until the screen adjustment",1);//��ʾ��ʾ��Ϣ
  lcd_showstring(10,104,16,(uint8_t *)"is completed.",1);//��ʾ��ʾ��Ϣ
	 
	tp_drow_touch_point(20,20,RED);//����1 
	tp_dev.sta=0;//���������ź� 
	tp_dev.xfac=0;//xfac��������Ƿ�У׼��,����У׼֮ǰ�������!�������	 
	while(1)//�������10����û�а���,���Զ��˳�
	{
		tp_dev.scan(1);//ɨ����������
		if((tp_dev.sta&0xc0)==TP_CATH_PRES)//����������һ��(��ʱ�����ɿ���.)
		{	
			outtime=0;		
			tp_dev.sta&=~(1<<6);//��ǰ����Ѿ����������.
						   			   
			pos_temp[cnt][0]=tp_dev.x;
			pos_temp[cnt][1]=tp_dev.y;
			cnt++;	  
			switch(cnt)
			{			   
				case 1:						 
					tp_drow_touch_point(20,20,WHITE);				//�����1 
					tp_drow_touch_point(lcddev.width-20,20,RED);	//����2
					break;
				case 2:
 					tp_drow_touch_point(lcddev.width-20,20,WHITE);	//�����2
					tp_drow_touch_point(20,lcddev.height-20,RED);	//����3
					break;
				case 3:
 					tp_drow_touch_point(20,lcddev.height-20,WHITE);			//�����3
 					tp_drow_touch_point(lcddev.width-20,lcddev.height-20,RED);	//����4
					break;
				case 4:	 //ȫ���ĸ����Ѿ��õ�
	    		    //�Ա����
					tem1=abs(pos_temp[0][0]-pos_temp[1][0]);//x1-x2
					tem2=abs(pos_temp[0][1]-pos_temp[1][1]);//y1-y2
					tem1*=tem1;
					tem2*=tem2;
					d1=sqrt(tem1+tem2);//�õ�1,2�ľ���
					
					tem1=abs(pos_temp[2][0]-pos_temp[3][0]);//x3-x4
					tem2=abs(pos_temp[2][1]-pos_temp[3][1]);//y3-y4
					tem1*=tem1;
					tem2*=tem2;
					d2=sqrt(tem1+tem2);//�õ�3,4�ľ���
					fac=(float)d1/d2;
					if(fac<0.95||fac>1.05||d1==0||d2==0)//���ϸ�
					{
						cnt=0;
 				    	tp_drow_touch_point(lcddev.width-20,lcddev.height-20,WHITE);	//�����4
   	 					tp_drow_touch_point(20,20,RED);								//����1
 						tp_adj_info_show(pos_temp[0][0],pos_temp[0][1],pos_temp[1][0],pos_temp[1][1],pos_temp[2][0],pos_temp[2][1],pos_temp[3][0],pos_temp[3][1],fac*100);//��ʾ����   
 						continue;
					}
					tem1=abs(pos_temp[0][0]-pos_temp[2][0]);//x1-x3
					tem2=abs(pos_temp[0][1]-pos_temp[2][1]);//y1-y3
					tem1*=tem1;
					tem2*=tem2;
					d1=sqrt(tem1+tem2);//�õ�1,3�ľ���
					
					tem1=abs(pos_temp[1][0]-pos_temp[3][0]);//x2-x4
					tem2=abs(pos_temp[1][1]-pos_temp[3][1]);//y2-y4
					tem1*=tem1;
					tem2*=tem2;
					d2=sqrt(tem1+tem2);//�õ�2,4�ľ���
					fac=(float)d1/d2;
					if(fac<0.95||fac>1.05)//���ϸ�
					{
						cnt=0;
 				    	tp_drow_touch_point(lcddev.width-20,lcddev.height-20,WHITE);	//�����4
   	 					tp_drow_touch_point(20,20,RED);								//����1
 						tp_adj_info_show(pos_temp[0][0],pos_temp[0][1],pos_temp[1][0],pos_temp[1][1],pos_temp[2][0],pos_temp[2][1],pos_temp[3][0],pos_temp[3][1],fac*100);//��ʾ����   
						continue;
					}//��ȷ��
								   
					//�Խ������
					tem1=abs(pos_temp[1][0]-pos_temp[2][0]);//x1-x3
					tem2=abs(pos_temp[1][1]-pos_temp[2][1]);//y1-y3
					tem1*=tem1;
					tem2*=tem2;
					d1=sqrt(tem1+tem2);//�õ�1,4�ľ���
	
					tem1=abs(pos_temp[0][0]-pos_temp[3][0]);//x2-x4
					tem2=abs(pos_temp[0][1]-pos_temp[3][1]);//y2-y4
					tem1*=tem1;
					tem2*=tem2;
					d2=sqrt(tem1+tem2);//�õ�2,3�ľ���
					fac=(float)d1/d2;
					if(fac<0.95||fac>1.05)//���ϸ�
					{
						cnt=0;
 				    	tp_drow_touch_point(lcddev.width-20,lcddev.height-20,WHITE);	//�����4
   	 					tp_drow_touch_point(20,20,RED);								//����1
 						tp_adj_info_show(pos_temp[0][0],pos_temp[0][1],pos_temp[1][0],pos_temp[1][1],pos_temp[2][0],pos_temp[2][1],pos_temp[3][0],pos_temp[3][1],fac*100);//��ʾ����   
						continue;
					}//��ȷ��
					//������
					tp_dev.xfac=(float)(lcddev.width-40)/(pos_temp[1][0]-pos_temp[0][0]);//�õ�xfac		 
					tp_dev.xoff=(lcddev.width-tp_dev.xfac*(pos_temp[1][0]+pos_temp[0][0]))/2;//�õ�xoff
						  
					tp_dev.yfac=(float)(lcddev.height-40)/(pos_temp[2][1]-pos_temp[0][1]);//�õ�yfac
					tp_dev.yoff=(lcddev.height-tp_dev.yfac*(pos_temp[2][1]+pos_temp[0][1]))/2;//�õ�yoff  
					if(abs(tp_dev.xfac)>2||abs(tp_dev.yfac)>2)//������Ԥ����෴��.
					{
						cnt=0;
 				    	tp_drow_touch_point(lcddev.width-20,lcddev.height-20,WHITE);	//�����4
   	 					tp_drow_touch_point(20,20,RED);								//����1
						lcd_showstring(40,26, 16,(uint8_t *)"TP Need readjust!",1);
						tp_dev.touchtype=!tp_dev.touchtype;//�޸Ĵ�������.
						if(tp_dev.touchtype)//X,Y��������Ļ�෴
						{
							CMD_RDX=0X90;
							CMD_RDY=0XD0;	 
						}else				   //X,Y��������Ļ��ͬ
						{
							CMD_RDX=0XD0;
							CMD_RDY=0X90;	 
						}			    
						continue;
					}		
					POINT_COLOR=BLUE;
					lcd_clear(WHITE);//����
					lcd_showstring(35,110, 16,(uint8_t *)"Touch Screen Adjust OK!",1);//У�����
					HAL_Delay(1000);
 					lcd_clear(WHITE);//����   
					return;//У�����				 
			}
		}
		HAL_Delay(10);
		outtime++;
		if(outtime>1000)
		{
			break;
	 	} 
 	}
}		

/*****************************************************************************
 * @name       :uint8_t tp_init(void)
 * @date       :
 * @function   :Initialization touch screen
 * @parameters :None
 * @retvalue   :0-no calibration
								1-Has been calibrated
******************************************************************************/  
uint8_t tp_init(void)
{
	tp_read_xy(&tp_dev.x,&tp_dev.y);//��һ�ζ�ȡ��ʼ��	 											
	lcd_clear(WHITE);//����
	tp_adjust();  //��ĻУ׼
	return 1; 									 
}

