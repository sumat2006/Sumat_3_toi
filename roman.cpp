#include<iostream>
using namespace std;

int main(){

    int n, I=0, V=0, X=0, L=0, C=0;
    //กำหนดตวอักษรโรมันเป็นหลักหน่อย สิบ และร้อย
    char nx[11][5] = {" ", "i", "ii", "iii", "iv", "v", "vi", "vii", "viii", "ix"};
    char nxx[11][5] = {" ", "x", "xx", "xxx", "xl", "l", "lx", "lxx", "lxxx", "xc"};
    char nxxx[5][5] = {" ", "c", "cc", "ccc"};

    cin >> n;

    //หาเลขหลักหน่วยทั้งหมด
    for(int i=1; i<=n; i++){
        int keep = i%10;

        for(int j=0; j<5; j++){
            if(nx[keep][j] == 'i') ++I;
            if(nx[keep][j] == 'v') ++V;
            if(nx[keep][j] == 'x') ++X;
        }
    }

    //หาเลขหลักสิบทั้งหมด
    for(int i=1; i<=n; i++){
        int keep = (i/10)%10;

        for(int j=0; j<5; j++){
            if(nxx[keep][j] == 'x') ++X;
            if(nxx[keep][j] == 'l') ++L;
            if(nxx[keep][j] == 'c') ++C;
        }
    }

    //หาเลขหลักร้อยทั้งหมด
    for(int i=1; i<=n; i++){
        int keep = (i/100)%10;

        for(int j=0; j<5; j++){
            if(nxxx[keep][j] == 'x') ++X;
            if(nxxx[keep][j] == 'l') ++L;
            if(nxxx[keep][j] == 'c') ++C;
        }
    }

    cout << I << " " << V << " " << X << " " << L << " " << C;
}
