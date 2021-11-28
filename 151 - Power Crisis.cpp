/******************************************************************************

151 - Power Crisis
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=87

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
    // -1 mean first we don't count; 
    int n;  
    vector<int> regions;
    int i;
    
    while(cin>>n && n!=0){
        
        for(i = 0 ; i< n; i++)
            regions.push_back(i+1);
        
        // for(i = 0 ; i< n; i++)
        //     cout << regions[i] << " ";
        //cout << "\n";
        
        for(i = 1 ; i<= n; i++){
            int end = josphus( n , i); //return index
            if( regions[end] + 1  == 13){
                cout << regions[end] + 1 << "\n";
                break;
            }
        }
        
        
    }
    
    return 0;
}
