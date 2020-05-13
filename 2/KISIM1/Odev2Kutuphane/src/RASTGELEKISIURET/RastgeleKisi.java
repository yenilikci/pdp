/*
 * @file  RastgeleKisi.java
 * @description Rastgelekisi classının bulunduğu java dosyası.
 * @course  2.Öğretim C Grubu 
 * @assignment  2
 * @date  15.04.2020
 * @author Berke Altıntaş berke.altintas@ogr.sakarya.edu.tr G181210077, Muhammed Melih Çelik muhammed.celik7@ogr.sakarya.edu.tr G181210023
 */
package RASTGELEKISIURET;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class RastgeleKisi extends Kisi{
   
    public void rastgeleKisiUret() throws IOException //kisinin değişkenlerini atama işlemini yapan tüm fonksiyonları çağırıp ardından dosyaya yazan fonksiyon.
    {
        setIsimSoyIsim();
        setKimlik();
        setTelefon();
        setYas();
        File f = new File("Kisiler.txt");
        FileWriter fw = new FileWriter(f,true);
        BufferedWriter br = new BufferedWriter(fw);
        String kisi = Tc.TCKimlikDondur() + " " + IsimSoyIsim + " " + Yas + " " + tel.TelefonDondur() + " (" + tel.IMEIDondur() + ")\n"; //ödevde verilen formata göre dosyaya yazma işlemi.
        br.write(kisi);
        br.flush();
        br.close();
    }
  
}