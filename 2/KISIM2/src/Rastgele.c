/**        
 * @file  Rastgele.c
 * @description Programın RASTGELE yapısına ait fonksiyonları ve özellikleri içeren dosya.
 * @course  2.Öğretim C Grubu 
 * @assignment  2
 * @date  22.04.2020
 * @author Berke Altıntaş berke.altintas@ogr.sakarya.edu.tr G181210077, Muhammed Melih Çelik muhammed.celik7@ogr.sakarya.edu.tr G181210023
 **/ 

#include "Rastgele.h"

//Nesne yönelimli dilmiş gibi davranılarak kurucu fonksiyon benzetmesi yapıldı.
Rastgele RastgeleKurucu()
{	
	Rastgele this;
	this = (Rastgele)malloc(sizeof(struct RASTGELE)); //malloc ile yapı boyutu kadar bellekten yer tahsis edildi.
	this->pTcKimlik = (char*)malloc(sizeof(char)*12); //malloc ile 12 karakterlik bellekten yer tahsisi yapıldı ve char işaretçisine çevrildi.
	this->pIMEINo = (char*)malloc(sizeof(char)*16);  //malloc ile 16 karakterlik bellekten yer tahsisi yapıldı ve char işaretçisine çevrildi.
	this->pTelefonNo = (char*)malloc(sizeof(char)*12);  //malloc ile 12 karakterlik bellekten yer tahsisi yapıldı ve char işaretçisine çevrildi.
	this->pIsimSoyIsim = (char*)malloc(sizeof(char)*30);  //malloc ile 30 karakterlik bellekten yer tahsisi yapıldı ve char işaretçisine çevrildi.
	this->lfsr = 0xACE1u;
	this->t = 0;
	//Yazılan fonksiyonlar , fonksiyon göstericisi yardımı ile gösterildi:
	this->rastgeleDeger = &RastgeleDeger;
	this->rastgeleIsimSoyisim = &RastgeleIsimSoyisimUret; 
	this->rastgeleYas = &RastgeleYasUret;
	this->rastgeleTc = &RastgeleTCUret;
	this->rastgeleImei = &RastgeleIMEIOlustur;
	this->rastgeleTelefon = &RastgeleTelefonOlustur;
	this->yoket = &RastgeleYokEt;
	return this;
}

int RastgeleDeger(const Rastgele this,unsigned int baslangicNumarasi,unsigned int bitisNumarasi) //Belirlediğimiz aralıkta rastgele bir değer döndürecek olan fonksiyon.
{
	
	if(baslangicNumarasi == bitisNumarasi) return baslangicNumarasi;
    int *p = malloc(sizeof(int)); //tamsayı p işaretçi için bellekten yer tahsis ettik
    this->t = this->t^(int)p; //tahsis ettiğimiz bu işaretçiyi 0 olan t ile bitwise işlemlerine soktuk 
    this->bit  = ((this->lfsr >> 0) ^ (this->lfsr >> 2) ^ (this->lfsr >> 3) ^ (this->lfsr >> 5) ) & 1; //bit değişkenine lfsr değişkeni bitwise işlemlerine sokularak yeni değer atandı
    this->lfsr = ((this->bit<<15) | (this->lfsr>>1) | this->t)%bitisNumarasi;//yapılan işlem sonuçlarında çıkan binary sayı verilen aralıktaki son sayı ile mod işlemine sokuldu
    while(this->lfsr<baslangicNumarasi){
        this->lfsr = this->lfsr + bitisNumarasi - baslangicNumarasi;//lfsr değeri belirtilen aralıkta değil ise belirtilen aralığa girene kadar aralık eklendi.
    }
    return (int)this->lfsr;
}

char *RastgeleIsimSoyisimUret(const Rastgele this) //Rastgele isim üretmemizi sağlayacak olan fonksiyon.
{
	FILE *fp;  //dosya işlemleri için tanınmladığımız FILE tipinde fp işaretçisi.
	int satir = 0;  
	char c;  
	fp = fopen("random_isimler.txt", "r"); 
	if (fp == NULL)  //Eğer dosya göstericisi boş işe dosya açılamamıştır.
	{ 
		printf("Dosya acilamadi:  %s","random_isimler.txt");  //Hata mesajı.
	    return 0; 
	} 
	for (c = getc(fp); c != EOF; c = getc(fp)) //Metin dosyasını okuyup satır sayısını bulacak olan fonksiyon.
		if (c == '\n') 
			satir++;
	fclose(fp); //dosya kapama fonksiyonu
    satir = this->rastgeleDeger(this,0,(satir+1)); //satir değişkeni 0'dan başladığı için 1 eklendi ve 0 ile (satir+1) arası rastgele bir değer dönüp tekrar satıra atandı.
    int i = 0;
    char str[1000];
    char* dosya = "random_isimler.txt";
    fp = fopen(dosya, "r"); //dosya tekrar açıldı
    while (true)
    {
        this->pIsimSoyIsim = fgets(str,sizeof(str),fp); //dosya göstercisi ile isimleri okundu ve pIsimSoyIsim işaretçisine atandı.
        if(i == satir)
            break;
        i++;
    }
    fclose(fp); //dosya kapama fonksiyonu
	for(int i = 0;i<30;i++)
    {
        if(this->pIsimSoyIsim[i] == '\n') //İsimler alt alta yazıldığı için alt satır kaçış işaretini gördüğü zaman
        {
            for(int j = 0;j<30-i ; j++)
                this->pIsimSoyIsim[i+j] = '\0'; //o isim satırının sonuna gelindiği bilgisi atandı.
            break;
        }
    }
	FILE *files; //tekrar dosya işaretçisi tanımlandı
    files = fopen("Kisiler.txt","a"); //dosya bu sefer ekleme modu ile açıldı. 
	fputs(this->pIsimSoyIsim , files); //İşaretçinin gösterdiği String isim soyisim değeri dosyaya yazıldı.
	fputs(" ",files);
	fclose(files); //tüm işlemler bitti dosya tekrar kapandı
	return this->pIsimSoyIsim; //İşaretçinin gösterdiği String isim soyisim değeri geri döndürüldü.
}

int RastgeleYasUret(const Rastgele this) //0 ile 100 arasında bir değer döndürmesi için fomksiyon.
{
	 return this->rastgeleDeger(this,0,101); //bu yüzden aralık değeri 0,101 verildi çünkü bitiş aralığının modunu alıyor.
}

char *RastgeleTCUret(const Rastgele this) //TC algoritmasına göre rastgele TC üretecek olan fonksiyon.
{
	int toplam1 = 0; //1,3,5,7,9.hanelerin toplamını tutacak olan değişken
	int toplam2 = 0; //2,4,6,8.hanelerin toplamını tutacak olan değişken.
	this->pTcKimlik[0] = '0' + this->rastgeleDeger(this,1,10); //ilk hane 0 olamaz 1-9 arası rastgele bir değer atandı.
	for (int i = 1; i < 9; ++i)
	{
		this->pTcKimlik[i] = '0' + this->rastgeleDeger(this,0,10); //diğer 8 haneye ise 0-9 arası rastgele değerler atandı.
	}
	for (int i = 0; i < 9; i += 2)
	{
		toplam1 += asciiToInt3((int)this->pTcKimlik[i]); //1,3,5,7,9.haneler toplandı toplam1'e atandı.
	}
	for (int i = 1; i < 8; i += 2)
	{
		toplam2 += asciiToInt3((int)this->pTcKimlik[i]); //2,4,6,8.haneler toplandı toplam2'ye atandı.

	}
	int hane10 = ((toplam1*7)-toplam2)%10; //toplam1'in 7 katından toplam2 çıkarıldı ve mod10'u alınarak 10.hane bulundu.
	while(hane10<0)
		hane10 = hane10+10;
	int hane11 = (toplam1+toplam2+hane10)%10; //ilk 10 hane toplamının mod10'u alındı ve 11.hane bulundu.
	this->pTcKimlik[9] = '0' + hane10; //tamsayı değerine sahip olan bu 10.hane karaktere çevrildi.
	this->pTcKimlik[10] = '0' + hane11; //tamsayı değerine sahip olan bu 11.hane de karaktere çevrildi.
	this->pTcKimlik[11] = '\0'; //son indis olduğunu tanımladık.
	return this->pTcKimlik;	//oluşan TCKimlik değerini geri döndürdük.
}

char* RastgeleIMEIOlustur(const Rastgele this) //IMEI algoritmasına göre rastgele imei üretecek fonksiyon.
{

	for (int i = 0; i < 14; ++i) //IMEI numarasının ilk 14 hanesini
	{
		this->pIMEINo[i] = '0' + this->rastgeleDeger(this,0,10); //rastgele 1-9 arası değerler atandı.
	}
	int i = 0;
	int toplam = 0;
	
	while(!(i == 14)) //tüm elemanları gezene kadar
	{
		if (i%2==0) //mod 2'si alındığında sıfır olan indisteki değerler toplama direk eklendi. 
		{
			toplam += asciiToInt3((int)this->pIMEINo[i]);
		}
		if (i%2==1) //mod 2'si alındığında 1 olan indisteki değerler ise 2 katı alınarak toplama eklendi.
		{
			int gecici = asciiToInt3(((int)this->pIMEINo[i]))*2;
			int geciciToplam = 0;
			geciciToplam = gecici % 10 + gecici / 10; //bu işlem ile sayı > 10 ise de sayı < 10 ise de farketmez
			toplam += geciciToplam;
		}
		i++;
	}
	//Toplam şu anda kadar ilk 14 hanenin toplamına eşit.
	if (toplam % 10 == 0) //İlk 14 hanesinin toplami 0 ise tüm toplamın mod 10'unun 0 olması için son hane de 0 olmalı.
	{
		this->pIMEINo[14] = '0'; //15.hane sıfır olur.
	}
	else //İlk 14 hanesinin toplamı sıfır değil ise mod 10'u 10 dan çıkarılıp son haneye eşitlenmeli.
	{
		this->pIMEINo[14] = '0'+(10-toplam%10);
	}
	this->pIMEINo[15] = '\0'; //son indis olduğunu tanımladık.
	return this->pIMEINo; //oluşan IMEINo değerini geri döndürdük.
}
char* RastgeleTelefonOlustur(const Rastgele this)
{
	this->pTelefonNo[0] = '0'; //Telefonların ilk hanesi 0 olduğu için '0' atandı.
	this->pTelefonNo[1] = '5'; //Telefonların ikinci hanesi 5 olduğu için '5' atandı.
	//Tüm hatlar için üçüncü rakam 0,5,3,6 veya 4 olabilir.
	char ucuncuRakamlar[5] = {'0','5','3','6','4'}; //Telefon numaralarının üçüncü hanesi bu 5 rakamdan birini alabilir.
	this->pTelefonNo[2] = ucuncuRakamlar[this->rastgeleDeger(this,0,5)]; //Telefon numarasınun üçüncü hanesine bu 5 rakamdan rastgele bir rakam atandı.
	//Eğer üçüncü rakamı 0 ise olabilecek durumlar
	if (this->pTelefonNo[2] == '0')
	{
		char dorduncuRakamSifirIcin[4] = {'1','5','6','7'};
		this->pTelefonNo[3] = dorduncuRakamSifirIcin[this->rastgeleDeger(this,0,4)];
	} 
	//Eğer üçüncü rakamı 5 ise olabilecek durumlar
	else if (this->pTelefonNo[2] == '5')
	{
		char dorduncuRakamBesIcin[6] = {'1','2','3','4','5','9'}; 
		this->pTelefonNo[3] = dorduncuRakamBesIcin[this->rastgeleDeger(this,0,6)];
	}
	//Eğer üçüncü rakamı 3 ise
	else if(this->pTelefonNo[2]== '3')
	{
		char dorduncuRakamUcIcin[10] = {'0','1','2','3','4','5','6','7','8','9'}; 
		this->pTelefonNo[3] = dorduncuRakamUcIcin[this->rastgeleDeger(this,0,10)];
	}
	//Eğer üçüncü rakamı 6 ise
	else if(this->pTelefonNo[2] == '6')
	{
		this->pTelefonNo[3] = '1';
	}
	//Eğer üçüncü rakamı 4 ise
	else if(this->pTelefonNo[2] == '4')
	{
		char dorduncuRakamDortIcin[10] = {'0','1','2','3','4','5','6','7','8','9'};
		this->pTelefonNo[3] = dorduncuRakamDortIcin[this->rastgeleDeger(this,0,10)];
	}
	for (int i = 4; i < 11; i++)
	{
		this->pTelefonNo[i] = '0' + this->rastgeleDeger(this,0,10); //Kalan hanelere 0-9 arası rastgele değerler atandı.
	}
	this->pTelefonNo[11] = '\0'; //son indis olduğunu tanımladık.
	return this->pTelefonNo; //oluşan TelefonNo değerini geri döndürdük.
}

int asciiToInt3(int a) //Karakter değerini tam sayı değerine çeviren fonksiyon.
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

void RastgeleYokEt(Rastgele this) //Bellekte tahsis edilen alanları geri verecek fonksiyon.
{
	if (this == NULL) return;
	free(this->pTcKimlik);
	free(this->pIMEINo);
	free(this->pTelefonNo);
	free(this);
}
