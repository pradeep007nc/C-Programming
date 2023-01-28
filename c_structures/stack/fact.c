#include<stdio.h>

void towerOfHanoi(int disks, char fromRod, char tempRod, char toRod){
    if (disks == 1){
        printf("Move rod from %c rod to %c rod",fromRod, toRod);
        return;
    }
    towerOfHanoi(disks-1, fromRod, toRod, tempRod);
    printf("\nmove %d disks from %c rod to %c rod\n",disks, fromRod, toRod);
    towerOfHanoi(disks-1, tempRod, toRod, fromRod);
}

int main(){
    int disks = 3;
    char a,b,c;
    towerOfHanoi(disks, a, b, c);
    return 0;
}