#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x=10;
    int &y=x;
    x=8;
    y=6;
    cout<<y;
    return 0;
}
