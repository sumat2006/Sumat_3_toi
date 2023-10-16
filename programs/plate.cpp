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

    //Configure the queue, count the queue id that leaves a row, and the number of queues that leave a row
    int q[ns][2], countQ = -1, temp[ns], countTemp = 0;

    //exit = true quit working
    while(exit == false){
        //Take command
        char command[2];
        cin >> command;

        if(command[0] == 'E'){
            //get id
            int id, room;
            cin >> id;

            //Find out where this ID is
            for(int i=0; i<ns; i++){
                if(id == s[i]) room = c[i];
            }

            //If there is still no one in line, add them
            if(countQ == -1){
                q[countQ+1][0] = room;
                q[countQ+1][1] = id;
            }
            else{
                //Check to see if you are in the same room
                for(int i=countQ; i>=0; i--){

                    //If in the same room Move the person who was there first out. then insert yourself
                    if(q[i][0] == room){
                        for(int j=countQ; j>i; j--){
                            q[j+1][0] = q[j][0];
                            q[j+1][1] = q[j][1];
                        }
                        q[i+1][0] = room;
                        q[i+1][1] = id;

                        break;
                    }
                    //If no one is in the same room, go to the back of the line
                    else if(q[i][0] != room && i == 0){
                        q[countQ+1][0] = room;
                        q[countQ+1][1] = id;
                    }
                }
            }

            countQ++;
        }
        else if(command[0] == 'D'){

            //Collect fees for people who leave the line
            temp[countTemp] = q[0][1];
            countTemp++;

            //Let the next person come up
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
