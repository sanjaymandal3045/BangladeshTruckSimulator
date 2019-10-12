# include "iGraphics.h"
# include "myheader.h"
#define ScreenWidth 1200
#define ScreenHeight 700
int Monster1_X = 20;//monster 1 speed
int Monster2_X = 10;
int Monster3_X = 20;
#define MARVELMonster1_X 20
#define MARVELMonster2_X 30
#define MARVELMonster3_X 40

int x,y,i,IREC;

int t=0;//time counting variable
char level[10];//character variable for level

char mm[6][20]={"Cars\\new men.bmp","Cars\\menu in.bmp","Cars\\blank1.bmp","Cars\\intro.bmp","Cars\\scorebrd.bmp"};
int index=0,mmX=0,mmY=0,levl,s=1;//here index changes interfaces of menu only
char Mons[5][20] = {"MON\\moj5.bmp","MON\\moj4.bmp","MON\\moj3.bmp","MON\\moj2.bmp","MON\\moj1.bmp"};
int MonsterIndex = 0 ;
char M[5][20] = {"M\\M1.bmp","M\\M2.bmp","M\\M3.bmp","M\\M4.bmp","M\\M5.bmp",};
char Zom[5][20] = {"ZOM\\Zom5.bmp","ZOM\\Zom4.bmp","ZOM\\Zom3.bmp","ZOM\\Zom2.bmp","ZOM\\Zom1.bmp"};
char TRUCK[3][20] = {"M\\Truck1.bmp","M\\Truck2.bmp","M\\Truck3.bmp"};
int MARVELMonsterindex = 0 ;
char MARVEL[7][20] = {"MARVEL\\MAR1.bmp","MARVEL\\MAR2.bmp","MARVEL\\MAR3.bmp","MARVEL\\MAR4.bmp","MARVEL\\MAR5.bmp","MARVEL\\MAR6.bmp","MARVEL\\MAR7.bmp"};
char MARVEL2[7][20] = {"MARVEL\\MARV1.bmp","MARVEL\\MARV2.bmp","MARVEL\\MARV3.bmp","MARVEL\\MARV4.bmp","MARVEL\\MARV5.bmp","MARVEL\\MARV6.bmp","MARVEL\\MARV7.bmp"};
char MARVEL3[7][20] = {"MARVEL\\MARVE1.bmp","MARVEL\\MARVE2.bmp","MARVEL\\MARVE3.bmp","MARVEL\\MARVE4.bmp","MARVEL\\MARVE5.bmp","MARVEL\\MARVE6.bmp","MARVEL\\MARVE7.bmp"};

int TRUCKIndex = 0 ;
int image1, image2, image3,image4,truckimg;
int x6,x2;

int scoree=0,bestScore,bs,sc;

char S[10],S1[10],S2[10];
typedef struct tree tree;
struct tree
{
	int imug;
	int x;
	int y;
};
tree tree1[12];

typedef struct grass Grass;
struct grass
{
	int grassimg;
	int x,y;
};
Grass grass1[12];

typedef struct Speed Speed ;
struct Speed
{
	int Position_x ;
	int Position_y ;
};
Speed Truck ;
typedef struct Monster Monster;
struct Monster
{
	int Monster_x ;
	int Monster_y ;
	bool TrueFalse ;
};
Monster monster1 ;
Monster monster2 ;
Monster monster3 ;
Monster Blood ;
Monster Fire ;
Monster Marvel1 ; 
Monster Marvel2 ;
Monster Marvel3 ;

typedef struct rstrip rstrip;
struct rstrip
{
	int image;
	int x;
};
rstrip strip[10];
int truckX,truckY;
void iDraw()
{
	

	iClear();
	iShowBMP(0,0,mm[index]);
		FILE *fp = fopen("data1.txt", "r");
		
		fscanf(fp, "%d", &bestScore);		
		sprintf(S1, "%d", bestScore);
		
		fclose(fp);



	if(index==2){
		iShowImage(0,200,1200,600,image3);// background sky
	
		iShowImage(0,300,1200,400,image4);// background hill
		for(int i=0;i<12;i++){
			iShowImage(tree1[i].x,310,300,200,tree1[i].imug); // shows the image of trees
		}
		iShowImage(0,0,1200,650,image1);// shows road
		for(int k=0;k<12;k++)
		{
			iShowImage(grass1[k].x,300,200,50,grass1[k].grassimg);	
		}
		for(int j=0;j<10;j++)
		{
			iShowImage(strip[j].x,150,100,10,strip[j].image);// changes the road strip as if its moving
		}
		iSetColor(0,255,0);
		iText(1050,650,S, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1050,600,level,GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255,0,0);
		iText(1050,625,"HEALTH",GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(0,255,0);
		iFilledRectangle(840,625,2,22);
		iFilledRectangle(840,625,190,2);
		iFilledRectangle(840,647,190,2);
		iFilledRectangle(1030,625,2,24); 
		iSetColor(255,0,0);
		iFilledRectangle(842,627,IREC,20);
		if(monster1.TrueFalse == true)
		iShowBMP2(monster1.Monster_x ,monster1.Monster_y,Mons[MonsterIndex],0);
		if(monster2.TrueFalse == true)
		iShowBMP2(monster2.Monster_x ,monster2.Monster_y,M[MonsterIndex],0);
		if(monster3.TrueFalse == true)
		iShowBMP2(monster3.Monster_x ,monster3.Monster_y,Zom[MonsterIndex],0);
		iShowBMP2(Truck.Position_x,Truck.Position_y,TRUCK[TRUCKIndex],0);
		if(Blood.TrueFalse == true)
		iShowBMP2(Blood.Monster_x ,Blood.Monster_y,"M\\Blood.bmp",0);
		if(Fire.TrueFalse == true)
		iShowBMP2(Fire.Monster_x ,Fire.Monster_y,"M\\Fire.bmp",0);
		if(Marvel1.TrueFalse == true)
		iShowBMP2(Marvel1.Monster_x,Marvel1.Monster_y, MARVEL[MARVELMonsterindex],0);
		if(Marvel2.TrueFalse == true)
		iShowBMP2(Marvel2.Monster_x,Marvel2.Monster_y, MARVEL2[MARVELMonsterindex],0);
		if(Marvel3.TrueFalse == true)
		iShowBMP2(Marvel3.Monster_x,Marvel3.Monster_y, MARVEL3[MARVELMonsterindex],0);
		if(scoree > bestScore){
		
			fp = fopen("data1.txt", "w");
		
			fprintf(fp,"%d", scoree);
			fclose(fp);
			//fprintf(fp,"%d", bestScore);
		}
		levl=s;
		sprintf(level,"Level:%d",levl);
		t++;
		if(t%6000==0)//this changes the level and zombie speed it takes 1 min 40 secs to complete a level
		{
			s++;
			Monster1_X = Monster1_X+10;
			Monster2_X = Monster2_X+10;
			Monster3_X = Monster3_X+10;
		}
	}
	if(index == 4)
	{			
		fp = fopen("data1.txt", "r");
		
		fscanf(fp, "%d", &bs);		
		sprintf(S1, "%d", bs);
		fclose(fp);
		iSetColor(0,0,0);
		iText(672,579,S2,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(672,539,S1,GLUT_BITMAP_TIMES_ROMAN_24);

	}
	
	
}

/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	
}
/*
	function iPassiveMouse() is called when the user moves the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iPassiveMouse(int mx, int my)
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
		//printf("%d\n",bestScore);
		printf("mx= %d my= %d\n",mx,my);
		printf("%d %d",bs,bestScore);
		if((mx>=28 && mx<=224) && (my>=654 && my<=682))
		{
			index=2;
		}
		if((mx>=457 && mx<=704) && (my>=654 && my<=682))
		{
			index=3;
		}
		if((mx>=961 && mx<=1170) && (my>=654 && my<=682))
		{
			index=4;
		}
		
		if((mx>=1050 && mx<=1130) && (my>=23 && my<=50))
		{
			exit(0);
		}
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if (key == 'p')
	{
		printf("time=%d\n",t);
		printf("mons=%d\n",Monster1_X);
		
	}
	if (key == 'r')
	{
		
	}
	if(key == '\r')
	{
		if(index==0){
			index=1;}
	}
	
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
	if(key == GLUT_KEY_DOWN)
	{
		Truck.Position_y = Truck.Position_y - 145 ;
		Truck.Position_x = Truck.Position_x - 50 ;
 	}
	else if(key == GLUT_KEY_UP)
	{
		Truck.Position_y = Truck.Position_y + 145 ;
		Truck.Position_x = Truck.Position_x + 50 ;
	}
	else if(key == GLUT_KEY_RIGHT)
	{
		Truck.Position_x = Truck.Position_x + 50 ;
	}
	else if(key == GLUT_KEY_LEFT)
	{
		Truck.Position_x = Truck.Position_x - 50 ;
	}
	//place your codes for other keys here
	else if(key == GLUT_KEY_END){
		index=1;
	
	}
//place your codes for other keys here
}


//Animating functions


void grass()//this sets the grass under the tree and creats still image
{
	int s=0;
	for(int i=0;i<12;i++)
	{
		grass1[i].x=s;
		s+=100;
	}
}
void grassmove()//this changes the grass under tree as if its moving
{
	for(int i=0;i<12;i++)
	{
		grass1[i].x-=10;
		if(grass1[i].x<=0)
		{
			grass1[i].x=1000;
		}
	}
}
void chen() //this changes the tree coordinates thats why its called in isettimer
{
	for(int i=0;i<12;i++){
		tree1[i].x-=10;
		if(tree1[i].x<=0)
		{
			tree1[i].x=1000;
		}
	}
}
void tra()// sets the trees line by by line and creats a still pic
{
	int t=0;
	for(int i=0;i<12;i++)
	{
		tree1[i].x=t;
		t+=100;
	}
	
}
void roadstrips()//sets the road strips and creats a still pic
{
	int f=0;
	for(int j=0;j<10;j++)
	{
		strip[j].x=f;
		f+=250;
	}
}
void roadstripschange()// this changes the roads strip coordinates thats why its called in isettimer
{
	for(int j=0;j<10;j++)
	{
		strip[j].x-=40;
		if(strip[j].x<=0)
		{
			strip[j].x=1100;
		}
	}
}
void changeTRUCKMove()
{
	TRUCKIndex++;
	if(TRUCKIndex>=2)
	{
		TRUCKIndex = 0 ;
	}
	Truck.Position_x = Truck.Position_x ;
	Truck.Position_y = Truck.Position_y ;
	if(Truck.Position_y<=0)
	{
		Truck.Position_y = 0 ;
	}
	else if(Truck.Position_y>=290)
	{
		Truck.Position_y = 290 ;
	}
	if(Truck.Position_x<=0)
	{
		Truck.Position_x = 0 ;
	}
	else if(Truck.Position_x>=944)
	{
		Truck.Position_x = 944;
	}
}
int length,length2,length3,Mlength,Mlength2,Mlength3;
void DamagingMonsters()
{
	MARVELMonsterindex++;
	if(MARVELMonsterindex>6)
	{
		MARVELMonsterindex = 0 ;
	}
	Marvel1.Monster_x = Marvel1.Monster_x - MARVELMonster1_X ;
	if(Marvel1.Monster_x <  0 || Marvel1.Monster_x == 0)
	{
		Marvel1.Monster_x = 1200 ;
	}
	Mlength = Marvel1.Monster_x - Truck.Position_x ;
	if(Mlength >= 0 && Mlength <= 160 && Marvel1.Monster_y == Truck.Position_y)
	{
		Marvel1.TrueFalse = false ;
		Fire.Monster_x = Marvel1.Monster_x ;
		Fire.Monster_y = Marvel1.Monster_y ;
		Fire.TrueFalse = true ;
		Marvel1.Monster_x = 1200 ; 
		IREC  = IREC - 18.8 ;
		if(IREC<=0 && index==2){
			index = 4 ;
		}
	}
	else
		Marvel1.TrueFalse = true ;
	Marvel2.Monster_x = Marvel2.Monster_x - MARVELMonster2_X ;
	if(Marvel2.Monster_x <  0 || Marvel2.Monster_x == 0)
	{
		Marvel2.Monster_x = 1200 ;
	}
	Mlength2 = Marvel2.Monster_x - Truck.Position_x ;
	if(Mlength2 >= 0 && Mlength2 <= 160 && Marvel2.Monster_y == Truck.Position_y)
	{
		Marvel2.TrueFalse = false ;
		Fire.Monster_x = Marvel2.Monster_x ;
		Fire.Monster_y = Marvel2.Monster_y ;
		Fire.TrueFalse = true ;
		Marvel2.Monster_x = 1200 ; 
		IREC  = IREC - 18.8 ;
		if(IREC<=0 && index==2){
			index = 4 ;
		}
	}
	else
		Marvel2.TrueFalse = true ;
		Marvel3.Monster_x = Marvel3.Monster_x - MARVELMonster3_X ;
	if(Marvel3.Monster_x <  0 || Marvel3.Monster_x == 0)
	{
		Marvel3.Monster_x = 1200 ;
	}
	Mlength3 = Marvel3.Monster_x - Truck.Position_x ;
	if(Mlength3 >= 0 && Mlength3 <= 160 && Marvel3.Monster_y == Truck.Position_y)
	{
		Marvel3.TrueFalse = false ;
		Fire.Monster_x = Marvel3.Monster_x ;
		Fire.Monster_y = Marvel3.Monster_y ;
		Fire.TrueFalse = true ;
		Marvel3.Monster_x = 1200 ; 
		IREC  = IREC - 18.8 ;
		if(IREC<=0 && index==2){
			index = 4 ;
		}
	}
	else
		Marvel3.TrueFalse = true ;
}
void changeMonsterAxisXPlusMovement123()
{
	MonsterIndex++;
	if(MonsterIndex>=4)
	{
		MonsterIndex = 0 ;
	}
	monster1.Monster_x = monster1.Monster_x - Monster1_X ;
	if(monster1.Monster_x <  0 || monster1.Monster_x == 0)
	{
		monster1.Monster_x = 1200 ;
	}
	length = monster1.Monster_x - Truck.Position_x ;
	if(length >= 0 && length <= 160 && monster1.Monster_y == Truck.Position_y)
	{
		monster1.TrueFalse = false ;
		Blood.Monster_x = monster1.Monster_x ;
		Blood.Monster_y = monster1.Monster_y ;
		Blood.TrueFalse = true ;
		monster1.Monster_x = 1200 ; 
	}
	else
		monster1.TrueFalse = true ;
	monster2.Monster_x = monster2.Monster_x - Monster2_X ;
	if(monster2.Monster_x <  0 || monster2.Monster_x == 0)
	{
		monster2.Monster_x = 1200 ;
	}
	length2 = monster2.Monster_x - Truck.Position_x ; 
	if(length2 >= 0 && length2 <= 160 && monster2.Monster_y == Truck.Position_y)
	{
		monster2.TrueFalse = false ;
		Blood.Monster_x = monster2.Monster_x ;
		Blood.Monster_y = monster2.Monster_y ;
		Blood.TrueFalse = true ;
		monster2.Monster_x = 1200 ;
	}
	else 
		monster2.TrueFalse = true ;
	monster3.Monster_x = monster3.Monster_x - Monster3_X ;
	if(monster3.Monster_x <  0 || monster3.Monster_x == 0)
	{
		monster3.Monster_x = 1200 ;
	}
	length3 = monster3.Monster_x - Truck.Position_x ;
	if(length3 >= 0 && length3 <= 160 && monster3.Monster_y == Truck.Position_y)
	{
		monster3.TrueFalse = false ;
		Blood.Monster_x = monster3.Monster_x ;
		Blood.Monster_y = monster3.Monster_y ;
		Blood.TrueFalse = true ;
		monster3.Monster_x = 1200 ;
	}
	else 
		monster3.TrueFalse = true ;
}
void score()
{
	if(index == 2){
		scoree++;
	}
	sc = scoree;

	sprintf(S, "SCORE: %d", sc);
	sprintf(S2, "%d", sc);
	
	if(bestScore<sc)
	{
		bestScore = sc;
	}

}
//Animating functions end
int main()
{
	iInitialize(ScreenWidth,ScreenHeight, "BTS");

	printf("time=%d\n",t);
	printf("mons=%d\n",Monster1_X);
	
	// loading images.
	/* iLoadImage() will return an interger type id
	   for each image you load.
	*/
	IREC  = 188 ;
	Truck.Position_x = 0 ;
	Truck.Position_y = 145 ;
	monster1.Monster_x = 1200 ;
	monster1.Monster_y = 0 ;
	Marvel3.Monster_x = 1200;
	Marvel3.Monster_y = 0 ;
	monster2.Monster_x = 1200 ;
	monster2.Monster_y = 145 ;
	monster3.Monster_x = 1200 ;
	monster3.Monster_y = 290;
	Blood.Monster_x = -100 ;
	Blood.Monster_y = -100 ;
	Fire.Monster_x = -100 ;
	Fire.Monster_y = -100 ;
	Marvel1.Monster_x = 1200;
	Marvel1.Monster_y = 145 ;
	Marvel2.Monster_x = 1200;
	Marvel2.Monster_y = 290 ;
	tra();//still images of trees
	grass();//still images of grass
	roadstrips();// still images of roadstrips
	iSetTimer(1000,score);
	iSetTimer(100,chen);//changing trees as if its moving
	iSetTimer(100,grassmove);//changing grass as if it is moving
	iSetTimer(100,roadstripschange);//changing roads strip as  if it is moving
	iSetTimer(50,changeTRUCKMove);
	iSetTimer(300,changeMonsterAxisXPlusMovement123); 
	iSetTimer(100,DamagingMonsters);
	for(int i=0;i<12;i++){
		if(i%2==0){
			tree1[i].imug=iLoadImage("tree\\tree6.png");
		}
		else if(i%5==0)
		{
			tree1[i].imug=iLoadImage("tree\\tree2.png");
		}
		else
		{
			tree1[i].imug=iLoadImage("tree\\tree7.png");
		}
	}
	for(int j=0;j<10;j++)
	{
		strip[j].image=iLoadImage("tree\\strip.png");
	}
	for(int k=0;k<12;k++)
	{
		grass1[k].grassimg=iLoadImage("tree\\gg.png");
	}
	//image2 = iLoadImage("tree\\tree2.jpg");
	image3 = iLoadImage("tree\\gothic.jpg");
	image4 = iLoadImage("tree\\mount2.png");
	image1 = iLoadImage("tree\\lvl1.png");
	truckimg = iLoadImage("Truck\\truck.png");
	iStart(); // it will start drawing
	return 0;
}

