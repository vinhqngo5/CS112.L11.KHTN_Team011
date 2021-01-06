#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int Fibonacci(int n)
{
	if (n<3) return 1;
	return Fibonacci(n-1)+Fibonacci(n-2);	
}
int main(int argc, char** argv) {
	int n;
	cout<<"Nhap so chu so cua day fibonacci can xuat: ";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cout<<Fibonacci(i)<<", ";
	}
	
	return 0;
}
