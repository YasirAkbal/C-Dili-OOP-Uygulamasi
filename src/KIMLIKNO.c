/**
*
* @author Ahmet Yasir Akbal/ahmet.akbal@ogr.sakarya.edu.tr
* @since 12.04.2018
* <p>
* Test Programýnýn olduðu kaynak dosyasý
* </p>
*/
#include "IMEINO.h"
#include "KIMLIKNO.h"

void _tcNoUret(const KimlikNo kimlik)
{
	short tekler = 0; //Tc numarasýndaki soldan tek haneli basamaklardaki rakamlarýn toplamýný tutan deðiþken
	short ciftler = 0; //Tc numarasýndaki soldan çift haneli basamaklardaki rakamlarýn toplamýný tutan deðiþken
	short temp; //Atamalar ve kontroller yaparken kolaylýk saðlamasý için geçici deðiþken
	short indis = 0;
	

	temp = 1 + rand() % 9; //0dan büyük 10dan küçük bir tamsayýyý temp deðiþkenine ata.
	kimlik->tcNo[indis++] = '0' + temp; //temp deðiþkenindeki sayýyý TC numarasýnýn ilk hanesine ata
	tekler += temp;//Ýlk hane tek haneli bir basamak olduðu için bu hanedeki rakamý tekler deðiþkinine ekle

	int i;
	for (i = 0; i<8; i++) //2-9 arasý(9 dahil) haneleri rastgele üreten döngü
	{
		temp = rand() % 10; //0-10 arasýnda bir sayý üretip bunu tempe ata
		kimlik->tcNo[indis++] = '0' + temp; //temp deðiþkenindeki sayýyý TC numarasýnýn bir sonraki hanesi olarak ekle
		if (i % 2 == 0) //Eðer okunan hane çift ise bu haneyi ciftler deðiþkenine ekle
			ciftler += temp;
		else //Eðer okunan hane çift ise bu haneyi tekler deðiþkenine ekle
			tekler += temp;
	}

	temp = (7 * tekler - ciftler) % 10; //Tek hanedeki rakamlarýn toplamýnýn 7 katýndan çift hanedeki rakamlarý çýkart ve çýkan sonucun 10 ile modunu al
	
	kimlik->tcNo[indis++] = '0' + temp; //temp deðiþkenindeki sayýyý tcNo'ya ata
	kimlik->tcNo[indis++] = '0' + (tekler + ciftler + temp) % 10; //10 hanedeki tüm rakamlarý toplayýp modunu al ve bu sayýyý TC No'nun 11. hanesi olarak ata 
	kimlik->tcNo[indis] = '\0';
}

char * _tcNoDondur(const KimlikNo kimlik)
{
	return kimlik->tcNo;
}

int _tcNoKontrol(const char *tcNo)
{	
	short indis = 0;
	short tekler; //TC nosundaki tek hanedeki rakamlarýn toplamýný tutmak için
	short ciftler = 0;  //TC nosundaki çift hanedeki rakamlarýn toplamýný tutmak için
	short temp; //kontrolleri daha basitleþtirmek için

	temp = tcNo[indis++] - '0'; //Tc nosunun ilk hanesini temp deðiþkenine ata

	if (temp == 0) //TC numarýsýnýn ilk hanesi 0 olmamalý. 0 ise false döndür.
		return 0;

	tekler = temp; //Ýlk hane tek haneli olduðu için tekler deðiþkenine ata
	int i;
	for (i = 1; i<9; i++) //Soldan 2. basamaktan 9. basamaða kadar(9. dahil)
	{
		if (i % 2 == 1) //Okunan basamak cift ise
			ciftler += tcNo[indis++] - '0';
		else //Okunan basamak tek ise
			tekler += tcNo[indis++] - '0';
	}

	temp = tcNo[indis++] - '0'; //temp deðiþkenine Tc nosunun 10. hanesini ata

	if (temp != (7 * tekler - ciftler) % 10 ) //temp eþitliðin sað tarafýna eþit deðilse false döndür
		return 0;

	//Tc nosunun son(11.) hanesi ilk 10 hanenin toplamýnýn 10 ile moduna eþitse true deðilse false dondur
	return (tcNo[indis] == '0' + (tekler + ciftler + temp) % 10);
}

KimlikNo kimlikOlustur()
{
	KimlikNo araci; //Bir KimlikNo tipinden iþaretci tanýmla
	araci = (KimlikNo)malloc(sizeof(struct KIMLIKNO)); //araci için bellekte yer ayýr
	araci->tcNo = (char*)malloc(sizeof(char)*12); //tcnoyu tutan tcNo deðiþkeni için bellekten yer iste
	araci->tcNoUret = &_tcNoUret; //NDP benzetmesi için fonksiyon göstericisine fonksiyonun adresini ata
	araci->tcNoDondur = &_tcNoDondur; //NDP benzetmesi için fonksiyon göstericisine fonksiyonun adresini ata
	araci->tcNoKontrol = &_tcNoKontrol; //NDP benzetmesi için fonksiyon göstericisine fonksiyonun adresini ata
	araci->kimlikYoket = &_kimlikYoket; //NDP benzetmesi için fonksiyon göstericisine fonksiyonun adresini ata

	return araci; //olusturulan yapýyý döndür
}

void _kimlikYoket(KimlikNo kimlik) //Yokedici fonksiyon
{
	if (kimlik == NULL) return; //zaten yokedilmesi için gönderilen yapý NULL ise hiçbir þey yapmadan fonksiyondan çýk
	
	free(kimlik->tcNo); //kimlikno yapýsýnda bulunan tcno karakter dizisini serbest býrak
	free(kimlik); //kimlik'i serbest býrak
	kimlik = NULL; //kimlik'i null yap
}
