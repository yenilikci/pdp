/*
 * @file  Rastgele.java
 * @description Rastgele classının bulunduğu java dosyası.
 * @course  2.Öğretim C Grubu 
 * @assignment  2
 * @date  15.04.2020
 * @author Berke Altıntaş berke.altintas@ogr.sakarya.edu.tr G181210077, Muhammed Melih Çelik muhammed.celik7@ogr.sakarya.edu.tr G181210023
 */
package RASTGELEKISIURET;

import java.io.IOException;


public class Rastgele { //bu class yazılırken rastgelelik sağlanması için system.nanotime'a başvuruldu.
                   
    public int RastgeleIsimSoyisimUret() throws IOException //kaçıncı satırdaki isimin alınacağına karar veren fonksiyon.
    {
        Kontrol kn = new Kontrol();
        int kisiSayisi = kn.isimlerDosyasiKontrol(); //random_isimler dosyasındaki satır sayısı değişkene atandı.
        return ((int)((System.nanoTime()%1000000)/100)%kisiSayisi); //System nanotime'ın 0 ile satır sayısı arasında sayı döndürmesi için. Daha çok değişiklik gösteren hane alınması matematiksel işlemlere başvuruldu.      
    }
    
    public int RastgeleYasUret() //0 ile 100 arasında rastgele sayı döndürmesi için fonksiyon.
    {
        return ((int)((System.nanoTime()%10000)/100)); //System nanotime'ın en değişken haneleri alınarak 0 ile 100 arasında sayı vermesi sağlandı.
    }
    
    public String RastgeleTCUret() //tc algoritmasına göre rastgele tc üretmesi için fonksiyon.
    {
        String tc = ""; 
        while(!(tc.length()==9)) //stringin uzunluğu 9 olana kadar rastgele rakamlar tc stringine eklendi.
        {
            int rastgeleDeger = (int)((System.nanoTime()%1000)/100); //system nanotime'ın en değişken hanesinin alınması için matematiksel işlemlere başvuruldu.
            if (rastgeleDeger == 0 && tc.length()==0) { //tcnin ilk hanesinin 0 olmasını engellemek için if bloğu.
                rastgeleDeger = (int)((System.nanoTime()%1000)/100);
            }else{
                        tc = tc + Integer.toString(rastgeleDeger);
            }

        }
        int toplam1 = ((Character.getNumericValue(tc.charAt(0))) + (Character.getNumericValue(tc.charAt(2))) + (Character.getNumericValue(tc.charAt(4)))
                        + (Character.getNumericValue(tc.charAt(6))) + (Character.getNumericValue(tc.charAt(8)))) * 7;
        int toplam2 = (Character.getNumericValue(tc.charAt(1))) + (Character.getNumericValue(tc.charAt(3))) + (Character.getNumericValue(tc.charAt(5)))
                        + (Character.getNumericValue(tc.charAt(7))); //tc algoritmasına göre gerekli işlemler.
        int hane10 = (toplam1 - toplam2)%10;
        if(hane10 <0)//negatif değer çıkarsa pozitif olana kadar 10 eklenmesi için.
            hane10 = hane10 + 10;
        tc = tc + Integer.toString(hane10);

        int hane11 = ((Character.getNumericValue(tc.charAt(0))) + (Character.getNumericValue(tc.charAt(1))) + (Character.getNumericValue(tc.charAt(2)))
                        + (Character.getNumericValue(tc.charAt(3))) + (Character.getNumericValue(tc.charAt(4))) + (Character.getNumericValue(tc.charAt(5))) 
                        + (Character.getNumericValue(tc.charAt(6))) + (Character.getNumericValue(tc.charAt(7))) + (Character.getNumericValue(tc.charAt(8))) 
                        + (Character.getNumericValue(tc.charAt(9))))%10;
        tc = tc + Integer.toString(hane11); //gerekli işlemler ile rastgele tc oluşturulması tamamlandı.

        return tc;
    }
    
    public String RastgeleIMEIOlustur() //imei algoritmasına göre rastgele imei oluşturması için fonksiyon.
    {
        String IMEI = "";
        while(!(IMEI.length()==14)) //stringin uzunluğu 14 olana kadar rastgele rakamlar imei stringine eklendi.
        {
            IMEI = IMEI + Integer.toString((int)(System.nanoTime()%1000)/100); //system nanotime'ın en değişken hanesinin alınması için matematiksel işlemlere başvuruldu. 
        }
        byte i = 0;
        int toplam = 0;
        while(!(i == IMEI.length())) //tüm karakterlerin imei algoritmasına uyması için gerekli işlemler.
        {
            if(i%2 == 0)
            {
                toplam += Character.getNumericValue(IMEI.charAt(i));
            }
            if(i%2 == 1)
            {
                int gecici = (Character.getNumericValue(IMEI.charAt(i)))*2;
                if(gecici >= 10) //gelen sayı 10'dan yüksekse algoritmaya göre her iki basamağında toplanması için gecici değişkene başvuruldu.
                {
                    String gecicis = Integer.toString(gecici);
                    toplam += (Character.getNumericValue(gecicis.charAt(0)));
                    toplam += Character.getNumericValue(gecicis.charAt(1));
                }
                else
                    toplam += gecici;
            }
            i++;
        }
        if(toplam%10 == 0) //algoritmaya göre gerekli işlemler yapıldı ve imeinin oluşturuldu.
            IMEI = IMEI + "0";
        else
            IMEI = IMEI + Integer.toString(10-toplam%10); //önceki if bloğu buradan mod işleminde 0 gelirse imeiye "10" olarak iki hane daha eklenmesin diye.
                      
        return IMEI;
    }
    
    public String RastgeleTelefonOlustur() //rastgele telefon oluşturulması için fonksiyon.
    {
        String telefonNo = "0";
        //ilk 10 Turk Telekom diğer 11 Turkcell en son 10 Vodafone
        String ucHane[] = new String[]{"501","505","506","507","551","552","553","554","555","559","530","531","532","533","534","535","536","537","538",
                                        "539","561","540","541","542","543","544","545","546","547","548","549"};
        telefonNo = telefonNo + ucHane[(int)(System.nanoTime()%31)]; //dizideki 31 farklı ilk 3 rakamdan birisi seçildi.
        for (int i = 0; i < 7; i++) 
        {
             telefonNo = telefonNo + Integer.toString((int)(System.nanoTime()%1000)/100); //system nanotime'ın en değişken hanesinin alınması için matematiksel işlemlere başvuruldu. 
        }
        return telefonNo; //gerekli işlemler sonucunda oluşturulan telefon numarası döndürüldü.
    }
}
