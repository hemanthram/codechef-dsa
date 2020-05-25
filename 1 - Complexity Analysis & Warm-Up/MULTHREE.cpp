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

ll power(ll x, ll y, ll p){ 
    ll res = 1;
    x = x % p; 
    while (y > 0) { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p;   
    } 
    return res; 
}

void solve(){
    ll k,d0,d1,x,quo,rem;
    cin>>k>>d0>>d1;
    x = (d0+d1);
    if(k == 2){
        if(x % 3 == 0) print("YES");
        else print("NO");
        return;
    }
    if(k == 3){
        if((x + (x%10))%3 == 0) print("YES");
        else print("NO");
        return;
    }
    k -= 3;
    vec p(1,0);
    ll s = x + (x%10);
    p.pb((2*x)%10);
    p.pb((4*x)%10);
    p.pb((8*x)%10);
    p.pb((16*x)%10);
    quo = k/4;
    rem = k%4;
    s += (quo*(p[1]+p[2]+p[3]+p[4]));
    rep(i,1,rem+1) s += p[i];
    if(s % 3 == 0) print("YES");
    else print("NO");
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
