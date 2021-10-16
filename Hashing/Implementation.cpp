#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

signed int main(int argc, const char** argv) {

    map<int, int> m;
    m[8] = 2;
    // m.insert(3, 6);
    cout<<m[8];
    // cout<<endl<<m[6];
    return 0;
}