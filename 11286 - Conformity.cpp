// https://www.pinghenotes.com/UVa-11286-Conformity/

#include <iostream> 
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	
	int n;
	vector<string> combination;
	string tmp;
	map <string,int> cls_cnt;
	
	cin >> n;
	while(n!=0){
		cls_cnt.clear();
		
		while(n>0){
			combination.clear();
			tmp.clear();
			
			// put class to vector
			for(int i=0 ; i<5;i++){
				cin >> tmp;
				combination.push_back(tmp);
			}
			
			// sort class to avoid same class in different class
			sort(combination.begin(), combination.end());
			
			tmp.clear();
			
			// combin class to string
			for(int i=0; i<5;i++){
				tmp  = tmp+ combination[i];
			}
			
			//cout << tmp;
			
			if(cls_cnt.find(tmp)!=cls_cnt.end() ){
				// if found
				cls_cnt[tmp] += 1;
			}else{
				cls_cnt[tmp] = 1;
			}
			
			n--;
		}
		
		int max_num = 0 ;
		int total = 0 ;
		map <string,int>::iterator it;
		
		for(it= cls_cnt.begin(); it!= cls_cnt.end(); it++)
			if (it->second > max_num){ max_num = it->second;}
		
		for(it = cls_cnt.begin(); it!=cls_cnt.end();it++)
			if(it->second == max_num){total+=max_num;}
			
		cout << total << "\n";

		cin >> n;
	}	
}
