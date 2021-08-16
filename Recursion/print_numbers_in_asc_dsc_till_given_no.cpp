#include<iostream>
using namespace std;

void printDsc(int n){
    if(n == 0)
        return ;

    cout<<n<<endl;
    printDsc(n-1);
}
void printAsc(int n){
    
    if(n == 0)
        return;

    printAsc(n-1);
    cout<<n<<endl;
    
}
int main()
{
    int n;
    cin>>n;
    // printDsc(n);
    printAsc(n);
    return 0;
}