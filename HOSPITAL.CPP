#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<fstream.h>
#include<process.h>
#include<stdio.h>
struct hosp
{	int pno;
	char wname[20];
}ob;
void add();
void disp();
void search();
void del();
void mod();
void  main()
{
	clrscr();
	int i;
	char c='y';
	do
	{
	clrscr();
	cout<<"\t\tWELCOME TO NATIONAL HOSPITAL \n\nEnter your option :\n\t\t1.Add Patient\n\t\t2.Display Patient3.\n\t\t3.Search Patient\n\t\t4.Delete Patient\n\t\t5.Modify Patient";
	cin>>i;
	switch(i)
	{
	case 1:add();
		break;
	case 2:disp();
		break;
	case 3:search();
		break;
	case 4:del();
		break;
	case 5:mod();
		break;
	default :exit(0);
	}
	cout<<"\n\nBack to Main Menu:";
	cin>>c;
	}while(c=='y'|| c=='Y');
	getch();
}

void add()

{	ofstream fout;
	fout.open("hosp.dat",ios::app | ios::beg |ios::binary);
	char ch='y';
	do
	{       cout<<"\nEnter Patient no.:";
		cin>>ob.pno;
		cout<<"\nEnter Ward name:";
		gets(ob.wname);
		fout.write((char *)& ob,sizeof(ob));
		cout<<"\nWant to enter more:";
		cin>>ch;
	}while(ch=='y');
	fout.close();
}
void disp()
{
	ifstream fin;
	fin.open("hosp.dat");
	fin.seekg(0);
	while(fin)
	{
		fin.read((char*)& ob,sizeof(ob));
		cout<<"\n\n\tPatient no.\tWard name";
		cout<<"\n\t"<<ob.pno<<"\t\t\t"<<ob.wname;
	}
	fin.close();
}
void search()
{
	ifstream fin;
	int k=0,ctr=0;
	fin.open("hosp.dat");
	fin.seekg(0);
	cout<<"\nEnter Patien no. to be searched:";
	cin>>k;
	while(fin.read((char*)& ob,sizeof(ob)))
	{
		fin.read((char*)& ob,sizeof(ob));
		if(ob.pno==k)
		{
			cout<<"\n\n\tPatient no.\tWard name";
			cout<<"\n\t"<<ob.pno<<"\t\t\t"<<ob.wname;
		}
		else
		ctr=1;
	}
	if(ctr==1) cout<<"\nPatient Not Found";
	fin.close();
}
void mod()
{
	fstream fin;
	int hold=0,k;
	fin.open("hosp.dat",ios::in|ios::out|ios::binary);
	fin.seekg(0);
	cout<<"\nEnter Patient no. to be modified:";
	cin>>k;
	while(fin)
	{       hold=fin.tellg();
		fin.read((char*)& ob,sizeof(ob));
		if(ob.pno==k)
		{       cout<<"\nEnter new no:";
			cin>>ob.pno;
			cout<<"\nEnter new Ward name:";
			gets(ob.wname);
			fin.seekg(hold);
			fin.write((char*)&ob,sizeof(ob));
		 }
	}
	cout<<"\nUpdation done!!!!";
	fin.close();
}
void del()
{
	ifstream fin;
	ofstream fout;
	int k=0;
	fin.open("hosp.dat");
	fin.seekg(0);
	cout<<"\nEnter Patient no. to be deleted:";
	cin>>k;
	while(fin.read((char*)& ob,sizeof(ob)))
	{
		fin.read((char*)& ob,sizeof(ob));
		fout.open("temp.dat",ios::app |ios::binary);
		if(ob.pno!=k)
		{
			fout.write((char*)& ob,sizeof(ob));
		}
	}
	remove("hosp.dat");
	rename("temp.dat","hosp.dat");
	fout.close();
	fin.close();
	cout<"\nRecord Deleted";
}
