/*
算法：
{1,2,3},
{4,5,6},
{7,8,9}

根据 7=>1([2][0]=>[0][0]) , 1=>3([0][0]=>[0][2])
总结出：new_martirx[col][size-i-1] = matrix[i][col];
*/

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> turnR(vector<vector<int>>& matrix);
int main()
{
    vector<vector<int>> arr
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    auto new_arr = turnR(arr);

    for (int i = 0; i < new_arr.size(); i++)
    {
        for (int j = 0; j < new_arr[i].size(); j++)
        {
            cout << new_arr[i][j] << ",";
        }
        cout << endl;
    }
}
vector<vector<int>> turnR(vector<vector<int>>& matrix)
{
    int n = matrix.size();
    vector<vector<int>> new_matrix = matrix;
    //N*N矩阵
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            new_matrix[j][n - i - 1] = matrix[i][j];
        }
    }
    matrix = new_matrix;
    return matrix;
}


