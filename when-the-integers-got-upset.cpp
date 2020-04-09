
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define gcd(a,b) __gcd(a,b)

const int mod = 1e9+7;

int n;

int arr[14],p[14];

ll dp[(1<<13)+10][14][14];

ll f(int mask,int prev1,int prev2){
	if(mask==(1<<(n+1))-2) return 0;
	if(dp[mask][prev1][prev2]!=-1) return dp[mask][prev1][prev2];
	ll ans = 1e9+7;

	for(int i=1;i<=n;i++){
		if(prev1==0 || prev2==0){
			ans = min(ans ,f(mask|(1<<i),i,prev1));
		}
		if(!(mask&(1<<i))){
			ans = min(ans,(arr[i]^arr[prev1]^arr[prev2])*p[__builtin_popcount(mask)] + f(mask|(1<<i),i,prev1));
		}
	}
	return dp[mask][prev1][prev2]=ans;
}


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		std::map<int,int> m;
		for (int i = 1; i <=n ; ++i)
		{
			cin>>arr[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin>>p[i];
		}
		memset(dp,-1,sizeof(dp));
		cout<<f(0,0,0)<<"\n";
	}

	return 0;
}
