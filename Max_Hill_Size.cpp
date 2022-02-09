1. Best Approch 

ll maxHillSize(vector<ll> a, ll n)
{
        ll res = 0;
        for(int i=0; i<n; i++) {
            ll cnt = 1;
            for(int j=i-1; j>=0; j--) {
                if(a[j]<=a[j+1]) cnt++;
                else break;
            }
            for(int j=i+1; j<n; j++) {
                if(a[j]<=a[j-1]) cnt++;
                else break;
            }
            res = max(res,cnt);
        }
        return res;
}

input:
  9
  1 2 1 1 1 3 3 4 1
output:
  7
  
 -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 2. Cinkmos Approch
 
 ll solve()
{
        ll n = vin(), res = 0, cnt = 0, increasing = 0, decresing = 0;
        vector<ll> a;
        map<ll,ll> G;
 
        for(int i=0; i<n; i++) {
            ll x = vin();
            a.push_back(x);
        }
        a.push_back(0);
        vector<pair<ll,ll> > H;
        H.push_back({0,0});
        
        for(int i=0; i<n; i++) {
            if(a[i]!=a[i+1]) {
                H.push_back({a[i],G[a[i]]+1});
                G[a[i]] = 0;
            }
            else G[a[i]]++;
        }
        H.push_back({0,0});
        H.push_back({MOD,0});
 
        for(int i=0; i<H.size()-1; i++)
        {
            if(H[i].first<H[i+1].first) {
                if(!increasing) {
                    cnt += H[i].second;
                    res = max(res, cnt);
                    cnt = H[i].second;
                }
                else cnt += H[i].second;
                decresing = 0;
                increasing++;
            }
            if(H[i].first>H[i+1].first) {
                increasing = 0;
                decresing++;
                cnt += H[i].second;
            }
        }
        return res;
}
 
 input:
  9
  1 2 1 1 1 3 3 4 1
output:
  7
