/*
思路：
   [1,1,1]    [1,0,1]    [1,0,1]
   [1,0,1] => [0,0,1] => [0,0,0]
   [1,1,1]    [1,1,1]    [1,0,1]
示例2：
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
输出：
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
*/

#include<iostream>
#include<vector>
using namespace std;


vector<vector<int>> Zero_matrix(vector<vector<int>>& matrix);
int main()
{
    vector<vector<int>> arr{
    {1,1,1},
    {1,0,1},
    {1,1,1}
    };
    vector<vector<int>> new_arr = Zero_matrix(arr);
    for (int i = 0; i < new_arr.size(); i++)
    {
        for (int j = 0; j < new_arr[i].size(); j++)
        {
            cout << new_arr[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
vector<vector<int>> Zero_matrix(vector<vector<int>>& matrix)
{
    bool isFirstColZero = false;
    bool isFirstRowZero = false;

    for (int i = 0; i < matrix.size(); i++)
    {
        if (matrix[i][0] == 0)
        {
            isFirstColZero = true;
        }
    }
    for (int j = 0; j < matrix[0].size(); j++)
    {
        if (matrix[0][j] == 0)
        {
            isFirstRowZero = true;
        }
    }
   
    for (int i = 1; i < matrix.size(); i++)
        for (int j = 1; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }

    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 1; j < matrix[i].size(); j++)
        {
            if (matrix[0][j] == 0 || matrix[i][0] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        if (isFirstColZero)
        {
            matrix[i][0] = 0;
        }
    }
    for (int j = 0; j < matrix[0].size(); j++)
    {
        if (isFirstRowZero)
        {
            matrix[0][j] = 0;
        }
    }

  

    return matrix;
}
