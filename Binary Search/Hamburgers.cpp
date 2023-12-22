#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define ll long long
 
string s;
ll rb, rs, rc, nb, ns, nc, pb, ps, pc, rubble;
 
bool check(ll mid)
{
    ll total=0;
    if(rb*mid > nb) 
      total+=(rb*mid-nb)*pb;
    if(rs*mid > ns) 
      total+=(rs*mid-ns)*ps;
    if(rc*mid > nc) 
      total+=(rc*mid-nc)*pc;
      
    return total<=rubble;
}
 
  int main()
  {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>s;
    cin>>nb>>ns>>nc>>pb>>ps>>pc>>rubble;
 
    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='B') rb++;
      else if(s[i]=='S') rs++;
      else rc++;
    }
 
    ll lo=0, hi=(ll)1e15, ans;
 
    while(lo<=hi)
    {
       ll mid= (lo+hi)/2ll;
       if(check(mid))
        {
            ans=mid;
            lo=mid+1;
        }
        else
          hi=mid-1;
    }
    cout<<ans;
    return 0;
  }
// Problem Link : https://codeforces.com/contest/371/problem/C
// My Solution : https://codeforces.com/contest/371/submission/238348106
