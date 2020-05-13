/*
 * @file  Kontrol.java
 * @description Kontrol classının bulunduğu java dosyası.
 * @course  2.Öğretim C Grubu 
 * @assignment  2
 * @date  15.04.2020
 * @author Berke Altıntaş berke.altintas@ogr.sakarya.edu.tr G181210077, Muhammed Melih Çelik muhammed.celik7@ogr.sakarya.edu.tr G181210023
 */
package RASTGELEKISIURET;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class Kontrol {
    public void uretilmisDosyaKontrol() throws FileNotFoundException, IOException //ilgili fonksiyonlara dosyadaki imeileri ve kimlikleri göndererek kontrol yapan fonksiyon.
    {
        KimlikNo TcKontrol = new KimlikNo();
        IMEINo IMEIKontrol = new IMEINo();
        int TcGecerli = 0;
        int IMEIGecerli = 0;
        int TcGecersiz = 0;
        int IMEIGecersiz = 0;
        
        FileReader f = new FileReader("Kisiler.txt");
        BufferedReader br  = new BufferedReader(f);
        String satir = br.readLine();
        while(satir != null) //gelen satırlar boşluk ile ayrılıp ilgili indexlerdeki tc ve imeiler kontrol fonksiyonlarına yollandı.
        {   
            String kelimeDizisi[] = satir.split(" ");
            if(TcKontrol.TCKimlikKontrol(kelimeDizisi[0]))
            {
                TcGecerli++;
            }
            else
            {
                TcGecersiz++;
            }
            if(IMEIKontrol.IMEIKontrol(kelimeDizisi[5]))
            {
                IMEIGecerli++;
            }
            else
            {
                IMEIGecersiz++;
            }
            satir = br.readLine();

        }      
        System.out.println("\nT.C. Kimlik Kontrol"); //çıkan sonuçlar ekrana yazdırıldı.
        System.out.println(TcGecerli + "     " + "Gecerli");
        System.out.println(TcGecersiz + "     " + "Gecersiz\n");
        System.out.println("IMEI Kontrol");
        System.out.println(IMEIGecerli + "     " + "Gecerli");
        System.out.println(IMEIGecersiz + "     " + "Gecersiz\n");
    }
    
    public int isimlerDosyasiKontrol() throws FileNotFoundException, IOException //verilen random_isimler dosyasının kaç satıra sahip olduğunu kontrol eden fonksiyon.
    {                         
        int satirSayisi = 0;
        FileReader f = new FileReader("random_isimler.txt");
        BufferedReader br  = new BufferedReader(f);
        String satir = br.readLine(); 
        while(satir != null)
        {   
            if (satir.length()>0)
            {
                satirSayisi++;
            }
            satir = br.readLine();
        }
        br.close();
        return satirSayisi;
    }
    
    public void kisilerDosyasiTemizle() throws FileNotFoundException //program her çalıştırıldığında kişiler dosyasını temizleyen fonksiyon.
    {
        File file = new File("Kisiler.txt");
        PrintWriter writer = new PrintWriter(file);
        writer.print("");
        writer.close();
    }
}
