
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define gcd(a,b) __gcd(a,b)


const int mod = 1e9+7;

int primes[] = {2,3,5,7};
int n;
int arr[100005];
ll arr1[100005];
ll dp[100005][4][1<<5];

//std::map<ll,ll>h;

ll f(int i,int cnt,int mask){
	if(i==n){
		return cnt==3;
	}
	if(cnt==3) return 1;
	if(dp[i][cnt][mask]!=-1) return dp[i][cnt][mask];
	ll ans = 0;
	if(mask&arr[i]){
		ans += f(i+1,cnt+1,mask&arr[i]);
		ans += f(i+1,cnt,mask);
	}
	else ans += f(i+1,cnt,mask);
	return dp[i][cnt][mask]=ans;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	ll d;
	map<int,int>m;
	m[2] = 0;
	m[3] = 1;
	m[5] = 2;
	m[7] = 3;
	int idx=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>d;
		//h[d]+=1;
		//if(h[d]>1) continue;
		//arr1[idx] = d;
		int val = 0;
		while(d){
			int y = d%10;
			d /= 10;
			if(m.count(y)) val |= (1<<m[y]);
		} 
		arr[i] = val;
		//idx++;
	}
	memset(dp,-1,sizeof(dp));
	//n = idx;
	//cout<<n<<endl;
	cout<<f(0,0,(1<<4)-1);
	
	//cout<<ans;
	return 0;
}
