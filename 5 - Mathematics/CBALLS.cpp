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
const int MAXN = 10001;
int n,a[MAXN],b[MAXN],ans,d,q,pq,fin;
vector <int> prime;

void primes() {
	int all[MAXN];
	rep(i,0,MAXN) all[i] = 0;
	rep(i,2,MAXN) {
		if(!all[i] ) prime.push_back(i);
		int j = 2*i;
		while(j <= MAXN) {
			all[j] = 1;
			j += i;
		}
	} 
} 

void solve(){
    cin>>n;
	rep(i,0,n) cin>>a[i];
    fin = INT_MAX;
    for(auto d : prime) {
        pq = 1; ans = 0;
        rep(i,0,n) {
            q = a[i]/d;
            if(a[i] % d != 0) ++q; 
            pq = max(q,pq);
            ans += (pq*d - a[i]);
        }
        fin = min(fin,ans);
    }
    cout<<fin<<endl;
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
