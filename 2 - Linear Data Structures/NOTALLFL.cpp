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
#define print(x) cout<<x<<endl

void solve(){
    ll n,k,ans = 0; 
    cin>>n>>k;
    vec a(n), p(k+1,0);
    rep(i,0,n) cin>>a[i];
    ll r=-1, l=0, c=0;
    while(r<n){
        if(c == k) {
            p[a[l]] -= 1;
            if(p[a[l]] == 0) c-=1;
            l += 1;
        }
        else{
            r += 1;
            if(r == n) continue;
            p[a[r]] += 1;
            if(p[a[r]] == 1) c+=1;
        }
        if(c < k)
        if((r-l+1) > ans)
        ans = r-l+1;
    }
    cout<<ans<<endl;
}   

int main(){
    fastio;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}
