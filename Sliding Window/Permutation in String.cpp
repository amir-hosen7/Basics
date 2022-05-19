#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define Mid(b,e) b+(e-b)/2
#define inf 1e18
double PI=2*acos(0.0);

//---------------------------------------------------------------------------//
//Timus: 314795JS
//knight moves
// ll X[8] = {2, 1, -1, -2, -2, -1, 1, 2};
// ll Y[8] = {1, 2, 2, 1, -1, -2, -2, -1};
// ll dx[]={1,-1,0,0};
// ll dy[]={0,0,1,-1};
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
//typedef tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>pbds;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>pbds; 
//typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update>pbds; 

//------------------------------------------------------------------------------//


const ll p=29;
const ll N=2e6+50;
const ll mod=1e9+7;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1=s1.size(),len2=s2.size();
        vector<int>cnt(26,0),currCnt(26,0);
        for(int i=0; i<len1; i++){
        	cnt[s1[i]-'a']++;
        }
        int L=0,ok;
        for(int i=0; i<len2; i++){
        	currCnt[s2[i]-'a']++;
        	ok=1;
        	for(int j=0; j<26; j++){
        		if(cnt[j]!=currCnt[j]){
        			ok=0; break;
        		}
        	}
        	if(ok==1){break;}
        	while(currCnt[s2[i]-'a']>cnt[s2[i]-'a']){
        		currCnt[s2[L]-'a']--; L++;
        	}
        }
        return ok;
    }
};

int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	for(ll T=1; T<=t; T++){
		string s1,s2;
		cin>>s1>>s2;
		Solution obj;
		yesNo(obj.checkInclusion(s1,s2));
	}
	return 0;
}



