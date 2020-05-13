/**        
 * @file  Kontrol.h
 * @description KONTOL yapısını ve prototipleri içeren başlık dosyası.
 * @course  2.Öğretim C Grubu 
 * @assignment  2
 * @date  22.04.2020
 * @author Berke Altıntaş berke.altintas@ogr.sakarya.edu.tr G181210077, Muhammed Melih Çelik muhammed.celik7@ogr.sakarya.edu.tr G181210023
 **/ 

#ifndef KONTROL_H
#define KONTROL_H

#include "Kisi.h"

struct KONTROL
{
    void(*uretilmisDosyaKontrol)(struct KONTROL*); //uretilmisDosyaKontrol fonksiyonunun göstericisi.
    void(*kisilerDosyasiTemizle)(struct KONTROL*); //kisilerDosyasiTemizle fonksiyonunun göstericisi.
    void(*kontrolyoket)(struct KONTROL*); //kontrolYokEt fonksiyonunun göstericisi.
};

typedef struct KONTROL *Kontrol; //KONTROL yapısı Kontrol göstericisi ile örneklendi.
Kontrol KontrolKurucu(); //Kontrol tipinde bir fonksiyon tanımlandı, kurucu fonksiyon gibi kullanıldı.
void uretilmisDosyaKontrol(const Kontrol);
void kisilerDosyasiTemizle(const Kontrol);
void kontrolYokEt(Kontrol);
#endif