#include <iostream>
using namespace std;
void subseq(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = s[0];
    string rest = s.substr(1);
    int code = ch;
    subseq(rest, ans);
    subseq(rest, ans + ch);
    subseq(rest, ans + to_string(code));
}
int main()
{
    subseq("ABC", "");
    cout << endl;
    return 0;
}