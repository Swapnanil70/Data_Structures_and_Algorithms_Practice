#include<iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int> &st, int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }
    
    int topele = st.top();
    st.pop();
    insertAtBottom(st, ele);
    st.push(topele);
}
void reverse(stack<int> &st){
    if(st.empty())
        return;

    int ele = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st, ele);
}
int main()
{
    stack<int> st;
    for (int i = 0; i < 6; i++)
    {
        /* code */
        st.push(i);
    }
    cout<<st.top()<<endl;
    reverse(st);
   while (!st.empty())
   {
       /* code */
       cout<<st.top()<<" ";
       st.pop();
   }
   
   return 0;
}