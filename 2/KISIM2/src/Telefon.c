/**        
 * @file  Telefon.c
 * @description Programın TELEFON yapısına ait fonksiyonları ve özellikleri içeren dosya.
 * @course  2.Öğretim C Grubu 
 * @assignment  2
 * @date  22.04.2020
 * @author Berke Altıntaş berke.altintas@ogr.sakarya.edu.tr G181210077, Muhammed Melih Çelik muhammed.celik7@ogr.sakarya.edu.tr G181210023
 **/ 

#include "Telefon.h"

//Nesne yönelimli dilmiş gibi davranılarak kurucu fonksiyon benzetmesi yapıldı.
TelefonNo TelefonKurucu()
{
    TelefonNo this;
    this = (TelefonNo)malloc(sizeof(struct TELEFON)); //malloc ile yapı boyutu kadar bellekten yer tahsis edildi.
    this->super = ImeiNoKurucu(); //İç içe kurulan yapının göstericisine kurucusu atandı.
    //Yazılan fonksiyonlar , fonksiyon göstericisi yardımı ile gösterildi:
    this->telefonolustur=&TelefonOlustur;
    this->telefondondur = &TelefonDondur;
    this->imeidondur = &ImeiDondur;
    this->telefonyoket = &TelefonNoYokEt;
    return this;
}

void TelefonOlustur(const TelefonNo this)
{
    Rastgele rs = RastgeleKurucu(); //Rastgele ile rs adında nesne oluşturma benzetmesi yapıldı.
    this->telefon = rs->rastgeleTelefon(rs); //Rastgele telefon değeri atandı.
}
char *TelefonDondur(const TelefonNo this)
{
    return this->telefon; //Rastgele telefon değeri döndürüldü.
}
char *ImeiDondur(const TelefonNo this)
{
    return this->super->pIMEI; //Rastgele imei değeri döndürüldü.
}

void TelefonNoYokEt(TelefonNo this) //Bellekte tahsis edilen alanları geri verecek fonksiyon.
{
    if(this == NULL)return;
    this->super->imeiYokEt(this->super);
    free(this);
}