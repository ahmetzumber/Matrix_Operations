/*
* matrixOps.c
* matrixOps kutuphanesindeki fonksiyonlarin implementasyonunun oldugu dosya
* Proje 1
* 1 Aralik 2019
* Ahmet Zumberoglu , ahmet.zumberoglu@stu.fsm.edu.tr
*/
#include "matrixOps.h"
#include <time.h>
#include <stdlib.h>

int **randomMatrixOlustur(int satirSayisi,int sutunSayisi,int randomNumberRange){
    
    int **dizi = (int**)calloc(sizeof(int),satirSayisi);        /* Iki boyutlu arrayde bir elemaninin da bir boyutu oldugu icin
                                                                 onun da adresini aliyoruz */
    srand((unsigned int)time(NULL));
    // Random diziyi yazdirma
    int i, j;
    for (i = 0; i < satirSayisi; i++){
          // iki boyutlu dizi icin yer ayirma
        for (j = 0; j < sutunSayisi; j++){  
			*(dizi+i) = (int*)calloc(sizeof(int),sutunSayisi);  
        }
    }
    
    for (i = 0; i < satirSayisi; i++){
        for (j = 0; j < sutunSayisi; j++){  
            *(*(dizi+i) + j) = rand() % randomNumberRange;
        }
    }
    
    return dizi;
}


void randomMatrixYazdir(int satirSayisi, int sutunSayisi, int **matrix){
    
    int i, j;
    for (i = 0; i < satirSayisi; i++) {
        for (j = 0; j < sutunSayisi; j++) {
            printf("%d\t",*(*(matrix + i)+ j));
        }
        printf("\n");
    }

}

void matrixDondur(int **matrix, int satirSayisi, int sutunSayisi, int direction){
    
    if (direction == 1) saatYonundeDondur(satirSayisi, sutunSayisi, matrix);
    if (direction == -1) saatYonuTersineDondur(satirSayisi, sutunSayisi, matrix);
    
}

void saatYonuTersineDondur(int satirSayisi, int sutunSayisi, int **matrix){
    
    
    int simdikiSayi = 0,sonrakiSayi = 0;    // Adim adim ilerletirken kullanilan degiskenler
    int x,y,z,t;                            // Dongu iteratorleri
    
    
    // Ilk satiri, ilk sutundan son sutuna kadar bir adim ilerletme
    for (t = 0; t < sutunSayisi-1; t++) {
    	simdikiSayi = *(*(matrix+0) + t);
        sonrakiSayi = *(*(matrix+0) + (t+1));
        *(*(matrix+0) + (t+1)) = simdikiSayi;
        *(*(matrix+0) + t) = sonrakiSayi;
    }
    
    // Birinci satir son sutunu bir adim ilerletme
    for (x = 0; x < satirSayisi-1; x++) {
        simdikiSayi = *(*(matrix+x) + (sutunSayisi-1));
        sonrakiSayi = *(*(matrix+(x+1)) + (sutunSayisi-1));
        *(*(matrix+(x+1)) + (sutunSayisi-1)) = simdikiSayi;
        *(*(matrix+x) + (sutunSayisi-1)) = sonrakiSayi;
    }
    
    // Son satiri sondan sutundan ilk sutuna dogru ilerletme
    for (y = sutunSayisi-1; y > 0; y--) {
    	simdikiSayi = *(*(matrix+(satirSayisi-1)) + y);
        sonrakiSayi = *(*(matrix+(satirSayisi-1)) + (y-1));
        *(*(matrix+(satirSayisi-1)) + (y-1)) = simdikiSayi;
        *(*(matrix+(satirSayisi-1)) + y) = sonrakiSayi;
    }
    
    // Ilk sutunu son satirdan yukari dogru bir adim ilerletme
    for (z = satirSayisi-1; z > 1; z--) {
    	simdikiSayi = *(*(matrix+z) + 0);
        sonrakiSayi = *(*(matrix+(z-1)) + 0);
        *(*(matrix+(z-1)) + 0) = simdikiSayi;
        *(*(matrix+z) + 0) = sonrakiSayi;
    }
}

void saatYonundeDondur(int satirSayisi, int sutunSayisi, int **matrix){
    
    
    int simdikiSayi = 0,sonrakiSayi = 0;
    int x,y,z,t;
    
    // Ilk satir ilk sutunu asagi dogru bir adim ilerletme
    for (x = 0; x < satirSayisi-1; x++) {
   		 simdikiSayi = *(*(matrix+x) + 0);
  		 sonrakiSayi = *(*(matrix + (x+1))+0);
   		 *(*(matrix + (x+1)) + 0) = simdikiSayi;
   		 *(*(matrix+x) + 0) = sonrakiSayi;
    }
        
    // Son satiri ilk sutundan son sutuna bir adim ilerletme
    for (y = 0; y < sutunSayisi-1; y++) {
   		 simdikiSayi =  *(*(matrix+(satirSayisi-1)) + y);
  		 sonrakiSayi = *(*(matrix+(satirSayisi-1)) + (y+1));
  		 *(*(matrix+(satirSayisi-1)) + (y+1)) = simdikiSayi;
   		 *(*(matrix+(satirSayisi-1)) + y) = sonrakiSayi;
    }
        
    // Son satir son sutunu yukari dogru bir adim ilerletme
    for (z = satirSayisi-1; z > 0; z--) {
	 	simdikiSayi = *(*(matrix + z) + (sutunSayisi-1));
        sonrakiSayi = *(*(matrix+(z-1)) + (sutunSayisi-1));
        *(*(matrix+(z-1)) + (sutunSayisi-1)) = simdikiSayi;
        *(*(matrix + z) + (sutunSayisi-1)) = sonrakiSayi;
    }  
        
    // ilk satiri, son sutundan ilk sutuna dogru bir adim ilerletme
    for (t = sutunSayisi-1; t > 1; t--) {
  	    simdikiSayi = *(*(matrix+0) + t);
        sonrakiSayi = *(*(matrix+0) + (t-1));
        *(*(matrix+0) + (t-1)) = simdikiSayi;
         *(*(matrix+0) + t) = sonrakiSayi;
    }
}
    
int isDigit(char *str){
    
    int length = 0;
    while (*(str + length) != '\0') {
        length++;
    }

    
    int i, control = 1;
    for (i = 0; i < length; i++) {
        if (!(*(str+i) >= 48 && *(str+i) <= 57)) {
            control = 0;
        }
    }
    return control;
}
