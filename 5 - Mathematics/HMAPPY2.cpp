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

ll gcd(ll a, ll b) {
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
} 

void solve(){
    ll n,a,b,k;
    cin>>n>>a>>b>>k;
    ll g = (a*b)/gcd(a,b); 
    if((n/a+n/b-2*(n/g)) >= k) cout<<"Win"<<endl;
    else cout<<"Lose"<<endl; 
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

