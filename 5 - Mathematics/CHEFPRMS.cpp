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
const int MAXN = 201;

vec prime;
void primes() {
	bool all[MAXN]={false};
    long long j;
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

bool check[201] ={false};
void solve(){
    ll n;
    cin>>n;
    rep(i,2,n) 
    if(check[i] && check[n-i]){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}   

int main(){
    fastio;
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	#endif

    primes();
    int l = prime.size();
    rep(i,0,l)
    rep(j,i+1,l)
    if(prime[i]*prime[j] <= 200)
    check[prime[i]*prime[j]] = true;

    ll t=1;
    cin>>t;
    while(t--)
    solve();
    return 0;
}
