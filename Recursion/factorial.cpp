#include <iostream>

using namespace std;
int fact(int n){
    if (n == 0)
    {
        /* code */
        return 1;
    }
    else
    {
        /* code */
        if(n == 0)
            return 1;

        int prevElement = fact(n-1);
        return n * prevElement;
    }
}
int main(){
    int n;
    cin>>n;
    cout<<fact(n);
    return 0;
}