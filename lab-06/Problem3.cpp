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

    string s, t, txt, word;

    int i, j, n, c, w, p;

    cin >> n;

    while (n--)
    {
        cin >> c;

        unordered_map<string, multiset<string>> ctg;
        unordered_map<string, int> cat_min, cnt;
        map<int, string> cat_order;
        unordered_map<string, bool> met;

        for (j = 0; j < c; j++)
        {
            cin >> s >> w >> p;
            cat_order[j] = s;
            cat_min[s] = p;

            for (i = 0; i < w; i++)
            {
                cin >> t;
                ctg[s].insert(t);
            }
        }

        getline(cin, txt);

        while (getline(cin, txt) && !txt.empty())
        {
            for (i = 0; i < sz(txt); i++)
                if (!isalpha(txt[i]))
                    txt[i] = ' ';

            istringstream iss(txt);

            while (iss >> word)
            {
                if (met[word])
                    continue;

                for (const auto &x : ctg)
                    for (const auto &e : x.second)
                        if (word == e)
                            cnt[x.first]++;

                met[word] = true;
            }
        }

        bool f = true;

        for (const auto &x : cat_order)
            if (cnt[x.second] >= cat_min[x.second])
            {
                if (!f)
                    cout << ",";

                cout << x.second;
                f = false;
            }

        if (f)
            cout << "SQF Problem.";


        cout << "\n";
    }
}