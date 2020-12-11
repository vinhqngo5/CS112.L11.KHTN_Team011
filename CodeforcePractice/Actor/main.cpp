#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int r,t,n,a,b,c,minn,maxx;
    cin>>r>>t;
    for (int i=0;i<t;i++){
        cin>>n>>a>>b>>c;
        minn=min(a,min(b,c))-(n-max(a,max(b,c)))-(n-(a+b+c-min(a,min(b,c))-max(a,max(b,c))));
        maxx=min(a,min(b,c));
        if (r==1)
            if (minn>0) cout<<minn<<endl;
            else cout<<0<<endl;
        else cout<<maxx<<endl;

    }
    return 0;
}
