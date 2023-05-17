#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    bool f;
    int n, t;
    string s;

    cin >> t;
    cin.ignore();

    while (t--)
    {
        getline(cin, s);

        list<char> l;

        auto it = l.begin();

        for (auto c : s)
        {
            if (c == '<')
            {
                if (it != l.begin())
                    it = l.erase(--it);
                else
                {}
            } else if (c == '[')
            {
                it = l.begin();
            } else if (c == ']')
            {
                it = l.end();
            } else {
                it = l.insert(it, c);
                it++;
            }
        }

        for (auto c : l) cout << c;

        cout << "\n";
    }
}


