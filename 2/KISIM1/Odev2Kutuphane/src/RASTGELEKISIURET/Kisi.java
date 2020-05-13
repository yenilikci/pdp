/*
 * @file  Kisi.java
 * @description Kisi classının bulunduğu java dosyası.
 * @course  2.Öğretim C Grubu 
 * @assignment  2
 * @date  15.04.2020
 * @author Berke Altıntaş berke.altintas@ogr.sakarya.edu.tr G181210077, Muhammed Melih Çelik muhammed.celik7@ogr.sakarya.edu.tr G181210023
 */
package RASTGELEKISIURET;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;

import java.io.IOException;

public class Kisi {    
    protected String IsimSoyIsim;
    protected KimlikNo Tc = new KimlikNo();
    protected int Yas;
    protected Telefon tel = new Telefon();   
    public void setIsimSoyIsim() throws FileNotFoundException, IOException //kisinin isim soyisim değişkenenine atama yapmak için fonksiyon.
    {
        Rastgele r = new Rastgele();
        int satir = r.RastgeleIsimSoyisimUret(); //hangi satırdaki ismin atanacağı rastgele classıyla seçildi.
                         
        FileReader f = new FileReader("random_isimler.txt");
        BufferedReader br  = new BufferedReader(f);
        int sayac = 0; 
        while(true) //seçilen satırdaki isim soyisim değişkene atandı.
        {   
            IsimSoyIsim = br.readLine();
            if(sayac == satir)
            {
                break;
            }
            sayac++;
        }
        br.close();
    }
    
    public void setTelefon() //kisinin telefonu ve imeisini oluşturan fonksiyon.
    {
        tel.TelefonOlustur();  
        tel.IMEIOlustur();
    }
    
    public void setKimlik() //kisinin kimliknosunu oluşturan fonksiyon.
    {
        Tc.TCKimlikOlustur();
    }
    
    public void setYas() //kisinin yaşını oluşturan fonksiyon.
    {
        Rastgele r = new Rastgele();
        Yas = r.RastgeleYasUret();
    }
}
    
    
    
    
    
   
