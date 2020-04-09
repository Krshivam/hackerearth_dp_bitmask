
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define gcd(a,b) __gcd(a,b)


const int mod = 1e9+7;

int l,n,m;

int arr[51];

ll dp[(1<<20)+5];

ll power(ll x,int y){
	ll ans = 1;
	for(int i=0;i<y;i++) ans*=x;
	return ans;
}


int f1(int x){
	int cnt = 0;
	while(x){
		cnt += (x&1);
		x>>=1;
	}
	return cnt;
}

ll f(int mask){
	if(mask==(1<<n)-1) return 0;
	if(dp[mask]!=-1) return dp[mask];
	ll ans = 9999999999999;

	for(int i=0;i<l;i++){
		ll bit_count = f1(arr[i])-f1(arr[i]&mask);
		if(bit_count==0) continue;
		ans = min(ans , power(bit_count,m)+f(mask|(arr[i])));
	}

	return dp[mask]=ans;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>l>>n>>m;
	int d;
	int u;
	memset(arr,0,sizeof(0));
	memset(dp,-1,sizeof(dp));
	for (int i = 0; i < l; ++i)
	{
		cin>>d;
		for (int j = 0; j < d; ++j)
		{
			cin>>u;
			arr[i] = arr[i]|(1<<u);
		}
	}

	//sort(arr,arr+l,compare);
	cout<<f(0);
	return 0;
}
