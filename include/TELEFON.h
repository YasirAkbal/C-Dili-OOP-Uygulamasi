#ifndef TELEFON_H
#define TELEFON_H
#include <time.h>
#include <stdlib.h>
#include <time.h>
#include "IMEINO.h"


typedef struct TELEFON* Telefon;
typedef struct IMEINO* IMEINo;

struct TELEFON
{
	char *telNo;
	IMEINo imei;

	void(*telNoUret)(const Telefon);
	char*(*telNoDondur)(const Telefon);
	void(*telYoket)(Telefon);
};


void _telNoUret(const Telefon);
char * _telNoDondur(const Telefon);
Telefon telNesneOlustur();
void _telYoket(Telefon);

#endif

