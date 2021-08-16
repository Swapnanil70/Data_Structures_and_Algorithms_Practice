#include<iostream>
#include<stack>
using namespace std;
void revSentence(string s){
    stack<string> st;
    string word = "";
    for(int i = 0; i <= s.length(); i++){
        
        if(s[i] != ' ' && i != s.length())
            word += s[i];

        if(s[i] == ' ' || i == s.length()){
            st.push(word);
            word ="";
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main()
{
    string s = "Hey, how are you doing?";
    revSentence(s);
   return 0;
}