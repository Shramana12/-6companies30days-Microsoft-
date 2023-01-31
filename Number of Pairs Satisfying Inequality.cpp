#include<bits/stdc++.h>
#define ll long long int
class Solution {
    ll solve(vector<int> &d, ll l, ll r, ll diff){
        if(l == r) return 0;

        ll mid = l + (r-l)/2;
        ll res = solve(d, l, mid, diff) + solve(d, mid+1, r, diff);

        vector<ll> merged;

        for(int j = mid+1; j <= r; j++){
            ll x = d[j] + diff;

            int ind = upper_bound(d.begin()+l, d.begin()+mid+1, x) - d.begin() - 1;
            if(ind <= mid) res += (ind - l + 1);
        }
        int i = l, j = mid+1;
        while(i <= mid && j <= r){
            if(d[i] <= d[j])
                merged.push_back(d[i++]);
            else merged.push_back(d[j++]);
        }
        while(i <= mid) merged.push_back(d[i++]);
        while(j <= r) merged.push_back(d[j++]);
        i = 0;
        while(l <= r){
            d[l++] = merged[i++];
        }

        return res;
    }
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<int> d(n);

        for(int i = 0; i < n; i++)
            d[i] = nums1[i]-nums2[i];
        
        return solve(d, 0, n-1, diff);
    }
};