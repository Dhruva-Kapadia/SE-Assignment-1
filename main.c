#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int toInt(char d){
    if(d == '1')
        return 1;
    else
        return 0;
}

int main()
{
    int cost = 0;
    int lane[MAX];
    char setup[MAX];
    printf("Input state of each slot (5 slots):\n");
    gets(setup);

    for(int i = 0; i < MAX; i++)
        lane[i] = toInt(setup[i]);

    int pos;
    printf("Enter Position to start at (1 to 5):\n");
    scanf("%d", &pos);
    pos = pos-1;

    int leftmost = 0;
    while((lane[leftmost] != 1) && (leftmost < pos))
        leftmost++;

    int rightmost = MAX - 1;
    while((lane[rightmost] != 1) && (rightmost > pos))
        rightmost--;


    if((leftmost == pos) && (rightmost == pos)){
        if(lane[pos] == 1){
            cost++;
            lane[pos] = 0;
        }
    }
    else
    if(rightmost == pos){
        while(pos >= leftmost){
            if(lane[pos] == 1){
                cost++;
                lane[pos] = 0;
            }
            pos--;
            cost++;
        }
    }
    else
    if(leftmost == pos){
        while(pos <= rightmost){
            if(lane[pos] == 1){
                cost++;
                lane[pos] = 0;
            }
            pos++;
            cost++;
        }
    }
    else
    if((pos - leftmost) < (rightmost - pos)){
        while(pos > leftmost){
            if(lane[pos] == 1){
                cost++;
                lane[pos] = 0;
            }
            pos--;
            cost++;
        }
        while(pos <= rightmost){
            if(lane[pos] == 1){
                cost++;
                lane[pos] = 0;
            }
            pos++;
            cost++;
        }
    }

    else{
        while(pos < rightmost){
            if(lane[pos] == 1){
                cost++;
                lane[pos] = 0;
            }
            pos++;
            cost++;
        }
        while(pos >= leftmost){
            if(lane[pos] == 1){
                cost++;
                lane[pos] = 0;
            }
            pos--;
            cost++;
        }
    }
    printf("\nAll Tickets Issued! Cost = %d", cost);
    return 0;
}
