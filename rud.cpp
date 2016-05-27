#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>

using namespace std;

int main()
{
	fstream fp;
	fp.open("file.txt",ios::in);
	int i=0,ret;
	char buff[10];
	while(!fp.fail())
	{
		fp>>buff;
		if(strlen(buff)==0)
		{
			cout<<" dude that last line with empty stuff was read "<<endl; // The program will never read any sort of empty line which u imagine exists
		}
		cout<<" Hey im in while loop  "<<endl;
		// i++;  So if you put this here value is 8. It means that it is reading that last line which was empty
		if(fp.fail()){
			cout<<" hey man fp.fail() has returned 1 "<<endl;
			break;
		}
		i++; // If you put this here the last line which is waste is not counted. This the correct position of the line to count no of records
		cout<<" dude buff has data "<<buff<<endl;
	}
	cout<<" the no of records in the file were "<<i<<endl;
return 0;
}
