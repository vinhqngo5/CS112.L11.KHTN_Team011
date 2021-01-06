#include <iostream>
#include <bits/stdc++.h>
#include<iomanip>
using namespace std;
int main()
{
    int S;
    cin>>S;
    int a,b;
    for (int i=1;i<sqrt(S);i++){
        if (S%i==0) {a=i; b=S/i;}
    }
    double V=0, maxx=0, eps=1e-6,h=0;
    for (double i=eps;i<(double)min(a,b)/2;i+=eps){
        V=a*b*i+4*i*i*i-2*i*i*(a+b);
        if (maxx<V) {maxx=V; h=i;}
    }
    cout<<setprecision(3)<<b<<endl<<a<<endl<<h<<endl;
    cout<<setprecision(3)<<maxx;
    return 0;
}
