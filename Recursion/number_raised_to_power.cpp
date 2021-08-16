#include<stdio.h>
#include<iostream>
using namespace std;
int power(int n, int p){
    if (p == 0)
    {
        /* code */
        return 1;
    }
    
    int prevPower = power(n, p-1);
    return n*prevPower;
}

int main(int argc, char const *argv[])
{
    /* code */
    int n;
    int p;
    cin>>n>>p;
    cout<<power(n, p);
    
    return 0;
}
