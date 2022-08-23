#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    long long a, b, c;
    cin >> a >> b >> c;

    auto f = [&](long long sum) {
        return sum - 100 * (long long)(sum >= 500);
    };

    cout << min({f(a + b + c), f(a + b) + f(c), f(a) + f(b + c), f(b) + f(a + c), f(a) + f(b) + f(c)}) << "\n";
}