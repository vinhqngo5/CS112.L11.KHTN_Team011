#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int A[n],B[n],C[n]={0},res=0;
    for (int i=n-1;i>=0;i--) cin>>A[i];
    for (int i=n-1;i>=0;i--) cin>>B[i];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (A[i]==B[j])
            else C[j]--;
        }
    }
    return 0;
}
