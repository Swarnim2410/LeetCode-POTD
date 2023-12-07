class Solution
{
public:
    int numberOfMatches(int n)
    {
        int ans = 0;
        if (n == 1)
        {
            return 0;
        }
        while (n != 2)
        {
            if (n % 2)
            {
                ans += (n / 2);
                n = n / 2 + 1;
            }
            else
            {
                ans += (n / 2);
                n = n / 2;
            }
        }
        ans += 1;
        return ans;
    }
};