#include<iostream>
using namespace std;

int main(){

    int n, m, a;
    cin >> n >> m;

    //Create a table and get values
    char data[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> data[i][j];
        }
    }

    //Get the value a m times
    for(int i=0; i<m; i++){
        cin >> a;

        for(int j=0; j<a; j++){
            //Set y_check = -1 as the starting point
            int y_check = -1;

            //Check if y_check is 'O' or '#'
            //If not, y_check-1 = '.' and y_check = '#'
            do{
                data[y_check-1][i] = '.';
                data[y_check][i] = '#';
                y_check++;
            }while(data[y_check][i] != 'O' && data[y_check][i] != '#' && y_check != n);
        }
    }

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
