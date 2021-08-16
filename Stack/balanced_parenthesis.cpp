#include<iostream>
#include<stack>
using namespace std;
bool isValid(string s){

    stack<char> st;
    for(int i = 0; i< s.length(); i++){
        
        if(s[i] == '[' or s[i] == '(' || s[i] == '{'){
            st.push(s[i]);
        }
        else
        {
            if(s[i] == '}'){
                if(st.top() != '{')
                    return false;

                st.pop();
            }
            if(s[i] == ')'){
                if(st.top() != '(')
                    return false;

                st.pop();
            }
            if(s[i] == ']'){
                if(st.top() != '[')
                    return false;

                st.pop();
            }
        }
    }
    if(st.empty())
        return true;

    return false;
}
int main()
{
    cout<<isValid("{([])");
   return 0;
}