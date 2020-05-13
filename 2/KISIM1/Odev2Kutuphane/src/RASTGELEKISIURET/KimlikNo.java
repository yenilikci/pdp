/*
 * @file  KimlikNo.java
 * @description KimlikNo classının bulunduğu java dosyası.
 * @course  2.Öğretim C Grubu 
 * @assignment  2
 * @date  15.04.2020
 * @author Berke Altıntaş berke.altintas@ogr.sakarya.edu.tr G181210077, Muhammed Melih Çelik muhammed.celik7@ogr.sakarya.edu.tr G181210023
 */
package RASTGELEKISIURET;


public class KimlikNo {
    private String TCKimlik;
    public void TCKimlikOlustur() //rastgele classından rastgele kimlik no oluşturulması için fonksiyon.
    {
        Rastgele rastgele = new Rastgele();
        TCKimlik = rastgele.RastgeleTCUret();
    }
    public String TCKimlikDondur() //kimliği döndürmesi için fonksiyon.
    {
        return TCKimlik;
    }
    public boolean TCKimlikKontrol(String TCKimlik) //parametre olarak alınan kimlik nonun kontrolünü yapan fonksiyon.
    {     
        
        boolean kontrol = false;
        int toplam1 = ((Character.getNumericValue(TCKimlik.charAt(0))) + (Character.getNumericValue(TCKimlik.charAt(2))) + (Character.getNumericValue(TCKimlik.charAt(4)))
                        + (Character.getNumericValue(TCKimlik.charAt(6))) + (Character.getNumericValue(TCKimlik.charAt(8)))) * 7;
        int toplam2 = (Character.getNumericValue(TCKimlik.charAt(1))) + (Character.getNumericValue(TCKimlik.charAt(3))) + (Character.getNumericValue(TCKimlik.charAt(5)))
                        + (Character.getNumericValue(TCKimlik.charAt(7)));
        int hane10 = (toplam1 - toplam2)%10;
        while(hane10 <0)//negatif değer çıkarsa pozitif olana kadar 10 eklenmesi için.
            hane10 = hane10 + 10;
        if(Character.getNumericValue(TCKimlik.charAt(9)) == hane10)
            kontrol = true;
        int hane11 = ((Character.getNumericValue(TCKimlik.charAt(0))) + (Character.getNumericValue(TCKimlik.charAt(1))) + (Character.getNumericValue(TCKimlik.charAt(2)))
                        + (Character.getNumericValue(TCKimlik.charAt(3))) + (Character.getNumericValue(TCKimlik.charAt(4))) + (Character.getNumericValue(TCKimlik.charAt(5))) 
                        + (Character.getNumericValue(TCKimlik.charAt(6))) + (Character.getNumericValue(TCKimlik.charAt(7))) + (Character.getNumericValue(TCKimlik.charAt(8))) 
                        + (Character.getNumericValue(TCKimlik.charAt(9))))%10;
        kontrol = Character.getNumericValue(TCKimlik.charAt(10)) == hane11;  //algoritmaya göre gerekli işlem yapılarak 10. ve 11 hanenin kontrolü sağlandı.     
        return kontrol; //kontrol değişkeni döndürüldü.
    }
}

