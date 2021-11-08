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
    int n;cin>>n;

    vi a(n);

    rep(i,0,n){
        cin>>a[i];
    }

    sort(a.begin(),a.end());

    long long mx = 0, mn = 0;

    rep(i, 0, n/2){
        mx += (a[i+n/2] - a[i]);
        mn += (a[2*i+1] - a[2*i]);
    }
    cout<<mn<<" "<<mx;
    return 0;
}