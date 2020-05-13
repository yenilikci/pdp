/**        
 * @file  RastgeleKisi.h
 * @description RASTGELEKISI yapısını ve prototipleri içeren başlık dosyası.
 * @course  2.Öğretim C Grubu 
 * @assignment  2
 * @date  22.04.2020
 * @author Berke Altıntaş berke.altintas@ogr.sakarya.edu.tr G181210077, Muhammed Melih Çelik muhammed.celik7@ogr.sakarya.edu.tr G181210023
 **/ 

#ifndef RASTGELEKISI_H
#define RASTGELEKISI_H
#include "Kisi.h"
#include "Kontrol.h"

struct RASTGELEKISI
{
    Kisi super; //İç içe yapı oluşturularak kalıtım benzetildi.
    void(*rastgelekisiuret)(struct RASTGELEKISI*); //rastgeleKisiUret fonksiyonunun göstericisi.
    void(*rastgelekisiyoket)(struct RASTGELEKISI*); //rastgeleKisiYokEt fonksiyonunun göstericisi.
};
typedef struct RASTGELEKISI *RastgeleKisi; //RASTGELEKISI yapısı RastgeleKisi göstericisi ile örneklendi.
RastgeleKisi RastgeleKisiKurucu(); //RastgeleKisi tipinde bir fonksiyon tanımlandı, kurucu fonksiyon gibi kullanıldı.
void rastgeleKisiUret(const RastgeleKisi);
void rastgeleKisiYokEt(RastgeleKisi);
#endif