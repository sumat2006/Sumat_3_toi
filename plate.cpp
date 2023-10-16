#include<iostream>
using namespace std;

int main(){

    bool exit = false;
    int nc, ns;
    cin >> nc >> ns;

    int c[ns], s[ns];
    for(int i=0; i<ns; i++){
        cin >> c[i] >> s[i];
    }

    //กำหนดค่าคิว นับคิว id ที่ออกจากแถว และจำนวนที่ออกจะแถว
    int q[ns][2], countQ = -1, temp[ns], countTemp = 0;

    //exit = true เลิกทำงาน
    while(exit == false){
        //รับคำสั่ง
        char command[2];
        cin >> command;

        if(command[0] == 'E'){
            //รับ id
            int id, room;
            cin >> id;

            //หาว่า id นี้อยู่น้องไหน
            for(int i=0; i<ns; i++){
                if(id == s[i]) room = c[i];
            }

            //หากยังไม่มีใครต่อคิวให้เพิ่มเลย
            if(countQ == -1){
                q[countQ+1][0] = room;
                q[countQ+1][1] = id;
            }
            else{
                //เช็คว่าอยู่ห้องเดียวกันไหม
                for(int i=countQ; i>=0; i--){

                    //ถ้าอยู่ห้องเดียวกัน ให้ย้ายคนที่อยู่ก่อนออกไป แล้วแทรกตัวเอง
                    if(q[i][0] == room){
                        for(int j=countQ; j>i; j--){
                            q[j+1][0] = q[j][0];
                            q[j+1][1] = q[j][1];
                        }
                        q[i+1][0] = room;
                        q[i+1][1] = id;

                        break;
                    }
                    //ถ้าไม่มีใครอยู่ห้องเดียวกัน ไปต่อหลังแถว
                    else if(q[i][0] != room && i == 0){
                        q[countQ+1][0] = room;
                        q[countQ+1][1] = id;
                    }
                }
            }

            countQ++;
        }
        else if(command[0] == 'D'){

            //เก็บค่าคนที่ออกจากแถว
            temp[countTemp] = q[0][1];
            countTemp++;

            //ให้คนต่อไปขึ้นมา
            for(int i=0; i<countQ; i++){
                q[i][0] = q[i+1][0];
                q[i][1] = q[i+1][1];
            }

            countQ--;
        }
        else if(command[0] == 'X'){
            exit = true;
        }
    }

    for(int i=0; i<countTemp; i++){
        cout << temp[i] << endl;
    }
    cout << "0";

    return 0;
}
/*
2 6
1 41
1 42
1 43
2 201
2 202
2 203
E 41
E 201
D
E 202
E 42
E 43
D
E 203
D
D
D
X
*/
