#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin>>n;
    long long sum=0,A[n],res=0;
    for (long long i=0;i<n;i++){
        cin>>A[i];
        sum+=A[i];
    }
    for (int i=0;i<n;i++)
        res+=A[i]*(sum-A[i]);
    cout<<res/2;

    return 0;
}*/
