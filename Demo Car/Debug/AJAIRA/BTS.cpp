/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"
# include "gl.h"



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
Back back1;
typedef struct Truck Truck;
struct Truck
{
	int x;
	int y;
};
 Truck truck; 
 char back[2][20] = {"AJAIRA\\Road.bmp","AJAIRA\\Road.bmp"};
 int i;
void iDraw()
{
	//place your drawing codes here	
	iClear();
	// background Moving
	for(i=0;i<2;i++)
	{
		iShowBMP(back1.x,0,back[i]);
	}
	iShowBMP2(truck.x,truck.y,"AJAIRA\\Truck.bmp",0);
}

/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
/*
background Moving code. Aidik akta jhamela hoise jeta ami thik korte partesi na. sesh houar por black screen aya then abar start hoy.code on korlei bujhte parbi
*/
void bcChange()
{
	for(i=0;i<2;i++)
	{
		back1.x = back1.x-10;
		if(back1.x<=0)
		{
			back1.x = 800 ;
		}
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
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
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
		truck.x = 0;
		truck.y = 320;
	}
	else if(key == GLUT_KEY_DOWN)
	{
		truck.x = 0;
		truck.y = 200;
	}
	else if(key == GLUT_KEY_RIGHT)
	{
		truck.x = 100;
		truck.y = 300 ;

	}
	
	//place your codes for other keys here
}


int main()
{
	//place your own initialization codes here. 
	iSetTimer(200,bcChange);
	iInitialize(800,600, "BTS");
	return 0;
}	