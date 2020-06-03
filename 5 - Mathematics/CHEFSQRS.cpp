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

void solve(){
    ll n;
    cin>>n;
    if(n == 1 || n%4 == 2) {
        cout<<-1<<endl;
        return;
    }
    ll x = sqrt(n),q,p=-1;
    rep(i,1,x+1){
        if(n%i == 0){
            q = n/i;
            if((q-i)%2 == 0 and i != q) p = (q-i)/2;
        }
    }
    if(p == -1) cout<<-1<<endl;
    else cout<<p*p<<endl;
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
    return 0;
}
