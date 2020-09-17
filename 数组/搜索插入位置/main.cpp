/*
目标：
1.找到目标值返回其位置。
2.无目标值，顺序插入并返回插入位置。
思路：
1.根据关键字 [排序数组]，[顺序插入]，我们可以很容易想到使用 [二分查找]。
2.可以将目标1，2合并。不必分开判断。
问题：
1.如何找到中心位置？
2.条件：判断目标值与中心数值大小。
3.如何设定边界？
题解：
1.寻找中心点，使用二进制法。
2.if（目标值>=中心值） , 向中心位置右边再次二分查找（小于同理）
3.以下代码用的是（目标值<=中心值）。尝试大于的写法。
注意：
数组的[左],[右]边界移动
*/

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
        int mid = ((right - left) >> 1) + left; //寻找中心点（二进制法）
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
