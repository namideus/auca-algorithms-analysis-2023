#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    stack<string> st;

    while (n--)
    {
        string cmd;
        cin >> cmd;

        if (cmd[0] == 'S')
        {
            string x;
            cin >> x;
            st.push(x);
        } else if (cmd[0] == 'K' && sz(st) > 0)
            st.pop();
        else if (cmd[0] == 'T')
        {
            if (sz(st) > 0)
                cout << st.top() << "\n";
            else
                cout << "Not in a dream\n";
        }
    }
}