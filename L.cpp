#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    vector<string> to_be_sorted(n);

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        string min_string = s;

        for (int i = 0; i < 2 * n; i++)
        {
            auto first_char = s[0];
            s.erase(s.begin());
            s += first_char;
            min_string = min(min_string, s);
        }

        to_be_sorted[i] = min_string;
    }

    sort(to_be_sorted.begin(), to_be_sorted.end());

    to_be_sorted.erase(unique(to_be_sorted.begin(), to_be_sorted.end()), to_be_sorted.end());

    cout << to_be_sorted.size() << "\n";
}
