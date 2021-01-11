#ifndef RASTGELEKISI_H
#define RASTGELEKISI_H
#include <time.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include "KISI.h"
#include "TELEFON.h"
#include "KIMLIKno.h"

typedef struct RASTGELEKISI* RastgeleKisi;
typedef struct KISI* Kisi;

struct RASTGELEKISI
{
	char isimler[3000][2][50];

	void(*ayir)(char[3000][2][50], RastgeleKisi);
	void(*rndDegerAta)(Kisi,RastgeleKisi);
	void(*rastgeleKisiYikici)(RastgeleKisi);
	void(*dosyaYaz)(const Kisi);
};

void _ayir(char[3000][2][50], RastgeleKisi);
void _rndDegerAta(Kisi, RastgeleKisi);
RastgeleKisi rastgeleKisiYapici();
void _rastgeleKisiYikici(RastgeleKisi);
void _dosyaYaz(const Kisi);

#endif 

