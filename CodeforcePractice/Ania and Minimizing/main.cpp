#include <iostream>
#include <conio.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,k;
	cin>>n;
	cin>>k;
	char S[n];
	for (int i=0;i<n;i++)
	{
		cin>>S[i];
	}
	if (n==1) cout<<0;
	else
	{
		if ( S[0]!='1') S[0]='1';
		for (int i=1;i<k;i++)
		{
			if (S[i]=='0') 
			{
				k=k+1;
			}
			else S[i]='0';
		}
		for (int i=0;i<n;i++)
		cout<<S[i];
	}
	
	
	return 0;
}
