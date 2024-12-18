#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll maxi=1e9+7;
int mod=maxi;
int mach=998244353;
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define vi vector<int> ;
#define vc vector<char>;
template<class T> void printvec(vector<T> x){
    for(auto i:x){
        auto mk = i;
        cout<<mk<<" ";
    }
    cout<<endl;
}
set<ll> primefactors(ll n){
    set<ll> ans = {};
    if(n%2==0){
        ans.insert(2);
        while(n%2==0){
            n /= 2;
            n = int(n);
        }
    }
    if (n!=1){
        ll t = n;
        for(ll i = 3; i<= sqrt(t); i+=2){
            if (n%i==0){
                ans.insert(i);
                while(n%i==0){
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
  if(nb==1) return false;
  else if(nb==2||nb==3) return true;
  else{
        if(nb%2==0) return false;
        else{
            int f2=1;
            for(int i=3;i<=sqrt(nb);i+=2){
                if(nb%i==0){
                    f2=0;
                    break;
                }
            }
            if(f2) return true;
            else return false;
        }
  }
}
int cntfac(int x){
    int c=0;
    for(int i=1;i<=sqrt(x);i++){
        if(x%i==0){
        ++c;
        if(x/i!=i) ++c;
        }
    }
    return c;
}
bool ispalindrome(string s){
  if(s.size()==1) return true;
  else{
    int f=1;
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-1-i]){
            f=0;
            break;
        }
    }
    if(f) return true;
    else return false;
  }
}
ll binexponent(ll a, ll b){
    if (b == 0) return 1;
    ll ans = 1;
    while (b){
        if (b & 1) ans = (ans * a) % maxi;
        a = (a * a) % maxi;
        b >>= 1;
    }
    return ans%maxi;
}
ll binaryMultiplier(ll a,ll b){
    ll mu=1e9+7;
    a=a%mu;
    b=b%mu;
    ll ans=0;
    while(b){
        if(b%2) ans=((ans+a))%mu;
        a=(a+a)%mu;
        b>>=1;
    }
    return ans;
}
ll gcd(ll a,ll b){
    ll temp;
    if(a==b) return a; 
    while(b>0){
        temp = b;
        b = b%a;
        a = temp; 
    }
    return a;
}
int nCr(int n, int k){
    int res = 1;
    if (k > n - k) k = n - k;
    for (int i = 0; i < k; ++i){
        res *= (n - i);
        res=res%maxi;
        res /= (i + 1);
    }
    return res;
}
bool isvowel(char a){
    if(a=='A'||a=='E'||a=='I'||a=='O'||a=='U'||a=='a'||a=='e'||a=='i'||a=='o'||a=='u') return true;
    return false;
}
vector<vector<int>> maxmul(vector<vector<int>> &a,vector<vector<int>> &b){
    vector<vector<int>> ans(2,vector<int>(2));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                ans[i][j]+=((a[i][k]%maxi)*(b[k][j]%maxi))%maxi;
            }
        }
    }
    return ans;
}
vector<vector<int>> mexpo(vector<vector<int>> &a,int n){
    if(n==0) return {{1,0},{0,1}};
    if(n==1) return {{2,2},{1,0}};
    vector<vector<int>> tp=mexpo(a,n/2);
    vector<vector<int>> ans;
    ans=maxmul(tp,tp);
    vector<vector<int>> f={{2,2},{1,0}};
    if(n&1) ans=maxmul(ans,f);
    return ans;
}
int fi(int u,vector<int> &par){
    if(u==par[u]) return u;
    return par[u]=fi(par[u],par);
}
void dsu(int u,int v,vector<int> &si,vector<int> &ed,vector<int> &se,vector<int> &par){
    u=fi(u,par);
    v=fi(v,par);
    if(u==v)
    return;
    if(si[v]>si[u])
    swap(u,v);
    par[v]=u;
    se[u]=max(se[u],se[v]);
    ed[u]+=ed[v];
    si[u]+=si[v];
}
void solvution(){
    int n,x,y,k;
    cin>>n>>k;
    vector<int> v(n);
    vector<int> dp(n+k,INT_MAX);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    dp[0] = 0;
    for(int i=0; i<n-1; i++){
        for(int j=1; j<=k; j++){
            dp[i+j] = min(dp[i+j], dp[i]+abs(v[i]-v[i+j]));
        }
    }
    cout<<dp[n-1];
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,y,z;
    solvution();
}