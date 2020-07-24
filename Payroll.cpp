//*******************************************************************
// Required header files
//*******************************************************************

 #include <graphics.h>
 #include <fstream.h>
 #include <string.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <ctype.h>
 #include <conio.h>
 #include <dos.h>



//******************************************************************
// Public functions required by many different functions.
//******************************************************************

void statusbar(char[]) ;
void getlinedelchar(char *, int, int, int &) ;
void getline(char *, int) ;

//*******************************************************************
// Class that contains the drawing functions & the main screen.
//*******************************************************************

class draw
{
	public :
		void lineh (int, int, int, char) ;
		void linev (int, int, int, char) ;
		void box   (int, int, int, int, char) ;
		void mscreen () ;
};

//*******************************************************************
// Class contains functions for drawing main menus
//*******************************************************************

class menu
{
	public :
		void main () ;
		int vertical_menu (char [] [20], int, int, int, int) ;
		int horizontal_menu(char [] [20], int, int, int, int);
		void help () ;
};

//*******************************************************************
// Class to control all the functions related to employee
//*******************************************************************

class employee
{
	private :
		int empcode, dd, mm, yy ;
		char empname[31], empaddress[31], empcity[21], emppin[7] ;
		char empphone[10], empdesig[21] ;
		char emphouse, empconv, empsex ;
		float empbasic, emppf, empda, emphra, empca;
		int fcode (int) ;
		int date (int, int, int) ;
		void emp_display (int) ;
	public :
		void emp_add () ;
		void emp_modify () ;
		void emp_del () ;
		void emp_displaycode () ;
		void emp_showlist () ;
		void emp_salslip () ;
		void print (int, int, int, int) ;
};

//*******************************************************************
// CLASS : draw
// FUNCTION : lineh
// DESCRIPTION : To draw a horizontal line   (x1, x2, y)
//*******************************************************************

void draw :: lineh (int row1, int row2, int column, char c)
{
	for (row1; row1 <= row2; row1++)
	{
		gotoxy (row1, column) ;
		cout <<c ;
	}
};

//*******************************************************************
// CLASS : draw
// FUNCTION : linev
// DESCRIPTION : To draw a vertical line (y1, y2, x)
//*******************************************************************

void draw :: linev (int column1, int column2, int row, char c)
{
	for (column1; column1 <= column2; column1++ )
	{
		gotoxy (row, column1) ;
		cout <<c ;
	}
};

//*******************************************************************
// CLASS : draw
// FUNCTION : box
// DESCRIPTION : To draw a box  (x1, y1, x2, y2)
//*******************************************************************

void draw :: box(int row1, int column1, int row2, int column2, char c)
{
	char ch=218 ;
	char c1, c2, c3, c4 ;
	char l1=196, l2=179 ;
	if (c == ch)
	{
		c1 = 218 ;
		c2 = 191 ;
		c3 = 192 ;
		c4 = 217 ;
		l1 = 196 ;
		l2 = 179 ;
	}
	else
	{
		c1 = c ;
		c2 = c ;
		c3 = c ;
		c4 = c ;
		l1 = c ;
		l2 = c ;
	}
	gotoxy(row1,column1) ;
	cout <<c1 ;
	gotoxy(row2,column1) ;
	cout <<c2 ;
	gotoxy(row1,column2) ;
	cout <<c3 ;
	gotoxy(row2,column2) ;
	cout <<c4 ;
	row1++ ;
	row2-- ;
	lineh(row1, row2, column1, l1) ;
	lineh(row1, row2, column2, l1) ;
	row1-- ;
	row2++ ;
	column1++ ;
	column2-- ;
	linev(column1,column2,row1,l2) ;
	linev(column1,column2,row2,l2) ;
}

//*******************************************************************
// CLASS : main_screen
// FUNCTION : mscreen
// DESCRIPTION : To paint the screen with the opening screen.
//*******************************************************************

void draw :: mscreen()
{
	int gd=DETECT, gm ;
	initgraph(&gd, &gm, "\\tc\\bgi") ;
	setcolor(LIGHTGRAY) ;
	rectangle(0, 0, getmaxx(), getmaxy()) ;
	setfillstyle(SOLID_FILL, LIGHTGRAY) ;
	floodfill(getmaxx()/2, getmaxy()/2, LIGHTGRAY) ;
	for(int t = 1; t < 115; t++)
	{
		setcolor(DARKGRAY) ;
		for(long int m = 0; m < 103000.0; m++) ;
			rectangle(getmaxx()/2-t-150, getmaxy()/2+t, getmaxx()/2+t+150, getmaxy()/2-t) ;
		floodfill(getmaxx()/2, getmaxy()/2, DARKGRAY) ;
	}
	setcolor(WHITE) ;
	settextstyle(GOTHIC_FONT, HORIZ_DIR, 7) ;
	settextjustify(CENTER_TEXT, CENTER_TEXT) ;
	outtextxy(getmaxx()/2, getmaxy()/2-60, "COMPUTER" ) ;
	outtextxy(getmaxx()/2, getmaxy()/2+60, "PROJECT" ) ;
	getch();
	for(int j = 0; j < 500; j++)
		for(long int k = 0; k < 40000.0; k++) ;
			setcolor(BLACK) ;
	rectangle(0, 0, getmaxx(), getmaxy()) ;
	setfillstyle(SOLID_FILL, BLACK) ;
	floodfill(getmaxx()/2, getmaxy()/2, BLACK) ;
	for(int i = 1; i < 150; i++)
	{
		setcolor(WHITE) ;
		settextstyle(GOTHIC_FONT, HORIZ_DIR, 4) ;
		settextjustify(CENTER_TEXT, CENTER_TEXT) ;
		outtextxy(120+i, 20+i, "PAYROLL - MANAGEMENT" ) ;
		for(long int j = 0 ;j < 100; j++) ;
			setcolor(BLACK) ;
		settextstyle(GOTHIC_FONT, HORIZ_DIR, 4) ;
		settextjustify(CENTER_TEXT, CENTER_TEXT) ;
		outtextxy(120+i, 20+i, "PAYROLL - MANAGEMENT" ) ;
	}
	setcolor(WHITE) ;
	settextstyle(GOTHIC_FONT, HORIZ_DIR, 4) ;
	settextjustify(CENTER_TEXT, CENTER_TEXT) ;
	outtextxy(120+i, 20+i, "PAYROLL - MANAGEMENT" ) ;
	for(j = 0; j < 250; j++)
		for(k = 0; k < 40000.0; k++) ;
	for(k = i; k > 50; k--)
	{
		setcolor(WHITE) ;
		settextstyle(GOTHIC_FONT, HORIZ_DIR, 4) ;
		settextjustify(CENTER_TEXT, CENTER_TEXT) ;
		outtextxy(120+i, 20.0+k, "PAYROLL - MANAGEMENT" ) ;
		for(long int j = 0; j < 100; j++) ;
			setcolor(BLACK) ;
		settextstyle(GOTHIC_FONT, HORIZ_DIR, 4) ;
		settextjustify(CENTER_TEXT, CENTER_TEXT) ;
		outtextxy(120+i, 20.0+k, "PAYROLL - MANAGEMENT" ) ;
	}
	setcolor(WHITE) ;
	settextstyle(GOTHIC_FONT, HORIZ_DIR, 4) ;
	settextjustify(CENTER_TEXT, CENTER_TEXT) ;
	outtextxy(120+i, 20.0+k, "PAYROLL - MANAGEMENT" ) ;
	for(j = 0; j < 250; j++)
		for(k = 0; k < 40000.0; k++) ;
	for(i = 1; i < 200; i++)
	{
		setcolor(YELLOW) ;
		settextstyle(GOTHIC_FONT, HORIZ_DIR, 5) ;
		settextjustify(CENTER_TEXT, CENTER_TEXT) ;
		outtextxy(0+i, getmaxy()/2-10, "Programmed by : " ) ;
		for(long int j = 0; j < 100; j++) ;
			setcolor(BLACK) ;
		settextstyle(GOTHIC_FONT, HORIZ_DIR, 5) ;
		settextjustify(CENTER_TEXT, CENTER_TEXT) ;
		outtextxy(0+i, getmaxy()/2-10, "Programmed by : " ) ;
	}
	setcolor(YELLOW) ;
	settextstyle(GOTHIC_FONT, HORIZ_DIR, 5) ;
	settextjustify(CENTER_TEXT, CENTER_TEXT) ;
	outtextxy(0+i, getmaxy()/2-10, "Programmed by : " ) ;
	for(j = 0; j < 250; j++)
		for(k = 0; k < 40000.0; k++);
	for(i = 1; i < 300; i++)
	{
		setcolor(GREEN);
		settextstyle(GOTHIC_FONT, HORIZ_DIR, 5);
		settextjustify(CENTER_TEXT, CENTER_TEXT);
		outtextxy(0+i, getmaxy()/2+50, "REETA SAHOO" );
		for(long int j = 0; j < 100; j++);
			setcolor(BLACK);
		settextstyle(GOTHIC_FONT, HORIZ_DIR, 5);
		settextjustify(CENTER_TEXT, CENTER_TEXT);
		outtextxy(0+i, getmaxy()/2+50, "REETA SAHOO" );
	}
	setcolor(GREEN);
	settextstyle(GOTHIC_FONT, HORIZ_DIR, 5);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	outtextxy(0+i, getmaxy()/2+50, "REETA SAHOO ");
	for(j = 0; j < 250; j++)
		for(k = 0; k < 40000.0; k++) ;
	for(i = 1; i < 315; i++)
	{
		setcolor(LIGHTRED) ;
		settextstyle(GOTHIC_FONT, HORIZ_DIR, 5) ;
		settextjustify(CENTER_TEXT, CENTER_TEXT) ;
		outtextxy(0+i, getmaxy()/2+95, "&" ) ;
		for(long int j = 0; j < 10000; j++) ;
			setcolor(BLACK) ;
		settextstyle(GOTHIC_FONT, HORIZ_DIR, 5) ;
		settextjustify(CENTER_TEXT, CENTER_TEXT) ;
		outtextxy(0+i, getmaxy()/2+95, "&" ) ;
	}
	setcolor(LIGHTRED) ;
	settextstyle(GOTHIC_FONT, HORIZ_DIR, 5) ;
	settextjustify(CENTER_TEXT, CENTER_TEXT) ;
	outtextxy(0+i, getmaxy()/2+95, "&"  ) ;
	for(j = 0; j < 250; j++)
		for(k = 0; k < 40000.0; k++) ;
	for(i = 1; i < 450; i++)
	{
		setcolor(GREEN) ;
		settextstyle(GOTHIC_FONT, HORIZ_DIR, 5) ;
		settextjustify(CENTER_TEXT, CENTER_TEXT) ;
		outtextxy(0+i, getmaxy()/2+140, "GAGAN SAHOO" ) ;
		for(long int j = 0; j < 100; j++) ;
			setcolor(BLACK) ;
		settextstyle(GOTHIC_FONT, HORIZ_DIR, 5) ;
		settextjustify(CENTER_TEXT, CENTER_TEXT) ;
		outtextxy(0+i, getmaxy()/2+140, "GAGAN SAHOO" ) ;
	}
	setcolor(GREEN) ;
	settextstyle(GOTHIC_FONT, HORIZ_DIR, 5) ;
	settextjustify(CENTER_TEXT, CENTER_TEXT) ;
	outtextxy(0+i, getmaxy()/2+140, "GAGAN SAHOO" ) ;
	getch();
	for(j = 0; j < 500; j++)
		for(k = 0; k < 40000.0; k++) ;
	for(i = 0; i < 550; i++)
	{
		for(long int j = 0; j < 50000.0; j++) ;
			setcolor(BLACK) ;
		rectangle(0+i, 0, 100+i, getmaxy()) ;
	}
	closegraph() ;
}

//*******************************************************************
// CLASS : menu
// FUNCTION : vertical_menu
// DESCRIPTION : To make vertical menu.
//*******************************************************************

int menu :: vertical_menu(char menu[] [20], int present, int end, int x, int y)
{
	int ex=0 ;
	draw L ;
	L.box(x + 9, y, x + strlen(menu[0]) + 12, y + end + 1, 218) ;
	for (int i=0; i<end; i++)
	{
		gotoxy(x + 10, y + i + 1) ;
		cout <<menu[i] ;
	}
	do
	{
		int tpresent = present ;
		textcolor(BLACK) ;
		textbackground(WHITE) ;
		gotoxy(x + 10,y + present) ;
		cprintf(menu[present - 1]) ;
		textcolor(WHITE) ;
		textbackground(BLACK) ;
		char ch = getch() ;
		switch (ch)
		{
			case 75 : if (present == 1)
					present = end ;
				else
					present-- ;
				break ;
			case 77 : if (present == end)
					present = 1 ;
				else
					present++ ;
				break ;
			case 71 : present = 1 ;
				break ;
			case 79 : present = end ;
				break ;
			case 72 : if (present == 1)
					present = end ;
				else
					present-- ;
				break ;
			case 80 : if (present == end)
					present = 1 ;
				else
					present++ ;
				break ;
			case 13 : ex = 1 ;
				break ;
			case 27 : present = end ;
				ex = 1 ;
		}
		gotoxy(x + 10,y + tpresent) ;
		cprintf(menu[tpresent - 1]) ;
	} while(!ex) ;
	return(present) ;
}

//*******************************************************************
// CLASS : menu
// FUNCTION : horizontal_menu
// DESCRIPTION : To make horizontal menu.
//*******************************************************************

int menu :: horizontal_menu(char menu[] [20], int present, int end, int x, int y)
{
	draw L ;
	int ex=0, i ;
	for (i = 0; i < end; i++)
	{
		gotoxy(x + (i + 2) * 10 - 5, y) ;
		cout <<menu[i] ;
	}
	L.lineh(1, 80, 2, 205) ;
	do
	{
		int tpresent = present ;
		textcolor(BLACK) ;
		textbackground(WHITE) ;
		gotoxy(x + (present + 1) * 10 - 5, y) ;
		cprintf(menu[present - 1]) ;
		textcolor(WHITE) ;
		textbackground(BLACK) ;
		char ch = getch() ;
		switch (ch)
		{
			case 71 : present = 1 ;
				break ;
			case 79 : present = end ;
				break ;
			case 75 : if (present == 1)
					present = end ;
				else
					present-- ;
				break ;
			case 77 : if (present == end)
					present = 1 ;
				else
					present++ ;
				break ;
			case 72 : if (present == 1)
					present = end ;
				else
					present-- ;
				break ;
			case 80 : if (present == end)
					present = 1 ;
				else
					present++ ;
				break ;
			case 13 : ex = 1 ; break ;
			case 27 : present = end ;
				ex = 1 ;
		}
		gotoxy(x + (tpresent + 1) * 10 - 5, y) ;
		cprintf(menu[tpresent - 1]) ;
	} while(!ex) ;
	return(present) ;
}

//*******************************************************************
// CLASS : menu
// FUNCTION : help
// DESCRIPTION : To print the help screen for various important operations.
//*******************************************************************

void menu :: help()
{
	clrscr();
	cout<<"\n\n\n\t\t\tAbout Payroll Management System "
		<<"\n\nPayroll Management System is a full fledged human resource management system "
		<<"\n\n\n 1) Important instructions are displayed at the status bar at the   "
		<<"\n    bottom of the screen."
		<<"\n\n 2) Press escape key to exit the immediate screen at any time"
		<<"\n    during the program."
		<<"\n\n\n\n"
		<<"\t\t\t\t\t\tReeta Sahoo"
		<<"\n\t\t\t\t\t\tGagan Sahoo";
	getch();
	clrscr() ;
	return ;
}

//*******************************************************************
// CLASS : menu
// FUNCTION : main
// DESCRIPTION : To draw the main menu & call related functions
//*******************************************************************

void menu :: main()
{
	int end=5, present=1, upperlim1=5, currentpos1=1, upperlim2=3, currentpos2=1, upperlim3=4, currentpos3=1;
	draw L ;
	char main[] [20] = { " FILE ", " EDIT ", " PRINT ", " HELP ", " EXIT " } ;
	char sub1[] [20] = { "New Employee ", "Display Info ", "Display List ", "Salary Slip  ", "Return       " } ;
	char sub2[] [20] = { "Modify Employee ", "Delete Employee ", "Return          " } ;
	char sub3[] [20] = { "Employee Info ", "Employee List ", "Salary Slip   ", "Return        " } ;
	L.mscreen() ;
	do
	{
		_setcursortype(_NOCURSOR) ;
		present = horizontal_menu(main, present, end, 3, 1) ;
		switch (present)
		{
			case 1 : currentpos1 = vertical_menu(sub1, currentpos1, upperlim1, 3, 3) ;
				employee A ;
				switch (currentpos1)
				{
					case 1 : _setcursortype(_SOLIDCURSOR) ;
						A.emp_add() ;
						getch();
						A.emp_showlist() ;
						getch();
						_setcursortype(_NOCURSOR) ;
						break ;
					case 2 : _setcursortype(_SOLIDCURSOR) ;
						// employee B ;
						getch();
						A.emp_displaycode() ;
						break ;
					case 3 :
						//employee C ;
						A.emp_showlist() ;
						break ;
					case 4 : _setcursortype(_SOLIDCURSOR) ;
						//employee D ;
						A.emp_salslip();
						_setcursortype(_NOCURSOR) ;
						break ;
				}
				clrscr() ;
				break ;
			 case 2 : currentpos2 = vertical_menu(sub2, currentpos2, upperlim2, 13, 3) ;
				switch(currentpos2)
				{
					case 1 : _setcursortype(_SOLIDCURSOR) ;
						employee A ;
						A.emp_modify() ;
						_setcursortype(_NOCURSOR) ;
						break ;
					case 2 : _setcursortype(_NORMALCURSOR) ;
						employee B ;
						B.emp_del() ;
						_setcursortype(_NOCURSOR) ;
						break ;
				}
				clrscr() ;
				break ;
			case 3 : currentpos3 = vertical_menu(sub3, currentpos3, upperlim3, 27, 3) ;
				switch(currentpos3)
				{
					case 1 : _setcursortype(_SOLIDCURSOR) ;
						employee A ;
						A.emp_displaycode() ;
						A.print(1,1,80,23) ;
						_setcursortype(_NOCURSOR) ;
						break ;
					case 2 : _setcursortype(_NORMALCURSOR) ;
						employee B ;
						B.emp_showlist() ;
						B.print(1,1,80,23) ;
						_setcursortype(_NOCURSOR) ;
						break ;
					case 3 : _setcursortype(_NORMALCURSOR) ;
						employee C ;
						C.emp_salslip() ;
						C.print(1,1,80,23) ;
						_setcursortype(_NOCURSOR) ;
						break ;
				}
				clrscr() ;
				break ;
			case 4 : help() ;
				clrscr() ;
				break ;
		}
	} while (present != end);
}

//*******************************************************************
// CLASS : employee
// FUNCTION : fcode
// DESCRIPTION : To return 0 if the given code is not found
//*******************************************************************

int employee :: fcode(int code)
{
	fstream file ;
	file.open("Employee.Dat", ios::in | ios::binary) ;
	file.seekg(0) ;
	int found = 0 ;
	employee temp;
	while (file.read((char *)&temp, sizeof(employee)))
	{
		if (temp.empcode == code)
		{
			found = 1 ;
			break ;
		}
	}
	file.close() ;
	return(found) ;
}

//*******************************************************************
// CLASS : employee
// FUNCTION : date
// DESCRIPTION : To return '0' if the date received is invalid
//*******************************************************************

int employee :: date(int dd, int mm, int yy)
{
	int days=0, valid ;
	if ((yy>1980) && (yy<2099))
		valid = 1 ;
	else
	{
		valid = 0 ;
		return(0) ;
	}
	switch(mm)
	{
		case 1  : days = 31 ;
			break ;
		case 2  : if (yy % 4 == 0)
				days = 29 ; // leap year
			else
				days = 28 ;
			break ;
		case 3  : days = 31 ;
			break ;
		case 4  : days = 30 ;
			break ;
		case 5  : days = 30 ;
			break ;
		case 6  : days = 31 ;
			break ;
		case 7  : days = 31 ;
			break ;
		case 8  : days = 31 ;
			break ;
		case 9  : days = 30 ;
			break ;
		case 10 : days = 31 ;
			break ;
		case 11 : days = 30 ;
			break ;
		case 12 : days = 31 ;
			break ;
		default : valid = 0 ;
			break ;
	}
	if ((dd > 0) && (dd <= days))
		valid = 1 ;
	else
		valid = 0 ;
	return (valid) ;
}

//*******************************************************************
// CLASS : employee
// FUNCTION : emp_display
// DESCRIPTION : to display a record from "Employee.Dat"
//*******************************************************************

void employee :: emp_display(int code)
{
	fstream file ;
	draw L ;
	employee t ;
	char* initial ;
	file.open("Employee.Dat", ios::in | ios::binary) ;
	file.seekg(0) ;
	while (file.read((char *)&t, sizeof(employee)))
	{
		if (t.empcode == code)
		{
			gotoxy(28,2) ;
			cout <<"EMPLOYEE  INFORMATION" ;
			if (t.empsex == 'F')
				initial = "Ms. " ;
			else
				initial = "Mr. " ;
			gotoxy(30,3) ;
			cout <<"EMPLOYEE CODE #" <<t.empcode ;
			L.lineh(2,79,4,240) ;
			gotoxy(20,6) ;
			cout <<"Name              : " <<initial <<t.empname ;
			gotoxy(20,7) ;
			cout <<"Address           : " <<t.empaddress ;
			gotoxy(40,8);
			cout <<t.empcity <<" - " <<t.emppin ;
			gotoxy(20,9) ;
			cout <<"Contact No.       : " <<t.empphone ;
			gotoxy(20,11) ;
			cout <<"Date Of Joining   : " <<t.dd <<"/" <<t.mm <<"/" <<t.yy ;
			gotoxy(20,13) ;
			cout <<"Designation       : " <<t.empdesig ;
			gotoxy(20,15) ;
			cout <<"Accomodation Provided : " <<t.emphouse ;
			gotoxy(20,16) ;
			cout <<"Conveyance Provided   : " <<t.empconv ;
			gotoxy(20,17) ;
			cout <<"Basic Salary      : Rs. " <<t.empbasic ;
			gotoxy(20,18) ;
			cout <<"Provident Fund    : Rs. " <<int((t.emppf/100)*t.empbasic) ;
			gotoxy(20,19) ;
			cout <<"Daily Allowance   : Rs. " <<int((t.empda/100)*t.empbasic) ;
			gotoxy(20,20) ;
			cout <<"Housing Allowance : Rs. " <<int((t.emphra/100)*t.empbasic) ;
			gotoxy(20,21) ;
			cout <<"Conveyance Allow  : Rs. " <<int((t.empca/100)*t.empbasic) ;
			L.lineh(2,79,22,240) ;
		}
	}
	file.close() ;
}

//*******************************************************************
// CLASS : employee
// FUNCTION : emp_add
// DESCRIPTION : To get data about new employee
//*******************************************************************

void employee :: emp_add()
{
	draw L ;
	employee t ;
	char ch, choice='Y';
	char d[3], m[3], y[5], basic[10], pf[6], da[6], ca[6], hra[6];
	int code=0, valid ;
	do
	{
		clrscr() ;
		_setcursortype(_SOLIDCURSOR) ;
		gotoxy(28,2) ;
		cout <<"ADDITION OF NEW EMPLOYEE" ;
		L.lineh(20,59,3,240) ;
		gotoxy(31,4) ;
		cout <<"Employee Code # " ;
		gotoxy(29,5) ;
		cout <<"~~~~~~~~~~~~~~~~~~~~~" ;
		gotoxy(5,8) ;
		cout <<"Name         : ............................." ;
		gotoxy(50,8);
		cout <<"Sex (M/F) : .";
		gotoxy(5,9) ;
		cout <<"Address      : ............................." ;
		gotoxy(50,9) ;
		cout <<"City      : ................." ;
		gotoxy(5,10) ;
		cout <<"Pin Code     : ......" ;
		gotoxy(50,10) ;
		cout <<"Phone No. : ........." ;
		L.lineh(3,78,11,196);
		gotoxy(5,12) ;
		cout <<"JOINING DATE" ;
		gotoxy(5,13) ;
		cout <<"Day   : .." ;
		gotoxy(30,13) ;
		cout <<"Month : .." ;
		gotoxy(54,13) ;
		cout <<"Year  : ...." ;
		L.lineh(3,78,14,196);
		gotoxy(5,15) ;
		cout <<"Designation  : ...................." ;
		L.lineh(3,78,16,196);
		gotoxy(5,17) ;
		cout <<"Accomodation (y/n) : ." ;
		gotoxy(43,17) ;
		cout <<"Conveyance (y/n) : ." ;
		L.lineh(3,78,18,196);
		gotoxy(5,19) ;
		cout <<"Basic Salary       (Rs) :  ........." ;
		gotoxy(5,20);
		cout <<"Provident Fund     (%)  :  ....." ;
		gotoxy(5,21);
		cout <<"Daily Allowance    (%)  :  ....." ;
		fstream file ;
		file.open("Employee.Dat", ios::in | ios::binary) ;
		file.seekg(0) ;
		employee te ;
		while (file.read((char *)&te, sizeof(employee)))
			code = te.empcode ;
		file.close() ;
		code++ ;
		t.empcode = code ;
		gotoxy(47,4) ;
		cout <<t.empcode ;
		do
		{
			valid = 1 ;
			statusbar(" ENTER THE NAME OF THE EMPLOYEE") ;
			_setcursortype(_SOLIDCURSOR) ;
			gotoxy(20,8) ;
			cout<<"                     " ;
			gotoxy(20,8) ;
			getline(t.empname, 29) ;
			if (t.empname[0] == '0')
				return ;
			if (strlen(t.empname) < 1)
			{
				valid = 0 ;
				statusbar("\aENTER CORRECTLY (LENGTH : 1..30)") ;
				getch() ;
				_setcursortype(_SOLIDCURSOR) ;
			}
		} while (!valid) ;
		do
		{
			statusbar("ENTER IF EMPLOYEE IS MALE(M) OR FEMALE(F)") ;
			_setcursortype(_SOLIDCURSOR) ;
			gotoxy(62,8) ;
			clreol() ;
			t.empsex = getch() ;
			if (t.empsex == 27)
				return ;
			t.empsex = toupper(t.empsex) ;
			if ((t.empsex == 27) || (t.empsex == '0'))
				return ;
		} while ((t.empsex != 'M') && (t.empsex != 'F')) ;
		cout <<t.empsex ;
		do
		{
			valid = 1 ;
			statusbar("ENTER ADDRESS OF THE EMPLOYEE") ;
			_setcursortype(_SOLIDCURSOR) ;
			gotoxy(20,9) ;
			cout <<"                     " ;
			gotoxy(20,9) ;
			getline(t.empaddress, 29) ;
			if (t.empaddress[0] == '0')
				return ;
			if (strlen(t.empaddress) < 1)
			{
				valid = 0 ;
				statusbar("\a ENTER CORRECTLY (LENGTH : 1..30)") ;
				getch() ;
				_setcursortype(_SOLIDCURSOR) ;
			}
		} while (!valid) ;
		do
		{
			valid = 1 ;
			statusbar("ENTER CITY OF THE EMPLOYEE") ;
			_setcursortype(_SOLIDCURSOR) ;
			gotoxy(62,9) ;
			clreol() ;
			getline(t.empcity, 17) ;
			if (t.empcity[0] == '0')
				return ;
			if (strlen(t.empcity) < 1)
			{
				valid = 0 ;
				statusbar("\aENTER CORRECLTY (LENGTH : 1..20)") ;
				getch() ;
				_setcursortype(_SOLIDCURSOR) ;
			}
		} while (!valid) ;
		do
		{
			valid = 1 ;
			statusbar("ENTER PIN CODE OF THE EMPLOYEE") ;
			_setcursortype(_SOLIDCURSOR) ;
			gotoxy(20,10) ;
			cout<<"                     " ;
			gotoxy(20,10) ;
			getline(t.emppin, 6) ;
			if (t.emppin[0] == '0')
				return ;
			if (strlen(t.emppin) != 6)
			{
				valid = 0 ;
				statusbar("\aENTER CORRECTLY (LENGTH : 6)") ;
				getch() ;
				_setcursortype(_SOLIDCURSOR) ;
			}
		} while (!valid) ;
		do
		{
			valid = 1 ;
			statusbar("ENTER PHONE NO. OF THE EMPLOYEE OR PRESS <enter> FOR NONE") ;
			_setcursortype(_SOLIDCURSOR) ;
			gotoxy(62,10) ;
			clreol() ;
			getline(t.empphone, 9) ;
			if (t.empphone[0] == '0')
				return ;
			if ((strlen(t.empphone) < 6 && strlen(t.empphone) > 0) || (strlen(t.empphone) > 9))
			{
				valid = 0 ;
				statusbar("\aENTER CORRECTLY") ;
				getch() ;
				_setcursortype(_SOLIDCURSOR) ;
			}
		} while (!valid) ;
		if (strlen(t.empphone) == 0)
			strcpy(t.empphone,"---") ;
		do
		{
			valid = 1 ;
			do
			{
				statusbar("ENTER DAY OF JOINING") ;
				_setcursortype(_SOLIDCURSOR) ;
				gotoxy(13,13) ;
				cout <<"          " ;
				gotoxy(13,13);
				getline(d, 2) ;
				t.dd = atoi(d) ;
				if (strlen(d) == 0)
				{
					statusbar("\aENTER CORRECTLY") ;
					getch() ;
					_setcursortype(_SOLIDCURSOR) ;
				}
				if (d[0] == 27)
					return ;
			} while (t.dd == 0) ;
			do
			{
				statusbar("ENTER MONTH OF JOINING") ;
				_setcursortype(_SOLIDCURSOR) ;
				gotoxy(38,13) ;
				cout <<"          " ;
				gotoxy(38,13);
				getline(m, 2) ;
				t.mm = atoi(m) ;
				if (m[0] == 27)
					return ;
				if (strlen(m) == 0)
				{
					statusbar("\aENTER CORRECTLY") ;
					getch() ;
					_setcursortype(_SOLIDCURSOR) ;
				}
			} while (t.mm == 0) ;
			do
			{
				statusbar(" ENTER YEAR OF JOINING") ;
				_setcursortype(_SOLIDCURSOR) ;
				gotoxy(62,13) ;
				clreol() ;
				getline(y, 4) ;
				t.yy = atoi(y) ;
				if (y[0] == 27)
					return ;
				if (strlen(y) == 0)
				{
					statusbar("\aENTER CORRECTLY") ;
					getch() ;
					_setcursortype(_SOLIDCURSOR) ;
				}
			} while (t.yy == 0) ;
			valid = date(t.dd, t.mm, t.yy) ;
			if (valid == 0)
			{
				statusbar("\a ENTER CORRECTLY") ;
				getch() ;
				_setcursortype(_SOLIDCURSOR) ;
				gotoxy(38,13) ;
				cout <<"          " ;
				gotoxy(62,13) ;
				clreol() ;
			}
		} while (!valid) ;
		do
		{
			valid = 1 ;
			statusbar("ENTER DESIGNATION OF THE EMPLOYEE") ;
			_setcursortype(_SOLIDCURSOR) ;
			gotoxy(20,15) ;
			clreol() ;
			getline(t.empdesig, 20) ;
			if (t.empdesig[0] == '0')
				return ;
			if (strlen(t.empdesig) < 1)
			{
				valid = 0 ;
				statusbar("\a ENTER CORRECLTY (LENGTH : 1..20)") ;
				getch() ;
				_setcursortype(_SOLIDCURSOR) ;
			}
		} while (!valid) ;
		do
		{
			statusbar("ENTER IF ACCOMODATION IS ALLOTED TO EMPLOYEE OR NOT");
			_setcursortype(_SOLIDCURSOR) ;
			gotoxy(26,17) ;
			cout <<"  " ;
			gotoxy(26,17) ;
			t.emphouse = getch() ;
			if (t.emphouse == 27)
				return ;
			t.emphouse = toupper(t.emphouse) ;
			if (t.emphouse == '0')
				return ;
		} while (t.emphouse != 'Y' && t.emphouse != 'N') ;
		cout <<t.emphouse ;
		do
		{
			gotoxy(0,25) ;
			statusbar(" ENTER IF CONVEIENCE ALLOWANCE IS ALLOTED TO EMPLOYEE OR NOT") ;
			_setcursortype(_SOLIDCURSOR) ;
			gotoxy(62,17) ;
			clreol() ;
			t.empconv = getch() ;
			t.empconv = toupper(t.empconv) ;
			if (t.empconv == 27)
				return ;
			if (t.empconv == '0')
				return ;
		} while (t.empconv != 'Y' && t.empconv != 'N') ;
		cout <<t.empconv ;
		do
		{
			valid = 1 ;
			statusbar(" ENTER BASIC SALARY OF THE EMPLOYEE") ;
			_setcursortype(_SOLIDCURSOR) ;
			gotoxy(32,19) ;
			clreol() ;
			getline(basic,9) ;
			t.empbasic = atof(basic) ;
			if (basic[0] == 27)
				return ;
			if ((strlen(basic) == 0) || (t.empbasic>100000.0))
			{
				valid = 0;
				statusbar("\aSHOULD NOT BE GREATER THAN 100000") ;
				getch() ;
				_setcursortype(_SOLIDCURSOR) ;
			}
		} while (!valid) ;
		do
		{
			valid = 1 ;
			statusbar(" ENTER PERCENTAGE OF BASIC SALARY TAKEN AS PF") ;
			_setcursortype(_SOLIDCURSOR) ;
			gotoxy(32,20) ;
			clreol() ;
			getline(pf,5) ;
			t.emppf = atof(pf) ;
			if (pf[0] == 27)
				return ;
			if ((strlen(pf) == 0) || (t.emppf>100))
			{
				valid = 0;
				statusbar("\a SHOULD NOT BE GREATER THAN 100 %") ;
				getch() ;
				_setcursortype(_SOLIDCURSOR) ;
			}
		} while (!valid) ;
		do
		{
			valid = 1 ;
			statusbar(" ENTER PERCENTAGE OF BASIC SALARY TAKEN AS DA") ;
			_setcursortype(_SOLIDCURSOR) ;
			gotoxy(32,21) ;
			clreol() ;
			getline(da,5) ;
			t.empda = atof(da) ;
			if (da[0] == 27)
				return ;
			if ((strlen(da) == 0) || (t.empda>100))
			{
				valid = 0;
				statusbar("\a SHOULD NOT BE GREATER THAN 100 %") ;
				getch() ;
				_setcursortype(_SOLIDCURSOR) ;
			}
		} while (!valid) ;
		if (t.emphouse == 'Y')
		{
			gotoxy(5,22) ;
			cout <<"House Rent Allowance (%):  ....." ;
			do
			{
				valid = 1 ;
				statusbar(" ENTER PERCENTAGE OF BASIC SALARY TAKEN AS HRA") ;
				_setcursortype(_SOLIDCURSOR) ;
				gotoxy(32,22) ;
				cout <<"  " ;
				gotoxy(32,22) ;
				getline(hra,5) ;
				t.emphra = atof(hra) ;
				if (hra[0] == 27)
					return ;
				if ((strlen(hra) == 0) || (t.emphra>100))
				{
					valid = 0;
					statusbar("\a SHOULD NOT BE GREATER THAN 100 %") ;
					getch() ;
					_setcursortype(_SOLIDCURSOR) ;
				}
			} while (!valid) ;
		}
		else
			t.emphra = 0 ;
		if (t.empconv == 'Y')
		{
			gotoxy(45,22) ;
			cout <<"Conveyance Allowance (%) :  ....." ;
			do
			{
				valid = 1 ;
				statusbar(" ENTER PERCENTAGE OF BASIC SALARY TAKEN AS CA") ;
				_setcursortype(_SOLIDCURSOR) ;
				gotoxy(72,22) ;
				clreol() ;
				getline(ca,5) ;
				t.empca = atof(ca) ;
				if (ca[0] == 27)
					return ;
				if ((strlen(ca) == 0) || (t.empca>100))
				{
					valid = 0;
					statusbar("\a SHOULD NOT BE GREATER THAN 100 %") ;
					getch() ;
					_setcursortype(_SOLIDCURSOR) ;
				}
			} while (!valid) ;
		}
		else
			t.empca = 0 ;
		do
		{
			statusbar("\a Do you wish to save (y/n) : ") ;
			ch = getch() ;
			ch = toupper(ch) ;
			if (ch == '0'|| ch == 27)
				return ;
		} while (ch != 'Y' && ch != 'N') ;
		if (ch == 'N')
			return ;
		file.open("Employee.Dat", ios::app | ios::out | ios::binary) ;
		file.write((char *)&t, sizeof(employee)) ;
		file.close() ;
		statusbar("\a Add any more (y/n) : ") ;
		do
		{
			choice = getch() ;
			choice = toupper(choice) ;
			if (choice == 13)
				choice = 'Y' ;
			if (choice == 27)
				choice = 'N' ;
		} while((choice != 'Y') && (choice !='N'));
	} while(choice == 'Y');
}

//*******************************************************************
// CLASS : employee
// FUNCTION : emp_modify
// DESCRIPTION : To provide with necessary data required for
//               modification of a given record
//*******************************************************************

void employee :: emp_modify()
{
	clrscr() ;
	draw L ;
	employee t ;
	int code, valid ;
	char ch, house='N', conv='N', choice='Y' ;
	char address[31], city[21], pin[7], phone[10], desig[21] ;
	char tbasic[10], tpf[6], tda[6], tca[6], thra[6] ;
	float basic=0, pf=0, da=0, ca=0, hra=0 ;
	do
	{
		gotoxy(72,2) ;
		cout <<"Esc=EXIT" ;
		gotoxy(5,5) ;
		cout <<"Enter code of the Employee : " ;
		cin >>code ;
		if (code == 0)
			return ;
		clrscr() ;
		if (!fcode(code))
		{
			gotoxy(30,24) ;
			cout <<"\a Record not found" ;
			getch() ;
			return ;
		}
		emp_display(code) ;
		gotoxy(72,2) ;
		cout <<"<0>=EXIT" ;
		gotoxy(24,2) ;
		cout <<"MODIFICATION OF EMPLOYEE RECORD" ;
		do
		{
			statusbar("\a Do you wish to modify this record (y/n) ") ;
			ch = getch() ;
			ch = toupper(ch) ;
			if (ch == '0')
				return ;
			if (ch == 13 )
				ch = 'Y' ;
			if (ch == 27 )
				ch = 'N' ;
		} while (ch != 'Y' && ch != 'N') ;
		if (ch == 'N')
			return ;
		clrscr() ;
		fstream file ;
		file.open("Employee.Dat", ios::in | ios::binary) ;
		file.seekg(0) ;
		while (file.read((char *)&t, sizeof(employee)))
		{
			if (t.empcode == code)
				break ;
		}
		gotoxy(72,2) ;
		cout <<"Esc=EXIT" ;
		gotoxy(26,2) ;
		cout <<"MODIFICATION OF NEW EMPLOYEE" ;
		L.lineh(20,59,3,240) ;
		gotoxy(31,4) ;
		cout <<"Employee Code # " <<code ;
		gotoxy(29,5) ;
		cout <<"~~~~~~~~~~~~~~~~~~~~~" ;
		gotoxy(5,8) ;
		cout <<"Name         : " ;
		gotoxy(50,8);
		cout <<"Sex (M/F) : ";
		gotoxy(5,9) ;
		cout <<"Address      : ............................." ;
		gotoxy(50,9) ;
		cout <<"City      : ................." ;
		gotoxy(5,10) ;
		cout <<"Pin Number   : ......" ;
		gotoxy(50,10) ;
		cout <<"Phone No. : ........." ;
		L.lineh(3,78,11,196);
		gotoxy(5,12) ;
		cout <<"JOINING DATE" ;
		gotoxy(5,13) ;
		cout <<"Day   :   ";
		gotoxy(30,13) ;
		cout <<"Month :   " ;
		gotoxy(54,13) ;
		cout <<"Year  :     " ;
		L.lineh(3,78,14,196);
		gotoxy(5,15) ;
		cout <<"Designation  : ...................." ;
		L.lineh(3,78,16,196);
		gotoxy(5,17) ;
		cout <<"Accomodation (y/n) : ." ;
		gotoxy(43,17) ;
		cout <<"Conveyance (y/n) : ." ;
		L.lineh(3,78,18,196);
		gotoxy(5,19) ;
		cout <<"Basic Salary       (Rs) :  ........." ;
		gotoxy(5,20) ;
		cout <<"Provident Fund     (%)  :  ....." ;
		gotoxy(5,21) ;
		cout <<"Daily Allowance    (%)  :  ....." ;
		gotoxy(20,8) ;
		cout <<t.empname ;
		gotoxy(62,8) ;
		cout <<t.empsex ;
		gotoxy(13,13) ;
		cout <<t.dd ;
		gotoxy(38,13) ;
		cout <<t.mm ;
		gotoxy(62,13) ;
		cout <<t.yy ;
		do
		{
			valid = 1 ;
			statusbar(" ENTER ADDRESS OF THE EMPLOYEE OR PRESS <enter> FOR NO CHANGE") ;
			_setcursortype(_SOLIDCURSOR) ;
			gotoxy(20,9) ;
			cout<<"                     " ;
			gotoxy(20,9) ;
			getline(address, 29) ;
			if (address[0] == '0')
				return ;
			if (strlen(address) > 30)
			{
				valid = 0 ;
				statusbar("\a Enter correctly (Range: 1..30)") ;
				getch() ;
				_setcursortype(_SOLIDCURSOR) ;
			}
		} while (!valid) ;
		if (strlen(address) == 0)
		{
			strcpy(address, t.empaddress) ;
			gotoxy(20,9) ;
			cout <<address ;
		}
		do
		{
			valid = 1 ;
			statusbar(" ENTER CITY OF THE EMPLOYEE OR PRESS <enter> FOR NO CHANGE") ;
			_setcursortype(_SOLIDCURSOR) ;
			gotoxy(62,9) ;
			clreol() ;
			getline(city, 17) ;
			if (city[0] == '0')
				return ;
			if (strlen(city) > 18)
			{
				valid = 0 ;
				statusbar("\a Enter correctly (Length : 1..18)") ;
				getch() ;
				_setcursortype(_SOLIDCURSOR) ;
			}
		} while (!valid) ;
		if (strlen(city) == 0)
		{
			strcpy(city, t.empcity) ;
			gotoxy(62,9) ;
			cout <<city ;
		}
		do
		{
			valid = 1 ;
			statusbar(" ENTER PIN CODE OR PRESS <enter> FOR NO CHANGE") ;
			_setcursortype(_SOLIDCURSOR) ;
			gotoxy(20,10) ;
			cout<<"                     " ;
			gotoxy(20,10) ;
			getline(pin, 6) ;
			if (pin[0] == '0')
				return ;
			if (strlen(pin) != 6 && strlen(pin) > 1)
			{
				valid = 0 ;
				statusbar("\a Enter correctly (Length : 6)") ;
				getch() ;
				_setcursortype(_SOLIDCURSOR) ;
			}
		} while (!valid) ;
		if (strlen(pin) == 0)
		{
			strcpy(pin, t.emppin) ;
			gotoxy(20,10) ;
			cout <<pin ;
		}
		do
		{
			valid = 1 ;
			statusbar(" ENTER PHONE NO. OF THE EMPLOYEE OR PRESS <enter> FOR NO CHANGE") ;
			_setcursortype(_SOLIDCURSOR) ;
			gotoxy(62,10) ;
			clreol() ;
			getline(phone, 9) ;
			if (phone[0] == '0')
				return ;
			if ((strlen(phone) < 6 && strlen(phone) > 0) || (strlen(phone) > 9))
			{
				valid = 0 ;
				statusbar("\a Enter correctly") ;
				getch() ;
				_setcursortype(_SOLIDCURSOR) ;
			}
		} while (!valid) ;
		if (strlen(phone) == 0)
		{
			strcpy(phone, t.empphone) ;
			gotoxy(62,10) ;
			cout <<phone ;
		}
		do
		{
			valid = 1 ;
			statusbar(" ENTER DESIGNATION OF THE EMPLOYEE OR PRESS <enter> FOR NO CHANGE") ;
			_setcursortype(_SOLIDCURSOR) ;
			gotoxy(20,15) ;
			clreol() ;
			getline(desig, 20) ;
			if (desig[0] == '0')
				return ;
			if (strlen(desig) > 20)
			{
				valid = 0 ;
				statusbar("\a Enter correctly (Range: 1..20)") ;
				getch() ;
				_setcursortype(_SOLIDCURSOR) ;
			}
		} while (!valid) ;
		if (strlen(desig) == 0)
		{
			strcpy(desig, t.empdesig) ;
			gotoxy(20,15) ;
			cout <<desig ;
		}
		do
		{
			statusbar(" ALLOTED ACCOMODATION ?(y/n) OR PRESS <enter> FOR NO CHANGE") ;
			_setcursortype(_SOLIDCURSOR) ;
			gotoxy(26,17) ;
			cout <<"           " ;
			gotoxy(26,17) ;
			house = getch() ;
			house = toupper(house) ;
			if (house == 27)
				return ;
			if (house == 13)
			{
				house = t.emphouse ;
				gotoxy(26,17) ;
			}
		} while (house != 'Y' && house != 'N') ;
		cout <<house ;
		do
		{
			statusbar(" ALLOTED CONVEYANCE ALLOWANCE ?(y/n) OR PRESS <enter> FOR NO CHANGE") ;
			_setcursortype(_SOLIDCURSOR) ;
			gotoxy(62,17) ;
			clreol() ;
			conv = getch() ;
			conv = toupper(conv) ;
			if (conv == 27)
				return ;
			if (conv == 13)
			{
				conv = t.empconv ;
				gotoxy(62,17) ;
			}
		} while (conv != 'Y' && conv != 'N') ;
		cout <<conv ;
		do
		{
			valid = 1 ;
			statusbar(" ENTER BASIC SALARY OF THE EMPLOYEE");
			_setcursortype(_SOLIDCURSOR) ;
			gotoxy(32,19) ;
			clreol() ;
			getline(tbasic,9) ;
			basic = atof(tbasic) ;
			if (basic > 100000.0)
			{
				valid = 0 ;
				statusbar("\a SHOULD NOT BE GREATER THAN 100000") ;
				getch() ;
				_setcursortype(_SOLIDCURSOR) ;
			}
		} while (!valid) ;
		if (strlen(tbasic) == 0)
		{
			basic = t.empbasic ;
			gotoxy(32,19) ;
			cout <<basic ;
		}
		do
		{
			valid = 1 ;
			statusbar(" ENTER PERCENTAGE OF BASIC SALARY TAKEN AS PF") ;
			_setcursortype(_SOLIDCURSOR) ;
			gotoxy(32,20) ;
			clreol() ;
			getline(tpf,5) ;
			pf = atof(tpf) ;
			if (pf > 100)
			{
				valid = 0 ;
				statusbar("\a SHOULD NOT BE GREATER THAN 100 %") ;
				getch() ;
				_setcursortype(_SOLIDCURSOR) ;
			}
		} while (!valid) ;
		if (strlen(tpf) == 0)
		{
			pf = t.emppf ;
			gotoxy(32,20) ;
			cout <<pf ;
		}
		do
		{
			valid = 1 ;
			statusbar(" ENTER PERCENTAGE OF BASIC SALARY TAKEN AS DA") ;
			_setcursortype(_SOLIDCURSOR) ;
			gotoxy(32,21) ;
			clreol() ;
			getline(tda,5) ;
			da = atof(tda) ;
			if (da > 100)
			{
				valid = 0 ;
				statusbar("\a SHOULD NOT BE GREATER THAN 100 %");
				getch() ;
				_setcursortype(_SOLIDCURSOR) ;
			}
		} while (!valid) ;
		if (strlen(tda) == 0)
		{
			da = t.empda ;
			gotoxy(32,21) ;
			cout <<da ;
		}
		if (house == 'Y')
		{
			gotoxy(5,22) ;
			cout <<"House Rent Allowance (%):  ....." ;
			do
			{
				valid = 1 ;
				statusbar(" ENTER PERCENTAGE OF BASIC SALARY TAKEN AS HRA");
				_setcursortype(_SOLIDCURSOR) ;
				gotoxy(32,22) ;
				cout <<"  " ;
				gotoxy(32,22) ;
				getline(thra,5) ;
				hra = atof(thra) ;
				if (hra > 100)
				{
					valid = 0 ;
					statusbar("\a SHOULD NOT BE GREATER THAN 100 %") ;
					getch() ;
					_setcursortype(_SOLIDCURSOR) ;
				}
				if (strlen(tda) == 0)
				{
					hra = t.emphra ;
					gotoxy(32,22) ;
					cout <<hra ;
				}
				else
					hra = 0 ;
			} while (!valid) ;
		}
		if (conv == 'Y')
		{
			gotoxy(45,22) ;
			cout <<"Conveyance Allowance (%) :  ....." ;
			do
			{
				valid = 1 ;
				statusbar(" ENTER PERCENTAGE OF BASIC SALARY TAKEN AS CA") ;
				_setcursortype(_SOLIDCURSOR) ;
				gotoxy(72,22) ;
				clreol();
				getline(tca,5) ;
				ca = atof(tca) ;
				if (ca > 100)
				{
					valid = 0 ;
					statusbar("\a SHOULD NOT BE GREATER THAN 100 %") ;
					getch() ;
					_setcursortype(_SOLIDCURSOR) ;
				}
				if (strlen(tca) == 0)
				{
					ca = t.empca ;
					gotoxy(72,22) ;
					cout <<ca ;
				}
				else
					ca = 0 ;
			} while (!valid) ;
		}
		strcpy(t.empaddress, address) ;
		strcpy(t.empcity, city) ;
		strcpy(t.emppin, pin) ;
		strcpy(t.empphone, phone) ;
		strcpy(t.empdesig, desig) ;
		t.empcode = code ;
		t.emphouse = house ;
		t.empconv = conv ;
		t.empbasic = basic ;
		t.emppf = pf ;
		t.empda = da ;
		t.emphra = hra ;
		t.empca = ca ;
		employee te ;
		file.close();	// change by reeta
		fstream file1 ;
		file.open("Employee.Dat", ios::in | ios::binary) ;
		file1.open("Tempmod.Dat", ios::out | ios::binary) ;
		file.seekg(0) ;
		while (file.read((char *)&te, sizeof(employee)))
		{
			if (t.empcode != te.empcode)
				file1.write((char *)&te, sizeof(employee)) ;
			else
				break ;
		}
		file1.write((char *)&t, sizeof(employee)) ;
		while (file.read((char *)&te, sizeof(employee)))
			file1.write((char *)&te, sizeof(employee)) ;
		file.close() ;
		file1.close() ;
		file.open("Employee.Dat", ios::out | ios::binary) ;
		file1.open("Tempmod.Dat", ios::in | ios::binary) ;
		file1.seekg(0) ;
		while (file1.read((char *)&t, sizeof(employee)))
		{
			file.write((char *)&t, sizeof(employee)) ;
		}
		file.close() ;
		file1.close() ;
		gotoxy(5,25) ;
		clreol() ;
		do
		{
			statusbar("\a Do you wish to save (y/n) ") ;
			ch = getch() ;
			ch = toupper(ch) ;
			if (ch == '0')
				return ;
		} while (ch != 'Y' && ch != 'N') ;
		if (ch == 'N')
			return ;
		statusbar(" Record Modified.") ;
		getch() ;
		statusbar("\a Modify any more (y/n) : ") ;
		do
		{
			choice = getch() ;
			choice = toupper(choice) ;
			if (choice == 13)
				choice = 'Y' ;
			if (choice == 27)
				choice = 'N' ;
		} while((choice != 'Y') && (choice !='N'));
	} while(choice == 'Y');
}

//*******************************************************************
// CLASS : employee
// FUNCTION : del
// DESCRIPTION : To delete a record in "Employee.Dat"
//*******************************************************************

void employee :: emp_del()
{
	clrscr() ;
	employee t ;
	char ch ;
	int code ;
	gotoxy(72,2) ;
	cout <<"<0>=EXIT" ;
	gotoxy(5,5) ;
	cout <<"Enter code of the Employee : " ;
	cin >>code ;
	if (code == 0)
		return ;
	clrscr() ;
	if (!fcode(code))
	{
		gotoxy(30,24) ;
		cout <<"\a Record not found" ;
		getch() ;
		return ;
	}
	gotoxy(72,2) ;
	cout <<"<0>=EXIT" ;
	gotoxy(23,1) ;
	cout <<"DELETION OF THE EMPLOYEE RECORD" ;
	emp_display(code) ;
	do
	{
		statusbar("\a Do you wish to remove this record (y/n) ") ;
		ch = getch() ;
		if (ch == 27)
			return ;
		if (ch == 13)
			ch = 'y' ;
		ch = toupper(ch) ;
		if (ch == '0')
			return ;
	} while (ch != 'Y' && ch != 'N') ;
	if (ch == 'N')
		return ;
	fstream file ;
	fstream file1 ;
	file.open("Employee.Dat", ios::in | ios::binary) ;
	file1.open("Tempdel.Dat", ios::out | ios::binary) ;
	file.seekg(0) ;
	while (file.read((char *)&t, sizeof(employee)))
	{
		if (t.empcode != code)
			file1.write((char *)&t, sizeof(employee)) ;
	}
	file.close() ;
	file1.close() ;
	file.open("Employee.Dat", ios::out | ios::binary) ;
	file1.open("Tempdel.Dat", ios::in | ios::binary) ;
	file1.seekg(0) ;
	while (file1.read((char *)&t, sizeof(employee)))
	{
		file.write((char *)&t, sizeof(employee)) ;
	}
	file.close() ;
	file1.close() ;
	clrscr() ;
	statusbar("\a Record Deleted") ;
	getch() ;
	statusbar("   Press any key to continue...") ;
	getch() ;
}

//*******************************************************************
// CLASS : employee
// FUNCTION : emp_displaycode
// DESCRIPTION : To obtain code for displaying a record
//*******************************************************************

void employee :: emp_displaycode()
{
	clrscr() ;
	int code ;
	gotoxy(72,2) ;
	cout <<"<0>=EXIT" ;
	gotoxy(5,5) ;
	_setcursortype(_SOLIDCURSOR) ;
	cout <<"Enter code of the Employee : " ;
	cin >>code;
	if (code == 0)
		return ;
	clrscr() ;
	if (!fcode(code))
	{
		_setcursortype(_NOCURSOR) ;
		gotoxy(30,25) ;
		cout <<"\a Record not found" ;
		getch() ;
		return ;
	}
	emp_display(code) ;
	statusbar("   Press any key to continue...") ;
	getch() ;
}

//*******************************************************************
// CLASS : employee
// FUNCTION : emp_showlist
// DESCRIPTION : To display the list of employees
//*******************************************************************

void employee :: emp_showlist()
{
	clrscr() ;
	employee t ;
	draw L ;
	int row = 6, found=0, flag=0 ;
	int d1, m1, y1 ;
	char ch ;
	struct date d;
	getdate(&d) ;
	d1 = d.da_day ;
	m1 = d.da_mon ;
	y1 = d.da_year ;
	gotoxy(23,2) ;
	cout <<"LIST OF EMPLOYEES AS ON " <<d1 <<"." <<m1 <<"." <<y1 ;
	L.lineh(1,80,3,240) ;
	gotoxy(12,4) ;
	cout <<"CODE #              NAME                   DESIGNATION" ;
	gotoxy(1,5) ;
	L.lineh(11,72,5,205) ;
	L.linev(4,22,10,186) ;
	L.linev(4,22,19,186) ;
	L.linev(4,22,51,186) ;
	L.linev(4,22,72,186) ;
	L.lineh(1,80,23,240) ;
	fstream file ;
	file.open("Employee.dat", ios::in | ios::binary) ;
	file.seekg(0) ;
	while (file.read((char *)&t, sizeof(employee)))
	{
		flag = 0 ;
		found = 1 ;
		gotoxy(12,row) ;
		cout <<t.empcode ;
		gotoxy(21,row) ;
		cout <<t.empname ;
		gotoxy(53,row) ;
		cout <<t.empdesig ;
		if (row == 18)
		{
			flag = 1 ;
			row = 6 ;
			statusbar(" Press any key to continue or Press <ESC> to exit") ;
			ch = getch() ;
			if (ch == 27)
				break ;
			clrscr() ;
			gotoxy(31,2) ;
			cout <<"LIST OF EMPLOYEES" ;
			L.lineh(1,90,3,240);
			gotoxy(2,4) ;
			cout <<"CODE #            NAME                      DESIGNATION";
			gotoxy(1,5) ;
			cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
		}
		else
			row++ ;
	}
	if (!found)
	{
		gotoxy(26,14) ;
		cout <<"\a Records not found" ;
	}
	if (!flag)
	{
		statusbar("   Press any key to continue...") ;
		getch() ;
	}
	file.close () ;
}

//*******************************************************************
// CLASS : employee
// FUNCTION : emp_salslip
// DESCRIPTION : To print the salary slip of an employee on the screen
//*******************************************************************

void employee :: emp_salslip()
{
	clrscr() ;
	employee t ;
	float hra=0, ca=0, da=0, pf=0, ot=0, advance=0, allowance=0, deduction=0, netsalary=0 ;
	int code, valid=0, days, hours ;
	int year ;
	char tdays[3], thours[4], tadvance[6], month[10] ;
	gotoxy(72,2) ;
	cout <<"<0>=EXIT" ;
	gotoxy(5,5) ;
	cout <<"Enter code of the Employee : " ;
	cin >>code ;
	if (code == 0)
		return ;
	if (!fcode(code))
	{
		clrscr() ;
		gotoxy(30,25) ;
		cout <<"\a Record not found" ;
		getch() ;
		return ;
	}
	clrscr() ;
	gotoxy(5,8) ;
	cout <<"Enter month for which SALARY SLIP is to be generated : " ;
	cin >>month ;
	gotoxy(5,11) ;
	cout <<"Enter year for which SALARY SLIP is to be generated  : " ;
	cin >>year ;
	clrscr() ;
	fstream file ;
	file.open("Employee.Dat", ios::in | ios::binary) ;
	file.seekg(0) ;
	while (file.read((char *)&t, sizeof(employee)))
	{
		if (t.empcode == code)
			break ;
	}
	file.close() ;
	draw L ;
	L.lineh(1,80,1,223) ;
	L.linev(1,23,1,222) ;
	L.linev(1,23,79,222) ;
	L.lineh(1,80,23,223) ;
	gotoxy(32,2) ;
	cout <<"Pearl Software" ;
	L.lineh(3,78,3,175) ;
	gotoxy(24,4) ;
	cout <<"SALARY SLIP  -  " <<month <<", " <<year ;
	L.lineh(3,78,5,196) ;
	gotoxy(4,6) ;
	cout <<"Employee Name : " <<t.empname ;
	gotoxy(48,6) ;
	cout <<"Designation : " <<t.empdesig ;
	L.box(4,7,76,21,218) ;
	do
	{
		valid = 1 ;
		statusbar(" ENTER NO. OF DAYS WORKED IN THE MONTH ") ;
		_setcursortype(_SOLIDCURSOR) ;
		gotoxy(25,10) ;
		cout <<"No. of Days Worked : " ;
		getline(tdays,2) ;
		days = atoi(tdays) ;
		if (tdays[0] == 27)
			return ;
		if (days > 26)
		{
			valid = 0 ;
			statusbar("\a CANNOT BE GREATER THAN 26 ") ;
			getch() ;
			_setcursortype(_SOLIDCURSOR) ;
		}
	} while (!valid) ;
	do
	{
		valid = 1 ;
		statusbar(" ENTER NO. OF HOURS WORKED OVER TIME ") ;
		_setcursortype(_SOLIDCURSOR) ;
		gotoxy(25,12) ;
		cout <<"Overtime hours     : " ;
		getline(thours,3) ;
		hours = atoi(thours) ;
		if (thours[0] == 27)
			return ;
		if (hours > 41)
		{
			valid = 0 ;
			statusbar("\a MORE THAN 40 Hrs. OVERTIME NOT PERMITTED ") ;
			getch() ;
			_setcursortype(_SOLIDCURSOR) ;
		}
	} while (!valid) ;
	gotoxy(25, 13);
	cout << "Basic salary is : " << t.empbasic;
	do
	{
		valid = 1 ;
		statusbar(" ENTER AMOUNT TAKEN AS ADVANCE ") ;
		_setcursortype(_SOLIDCURSOR) ;
		gotoxy(25,14) ;
		cout <<"Advance amount (Rs): " ;
		getline(tadvance,6) ;
		advance = atof(tadvance) ;
		if (tadvance[0] == 27)
			return ;
		if (advance > t.empbasic)
		{
			valid = 0 ;
			statusbar("\a ADVANCE CANNOT BE GREATER THAN BASIC PAY ") ;
			getch() ;
			_setcursortype(_SOLIDCURSOR) ;
		}
	} while (!valid) ;
	clrscr();

	L.lineh(1,80,1,223) ;
	L.linev(1,23,1,222) ;
	L.linev(1,23,79,222) ;
	L.lineh(1,80,23,223) ;
	gotoxy(32,2) ;
	cout <<"Pearl Software" ;
	L.lineh(3,78,3,175) ;
	gotoxy(24,4) ;
	cout <<"SALARY SLIP  -  " <<month <<", " <<year ;
	L.lineh(3,78,5,196) ;
	gotoxy(4,6) ;
	cout <<"Employee Name : " <<t.empname ;
	gotoxy(48,6) ;
	cout <<"Designation : " <<t.empdesig ;
	L.box(4,7,76,21,218) ;

	_setcursortype(_NOCURSOR) ;
	gotoxy(25,10) ;
	cout <<"                               " ;
	gotoxy(25,12) ;
	cout <<"                               " ;
	gotoxy(25,14) ;
	cout <<"                               " ;
	gotoxy(7,8) ;
	cout <<"BASIC SALARY                             : Rs." ;
	gotoxy(7,10) ;
	cout <<"ALLOWANCE" ;
	gotoxy(9,11) ;
	cout <<"Daily Allowance       : Rs." ;
	gotoxy(9,12) ;
	cout <<"Over Time             : Rs." ;
	gotoxy(9,13) ;
	cout <<"Conveyance Allowance  : Rs." ;
	gotoxy(9,14) ;
	cout <<"House Rent Allowance  : Rs." ;
	gotoxy(7,16) ;
	cout <<"DEDUCTIONS" ;
	gotoxy(9,17) ;
	cout <<"Provident Fund        : Rs." ;
	gotoxy(9,18) ;
	cout <<"Advance Taken         : Rs." ;
	gotoxy(9,20) ;
	cout <<"N E T   S A L A R Y                    : Rs." ;
	hra = int((t.emphra  *  t.empbasic)/100) ;
	ca = int((t.empca   *  t.empbasic)/100) ;
	da = int(((t.empda  *  t.empbasic)/100) * days) ;
	pf = int((t.emppf   *  t.empbasic)/100) ;
	ot = int((hours) * (t.empbasic/160)) ;
	allowance = hra + ca + da + ot + t.empbasic ;
	deduction = pf + advance;
	netsalary = allowance - deduction ;
	gotoxy(54,8) ;
	cout <<t.empbasic ;
	gotoxy(37,11) ;
	cout <<da ;
	gotoxy(37,12) ;
	cout <<ot ;
	gotoxy(37,13) ;
	cout <<ca ;
	gotoxy(37,14) ;
	cout <<hra ;
	gotoxy(47,14) ;
	cout <<" : Rs. " <<allowance ;
	gotoxy(37,17) ;
	cout <<pf ;
	gotoxy(37,18) ;
	cout <<advance ;
	gotoxy(47,18) ;
	cout <<" : Rs. " <<deduction ;
	L.lineh(6,74,19,196) ;
	gotoxy(54,20) ;
	cout <<netsalary ;
	gotoxy(2,1) ;
	getch() ;
}

//*******************************************************************
// CLASS : employee
// FUNCTION : print
// DESCRIPTION : To read the characters on the screen & save it
//               to a temp variable and then send it to the printer.
//*******************************************************************

void employee :: print(int x1, int y1, int x2, int y2)
{
	statusbar(" PRINTING PRINTING PRINTING PRINTING PRINTING PRINTING PRINTING PRINTING PRINTI") ;
	const SEGMENT = 0xB800 ;
	unsigned norow = y2 - y1 + 1, nocol = x2 - x1 + 1 ;
	unsigned i = 0, noele = norow * nocol, *ptr ;
	ptr = new unsigned [noele] ;
	ofstream prn("PRN") ;
	cout<< noele;
	for (unsigned row=y1; row<=y2; row++)
	{
		for(unsigned col=x1; col<=x2; col++)
		{
			unsigned offset = 2*col + 160*row - 162 ;
			ptr[i++] = peek(SEGMENT,offset) ;
		}
	}
	int count = 0 ;
	for(i=0; i<noele; i++, count++)
	{
		unsigned char ch = ptr[i] % 256 ;
		prn <<ch ;
		if (count == 80)
		{
			prn <<"\n" ;
			count = 0 ;
		}
	}
	prn.close() ;
}

//*******************************************************************
// Main Menu
//*******************************************************************

void main(void)
{
	menu menu ;
	menu.main() ;
}

//*******************************************************************
// FUNCTION : statusbar
// DESCRIPTION : To make the status bar at prefixed coordinates at
//               the bottom of the screen.
//*******************************************************************

void statusbar(char m[])
{
	_setcursortype(_NOCURSOR) ;
	window(1,24,80,25) ;
	textcolor(BLACK) ;
	textbackground(WHITE) ;
	cprintf(m) ;
	clreol() ;
	window(1,1,80,24) ;
	textcolor(WHITE) ;
	textbackground(BLACK) ;
}

//*******************************************************************
// FUNCTION : getlinedelchar
// DESCRIPTION : To delete a character for getline
//*******************************************************************

void getlinedelchar(char *s, int col, int p, int &len)
{
	int i ;
	for (i=p; i<len; i++)
		s[i - 1] = s[i] ;
	gotoxy(col + p - 1,wherey()) ;
	len-- ;
	for (i=p - 1; i<len; i++)
		cout << s[i] ;
	cout <<'.' ;
}

//*****************************************************************
// FUNCTION : getline
// DESCRIPTION : To add online editing for inputing a line.
//*****************************************************************

void getline(char *s , int limit)
{
	int i, curx, done, col ;
	col = wherex() ;
	for (i = 0; i<limit; i++)
		cout <<'.' ;
	gotoxy(col,wherey()) ;
	done = 0 ;
	curx = 0 ;
	i = 0 ;
	do
	{
		char ch = getch() ;
		ch = toupper(ch) ;
		switch (ch)
		{
			case 0 : ch = getch();
				switch(ch)
				{
					case 75 : if (curx>0)
						{
							curx-- ;
							gotoxy(wherex()-1,wherey()) ;
						}
						break ;
					case 77 : if (curx<i)
						{
							curx++ ;
							gotoxy(wherex()+1,wherey()) ;
						}
						break ;
					case 83 : if (i>0)
						{
							if (curx<i)
							{
								getlinedelchar(s,col,curx + 1,i) ;
								gotoxy(col + curx,wherey()) ;
								if (i == 0)
									s[i] = 0 ;
							}
						}
				}
				break ;
			case 8  : if (curx>0)
				{
					getlinedelchar(s,col,curx,i) ;
					gotoxy(col + curx - 1,wherey()) ;
					curx-- ;
					if (i == 0)
						s[i] = 0 ;
				}
				break ;
			case 13 : done = 1 ;
				s[i] = 0 ;
				break ;
			case 27 : done = 1 ;
				s[0] = '0' ;
				break ;
			default : if (i < limit)
				{
					if (curx < i)
					{
						s[curx] = ch ;
						cout <<ch ;
						curx++ ;
					}
					else
					{
						s[i] = ch ;
						cout <<ch ;
						i++ ;
						curx = i ;
					}
				}
				else
					s[i] = 0 ;
		}
	} while (!done) ;
	cout <<"\n" ;
}