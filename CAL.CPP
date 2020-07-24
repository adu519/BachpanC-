#include<iostream.h>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>

int calci()
{ int mainm=0;
do
{ int d,m,choice;
  d=DETECT;
  initgraph(&d,&m,"..\\bgi");

		  setcolor(15);
		  settextstyle(3,0,3);
		  rectangle(35,85,500,208);
		  line(250,85,250,208);
		  line(55,85,55,208);
		  line(270,85,270,208);
		  line(35,118,500,118);
		  line(35,148,500,148);
		  line(35,178,500,178);
		  setcolor(RED);
		  outtextxy(40,90,"1");
		  outtextxy(40,120,"2");
		  outtextxy(40,150,"3");
		  outtextxy(40,180,"4");
		  outtextxy(255,90,"5");
		  outtextxy(255,120,"6");
		  outtextxy(255,150,"7");
		  outtextxy(255,180,"8");
		  setcolor(WHITE);
		  outtextxy(40,90,"    Add");
		  outtextxy(40,120,"    Subtract");
		  outtextxy(40,150,"    Multiply");
		  outtextxy(40,180,"    Divide");
		  outtextxy(255,90,"    Square");
		  outtextxy(255,120,"    Cube");
		  outtextxy(255,150,"    Factorial");
		  outtextxy(255,180,"    Back");
		  outtextxy(90,300,"Press your choice No. & hit Enter");


		   choice=getch();

		    if(choice==49)
		    {
		     setcolor(RED);
		     outtextxy(40,90,"    Add");
		    }

		    else
		    if(choice==50)
		    {
		     setcolor(RED);
		     outtextxy(40,120,"    Subtract");
		    }

		    else
		    if(choice==51)
		    {
		     setcolor(RED);
		     outtextxy(40,150,"    Multiply");
		    }

		    else
		    if(choice==52)
		    {
		     setcolor(RED);
		     outtextxy(40,180,"    Divide");
		    }

		     else
		    if(choice==53)
		    {
		     setcolor(RED);
		     outtextxy(255,90,"    Square");
		    }

		     else
		    if(choice==54)
		    {
		     setcolor(RED);
		     outtextxy(255,120,"    Cube");
		    }

		     else
		    if(choice==55)
		    {
		     setcolor(RED);
		     outtextxy(255,150,"    Factorial");
		    }

		     else
		    if(choice==56)
		    {
		     setcolor(RED);
		     outtextxy(255,180,"    Back");
		    }



		     outtextxy(150,330,"Press Any Key To Continue");
		     getch();

		     cleardevice();

		     setcolor(2);
		     rectangle(10,10,600,400);
		     setcolor(11);
		     rectangle(15,15,595,395);
		     float a,b,c;
		      gotoxy(10,2);

		      switch(choice)
		       {
			case 49:
			{

			 cout<<"\n\n\n\tEnter first no to add:";
			 cin>>a;
			 cout<<"\n\tEnter second no to add:";
			 cin>>b;
			 c=a+b;
			 cout<<"\n\n\t"<<a<<"+"<<b<<"="<<c;
			getch();
			}
			 break;

			case 50:
			{
			 cout<<"\n\n\n\tEnter the first no to subtract from:";
			 cin>>a;
			 cout<<"\n\tEnter the second no to subtract:";
			 cin>>b;
			 c=a-b;
			 cout<<"\n\n\t"<<a<<"-"<<b<<"="<<c;
			getch();
			}
			 break;

			case 51:
			{
			 cout<<"\n\n\n\tEnter the first no to mutiply:";
			 cin>>a;
			 cout<<"\n\tEnter the second no to multiply:";
			 cin>>b;
			 c=a*b;
			 cout<<"\n\n\t"<<a<<"x"<<b<<"="<<c;
			getch();
			}
			 break;

			case 52:
			{
			 cout<<"\n\n\n\tEnter the number to divide:";
			 cin>>a;
			 cout<<"\n\tEnter the number to divide from:";
			 cin>>b;
			 c=a/b;
			 cout<<"\n\n\t"<<a<<"/"<<b<<"="<<c;
			getch();
			}
			 break;


			case 53:
			{
			 cout<<"\n\n\n\tEnter the number:";
			 cin>>a;
			 cout<<"\n\tSquare is:"<<a*a;
			getch();

			}
			 break;


		       case 54:
			{
			 cout<<"\n\n\n\tEnter the number:";
			 cin>>a;
			 cout<<"\n\tCube is:"<<a*a*a;

			getch();

			}
			 break;



			case 55:
			{
			 double f;
			 cout<<"\n\n\n\tEnter the number:";
			 cin>>a;


			 f=1;

			 for(double i=a;i>=1;i--)
			 {

			  f=f*a;
			  a=a-1;
			 }
			  cout<<"\n\tFactorial is:"<<f;
			 getch();
			 }
			 break;

			 case 56:
			 mainm=1;
			 break;

			default:
		      outtextxy(90,120,"Invalid option");
		      }
		      }while(mainm==0);
		      return mainm;
}
