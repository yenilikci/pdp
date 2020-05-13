/**        
 * @file  KimlikNo.h
 * @description KIMLIKNO yapısını ve prototipleri içeren başlık dosyası.
 * @course  2.Öğretim C Grubu 
 * @assignment  2
 * @date  22.04.2020
 * @author Berke Altıntaş berke.altintas@ogr.sakarya.edu.tr G181210077, Muhammed Melih Çelik muhammed.celik7@ogr.sakarya.edu.tr G181210023
 **/ 

#ifndef KIMLIKNO
#define KIMLIKNO_H
#include "Rastgele.h"

struct KIMLIKNO
{
    char *pKimlik; //TCKimlik değerini tutacak karakter işaretçisi.
    void(*kimlikolustur)(struct KIMLIKNO*); //TcKimlikOlustur fonksiyonunun göstericisi.
    char*(*kimlikdondur)(struct KIMLIKNO*); //TcKimlikDondur fonksiyonunun göstericisi.
    bool(*kimlikkontrol)(struct KIMLIKNO*,char *); //TcKimlikKontrol fonksiyonunun göstericisi.
    void(*kimlikyoket)(struct KIMLIKNO*); //TcKimlikYokEt fonksiyonunun göstericisi.
};

typedef struct KIMLIKNO * KimlikNo; //KIMLIKNO yapısı KimlikNo göstericisi ile örneklendi.
KimlikNo KimlikKurucu(); //KimlikNo tipinde bir fonksiyon tanımlandı, kurucu fonksiyon gibi kullanıldı.
void TCKimlikOlustur(const KimlikNo);
char *TCKimlikDondur(const KimlikNo);
bool TCKimlikKontrol(const KimlikNo,char *);
void TcKimlikYokEt(KimlikNo);
int asciiToInt2(int);
#endif 