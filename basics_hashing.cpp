#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>

using namespace std;

int hashtable[15];
int position[15];

int hash(char key[10])
{
	int temp;
	temp = (key[0] + key[1] + key[2]) % 15;
	return temp;
}	
int hash2(char key[10])
{
	int temp;
        temp = 7 - ((key[0] + key[1] + key[2]) % 7);
        return temp;
}
int doublehash(char key[10])
{
	int temp;
        int val1 = hash(key);
	int val2 = hash2(key);
	temp = (val1 + val2) % 15; 
        return temp;
}
class student
{
	public: char name[20],usn[10],sem[5];
		char buff[35];
		void read();
		void pack();
		void unpack();
		void display();
		void search();
		void modify();
		student();
		
};
void student::modify()
{
}
student::student()
{
	for(int i=0;i<10;i++)
		hashtable[i] = 0; // initialize hastable to zero
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
        cout<<" enter the student details "<<endl;
        cout<<" Name :  ";
        cin>>name;
        cout<<" USN :  ";
        cin>>usn;
        cout<<" Sem :  ";
        cin>>sem;
        pack();
	int pos = hash(usn);
	cout<< " hash(usn) returned "<<pos<<endl;
	if(hashtable[pos] == 0)
	{
		cout<<" No collision "<<endl;
		position[pos] = fout.tellg();
		hashtable[pos] = 1;
	}
	else if(hashtable[pos] != 0)
	{
		cout<<" Collision occurred "<<endl;
		pos = doublehash(usn);
		cout<< " doublehash(usn) returned "<<pos<<endl;
		if(hashtable[pos] == 0)
		{
			cout<<" Double hash successful "<<endl;
			position[pos] = fout.tellg();
			hashtable[pos] = 1;
		}
		else if (hashtable[pos] != 0)
		{
			cout<<" Cannot insert record ! Sorry "<<endl;
			return;
		}
	}
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
	 unpack();
	 cout<<" Name :  "<<name<<endl;
	 cout<<" USN :  "<<usn<<endl;
	 cout<<" Sem :  "<<sem<<endl;
}
void student::search()
{
	char key[10];
	cout<<" Enter key to be searched "<<endl;
	cin>>key;
	ifstream fp;
	int pos;
	int flag = -1;
	fp.open("student.txt");
	for(int i=0;i<15;i++)
	{
		pos = position[i];
		fp.seekg(pos,ios::beg);
		fp>>buff;
		unpack();
		if(strcmp(key,usn)==0)
		{
			cout<<" Record found "<<endl;
			cout<<" Name : "<<name<<endl;
			cout<<" USN : "<<usn<<endl;
			cout<<" Sem : "<<sem<<endl;
			cout<<endl;
			flag = 1;
		}
	}
	if(flag==-1){
	cout<< " Record not found "<<endl;
	return;
	}
}
int main()
{
        int choice;
        student s;
        do{
                cout<<" 1--> enter data  | 3 --> search  "<<endl;
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
	cout<< " The contents of the hashtable are  "<<endl;
	for(int i=0;i<15;i++)
		cout<<" i : "<<i<<" val : "<<hashtable[i]<<endl;
	cout<<" The elements of the position table is "<<endl;
	for(int i=0;i<15;i++)
		cout<<" i : "<<i<<" val : "<<position[i]<<endl;
return 0;
}
						
