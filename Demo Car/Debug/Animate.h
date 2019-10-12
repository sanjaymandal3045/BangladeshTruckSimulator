#ifndef ANIMATE_H_INCLUDED
#define ANIMATE_H_INCLUDED


int s,movecontrol=-1;

typedef struct tree tree;
struct tree
{
	int imug;
	int x;
	int y;
};
tree tree1[36];

typedef struct grass Grass;
struct grass
{
	int grassimg;
	int x,y;
};
Grass grass1[36];


typedef struct rstrip rstrip;
struct rstrip
{
	int image;
	int x;
};
rstrip strip[10];

void grass()//this sets the grass under the tree
{

	int s=0;
	for(int i=0;i<36;i++)
	{
		grass1[i].x=s;
		s+=50;
	}
}
void grassmove()//this changes the grass under tree as if its moving
{
	if(movecontrol==1){
		for(int i=0;i<36;i++)
		{
			grass1[i].x-=10;
			if(grass1[i].x<=0)
			{
				grass1[i].x=1500;
			}
		}
	}
	if(movecontrol==0)
	{
		for(int i=36;i>=0;i--)
		{
			grass1[i].x+=5;
			if(grass1[i].x>=1200)
			{
				grass1[i].x=-1;
			}
		}
	}
}
void chen() //this changes the tree coordinates thats why its called in isettimer
{
	if(movecontrol==1){
		for(int i=0;i<36;i++){
			tree1[i].x-=10;
			if(tree1[i].x<=0)
			{
				tree1[i].x=1500;
			}
		}
	}
	if(movecontrol==0)
	{
		for(int i=36;i>=0;i--){
			tree1[i].x+=5;
			if(tree1[i].x>=1200)
			{
				tree1[i].x=0;
			}
		}
	}
}
void tra()// sets the trees line by by line and creats a still pic
{
	int t=0;
	for(int i=0;i<36;i++)
	{
		tree1[i].x=t;
		t+=50;
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
	if(movecontrol==1){

		for(int j=0;j<10;j++)
		{
			strip[j].x-=40;
			if(strip[j].x<=0)
			{
				strip[j].x=1100;
			}
		}
	}
	if(movecontrol==0)
	{
		for(int j=0;j<10;j++)
		{
			strip[j].x+=35;
			if(strip[j].x>=1200)
			{
				strip[j].x=0;
			}
		}
	}

}















#endif  // !ANIMATE_H_INCLUDED