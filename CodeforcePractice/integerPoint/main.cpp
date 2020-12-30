#include <iostream>

using namespace std;

int main()
{
    int k;
    cin>>k;
    while (k-- >0){
        long long n,m;
        long long demchann=0, demchanm=0, x;
        cin>>n;
        for (int i=0;i<n;i++){
            cin>>x;
            if (x%2==0) demchann++;
        }
        cin>>m;
        for (int i=0;i<m;i++){
            cin>>x;
            if (x%2==0) demchanm++;
        }
        cout<<demchanm*demchann+(n-demchann)*(m-demchanm)<<endl;
    }
    return 0;
}
