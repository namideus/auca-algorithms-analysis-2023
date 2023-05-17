#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

vector<tuple<int, string, string>> v;

inline void precalc()
{
    v = {
            make_tuple(0, "00:00", "00:59"), make_tuple(0, "01:00", "01:59"),
            make_tuple(0, "02:00", "02:59"), make_tuple(0, "03:00", "03:59"),
            make_tuple(0, "04:00", "04:59"), make_tuple(0, "05:00", "05:59"),
            make_tuple(0, "06:00", "06:59"), make_tuple(0, "07:00", "07:59"),
            make_tuple(0, "08:00", "08:59"), make_tuple(0, "09:00", "09:59"),
            make_tuple(0, "10:00", "10:59"), make_tuple(0, "11:00", "11:59"),
            make_tuple(0, "12:00", "12:59"), make_tuple(0, "13:00", "13:59"),
            make_tuple(0, "14:00", "14:59"), make_tuple(0, "15:00", "15:59"),
            make_tuple(0, "16:00", "16:59"), make_tuple(0, "17:00", "17:59"),
            make_tuple(0, "18:00", "18:59"), make_tuple(0, "19:00", "19:59"),
            make_tuple(0, "20:00", "20:59"), make_tuple(0, "21:00", "21:59"),
            make_tuple(0, "22:00", "22:59"), make_tuple(0, "23:00", "23:59")
    };
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, i, j, km;
    string s, license, timedate, hour, min, type, ex, en;

    precalc();

    cin >> t;

    while (t--)
    {
        set<string> licenses;
        unordered_map <string, vector<tuple<string, string, int>>> enter, exit, record;

        for (i = 0; i < 24; i++)
            cin >> get<0>(v[i]);

        cin.ignore();

        while (getline(cin, s) && !s.empty())
        {
            istringstream iss(s);
            iss >> license >> timedate >> type >> km;
            licenses.insert(license);
            record[license].emplace_back(timedate, type, km);
        }

        for (const auto &l : licenses)
        {
            sort(begin(record[l]), end(record[l]), [](const auto & a, const auto & b)
            {
                return get<0>(a) < get<0>(b);
            });

            double bill = 0;

            for (i = 0; i < sz(record[l]) - 1; ++i)
            {
                const auto a = record[l][i];
                const auto b = record[l][i + 1];

                if (get<1>(a) == "enter" && get<1>(b) == "exit")
                {
                    string time = get<0>(a).substr(6);

                    auto it = find_if(begin(v), end(v), [time](const auto & t) {
                        return get<1>(t) <= time && time <= get<2>(t);
                    });

                    bill += 100 + abs(get<2>(a) - get<2>(b)) * get<0>(*it);
                }
            }

            bill += 200;

            cout << fixed << setprecision(2);

            if (bill != 200)
                cout << l << " $" << bill / 100.0 << "\n";
        }

        if (t) cout << "\n";
    }
}