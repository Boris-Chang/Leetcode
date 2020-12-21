/*题目描述：回文数
判断一个数字正序和倒序是不是相同
例如：
121的倒叙还是121
-121的倒叙和原数字并不相同
最终返回并输出true 或者 false
*/
#include<iostream>
using namespace std;

bool isPalindrome(int num_);
int main()
{
    int num_ = 121;
    int result_ = isPalindrome(num_);
    cout<<result_<<endl;

    return 0;
}
/*
如果一个数的长度为奇数，将该数一分为二，后半部分和前半部分相同，则该数是回文数。
比如：121；
1. a = 121&10 , revers_ = revers_*10+a(int revers=0)
2. b = 121/10 , a = b%10
3. if b <= revers , 那么已经处理了半位数的数字了
注意：
如果一个数大于0 并且 末尾为0 ，则这样的数一定不是回文数
如果一个数为负数，也一定不是回文数 
*/
bool isPalindrome(int num_)
{
    if(num_<0 || (num_%10==0 && num_!=0))
   {
       return false;
   }
   int revertedNumber = 0;
   while(num_>revertedNumber){
       revertedNumber = revertedNumber * 10 + num_ % 10;
       num_/=10;
   }
   return num_==revertedNumber || num_ == revertedNumber/10;
}       
