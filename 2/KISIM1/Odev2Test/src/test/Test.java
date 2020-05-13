/*
 * @file  Test.java
 * @description Programın çalışmasını sağlayan dosya.
 * @course  2.Öğretim C Grubu 
 * @assignment  2
 * @date  15.04.2020
 * @author Berke Altıntaş berke.altintas@ogr.sakarya.edu.tr G181210077, Muhammed Melih Çelik muhammed.celik7@ogr.sakarya.edu.tr G181210023
 */
package test;

import RASTGELEKISIURET.*;
import java.io.IOException;
import java.util.Scanner;



public class Test {
    public static void main(String[] args) throws IOException {
        Kontrol kn = new Kontrol();
        while(true)
        {
            System.out.println("1-Rastgele Kişi Üret \n2-Üretilmiş Dosyayı Kontrol Et \n3-Çıkış");
            Scanner tara = new Scanner(System.in);
            int secenek = tara.nextInt();
            switch(secenek)
            {
                case 1:
                    kn.kisilerDosyasiTemizle();  //1 seçeneği seçildiğinde mevcut kişiler dosyasını temizlemesi için fonksiyon çağırıldı.
                    RastgeleKisi kisiUret = new RastgeleKisi(); //rastgele kisi üretme fonksiyonunun kullanılması için nesne oluşturuldu.
                    System.out.print("Kaç Kişi Üretilsin : ");
                    int sayi = tara.nextInt();
                    for(int i = 0 ; i < sayi ; i++)
                    {
                        kisiUret.rastgeleKisiUret(); //girilen sayı kadar kişi üretildi.
                    }
                    break;                  
                case 2:
                   kn.uretilmisDosyaKontrol(); //üretilmiş dosyanın kontrolü için.
                   break;
                case 3:
                    System.exit(0);
            }
        }   
    }
    
}
