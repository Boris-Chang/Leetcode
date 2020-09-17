/*头脑中的第一反应是：
1. 如何找到中心索引？
2. 怎么判断中心索引？

我们可以根据示例1找到具体的解决方案：
array[6] = {1,7,3,6,6,5};

思路：
目测array[3]==6是答案。通过求和的方式1+7+3=6+5得出；
但数组的特点是从array[0]的位置开始依次向右移动，我们很难直接得到6+5的值；

*那么用什么方法求和呢？
既然加法很难得出结果，那么用减法行不行？
试一试！
6+5 = total-1-7-3；

*所以也就可以做出判断（左==右）：
判断left ?= right 
if (1+7+3 == total-array[i]-6-5) return i; //i是当前索引
*/


#include<iostream>
using namespace std;

int pivotIndex(int Num[], int s);

int main()
{
    const int size = 6;
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int ans = pivotIndex(arr,size);
    cout << ans << endl;

    return 0;
}
int pivotIndex(int Num[],int s)
{
    int sumTotal = 0;
    int sumLeft = 0;

    for (int i = 0; i < s; i++)
    {
        sumTotal += Num[i];
    }

    for (int j = 0; j < s; j++)
    {
        if (sumLeft == sumTotal - Num[j] - sumLeft)
        {
            return j;
        }
        sumLeft += Num[j];
    }
    return -1;
}
