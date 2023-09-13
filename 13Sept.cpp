class Solution {
public:
    int candy(vector<int>& r) 
    {
        int n = r.size();
        if(n==1)
        {
            return 1;
        }
        vector<int>ans(n,1);
        for(int i=1;i<n;i++)
        {
            if(r[i]>r[i-1])
            {
                ans[i] = ans[i-1] + 1;
            }
        }
        int cnt = 0;
        for(int i=n-2;i>=0;i--)
        {
            if(r[i]>r[i+1])
            {
                if(ans[i]<=ans[i+1])
                {
                    ans[i] = ans[i+1] + 1;
                }
            }
            cnt += ans[i];
        }  
        cnt += ans[n-1];
        return cnt;
    }
};