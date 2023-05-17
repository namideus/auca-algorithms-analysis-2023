#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

long team[1000000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, c, t, m, a, id, mem, pos;
    string cmd;
    c = 1;

    while (cin >> t && t)
    {
        deque<pair<int, deque<int>>> q;

        for (int i = 0; i < t; ++i)
        {
            cin >> m;
            while (m--)
            {
                cin >> mem;
                team[mem] = i;
            }
        }
        cout << "Scenario #" << c << "\n";
        while (cin >> cmd && cmd[0] != 'S')
        {
            if (cmd[0] == 'E')
            {
                cin >> id;
                auto it = find_if(begin(q), end(q), [id](const pair<int, deque<int>> &p)
                {
                    return team[id] == p.first;
                });

                if (it == end(q))
                    q.push_back({team[id], deque<int>{id}});
                else
                    it->second.push_back(id);
            }
            if (cmd[0] == 'D')
            {
                cout << q.front().second.front() << "\n";
                q.front().second.pop_front();

                if (q.front().second.empty())
                    q.pop_front();
            }
        }
        cout << "\n";
        c++;
    }
}

