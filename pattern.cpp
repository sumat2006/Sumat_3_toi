#include<iostream>
using namespace std;

int main(){

    int n, max_line = 0;
    cin >> n;
    //สร้าง data[n][70]
    char data[n][70];

    //สร้างผ้าทั้งหมดให้ไม่มีลาย
    for(int i=0; i<n; i++){
        for(int j=0; j<70; j++){
            data[i][j] = 'o';
        }
    }

    //สร้างลายผ้า
    for(int i=0; i<n; i++){
        int p, q, r;
        cin >> p >> q >> r;

        for(int x=q-1; x<r+q-1; x++) if(x < 70) data[p-1][x] = 'x';

        if(max_line < p) max_line = p;
    }

    //พิมพ์ลายผ้า
    for(int i=0; i<max_line; i++){
        for(int j=0; j<70; j++){
            cout << data[i][j];
        }
        cout << endl;
    }

    return 0;
}
/*
4
1 1 10
2 3 9
3 5 25
2 20 2

*/

