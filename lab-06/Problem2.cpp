#include <bits/stdc++.h>
#define llui long long unsigned int

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, ans, w, t;

    unordered_map<string, string> dict;

    while (getline(cin, s) && !s.empty())
    {
        istringstream iss(s);
        iss >> w >> t;
        dict[t] = w;
    }

    while (cin >> w)
    {
        if (!dict[w].empty())
            cout << dict[w] << "\n";
        else
            cout << "eh\n";
    }
}