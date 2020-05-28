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
ll pre[N][N], fre[N][N];
ll n,k,x,f,l,m,r,b,M,bx; 
ll a[N];

void solve() {
    b = 0;
    rep(i,0,N) { pre[i][0] = 0; fre[i][0] = N; }
    cin>>n>>k;
    rep(i,0,n) {
        cin>>a[i];
        rep(j,1,N) {
            pre[j][i+1] = pre[j][i] + (j>=a[i] ? 1:0); 
            fre[j][i+1] = fre[j][i] + (j==a[i] ? 1:0);
        }  
    }
    rep(i,0,n){
        rep(j,i,n){
            M = (k+j-i)/(j-i+1);
            x = (k+M-1)/M;
            l = 0; r = 1999;
            while(l <= r){
                m = (l+r)/2;
                f = pre[m+1][j+1]-pre[m+1][i];
                if( f == x ) { bx = m+1; r = m-1; }
                if( f > x ) { bx = m+1; r = m-1; }
                if( f < x ) l = m+1;
            }
            // cout<<bx<<endl;
            f = fre[bx][j+1] - fre[bx][i];
            if(fre[f][j+1] - fre[f][i] > 0) b += 1;
        }
    }
    cout<<b<<endl;
}   

int main(){
    fastio;
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    cin>>t;
    while(t--)
    solve();
    return 0;
}
