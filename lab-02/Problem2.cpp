#include <bits/stdc++.h>
#define INF 1e9

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct car
{
    int arrival_time, id;

    car(int t, int i) {
        arrival_time = t;
        id = i;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, c, t, m, a, time;
    string s;
    char fs;

    cin >> c;

    while (c--)
    {
        cin >> n >> t >> m;

        queue<car> left, right;
        vector<int> load_time(m);

        for (int i = 0; i < m; ++i)
        {
            cin >> a >> s;

            if (s.front() == 'l')
                left.emplace(a, i);
            else
                right.emplace(a, i);
        }

        time = 0;
        fs = 'l';

        while (!left.empty() || !right.empty())
        {
            int early_car = INF;

            if (!left.empty())
                early_car = left.front().arrival_time;

            if (!right.empty())
                early_car = min(early_car, right.front().arrival_time);

            time = max(early_car, time);

            for (int i = 0; i < n; i++)
            {
                if (left.empty() && right.empty())
                    break;

                if (fs == 'l' && left.front().arrival_time > time)
                    break;

                if (fs == 'r' && right.front().arrival_time > time)
                    break;

                if (fs == 'l' && !left.empty())
                {
                    load_time[left.front().id] = time + t;
                    left.pop();
                }

                if (fs == 'r' && !right.empty())
                {
                    load_time[right.front().id] = time + t;
                    right.pop();
                }
            }

            time += t;
            fs = fs == 'l' ?  'r' : 'l';
        }

        for (auto time : load_time)
            cout << time << "\n";

        if (c) cout << "\n";
    }
}