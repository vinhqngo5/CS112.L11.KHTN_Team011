#include <iostream>
using namespace std;
int main()
{
    int a,b,ucln=1;
    cin>>a>>b;
    if(b<a) swap(a,b);
    for (int i=1;i<=a;i++)
    {
        if((a%i)==0 && (b%i)==0)
            ucln=i;
    }
    cout<<ucln;
    return 0;
}
