class Solution
{
public:
    int totalMoney(int n)
    {
        int a = n / 7;
        int b = n % 7;
        int ans = 0;
        int f = 1;
        if (a == 0)
        {
            while (b)
            {
                ans += f;
                f++;
                b--;
            }
            return ans;
        }
        int c = 7;
        int d = 28;
        ans += (d * a);
        int g = a - 1;
        while (g--)
        {
            ans += c;
            c += 7;
        }
        int e = 1 + a;
        while (b)
        {
            ans += e;
            e++;
            b--;
        }
        return ans;
    }
};