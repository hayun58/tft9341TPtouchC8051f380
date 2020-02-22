
/*  last update 21/02/2020 */
/*  Avi Hayun */

#include "compiler_defs.h"
#include "C8051F380_defs.h"
#include "initavi.h"
#include "pic.h"

void Init_Device(void);
void initAVI(void);

void Test_Color(void);
void MenuScreen();
void Font_test(void);
void Pic_test(void);
void Test_shape(void);

void main(void)
{
	S16 x=0, y=0,  ButtonNum;

	Init_Device();
	initAVI();
	LCD_setRotation(0);
	LCD_fillScreen(BLACK);
	TouchSet(293, 3725, 3891, 306);

	MenuScreen();

	while(1) {
		if(!T_IRQ) {
			delay_ms(10);
			x = ReadTouchX();
			y = ReadTouchY();
			LCD_setCursor (25, 100);
			ButtonNum= ButtonTouch(x, y);
			printf("x=%d y=%d  b=%d   ", x, y,ButtonNum);

			if(ButtonNum==1){  
				Test_Color();
				MenuScreen();
			}
			else if(ButtonNum==2){ 
				Font_test();
				MenuScreen();
			}
			else if(ButtonNum==3){
				Pic_test();
				MenuScreen();				
			}
			else if(ButtonNum==4) {
				Test_shape();
				MenuScreen();
			}
		}	
	}
}

void MenuScreen() {
	LCD_fillScreen(BLACK);
	LCD_printHebCenter(0, 10,"תוכנית דוגמא" , 4,RED, BLACK);
	LCD_printHebCenter (0 ,50 ,"אבי חיון",3, WHITE, BLACK);  //hebrew		
	LCD_drawButton(1,10,  150,60,60, 10, RED,WHITE,"Color",1);
	LCD_drawButton(2,80, 150,60,60, 10, BLUE,YELLOW,"Text",2);
	LCD_drawButton(3,150, 150,60,60, 10, GREEN,BLACK,"Picture",1);
	LCD_drawButton(4,220, 150,60,60, 10, YELLOW,BLACK,"Shape",2);
	LCD_setText2Color(WHITE,BLACK);
}

void Test_Color(void) {
	LCD_fillScreen(RED);
	delay_ms(1000);
	LCD_fillScreen(GREEN);
	delay_ms(1000);	
	LCD_fillScreen(BLUE);
	delay_ms(1000);
	LCD_fillScreen(BLACK);
}

void Font_test(void) {
	int x=1234;
	LCD_fillScreen(BLACK);
	LCD_print2C(20,30,"abcd",1,WHITE,BLACK);
	LCD_print2C(80,30,"xyz",2,WHITE,BLACK);
	LCD_printC(20,60,"3.95' ILI9488 320X480",3,YELLOW);
	LCD_printC(20,120,"Test 2017-11-23",3,GREEN);
	LCD_println("");
	LCD_setTextSize(2);
	LCD_setText1Color(WHITE);
	LCD_println("ABCDabcd1234");
	LCD_println("~!@#$%^&*()_+{}:<>?/|-+.");
	LCD_setTextSize(2);
	LCD_setText1Color(YELLOW);
	LCD_printHebln("אבגדהוזחטיכלמנסעפצקרשת");
	LCD_println("ABCDE");
	printf("x=%d  ",x);
	while(T_IRQ);
}

void Pic_test(void) {
	LCD_fillScreen(BLACK);	
	LCD_DrawBitmap16(30, 30, gImage_qq);
	while(T_IRQ);
}

void Test_shape(void) {
	LCD_fillScreen(BLACK);
	LCD_drawRect(10,20,100,100,RED); 
	LCD_fillRect(50,100,80,80,BLUE); 	
	LCD_fillRoundRect(100,150,40,40,10,YELLOW); 	
	LCD_drawCircle(120,120,30,GREEN);
	LCD_fillCircle(120,120,20,WHITE);
	//LCD_drawTriangle(120,170,150,100,180,170,RED);
	LCD_fillTriangle(120,170,150,100,180,170,RED);
	while(T_IRQ);
}


