
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define gcd(a,b) __gcd(a,b)


const int mod = 1e9+7;

int n,arr[51];
std::map<int, int>h;
int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

int factor[51];

int dp[1<<16][51];

int f(int mask,int i){
	if(i==n){
		return 0;
	}
	if(dp[mask][i]!=-1) return dp[mask][i];
	int ans = 0;
	if(arr[i]==1){
		ans = max(ans,1+f(mask,i+1));
	}
	if(!(mask&factor[i])){
		ans = max(ans,1+f(mask|factor[i],i+1));
		ans = max(ans,f(mask,i+1));
	}
	ans = max(ans,f(mask,i+1));
	return dp[mask][i]=ans;

}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m = sizeof(primes)/sizeof(int);
	//cout<<m<<endl;
	for (int i = 0; i < m; ++i)
	{
		h[primes[i]] = i;
	}
	int t;
	cin>>t;
	while(t--){
		memset(dp,-1,sizeof(dp));
		cin>>n;
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
			int x = arr[i];
			int val = 0;
			for(int j = 2;j*j<=x;j++){
				if(x%j==0){
					while(x%j==0){
						x/=j;
					}
					val |= (1<<h[j]);
				}
			}
			if(x>1) val |= (1<<h[x]);

			factor[i] = val;
		}
		cout<<f(0,0)<<"\n";
	}
	return 0;
}
