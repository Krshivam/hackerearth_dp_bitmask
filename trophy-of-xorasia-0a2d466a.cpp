
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define gcd(a,b) __gcd(a,b)


const int mod = 1e9+7;
ll dp[1<<20][20];

ll arr[21];
int n;

ll f(int mask,int i){
	if(i==n){
		if(mask==(1<<n)-1) return 0;
		return 99999999999999;
	}
	//cout<<mask<<endl;
	if(dp[mask][i]!=-1) return dp[mask][i];
	ll ans = 99999999999999;
	if(mask&(1<<i)) ans = min(ans,f(mask,i+1));
	for(int j=0;j<n;j++){
		if(!(mask&(1<<j)) && i!=j && !(mask&(1<<i))){
			ans = min(ans,(arr[i]^arr[j])+f(mask|(1<<j)|(1<<i),i+1));
		}
	}
	return dp[mask][i] = ans;
}

ll f1(int mask,int i){
	if(i==n){
		if(mask==(1<<n)-1) return 0;
		return -99999;
	}
	//cout<<mask<<endl;
	if(dp[mask][i]!=-1) return dp[mask][i];
	ll ans = 0;
	if(mask&(1<<i)) ans = max(ans,f1(mask,i+1));
	for(int j=0;j<n;j++){
		if(!(mask&(1<<j)) && i!=j && !(mask&(1<<i))){
			ans = max(ans,(arr[i]^arr[j])+f1(mask|(1<<j)|(1<<i),i+1));
		}
	}
	return dp[mask][i] = ans;
}



int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	memset(dp,-1,sizeof(dp));
	ll mn = f(0,0);
   memset(dp,-1,sizeof(dp));
	cout<<mn<<" "<<f1(0,0);
	return 0;
}
