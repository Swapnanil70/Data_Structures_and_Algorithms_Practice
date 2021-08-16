#include <iostream>

using namespace std;
bool sort(int arr[], int n){
    if (n==1)
    {
        /* code */
        return true;
    }
    bool prevArray = sort(arr+1, n-1);
    return (arr[0] < arr[1] && prevArray);
    
}
int main(){
    int arr[]= {1,6,3,4,5};
    cout<<sort(arr, 5)<<endl;
    return 0;
}