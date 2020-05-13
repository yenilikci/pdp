/**        
 * @file  Kontrol.c
 * @description Programın KONTROL yapısına ait fonksiyonları ve özellikleri içeren dosya.
 * @course  2.Öğretim C Grubu 
 * @assignment  2
 * @date  22.04.2020
 * @author Berke Altıntaş berke.altintas@ogr.sakarya.edu.tr G181210077, Muhammed Melih Çelik muhammed.celik7@ogr.sakarya.edu.tr G181210023
 **/ 

#include "Kontrol.h"

//Nesne yönelimli dilmiş gibi davranılarak kurucu fonksiyon benzetmesi yapıldı.
Kontrol KontrolKurucu()
{
    Kontrol this;
    this = (Kontrol)(malloc(sizeof(struct KONTROL))); //malloc ile yapı boyutu kadar bellekten yer tahsis edildi.
    this->uretilmisDosyaKontrol = &uretilmisDosyaKontrol;
    this->kisilerDosyasiTemizle = &kisilerDosyasiTemizle;
    this->kontrolyoket = &kontrolYokEt;
    return this;
}

void uretilmisDosyaKontrol(const Kontrol this)
{
    int TcGecerli = 0; //geçerli Tc sayısını tutacak değişken
    int IMEIGecerli = 0; //geçerli Imei sayısını tutacak değişken
    int TcGecersiz = 0; //geçersiz Tc sayısını tutacak değişken
    int IMEIGecersiz = 0; //geçersiz Imei sayısını tutacak değişken
    KimlikNo kimlik = KimlikKurucu(); //KIMLIK yapısına ait özellikleri kullanabilmek için KimlikNo'dan nesne üretimi benzetmesi yapıldı
    ImeiNo imei = ImeiNoKurucu(); //IMEI yapısına ait özellikleri kullanabilmek için ImeiNo'dan nesne üretimi benzetmesi yapıldı.
    char Tc[12];
    char Imei[16];
    FILE *file = fopen ("Kisiler.txt", "r" ); //Kisiler dosyasını okuma modunda açıyoruz.
    if ( file != NULL )
    {
        char satir [ 300 ]; //300 karakterlik bir dizi tanımlandı.
        while ( fgets ( satir, sizeof satir, file ) != NULL ) //son satıra kadar döngü döndürüldü.
        {
            for(int i=0;i<11;i++)
            {
                Tc[i] = satir[i]; //satırdaki ilk değer TCKimlikNo değeri olduğu için ilk 11 hanesi Tc'ye atandı.
            }
            Tc[11] = '\0'; //Tc'nin son indisini tanımladık.

            for(int i=0;i<300;i++) //satir uzunluğu kadar bir döngü daha döndürdük
            {
                if(satir[i] =='(') //imei'nin önündeki parantez açma karakterini görünce
                {
                    for(int j=0;j<15;j++)
                    {
                        Imei[j] = satir[i+j+1]; //bir sonraki indisten devam eden 15 karakteri imei dizisine atadık.
                        
                    }
                    Imei[15] = '\0'; //Imei'nin son indisini tanımladık.
                    break;
                }
            }
            
            if (kimlik->kimlikkontrol(kimlik,Tc)) //eğer TC değeri geçerli ise
                TcGecerli++;        
            else //geçersiz ise
                TcGecersiz++;

            if (imei->imeiKontrol(imei,Imei)) //eğer Imei değeri geçerli ise
            {
                IMEIGecerli++;
            }
            else //geçersiz ise
                IMEIGecersiz++;
      }
      fclose ( file ); //dosya kapatıldı
   }
   else //eğer dosya işaretçisi boş ise
   {
      perror ( "Kisiler.txt" ); 
   }

    //Geçerli ve geçersiz Tc Kimlik ve Imei sayılarının ekrana basılması.
    printf("\nT.C. Kimlik Kontrol\n");
    printf("%d Gecerli\n",TcGecerli);
    printf("%d Gecersiz\n",TcGecersiz);
    printf("\nIMEI KONTROL\n");
    printf("%d Gecerli\n",IMEIGecerli);
    printf("%d Gecersiz\n\n",IMEIGecersiz);

}

void kisilerDosyasiTemizle(const Kontrol this) //Tekrar kişi üretmek istenildiğinde sıfırdan yazılmayı sağlayacak fonksiyon.
{
    FILE *fp; //FILE tipinde dosya işaretçisi.
    fp = fopen("Kisiler.txt", "w"); //bunu sağlamak için dosyayı "w" modunda açtık.
    fclose(fp); //işimiz bittiği için dosyayı kapattık
}

void kontrolYokEt(Kontrol this) //Bellekte tahsis edilen alanları geri verecek fonksiyon.
{
    if(this == NULL)return;
    free(this);
}
