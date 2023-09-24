class Solution {
public:
    double champagneTower(int p, int qr, int qg) 
    {
        vector<vector<double>>dp(qr+1,vector<double>(qr+1,0.0));
        dp[0][0] = (double)p/1.0;
        for(int i=0;i<qr;i++)
        {
            for(int j=0;j<=i;j++)
            {
                double x = (dp[i][j] - 1)/2.0;
                if(x>0)
                {
                    dp[i+1][j]+=x;
                    dp[i+1][j+1]+=x;
                }
            }
        }
        return min(1.0,dp[qr][qg]);
    }
};