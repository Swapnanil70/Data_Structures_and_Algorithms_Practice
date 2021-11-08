#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
#include<unordered_map>
#define rep(i,a,b) for(int i = 0; i < b; i++)
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
using namespace std;
int main()
{
    int n;
    cin>> n;

    vector<int> a(n);

    rep(i,0,n){
        cin>> a[i];
    }
    priority_queue<int, vi, greater<int> > minheap;

    rep(i, 0, n){
        minheap.push(a[i]);
    }
    int ans = 0;

    while(minheap.size() > 1){
        int e1 = minheap.top();
        minheap.pop();
        int e2 = minheap.top();
        minheap.pop();
        ans += e1 + e2;
        minheap.push(e1 + e2);
    }
    cout<<ans;
    return 0;
}