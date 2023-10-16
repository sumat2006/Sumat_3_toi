#include<iostream>
using namespace std;

int main(){

    int n, check[101];
    cin >> n;

    if(n < 6) cout << "no";
    //loop a, b, c และนำมาบวกันจนกว่าจะได้น้อยกว่าหรือเท่ากับ n แล้วให้ check[a+b+c] = 1
    else{
        for(int a=0; a<=n; a+=6){
            for(int b=0; b<=n; b+=9){
                for(int c=0; c<=n; c+=20){
                    if(a+b+c <= n) check[a+b+c] = 1;
                    else continue;
                }
            }
        }
    }

    //ถ้า check[i] = 1 ให้พิมพ์ i
    for(int i=1; i<=n; i++){
        if(check[i] == 1) cout << i << endl;
    }

    return 0;
}
/*

*/
