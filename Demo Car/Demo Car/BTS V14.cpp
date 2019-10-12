# include "iGraphics.h"
# include "myheader.h"
# include "Animate.h"
#define ScreenWidth 1200
#define ScreenHeight 700
int Monster1_X = 20;//monster 1 speed
int Monster2_X = 10;
int Monster3_X = 20;

char n[20];// for taking name in game
int namedone=0;//name checker
int nameindex=0;
int nu;


//pause variables
int ptree,pgrass,ptruck,pstrip,pdmgzom,pnormzom,pause=0;

//varibles for play music
int preIndex ;
int changedIndex;
bool sound = true;		// Used for sound track
bool soundd = false;	// Used for sound track
bool sounddd = true;	// Used for sound track
bool sco = true;		//Used for Score System
int kill = 0;
int fuel=1000,truckctrl=1;//variable for fuel and truck control
char fu[10];//variable for showing

int MARVELMonster1_X = 20;//variables for damaging zombies
int MARVELMonster2_X = 15;
int MARVELMonster3_X = 20;

//variables for fuel container
int fuimg,cot,cotX=1200;
int gasY;
int fillfuel=0;
int gc=1;

int x,y,i,IREC;
int storyindex=0,storyfl=1;//variables for story showing

int t=0;//time counting variable
char level[10];//character variable for level

char mm[7][80]={"Cars\\menuu1.bmp","Cars\\final main menu.bmp","Cars\\blank1.bmp","Cars\\contrl.bmp","Cars\\scbrd.bmp","Cars\\cre2.bmp"};
int index=0,mmX=0,mmY=0,levl,se=1;//here index changes interfaces of menu only
char Mons[5][20] = {"MON\\moj5.bmp","MON\\moj4.bmp","MON\\moj3.bmp","MON\\moj2.bmp","MON\\moj1.bmp"};
int MonsterIndex = 0 ;
char M[5][20] = {"M\\M1.bmp","M\\M2.bmp","M\\M3.bmp","M\\M4.bmp","M\\M5.bmp",};
char Zom[5][20] = {"ZOM\\Zom5.bmp","ZOM\\Zom4.bmp","ZOM\\Zom3.bmp","ZOM\\Zom2.bmp","ZOM\\Zom1.bmp"};
char TRUCK[3][20] = {"M\\Truck1.bmp","M\\Truck2.bmp","M\\Truck3.bmp"};
int MARVELMonsterindex = 0 ;
char MARVEL[7][20] = {"MARVEL\\MAR1.bmp","MARVEL\\MAR2.bmp","MARVEL\\MAR3.bmp","MARVEL\\MAR4.bmp","MARVEL\\MAR5.bmp","MARVEL\\MAR6.bmp","MARVEL\\MAR7.bmp"};
char MARVEL2[7][20] = {"MARVEL\\MARV1.bmp","MARVEL\\MARV2.bmp","MARVEL\\MARV3.bmp","MARVEL\\MARV4.bmp","MARVEL\\MARV5.bmp","MARVEL\\MARV6.bmp","MARVEL\\MARV7.bmp"};
char MARVEL3[7][20] = {"MARVEL\\MARVE1.bmp","MARVEL\\MARVE2.bmp","MARVEL\\MARVE3.bmp","MARVEL\\MARVE4.bmp","MARVEL\\MARVE5.bmp","MARVEL\\MARVE6.bmp","MARVEL\\MARVE7.bmp"};
char story[4][70]={"Stor\\story1.bmp","Stor\\story2.bmp","Stor\\story3.bmp","Stor\\story4.bmp"};
char namepage[4][20]={"Cars\\playername.bmp"};

int TRUCKIndex = 0 ;
int image1, image2, image3,image4,truckimg;
int x6,x2;

int load[21];		// Loads game using this array
int save[21];		// saves game using this array


int scoree=0,bestScore,bs,sc;
int arr[20];
char name[20],name1[20][5];			/// Both used for name purposes
int lowestScore;					// Stores the 5th rank score to compare current score

char S[10],S1[10],S2[10];			///Strings used to convert int value to String

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

typedef struct leaders leaders;
struct leaders
{
	char nam[20];
	int score;
};
leaders leader1;
leaders leader2;
leaders leader3;
leaders leader4;
leaders leader5;

Monster monster1 ;
Monster monster2 ;
Monster monster3 ;
Monster Blood ;
Monster Fire ;
Monster Marvel1 ;
Monster Marvel2 ;
Monster Marvel3 ;

int highScoreCoordinates = 539;


int truckX,truckY;
void iDraw()
{


	iClear();
	iShowBMP(0,0,mm[index]);
		FILE *fp = fopen("data1.txt", "r");

			fscanf(fp, "%s %d",&name1[i], &bs);
			sprintf(S1, "%d",bs);

		fclose(fp);

		if(index == 1){
			iSetColor(255,255,255);
			iText(942,84, "LEADERBOARD",GLUT_BITMAP_TIMES_ROMAN_24);

		}//(mx>=1029 && mx<=579) && (my>=1161 && my<=614)

	if(index==2 && namedone==1 && storyfl==0){


		iShowImage(0,200,1200,600,image3);// background sky

		iShowImage(0,300,1200,400,image4);// background hill
		for(int i=0;i<36;i++){
			iShowImage(tree1[i].x,310,300,200,tree1[i].imug); // shows the image of trees
		}
		iShowImage(0,0,1200,650,image1);// shows road
		for(int k=0;k<36;k++)
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
		iText(37,641,"SAVE",GLUT_BITMAP_TIMES_ROMAN_24);////(mx>=37 && mx<=641) && (my>=154 && my<=651)
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
		if(Blood.TrueFalse == true && movecontrol==1)
		iShowBMP2(Blood.Monster_x-=10 ,Blood.Monster_y,"M\\Blood.bmp",0);
		if(Blood.TrueFalse == true && movecontrol==0)
		iShowBMP2(Blood.Monster_x+=5 ,Blood.Monster_y,"M\\Blood.bmp",0);
		if(Fire.TrueFalse == true && movecontrol==1)
		iShowBMP2(Fire.Monster_x-=10 ,Fire.Monster_y,"M\\Fire.bmp",0);
		if(Fire.TrueFalse == true && movecontrol==0)
		iShowBMP2(Fire.Monster_x+=5 ,Fire.Monster_y,"M\\Fire.bmp",0);
		if(Blood.TrueFalse == true && movecontrol==-1)
		iShowBMP2(Blood.Monster_x ,Blood.Monster_y,"M\\Blood.bmp",0);
		if(Fire.TrueFalse == true && movecontrol==-1)
		iShowBMP2(Fire.Monster_x ,Fire.Monster_y,"M\\Fire.bmp",0);
		if(Marvel1.TrueFalse == true)
		iShowBMP2(Marvel1.Monster_x,Marvel1.Monster_y, MARVEL[MARVELMonsterindex],0);
		if(Marvel2.TrueFalse == true)
		iShowBMP2(Marvel2.Monster_x,Marvel2.Monster_y, MARVEL2[MARVELMonsterindex],0);
		if(Marvel3.TrueFalse == true)
		iShowBMP2(Marvel3.Monster_x,Marvel3.Monster_y, MARVEL3[MARVELMonsterindex],0);
		iText(37,500,fu,GLUT_BITMAP_TIMES_ROMAN_24);

		levl=se;
		sprintf(level,"Level:%d",levl);
		t++;
		if(t%400==0)//this changes the level and zombie speed it takes 1 min 40 secs to complete a level
		{
			se++;
			Monster1_X = Monster1_X+10;//changes zombie movement speed when level is upgraded
			Monster2_X = Monster2_X+10;
			Monster3_X = Monster3_X+10;
			MARVELMonster1_X=MARVELMonster1_X+10;
			MARVELMonster2_X=MARVELMonster2_X+10;
			MARVELMonster3_X=MARVELMonster3_X+10;
		}


			//this part shows gas container
		gc++;
		if(cotX==1200){
			if(gc>0){
				cot=145;
			}
			if(gc>=50)
			{
				cot=290;
			}
			if(gc>=100)
			{
				cot=0;
			}
		}
		printf("%d\n",gc);
		if(gc>140)
		{
			gc=1;
		}

		gasY=cot;//Y axis of gas container
		if(fillfuel==0){
			iShowImage(cotX,gasY,50,50,fuimg);
		}

		if(fillfuel==1)
		{
			for(int g=1;g<70;g++){
				iSetColor(50,255,160);
				iText(600,550,"+10 Fuel!",GLUT_BITMAP_TIMES_ROMAN_24);
			}
		}
		if(pause==0){
			cotX-=30;}  //X axis of gas container
		if(pause==1)
		{
			cotX=cotX;
		}
		if(cotX<0 || fillfuel==1)
		{
			cotX=1200;
		}
		int glen;//distance between gas container and object
		glen=cotX-Truck.Position_x;
		if((glen>=0 && glen<=160) && (Truck.Position_y==gasY))
		{
			fillfuel=1;
		}
		else
		{
			fillfuel=0;
		}
		//printf("gas:%d\n",fuel);
		//gas container part end

		if(pause==1)
		{
			iSetColor(0,255,0);
			iText(550,450,"Paused",GLUT_BITMAP_TIMES_ROMAN_24);
		}

	}


	if(index==2 && storyfl==1)
	{

		//this part shows story
		if(storyindex>=4)
		{
				storyfl=0;
		}
		if(storyfl==1){

			iShowBMP(0,0,story[storyindex]);
			iSetColor(255,0,0);
			iText(1000,10,"Press E to skip",GLUT_BITMAP_TIMES_ROMAN_24);
		}
		//story part end
	}



	//this part takes name of player
	if(index==2 && namedone==0)
	{

		iShowBMP(0,0,namepage[0]);
		iSetColor(0,0,0);
		iText(500,400,"Player name:",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(630,400,n,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	//player name taking part end


	if(index == 2){

		sound = true;
	}
	else sound =false;


	if(index == 4)
	{

		fp = fopen("data1.txt", "r");		//When the Leaderboard menu is opened this reads the file and displays on game according to the ranks

		for(i=0 ; i<5; i++){

			fscanf(fp, "%s %d",&name1[i], &bs);
			sprintf(S1, "%d",bs);
			if(i==0){
				iSetColor(255,255,255);
				iText(733,420 ,name1[0],GLUT_BITMAP_TIMES_ROMAN_24);
				iText(890,420,S1,GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if(i==1){
				iSetColor(255,255,255);
				iText(733,348 ,name1[1],GLUT_BITMAP_TIMES_ROMAN_24);
				iText(890,348,S1,GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if(i==2){
				iSetColor(255,255,255);
				iText(733,277 ,name1[2],GLUT_BITMAP_TIMES_ROMAN_24);
				iText(890,277,S1,GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if(i==3){
				iSetColor(255,255,255);
				iText(733,204 ,name1[3],GLUT_BITMAP_TIMES_ROMAN_24);
				iText(890,204,S1,GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if(i==4){
				iSetColor(255,255,255);
				iText(733,135 ,name1[4],GLUT_BITMAP_TIMES_ROMAN_24);
				iText(890,135,S1,GLUT_BITMAP_TIMES_ROMAN_24);
			}

			int k, temp=0,i,j;
			char tempStr[20];
			char name1[20][20];
			FILE *fp = fopen("data1.txt", "r");

			k=0;
			while(fscanf(fp, "%s %d", &name1[k],&arr[k]) != EOF)		//takes scores to a different array
			{
				k++;

			}
			fclose(fp);


			for (i = 0; i < k-1; i++)			//Bubble Sorts the whole ranks
			{

				for (j = 0; j < k-i-1; j++)
				{
					if (arr[j] < arr[j+1])
					{
						temp = arr[j];
						arr[j] = arr[j+1];
						arr[j+1] = temp;

						strcpy(tempStr,name1[j]);
						strcpy(name1[j],name1[j+1]);
						strcpy(name1[j+1],tempStr);
					}
				}
			}
			lowestScore = arr[4];

			fp = fopen("data1.txt", "w");		//Writes on file when the sorting is done
			for(i=0; i<k; i++){

			fprintf(fp,"%s %d ", name1[i], arr[i]);

			}
			fclose(fp);

			if(scoree > lowestScore){

				if(sco){

				fp = fopen("data1.txt", "a");

				fprintf(fp," %s %d", name, scoree);
				fclose(fp);
				sco = false;
				//fprintf(fp,"%d", bestScore);
				}
			}

		}
		fclose(fp);

	}
	if(movecontrol>=0)
	{
		if(pause==0){
			fuel--;}//the fuel will decrease when the car is moving
		if(pause==1)
		{
			fuel=fuel;
		}
		sprintf(fu,"Fuel:%d",fuel);
		if(fillfuel==1)
		{
			fuel+=10;
		}
		if(fuel>1000)
		{
			fuel=1000;
		}

	}


	if(fuel<0)
	{
		movecontrol=-1;
		truckctrl=0;
	}
}

void sortLeaderboard(){



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
		//printf("mx= %d my= %d\n %d \n",mx,my,kill);
		//printf("%d %d\n",save[0],save[1]);
	if(index==1){
		if((mx>=50 && mx<=350) && (my>=580 && my<=700))
				{
					index=2;
				}
		else if((mx>=50 && mx<=476) && (my>=336 && my<=449))
			{
				index=3;
			}
		else if((mx>=70 && mx<=350) && (my>=50 && my<=150))
			{
					exit(0);
			}
		else if((my>=186 && my<=291)&& (mx>=50 && mx<=432))
			{
				index=5;
			}
		else if((mx>=927 && mx<=1130) && (my>=80 && my<=117))
			{
				index=4;
			}
		else if((my>=347 && my<=574)&& (mx>=31 && mx<=347))
			{
				//printf("i wok");

			FILE *fpp = fopen("data2.txt", "r");

			int j =0;
			while(fscanf(fpp, "%d", &load[j]) != EOF){
				j++;
			}
			Truck.Position_x = load[0] ;
			Truck.Position_y = load[1] ;
			monster1.Monster_x = load[2] ;
			monster1.Monster_y = load[3] ;
			Marvel3.Monster_x = load[4];
			Marvel3.Monster_y = load[5] ;
			monster2.Monster_x = load[6] ;
			monster2.Monster_y = load[7] ;
			monster3.Monster_x = load[8] ;
			monster3.Monster_y = load[9];
			Blood.Monster_x = load[10] ;
			Blood.Monster_y = load[11] ;
			Fire.Monster_x = load[12] ;
			Fire.Monster_y = load[13] ;
			Marvel1.Monster_x = load[14];
			Marvel1.Monster_y = load[15] ;
			Marvel2.Monster_x = load[16];
			Marvel2.Monster_y = load[17] ;
			scoree = load[18];
			IREC = load[19];
			fuel = load[20];
			fclose(fpp);
			index = 2;
		}
		else if((mx>=37 && mx<=641) && (my>=154 && my<=651))
			{
				if(index==2){
						save[0] = Truck.Position_x;
						save[1] = Truck.Position_y;
						save[2] = monster1.Monster_x;
						save[3] = monster1.Monster_y;
						save[4] = Marvel3.Monster_x;
						save[5] = Marvel3.Monster_y ;
						save[6] = monster2.Monster_x ;
						save[7] = monster2.Monster_y;
						save[8] = monster3.Monster_x ;
						save[9] = monster3.Monster_y;
						save[10] = Blood.Monster_x;
						save[11] = Blood.Monster_y;
						save[12] = Fire.Monster_x;
						save[13] = Fire.Monster_y ;
						save[14] = Marvel1.Monster_x;
						save[15] = Marvel1.Monster_y;
						save[16] = Marvel2.Monster_x;
						save[17] = Marvel2.Monster_y ;
						save[18] = scoree;
						save[19] = IREC;
						save[20] = fuel;

				FILE *fpp = fopen("data2.txt", "w");
				for(int j = 0; j<21; j ++){
					fprintf(fpp, "%d ",save[j]);
				}
					fclose(fpp);
					index = 1;
			}
		}
	}

		else if(index == 2){

			if((mx>=26 && mx<=106) && (my>=639 && my<=668)){
						save[0] = Truck.Position_x;
						save[1] = Truck.Position_y;
						save[2] = monster1.Monster_x;
						save[3] = monster1.Monster_y;
						save[4] = Marvel3.Monster_x;
						save[5] = Marvel3.Monster_y ;
						save[6] = monster2.Monster_x ;
						save[7] = monster2.Monster_y;
						save[8] = monster3.Monster_x ;
						save[9] = monster3.Monster_y;
						save[10] = Blood.Monster_x;
						save[11] = Blood.Monster_y;
						save[12] = Fire.Monster_x;
						save[13] = Fire.Monster_y ;
						save[14] = Marvel1.Monster_x;
						save[15] = Marvel1.Monster_y;
						save[16] = Marvel2.Monster_x;
						save[17] = Marvel2.Monster_y ;
						save[18] = scoree;
						save[19] = IREC;
						save[20] = fuel;

				FILE *fpp = fopen("data2.txt", "w");
				for(int j = 0; j<21; j ++){
					fprintf(fpp, "%d ",save[j]);
				}
					fclose(fpp);
					index = 1;
			}
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
	if (key == 's')
	{
						if(index==2){
						save[0] = Truck.Position_x;
						save[1] = Truck.Position_y;
						save[2] = monster1.Monster_x;
						save[3] = monster1.Monster_y;
						save[4] = Marvel3.Monster_x;
						save[5] = Marvel3.Monster_y ;
						save[6] = monster2.Monster_x ;
						save[7] = monster2.Monster_y;
						save[8] = monster3.Monster_x ;
						save[9] = monster3.Monster_y;
						save[10] = Blood.Monster_x;
						save[11] = Blood.Monster_y;
						save[12] = Fire.Monster_x;
						save[13] = Fire.Monster_y ;
						save[14] = Marvel1.Monster_x;
						save[15] = Marvel1.Monster_y;
						save[16] = Marvel2.Monster_x;
						save[17] = Marvel2.Monster_y ;
						save[18] = scoree;
						save[19] = IREC;
						save[20] = fuel;

				FILE *fpp = fopen("data2.txt", "w");
				for(int j = 0; j<21; j ++){
					fprintf(fpp, "%d ",save[j]);
				}
					fclose(fpp);
					//index = 1;

						}
	}
	if(key == '\r')
	{
		if(index==0){
			index=1;}
	}
	if(index==2 && namedone==1 && storyfl==1){
		if(key == 'e')
		{
			storyfl=0;
		}
	}
	if(index==2 && storyindex<4 && namedone==1)
	{
		if(key == '\r')
		{
			storyindex++;
		}
	}
	if(index==2 && namedone==0)
	{
		if(key !='\b')
		{
			//namedone=0;
			n[nameindex]=key;
			nameindex++;
			n[nameindex]='\0';
		}
		else
		{
			if(nameindex<=0)
			{
				nameindex=0;
			}
			else
			{
				nameindex--;
				n[nameindex]='\0';
			}
		}
		if(key == '\r')
		{
			for(int i=0;n[i]!='\0';i++)
			{
				name[i]=n[i];
			}
			namedone=1;
		}
	}
	if(index==2 && namedone==1 && storyfl==0)
	{
		if( key == 'p')
		{
			iPauseTimer(ptree);
			iPauseTimer(pgrass);
			iPauseTimer(ptruck);
			iPauseTimer(pstrip);
			iPauseTimer(pnormzom);
			iPauseTimer(pdmgzom);
			pause=1;
		}
		if( key == 'r')
		{
			iResumeTimer(ptree);
			iResumeTimer(pgrass);
			iResumeTimer(ptruck);
			iResumeTimer(pstrip);
			iResumeTimer(pnormzom);
			iResumeTimer(pdmgzom);
			pause=0;
		}
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
		if(truckctrl==1)
		Truck.Position_y = Truck.Position_y - 145 ;
		Truck.Position_x = Truck.Position_x - 50 ;
 	}
	else if(key == GLUT_KEY_UP)
	{
		if(truckctrl==1)
		Truck.Position_y = Truck.Position_y + 145 ;
		Truck.Position_x = Truck.Position_x + 50 ;
	}
	else if(key == GLUT_KEY_RIGHT)
	{
		if(truckctrl==1){
		movecontrol=1;
		Truck.Position_x = Truck.Position_x + 50 ;
		}
	}
	else if(key == GLUT_KEY_LEFT)
	{
		if(truckctrl==1){
		movecontrol=0;
		Truck.Position_x = Truck.Position_x - 50 ;
		}
	}
	//place your codes for other keys here
	else if(key == GLUT_KEY_END){
		index=1;

	}
//place your codes for other keys here
}


//Animating functions
//Animating functions and variables for background changing are in Animate.h header file

//This function is used to control the animation of the truck and to keep it within screen
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
//This function is used to control the animation of the damaging monsters,Health of the truck
void DamagingMonsters()
{
	if(index==2 && namedone==1 && storyfl==0){
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
				Truck.Position_x = 0 ;
				Truck.Position_y = 145 ;
				se=1;
				t=0;
				//scoree=0;
				IREC  = 188 ;
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
				Truck.Position_x = 0 ;
				Truck.Position_y = 145 ;
				se=1;
				t=0;
				//scoree=0;
				IREC  = 188 ;
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
				Truck.Position_x = 0 ;
				Truck.Position_y = 145 ;
				se=1;
				t=0;
				//scoree=0;
				IREC  = 188 ;
				index = 4 ;
			}
		}
		else
			Marvel3.TrueFalse = true ;
	}

}
//This function is used to control the animation of the zombies
void changeMonsterAxisXPlusMovement123()
{
	if(index==2 && namedone==1 && storyfl==0){
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
			kill++ ;
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
			kill++ ;
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
			kill++ ;
			Blood.Monster_x = monster3.Monster_x ;
			Blood.Monster_y = monster3.Monster_y ;
			Blood.TrueFalse = true ;
			monster3.Monster_x = 1200 ;

		}
		else
			monster3.TrueFalse = true ;
	}

}
void score()
{
	if(index==2 && namedone==1 && storyfl==0){

		if(pause==1)
		{
			scoree=scoree;
		}
		else
		{
			scoree++;
		}
	}
	sc = scoree+(kill*10);		//Counts Score

	sprintf(S, "SCORE: %d", sc);
	sprintf(S2, "%d", sc);

	if(bestScore<sc)
	{
		bestScore = sc;
	}

}

void loadGame(){


}

void saveGame(){


}
void mainmenumusic()//music main menu music playing function
{

	if(sound)
	{
		PlaySound("music\\A wild river to take you home — Black Hill Silent Island (online-audio-converter.com).wav",NULL,SND_LOOP | SND_ASYNC);//main menu music
	}


}

void changeMusic(){

	if(soundd)
	{
		PlaySound("music\\videoplayback.wav",NULL,SND_LOOP | SND_ASYNC);//Playing ingame music
	}
}
void changeI()
{

	if(index ==1 ){
		if(!sound){
			PlaySound(0,0,0);
		}
		sounddd = false;
		soundd = false;
		sound = true;

		mainmenumusic();
	}
	else if(index == 2){
		if(!soundd){
			PlaySound(0,0,0);
		}
		sounddd = false;
		soundd = true;
		sound = false;

		changeMusic();
	}


}


void assign1(){				//Assigns a index if game game index changes
	preIndex = index;

}

void assign2(){				// If game index changes calls the music changing function

	if(preIndex != index){

		changeI();
	}

}


//Animating functions end
int main()
{

	iInitialize(ScreenWidth,ScreenHeight, "BTS");

	printf("%s\n",name);

	//printf("Enter Player Name\n");
	//scanf("%s",&name);
	// loading images.
	/* iLoadImage() will return an interger type id
	   for each image you load.
	printf("time=%d\n",t);
	printf("mons=%d\n",Monster1_X);
	*/
	IREC  = 188 ;
	if(sounddd)
	{
		PlaySound("music\\Skyrim - Dovahkiin (Metal Cover).wav",NULL,SND_LOOP | SND_ASYNC);//main menu music A wild river to take you home — Black Hill Silent Island (online-audio-converter.com).wav
	}
	//here everything has been initialized with its first value
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
	//loadGame();
	sortLeaderboard();
	tra();//still images of trees
	grass();//still images of grass
	roadstrips();// still images of roadstrips
	iSetTimer(50,assign1);
	iSetTimer(5,assign2);
	iSetTimer(1000,score);
	ptree=iSetTimer(100,chen);//changing trees as if its moving
	pgrass=iSetTimer(100,grassmove);//changing grass as if it is moving
	pstrip=iSetTimer(100,roadstripschange);//changing roads strip as  if it is moving
	ptruck=iSetTimer(50,changeTRUCKMove);
	pnormzom=iSetTimer(300,changeMonsterAxisXPlusMovement123);
	pdmgzom=iSetTimer(100,DamagingMonsters);
	for(int i=0;i<36;i++){
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
	for(int k=0;k<36;k++)
	{
		grass1[k].grassimg=iLoadImage("tree\\gg.png");
	}
	//image2 = iLoadImage("tree\\tree2.jpg");
	image3 = iLoadImage("tree\\gothic.jpg");
	image4 = iLoadImage("tree\\mount2.png");
	image1 = iLoadImage("tree\\lvl1.png");
	truckimg = iLoadImage("Truck\\truck.png");
	fuimg=iLoadImage("tree\\gasfuel.png");
	iStart(); // it will start drawing
	return 0;
}

