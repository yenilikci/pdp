/**        
 * @file  Kisi.c
 * @description Programın KISI yapısına ait fonksiyonları ve özellikleri içeren dosya.
 * @course  2.Öğretim C Grubu 
 * @assignment  2
 * @date  22.04.2020
 * @author Berke Altıntaş berke.altintas@ogr.sakarya.edu.tr G181210077, Muhammed Melih Çelik muhammed.celik7@ogr.sakarya.edu.tr G181210023 
 **/ 

#include "Kisi.h"

//Nesne yönelimli dilmiş gibi davranılarak kurucu fonksiyon benzetmesi yapıldı.
Kisi KisiKurucu()
{
    Kisi this;
    this = (Kisi)(malloc(sizeof(struct KISI))); //malloc ile yapı boyutu kadar bellekten yer tahsis edildi.
    this->kimlikSuper = KimlikKurucu(); //İç içe oluşturulan yapının kurucusu atandı.
    this->telefonSuper = TelefonKurucu(); //İç içe oluşturulan yapının kurucusu atandı.
    this->yas=0; // tamsayı değişken olan yas değişkenine 0 başlangıç değeri atandı.
    this->setisimsoyisim = &setIsimSoyIsim;
    this->setkimlik = &setKimlik;
    this->settelefon = &setTelefon;
    this->setyas = &setYas;
    this->kisiyoket = &KisiYokEt;
    return this;
}

void setIsimSoyIsim(const Kisi this) //isimSoyisim değerini atayacak fonksiyon.
{    
    Rastgele rastgele = RastgeleKurucu(); //Rastgele ile rastgele adında nesne oluşturma benzetmesi yapıldı.
    this->IsimSoyIsim = rastgele->rastgeleIsimSoyisim(rastgele); //IsimSoyIsim karakter işaretçisine rastgeleden üretilen rastgele bir isimSoyIsim değeri atandı.
    rastgele->yoket; //bellekteki bu yapı serbest bırakıldı.
    free(rastgele);
}

void setTelefon(const Kisi this) //telefon ve imei değerini atayacak fonksiyon
{
    this->telefonSuper->telefonolustur(this->telefonSuper);
    this->telefonSuper->super->imeiOlustur(this->telefonSuper->super);
}
void setKimlik(const Kisi this) //kimlik değerini atayacak fonksiyon
{
    this->kimlikSuper->kimlikolustur(this->kimlikSuper); 
}
void setYas(const Kisi this) //yas degerini atayacak fonksiyon.
{
    Rastgele rs = RastgeleKurucu(); //Rastgele ile rs adında nesne oluşturma benzetmesi yapıldı.
    this->yas = rs->rastgeleYas(rs); //yas değişkenine rastgeleYas fonksşyonu ile rastgele bir değer atandı.
    rs->yoket; //bellekteki bu yapı serbest bırakıldı.
    free(rs);
}

void KisiYokEt(Kisi this) //Bellekte tahsis edilen alanları geri verecek fonksiyon.
{
	if (this == NULL) return;
    this->kimlikSuper->kimlikyoket(this->kimlikSuper); 
    this->telefonSuper->telefonyoket(this->telefonSuper);
	free(this);
}