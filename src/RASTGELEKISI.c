/**
*
* @author Ahmet Yasir Akbal/ahmet.akbal@ogr.sakarya.edu.tr
* @since 12.04.2018
* <p>
* Test Programýnýn olduðu kaynak dosyasý
* </p>
*/
#include "RASTGELEKISI.h"

void _ayir(char isimler[3000][2][50], RastgeleKisi rstKisi) //random_isimler.txt dosyasýný okuyan ve içindekileri kaydeden fonksiyon
{
	
	FILE *fp = fopen("C:\\Users\\Ýlhan Akbal\\Desktop\\random_isimler.txt", "r"); //dosya aç okuma modunda
	char ad[30]; //adý tutmak için
	char soyad[30]; //soyadý tutmak için
	int i = 0; //indis sayacý
	
	if(!fp) //dosya açýlmamýþsa hata mesajý yaz
		printf("Dosya acma hatasi\n");
	
	else //dosya açýldýysa iþlemleri yap
	{
		while (!feof(fp)) //dosyanýn sonuna gelinmediði sürece dön
		{	
			fscanf(fp, "%s %s", ad, soyad); //dosyayý boþluk ayracýna göre oku ve ad,soyad karakter dizilerine ata
			strcpy(isimler[i][0],ad); //atama iþlemi
			strcpy(isimler[i][1],soyad); //atama iþlemi
			i++;
		}
		fclose(fp); //dosyayý kapat
	}

}

void _dosyaYaz(const Kisi kisi)
{
	FILE *fp = fopen("doc\\Kisiler.txt", "a"); //dosya aç append modunda
	
	if(!fp)//dosya açýlmamýþsa hata mesajý yaz
		printf("Dosya acma hatasi\n");
	
	else//dosya açýldýysa iþlemleri yap
	{
		fprintf(fp, "%s %s %s %d %s %c%s%c%c", kisi->kimlikNo->tcNoDondur(kisi->kimlikNo), kisi->adDondur(kisi), kisi->soyadDondur(kisi), kisi->yasDondur(kisi), 
			kisi->telefon->telNoDondur(kisi->telefon),'(', kisi->telefon->imei->imeiNoDondur(kisi->telefon->imei), ')','\n'); //kisinin tüm özellikler Kisiler.txt dosyasýna yaz
		fclose(fp); //dosyayý kaapt
	}
}

void _rndDegerAta(Kisi kisi, RastgeleKisi rstKisi) //rastgele deðer atýyan fonksiyon
{	
	int rnd = rand() % 3000; //isimler içinden rastgele birini seçmek için

	kisi->adAta(kisi, rstKisi->isimler[rnd][0]); //random ad ata
	kisi->soyadAta(kisi, rstKisi->isimler[rnd][1]); //random soyad ata
	kisi->yasAta(kisi, rand() % 100); //random yas ata
	kisi->kimlikNo->tcNoUret(kisi->kimlikNo); //random tcno oluþtur ve ata
	kisi->telefon->telNoUret(kisi->telefon); //random telno oluþtur ve ata
	kisi->telefon->imei->imeiNoUret(kisi->telefon->imei); //random imeino oluþtur ve ata
}

RastgeleKisi rastgeleKisiYapici()
{	
	RastgeleKisi rstKisi; //Bir RastgeleKisi tipinden iþaretci tanýmla
	rstKisi = (RastgeleKisi)malloc(sizeof(struct RASTGELEKISI)); //RastgeleKisi için bellekte yer ayýr
	rstKisi->ayir = _ayir; //NDP benzetmesi için fonksiyon göstericisine fonksiyonun adresini ata
	rstKisi->rndDegerAta = &_rndDegerAta; //NDP benzetmesi için fonksiyon göstericisine fonksiyonun adresini ata
	rstKisi->rastgeleKisiYikici = &_rastgeleKisiYikici; //NDP benzetmesi için fonksiyon göstericisine fonksiyonun adresini ata
	rstKisi->dosyaYaz = &_dosyaYaz; //NDP benzetmesi için fonksiyon göstericisine fonksiyonun adresini ata
	rstKisi->ayir(rstKisi->isimler, rstKisi); //Ýsim ve soyisimleri okuyup ayýran fonksiyonu çaðýr

	return rstKisi; //rstKisiyi döndür
}

void _rastgeleKisiYikici(RastgeleKisi rstKisi) //Yokedici fonksiyon
{	
	if(rstKisi == NULL) return; //zaten yokedilmesi için gönderilen yapý NULL ise hiçbir þey yapmadan fonksiyondan çýk
	free(rstKisi); //rstKisi serbest býrak
	rstKisi = NULL; //rstKisiye NULL ata
}


