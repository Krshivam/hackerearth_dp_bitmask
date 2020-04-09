
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
int val;

std::vector<int> v[22];
ll dp[1<<22];



ll f(int mask){   //will modify later 

	if(mask==(1<<(n+1))-2) {
		return 1;
	}
	if(dp[mask]!=-1) return dp[mask];
	ll ans = 0;
	int x;
	for(int i=1;i<=n;i++){
		if(!(mask&(1<<i))){
			bool ok = 1;
			for(int j=0;j<v[i].size();j++){
				int x = v[i][j];
				//cout<<x<<" ";
				//cout<<"ehjrew"<<endl;
				if(!(mask&(1<<x)))  ok = 0;
			}
			if(ok) ans += f(mask|(1<<i));
		}
	}
	return dp[mask]=ans;
}


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	//cout<<(1<<n)-1<<endl;
	memset(dp,-1,sizeof(dp));
	//val = (1<<n)-1;
	ll ans = 0;
	for(int i=1;i<=20;i++){
		for(int j=i-1;j>0;j--){
			if((i&j) == j) v[i].pb(j);
		}
	}
	
	ans = f(0);
	cout<<ans;
	return 0;
}
