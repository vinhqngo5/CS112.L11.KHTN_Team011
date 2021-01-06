#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int n,dodai=0,dem=0;
    cin>>n;
    char A[n+1];
    for (int i=0;i<n;i++)
        cin>>A[i];
        
    for (int i=0;i<n;i++)
    {
        if (((A[i]=='a' || A[i]=='h') && A[i]!=A[i-1]&& i!=0)||((i==0)&&(A[i]=='a'||A[i]=='h')))
        {
            dem=dem+1;
            if (dem>dodai) dodai=dem;
        }
        else dem=0;

    }
    cout<<dodai;
    return 0;
}
