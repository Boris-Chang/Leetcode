#include<iostream>
#include<vector>
using namespace std;

int searchInsert(vector<int>& nums, int poss);
int main()
{
    const int size = 5;
    int target;
    cin >> target;
    
    vector<int> arr{ 1,3,5,7,9 };
    
    int insert = searchInsert(arr, target);

    cout << insert << endl;
    return 0;
}
int searchInsert(vector<int>& nums, int poss)
{
    int n = nums.size();
    int ans = n;
    int right = n - 1;
    int left = 0;

    while (left <= right)
    {
        int mid = ((right - left) >> 1) + left;
        if (poss <= nums[mid])
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}
