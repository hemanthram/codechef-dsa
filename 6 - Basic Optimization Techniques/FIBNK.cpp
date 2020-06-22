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
const ll M = 1000000007;

void matMul(ll a[2][2], ll b[2][2]){
    ll c[2][2];
    rep(i,0,2)
    rep(j,0,2){
        c[i][j] = 0;
        rep(k,0,2)
        c[i][j] = (c[i][j]+(a[i][k]*b[k][j]))%M;
    }
    rep(i,0,2)
    rep(j,0,2)
    a[i][j] = c[i][j];
}

long long fibN(ll n){
    if(n <= 2){
        if(n==0) return 0;
        if(n==1) return 1;
        return 1;
    } n -= 2; 
    ll m[2][2] = {{1,1},{1,0}}, fn[2][2]={{1,0},{1,1}};
    while(n>0) {
        if(n%2 != 0) matMul(fn,m);
        n = n>>1;
        matMul(m,m);
    }
    return fn[1][0];
}

void solve(){
    ll n,k; cin>>n>>k;
    ll q = n/k; ll r = n%k;
    ll R = (fibN(r+1)-1)%M;
    ll K = (fibN(k+1)-1)%M;
    cout<<(K*q+R)%M<<endl; 
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