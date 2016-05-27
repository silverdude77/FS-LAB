#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>

using namespace std;

char buffer[10][36];
int num_keys;

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
	fstream fp;
	fp.open("student.txt",ios::out|ios::in);
	while(!fp.eof())
	{
		fp>>buffer[i];
		if(fp.fail()) break; // working fine to detect if file is empty
		i++;
	}
	if(i==0){
		cout<<" Dude no records have been inserted so im just going to insert 0 (indicating no records deleted at pos 0 "<<endl;
		buffer[0][0] = '0'; // means record is empty;
	}
	num_keys = i;
	cout<<" At the end of constructor the value of num_keys is "<<num_keys<<endl;
}
void student::pack()
{
	strcpy(buff,name);
	strcat(buff,"|");
	strcat(buff,usn);
	strcat(buff,"|");
	strcat(buff,sem);
	for(int i=strlen(buff);i<36;i++)
	{
		strcat(buff,"*"); // we can do vlr also because manipulation is being done in the 2d buffer
	}
}
void student::read() 
{
	cout<<"Enter Name : ";
	cin>>name;
	cout<<"Enter USN : ";
        cin>>usn;
	cout<<"Enter Sem : ";
        cin>>sem;
	pack();
	cout<<" So the no records inserted untill now is "<<num_keys;
	if(buffer[0][0]=='0' && num_keys>=2) // Bugs in this part !!!
	{
		cout<<" inserting record at position "<<num_keys<<endl;
		strcpy(buffer[num_keys],buff);
		num_keys++;
		cout<<" next record going to be inserted in position "<<num_keys<<endl;
	}
	if(buffer[0][0]=='0' && num_keys==0) // Bugs in this part !!!
        {
		cout<<" Hopefully I only get executed once !!! Entering first record "<<endl;
                strcpy(buffer[1],buff);
		num_keys=2;
		cout<<" Im going to set the value of num_keys as "<<num_keys<<endl;
        }
	if(buffer[0][0]!='0') // this is perfect
	{
		cout<<" Hey we have some deleted records , why dont you use them"<<endl;
		int avail = atoi(buffer[0]);
		cout<<" We have an empty record at position "<<avail<<endl;
		int temp = atoi(buffer[avail]); // gets the position of empty record in int format
		buffer[0][0] = temp + '0';
		strcpy(buffer[avail],buff);			
	}
	cout<<" So after entering a record the buffer is "<<endl;
	for(int i=0;i<num_keys;i++)
	{
		cout<<buffer[i]<<endl;
	}
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
	cout<<" USN : "<<usn<<endl;
	cout<<" Sem : "<<sem<<endl; 
}
void student::del() // Works perfectly !!!
{
	char temp;
	char key[10];
	cout<<" Enter the key to be deleted ! ";
	cin>>key;
	for(int i=1;i<num_keys;i++)
	{
		strcpy(buff,buffer[i]);
		unpack();
		if(strcmp(usn,key)==0)
		{
			cout<<" congo !!! record found !!!"<<endl;
			temp = i + '0' ;
			buffer[i][0] = buffer[0][0];
			buffer[0][0] = temp;	
		}
	}
	cout<<" So after deleting a record the buffer is "<<endl;
        for(int i=0;i<num_keys;i++)
        {
                cout<<buffer[i]<<endl;
        }	
}
void student::search()
{
}
student::~student()
{
	cout<<" Hey im the destructor !!! Im going to write to the file now !"<<endl;
	ofstream fout;
	fout.open("student.txt",ios::app);
	for(int i=0;i<num_keys;i++){
	fout<<buffer[i]<<endl;
	}
}
int main()
{
	cout<<" dude main is being executed "<<endl;
	int choice;
        student s;
	cout<<" creation of object is executed "<<endl;
        do{
                cout<<" 1--> enter data | 2--> display data | 3 --> search | 4 --> delete  "<<endl;
                cin>>choice;
                switch(choice)
                {
                        case 1: s.read();
                                break;
                        case 2: s.display();
                                break;
                        case 4: s.del();
                                break;
                        default:choice = -1;
                                break;
                }
        } while(choice != -1);

return 0; 
}  
