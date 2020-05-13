/*
 * @file  Telefon.java
 * @description Telefon classının bulunduğu java dosyası.
 * @course  2.Öğretim C Grubu 
 * @assignment  2
 * @date  15.04.2020
 * @author Berke Altıntaş berke.altintas@ogr.sakarya.edu.tr G181210077, Muhammed Melih Çelik muhammed.celik7@ogr.sakarya.edu.tr G181210023
 */
package RASTGELEKISIURET;

public class Telefon extends IMEINo { //her telefonun bir imeisi olması için imeino classı ile extendslendi.
    private String Telefon;
    public void TelefonOlustur() //rastgele fonksiyonu kullanarak telefon no oluşturan fonksiyon.
    {
        Rastgele rastgele = new Rastgele();
        Telefon = rastgele.RastgeleTelefonOlustur();
    }
    public String TelefonDondur() //telefon değişkeninin değerini döndüren fonksiyon.
    {
        return Telefon;
    }
    public String IMEIDondur() //imei değişkeninin değerini döndüren fonksiyon.
    {
        return IMEI;
    }
}
