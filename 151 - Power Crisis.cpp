/******************************************************************************
151 - Power Crisis
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=87
https://blog.csdn.net/u011500062/article/details/72855826

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
    	regions.clear(); // don't forget
    	
        // -1 mean first we don't count; 
        n=n-1;
        
        //build the list
        for(i = 0 ; i< n; i++)
            regions.push_back(i+1);
        
        // for(i = 0 ; i< n; i++)
        //     cout << regions[i] << " ";
        //cout << "\n";
      	
      	// it's passable that m is bigger than n. ex: 45 54
        for(m = 1 ; m<= 999; m++){ 
            int end = josphus( n , m); //return index
            if( regions[end] + 1  == 13){
                //cout << regions[end] + 1 << "\n";  // cout lest regions
                cout << m<< endl; // smallest m th 
                break;
            }
        }
        
    }
    
    return 0;
}
