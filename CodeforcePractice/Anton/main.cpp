#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<min(a,min(c,d))*256+(a-min(a,min(c,d))>0)*32*min(b,a-min(a,min(c,d)));
    return 0;
}
