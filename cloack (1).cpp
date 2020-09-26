ÍÍÍÍÍÍÍ¼

#include<conio.h>				//To detect keyboard press
#include<graphics.h>				//Basic drawing operations
#include<dos.h>					//For Date & Time
#include<math.h>				//Cos,Sin
#include<stdlib.h>				//itoa
#include<string.h>				//strcpy,strcat,strlen
const float PI = 3.1415926535;			//PI value

int sec, min, hr;				//Store time

struct time t;					//Get time
struct dosdate_t d;				//Get Date

char p[8] = {0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55};//User defined fill pattern

char strhr[5] = "",strmin[5] = "",strsec[5] = "";//Store date.

char strdate[30];
//Select day of Month
char strday[][3]={"01", "02", "03", "04", "05", "06", "07", "08", "09", "10",
	       "11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
	       "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31"};
//Select month of Year
char strmonth[][9]={"January", "February", "March", "April", "May", "June",
		    "July", "August", "September", "October", "November", "December"};
char stryr[5] = "";//Store year
//Select day of Week
char strwday[][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void GoodBye (void);//Shows close down screen

void main ()//Program entry
{
	int gd = DETECT, gm;			//Graphics initialisation
	sec = min = hr = 0;			//Remove garbage values
	initgraph    (&gd, &gm, "E:\\tc\\bgi");	//Switch to graphics

	setfillstyle (SOLID_FILL, RED);		//Background- style & color
	bar (0, 0, 639, 479);			//Background
	float angle;//Inclination of the hands of the clock

	setcolor     (YELLOW);		        //Dial border of the clock
	setfillstyle (SOLID_FILL, YELLOW);
	fillellipse  (320, 240, 240, 240);      //Dial border

	setcolor         (LIGHTBLUE);		//Dial of the clock
	setfillstyle     (SOLID_FILL, LIGHTBLUE);
	fillellipse      (320, 240, 235, 235);

	setcolor         (DARKGRAY);		//Inside color of the clock
	setfillstyle     (SOLID_FILL, LIGHTGRAY);
	fillellipse      (320, 240, 190, 190);

	setcolor         (BLACK);
	settextstyle     (10, 0, 1);		//Bold_Font
	outtextxy        (306, 5, "XII");
	outtextxy        (312, 430, "VI");
	outtextxy        (520, 215, "III");
	outtextxy        (102, 215, "IX");
	setfillpattern   (p, WHITE);
	bar              (560, 215, 575, 265);  //Showing the key to the watch
	bar              (575, 220, 580, 260);  //Just a sho
/*	setfillpattern(p,LIGHTGRAY);
	bar(560,215,575,219);
	setfillpattern(p,DARKGRAY);
	bar(560,261,575,265);*/
	setfillstyle     (SOLID_FILL, WHITE);   //Making the textbox for Date
	bar              (210, 310, 445, 350);
	setcolor         (DARKGRAY);
	rectangle        (210, 310, 445, 350);
	setcolor         (BLACK);
	rectangle        (211, 311, 444, 349);
	setcolor         (WHITE);
	line             (210, 350, 446, 350);
	line             (446, 350, 446, 310);
	setcolor         (LIGHTGRAY);
	rectangle        (212, 312, 443, 348);  //End of textbox for Date

	while( ! kbhit() ){
	gettime          (&t);//Load system time into structure t
	sec   = t.ti_sec;	//Store seconds
	min   = t.ti_min;	//Store minutes
	hr    = t.ti_hour;	//Store hours

	setfillstyle     (SOLID_FILL, BROWN);
	fillellipse      (320, 240, 10, 10); //  -------|
	setfillstyle     (SOLID_FILL, WHITE);//         |   Display center of
	fillellipse      (320, 240, 7, 7);   //  -------|->    the Clock
	setfillstyle     (SOLID_FILL, GREEN);//         |
	fillellipse      (320, 240, 4, 4);   //  -------|

	itoa             (hr, strhr, 10); //Get hours in a string
	if( strlen (strhr) == 1)          //Make it a string having len = 2
	{
		strhr[2]   = '\0';
		strhr[1]   = strhr[0];
		strhr[0]   = '0';
	}
	itoa             (min, strmin, 10);//Get minutes in a string
	if( strlen (strmin) == 1)          //Make it a string having len = 2
	{
		strmin[2]   = '\0';
		strmin[1]   = strmin[0];
		strmin[0]   = '0';
	}
	itoa             (sec, strsec, 10);//Get seconds in a string
	if( strlen (strsec) == 1)          //Make it a string heving len = 2
	{
		strsec[2]   = '\0';
		strsec[1]   = strsec[0];
		strsec[0]   = '0';
	}
	setcolor         (BLACK);
	settextstyle     (5, 0, 4);
	moveto           (244, 117);
	outtext          (strhr);outtext (":");
	outtext          (strmin);outtext (":");
	outtext          (strsec);         //Display the time in the given region

	_dos_getdate     (&d);             //Load system date into structure d
	strcpy (strdate, strwday[d.dayofweek]);strcat (strdate, ",");
	strcat (strdate, strmonth[d.month-1]);strcat (strdate, " ");
	strcat (strdate, strday[d.day-1]);strcat (strdate, ",");
	itoa   (d.year, stryr, 10);
	strcat (strdate, stryr);
	settextstyle (1, 0, 1);
	moveto (225, 320);outtext (strdate);

	setlinestyle(SOLID_LINE,0,3);

	int totsec = ((t.ti_hour%12)* 60)+(t.ti_min);
	angle = (float)(((float)totsec/(float)720)* 2 *PI);angle -= PI / 2;
	setcolor (BLACK);

	line (320+2,240+2,320 +(100 * cos(angle))+ 2,240 +(100 * sin(angle))+ 2);
	setcolor (BROWN);
	line (320, 240, 320 + (100 * cos(angle)),240 +(100 * sin(angle)));


	angle = ((float)min/60)* 2 *PI;angle = angle - (PI / 2);
	setcolor (BLACK);

	line (320+3,240+3,320 +(175 * cos(angle))+ 3,240 +(175 * sin(angle))+ 3);
	setcolor (RED);
	line (320, 240, 320 + (175 * cos(angle)), 240 + (175 * sin(angle)));

	setlinestyle (SOLID_LINE,0,1);
	angle = ((float)sec/60)* 2 *PI;angle   = angle - (PI / 2);
	setcolor (BLACK);
	line (320+5,240+5,320 +(180 * cos(angle))+ 5,240 +(180 * sin(angle))+ 5);
	setcolor (RED);
	line (320,240,320 +(180 * cos(angle)), 240 +(180 * sin(angle)));

	delay (900);  setcolor(LIGHTGRAY);
	setlinestyle (SOLID_LINE, 0, 3);

	totsec = ((t.ti_hour % 12) * 60) + (t.ti_min);
	angle = (float)(((float)totsec/(float)720)* 2 *PI);angle -= PI / 2;
	line (320,240,320 +(100 * cos(angle)),240 +(100 * sin(angle)));
	line (320+2, 240+2,320 +(100 * cos(angle))+ 2,240 +(100 * sin(angle))+ 2);

	angle = ((float)min/60)* 2 *PI;angle = angle - (PI / 2);
	line (320,240,320 +(175 * cos(angle)),240 +(175 * sin(angle)));
	line (320+3,240+3,320 +(175 * cos(angle))+ 3,240 +(175 * sin(angle))+ 3);


	setlinestyle (SOLID_LINE,0,3);
	angle = ((float)sec/60)* 2 *PI;angle = angle - (PI / 2);
	line (320+5,240+5,320 +(180 * cos(angle))+ 5,240 +(180 * sin(angle))+ 5);
	line (320,240,320 +(180 * cos(angle)),240 +(180 * sin(angle)));

	setlinestyle (SOLID_LINE, 0, 1);
	setfillstyle (SOLID_FILL, WHITE);
	bar (240, 127, 390, 160);
	setcolor (BLACK);
	rectangle (241, 128, 389, 159);
	setcolor (DARKGRAY);
	line (240, 160, 240, 127);
	line (240, 127, 390, 127);
	setcolor (WHITE);
	line (240, 160, 390, 160);
	line (390, 160, 390, 127);
	setcolor (LIGHTGRAY);
	rectangle (242, 129, 388, 158);

	if( (sec>19 && sec<41) || (hr>19 && hr<41) || (min>19&&min<41) )
	{
	setfillstyle (SOLID_FILL, WHITE);
	bar (210, 310, 445, 350);
	setcolor (DARKGRAY);
	rectangle (210, 310, 445, 350);
	setcolor (BLACK);
	rectangle (211, 311, 444, 349);
	setcolor (WHITE);
	line (210, 350, 446, 350);
	line (446, 350, 446, 310);
	setcolor (LIGHTGRAY);
	rectangle (212, 312, 443, 348);
	}
	}
	GoodBye();
}
void GoodBye (void)
{
	closegraph ();
	int i,j;i = 5;
	textbackground (BLACK);
	textcolor (RED);
	clrscr ();

	delay (200);
	for (i = 0;i < 3;i ++)
	{
		clrscr ();
		gotoxy (5, 10);cprintf ("A CLOCK PROGRAM: ");
		delay (100);
		gotoxy (5, 15);cprintf ("ÛÛÛÛÛ   ÛÛÛÛÛÛ   ÛÛÛÛ   ÛÛÛÛÛ   ÛÛ  ÛÛ    ÛÛ      ÛÛ    ÛÛ  ÛÛ ");
		delay (100);
		gotoxy (5, 11);cprintf ("ÛÛÛÛÛ   ÛÛÛÛÛÛ   ÛÛÛÛ   ÛÛÛÛÛ    ÛÛÛÛ   ÛÛÛÛÛÛ  ÛÛÛÛÛÛ   ÛÛÛÛ ");
		delay (100);
		gotoxy (5, 14);cprintf ("ÛÛ  ÛÛ  ÛÛ      ÛÛ  ÛÛ  ÛÛ  ÛÛ  ÛÛÛÛÛÛ    ÛÛ      ÛÛ    ÛÛÛÛÛÛ ");
		delay (100);
		gotoxy (5, 12);cprintf ("ÛÛ  ÛÛ  ÛÛ      ÛÛ  ÛÛ  ÛÛ  ÛÛ  ÛÛ  ÛÛ    ÛÛ      ÛÛ    ÛÛ  ÛÛ ");
		delay (100);
		gotoxy (5, 13);cprintf ("ÛÛ  ÛÛ  ÛÛÛÛ    ÛÛ  ÛÛ  ÛÛ  ÛÛ  ÛÛ  ÛÛ    ÛÛ      ÛÛ    ÛÛ  ÛÛ ");
		delay (900);
       }

	textcolor(CYAN);
	gotoxy (1, 20);cprintf ("Exiting.....");
	gotoxy (1, 21);
	for (i = 0;i < 80;i ++)
	{
		gotoxy (wherex(),21);
		cprintf ("Û");
		delay (50);
	}
	textcolor(RED);
	delay (200);
	gotoxy (5, wherey () - 1);
	textcolor (WHITE);textbackground (CYAN);
	cprintf ("UnIstalling Clock.....                  [50  %]                    ");
	delay (3000);gotoxy(5, wherey ());
	cprintf ("DeInitialising Clock.....               [100 %] Completed.         ");
	delay (1500);gotoxy(5, wherey ());
	cprintf ("UnLoading System Date/Time.....         Done.                ");
	delay (1800);gotoxy(5, wherey ());
	cprintf ("UnLoading Graphics.....                 In Progress          ");
	delay (1000);gotoxy(5, wherey ());
	cprintf ("Removing Loaded Objects Graphics.....      Done                 ");
	delay (2000);gotoxy(5, wherey ());
	cprintf ("UnInstanciating GUI(Graphical User Interface)                ");
	delay (2000);gotoxy(5, wherey ());
	cprintf("Destroying & Removing Registry Values of the Software on System ");
	delay (1000);
	gotoxy (5, 5);
	textbackground (BLACK);
	textcolor (LIGHTCYAN);
	clrscr ();
	cprintf ("For any queries and bugs and improvements ... etc,         ");
	gotoxy (5, 6);
	cprintf ("Mail me at  <");
	textcolor (WHITE);
	cprintf (" adityamgopi@gmail.com");
	textcolor (LIGHTCYAN);
	cprintf (" >                  ");
	gotoxy (5, 20);
	cprintf ("Press any key to exit.....");
	getch ();
	getch ();
}
