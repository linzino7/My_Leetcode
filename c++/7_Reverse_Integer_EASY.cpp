/*
7. Reverse Integer [Easy]

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
Example 4:

Input: x = 0
Output: 0
 

Constraints:

-231 <= x <= 231 - 1

//C++
*/
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        printf("x = %d\n", x);
        
        int negtive = 1;
        string tmp ="";
        string ans = "";
        
        // inver string
        if(x== -2147483648){
            tmp = "2147483648";
        }else if ( x < 0 ){
            negtive =-1;
            x = x * -1;
            tmp = to_string(x);
            printf("inver = %d \n", x);
        }else{
             tmp = to_string(x);
        }
        

        
        if(tmp.length()>10){
            return 0;
        }
        
        printf("tmp = %s\n", tmp.c_str());
        
        for(int i=0; i < tmp.length();i++){
            ans = tmp[i] + ans;
        }
        printf("ans = %s\n", ans.c_str());
        printf("ng = %d\n", negtive);
        
        //bound1 = 2147483647.000000
        //bound2 = -2147483648.000000
        // check number string by string to avoid invert number is overflow when len is 10  .
        string cp = "2147483647";
        bool f = 0;
        if (ans.length()==10 ){
            for (int j =0; j<10;j++){
                if ( j==9 && negtive==1){
                    if((int)ans[j]>55){// ascii 7
                        f = 1;
                        printf("ERROR1!! %d\n", j);
                        break;
                    }
                }else if ( j==9 && negtive==-1){
                    if((int)ans[j]>56){// ascii 8
                        f = 1;
                        printf("ERROR2!! %d\n", j);
                        break;
                    }
                }else{
                    if((int)ans[j]>(int)cp[j]){
                        f = 1;
                        printf("ERROR3!! %d , ans= %d ,cp = %d\n", j,(int)ans[j],(int)cp[j]);
                        break;
                    }else if((int)ans[j]<(int)cp[j]){
                        f = 0;
                        break;
                    }
                }
            }
        }
        if( f==1){return 0;}
        
        
        int a = stoi(ans) * negtive;
        printf("a = %d\n", a);
        printf("======\n", a);
        return a;
    }
};