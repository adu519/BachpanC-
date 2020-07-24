

#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>


#include "D:\ISHAN\TC\BIN\ISHAN_~1\CAL.CPP"
#include "D:\ISHAN\TC\BIN\ISHAN_~1\STOCK.CPP"




int cho=0;
int l;
void moveffect();
void BorderLines(int);
void BorderFlowers();
void colorline();
void ending();



void BorderLines()
{    int j;
     for(j=40;j<560;j++)             //for first line from left to right
     {
      delay(3);
      putpixel(j,25,j=j);
     }

     for(j=560;j>40;j--)
     {
      delay(2);
      putpixel(j,425,j);
     }

     for(j=45;j<405;j++)
     {
      delay(2);
      putpixel(25,j,j);
     }

     for(j=405;j>40;j--)
     {
      delay(2);
      putpixel(575,j,j);
     }	    //lines connected to flowers ended
     sound(400);

int i=300;                   //lines for inner triangle started
     for(j=110;j<350;j++)
     {
      delay(2);
      putpixel(i,j,GREEN);
      i++;
     }

i=300;
     for(j=110;j<350;j++)
     {
      delay(2);
      putpixel(i,j,BLUE);
      i--;
     }

i=350;
     for(j=60;j<540;j++)
     {
      delay(2);
      putpixel(j,i,RED);
     }

i=160;                       //lines for inverse triangle started
     for(j=45;j<540;j++)
     {
      delay(2);
      putpixel(j,i,RED);
     }

i=160;
     for(j=540;j>290;j--)
     {
      delay(2);
      putpixel(j,i,BLUE);
      i++;                   //as slanting line
     }

i=290;
     for(j=410;j>160;j--)
     {
      delay(2);
      putpixel(i,j,GREEN);
      i--;
     }

       }

void BorderLines1()
{    int j;
     for(j=40;j<560;j++)             //for first line from left to right
     {

      putpixel(j,25,j=j);
     }

     for(j=560;j>40;j--)
     {
     //  delay(1);
      putpixel(j,425,j);
     }

     for(j=45;j<405;j++)
     {
     // delay(1);
      putpixel(25,j,j);
     }

     for(j=405;j>40;j--)
     { // delay(1);
	putpixel(575,j,j);
     }                            //lines connected to flowers ended


int i=300;                   //lines for inner triangle started
     for(j=110;j<350;j++)
     {
     // delay(1);
      putpixel(i,j,GREEN);
      i++;
     }

i=300;
     for(j=110;j<350;j++)
     {// delay(1);
       putpixel(i,j,BLUE);
      i--;
     }

i=350;
     for(j=60;j<540;j++)
     {
      //delay(1);
      putpixel(j,i,RED);
     }

i=160;                       //lines for inverse triangle started
     for(j=45;j<540;j++)
     {
      //delay(1);
      putpixel(j,i,RED);
     }

i=160;
     for(j=540;j>290;j--)
     {
      //delay(1);
      putpixel(j,i,BLUE);
      i++;                   //as slanting line
     }

i=290;
     for(j=410;j>160;j--)
     {//delay(1);
      putpixel(i,j,GREEN);
      i--;
     }

     }

void moveffect()
{
	for(l=400;l>=90;l=l-40)
	{
		cleardevice();
		settextstyle(1,0,1);
		outtextxy(240,l,"PROJECT");
		delay(300);
	}

	for(l=400;l>=125;l=l-40)
	{
		cleardevice();
		outtextxy(240,90,"PROJECT");
		settextstyle(1,0,1);
		outtextxy(265,l,"OF");
		delay(300);
	}

	for(l=400;l>=160;l=l-40)
	{
		cleardevice();
		outtextxy(240,90,"PROJECT");
		outtextxy(265,125,"OF");
		settextstyle(1,0,1);
		outtextxy(140,l,"COMPUTER PROGRAMMING ");
		delay(300);
	}


	for(l=400;l>=300;l=l-20)
	{
		cleardevice();
		settextstyle(1,0,1);
		outtextxy(240,90,"PROJECT");
		outtextxy(265,125,"OF");
		outtextxy(140,160,"COMPUTER PROGRAMMING");
		settextstyle(1,0,1);
		outtextxy(l,300,"MADE BY:");
		delay(300);
	}


	for(l=400;l>=310;l=l-20)
	{
		cleardevice();
		settextstyle(1,0,1);
		outtextxy(240,90,"PROJECT");
		outtextxy(265,125,"OF");
		outtextxy(140,160,"COMPUTER PROGRAMMING");
		settextstyle(1,0,1);
		outtextxy(300,300,"MADE BY:");
		outtextxy(l,350,"ISHAN GUPTA");
		delay(300);
	}

	for(l=400;l>=320;l=l-20)
	{
		cleardevice();
		settextstyle(1,0,1);
		outtextxy(240,90,"PROJECT");
		outtextxy(265,125,"OF");
		outtextxy(140,160,"COMPUTER PROGRAMMING");
		settextstyle(1,0,1);
		outtextxy(300,300,"MADE BY:");
		outtextxy(320,350,"ISHAN GUPTA");
		outtextxy(l,400,"12-A DPS");
		delay(300);
	}
}

void BorderFlowers()
{
    circle(25,25,10);          //circle 1 top left corner start
    setfillstyle(SOLID_FILL,YELLOW);
    floodfill(20,20,WHITE);
    circle(20,20,15);
    setfillstyle(SOLID_FILL,RED);
    floodfill(15,15,WHITE);
    circle(20,30,15);
    setfillstyle( HATCH_FILL,GREEN);
    floodfill(30,15,WHITE);
    circle(30,20,15);
    setfillstyle( HATCH_FILL,GREEN);
    floodfill(30,40,WHITE);
    circle(30,30,15);
    setfillstyle( HATCH_FILL,GREEN);
    floodfill(40,15,WHITE);
    setfillstyle(SOLID_FILL,RED);
    floodfill(40,20,WHITE);
    circle(20,30,15);
    setfillstyle(SOLID_FILL,RED);
    floodfill(20,37,WHITE);
    setfillstyle(SOLID_FILL,RED);
    floodfill(20,12,WHITE);
    setfillstyle(  HATCH_FILL,18);
    floodfill(35,37,WHITE);           //circle 1 top left corner end
    circle(575,25,10);                //circle 2 top right corner start
    setfillstyle(SOLID_FILL,YELLOW);
    floodfill(570,20,WHITE);
    circle(570,20,15);
    setfillstyle(SOLID_FILL,RED);
    floodfill(565,15,WHITE);
    circle(570,30,15);
    setfillstyle( HATCH_FILL,GREEN);
    floodfill(580,15,WHITE);
    circle(580,20,15);
    setfillstyle( HATCH_FILL,GREEN);
    floodfill(580,40,WHITE);
    circle(580,30,15);
    setfillstyle( HATCH_FILL,GREEN);
    floodfill(590,15,WHITE);
    setfillstyle(SOLID_FILL,RED);
    floodfill(590,20,WHITE);
    circle(570,30,15);
    setfillstyle(SOLID_FILL,RED);
    floodfill(570,37,WHITE);
    setfillstyle(SOLID_FILL,RED);
    floodfill(570,12,WHITE);
    setfillstyle(  HATCH_FILL,18);
    floodfill(585,37,WHITE);
    circle(25,425,10);                      //circle 2 top right corner end
    setfillstyle(SOLID_FILL,YELLOW);        // circle 3 bottom left corner start
    floodfill(20,420,WHITE);
    circle(20,420,15);
    setfillstyle(SOLID_FILL,RED);
    floodfill(15,415,WHITE);
    circle(20,430,15);
    setfillstyle( HATCH_FILL,GREEN);
    floodfill(30,415,WHITE);
    circle(30,420,15);
    setfillstyle( HATCH_FILL,GREEN);
    floodfill(30,440,WHITE);
    circle(30,430,15);
    setfillstyle( HATCH_FILL,GREEN);
    floodfill(40,415,WHITE);
    setfillstyle(SOLID_FILL,RED);
    floodfill(40,420,WHITE);
    circle(20,430,15);
    setfillstyle(SOLID_FILL,RED);
    floodfill(20,437,WHITE);
    setfillstyle(SOLID_FILL,RED);
    floodfill(20,412,WHITE);
    setfillstyle(  HATCH_FILL,18);
    floodfill(35,437,WHITE);               	// circle 3 bottom left corner end
    circle(575,425,10);                        	// circle 4 bottom right corner start
    setfillstyle(SOLID_FILL,YELLOW);
    floodfill(570,420,WHITE);
     circle(570,420,15);
    setfillstyle(SOLID_FILL,RED);
    floodfill(565,415,WHITE);
       circle(570,430,15);
    setfillstyle( HATCH_FILL,GREEN);
    floodfill(580,415,WHITE);
       circle(580,420,15);
    setfillstyle( HATCH_FILL,GREEN);
    floodfill(580,440,WHITE);
       circle(580,430,15);
    setfillstyle( HATCH_FILL,GREEN);
    floodfill(590,415,WHITE);
    setfillstyle(SOLID_FILL,RED);
    floodfill(590,420,WHITE);
       circle(570,430,15);
    setfillstyle(SOLID_FILL,RED);
    floodfill(570,437,WHITE);
    setfillstyle(SOLID_FILL,RED);
    floodfill(570,412,WHITE);
    setfillstyle(  HATCH_FILL,18);
    floodfill(585,437,WHITE);                 	// circle 4 bottom right corner end
    }

void colorline()
{
rectangle(10,10,600,450);  //of firstpage
for(int j=40;j<560;j++)    //colored lines on page 1 start
     {
      delay(2);
      putpixel(j,55,j);
     }

for(j=40;j<560;j++)
     {
      delay(2);
      putpixel(j,210,j);
     }

     }

void ending()
{       cleardevice();
	int i,j;
	setfillstyle(LINE_FILL,DARKGRAY);
	for(i=5,j=80;i<40||j>40;i++,j--){
		bar(pixTOrc(2),pixTOrc(10),pixTOrc(i),pixTOrc(55));
		delay(10);
		bar(pixTOrc(j),pixTOrc(10),pixTOrc(80),pixTOrc(55));
		sound(400+(i*50));
		delay(10);
		nosound();}

	settextstyle(SMALL_FONT,HORIZ_DIR,7);
	displayMe(pixTOrc(5),pixTOrc(18),"Programmed by : ISHAN GUPTA",50);
	displayMe(pixTOrc(5.15),pixTOrc(18),"Programmed by : ISHAN GUPTA",0);
	setcolor(LIGHTGREEN);
	 displayMe(pixTOrc(5),pixTOrc(23),"Special Thanks to: Mrs. Jyoti Mathur ",50);
	displayMe(pixTOrc(5.15),pixTOrc(23),"Special Thanks to: Mrs. Jyoti Mathur ",0);
	setcolor(LIGHTCYAN);
	displayMe(pixTOrc(5),pixTOrc(28),"Email : ishanig1991@gmail.com",10);
	displayMe(pixTOrc(5.15),pixTOrc(28),"Email : ishanig1991@gmail.com",0);
	setcolor(LIGHTMAGENTA);
	outtextxy(pixTOrc(5),pixTOrc(45),"Your Suggestion and comments are always welcome");
	delay(1000);
	exit(0);
}

void main(int)
{
//Initializing of Graphics

int d,m,k=0;
  d=DETECT;
  initgraph(&d,&m,"..\\bgi");
   sound(900);
   moveffect();
   sound(700);
   colorline();
   sound(550);

for(l=0;l<=45;l++)        //loop for glowing look on page 1
{
delay(100);
sound(400+(l*70));
		delay(10);
		nosound();
setcolor(l);
settextstyle(1,0,1);
outtextxy(240,90,"PROJECT");
outtextxy(265,125,"OF");
outtextxy(140,160,"COMPUTER PROGRAMMING");
settextstyle(1,0,1);
setcolor(RED);
outtextxy(300,300,"MADE BY:");
setcolor(YELLOW);
outtextxy(320,350,"ISHAN GUPTA");

}
char choice;
cleardevice();
closegraph();
  int d1,m1;
  d=DETECT;
  initgraph(&d,&m,"..\\bgi");
//char choice;
int b,c;
BorderFlowers();
sound(500);
BorderLines();
sound(600);
//Note at the end
do{
	if(k!=0)
	{
	clrscr();
	d=DETECT;
	  initgraph(&d,&m,"..\\bgi");
	BorderFlowers();
	BorderLines1();
	}
	k++;
      setcolor(BLUE);
      outtextxy(200,450," PRESS THE CHARACTER INITIAL IN FRONT OF YOUR CHOICE");

//The main Body
   while(1)
   {
   int i;
	 for(i=1;i<15;i++)
	  {
		sound(400+(i*100));
		delay(10);
		setcolor(RED);
     rectangle(200,40,400,80);
     delay(100);
     setcolor(i);
     settextstyle(1,0,1);
     outtextxy(235,50,"UTILITY BOX");
     setcolor(RED);
     settextstyle(1,0,1);
     outtextxy(210,170,"I");
     setcolor(WHITE);
     outtextxy(226,170,"NVENTORY MANAGEMENT");
     setcolor(RED);
     outtextxy(210,290,"E");
     setcolor(WHITE);
     outtextxy(226,290,"XIT");
     setcolor(RED);
     outtextxy(210,230,"C");
     setcolor(WHITE);
     outtextxy(226,230,"ALCULATOR");
     }
     break;
      }


//Get the input of the main page
      nosound();
      int f=0;
       do{
       choice=getch();
 //Switching the Input
	 f=0;
	switch(choice)
	{

	 case 'c':
	 case 'C':
	 {
	  setcolor(RED);
	outtextxy(226,230,"ALCULATOR");
		delay(500);
	cleardevice();
	cho=calci();    //File calculator invoked
	}
	break;

     case 'i':
    case 'I':
    {
		setcolor(RED);
	outtextxy(226,170,"NVENTORY MANAGEMENT");
	delay(500);
	cleardevice();
	cho=inve();//File Stock called

     }break;

    case 'e':
    case 'E':
	     ending();
	     break;
    default:f=1;
	  }
	}while(f==1);

  }while(cho==1);

 }


