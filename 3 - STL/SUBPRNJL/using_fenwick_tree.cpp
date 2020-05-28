// g++ file.cpp -o file | file
// ram learns c++

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define vec vector<ll>
#define pb  push_back
#define pai pair<ll,ll>
#define all(a) (a).begin(),(a).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
const ll N = 2002;
ll fre[N][N];
ll n,k,x,f,l,m,r,b,M,bx; 
ll a[N];
ll fenv[N];
void addFenv(ll p, ll x) {
    for(; p < N; p |= p + 1)
        fenv[p] += x;
}
ll getFenv(ll r) {
    ll res = 0;
    for(; r >= 0; r = (r & (r + 1)) - 1)
        res += fenv[r];
    return res;
}
ll kFenv(ll k) {
    ll l = 0; 
    ll h = N; 
    while (l < h) {
        ll mid = (l+h)/2; 
        if (k <= getFenv(mid)) h = mid; 
        else l = mid+1; 
    }  return l; 
}


void solve() {
    b = 0;
    rep(i,0,N) { fenv[i] = 0; fre[i][0] = N; }
    cin>>n>>k;
    rep(i,0,n) {
        cin>>a[i];
        rep(j,1,N) 
        fre[j][i+1] = fre[j][i] + (j==a[i] ? 1:0);  
    }
    rep(i,0,n){
        rep(j,i,n){
            M = (k+j-i)/(j-i+1);
            x = (k+M-1)/M;
            l = 0; r = 1999;
            addFenv(a[j], 1);
            bx = kFenv(x);
            f = fre[bx][j+1] - fre[bx][i];
            if(fre[f][j+1] - fre[f][i] > 0) b += 1;
        }
    }
    cout<<b<<endl;
}   

int main(){
    fastio;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll t=1;
    cin>>t;
    while(t--)
    solve();
    return 0;
}
