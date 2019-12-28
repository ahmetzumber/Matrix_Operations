/*
* main.c
* Programin menusu ve kontrollerin yapildigi yer
* Proje 1
* 1 Aralik 2019
* Ahmet Zumberoglu , ahmet.zumberoglu@stu.fsm.edu.tr
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrixOps.h"

int main(int argc, const char * argv[]) {
    
    int islemNo = 1;
    int satirSayisi = 0, sutunSayisi = 0, direction = 0, rastgeleSayiAraligi = 0, adimSayisi = 0;
    
    // Her bir parametreye string girdisini kontrol etmek icin 
    char satirKontrol[15];
    char sutunKontrol[15];
    char randomSayiKontrol[15];
    char directionKontrol[15];
    char adimSayisiKontrol[15];
    char islemNoKontrol[15];
    
    satirSayisi = atoi(*(argv + 1));
    sutunSayisi = atoi(*(argv + 2));
    direction = atoi(*(argv + 3));
    rastgeleSayiAraligi = atoi(*(argv + 4));
    adimSayisi = atoi(*(argv + 5));
    
    int **matrix ; 
    matrix = randomMatrixOlustur(satirSayisi, sutunSayisi, rastgeleSayiAraligi);;
    
    while (islemNo > 0 && islemNo != 5) {

        // ISLEM NO 1 GIRILDIGINDE
        if (islemNo == 1) {
            
            randomMatrixYazdir(satirSayisi, sutunSayisi, matrix);
            int i;
            for (i = 0; i < adimSayisi; i++) {
                matrixDondur(matrix, satirSayisi, sutunSayisi, direction);
            }
            printf("------------------------------\n");
            randomMatrixYazdir(satirSayisi, sutunSayisi, matrix);
        }

        // ISLEM NO 2 GIRILDIGINDE
        if(islemNo == 2){
            int control = 1;
            
            while (control == 1) {
            	int satirCtrl = 1, sutunCtrl = 1, randomSayiCtrl = 1;
            	
            	while(satirCtrl == 1){
			    printf("Satir sayisi giriniz : ");
                scanf("%s",satirKontrol);
                if(isDigit(satirKontrol) == 1) {
					satirSayisi = atoi(satirKontrol);
					satirCtrl++;
				}
                else
                	printf("!! LUTFEN GECERLI BIR SATIR GIRINIZ !!\n");
                }
                
                while(sutunCtrl == 1){
                printf("Sutun sayisi giriniz : ");
                scanf("%s",sutunKontrol);
                if(isDigit(sutunKontrol) == 1){
					sutunSayisi = atoi(sutunKontrol);
					sutunCtrl++;
				}
                else 
                	printf("!! LUTFEN GECERLI BIR SUTUN GIRINIZ !!\n");
                }
                
                while(randomSayiCtrl == 1){
                printf("Rastgele sayi giriniz : ");
                scanf("%s",randomSayiKontrol);
                if(isDigit(randomSayiKontrol) == 1){ 
					rastgeleSayiAraligi = atoi(randomSayiKontrol);
					randomSayiCtrl++;
				}
                else
                	printf("!! LUTFEN GECERLI BIR SAYI GIRINIZ !!\n");
                }
                printf("----------------------------\n");
                
                if (!(satirSayisi < 0) && !(sutunSayisi < 0)) {  // Satir ve sutun sayisi negatif degilse islemleri yap, controlu arttir ve cik
                   if(!(satirSayisi < 2) && !(sutunSayisi < 2) && !(rastgeleSayiAraligi < 0)){
				    matrix = randomMatrixOlustur(satirSayisi, sutunSayisi, rastgeleSayiAraligi);
                    randomMatrixYazdir(satirSayisi, sutunSayisi, matrix);
                    control++;
                    }
                }else
                    printf("!! LUTFEN GECERLI BIR SATIR YA DA SUTUN SAYISI GIRINIZ !!\n");
            }
        }
        
        
        // ISLEM NO 3 GIRILDIGINDE
        if(islemNo == 3){
            int control = 1;
            while (control == 1) {
            	
                printf("Direction (Please enter 1 or -1) : ");
                scanf("%s",directionKontrol);
                direction = atoi(directionKontrol);   
                if ((direction == 1 || direction == -1) && isDigit(directionKontrol) == 1) {  // Direction -1 ya da 1 ise matrisi dondur, controlu arttir ve cik
					if(!(direction > 1) && !(direction < -2)){								  
				    	control++;
					}
                }
                else printf("!! LUTFEN GECERLI BIR YON GIRINIZ !!\n");
            }
        }
        
        
        // ISLEM NO 4 GIRILDIGINDE
        if(islemNo == 4){
            int control = 1;
            while(control == 1){
                printf("Adim sayisi giriniz : ");
                scanf("%s",adimSayisiKontrol);
                if (!(adimSayisi < 0)  && isDigit(adimSayisiKontrol) == 1) {    // Adim sayisi negatif degilse islemleri yap, controlu arttir ve cik
                    adimSayisi = atoi(adimSayisiKontrol);
					control++;
                }else printf("!! LUTFEN GECERLI BIR ADIM SAYISI GIRINIZ !!\n");
            }
        }
        
        
        // ISLEM NO 5 GIRILDIGINDE
        if(islemNo == 5){
            free(matrix);
            free(randomMatrixOlustur(satirSayisi, sutunSayisi, rastgeleSayiAraligi));
            printf("Cikis Yapiliyor...\n");
            break;
        }
        
        // ISLEM NO NEGATIF YA DA 5'TEN BUYUKSE
        if(islemNo < 0 || islemNo > 5){
            printf("\n------!! LUTFEN GECERLI BIR ISLEM NUMARASI GIRINIZ !!------ \n\n");
        }
   		
        printf("1. Uygulamayi calistir\n");
        printf("2. Matris olustur\n");
        printf("3. Direction (Please enter 1 or -1)\n");
        printf("4. Step number\n");
        printf("5. Exit\n\n");
        int control = 1;
        while(control == 1){
        	printf("Bir islem numarasi giriniz : ");
       		scanf("%s",islemNoKontrol);
        	if(isDigit(islemNoKontrol) == 1) {
        		islemNo = atoi(islemNoKontrol);
        		control++;
			}				
		}
        
        printf("\n");
    
    } // while

    
        return 0;
}
