/**        
 * @file  Rastgele.h
 * @description RASTGELE yapısını ve prototipleri içeren başlık dosyası.
 * @course  2.Öğretim C Grubu 
 * @assignment  2
 * @date  22.04.2020
 * @author Berke Altıntaş berke.altintas@ogr.sakarya.edu.tr G181210077, Muhammed Melih Çelik muhammed.celik7@ogr.sakarya.edu.tr G181210023
 **/ 

#ifndef RASTGELE_H
#define RASTGELE_H
#include <stdio.h> //printf ve scanf gibi fonksiyonları kullanabilmek için eklendi.
#include <conio.h> //getch() fonksiyonu için eklendi
#include <time.h> //zaman özelliklerini kullanabilmek için eklendi
#include <stdlib.h>	//bellek işlemleri için eklendi.
#include <string.h>	 //string ifadelere ait fonksiyonlar için eklendi
#include <stdbool.h> //bool için eklendi

struct RASTGELE
{	
	unsigned int lfsr; //Rastgele değer üretirken kullanıldı.
	unsigned int bit,t; //Rastgele değer üretilirken kullanıldı.
	char *pTcKimlik; //TcKimlik değerini tutacak karakter göstericisi.
	char *pIMEINo;	//IMEINo değerini tutacak karakter göstericisi.
	char *pTelefonNo; //TelefonNo değerini tutacak karakter göstercisi.
	char *pIsimSoyIsim;	//IsimSoyIsim değerini tutacak karakter göstericisi.
	int(*rastgeleDeger)(struct RASTGELE*,unsigned int,unsigned int);  //RastgeleDeger fonksiyonunun göstericisi.
	char*(*rastgeleIsimSoyisim)(struct RASTGELE*);  //RastgeleIsimSoyisimUret fonksiyonunun göstericisi.
	int(*rastgeleYas)(struct RASTGELE*);  //RastgeleYasUret fonksiyonunun göstericisi.
	char*(*rastgeleTc)(struct RASTGELE*);  //RastgeleTcUret fonksiyonunun göstericisi.
	char*(*rastgeleImei)(struct RASTGELE*);  //RastgeleIMEIOlustur fonksiyonunun göstericisi.
	char*(*rastgeleTelefon)(struct RASTGELE*);	//RastgeleTelefonOlustur fonksiyonunun göstericisi.
	void(*yoket)(struct RASTGELE*); //RastgeleYokEt fonksiyonunun göstericisi.
};

typedef struct RASTGELE *Rastgele; //RASTGELE yapısı Rastgele göstericisi ile örneklendi.
Rastgele RastgeleKurucu(); //Rastgele tipinde bir fonksiyon tanımlandı, kurucu fonksiyon gibi kullanıldı.
int RastgeleDeger(const Rastgele,unsigned int,unsigned int);
char* RastgeleIsimSoyisimUret(const Rastgele);
int RastgeleYasUret(const Rastgele);
char *RastgeleTCUret(const Rastgele);
char *RastgeleIMEIOlustur(const Rastgele);
char *RastgeleTelefonOlustur(const Rastgele);
void RastgeleYokEt(Rastgele);
int asciiToInt3(int);
#endif