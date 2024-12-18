#include <bits/stdc++.h>
using namespace std;
template <typename... T>
void see(T &...args) { ((cin >> args), ...); }
template <typename... T>
void put(T &&...args) { ((cout << args << " "), ...); }
template <typename... T>
void putl(T &&...args)
{
    ((cout << args << " "), ...);
    cout << '\n';
}

template <typename T>
void print(vector<T> x)
{
    for (auto i : x)
        cout << i << ' ';
    cout << "\n";
}
template <typename T>
void print(set<T> x)
{
    for (auto i : x)
        cout << i << ' ';
    cout << "\n";
}
template <typename T>
void print(unordered_set<T> x)
{
    for (auto i : x)
        cout << i << ' ';
    cout << "\n";
}
template <typename T>
void print(T &&x) { cout << x << "\n"; }
template <typename T, typename... S>
void print(T &&x, S &&...y)
{
    cout << x << ' ';
    print(y...);
}

#define int long long
#define pb push_back
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define vi vector<int>
#define vii vector<pii>
#define vc vector
#define L cout << '\n';
#define E cerr << '\n';
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rev(i, a, b) for (int i = a; i > b; --i)
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define setpr(x) cout << setprecision(x) << fixed
#define sz size()
#define seea(a, x, y)           \
    for (int i = x; i < y; i++) \
    {                           \
        cin >> a[i];            \
    }
#define seev(v, n)              \
    for (int i = 0; i < n; i++) \
    {                           \
        int x;                  \
        cin >> x;               \
        v.push_back(x);         \
    }
#define sees(s, n)              \
    for (int i = 0; i < n; i++) \
    {                           \
        int x;                  \
        cin >> x;               \
        s.insert(x);            \
    }
#define NO cout << "NO" << endl
#define YES cout << "YES" << endl
#define initarr0(arr, n) memset(arr, 0, sizeof(arr[0]) * n)
#define initarr(arr, n, val) memset(arr, val, sizeof(arr[0]) * n)
#define initArrInf(arr, n) memset(arr, 0x3f3f3f3f, sizeof(int) * n)

const ll maxi = 1000000007;
const ll inf = 1LL << 62;

// template<class T> void print(vector<T> x){
//     for(auto i:x){
//         auto mk = i;
//         cout<<mk<<" ";
//     }
//     // cout<<endl;
// }

// template<class T> void print()

set<ll> primefactors(ll n)
{
    set<ll> ans = {};
    if (n % 2 == 0)
    {
        ans.insert(2);
        while (n % 2 == 0)
        {
            n /= 2;
            n = (int)(n);
        }
    }
    if (n != 1)
    {
        ll t = n;
        for (ll i = 3; i <= sqrt(t); i += 2)
        {
            if (n % i == 0)
            {
                ans.insert(i);
                while (n % i == 0)
                {
                    n /= i;
                }
            }
        }
        ans.insert(n);
    }
    return ans;
}
bool isitprime(int nb)
{
    if (nb == 1)
        return false;
    else if (nb == 2 || nb == 3)
        return true;
    else
    {
        if (nb % 2 == 0)
            return false;
        else
        {
            int f2 = 1;
            for (int i = 3; i <= sqrt(nb); i += 2)
            {
                if (nb % i == 0)
                {
                    f2 = 0;
                    break;
                }
            }
            if (f2)
                return true;
            else
                return false;
        }
    }
}
int cntfac(int x)
{
    int c = 0;
    for (int i = 1; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            ++c;
            if (x / i != i)
                ++c;
        }
    }
    return c;
}
bool ispalindrome(string s)
{
    if (s.size() == 1)
        return true;
    else
    {
        int f = 1;
        for (int i = 0; i < s.size() / 2; i++)
        {
            if (s[i] != s[s.size() - 1 - i])
            {
                f = 0;
                break;
            }
        }
        if (f)
            return true;
        else
            return false;
    }
}
ll binexponent(ll a, ll b, ll mod = maxi)
{
    if (b == 0)
        return 1;
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans % mod;
}
ll binaryMultiplier(ll a, ll b)
{
    ll mu = 1e9 + 7;
    a = a % mu;
    b = b % mu;
    ll ans = 0;
    while (b)
    {
        if (b % 2)
            ans = ((ans + a)) % mu;
        a = (a + a) % mu;
        b >>= 1;
    }
    return ans;
}
ll gcd(ll a, ll b)
{
    ll temp;
    if (a == b)
        return a;
    while (b > 0)
    {
        temp = b;
        b = b % a;
        a = temp;
    }
    return a;
}
int nCr(int n, int k)
{
    int res = 1;
    if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res = res % maxi;
        res /= (i + 1);
    }
    return res;
}

bool isvowel(char ch) { return (2130466 >> (ch & 31)) & 1; }

int fi(int u, vector<int> &par)
{
    if (u == par[u])
        return u;
    return par[u] = fi(par[u], par);
}

vector<int> centroid(vc<vi> &graph)
{
    int n = graph.sz;
    vi centroid;
    vi rank(n, 1);
    print(centroid);

    function<void(int, int)> dfs = [&](int curr, int prev)
    {
        bool is_centroid = false;

        for (auto nxt : graph[curr])
            if (nxt != prev)
            {
                dfs(nxt, curr);
                rank[curr] += rank[nxt];
                if (rank[nxt])
                    is_centroid = true;
            }

        if (n - rank[curr] > (n / 2))
            is_centroid = false;

        if (is_centroid)
            centroid.pb(curr);
    };

    dfs(0, -1);

    return centroid;
}

bool dfsfe(vc<vi> &graph, int node)
{
    int n = graph.sz;
    vi rank(n, 1);

    bool ans = true;

    function<void(int, int)> dfs = [&](int curr, int prev)
    {
        vi child;
        for (auto v : graph[curr])
            if (v != prev)
            {
                dfs(v, curr);
                child.pb(rank[v]);
            }

        sort(all(child));
        for (auto c : child)
        {
            if (c > rank[curr])
            {
                ans = false;
            }
            rank[curr] += c;
        }
        return rank[curr];
    };

    dfs(node, 0);
    return ans;
}

void op(char &ch, int delta)
{
    ch = char('0' + (ch - '0' + delta) % 3);
}

const int MAX_SIZE = 1e5;
struct FenwickTree
{
    int n;
    int bit[MAX_SIZE];

    FenwickTree(int n)
    {
        this->n = n;
        memset(this->bit, 0, sizeof(this->bit));
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size())
    {
        for (size_t i = 0; i < a.size(); i++)
        {
            bit[i] += a[i];
            int sr = i | (i + 1);
            if (sr < n)
                bit[sr] += bit[i];
        }
    }

    int sum(int l)
    {
        int sm = 0;
        for (; l >= 0; l = (l & (l + 1)) - 1)
            sm += bit[l];
        return sm;
    }

    int sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta)
    {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

const int INF = 0x3f3f3f3f;
class SegmentTree
{

public:
    int n;
    int t[MAX_SIZE * 4];
    int totalSm;

    SegmentTree(vector<int> const &a) : SegmentTree(a, [](int a, int b)
                                                    { return a + b; }) {}

    // SegmentTree(vector<int> const &a, function<int(int,int)> func): SegmentTree(a, func){
    //     memset(t, setter, sizeof(t));
    // }

    SegmentTree(vector<int> const &a, std::function<int(int, int)> func, int setter = 0)
    {
        this->n = a.size();
        this->comp = func;
        memset(t, setter, sizeof(t));
        this->totalSm = build(a, 0, 0, n - 1);
        this->print();
        cout << this->totalSm << endl;
    }

    void print()
    {
        cout << "print: ";
        for (int i = 0; i < (this->n) * 4; i++)
        {
            cout << t[i] << " ";
        }
        cout << endl;
    }

    int build(vector<int> const &a, int v, int l, int r)
    {
        if (l == r)
        {
            t[v] = a[l];
        }
        else
        {
            int m = (l + r) / 2;
            t[v] = comp(build(a, v * 2 + 1, l, m), build(a, v * 2 + 2, m + 1, r));
            // t[v] = build(a, v*2+1, l, m)+ build(a, v*2+2, m+1, r);
        }
        return t[v];
    }

    int query(int l, int r)
    {
        return query(0, 0, n - 1, l, r);
    }

    int query(int x, int l, int r, int xl, int xr)
    {
        if (xr < l || r < xl)
            return 0;
        if (xl <= l && r <= xr)
            return t[x];

        int mid = (l + r) / 2;
        int lsum = query(x * 2 + 1, l, mid, xl, xr);
        int rsum = query(x * 2 + 2, mid + 1, r, xl, xr);

        return this->comp(lsum, rsum);
        // return lsum+rsum;
    }

private:
    std::function<int(int, int)> comp;
};


bool compa(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

void solvution(){
    int n;
    cin>>n;
    
    unordered_map<pair<int,int>, int> dp;
    vector<string> s(2);
    
    cin>>s[0]; cin>>s[1];




}

signed main()
{
    IOS;
    #ifdef LOCAL
        clock_t tStart = clock();
        freopen(getenv("CONTEST_INPUT_FILE"), "r", stdin);
        freopen(getenv("CONTEST_OUTPUT_FILE"), "w", stdout);
    #endif

    // cout << setprecision(15);

    /*MULTI - CODEFORCES*/ int n; cin >> n; for (int i = 0; i < n; i++) solvution();
    // /*MULTI - META*/ int n; cin>>n; for(int i=0; i<n; i++) { cout<<"Case #"<<(i+1)<<": "; solvution(); cerr<<"Test #"<<(i+1)<<" completed"<<endl;}
    // /*SINGLE - ATCODER;CSES*/ solvution();

    #ifdef LOCAL
        cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}