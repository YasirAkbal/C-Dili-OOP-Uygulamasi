#ifndef KISI_H
#define KISI_H
#include <time.h>
#include "TELEFON.h"
#include "KIMLIKNO.h"
#include "RASTGELEKISI.h"

typedef struct KISI* Kisi;
typedef struct RASTGELEKISI* RastgeleKisi;

struct KISI
{
	Telefon telefon;
	KimlikNo kimlikNo;
	const char *ad;
	const char *soyad;
	short yas;

	void(*adAta)(const Kisi, const char*);
	const char*(*adDondur)(const Kisi);
	void(*soyadAta)(const Kisi, const char*);
	const char*(*soyadDondur)(const Kisi);
	void(*yasAta)(const Kisi, short);
	int(*yasDondur)(const Kisi);
	void (*kisiYoket)(Kisi);
};


void _adAta(const Kisi, const char*);
const char * _adDondur(const Kisi);
void _soyadAta(const Kisi, const char*);
const char * _soyadDondur(const Kisi);
void _yasAta(const Kisi, short);
int _yasDondur(const Kisi);
Kisi kisiOlustur(RastgeleKisi);
void _kisiYoket(Kisi);


#endif 

