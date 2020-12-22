#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int A[n];
    cin>>A[0];
    int minn=A[0], maxx=A[0];
    for (int i=1;i<n;i++){
        cin>>A[i];
        if (A[i]<minn) minn=A[i];
        if (A[i]>maxx) maxx=A[i];
    }
    if (minn>=0) cout<<maxx*2;
    else if (maxx<=0) cout<<-minn*2;
    else cout<<maxx*2-minn*2;
    return 0;
}
