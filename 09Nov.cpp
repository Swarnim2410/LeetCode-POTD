class Solution
{
public:
    int mod = 1e9 + 7;
    int countHomogenous(string s)
    {
        long long n = s.length();
        long long i = 1;
        int cnt = 1;
        char ch = s[0];
        long long ans = 0;
        while (i < n)
        {
            if (s[i] == ch)
            {
                cnt++;
            }
            else
            {
                long long x = cnt;
                long long y = (cnt + 1) % mod;
                long long z = (x * y) % mod;
                long long f = z / 2;
                ans = (ans + f) % mod;
                cnt = 1;
                ch = s[i];
            }
            i++;
        }
        if (cnt)
        {
            // ans = (ans + (((cnt*(cnt+1))%mod)/2)%mod)%mod;
            long long x = cnt % mod;
            long long y = (cnt + 1) % mod;
            long long z = (x * y) % mod;
            long long f = z / 2;
            ans = (ans + f) % mod;
        }
        return (int)ans;
    }
};