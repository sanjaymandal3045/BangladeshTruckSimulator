/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"
#include "bitmap_loader.h"

int x = 300, y = 300, r = 20,index=0,mmX=0,mmY=0;
int rx=0,ry=0;
int posX=500,posY=6;
//char ro[2][20]={"Cars\\road1.bmp","Cars\\road2.bmp"};
char mm[6][20]={"Cars\\new men.bmp","Cars\\menu in.bmp","Cars\\roadOp.bmp","Cars\\intro.bmp"};
char back[16][50] = {"SIM\\re1.bmp","SIM\\re2.bmp","SIM\\re3.bmp","SIM\\re4.bmp","SIM\\re5.bmp","SIM\\re6.bmp","SIM\\re7.bmp","SIM\\re8.bmp","SIM\\re9.bmp","SIM\\re10.bmp","SIM\\re11.bmp","SIM\\re12.bmp","SIM\\re13.bmp","SIM\\re14.bmp","SIM\\re15.bmp","SIM\\re16.bmp"};
char buck[2][50]={"SIM\\ro1.bmp","SIM\\ro2.bmp"};

/*
	function iDraw() is called again and again by the system.
*/
/*structure code of the background */
typedef struct Back Back;
struct Back
{
	int x;
	int y;
};
Back back1[2];
typedef struct Truck Truck;
struct Truck
{
	int x;
	int y;
};
 Truck truck;

 int i;
void iDraw()
{
	//place your drawing codes here
	iClear();
	iShowBMP(0,0,mm[index]);
	if(index==2){
		for(i=0;i<16;i++)//ei block ta pic er slice gula ek kore
		{
			iShowBMP(back1[i].x,back1[i].y,back[i]);
			iShowBMP2(truck.x,truck.y,"AJAIRA\\Truck.bmp",0);
		}
	}
	//iShowBMP2(truck.x,truck.y,"SIM\\Truck.bmp",0);
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
/*
background Moving code. Aidik akta jhamela hoise jeta ami thik korte partesi na. sesh houar por black screen aya then abar start hoy.code on korlei bujhte parbi
*/
//ei function ta still image banay.main functin e iSetTimer ta comment out kore test kor
void bcChange()
{
	int j=0;
	for(i=0;i<16;i++)
	{
		back1[i].x=j;
		back1[i].y=0;
		j+=50;
	}

}


void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		printf("x=%d,y=%d ",mx,my);//this will show coordinate points when u click
		if(index==1){
			
			if((mx>=100 && mx<=324) && (my>=838 && my<=861))
			{
				index=2;
			}
			
			if((mx>=1050 && mx<=1080) && (my>=27 && my<=66))
			{
				exit(0);
			}
			if((mx>=461 && mx<=690) && (my>=834 && my<=858))
			{
				index=3;
			}
		}
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
	printf("%d %d\n",mx,my);
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		//do something with 'q'
		iPauseTimer(0);
	}
	if(key == 'r')
	{
		iResumeTimer(0);
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_UP)
	{
		truck.x = truck.x+35;
		truck.y = truck.y+70;
	}
	else if(key == GLUT_KEY_DOWN)
	{
		truck.x = truck.x-35;
		truck.y = truck.y-70;
	}
	else if(key == GLUT_KEY_RIGHT)
	{
		truck.x = truck.x+20;
		truck.y = truck.y;
	}
	else if(key == GLUT_KEY_LEFT)
	{
		truck.x = truck.x-20;
		truck.y = truck.y;
	}


	//place your codes for other keys here
}
/*void TruckChangeY()
{
	if(truck.y<=0)
	{
		truck.y = 0 ;
	}
	else if(truck.y>= 397)
	{
		truck.y = 397 ;
	}
}
void TruckChangeX()
{

	if(truck.x<=0)
	{
		truck.x = 0 ;
	}
	else if(truck.x>=700)
	{
		truck.x = 700 ;
	}
}*/
//ei function tai mainly background take move kortese.youtube e ig tutorial e video ase shob explain kora
void change()
{
	for(i=0;i<16;i++)
	{
		back1[i].x-=50;//because the pictures are 50x600 pixel
		if(back1[i].x<=0)
		{
			back1[i].x=650;//ekhane 650  dile pic er majhe kalo spot dekha jai na. variable change kore test kor
		}
	}
}


int main()
{
	truck.x=0;
	truck.y=0;
	bcChange();
	/*iSetTimer(50,TruckChangeY);
	iSetTimer(50,TruckChangeX);*/
	//place your own initialization codes here.
	iSetTimer(100,change);
	iInitialize(800,600, "BTS");
	return 0;
}
