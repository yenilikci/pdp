/**        
 * @file  ImeiNo.h
 * @description IMENINO yapısını ve prototipleri içeren başlık dosyası.
 * @course  2.Öğretim C Grubu 
 * @assignment  2
 * @date  22.04.2020
 * @author Berke Altıntaş berke.altintas@ogr.sakarya.edu.tr G181210077, Muhammed Melih Çelik muhammed.celik7@ogr.sakarya.edu.tr G181210023
 **/ 

#ifndef IMEI_H
#define IMEI_H
#include "Rastgele.h"

struct IMEINO
{
    char *pIMEI; //IMEI değerini tutacak karakter işaretçisi.
    void(*imeiOlustur)(struct IMEINO*); //IMEIOlustur fonksiyonunun göstericisi.
    bool(*imeiKontrol)(struct IMEINO*,char *); //IMEIKontrol fonksiyonunun göstericisi.
    void(*imeiYokEt)(struct IMEINO*); //ImeiNoYokEt fonksiyonunun göstericisi.
};

typedef struct IMEINO *ImeiNo; //IMEINO yapısı ImeiNo göstericisi ile örneklendi.
ImeiNo ImeiNoKurucu(); //ImeiNo tipinde bir fonksiyon tanımlandı, kurucu fonksiyon gibi kullanıldı.
void IMEIOlustur(const ImeiNo);
bool IMEIKontrol(const ImeiNo,char *);
void ImeiNoYokEt(ImeiNo);
int asciiToInt(int);
#endif