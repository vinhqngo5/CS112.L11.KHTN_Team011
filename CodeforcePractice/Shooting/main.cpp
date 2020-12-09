#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int A[n],tam,key=1,dem=0,B[n];
	for (int i=0;i<n;i++)
	{
		cin>>A[i];
		B[i]=A[i];
	}
	for (int i=0;i<n;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			if (A[j]>A[i]) 
			{
				tam=A[i];
				A[i]=A[j];
				A[j]=tam;	
			}
		}
	}	
	cout<<endl;
	for (int i=0;i<n;i++)
		dem=dem+i*A[i]+1;
	cout<<dem<<endl;
	
	for (int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if (A[i]==B[j])
			{
				cout<<j+1<<"\t";
				B[j]=0;
				break;
			}
		}
	}	
	cout<<endl;
	
	return 0;
}
