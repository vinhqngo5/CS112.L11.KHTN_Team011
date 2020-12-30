#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int A[n],dem=0,min=10000;
	for(int i=0;i<n;i++)
		cin>>A[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if ((A[j]-A[i])%2!=0) dem=dem+1;
		}
		if (dem<min) min=dem;
		dem=0;
	}
	cout<<min;
	return 0;
}
