#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    string s;
    rep(i,0,3)s+='1';
    rep(i,0,5)s+='6';
    rep(i,0,2)s+='7';
    mt19937 prng(chrono::high_resolution_clock::now().time_since_epoch().count());
    shuffle(s.begin(), s.end(), prng);
    cout << s << "\n";
}