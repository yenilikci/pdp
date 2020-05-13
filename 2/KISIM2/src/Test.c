/**        
 * @file  Test.c
 * @description Programın test edilip çalıştırıldığı dosya.
 * @course  2.Öğretim C Grubu 
 * @assignment  2
 * @date  22.04.2020
 * @author Berke Altıntaş berke.altintas@ogr.sakarya.edu.tr G181210077, Muhammed Melih Çelik muhammed.celik7@ogr.sakarya.edu.tr G181210023
 **/ 

#include "RastgeleKisi.h"
#include "locale.h"

int main() {
    setlocale(LC_ALL, "Turkish");
    Kontrol kn = KontrolKurucu(); //Kontrol yapısına ait özellikleri ve fonksiyonları kullanabilmek için.
    RastgeleKisi rs=RastgeleKisiKurucu(); //RastgeleKisi yapısına ait özellikleri ve fonksiyonları kullanabilmek için.
    while (true)
    {
        printf("1-Rastgele Kisi Uret\n2-Uretilmis Dosyayi Kontrol Et\n3-Cikis\n");
        int secenek;
        scanf("%d", &secenek);
        switch (secenek) 
        {
            case 1:      
                kn->kisilerDosyasiTemizle(kn); //Dosyayı sıfırdan yazması için mevcut kişiler dosyasını temizleyen fonksiyon çağrıldı.
                printf("Kac Kisi Uretilsin?\n");
                int sayi=0;
                scanf("%d", &sayi); //Kullancıdan kişi sayısının alınması.
                for (int i=0; i < sayi; i++)
                {
                    rs->rastgelekisiuret(rs);  //Kullanıcının girdiği sayı kadar rastgele kişi üretildi.
                }
                break;
            case 2:   
                kn->uretilmisDosyaKontrol(kn); //Üretilmiş dosyanın kontrolü için.
                break;
            case 3:
                rs->rastgelekisiyoket(rs); //Fonksiyonun çağrılması ile çıkış yapmadan önce bütün heap bölgesindeki veriler serbest bırakıldı. 
                kn->kontrolyoket(kn); //Kontrol yapısından oluşturulan heap bölgesindeki veriler de temizlendi.
                exit(0);
                break;
        }
    }
    getch();
    return 0;
}