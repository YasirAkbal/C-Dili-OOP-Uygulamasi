/**
*
* @author Ahmet Yasir Akbal/ahmet.akbal@ogr.sakarya.edu.tr 
* @since 12.04.2018
* <p>
* Test Programýnýn olduðu kaynak dosyasý
* </p>
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IMEINO.h"
#include "KISI.H"
#include "RASTGELEKISI.h"
#include "IMEINO.h"
#include "KIMLIKNO.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void tcIMEIKontrol(int*, int*, int*); 
void tcIMEIBul(char[], char[], char[]);
void parantezSil(char*,char[]);
void sifirla(int*, int*, int*);

int main(int argc, char *argv[]) {
	
	srand(time(NULL)); //rand fonksiyonunu beslemek için
	RastgeleKisi rstKisi = rastgeleKisiYapici(); 
	short secim = 0;
	short olusacakKisiSayisi;
	short i;
	int sayac = 0;
	Kisi kisi;
	int gecerliTC = 0;
	int gecerliIMEI = 0;
	int toplamKisiSayisi = 0;
	
	while(secim != 3) //seçim 3 deðilse
	{		
		printf("1- Rastgele Kisi Uret\n2- Uretilmis Dosya Kontrol Et\n3- Cikis\n");
		scanf("%d",&secim);
		
		switch(secim)
		{
			case 1: //Kisileri olustur ve dosyaya yaz
				printf("Olusturalacak kisi sayisini giriniz: ");
				scanf("%d",&olusacakKisiSayisi);
				for(i=0;i<olusacakKisiSayisi;i++)
				{
					kisi = kisiOlustur(rstKisi);
					kisi->kisiYoket(kisi);
				}
				break;
			case 2: //Oluþturulan kiþilerin imei ve tcsini kontrol eden fonksiyonun çaðrýsý
				tcIMEIKontrol(&gecerliTC, &gecerliIMEI, &toplamKisiSayisi);
				break;
			case 3:
				break;
			default:
				printf("Yanlis secim\n");
		}
	}
		
	return 0;
}

void tcIMEIKontrol(int* gTC, int* gIMEI, int* toplam) //Oluþturulan kiþilerin imei ve tcsini kontrol eden fonksiyon
{
	FILE *fp = fopen("doc\\Kisiler.txt", "r"); //dosya aç okuma modunda
	char tc[11];
	char imei[15];
	char satir[200] = {0};
	int i = 0;
	
	if(!fp) //dosya açýlamamýþsa hata mesajý ver
		printf("Dosya acma hatasi\n");
	
	else //dosya açýldýysa bu iþlemleri yap
	{
		while (fgets(satir,200,fp) != NULL)
		{	
			tcIMEIBul(satir, tc, imei);
			
			if(_tcNoKontrol(tc)) //tc doðruysa
				(*gTC)++;
					
			if(_imeiNoKontrol(imei)) //imei doðruysa
				(*gIMEI)++;
				
			(*toplam)++; //toplam kiþisi sayýsýný say					
		}
		fclose(fp); //dosyayý kapat
	}
	printf("T.C. Kimlik Kontrol\n%d Gecerli\n%d Gecersiz\n",*gTC,*toplam - *gTC); //ekrana yazma iþlemleri
	printf("IMEI Kontrol\n%d Gecerli\n%d Gecersiz\n",*gIMEI,*toplam - *gIMEI);
	
	sifirla(gTC, gIMEI, toplam); //gecerlitc, gecerliimei ve toplam kiþi sayýsýný sýfýrlayan fonkisoyonu çaðýr
}

void tcIMEIBul(char satir[], char tc[], char imei[]) //Kisiler.txtdeki satýrlardan tc ve imei deðerlerini bul
{	
	strcpy(tc, strtok(satir, " ")); //satiri bosluk ayracina gore ayýr
	
	int i;
	for(i=0;i<4;i++) //tcye ulasana kadar bol
		strtok(NULL, " ");
		
	parantezSil(strtok(NULL, " "),imei); //imeinin parantezlerini silmek için parametre olarak parantezSil fonksiyonuna gönder	
}

void parantezSil(char *parantezli,char imei[]) //imeinin yanýnda bulunan parantezleri sil
{
	int i;
	for(i=1;i<16;i++) //parantezleri sil
		imei[i-1] = parantezli[i];
}

void sifirla(int* gTC, int* gIMEI, int* toplam) //gecerlitc, gecerliimei ve toplam kiþi sayýsýný sýfýrlayan fonkisoyon
{
	*gTC = 0;
	*gIMEI = 0;
	*toplam = 0;
}

