#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int id = 0, i, s, n;

    cin >> s >> n;

    vector<pair<int, int>> state;

    for (i = 1; i <= n; i++)
        state.emplace_back(i, 1);

    while (sz(state) > 1)
    {
        id = (id + s - 1) % sz(state);  // cyclic id
        auto p = state[id];

        if (p.second == 1)  // folded
        {
            state[id] = {p.first, 2};
            state.insert(begin(state) + id, {p.first, 2});
        } else if (p.second == 2)   // fists
        {
            state[id] = {p.first, 3};
            id++;
        } else // palm down
        {
            state.erase(begin(state) + id);
        }
    }

    cout << state[0].first << "\n";
}