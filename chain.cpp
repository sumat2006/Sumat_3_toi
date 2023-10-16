#include<iostream>
#include<string.h>
using namespace std;

int main(){

    int l, n;
    bool chain = false;
    cin >> l >> n;

    //สร้าง text[l+1], text_temp[l+1] (เพื่อใช้เปรียบเทียบ)
    char text[l+1], text_temp[l+1];

    for(int i=0; i<n; i++){
        cin >> text;

        //หาก i = 0 ให้ก็อป text ใส่ใน text_temp
        if(i == 0) strcpy(text_temp, text);
        //หาก chain = false หรือโซ่คำยังไม่ขาด
        else if(chain == false){
            int like = 0;

            //เปรียบเทียบว่าอักษรเหมือนกันไหม
            for(int j=0; j<l; j++){
                if(text[j] == text_temp[j]) like++;
            }

            //หากอักษรน้อกว่า l-2 ให้โซ่คำขาด chain = true
            if(like < l-2) chain = true;
            //หากไม่ใช่ให้ text ใส่ใน text_temp
            else strcpy(text_temp, text);
        }
    }

    cout << text_temp;

    return 0;
}
/*
4
12
HEAD
HEAP
LEAP
TEAR
REAR
BAER
BAET
BEEP
JEEP
JOIP
JEIP
AEIO
*/
