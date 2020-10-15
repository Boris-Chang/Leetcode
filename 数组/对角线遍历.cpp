/*
示例:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

输出:  [1,2,4,7,5,3,6,8,9]
*/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
   vector<vector<int>> nums
   {
     {1,2,3},
     {4,5,6},
     {7,8,9}
   }
   auto new_nums = diagonal(nums);
   for(int i=0;i<new_nums.size();i++)
   {
       cout<<new_nums[i]<<",";
   }
   return 0;
}
vector<vector<int>> diagonal(vector<vector<int>>& matrix)
{
    vector<int> arr;
    int m=matirx.size();
    if(m==0) return matrix;
    int n=matrix[0].size();
    if(n==0) return matrix;
    
    bool flag = true; //记录对角线起始点位置
    for(int i=0;i<m+n;i++)
    {
       int pm = (flag)?m:n;
       int pn = (flag)?n:m;
       
       int x=(i<pm)?i:pm-1; //x始终取大值
       int y=i-x; //y取小值
       
       while(x>=0 && y<n)
       {
          arr.push_back(flag?matrix[x][y]:matrix[y][x])； //当横坐标为x时：大->小 ，为y时：小->大；
          x--;
          y++;
       }
       
       flag=!flag;//对角线循环；
     }
     return arr;
}
