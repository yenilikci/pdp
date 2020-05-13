/**        
 * @file  Telefon.h
 * @description TELEFON yapısını ve prototipleri içeren başlık dosyası.
 * @course  2.Öğretim C Grubu 
 * @assignment  2
 * @date  22.04.2020
 * @author Berke Altıntaş berke.altintas@ogr.sakarya.edu.tr G181210077, Muhammed Melih Çelik muhammed.celik7@ogr.sakarya.edu.tr G181210023
 **/ 

#ifndef TELEFON_h
#define TELEFON_H
#include "ImeiNo.h"

struct TELEFON
{
    ImeiNo super; //İç içe yapı oluşturularak kalıtım benzetildi.
    char *telefon; //Telefon değerini tutacak char pointer.
    void(*telefonolustur)(struct TELEFON*); //TelefonOlustur fonksiyonunun göstericisi.
    char*(*telefondondur)(struct TELEFON*); //TelefonDondur fonksiyonunun göstericisi.
    char*(*imeidondur)(struct TELEFON*); //ImeiDondur fonksiyonunun göstericisi.
    void(*telefonyoket)(struct TELEFON*); //TelefonNoYokEt fonksiyonunun göstericisi.
};
typedef struct TELEFON *TelefonNo; //TELEFON yapısı TelefonNo göstericisi ile örneklendi.
TelefonNo TelefonKurucu(); //TelefonNo tipinde bir fonksiyon tanımlandı, kurucu fonksiyon gibi kullanıldı.
void TelefonOlustur(const TelefonNo);
char *TelefonDondur(const TelefonNo);
char *ImeiDondur(const TelefonNo);
void TelefonNoYokEt(TelefonNo);
#endif