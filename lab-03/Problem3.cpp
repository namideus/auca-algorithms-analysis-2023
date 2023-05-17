#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test, t, m, n, cnt, i, j;
    string s, w, l, k;
    set<string> dict;

    while (getline(cin, s))
    {
        istringstream iss(s);

        while (iss >> w)
        {
            for (i = 0; i < sz(w); i++)
                if (isalpha(w[i]) || w[i] == '-')
                    l += tolower(w[i]);
                else if (!isalpha(w[i]) && w[i] != '-')
                    dict.insert(l), l = "";

            if (sz(l) > 0)
                if (l.back() == '-')
                    l.erase(end(l) - 1);
                else
                    dict.insert(l), l = "";
        }
    }

    for (auto w : dict)
        if (sz(w) > 0)
            cout << w << "\n";
}


