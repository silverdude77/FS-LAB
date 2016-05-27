#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

using namespace std;

int main()
{
	char buffer[10][10];
	buffer[0][0] = '0';
	int val = atoi(buffer[0]);
	cout<<" The value present in the buffer in integer format is "<<val<<endl;
	int i = 7;
	char temp = i + '0';	
	cout<<" Temp is "<<temp<<endl;
	ifstream fp;
	fp.open("student.txt");
	char buffer[10][36];
	i=0;
	while(!fp.eof())
	{
		fp<<buffer[i];

	return 0;
}
