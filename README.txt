Сконфигурировано через CubeMX.
Среда разработки - CubeIDE.

Настройка FMC ног через CMSIS в nt35510.c - HAL_SRAM_MSPInit();

Настройка подсветки (BL/LED) + RST в nt35510.c - LCD_GPIOInit();

Контроллер (STM32H750VB) - https://www.st.com/resource/en/datasheet/stm32h750vb.pdf
Дисплей - http://www.lcdwiki.com/3.97inch_16BIT_Module_NT35510_SKU:MRB3973

Физически подключенные ноги (LCD [альтернативные названия] - MCU) по FMC RGB565:
DB0                 -   PD14
DB1                 -   PD15
DB2                 -   PD0
DB3                 -   PD1
DB4                 -   PE7
DB5                 -   PE8
DB6                 -   PE9
DB7                 -   PE10
DB8                 -   PE11
DB9                 -   PE12
DB10                -   PE13
DB11                -   PE14
DB12                -   PE15
DB13                -   PD8
DB14                -   PD9
DB15                -   PD10
CS                  -   PC7
RS                  -   PD11
WR                  -   PD5
RD                  -   PD4
RST                 -   PD12
BL [LED]            -   PC10
MISO [TDOUT, DOUT]  -   PB14
MOSI [TDIN, DIN]    -   PB15
PEN [INT, TINT]     -   PD13
CLK [TCLK, SCLK]    -   PB10
T_CS                -   PB11
