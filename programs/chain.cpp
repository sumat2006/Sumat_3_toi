#include<iostream>
#include<string.h>
using namespace std;

int main(){

    int l, n;
    bool chain = false;
    cin >> l >> n;

    //Create text[l+1], text_temp[l+1] (for comparison)
    char text[l+1], text_temp[l+1];

    for(int i=0; i<n; i++){
        cin >> text;

        //If i = 0, copy text and put it in text_temp
        if(i == 0) strcpy(text_temp, text);
        //If chain = false or the word chain is not broken
        else if(chain == false){
            int like = 0;

            //Compare whether the letters are the same or not
            for(int j=0; j<l; j++){
                if(text[j] == text_temp[j]) like++;
            }

            //If the letters are less than l-2, give the ultimatum chain chain = true.
            if(like < l-2) chain = true;
            //If not, put text in text_temp
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
