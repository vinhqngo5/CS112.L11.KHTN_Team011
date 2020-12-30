#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        long long a,b;
        cin>>a>>b;
        if (a%2==1){
            if ((b-a+1)%2==0) cout<<(((b-a+1-2)/2 %2)^a^b)<<endl;
            else cout<<(((b-a+1-1)/2 %2)^a)<<endl;
        }
        else{
            if ((b-a+1)%2==0) cout<<((b-a+1)/2 %2)<<endl;
            else cout<<(((b-a+1-1)/2 %2)^b)<<endl;
        }
    }
    return 0;
}
