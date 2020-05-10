/*************************************************************************
* CHRISTOPHER SNELL <cpsnell@gmail.com>
* Program Name: Infinite Integer (Beginning of a Type)
* Program Type: Beta
* Problem: Currently basic types suffer from a maximum limit
*          and this does not need to be so...
* May 2020:
* The following implementation supports addition for an infinite integer
* Even with this implementation certain items of interest can be done.
*************************************************************************/
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct longNumber
{
    vector<int> myNum;
    vector<int> result;
    
    longNumber(string setNumber)
    {
        for(char c : setNumber)
        {
            myNum.push_back(int(c) - int('0'));
        }
    }
    
    void displayNumber()
    {
        for(int a : myNum)
        {
            cout << a;
        }
        cout << endl;
    }
    
    void add(longNumber input)
    {
        reverse(input.myNum.begin(), input.myNum.end());
        reverse(myNum.begin(), myNum.end());
        
        int carry = 0;
        bool carrytrue = false;
        
        vector<int>::iterator it = input.myNum.begin();
        vector<int>::iterator mt = myNum.begin();
        
        for(; it!=input.myNum.end() && mt!=myNum.end(); it++, mt++)
        {
            int value = *it + *mt + carry;
            if(value >= 10)
            {
                carrytrue = true;
                value = value - 10;
            }
            else
            {
                carrytrue = false;
            }
            result.push_back(value + carry);
            
            if(carrytrue == true)
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }
        }
        for(;it!=input.myNum.end(); it++)
        {
            result.push_back(*it + carry);
            carry = 0;
        }
        
        for(;mt!=myNum.end(); mt++)
        {
            result.push_back(*mt + carry);
            carry = 0;
        }
        
        reverse(result.begin(), result.end());
        myNum.swap(result);
        result.clear();
        
    }
    
};

int main()
{
    longNumber result("0");
    longNumber addend1("1111111111111122222333333333333333444444444444444555555555556666666");
    longNumber addend2("22222");
    
    result.add(addend1);
    result.add(addend2);
    result.displayNumber();
    
    return 0;
}
