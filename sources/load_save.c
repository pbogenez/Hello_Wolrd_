//
// Created by trist on 18/12/2018.
//

#include "../headers/load_save.h"

void save_game(FILE* fp, int stop)
{
    fprintf(fp, "%d", stop);
}

int return_save(int stop)
{
    char c;
    FILE* fp;
    fp =fopen("../texts/save.txt","r");
    c = getc(fp);
    switch (c)
    {
        case('1'):
            stop = 1;
            break;
        case('2'):
            stop = 2;
            break;
        case('3'):
            stop = 3;
            break;
        case('4'):
            stop = 4;
            break;
        case('5'):
            stop = 5;
            break;
        case('6'):
            stop = 6;
            break;
        default:
            break;
    }
    return stop;
}