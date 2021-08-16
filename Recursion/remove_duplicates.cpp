#include<iostream>
using namespace std;
string removeDup(string s){

    if (s.length() == 0)
    {
        return "";
        /* code */
    }
    char ch = s[0];
    string ans = removeDup(s.substr(1));

    if (ch == ans[0])
    {
        /* code */
        return ans;
    }
    return (ch + ans);
    
    
}
int main()
{
    cout<<removeDup("aaaafdjfdddffffsddss");
   return 0;
}