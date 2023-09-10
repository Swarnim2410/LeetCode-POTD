class Solution {
public:
    long long mod = (long long)1e9+7;
    int countOrders(int n) 
    {
        long long prev = 1;
        long long prevresult = 1;
        long long curr = 1;
        if(n==1)
        {
            return 1;
        }    
        else
        {
            for(int i=0;i<n-1;i++)
            {
                curr = (curr + 4)%mod;
                long long newvar = (curr + prev)%mod;
                prev = newvar;
                long long newres = (newvar * prevresult)%mod;
                prevresult = newres;
            }
        }
        return (prevresult)%mod;
    }
};