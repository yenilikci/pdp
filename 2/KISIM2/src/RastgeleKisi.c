/**        
 * @file  RastgeleKisi.c
 * @description Programın RASTGELEKISI yapısına ait fonksiyonları ve özellikleri içeren dosya.
 * @course  2.Öğretim C Grubu 
 * @assignment  2
 * @date  22.04.2020
 * @author Berke Altıntaş berke.altintas@ogr.sakarya.edu.tr G181210077, Muhammed Melih Çelik muhammed.celik7@ogr.sakarya.edu.tr G181210023  
 **/ 

#include "RastgeleKisi.h"

//Nesne yönelimli dilmiş gibi davranılarak kurucu fonksiyon benzetmesi yapıldı.
RastgeleKisi RastgeleKisiKurucu()
{
    RastgeleKisi this;
    this = (RastgeleKisi)(malloc(sizeof(struct RASTGELEKISI))); //malloc ile yapı boyutu kadar bellekten yer tahsis edildi.
    this->super = KisiKurucu();
    this->rastgelekisiuret = &rastgeleKisiUret;
    this->rastgelekisiyoket = &rastgeleKisiYokEt;
    return this;
}
void rastgeleKisiUret(const RastgeleKisi this) //Rastgele kişi üreten fonksiyon.
{ 
    FILE *files; //FILE tipinde files işaretçisi.
    files = fopen("Kisiler.txt","a"); //ekleme modunda Kisiler.txt dosyası açıldı.
    this->super->setkimlik(this->super); //kimlik değeri atandı.
    this->super->settelefon(this->super); //telefon değeri atandı.
    this->super->setyas(this->super); //yas degeri atandı.
    fputs(this->super->kimlikSuper->kimlikdondur(this->super->kimlikSuper),files); //kimlik değeri dosyaya yazıldı.
    fputs(" ",files); //dosyaya boşluk karakteri yazıldı.
    fclose(files); //dosya kapatıldı.
    this->super->setisimsoyisim(this->super); //isimSoyisim değeri atandı.
    files = fopen("Kisiler.txt","a"); //ekleme modunda Kisiler.txt dosyası açıldı.
    fprintf(files,"%d",this->super->yas); //yas degeri dosyay yazıldı.
    fputs(" ",files); //boşluk karakteri dosyaya yazıldı.
    fputs(this->super->telefonSuper->telefondondur(this->super->telefonSuper) , files); //telefon değeri dosyaya yazıldı.
    fputs(" (",files); //parantez açma işareti dosyaya yazıldı.
    fputs(this->super->telefonSuper->imeidondur(this->super->telefonSuper) , files); //imei değeri dosyaya yazıldı.
    fputs(")",files); //parantez kapama işareti dosyaya yazıldı.
    fputs("\n",files); //alt satıra geçiş karakteri dosyaya basıldı
    fclose(files); //dosya kapatıldı.
}

void rastgeleKisiYokEt(RastgeleKisi this) //Bellekte tahsis edilen alanları geri verecek fonksiyon.
{
    if(this == NULL)return;
    this->super->kisiyoket(this->super);
    free(this);
}
