#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
    int a,b,c,d=0;
    cin>>a>>b>>c;
    if (b>c/2) d=(b-c/2)/2;
    cout<<3*min(c/2,b)+3*min(d,a)<<endl;
    }
    return 0;

}
