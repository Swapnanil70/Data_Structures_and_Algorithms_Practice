#include <iostream>

using namespace std;
void des(int n){
    if (n==0)
    {
        /* code */
        return;
    }
    cout<<n<<endl;
    des(n-1);
}
// void as(int n){
//     int temp = 0
//     if (n==temp)
//     {
//         /* code */
//         return;
//     }
//     cout<<temp<<endl;
//     as(n+1);
// }
int main(){
    int n;
    cin>>n;
    des(n);
    // as(n);
    return 0;
}