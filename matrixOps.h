/*
* matrixOps.c
* matrixOps kutuphanesi, kullandigim fonksiyonlarin prototipleri
* Proje 1
* 1 Aralik 2019
* Ahmet Zumberoglu , ahmet.zumberoglu@stu.fsm.edu.tr
*/
#ifndef matrixOps_h
#define matrixOps_h

#include <stdio.h>
#endif /* matrixOps_h */


int **randomMatrixOlustur(int, int, int);
void randomMatrixYazdir(int, int, int**);
void matrixDondur(int**, int, int, int);
void saatYonundeDondur(int, int, int**);
void saatYonuTersineDondur(int, int, int**);
int isDigit(char*);
