/**
*
* @author Ahmet Yasir Akbal/ahmet.akbal@ogr.sakarya.edu.tr
* @since 12.04.2018
* <p>
* Test Programýnýn olduðu kaynak dosyasý
* </p>
*/

#include "IMEINO.h"

void _imeiNoUret(const IMEINo pIMEINo)
{
	short toplam = 0;
	short temp;
	short indis = 0;

	int i;
	for (i = 1; i<15; i++) //Ýlk 14 basamaðý oluþtur
	{
		temp = rand() % 10;
		pIMEINo->imeiNo[indis++] = '0' + temp;
		if (i % 2 == 1)//Eðer soldan tek basamak ise rakamý 2 ile çarp ve basamak deðerlerini topla
		{
			toplam += (temp * 2) % 10 + (temp * 2) / 10;
		}
		else //Soldan çift basamak ise direkt rakamý topla
		{
			toplam += temp;
		}
	}

	if (toplam % 10 != 0)//toplamýn son hanesi 0 deðilse, toplandýðýnda onu kendisinden büyük en küçük 10 ile tam bölünen sayý yapan sayýyý bul
		pIMEINo->imeiNo[indis++] = '0' + (10 - toplam % 10);
	else //toplamýn son hanesi 0 ise IMEI'nin 15.hanesini 0 yap
		pIMEINo->imeiNo[indis++] = '0' + 0;
	
	pIMEINo->imeiNo[indis] = '\0'; //diziyi mühürle
}

char * _imeiNoDondur(const IMEINo pIMEINo)
{
	return pIMEINo->imeiNo;
}

int _imeiNoKontrol(const char * imeiNo)
{
	short toplam = 0; //IMEI'deki rakamlarýn toplamýný tutan deðiþken
	short temp; //Rakamlarý tutan geçici deðiþken
	short indis = 0;
	int i;
	for (i = 1; i<15; i++) //Ýlk 14 basamaða kadar oku ve toplam deðiþkenlerine bazý eklemeler yap
	{
		temp = imeiNo[indis++] - '0';
		if (i % 2 == 1) //Eðer okunan basamak soldan tek haneli ise, o basamaktaki rakamý 2 ile çarpýp çýkan sayýnýn rakamlarýný topla
			toplam += (temp * 2) % 10 + (temp * 2) / 10;
		else//Eðer okunan basamak soldan çift haneli ise direkt rakamlarý topla
			toplam += temp;
	}

	if (toplam % 10 != 0) //toplam deðiþkeni 10a tam bölünmüyorsa ona eklendiðinde 10 tam bölünebilecek sayýyý bul ve tempe ata
		temp = (10 - toplam % 10);
	else //toplam deðiþkeni 10a tam bölünüyorsa tempi 0 yap
		temp = 0;

	//temp, IMEInin 15.basamaðýna eþitse true deðilse false döndür
	return (temp == imeiNo[indis] - '0');
}

IMEINo imeiNesneOlustur(Telefon telefon) //Yapýcý fonksiyon
{	
	telefon->imei = (IMEINo)malloc(sizeof(struct IMEINO)); //imei için bellekte yer ayýr
	telefon->imei->imeiNoUret = &_imeiNoUret; //NDP benzetmesi için fonksiyon göstericisine fonksiyonun adresini ata
	telefon->imei->imeiNoKontrol = &_imeiNoKontrol; //NDP benzetmesi için fonksiyon göstericisine fonksiyonun adresini ata
	telefon->imei->imeiNoDondur = &_imeiNoDondur; //NDP benzetmesi için fonksiyon göstericisine fonksiyonun adresini ata
	telefon->imei->imeiYoket = &_imeiYoket; //NDP benzetmesi için fonksiyon göstericisine fonksiyonun adresini ata
	telefon->imei->imeiNo = (char*)malloc(sizeof(char) * 16); //imei no için bellekten yer iste.

	return telefon->imei; //telefon yapýsýnýn elemaný olan ve olusturulan imei yapýsýný geri dondur
}

void _imeiYoket(IMEINo pImei) //Yokedici fonksiyon
{
	if (pImei == NULL) return; //zaten yokedilmesi için gönderilen yapý NULL ise hiçbir þey yapmadan fonksiyondan çýk
	
	free(pImei->imeiNo); //imeino yapýsýnda bulunan imei karakter dizisini serbest býrak
	free(pImei); //pImeiyi serbest býrak
	pImei = NULL; //pImeiyi null yap
}

