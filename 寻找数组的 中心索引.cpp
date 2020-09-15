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