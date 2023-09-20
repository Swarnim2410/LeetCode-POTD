class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int n=nums.size();
        vector<int> pre(n,0);
        vector<int> suff(n,0);
        int sum=nums[0];
        pre[0]=sum;
        for(int i=1;i<n;i++)
        {
            sum+=nums[i];
            pre[i]=sum;
        }
        sum=nums[n-1];
        suff[n-1]=sum;
        for(int i=n-2;i>=0;i--)
        {
            sum+=nums[i];
            suff[i]=sum;
        }
        int ans=INT_MAX;
        if(suff[0]<x)
        {
            return -1;
        }
        if(suff[0]==x)
        {
            ans = n;
        }
        for(int i=0;i<n;i++)
        {
            if(pre[i]==x)
            {
                ans = min(ans,i+1);
                break;
            }
        }
        for(int i=n-1;i>=1;i--)
        {
            //cout << 3 << endl;
            if(suff[i]==x)
            {
                ans=min(ans,n-i);
                return ans;
            }
            int it1=lower_bound(pre.begin(), pre.end(),x-suff[i] )-pre.begin();
            int it2=upper_bound(pre.begin(), pre.end(), x-suff[i])-pre.begin();
            if(it1==it2)
            {
                if(it1==n)
                {
                    return -1;
                }
            }
            else
            {
                ans = min(ans,n-i+it2);
            }
        }
        if(ans==INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};