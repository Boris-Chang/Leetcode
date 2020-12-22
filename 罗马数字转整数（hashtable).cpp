#include<iostream>
#include<string>
#include<map>
using namespace std;

void test();
int solution_(string str_);
int main()
{
    test();
    return 0;
}
void test()
{
    string str_="XXIV";
    int result_ = solution_(str_);
    cout<<result_<<endl;
}
int solution_(string str_)
{
    int result_ = 0;
    map<char,int> Roma_to_numberMap=
    {
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}
    };
    for(int i=0;i<str_.size();i++)
    {
        if(Roma_to_numberMap[str_[i]]<Roma_to_numberMap[str_[i+1]])
        {
            result_ -= Roma_to_numberMap[str_[i]];
        }
        else
        {
            result_ += Roma_to_numberMap[str_[i]];
        }
    }
    return result_;
}
