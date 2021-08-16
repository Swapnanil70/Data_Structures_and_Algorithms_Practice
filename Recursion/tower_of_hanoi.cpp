#include<iostream>
using namespace std;
void towerOfHanoi(int n, char src, char help, char dest){ 
    if(n == 0)
        return;

    towerOfHanoi(n-1, src, dest, help);
    cout<<"Move from "<<src<<" to "<<dest<<endl;
    towerOfHanoi(n-1, help, src, dest);
}
int main()
{
    towerOfHanoi(5, 'A', 'B', 'C');
   return 0;
}