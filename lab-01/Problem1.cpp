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
    int n;
    string s;

    while (getline(cin, s))
    {
        n = sz(s);
        string w;
        list<string> l;

        for (int i = 0; i < n; i++)
        {
            w = "";

            if (s[i] == '[' && (s[i + 1] != '[' && s[i + 1] != ']') && i < n)
            {
                i += 1;
                while (s[i] != '[' && s[i] != ']' && i < n)
                {
                    w += s[i];
                    i++;
                }
                l.push_front(w);
                i--;
            } else if (s[i] != ']' && s[i] != '[')
                l.emplace_back(1, s[i]);
        }

        for (auto d : l)
            cout << d;

        cout << "\n";
    }
}


