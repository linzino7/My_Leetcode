#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;


//5
//-5
//2
//3
//0
//99
//0

// you can sort and matched then continue  to  speed up 
// https://blog.xuite.net/abcd6891/LJYprogramming/63940814-10125+-+Sumsets

int main(){
	int n;
	int bn;
	long tmp;
	vector<int> nums;
	long max_num ;
	
	while(cin >> n && n!=0){
		tmp = 0;
		nums.clear();
		max_num = -99999999;
		bn = n;
		
		while(n--){
			cin >> tmp;
			nums.push_back(tmp);
		}
		
		sort( nums.begin(),nums.end());
		
		tmp = 0;
		for(int i =0; i< nums.size();i++){
			for(int j =i+1; j< nums.size();j++){ // key set init number is prevous index.
				for(int k =j+1; k< nums.size();k++){
					// can't sum same number
					if(i!=j && j!=k && i!=k){
						tmp = nums[i]+nums[j]+nums[k];
						
						//cout << i << " "  << j << " " << k << " "<< tmp << " = "<<  nums[i]<<" "<<nums[j]<< " "<<nums[k]  << "\n";
						// sum can not is itself. ex n =4  v={3,-1,0,1}  -1 +0 +1 =0 [error]
						if(tmp > max_num && tmp!=nums[i] && tmp!=nums[j] && tmp!=nums[k]){
							// search nums	
								
							if ( binary_search(nums.begin(),nums.end(),tmp) ){
								max_num = tmp;
							}
							
						}
					}
				}
			}
		}
		
		if(max_num !=-99999999 && bn >3){
			cout << max_num << "\n" ;
			
		}else{
			cout<< "no solution\n";
		}
		
	}
	
}


