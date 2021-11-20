// 上傳時不要有中文  會錯誤 

#include <iostream> 

using namespace std;

int flog = 0 ;
int x = 0;

struct Node{ 
	int left;
	int right;
	int data;
};


void parse(Node* currnode, int sum, int LR){
	char c;
	int n;
	
	cin >> c ; // (
	cin >> n;
	
	if(!cin){ // if ) 清空 然後下一個cin 會再 讀一次。 
		cin.clear()	;
		// 要避免只有一個分支但是剛好加總是 要找的值 
		if(LR==1){
			currnode->left = 1; 
		}
		if(LR==2){
			currnode->right = 1; 
		}
		
		if(currnode->left == 1 && currnode->right == 1){ //如果遇到樹根確認一下 
			if ( sum == x  ){
				flog = 1;				
			}
		}
		
	}else{
		sum += n;
		currnode->data = n;
	
		Node* n = new Node();
		parse(n, sum,1); //1 =left
		parse(n, sum,2); //2 =right
		
	}
	
	cin >>c ; // )  
}

int main(){
	
	while(cin >> x){
		
		flog = 0 ;
		Node* root = new Node();
		parse(root, 0, 0);
		
		if(flog){
			cout << "yes" << endl;
		}else{
			cout << "no" << endl;
		}
	}
	
	return 0;
}
