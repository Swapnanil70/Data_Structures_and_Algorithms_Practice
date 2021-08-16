#include<iostream>
using namespace std;
int first_occurrence(int arr[], int n, int i, int key){

    if(i == n)
        return -1;
    if(arr[i] == key)
        return i;

    return first_occurrence(arr, n, i+1, key);
}
int last_occurrence(int arr[], int n, int i, int key){

    if(i == n)
        return -1;
    
    int restArray = last_occurrence(arr, n, i+1, key);
    if(restArray != -1)
        return restArray;
         
    if(arr[i] == key)
        return i;

    return -1;
}
int main()
{
    int arr[] = {4,3,5,6,4,2,7,8};
    cout<<first_occurrence(arr, 8, 0, 5)<<endl;
    cout<<last_occurrence(arr, 8, 0, 4)<<endl;
   return 0;
}