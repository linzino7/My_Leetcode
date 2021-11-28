/******************************************************************************

151 - Power Crisis
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=87

*******************************************************************************/
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

// n is how many regions , poeples in josphus problem 
// m is  which counted number have to been killed.
int josphus(int n, int m){
    if(n ==1){
        return 0;
    }else{
        return (josphus(n-1,m)+m) % n ;
    }
}

int main()
{   
    
    int n;  
    vector<int> regions;
    int i,m;
    
    while(cin>>n && n!=0){
        
        // -1 mean first we don't count; 
        n=n-1;
        
        //build the list
        for(i = 0 ; i< n; i++)
            regions.push_back(i+1);
        
        // for(i = 0 ; i< n; i++)
        //     cout << regions[i] << " ";
        //cout << "\n";
        
        for(m = 1 ; m<= n; m++){
            int end = josphus( n , m); //return index
            if( regions[end] + 1  == 13){
                //cout << regions[end] + 1 << "\n";  // cout lest regions
                cout << m; // smallest m th 
                break;
            }
        }
        
        
    }
    
    return 0;
}


