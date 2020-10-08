/*
算法描述:
工具：vector()函数，sort()函数
1. 需要新数组new_arr存储新区间；
2. 将数组按升序排序：{{0，3}，{0，1}，{0，2}，{2，5}，{1，9}，{10，11}，{12，19}}
3. if 右边界R（arr[i][1]）< 左边界L（arr[i][0]）,说明不重合（{0，3}，{10，11}）。 将当前数组置入new_arr（使用new_arr.back())
  else 比较右边界R并取最大值更新。max({0,3},{2,5})
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& arr); //函数声明
int main()
{
  vector<vector<int>> verise
  {
    {2,6},
    {1,3},
    {15,18},
    {8,10}
};
  vector<vector<int>> new_arr = merge(verise);//合并区间函数
  for(int i=0;i<new_arr.size();i++)
  {
      for(int j=0;j<new_arr[i].size();i++)
      {
          cout<<new_arr[i][j]<<",";
      }
      cout<<endl;
  }
  return 0;
}
//合并区间
vector<vector<int>> merge(vector<vector<int>>& arr)
{
    if(arr.size()==0)
    {
        return {};
    }
    sort(arr.begin(),arr.end());
    vector<vector<int>> merged;//定义新数组
    for(int i=0;i<merged.size();++i)
    {
       int L=arr[i][0],R=arr[i][1];//初始化 左边界和有边界
       if(!merged.size()||arr.back()[1]<L)
       {
          merged.push_back({L,R});//不重合。补充进新数组；
       }
       else
       {
          merged.back()[1] = max(merged.back()[1],R);
          //比较并返回最大右边界R；
       }
     }
     return merged;
 }
