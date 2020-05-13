/**        
 * @file  KimlikNo.c
 * @description Programın KIMLIKNO yapısına ait fonksiyonları ve özellikleri içeren dosya.
 * @course  2.Öğretim C Grubu 
 * @assignment  2
 * @date  22.04.2020
 * @author Berke Altıntaş berke.altintas@ogr.sakarya.edu.tr G181210077, Muhammed Melih Çelik muhammed.celik7@ogr.sakarya.edu.tr G181210023
 **/ 

#include "KimlikNo.h"

//Nesne yönelimli dilmiş gibi davranılarak kurucu fonksiyon benzetmesi yapıldı.
KimlikNo KimlikKurucu()
{
    KimlikNo this;
    this = (KimlikNo)malloc(sizeof(struct KIMLIKNO)); //malloc ile yapı boyutu kadar bellekten yer tahsis edildi.
    this->kimlikolustur = &TCKimlikOlustur;
    this->kimlikdondur = &TCKimlikDondur;
    this->kimlikkontrol = &TCKimlikKontrol;
    this->kimlikyoket = &TcKimlikYokEt;
    return this;
}

void TCKimlikOlustur(const KimlikNo this) //TcKimlikNo oluşturan fonksiyon.
{
    Rastgele rastgele = RastgeleKurucu(); //Rastgele ile rastgele adında nesne oluşturma benzetmesi yapıldı.
    this->pKimlik = rastgele->rastgeleTc(rastgele); //pKimlik karakter işaretçisine rastgele kimlik değeri atandı.
}

char *TCKimlikDondur(const KimlikNo this) //pKimlik karakter işaretçisinin değerini döndüren fonksiyon.
{
    return this->pKimlik;
}
bool TCKimlikKontrol(const KimlikNo this,char * tc) //TcKimlikNo kontrolünü yapacak olan fonksiyon
{
    int toplam1=0; //1,3,5,7,9.hanelerin toplamını tutacak olan değişken
    int toplam2=0; //2,4,6,8.hanelerin toplamını tutacak olan değişken.
    char a = 'A'; //ilk değer 'A' karakteri olarak atandı.
    bool kontrol = false;
	for (int i = 0; i < 9; i += 2)
	{
        a = (char)(tc[i]);
		toplam1 += asciiToInt2((int)(a)); //1,3,5,7,9.haneler toplandı toplam1'e atandı.
	}
	for (int i = 1; i < 8; i += 2)
	{ 
        a = (char)(tc[i]);
		toplam2 += asciiToInt2((int)(a)); //2,4,6,8.haneler toplandı toplam2'ye atandı.
	}
    int hane10 = ((toplam1*7)-toplam2)%10;  //toplam1'in 7 katından toplam2 çıkarıldı ve mod10'u alınarak 10.hane bulundu.
	while(hane10<0)
		hane10 = hane10+10;
    a = (char)(tc[9]); //metinden gelen bu 10.değer a değişkenine atandı.
    if(asciiToInt2((int)(a)) == hane10) //metinden gelen değer ile hane10 değeri aynı mı diye kontrol edildi
        kontrol = true; //aynı ise kontrol true'ya çevrildi
    int hane11 = (toplam1+toplam2+hane10)%10; //ilk 10 hane toplamının mod10'u alındı ve 11.hane bulundu.
    a = (char)(tc[10]);  //bu 11.değer tekrar a'ya atandı
    kontrol = (asciiToInt2((int)(a)) == hane11); //olması gereken değer ile metinden gelen değer aynı mı diye kontrol edildi.
    return kontrol;  
}

int asciiToInt2(int a) //Karakter değerini tam sayı değerine çeviren fonksiyon.
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

void TcKimlikYokEt(KimlikNo this) //Bellekte tahsis edilen alanları geri verecek fonksiyon.
{
    if(this == NULL) return;
    free(this);
}














