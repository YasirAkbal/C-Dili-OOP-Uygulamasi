/**
*
* @author Ahmet Yasir Akbal/ahmet.akbal@ogr.sakarya.edu.tr
* @since 12.04.2018
* <p>
* Test Programýnýn olduðu kaynak dosyasý
* </p>
*/
#include "TELEFON.h"


void _telNoUret(const Telefon telefon)
{
	telefon->telNo[0] = 5 + '0';
	
	int i;
	for (i = 1; i<10; i++) //9 tane rastgele hane ekle(0,10 arasý)
	{
		telefon->telNo[i] = rand() % 10 + '0';
	}
	telefon->telNo[i] = '\0';
}

char * _telNoDondur(const Telefon telefon) // telnoyu donduren fonksiyon
{
	return telefon->telNo;
}

Telefon telNesneOlustur() //Yapýcý fonksiyon
{
	Telefon araci; //Bir araci tipinden iþaretci tanýmla
	araci = (Telefon)malloc(sizeof(struct TELEFON)); //araci için bellekte yer ayýr
	araci->telNo =  (char*)malloc(sizeof(char) * 11); //telný için bellekten yer iste
	araci->telNoUret = &_telNoUret; //NDP benzetmesi için fonksiyon göstericisine fonksiyonun adresini ata
	araci->telNoDondur = &_telNoDondur; //NDP benzetmesi için fonksiyon göstericisine fonksiyonun adresini ata
	araci->telYoket = &_telYoket; //NDP benzetmesi için fonksiyon göstericisine fonksiyonun adresini ata
	araci->imei = imeiNesneOlustur(araci); //imeiNo yapýsýnýn yapýcýsýný çaðýr

	return araci; //araciyi döndür
}

void _telYoket(Telefon telefon) //Yokedici fonksiyon
{
	telefon->imei->imeiYoket(telefon->imei); //telefon yapýsýnda bulunan imeinin yokedicisini çaðýr
	if (telefon == NULL) return; //zaten telefon NULLsa fonksiyondan çýk
	
	free(telefon->telNo); //telNo karakter iþaretçisini serbest býrak
	free(telefon); //telefonu serbest býrak
	telefon = NULL; //telefona NULL ata
}
