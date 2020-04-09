
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define gcd(a,b) __gcd(a,b)


const int mod = 1e9+7;

pii arr[22],arr1[22];
ll dp[1<<20][21];
int n;


ll dist(int idx1,int idx2){
	return abs(arr[idx1].first-arr1[idx2].first)+abs(arr[idx1].second-arr1[idx2].second);
}

ll f(int i,int mask){
	if(i==n){
		if(mask==(1<<n)-1) return 0;
		return 9999999;
	}
	if(dp[mask][i]!=-1) return dp[mask][i];
	ll ans = 99999999999;
	for(int j=0;j<n;j++){
		if(!(mask&(1<<j))){
			ans = min(ans,dist(i,j)+f(i+1,mask|(1<<j)));
		}
	}
	return dp[mask][i]=ans;
}


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	memset(dp,-1,sizeof(dp));
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i].first>>arr[i].second;
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>arr1[i].first>>arr1[i].second;
	}
	cout<<f(0,0);
	return 0;
}
