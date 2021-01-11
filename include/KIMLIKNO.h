#ifndef KIMLIK_H
#define KIMLIK_H
#include <time.h>
#include <stdlib.h>
#include <time.h>

typedef struct KIMLIKNO* KimlikNo;

struct KIMLIKNO
{
	char *tcNo;

	void(*tcNoUret)(const KimlikNo);
	char*(*tcNoDondur)(const KimlikNo);
	int(*tcNoKontrol)(const char *);
	void(*kimlikYoket)(KimlikNo);
};

void _tcNoUret(const KimlikNo);
char * _tcNoDondur(const KimlikNo);
int _tcNoKontrol(const char *);
KimlikNo kimlikOlustur();
void _kimlikYoket(KimlikNo);

#endif 

