/**************************************************************/
/****************INVENTORY MANAGEMENT SYSTEM*******************/
/**************************************************************/
/*Programmed by : ISHAN GUPTA**********************************/
/*Password is : ishan **********************************/
/**************************************************************/


#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<fstream.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>
#include<string.h>
#include<stdio.h>
#include <time.h>

fstream inoutfile;

//Menu Global Item
#define pixTOrc(x) (8*(x-1))       //for resizing the bar
#define INC 4  //Increment Distance Between Menu Items
#define ROW 15 //Row Value for Menu Item
#define COL 8 //Column Value for Menu Item

// To display the Inventory Main menu options
typedef char option[15];
option mainMenu[]= {
  "New Record",
  "Display",
 "Search",
 "Updation",
 "Deletion",
 "Analysis",
 "Main Menu",
 "Exit"
};


/*-------------------Inventory Class--------------------*/

class Inventory{
	char itemName[20];
	int qty,itemNo;
	double price,amt;

	public:

	int getno(){return itemNo;}
	char *getitem(){ return itemName;}
	double getamt(){return amt;}
	void getdata();
	void showdata(int,int);
	void showspecific();
	void alterspecific(int,char *);
};

void Inventory :: getdata(){
	gotoxy(30,12);
	cout<<"Enter Item Number : ?\b";
	cin>>itemNo;
	gotoxy(30,14);
	cout<<"Enter Item Name : ?\b";
	cin>>itemName;
	gotoxy(30,16);
	cout<<"Enter Quantity : ?\b";
	cin>>qty;
	gotoxy(30,18);
	cout<<"Enter Price : ?\b";
	cin>>price;
	amt = price * qty;
}

void Inventory :: showdata(int x,int y){
	gotoxy(x,y);
	cout.setf(ios::left,ios::adjustfield);
	cout<<setw(3)<<itemNo;
	cout.setf(ios::left,ios::adjustfield);
	cout<<setw(13)<<itemName;
	cout<<setw(4)<<qty;
	cout.setf(ios::right,ios::adjustfield);
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed,ios::floatfield);
	cout<<setprecision(2)<<setw(8)<<price;
	cout.setf(ios::right,ios::adjustfield);
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed,ios::floatfield);
	cout<<setprecision(2)<<setw(15)<<amt;
}

void Inventory :: showspecific(){
	gotoxy(30,13);
	cout<<"--Search Item Found--";
	gotoxy(30,15);
	cout<<"Item No : ";
	cout.setf(ios::left,ios::adjustfield);
	cout<<itemNo;
	gotoxy(30,17);
	cout<<"Item Name : ";
	cout.setf(ios::left,ios::adjustfield);
	cout<<itemName;
	gotoxy(30,19);
	cout<<"Quantity : ";
	cout<<qty;
	cout.setf(ios::right,ios::adjustfield);
	gotoxy(30,21);
	cout<<"Price : ";
	cout<<setprecision(2)<<price;
	gotoxy(30,23);
	cout<<"Amount : ";
	cout.setf(ios::right,ios::adjustfield);
	cout<<setprecision(2)<<amt;
}

void Inventory :: alterspecific(int itmno,char itmname[20]){
	itmno=itemNo;
	strcpy(itemName,itmname);
	gotoxy(30,16);
	cout<<"Enter Quantity : ?\b";
	cin>>qty;
	gotoxy(30,18);
	cout<<"Enter Price : ?\b";
	cin>>price;
	amt = price * qty;
}


/*---------------Inventory Codes End------------------*/





/*--------------Menu and all other functions Code--------------*/

//Displays Graphic text in delaying fashion
void displayMe(int x,int y,const char *ch,int delayTime){
   char d[2];
   int len=strlen(ch);
   for(int i=0;i<=len;i++)
    {
     d[0]=ch[i];
     d[1]='\0';
     outtextxy(x+pixTOrc((i+1)*2),y,d);
     delay(delayTime);
    }
}

//Function which shows loading...progress bar
void loading(){
	 //progressbar logic
	   int i=1,j,cnt,clrflag=0;
	   setcolor(BLACK);
	   j=160;
	   cnt=5;
	   for(i=j;i<420;i++){
	      gotoxy(35,25);
	      cout<<cnt;
	      rectangle(j,375,i,405);
	      outtextxy(240,340,"LOADING ");
	      if(i==(j+10)){
		 j=j+13;
		 i=j;
		 if(clrflag==1){
		   clrflag=0;
		   setcolor(BLACK);
		 }
		 else{
		   clrflag=1;     //change color to grey when increment to 13
		   setcolor(DARKGRAY);
		 }
		 cnt=cnt+5;
	      }
	   }
   delay(1500);
}

// Function to displays all the menu prompt messages from the pointer array of option a[]
void normalvideo(int x,int y,char *str)
{
    x=pixTOrc(x);
    y=pixTOrc(y);
    outtextxy(x,y,str);
}

// Function to move the cursor on the menu prompt with a reverse video color
void reversevideo(int x,int y,char *str)
{
	x=pixTOrc(x);
	y=pixTOrc(y);
	setcolor(YELLOW);  //Selected Item
	sound(400);
	delay(100);
	nosound();
	outtextxy(x,y,str);
	setcolor(RED); //Unselected Item
	sound(500);
	delay(100);
	nosound();
}

//Keep Track of which arrow key is displayed
char menu()
{
	settextstyle(2,HORIZ_DIR,3);
	setcolor(WHITE);  //Initial Menu Item Color
	int i,done;
	for(i = 1; i < 8; i++)
	  normalvideo(COL, (i*INC)+ROW, mainMenu[i]);
	  //COL provides 5 dist between menu,same ROW,mainMenu[] display opt
	reversevideo(COL,ROW, mainMenu[0]);
	i = done =0;
	do
	{
			/**status Bar **/
			//Message will be displayed as status bar guide-line
			setfillstyle(SOLID_FILL,BLUE);
			settextstyle(SMALL_FONT,HORIZ_DIR,5);
			bar(pixTOrc(2),pixTOrc(52.5),pixTOrc(75),pixTOrc(55)); //second last bar from bottom
			setcolor(LIGHTCYAN);
			switch(i){
				case 0 : outtextxy(pixTOrc(5),pixTOrc(52.75),"Add New Item to Inventory");
					 break;
				case 1 : outtextxy(pixTOrc(5),pixTOrc(52.75),"Display All Items available in Inventory");
					 break;
				case 2 : outtextxy(pixTOrc(5),pixTOrc(52.75),"Search for a specific Item in Inventory");
					 break;
				case 3 : outtextxy(pixTOrc(5),pixTOrc(52.75),"Modify the quantity and price information of Item available in Inventory");
					 break;
				case 4 : outtextxy(pixTOrc(5),pixTOrc(52.75),"Deletion of item from Inventory ");
					 break;
				case 5 : outtextxy(pixTOrc(5),pixTOrc(52.75),"Managerial Analysis To tak Decisions...");
					 break;
				case 6 : outtextxy(pixTOrc(5),pixTOrc(52.75),"Go to the Main Menu");
					 break;
				case 7 : outtextxy(pixTOrc(5),pixTOrc(52.75),"Close the Program --> BYE C U @ www.ishanig1991@gmail.com");
					 break;
			}
			/**status Bar ends**/
			time_t t;
			/*****Time display****/
			//Displaying Time logic
			 while(!kbhit())
			 /*Checks for currently available keystrokes
			  Declaration:  int kbhit(void);
			  Remarks:
			kbhit checks to see if a keystroke is currently available.
			 Any available keystrokes can be retrieved with getch or getche.
			 Return Value:
			 þ On success (if a keystroke is available),
			    returns a non-zero integer
			  þ If a keystroke is not available, returns 0.
			 */
			 {
			      time(&t);  //time_t time(time_t *timer);
			      bar(pixTOrc(2),pixTOrc(55.5),pixTOrc(75),pixTOrc(58));
			      outtextxy(pixTOrc(5),pixTOrc(56),ctime(&t));
			      delay(200);
			 }
			  /*****Time display Ends****/

			 //Restore Orignal Color and Font Setting
			 setcolor(WHITE);
			settextstyle(2,HORIZ_DIR,3);

		int key = getch();
		switch (key)
		{
		case 72: //for upper arrow key
			 normalvideo(COL, (i*INC)+ROW, mainMenu[i]);
			 i--;
			 if (i == -1)
			 i = 7;
			 reversevideo(COL,(i*INC)+ROW,mainMenu[i]);
			 break;
		case 80://for lower arrow key
			  normalvideo(COL, (i*INC)+ROW, mainMenu[i]);
			  i++;
			  if (i == 8)
			  i = 0;
			  reversevideo(COL, (i*INC)+ROW, mainMenu[i]); //changes color to yellow
			  break;

		case 13:           //for enter
				done = 1;
		}
	}
	while (!done); //till done != 1
	return(i+49);    //return the no of option selected
}

//Advertise Screen will displayed to utilize empty screen area
//It can be utilize for some effective...work
void advertise(){
	setcolor(BLUE);
	outtextxy(pixTOrc(30),pixTOrc(20),"MADE BY:ISHAN GUPTA");
	outtextxy(pixTOrc(30),pixTOrc(26),"CLASS: 12-A ,DPS Jodhpur");
	outtextxy(pixTOrc(30),pixTOrc(32),"ishanig1991@gmail.com");
	setcolor(YELLOW);
}



//At Exit the end function will call...
void end(){
	int i,j;
	setfillstyle(LINE_FILL,DARKGRAY);
	for(i=5,j=80;i<40||j>40;i++,j--){
		bar(pixTOrc(2),pixTOrc(10),pixTOrc(i),pixTOrc(55));
		delay(10);
		bar(pixTOrc(j),pixTOrc(10),pixTOrc(80),pixTOrc(55));
		sound(400+(i*50));
		delay(10);
		nosound();
	}
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

/* The function is used to display the main menu*/
int control_menu()
{
     char choice;
     int mainme=0,t=1;
	do
	{
		choice = menu(); //takes the choice entered
		switch (choice)
		{
		   case '1':    //Add New Item
				Inventory additem;
				inoutfile.open("c:\\stock.dat",ios::ate | ios::out | ios::binary);
				inoutfile.seekg(0,ios::end);
				setfillstyle(SOLID_FILL,BLACK);
				bar(pixTOrc(28),pixTOrc(14),pixTOrc(75),pixTOrc(50));
				setcolor(YELLOW);
				outtextxy(pixTOrc(40),pixTOrc(15),"Add New Item");
				additem.getdata();
				char ch;
				cin.get(ch);
				inoutfile.write((char *) &additem, sizeof(additem));
				gotoxy(30,22);
				cout<<"-> Item Added in Inventory <-";
				flush(inoutfile); //flushes the ostream
				inoutfile.close();
				getch();
				setfillstyle(SOLID_FILL,LIGHTGRAY);
				bar(pixTOrc(28),pixTOrc(14),pixTOrc(75),pixTOrc(50));
				advertise();
				break;

		   case '2':    //Display All Item in inventory
				Inventory showitem;
				static int count=0;
				count++;
				inoutfile.open("c:\\stock.dat",ios::ate| ios::in | ios::binary);
				setfillstyle(SOLID_FILL,BLACK);
				bar(pixTOrc(28),pixTOrc(14),pixTOrc(75),pixTOrc(50));
				setcolor(YELLOW);
				outtextxy(pixTOrc(40),pixTOrc(15),"Inventory Stock");
				inoutfile.seekg(0,ios::beg); //goto start of file
				gotoxy(28,11);
				cout<<" No "<<" Item Name "<<"   qty "<<"   price "<<"       amount";
				gotoxy(28,12);
				cout<<"----------------------------------------------";
				int x=30,y=13;
				while(inoutfile){
					inoutfile.read((char *) &showitem, sizeof(showitem));
					if(!inoutfile.eof())
						showitem.showdata(x,y++);
				}
				inoutfile.close();
				getch();
				setfillstyle(SOLID_FILL,LIGHTGRAY);
				bar(pixTOrc(28),pixTOrc(14),pixTOrc(75),pixTOrc(50));
				advertise();
				break;

		   case '3':    //Search for specific Item in inventory
				Inventory srchitem;
				inoutfile.open("c:\\stock.dat",ios::ate |ios::in| ios::out | ios::binary);
				setfillstyle(SOLID_FILL,BLACK);
				bar(pixTOrc(28),pixTOrc(14),pixTOrc(75),pixTOrc(50));
				setcolor(YELLOW);
				outtextxy(pixTOrc(40),pixTOrc(15),"Search Item");
				gotoxy(30,11);
				cout<<"Enter Item Name : ";
				char name[20];
				cin>>name;
				inoutfile.seekg(0,ios::beg);
				int found=0;
				while(inoutfile){
					inoutfile.read((char *) &srchitem, sizeof(srchitem));
					if(strcmp(srchitem.getitem(),name)==0){
						found=1;
						srchitem.showspecific();
					}
				}
				if(found==0){
					gotoxy(30,15);
					cout<<"SEARCH ITEM NOT FOUND";
				}
				inoutfile.close();
				getch();
				setfillstyle(SOLID_FILL,LIGHTGRAY);
				bar(pixTOrc(28),pixTOrc(14),pixTOrc(75),pixTOrc(50));
				advertise();
				break;

		   case '4':    //Modify the status of item in inventory
				Inventory alteritem;
				inoutfile.open("c:\\stock.dat",ios::ate |ios::in| ios::out | ios::binary);
				setfillstyle(SOLID_FILL,BLACK);
				bar(pixTOrc(28),pixTOrc(14),pixTOrc(75),pixTOrc(50));
				setcolor(YELLOW);
				outtextxy(pixTOrc(40),pixTOrc(15),"Modify Item Details");
				gotoxy(30,13);
				cout<<"Enter Item Name : ";
				cin>>name;
				inoutfile.seekg(0,ios::beg);
				found=0;
				int rec=0;
				while(inoutfile){
					rec++;
					inoutfile.read((char *) &alteritem, sizeof(alteritem));
					if(strcmp(alteritem.getitem(),name)==0){
						found=1;
						int location = (rec-1) * (sizeof(alteritem));
						inoutfile.seekp(location);
						alteritem.alterspecific(alteritem.getno(),alteritem.getitem());
						cin.get(ch);
						inoutfile.write((char *) &alteritem, sizeof(alteritem));
						break;
					}
				}
				if(found==0){
					gotoxy(30,15);
					cout<<"ITEM NOT FOUND -- NO Modification Possible";
				}
				else{
					gotoxy(30,24);
					cout<<"ITEM Updated Successfully";
				}
				inoutfile.close();
				getch();
				setfillstyle(SOLID_FILL,LIGHTGRAY);				bar(pixTOrc(28),pixTOrc(14),pixTOrc(75),pixTOrc(50));
				bar(pixTOrc(28),pixTOrc(14),pixTOrc(75),pixTOrc(50));
				advertise();
				break;

		   case '5':    //Delete Item in inventory
				Inventory delitem;
				inoutfile.open("c:\\stock.dat",ios::ate |ios::in| ios::out | ios::binary);
				setfillstyle(SOLID_FILL,BLACK);
				bar(pixTOrc(28),pixTOrc(14),pixTOrc(75),pixTOrc(50));
				setcolor(YELLOW);
				outtextxy(pixTOrc(40),pixTOrc(15),"Delete  Item");
				gotoxy(30,11);
				cout<<"Enter Item Name : ";
				cin>>name;
				inoutfile.seekg(0,ios::beg);
				fstream tempFile("c:\\stock1.dat",ios::ate |ios::out| ios::out | ios::binary);
				found=0;
				while(inoutfile){
					inoutfile.read((char *) &delitem, sizeof(delitem));
					if(strcmp(delitem.getitem(),name)!=0){
						cin.get(ch);
						tempFile.write((char *) &delitem, sizeof(delitem));
						found=0;
					}
					else{
						gotoxy(30,18);
						cout<<"Wait Please...Deletion may take few seconds";
						found=1;
					}
				}
				if(found==0){
					gotoxy(30,15);
					cout<<"ITEM NOT FOUND -- No Deletion Possible";
				}
				else{
					gotoxy(30,15);
					cout<<"ITEM FOUND -- Deleted Successfully";
				}
				tempFile.flush();
				inoutfile.flush();
				tempFile.close();
				inoutfile.close();
				remove("c:\\stock.dat");
				rename("c:\\stock1.dat","c:\\stock.dat");
				getch();
				setfillstyle(SOLID_FILL,LIGHTGRAY);
				bar(pixTOrc(28),pixTOrc(14),pixTOrc(75),pixTOrc(50));
				advertise();
				break;


		   case '6':    //Analysis of Inventory Items
				Inventory anitem;
				inoutfile.open("c:\\stock.dat",ios::ate |ios::in| ios::binary);
				setfillstyle(SOLID_FILL,BLACK);
				bar(pixTOrc(28),pixTOrc(14),pixTOrc(75),pixTOrc(50));
				setcolor(YELLOW);
				outtextxy(pixTOrc(40),pixTOrc(15),"Managerial Analysis");
				gotoxy(30,16);
				int last=inoutfile.tellg();
				int n = last/sizeof(anitem);
				cout<<"Total Items in Inventory : "<<n;
				inoutfile.seekg(0,ios::beg); //goto start of file
				double total=0.0;
				while(inoutfile){
					inoutfile.read((char *) &anitem, sizeof(anitem));
					if(!inoutfile.eof())
					    total=total + anitem.getamt();
				}
				inoutfile.close();
				gotoxy(30,18);
				cout<<"Total Investements : "<<total;
				getch();
				setfillstyle(SOLID_FILL,LIGHTGRAY);
				bar(pixTOrc(28),pixTOrc(14),pixTOrc(75),pixTOrc(50));
				advertise();
				break;


		   case '7' :{
				mainme=1;
				return mainme ;
			     }
		   case '8' :end();
		   }
	  } while(mainme!=1);
	  return mainme;
	  }





//Function Displaying Password Screen...
int get_password()
{
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar(0,0,640,480);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	setcolor(BLUE);
	outtextxy(pixTOrc(8),pixTOrc(2),"Inventory Management System");
	setfillstyle(LINE_FILL,BROWN);
	bar(pixTOrc(8),pixTOrc(7),pixTOrc(70),pixTOrc(7.5));

	int i,j;
	setfillstyle(LINE_FILL,DARKGRAY);
	for(i=15,j=65;i<25||j>25;i++,j--){
		bar(pixTOrc(15),pixTOrc(15),pixTOrc(i),pixTOrc(40));
		delay(10);
		bar(pixTOrc(j),pixTOrc(15),pixTOrc(65),pixTOrc(40));
		sound(10+(i*250));
		delay(10);
		nosound();
	}
	int c=pixTOrc(40),a=-1;
	char pass[20],correctpassword[20]="ishan";
	setcolor(YELLOW);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	outtextxy(pixTOrc(16),pixTOrc(17),"Enter password : ");
	setcolor(LIGHTCYAN);
	outtextxy(pixTOrc(16),pixTOrc(33),"Password is in Code top ");
	setcolor(WHITE);
	while (pass[a]!='\r')
	{
		pass[++a]=getche();
		if  (pass[a]=='\r'){
			pass[a]='\0';
			break;
		}
		c+=15;
		outtextxy(c,pixTOrc(17.5), "*");
	 }

		if (strcmp(pass,correctpassword)==0){
			outtextxy(pixTOrc(20),pixTOrc(24),"Password Accepted");
			loading();
			return(0);
		}
		else{
			outtextxy(pixTOrc(20),pixTOrc(24),"Wrong Password!!!");
			setcolor(WHITE);
			getch();
			return (1);
		}
}

/*Main Function for this file*/
int inve()
{
	int i,j,store,cnt=0;
	char trial='n';
	int gd=DETECT,gm=0;
	int incorrect_pass;
	initgraph(&gd,&gm,"");
		do
		{
		incorrect_pass=get_password();
		if(incorrect_pass)
			{
			clrscr();
				if(cnt==0)
				{
		outtextxy(pixTOrc(20),pixTOrc(24),"WRONG PASSWORD (3 Attempts left) !");
		outtextxy(pixTOrc(20),pixTOrc(26),"Press Y to retry");
				}
				else if(cnt==1)
				{
		outtextxy(pixTOrc(20),pixTOrc(24),"WRONG PASSWORD (2 Attempts left) !");
		outtextxy(pixTOrc(20),pixTOrc(26),"Press Y to retry");
				}
				else if(cnt==2)
				{
		outtextxy(pixTOrc(20),pixTOrc(24),"WRONG PASSWORD (Last Attempts left) !");
		outtextxy(pixTOrc(20),pixTOrc(26),"Press Y to retry");
				}
				else if(cnt==3)
				end();
				trial=getch();
				cnt++;
				if(trial!='y'&&trial!='Y')
				end();
			 }
		else
		{
		cnt=0;
		break;
		}
		       }while(trial=='y'||trial=='Y');
/*--------Title of Inventory Management system--------*/
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar(0,0,640,480);

	setcolor(DARKGRAY);              //rectangles outlining
	rectangle(0,0,639,480);
	rectangle(1,1,638,479);
	setcolor(BLACK);
	rectangle(2,1,637,478);
	rectangle(3,1,636,477);

	settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
	setcolor(BLUE);
	outtextxy(pixTOrc(8),pixTOrc(2),"Inventory Management System");

	setfillstyle(LINE_FILL,DARKGRAY);          //loop to give the effect of enclosing bars
	for(i=15,j=70;i<40||j>40;i++,j--){
		bar(pixTOrc(8),pixTOrc(7),pixTOrc(i),pixTOrc(7.5));      //Declaration:  void far bar(int left, int top, int right, int bottom);
		delay(10);
		bar(pixTOrc(j),pixTOrc(7),pixTOrc(70),pixTOrc(7.5));  //bar from right to left
		delay(20);
	}

	bar(pixTOrc(7),pixTOrc(14),pixTOrc(25),pixTOrc(50));  //bar of main menu

/*--------Title code ends of Inventory Management system--------*/

	//Calling Menu
       store=control_menu();

     closegraph();
      return store;
     }
