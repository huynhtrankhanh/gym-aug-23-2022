#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;

    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        n++;
        k++;
        cout << (((n * (n + 1) / 2) % 1000000007) * k) % 1000000007 << "\n";
    }
}