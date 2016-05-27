#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
using namespace std;
char pkeys[100][10],skeys[100][10];
int addr[100],num_keys=0;
class student
{
	public:	char name[20],usn[10],sem[5];
		char buff[36];
		void read();
		void pack();
		void display();
		void unpack();
		void search();
		void del();
		student();
		~student();
			
};
student::student()
{
	int i=0;
	ifstream fp;
	fp.open("sec_index.txt");
	while(!fp.fail())
	{
		fp>>pkeys[i]>>skeys[i]>>addr[i];
		if(fp.fail()) break;
		i++;
	}
	if(i==0)
	{
		cout<<" Hey, this is the constructor ! Is this the first time you are entering a record !"<<endl;
		return;
	}
	num_keys = i;
}
student::~student()
{
	cout<<" Hey, this is destructor ! Im going to write to secondary index "<<endl;
	ofstream fout;
	fout.open("sec_index.txt",ios::app);
	if(num_keys==0)
	{
		cout<<" NO keys to be written !!!"<<endl;
		return;
	}
	for(int i=0;i<num_keys;i++)
	{
		if(skeys[i][0]!='*'){
		fout<<pkeys[i]<<"\t"<<skeys[i]<<"\t"<<addr[i]<<endl;
		}
	}
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
	ofstream fp;
	fp.open("sec_index.txt",ios::app);
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
	strcpy(pkeys[num_keys],usn);
	strcpy(skeys[num_keys],name);
        addr[num_keys] = fout.tellg();
	pack();
	fout<<buff<<endl;
	num_keys++;
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
		cout<<" USN : "<<usn<<endl;			// Dude this only prints individual records. So display function in menu only prints 1 record. plz fix me !!!
		cout<<" Sem : "<<sem<<endl;
}
void student::search()
{
	char key[20];
	cout<<" Enter the key to be searched ";
	cin>>key;
	ifstream fp;
	fp.open("student.txt");
	for(int i=0;i<num_keys;i++)
	{
		if(strcmp(skeys[i],key)==0)
		{
			cout<<" Congo ! record found !!!"<<endl;
			fp.seekg(addr[i],ios::beg);
			fp>>buff;
			unpack();
			display();
		}
	}
}
void student::del()
{
        char key[10];
        cout<<" Enter the key to be searched ";
        cin>>key;
        for(int i=0;i<num_keys;i++)
        {
                if(strcmp(skeys[i],key)==0)
                {
                        cout<<" Congo ! record found !!!"<<endl;
                        skeys[i][0] = '*';
                        return;
                }
        }
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

