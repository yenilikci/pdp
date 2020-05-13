/**        
 * @file  Kisi.h
 * @description KISI yapısını ve prototipleri içeren başlık dosyası.
 * @course  2.Öğretim C Grubu 
 * @assignment  2
 * @date  22.04.2020
 * @author Berke Altıntaş berke.altintas@ogr.sakarya.edu.tr G181210077, Muhammed Melih Çelik muhammed.celik7@ogr.sakarya.edu.tr G181210023
 **/ 

#ifndef KISI_H
#define KISI_H
#include "KimlikNo.h"
#include "Telefon.h"

struct KISI
{
    char *IsimSoyIsim; //IsimSoyIsim değerini tutacak karakter işaretçisi.
    int yas; //yas değerini tutacak değişken.
    KimlikNo kimlikSuper; //İç içe yapı kullanılarak kalıtım benzetildi.
    TelefonNo telefonSuper; //İç içe yapı kullanılarak kalıtım benzetildi.
    void(*setisimsoyisim)(struct KISI*); //setIsimSoyIsim fonksiyonunun göstericisi.
    void(*settelefon)(struct KISI*); //setTelefon fonksiyonunun göstericisi.
    void(*setkimlik)(struct KISI*); //setKimlik fonksiyonunun göstericisi.
    void(*setyas)(struct KISI*); //setYas fonksiyonunun göstericisi.
    void(*kisiyoket)(struct KISI*); //KisiYokEt fonksiyonunun göstericisi.
};
typedef struct KISI *Kisi; //KISI yapısı Kisi göstericisi ile örneklendi.
Kisi KisiKurucu(); //Kisi tipinde bir fonksiyon tanımlandı, kurucu fonksiyon gibi kullanıldı.
void setIsimSoyIsim(const Kisi);
void setTelefon(const Kisi);
void setKimlik(const Kisi);
void setYas(const Kisi);
void KisiYokEt(Kisi);
#endif