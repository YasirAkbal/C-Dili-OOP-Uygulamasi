/**
*
* @author Ahmet Yasir Akbal/ahmet.akbal@ogr.sakarya.edu.tr
* @since 12.04.2018
* <p>
* Test Programýnýn olduðu kaynak dosyasý
* </p>
*/

#include "KISI.H"


void _adAta(const Kisi kisi, const char * ad) //ad üyesini set eden fonksiyon
{
	kisi->ad = ad;
}

const char * _adDondur(const Kisi kisi) //ad üyesini get eden fonksiyon
{
	return kisi->ad;
}

void _soyadAta(const Kisi kisi, const char * soyad) //soyad üyesini set eden fonksiyon
{
	kisi->soyad = soyad;
}

const char * _soyadDondur(const Kisi kisi) //ad üyesini get eden fonksiyon
{
	return kisi->soyad;
}

void _yasAta(const Kisi kisi, short yas) //yas üyesini set eden fonksiyon
{
	kisi->yas = yas;
}

int _yasDondur(const Kisi kisi) //yas üyesini get eden fonksiyon
{
	return kisi->yas;
}

Kisi kisiOlustur(RastgeleKisi rstKisi) //Yapýcý fonksiyon
{	
	Kisi kisi; //Bir KimlikNo tipinden iþaretci tanýmla
	kisi = (Kisi)malloc(sizeof(struct KISI)); //kisi için bellekte yer ayýr
	kisi->adAta = &_adAta; //NDP benzetmesi için fonksiyon göstericisine fonksiyonun adresini ata
	kisi->adDondur = &_adDondur; //NDP benzetmesi için fonksiyon göstericisine fonksiyonun adresini ata
	kisi->soyadAta = &_soyadAta; //NDP benzetmesi için fonksiyon göstericisine fonksiyonun adresini ata
	kisi->soyadDondur = &_soyadDondur; //NDP benzetmesi için fonksiyon göstericisine fonksiyonun adresini ata
	kisi->yasAta = &_yasAta; //NDP benzetmesi için fonksiyon göstericisine fonksiyonun adresini ata
	kisi->yasDondur = &_yasDondur; //NDP benzetmesi için fonksiyon göstericisine fonksiyonun adresini ata
	kisi->kisiYoket = &_kisiYoket; //NDP benzetmesi için fonksiyon göstericisine fonksiyonun adresini ata
	
	kisi->telefon = telNesneOlustur(); //telefon üyesini oluþtur
	kisi->kimlikNo = kimlikOlustur(); //kimlikNo üyesini oluþtur
	rstKisi->rndDegerAta(kisi, rstKisi); //Kisi yapýsýnýn elemanlarýna rastgele deðerler ata
	rstKisi->dosyaYaz(kisi); //Atanan bu rastgele deðerleri dosyaya yaz

	return kisi; //kisi yapýsýný döndür
}

void _kisiYoket(Kisi araci) //Yokedici fonksiyon
{	
	araci->kimlikNo->kimlikYoket(araci->kimlikNo); //KimlikNo yapýsýnda bulunan telefonun yokedicisini çaðýr
	araci->telefon->telYoket(araci->telefon); //Kisi yapýsýnda bulunan telefonun yokedicisini çaðýr
	if(araci == NULL) return; //zaten yokedilmesi için gönderilen yapý NULL ise hiçbir þey yapmadan fonksiyondan çýk
	free(araci); //araciyi serbest býrak
	araci = NULL; //araciya NULL ata
}
