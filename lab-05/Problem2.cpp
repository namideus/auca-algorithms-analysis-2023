#include <bits/stdc++.h>
#define msg_gr "GRANTED\n"
#define msg_de "DENIED\n"
#define msg_ig "IGNORED\n"
#define lli long long int

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lli n, t, trid, item;
    char mode;

    cin >> t;

    while (t--)
    {
        map<lli, set<lli>> avail;
        map<lli, bool> ignor;
        map<lli, lli> track;

        while (cin >> mode && mode != '#')
        {
            cin >> trid >> item;

            if (ignor[trid])
            {
                cout << msg_ig;
                continue;
            }

            switch (mode)
            {
                case 'S':
                    if (track.find(item) != end(track))
                    {
                        if (track[item] == trid)
                        {
                            cout << msg_gr;
                        } else {
                            cout << msg_de;
                            ignor[trid] = true;
                        }
                    } else {
                        cout << msg_gr;
                        avail[item].insert(trid);
                    }
                    break;
                case 'X':
                    if (avail.find(item) != end(avail))
                    {
                        if (sz(avail[item]) == 1 && *begin(avail[item]) == trid)
                        {
                            cout << msg_gr;
                            track[item] = trid;
                        } else {
                            cout << msg_de;
                            ignor[trid] = true;
                        }
                    } else if (track.find(item) == end(track) || track[item] == trid)
                    {
                        cout << msg_gr;
                        track[item] = trid;
                    } else {
                        cout << msg_de;
                        ignor[trid] = true;
                    }
                    break;
            }
        }

        if (t)
            cout << "\n";
    }
}
