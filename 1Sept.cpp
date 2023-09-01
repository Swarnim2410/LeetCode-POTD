class Solution {
public:

    int func(int i)
    {
        if(i==0)
        {
            return 0;
        }
        if(i==1)
        {
            return 1;
        }
        if(i%2==0)
        {
            return func(i/2);
        }
        return 1+func(i/2);
    }
    vector<int> countBits(int n) 
    {
        vector<int>ans(n+1);
        for(int i=0;i<=n;i++)
        {
            ans[i] = func(i);
        }   
        return ans; 
    }
};