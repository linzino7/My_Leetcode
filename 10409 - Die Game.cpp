# include <iostream> 
# include <string>

using namespace std;

int main(){
	int n;
	
	while(cin >> n && n != 0){
		string cmd;
		//          top0 ,north1 ,west2,east3, south4 , bottom5 
		int die[6]={1,2,3,4,5,6};
		int  tmp ;
		for(int i =0 ; i< n ; i++){
			cin >> cmd; 
			if (cmd =="north"){
				tmp = die[1];
				die[1] = die[0];
				die[0] = die[4];
				die[4] = die[5];
				die[5] = tmp;
			}else if (cmd == "east"){
				tmp = die[3];
				die[3] = die[0];
				die[0] = die[2];
				die[2] = die[5];
				die[5] = tmp;
			}else if (cmd == "south"){
				tmp = die[4];
				die[4] = die[0];
				die[0] = die[1];
				die[1] = die[5];
				die[5] = tmp;
				
			}else if (cmd == "west"){
				tmp = die[2];
				die[2] = die[0];
				die[0] = die[3];
				die[3] = die[5];
				die[5] = tmp;
				
			}
		}
		cout << die[0]<< "\n";
	}
	
}
