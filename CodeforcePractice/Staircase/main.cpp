#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string num;
        cin>>num;
        int dem1=1,dem2=1;
        for (int i=0;i<n;i++){
            if (num[i]=='1') break;
            dem1++;
        }
        for (int i=n-1;i>=0;i--){
            if (num[i]=='1') break;
            dem2++;
        }
        cout<<max((n+1-min(dem1,dem2))*2,n)<<endl;
    }
    return 0;
}
