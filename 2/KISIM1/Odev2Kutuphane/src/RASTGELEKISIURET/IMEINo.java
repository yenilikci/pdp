/*
 * @file  IMEINo.java
 * @description Imeimno classının bulunduğu java dosyası..
 * @course  2.Öğretim C Grubu 
 * @assignment  2
 * @date  15.04.2020
 * @author Berke Altıntaş berke.altintas@ogr.sakarya.edu.tr G181210077, Muhammed Melih Çelik muhammed.celik7@ogr.sakarya.edu.tr G181210023
 */
package RASTGELEKISIURET;


public class IMEINo {  
    protected String IMEI;
    public void IMEIOlustur() //rastgele classından rastgele imei oluşturulması için fonksiyon.
    {
        Rastgele rastgele = new Rastgele();
        IMEI = rastgele.RastgeleIMEIOlustur();
    }    
    public boolean IMEIKontrol(String IMEI) //parametre olarak alınan imeinin kontrolünü yapan fonksiyon.
    {             
        IMEI = IMEI.substring(1, 16); //gelen imeinin sonundaki ve başındaki parantezler silindi.
        byte i = 0;
        int toplam = 0;
        while(!(i == IMEI.length()-1)) //son karakterden öncesine kadar tüm karakterlerin imei algoritmasına göre gerekli hesapları yapıldı.
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
        if(toplam%10 == 0 && Character.getNumericValue(IMEI.charAt(14)) == 0) //son karakterin kontrolü yapıltıkdan sonra doğru olup olmadığı döndürüldü.
        {
            return true;
        }      
        else         
            return (10-toplam%10) == Character.getNumericValue(IMEI.charAt(14));

    }
}
