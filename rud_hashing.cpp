#include<iostream>
#include<stdlib.h>

using namespace std;

int hash(char key[10])
{
        int temp;
        temp = (key[0] + key[1] + key[2]) % 10;
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
        temp = val1 + val2;
        return temp;
}

int main()
{
	int n = 0;
	char ele[10];
	int hashtable[10];
	for(int i=0;i<10;i++)
		hashtable[i]=0;
	while(n <10)
	{
		
		cout<< " Enter the elements to insert in hash table"<<endl;
		cin>>ele;
		int pos = hash(ele);
		cout<< " Hash 1 value was  "<<pos<<endl;
		if(hashtable[pos] == 0)
		{
			cout<< " Congo !!! The hash function succeded no need for double hash "<<endl;
			hashtable[pos] = 1;
			n++;
		}
		else if(hashtable[pos] !=0)
		{
			cout<< " Collission has occured !!! because hashtable[pos] is " <<hashtable[pos]<<endl; 
			cout<<" Using double hash now "<<endl;
			pos = doublehash(ele);
			cout<< " Position returned by doublehash is "<<pos;
			if(hashtable[pos] == 0)
			{
				cout<< " Congo !!! After collision , double hash has succeded "<<endl;
				hashtable[pos] = 1;
				n++;
			}
			else if(hashtable[pos] !=0)
			{
				cout<< " Double hash failed because hashtable[pos] had "<<hashtable[pos]<<endl;
				cout<< " Sorry cannot insert the number "<<endl;
			}
		}
	}
	cout<< " The hashtable contents are "<<endl;
	for(int j=0;j<10;j++)
	{
		cout<< " Index : "<<j<< " Element : "<<hashtable[j]<<endl;
	}
return 0;
} 
