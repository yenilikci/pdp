/**        
 * @file  ImeiNo.c
 * @description Programın IMEINO yapısının ve fonksiyon prototiplerinin tanımlandığı başlık dosyası.
 * @course  2.Öğretim C Grubu 
 * @assignment  2
 * @date  22.04.2020
 * @author Berke Altıntaş berke.altintas@ogr.sakarya.edu.tr G181210077, Muhammed Melih Çelik muhammed.celik7@ogr.sakarya.edu.tr G181210023
 **/ 

#include "ImeiNo.h"

//Nesne yönelimli dilmiş gibi davranılarak kurucu fonksiyon benzetmesi yapıldı.
ImeiNo ImeiNoKurucu()
{
    ImeiNo this;
    this = (ImeiNo)malloc(sizeof(struct IMEINO)); //malloc ile yapı boyutu kadar bellekten yer tahsis edildi.
    this->imeiOlustur = &IMEIOlustur;
    this->imeiKontrol = &IMEIKontrol;
    this->imeiYokEt = &ImeiNoYokEt;
    return this;
}


void IMEIOlustur(const ImeiNo this) //Imei oluşturacak fonksiyon.
{
    Rastgele rastgele = RastgeleKurucu(); //Rastgele ile rastgele adında nesne oluşturma benzetmesi yapıldı.
    this->pIMEI = rastgele->rastgeleImei(rastgele); //Rastgele imei oluşturulup, pIMEI karakter işaretçisine atandı.
}
bool IMEIKontrol(const ImeiNo this,char *imei)
{
    int i = 0;
    int toplam = 0; 
    char a = 'A'; //ilk değer 'A' karakteri olarak atandı.
    while(!(i == strlen(imei)-1)) //i , uzunluk-1 e kadar döndü
    {
        a = (char)(imei[i]); //Imei'nin o karakteri a karakter değişkenine eşitlendi.
        if (i%2==0) //mod 2'si alındığında sıfır olan indisteki değerler toplama direk eklendi. 
        {
            toplam += asciiToInt((int)(a));
        }
        if (i%2 ==1) //mod 2'si alındığında 1 olan indisteki değerler ise 2 katı alınarak toplama eklendi.
        {
            int gecici = (int)(a);  //a karakteri tamsayıya dönüştürülerek geçici değişkene atandı
            gecici = asciiToInt(a)*2; //bu geçici değişken 2 ile çarpıldı
            if (gecici >=10) //değer 10'a eşit veya büyükse basamaklarına ayrıldı
            {
                toplam += (gecici)/10; //iki basamaklı sayının ilk basamağı (birler)
                toplam += (gecici)%10; //iki basamaklı sayının ikinci basamağı (onlar)
            }
            else //değilse
                toplam += gecici; //direk toplama eşitlendi.
        }
        i++; 
    }
    a = (char)(imei[14]); //Imei'nin son karakteri a değişkenine atandı.
    int imei15 = asciiToInt((int)(a)); //a karakteri, tamsayıya çeviren fonksiyon ile imei15 değişkenine atandı.
    if(toplam %10 == 0 && imei15 == 0) //son karakterin kontrolü yapıldıktan sonra doğru olup olmadığı döndürüldü. 
    {
        return true;
    }
    else
    {
        return (10-toplam%10) == imei15;
    }

}

int asciiToInt(int a) //Karakter değerini tam sayı değerine çeviren fonksiyon.
{
    int b = 0;
    if(a == 48)
        b = 0;
    if(a == 49)
        b = 1;
    if(a == 50)
        b = 2;
    if(a == 51)
        b = 3;
    if(a == 52)
        b = 4;
    if(a == 53)
        b = 5;
    if(a == 54)
        b = 6;
    if(a == 55)
        b = 7;
    if(a == 56)
        b = 8;
    if(a == 57)
        b = 9;
    return b;
}

void ImeiNoYokEt(ImeiNo this) //Bellekte tahsis edilen alanları geri verecek fonksiyon.
{
    if(this == NULL)return;
    free(this);
}