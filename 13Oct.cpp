class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();
        cost.push_back(0);
        int prev2 = cost[0];
        int prev = cost[1];
        for(int i=2;i<n+1;i++)
        {
            int curr = min(prev2,prev) + cost[i];
            prev2 = prev;
            prev = curr;
        }  
        return prev;
    }
};