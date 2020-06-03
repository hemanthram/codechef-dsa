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
const ll MAXN=1000000;
ll n;

vector <ll> prime;
void primes() {
	bool all[MAXN]={false};
    ll j;
	rep(i,2,MAXN) {
		if( all[i] ) continue; 
        prime.push_back(i);
		j = i*i;
		while(j <= MAXN) {
			all[j] = true;
			j += i;
		}
	} 
} 

void solve(){
    cin>>n;
    vec a;
    ll q = n/3, r = n%3;
    rep(i,0,q-1) { a.pb(10); a.pb(6); a.pb(15); }
    if(r == 0) { a.pb(10); a.pb(6); a.pb(15); }
    if(r == 1) { a.pb(10); a.pb(6); a.pb(21); a.pb(35); }
    if(r == 2) { a.pb(10); a.pb(6); a.pb(33); a.pb(77); a.pb(35); }
    rep(i,0,n) { cout<<a[i]*prime[i+6]<<' '; }
    cout<<endl;
}   

int main(){
    fastio;
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	#endif
	primes();
    ll t=1;
    cin>>t;
    while(t--)
    solve();
    return 0;
}
