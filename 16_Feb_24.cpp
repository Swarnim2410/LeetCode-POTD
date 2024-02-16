class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        int n = arr.size();
        map<int, int> mp;
        for (auto it : arr)
        {
            mp[it]++;
        }
        vector<int> v;
        for (auto it : mp)
        {
            v.push_back(it.second);
        }
        sort(v.begin(), v.end());
        int x = v.size();
        int i = 0;
        while (i < x)
        {
            if (k <= 0)
            {
                break;
            }
            if (v[i] <= k)
            {
                k -= v[i];
                i++;
            }
            else
            {
                break;
            }
        }
        return x - i;
    }
};