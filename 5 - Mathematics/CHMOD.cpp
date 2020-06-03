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
const int MAXN = 100002, MAXA = 101;
int n,a[MAXN],p[MAXA][MAXN],t,m,l,r;
long long ans;
vector <int> prime;

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

void primes() {
	int all[MAXA];
	rep(i,0,MAXA) all[i] = 0;
	rep(i,2,MAXA) {
		if(!all[i] ) prime.push_back(i);
		int j = 2*i;
		while(j <= MAXA) {
			all[j] = 1;
			j += i;
		}
	} 
} 

void solve(){
    scanf("%d", &n);
	rep(i,0,n) scanf("%d", &a[i]);
	rep(i,0,MAXA) p[i][0] = 0;
	rep(i,0,n) {
		for(auto j:prime) {
			if(a[i] % j == 0) {
				int h = j, c=0;
				while(a[i] % h == 0){
					c += 1;
					h *= j;
				}
				p[j][i+1] = p[j][i]+c;
			}
			else p[j][i+1] = p[j][i];
		}
	}	
	scanf("%d", &t);
	rep(_,0,t){
	    scanf("%d %d %d",&l,&r,&m);
		ans = 1;
		for(auto i:prime) {
			ans = ans * (power(i, p[i][r]-p[i][l-1], m)) ;
			ans %= m;
		}
		printf("%ld\n", ans);
	}

}   

int main(){
    fastio;
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	#endif
	primes();
    ll t=1;
    // cin>>t;
    while(t--)
    solve();
    return 0;
}
