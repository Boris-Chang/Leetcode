/*
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

示例 1:

输入: "III"
输出: 3
示例 2:

输入: "IV"
输出: 4
示例 3:

输入: "IX"
输出: 9
示例 4:

输入: "LVIII"
输出: 58
解释: L = 50, V= 5, III = 3.

*/
/*
注：不要被罗马数字干扰，其实就是处理一个简单的数组，如果左边的数比右边的小，做减法。否则做加法。
这里所考察的一部分是如何利用数据结构hashmap存储字符和数字。
*/
#include<iostream>
#include<string>
using namespace std;

int getChar(char ch);
void test();
int main()
{
    test();
    
    return 0;
}
void test()
{
    string str_ = "XXIV";
    int sum_=0;
    
    for(int i=0;i<str_.size();i++)
    {
        int preNum = getChar(str_[i]);
        int num_=getChar(str_[i+1]);
        if(preNum<num_)
        {
            sum_ -= preNum;
        }
        else
        {
            sum_ += preNum;
        }
    }
    cout<<sum_<<endl;
}
int getChar(char ch)
{
    switch(ch)
    {
        case 'I': 
            return 1;
            break;
        case 'V': 
            return 5;
            break;
        case 'X': 
            return 10;
            break;
        case 'L': 
            return 50;
            break;
        case 'C': 
            return 100;
            break;        
        case 'D': 
            return 500;
            break;
        case 'M': 
            return 1000;
            break;
        default: 
            return 0;
            break;
    }
}
