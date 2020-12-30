#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int A[n],tam,dem=n;
	for (int i=0;i<n;i++)
		cin>>A[i];
	for (int i=0;i<n-1;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			if (A[j]>A[i])
			{
				tam=A[j];
				A[j]=A[i];
				A[i]=tam;
			}
		}
	}
	for (int i=0;i<n-1;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			if ((A[i]%A[j])==0)
			{
				dem=dem-1;
				break;
			}
		}
	}
	cout<<dem;
	return 0;
}
