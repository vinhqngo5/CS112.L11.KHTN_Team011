#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int XORinacci(int a,int b ,int n)
{
	int c;
	if (n==0) return a;
	else if (n==1) return b;
	else
	{
		for (int i=2;i<n;i++)
		{
			c=a^b;
			a=b;
			b=c;
		}
		return c;
	}
}
int main(int argc, char** argv) {
	int x;
	cin>>x;
	int n[x], a[x], b[x];
	for (int i=0;i<x;i++)
	{
		cin>>a[i]>>b[i]>>n[i];
	}
	for (int i=0;i<x;i++)
	{
		cout<<XORinacci(a[i],b[i],n[i])<<endl;
	}
	return 0;
}
