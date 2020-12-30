#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,tam=1;
    cin>>n>>k;
    int A[n];
    for (int i=0;i<n;i++)
        cin>>A[i];
    sort (A,A+n);
    k-=A[0]-1;
    if (k<=0) { cout<<A[0]+k-1; return 0;}
    for (int i=1;i<n;i++){
        k-=(A[i]-A[i-1]-1);
        if (k<=0) {tam=i; break;}
    }
    if (k>0) cout<<A[n-1]+k;
    else cout<<A[tam]+k-1;
    return 0;
}
