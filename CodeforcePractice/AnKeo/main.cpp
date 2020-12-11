#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	/*srand(time(NULL));
	int n,j;
	cin>>n;
	int A[n+1];
	for (int i=0;i<n;i++)
	{
		cin>>A[i];
		//A[i]=rand()%7+1;
		//cout<<A[i]<<"\t";
	}
	int dem=1, max=2, keo1=A[0], keo2;
	for (int i=1;i<n;i++)
	{
		if (A[i]==keo1 || A[i]==keo2 || keo2==0)
		{
			dem=dem+1;
			if (dem>=max) max=dem;
			if (A[i]!=keo1 && keo2==0) keo2=A[i];
		}
		else 
		{
			keo1=A[i-1];
			if (A[i]!=A[i-1]) keo2=A[i];
			else keo2=0;
			if (dem>=max) max=dem;
			dem=2;
			j=i-1;
			for (;j>0;j--)
			{
				
				if (A[j-1]==keo1) 
				{
					dem=dem+1;
				}
				else break;
			}
		}
	}
	if (n<=1) max=1;
	cout<<endl;
	cout<<max;
	return 0;*/
}
