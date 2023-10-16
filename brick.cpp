#include<iostream>
using namespace std;

int main(){

    int n, m, a;
    cin >> n >> m;

    //สร้างตาราง และรับค่า
    char data[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> data[i][j];
        }
    }

    //ปริ้นเช็คตาราง
//    for(int i=0; i<n; i++){
//        for(int j=0; j<m; j++){
//            cout << data[i][j];
//        }
//        cout << endl;
//    }

    //รับค่า a จำนวน m ครั้ง
    for(int i=0; i<m; i++){
        cin >> a;

        for(int j=0; j<a; j++){
            //ตั้งให้ y_check = -1 เป็นจุดเริ่มต้น
            int y_check = -1;

            //เช็คว่า y_check ว่าเป็น 'O' หรือ  '#'  ไหม
            //ถ้าไม่เป็นให้ y_check-1 = '.' และ y_check = '#'
            do{
                data[y_check-1][i] = '.';
                data[y_check][i] = '#';
                y_check++;
            }while(data[y_check][i] != 'O' && data[y_check][i] != '#' && y_check != n);
        }
    }

    //แสดงข้อมูลส่งออก
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << data[i][j];
        }
        cout << endl;
    }

    return 0;
}
/*
8 5
.....
.....
.OO..
.....
.O...
...O.
.....
.....
1 1 3 2 0
*/
