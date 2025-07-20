/*****************************************************************************
* | File        :   lcd_2in8.c
* | Author      :   Waveshare team
* | Function    :   2.9inch e-paper V2 test demo
* | Info        :
*----------------
* |	This version:   V1.0
* | Date        :   2021-01-20
* | Info        :
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/
#include "main.h"
#include "LCD_Driver.h"
#include "LCD_Touch.h"
#include "LCD_GUI.h"
#include "LCD_Bmp.h"
#include "DEV_Config.h"
#include <stdio.h>
#include "hardware/watchdog.h"
#include "pico/stdlib.h"

extern LCD_DIS sLCD_DIS;

int lcd_test(void)
{
  printf("hello...\n");
  uint8_t counter = 0;

  System_Init();
  SD_Init();

  // down-to-up, left-to-right
  LCD_SCAN_DIR  lcd_scan_dir = D2U_L2R; // default: SCAN_DIR_DFT;

  // (scan direction, backlight brightness)
  LCD_Init(lcd_scan_dir,800);

  // Touch initialization
  TP_Init(lcd_scan_dir);

  while (1) {
    GUI_Show();
    Driver_Delay_ms(1000);
  }

  GUI_DrawRectangle(sLCD_DIS.LCD_Dis_Column - 30, 20,
                    sLCD_DIS.LCD_Dis_Column, 50,
                    BLUE, DRAW_FULL, DOT_PIXEL_1X1);

  return 0;

  LCD_Show_bmp(lcd_scan_dir);
  Driver_Delay_ms(2000);

  TP_GetAdFac();
  //TP_Dialog(lcd_scan_dir);
  while(1){
    TP_DrawBoard(lcd_scan_dir);
  }

  return 0;
}
