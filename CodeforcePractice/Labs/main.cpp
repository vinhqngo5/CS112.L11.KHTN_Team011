#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int A[n][n],num=1;
    for (int i=0;i<n;i++){
        if (i%2==0) {
            for (int j=0;j<n;j++)
                A[j][i]=num++;
        }
        else {
            for (int j=n-1;j>=0;j--)
                A[j][i]=num++;
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++)
            cout<<A[i][j]<<"\t";
        cout<<endl;
    }
    return 0;
}
