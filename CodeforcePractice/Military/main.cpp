#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long long n,a,b;
    cin>>n>>a>>b;
    cout<<(abs((n-1)*b+a-(n-1)*a-b)+1)*(b>a?1:0);
    return 0;
}
