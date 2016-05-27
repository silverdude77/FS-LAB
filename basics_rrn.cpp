/* MORAL OF THE PROGRAM 

  1) ONLY DIFFERENCE BETWEEN VLR AND FLR IS THAT ONE LINE IN PACK()
  2) GENERAL RECORD HAS NEWLINE INCLUDED AS LAST CHARACTER
	FOR EXAMPLE OUTPUT OF THIS CODE
	 Enter key to be searched 
6
 current get pointer tellg() is 0 record structure was a|1|6 and 31 *
 current put pointer tellp() is 0
 current get pointer tellg() is 36
 current put pointer tellp() is 36
 current get pointer tellg() is 73
 current put pointer tellp() is 73
 current get pointer tellg() is 110
 current put pointer tellp() is 110
 current get pointer tellg() is 119
 current put pointer tellp() is 119
 current get pointer tellg() is 127
*/


#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
using namespace std;
void function();
int rrn;
class student
{
	public:	char name[20],usn[10],sem[5];
		char buff[36];
		void read();
		void pack();
		void display();
		void unpack();
		void search();
		void modify();
		student();
		~student();
			
};
student::student()
{
	int i=0;
	fstream fp;
	fp.open("rrn.txt",ios::in|ios::out);
	while(!fp.eof())
	{
		fp>>rrn;
		if(fp.fail()) break;
		i++;
	}
	if(i==0)
	{
		cout<<" Hey is this the first record you are inserting "<<endl;
		rrn=0;
		fp<<rrn;
	}
	cout<<" Hey, this is the constructor !!! current value of rrn is "<<rrn<<endl;
}
student::~student()
{
	cout<<" Hey, this is destructor ! the value of rrn being written is "<<rrn<<endl;
	ofstream fout;
	fout.open("rrn.txt",ios::out);
	fout<<rrn;
}
void student::pack()
{
	strcpy(buff,name);
	strcat(buff,"|");
	strcat(buff,usn);
	strcat(buff,"|");
	strcat(buff,sem);
	for(int i=strlen(buff);i<=35;i++)
	{
		strcat(buff,"*"); 
	}
}
void student::read()
{
	fstream fout;
        fout.open("student.txt",ios::app|ios::out);
        cout<<" current get pointer tellg() is "<<fout.tellg()<<endl;
        cout<<" current put pointer tellp() is "<<fout.tellp()<<endl;

	cout<<" enter the student details "<<endl;
	cout<<" Name :  ";
	cin>>name;
	cout<<" USN :  ";
	cin>>usn;
	cout<<" Sem :  ";
	cin>>sem;
	pack();
	fout<<buff<<endl;
	rrn++;
}
void student::unpack()
{
	strcpy(name,strtok(buff,"|"));
	strcpy(usn,strtok(NULL,"|"));
	strcpy(sem,strtok(NULL,"*"));
}
void student::display()
{
		cout<<" Name : "<<name<<endl;
		cout<<" USN : "<<usn<<endl;                 // Hey dude this only prints one record so plz fix me by function overloading ok cool!!!
		cout<<" Sem : "<<sem<<endl;
}
void student::search()
{
	int key;
	cout<<" Hey enter the rrn to be searched !"<<endl;
	cin>>key;
	if(key < 0 || key >= rrn)
	{
		cout<<" Hey that is an invalid rrn you entered !!! plz try again later with valid rrn !!!"<<endl;
		return;
	}
	int pos = (key*36)+key;
	ifstream fp;
	fp.open("student.txt");
	fp.seekg(pos,ios::beg);
	fp>>buff;
	unpack();
	display();
}	
int main()
{
	string buff;
	cout<<" printing file contents line by line"<<endl;
/*	fstream fp;
	fp.open("file.txt",ios::in);
	while(!fp.eof())
	{
		cout<<" tell g pointer points to  "<<fp.tellg()<<endl;
		cout<<" tell p pointer points to  "<<fp.tellp()<<endl;
		getline(fp,buff); // Reads new_line character as part of buff
		if(fp.fail()) break;
		cout<<" buff contains  "<<buff<<endl;
	}
	function(); */
	int choice;
	student s;
	do{
		cout<<" 1--> enter data | 2--> display data | 3 --> search  "<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1: s.read();
				break;
			case 2: s.display();
				break;
			case 3: s.search();
				break;
			default:choice = -1;
				break;
		}
	} while(choice != -1);
				
return 0;
}

