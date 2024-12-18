#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using u64 = uint64_t;
const i64 mod = 1e9 + 7;

void solution()
{

    int x;
    i64 m;
    cin >> x >> m;

    int ans = 0;
    for (int y = 1; y <= min((i64)(2LL * x), m); y++)
    {
        if ((x != y) and (((x % (x ^ y)) == 0)) or ((x % (x ^ y)) == 0))
        {
            ++ans;
        }
    }

    cout << ans << endl;
}

int main()
{
#ifdef LOCAL
    freopen(getenv("CONTEST_INPUT_FILE"), "r", stdin);
    freopen(getenv("CONTEST_OUTPUT_FILE"), "w", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    for (int ti = 0; ti < t; ti++)
        solution();
}