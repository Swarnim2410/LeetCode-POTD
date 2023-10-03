class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) 
    {
        // int cnt = 0;
        // for(int i=0;i<nums.size();i++)
        // {
        //     for(int j=i+1;j<nums.size();j++)
        //     {
        //         if(nums[i]==nums[j])
        //         {
        //             cnt++;
        //         }
        //     }
        // }    
        // return cnt;

        int n = nums.size();
        int cnt=0;
        vector<int>hash(101,0);
        for(int i=0;i<n;i++)
        {
            hash[nums[i]]++;
        }
        for(int i=0;i<=100;i++)
        {
            int x = hash[i];
            cnt += (x*(x-1)/2);
        }
        return cnt;
    }
};