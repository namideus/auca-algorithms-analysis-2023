#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

map<string, string> g;
map<string, list<string>> cp;

inline void set_gene(string child, string p1, string p2)
{
    if (g[p1].empty())
        set_gene(p1, cp[p1].front(), cp[p1].back());

    if (g[p2].empty())
        set_gene(p2, cp[p2].front(), cp[p2].back());

    string res = "non-existent";

    if ((g[p1][0] != 'n' && g[p2][0] != 'n') || (g[p1][0] == 'd' || g[p2][0] == 'd'))
        if (
                (g[p1][0] == 'd' && g[p2][0] == 'd') ||
                (g[p1][0] == 'd' && g[p2][0] == 'r') ||
                (g[p1][0] == 'r' && g[p2][0] == 'd')
                )
            res = "dominant";
        else
            res = "recessive";

    g[child] = res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    string a, b;

    cin >> n;

    while (n--)
    {
        cin >> a >> b;

        if (b == "dominant" || b == "recessive" || b == "non-existent")
            g[a] = b;
        else
            cp[b].push_back(a);
    }

    for (auto child : cp)
        set_gene(child.first, child.second.front(), child.second.back());

    for (const auto& gene : g)
        cout << gene.first << " " << gene.second << "\n";
}
