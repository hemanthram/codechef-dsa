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
#define rev(i,a,b) for(ll i=a;i>b;i--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define printn(a) cout<<a<<'\n'
#define prints(a) cout<<a<<' '
#define nl '\n'
const ll N = 100005;
ll parent[N], size[N];
bool res;

ll find_set(ll x) {
    if(x == parent[x]) return x;
    return parent[x] = find_set(parent[x]);
}
void make_set(ll x) { parent[x]=x; size[x]=1; }
void union_set(ll x, ll y) {
    x = find_set(x);
    y = find_set(y);
    if(x == y) return;
    // if(size[x] < size[y]) swap(x,y);
    parent[y] = x;
    size[x] += size[y];
}

void solve(){
    ll n,q,o,x,y; cin>>n;
    vec s(n+1); rep(i,0,n) { cin>>s[i+1]; make_set(i+1); }
    cin>>q; rep(i,0,q) {
        cin>>o; 
        if(o == 0) {
            cin>>x>>y;
            ll px = find_set(x), py = find_set(y);
            if(px == py) { printn("Invalid query!"); continue; }
            if(s[px] > s[py]) union_set(x,y);
            if(s[py] > s[px]) union_set(y,x);
        }
        else {
            cin>>x;
            printn(find_set(x));
        }
    }
}

int main(){
    fastio;
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	#endif
    ll t=1;
    cin>>t;
    while(t--)
    solve();
    return(0);
}