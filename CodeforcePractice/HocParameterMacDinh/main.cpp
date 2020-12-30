#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void HamGiDo(int x, int y=1)
{
	cout<<x+y<<endl;
}
int main(int argc, char** argv) {
	HamGiDo(9,5);
	HamGiDo(9);
	
	return 0;
}
