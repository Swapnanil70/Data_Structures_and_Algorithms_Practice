#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;
int main()
{
    set<int> s;
    multiset<int> m;
    unordered_set<int> us;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    for(auto i : s)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    s.erase(3);
    s.insert(4);
    for(auto i : s)
        cout<<i<<" ";
    cout<<endl<<s.size()<<endl;


    m.insert(1);
    m.insert(2);
    m.insert(3);
    m.insert(4);
    m.insert(5);
    for(auto i : m)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    m.erase(3);
    m.insert(4);
    m.erase(4); //multiset will delete all occurrences of the element but m.erase(m.find(4)) will not
    for(auto i : m)
        cout<<i<<" ";
    cout<<endl<<m.size()<<endl;


    us.insert(1);
    us.insert(2);
    us.insert(3);
    us.insert(4);
    us.insert(5);
    for(auto i : us)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    us.erase(3);
    us.insert(4);
    for(auto i : s)
        cout<<i<<" ";
    cout<<endl<<us.size();
   return 0;
}