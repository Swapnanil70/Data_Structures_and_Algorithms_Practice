#include<iostream>
using namespace std;
void printPi(string s){
    if(s.length() == 0)
        return;

    if (s[0] == 'p' && s[1] == 'i')
    {
        /* code */
        cout<<3.14;
        printPi(s.substr(2));
    }
    else 
    {
        cout<<s[0];
        printPi(s.substr(1));
    }
    
}
int main()
{
    printPi("pixxppipsipi");
   return 0;
}