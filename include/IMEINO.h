#ifndef IMEINO_H
#define IMEINO_H
#include <time.h>
#include <stdlib.h>
#include <time.h>
#include "TELEFON.h"

typedef struct IMEINO* IMEINo;
typedef struct TELEFON* Telefon;

struct IMEINO
{
	char *imeiNo;

	void(*imeiNoUret)(const IMEINo);
	char*(*imeiNoDondur)(const IMEINo);
	int(*imeiNoKontrol)(const char *);
	void(*imeiYoket)(IMEINo);
};

void _imeiNoUret(const IMEINo);
char * _imeiNoDondur(const IMEINo);
int _imeiNoKontrol(const char *);
IMEINo imeiNesneOlustur(Telefon);
void _imeiYoket(IMEINo);
#endif // !1

