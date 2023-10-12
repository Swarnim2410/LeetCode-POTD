/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int n = mountainArr.length();
        int ans = 0;
        int s = 0;
        int e = n - 1;
        int m = s + (e - s) / 2;
        int largest = 0;
        while (s < e)
        {
            if (mountainArr.get(m + 1) > mountainArr.get(m))
            {
                s = m + 1;
            }
            else
            {
                e = m;
            }
            m = s + (e - s) / 2;
        }
        largest = s;
        s = 0;
        e = largest;
        m = s + (e - s) / 2;
        while (s <= e)
        {
            if (target == mountainArr.get(m))
            {
                ans = 1;
                return m;
            }
            else if (target > mountainArr.get(m))
            {
                s = m + 1;
            }
            else
            {
                e = m - 1;
            }
            m = s + (e - s) / 2;
        }
        s = largest + 1;
        e = n - 1;
        m = s + (e - s) / 2;
        while (s <= e)
        {
            if (target == mountainArr.get(m))
            {
                ans = 1;
                return m;
            }
            else if (target < mountainArr.get(m))
            {
                s = m + 1;
            }
            else
            {
                e = m - 1;
            }
            m = s + (e - s) / 2;
        }
        return -1;
    }
};