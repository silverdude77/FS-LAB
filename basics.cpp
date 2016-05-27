#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
using namespace std;
void function();
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
	int i;
	fstream fp;
	fp.open("student.txt",ios::out|ios::in);
	while(!fp.eof())
	{
		
void student::pack()
{
	strcpy(buff,name);
	strcat(buff,"|");
	strcat(buff,usn);
	strcat(buff,"|");
	strcat(buff,sem);
	/*for(int i=strlen(buff);i<=35;i++)
	{
		strcat(buff,"*"); for VLR this shit not required !!!
	}*/
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
}
void student::unpack()
{
	strcpy(name,strtok(buff,"|"));
	strcpy(usn,strtok(NULL,"|"));
	strcpy(sem,strtok(NULL,"*"));
}
void student::display()
{
	int count=0;
	fstream fin;
	fin.open("student.txt",ios::in);
	while(!fin.eof())
	{
		
		cout<<" current get pointer tellg() is "<<fin.tellg()<<endl;
        	cout<<" current put pointer tellp() is "<<fin.tellp()<<endl;
		fin>>buff;
		if(fin.fail()) break;
		count++;
		unpack();
		cout<< " record no "<<count<<endl;
		cout<<" Name : "<<name<<endl;
		cout<<" USN : "<<usn<<endl;
		cout<<" Sem : "<<sem<<endl;
	}
}
void student::search()
{
	int flag=0;
	int count=0;
	fstream fin;
	fin.open("student.txt",ios::in);
	char key[10];
	cout<< " Enter key to be searched "<<endl;
	cin>>key;
	while(!fin.eof())
        {       
                
                cout<<" current get pointer tellg() is "<<fin.tellg()<<endl;
                cout<<" current put pointer tellp() is "<<fin.tellp()<<endl;
                fin>>buff;
                if(fin.fail()) break;
                count++;
                unpack();
		if(strcmp(usn,key)==0){
		flag = 1;
                cout<< " record found !!! congratulations !!!! record no "<<count<<endl;
                cout<<" Name : "<<name<<endl;
                cout<<" USN : "<<usn<<endl;
                cout<<" Sem : "<<sem<<endl;
		return ;
        	}
	}
	if(flag == 0){
	cout<<" Sorry, record not found !"<<endl;
	}
}
void student::modify()
{
	int flag=0;
	char buffer[10][36];
	ifstream fp;
	int i =0;
	fp.open("student.txt",ios::in);
	while(!fp.eof())
	{
		fp>>buffer[i];
		if(fp.fail()) break;
		i++;
	}
	fp.close();
	int count = i;
	cout<<" the records being read into 2d buffer are"<<endl;
	for(i=0;i<count;i++)
	{
		cout<<buffer[i]<<endl;
	}
	char key[10];
	cout<<" Enter the key to be modified "<<endl;
	cin>>key;
	i=0;
	fp.open("student.txt");
	while(!fp.eof())
	{
		fp>>buff;
		if(fp.fail()) break;
		i++;
		unpack();
		if(strcmp(key,usn)==0)
		{
			flag=1;
			cout<<" Congrats !!! Record Found "<<endl;
			cout<<" PLz enter the new details"<<endl;
			cout<<" Name : ";
			cin>>name;
			cout<<" USN : ";
                        cin>>usn;
			cout<<" Sem : ";
                        cin>>sem;
			pack();
			strcpy(buffer[i-1],buff);
		}
	}
	cout<<" the records after being modified in 2d buffer are"<<endl;
        for(i=0;i<count;i++)
        {       
                cout<<buffer[i]<<endl;
        }
	if(flag==1){
	ofstream fout;
	fout.open("student.txt",ios::out);
	for(i=0;i<count;i++)
	{
		fout<<buffer[i]<<endl;
	}
	}
	if(flag == 0){
        cout<<" Sorry, record not found !"<<endl;
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
		cout<<" 1--> enter data | 2--> display data | 3 --> search | 4 --> modify "<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1: s.read();
				break;
			case 2: s.display();
				break;
			case 3: s.search();
				break;
			case 4: s.modify();
				break;
			default:choice = -1;
				break;
		}
	} while(choice != -1);
				
return 0;
}
void function()
{
	fstream fp;
        fp.open("file.txt",ios::in); // when u reopen the file put pointer and get pointer is set to 0
	cout<<" re opening the file "<<endl;
	cout<<" tell g pointer points to  "<<fp.tellg()<<endl;
        cout<<" tell p pointer points to  "<<fp.tellp()<<endl;
}

