#include <fstream.h>
#include <conio.h>
#include <string.h>


void multspce(char name[13]);

void main()
{
	clrscr();
	char name[13],ch='a';
	cout<<"Enter file name (8 character.3 in extension): ";
	cin>>name;
	cout<<"Enter the data that you want to save in a file \n(Press enter when you have entered data) : ";
	ofstream out;
	ifstream in;
	out.open(name);
	while(1)
	{
		ch=getche();
		out.put(ch);
		if (ch=='\r')
			break;

	}
	out.close();
	in.open(name);
	in.seekg(0);
	cout<<endl<<endl<<"The data stored is : "<<endl;

	while(in)
	{
		in.get(ch);
		cout<<ch;
	}
	cout<<char(8)<<" "<<char(8);
	in.close();
	getch();

	multspce(name);
}



void multspce(char name[13])
{
	int	flag=0;
	fstream io,inout;
	io.open(name,ios::in||ios::out||ios::app);
	inout.open(name,ios::in||ios::out||ios::app);
	ifstream in;
	in.open(name);
	char ch,ch1;

	io.seekg(0);
	inout.seekg(0);

	while(inout)
	{
		if(!flag)
			inout.get(ch);
//		io.get(ch1);
		ch1=ch;
		io.put(ch1);
		if (flag)
		{
			flag=0;
		}
/*		if (ch!=' ')
		{
			str1[j]=str[i];
		}
*/

		if (ch==' ')
		{
			io.put(' ');
			while(ch==' ' && inout)
			{
				flag=1;
				inout.get(ch);
			}
//			str1[j]=' ';
		}
	}
//	str1[j]='\0';
//	cout<<str1;
	in.seekg(0);
	cout<<endl<<endl<<"The modified data is : "<<endl;

	while(in)
	{
		in.get(ch);
		cout<<ch;
	}
	getch();

}
