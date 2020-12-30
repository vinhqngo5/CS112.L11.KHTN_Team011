#include <iostream>

using namespace std;

int main()
{
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        string s1, s2;
        cin>>s1>>s2;
        int a=s1.size(), b=s2.size(), key=0;
        if (a!=b) cout<<"NO"<<endl;
        else {
            for (int j=0;j<a;j++){
                for (int h=0; h<a;h++){
                    if (s2[h]==s1[j]) {cout<<"YES"<<endl; key=1; break;}
                }
               if (key==1) break;
            }
            if (key==0) cout<<"NO"<<endl;
        }
    }
    return 0;
}
