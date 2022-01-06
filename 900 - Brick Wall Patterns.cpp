/******************************************************************************

https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=841

*******************************************************************************/

#include <iostream>

using namespace std;

long int f[50] = {0};

int main()
{
    f[1] = 1;
    f[2] = 2;
    
    for(int i =3; i<=50; i++){
        f[i] = f[i-1] + f[i-2];
    }
    
    int n;
    
    while(cin>>n && n!=0){
        cout << f[n] << "\n";
    }


    return 0;
}
