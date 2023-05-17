#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    double E_t, E_max, E_rel, lamdba = 0;
    string txt, in, out;

    map<string, int> p;
    istringstream iss;

    while (getline(cin, txt) && txt != "****END_OF_INPUT****")
    {
        if (txt == "****END_OF_TEXT****")
        {
            E_max = log10(lamdba);

            for (auto const &x : p)
                E_t += (x.second * log10(lamdba / x.second)) / lamdba;

            E_rel = E_t * 100 / E_max;

            cout << fixed << setprecision(0);
            cout << lamdba << " ";
            cout << fixed << setprecision(1);
            cout << (E_t * 10) / 10 << " ";
            cout << fixed << setprecision(0);
            cout << E_rel << "\n";

            lamdba = E_t =  0;

            p.clear();
            iss.clear();
        }
        else if (txt != "")
        {
            iss = istringstream(txt);

            while (iss >> in)
            {
                lamdba++;
                out = "";

                for (auto const &c : in)
                    if (c != ',' && c != '.' && c != ':' && c != ';' && c != '!' && c != '?' && c != '"' && c != '(' && c != ')')
                        out += tolower(c);

                p[out]++;
            }
        }
    }
}