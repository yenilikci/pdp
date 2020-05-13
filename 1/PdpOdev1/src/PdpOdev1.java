import java.io.*; //Dosya işlemlerinde kullandım örn: try catch yapısı içerisinde FileNotFoundException'ı sağlarken.
import java.util.Scanner; //Scanner sınıfı için gerekli
import java.util.regex.*; //Pattern ve Matcher sınıfları için gerekli

/**
 * @author Muhammed Melih Çelik  muhammed.celik7@ogr.sakarya.edu.tr
 * @since 1 Mart 2020 
 * <p>
 * Programlama Dillerinin Prensipleri 1.Ödev - Dosya İşlemleri ve Düzenli İfadeler
 * </p>
 */
public class PdpOdev1 {
    public static void main(String[] args) {
        
        String dosyaOku; //txt dosyası okunacak ve return edilecek değer bu değişkene atanacak.
        
        int sesliHarfSayisi=0,kelimeSayisi=0,cumleSayisi=0,mailSayisi=0,siteSayisi=0; //ilk atama
        
        //txt dosyasından okunan String değer dosyaOku değişkenine atandı.
        dosyaOku = dosyaOku(""); 
        
        //kelimeDizisi() fonksiyonuna dosyaOku'daki string değer gönderildi ve split metodu ile oluşturulan dizi değişkenleri kelimeDizisi adlı string dizisine atandı.
        String[] kelimeDizisi = kelimeDizisi(dosyaOku);
        
        /*
        sesliHarfSayisi isimli tam sayı değişkenine sesliHarfSayisi() fonksiyonundan dönen tamsayı değeri atandı.
        sesliHarfSayisi() fonksiyonu sesli harfleri bulacak regex ifadesini ve String ifadeyi parametre olarak aldı.
        Sesli Harf Sayısı İçin Kullandığım Regex = "[AEIİOÖUÜaeıioöuü]"
        */
        sesliHarfSayisi = sesliHarfSayisi("[AEIİOÖUÜaeıioöuü]",dosyaOku);
        
        /*
        kelimeSayisi isimli tam sayı değişkenine kelimeSayisi() fonksiyonundan dönen tamsayı değeri atandı.
        kelimeSayisi() fonksiyonu parametre olarak String bir dizi olan kelimeDizisini aldı ve bu dizinin uzunluk bilgisini kullandı.
        */
        kelimeSayisi = kelimeSayisi(kelimeDizisi);   

        /*
        cumleSayisi isimli tam sayı değişkenine cumleSayisi() fonksiyonundan dönen tamsayı değeri atandı.
        cumleSayisi() fonksiyonu cümleleri bulacak regex ifadesini ve String bir diziyi parametre olarak aldı.
        Cümle Sayısı İçin Kullandığım Regex = "\\.$"
        */
        cumleSayisi = cumleSayisi("\\.$",kelimeDizisi); 

        /*
        mailSayisi isimli tam sayı değişkenine mailSayisi() fonksiyonundan dönen tamsayı değeri atandı.
        mailSayisi() fonksiyonu mailleri bulacak regex ifadesini ve String bir diziyi parametre olarak aldı.
        Mail Sayısı İçin Kullandığım Regex = "^[_A-Za-z0-9-\\+]+(\\.[_A-Za-z0-9-]+)*@[A-Za-z0-9-]+(\\.[A-Za-z0-9]+)*(\\.[A-Za-z]{2,})$"
        */
        mailSayisi = mailSayisi("^[_A-Za-z0-9-\\+]+(\\.[_A-Za-z0-9-]+)*@[A-Za-z0-9-]+(\\.[A-Za-z0-9]+)*(\\.[A-Za-z]{1,})$",kelimeDizisi);
        
        /*
        siteSayisi isimli tam sayı değişkenine siteSayisi() fonksiyonundan dönen tamsayı değeri atandı.
        siteSayisi() fonksiyonu siteleri bulacak regex ifadesini ve String bir diziyi parametre olarak aldı.
        Site Sayısı İçin Kullandığım Regex = "^(http:\\/\\/www\\.|https:\\/\\/www\\.|http:\\/\\/|https:\\/\\/)?[A-Za-z0-9]+([\\-\\.]{1}[A-Za-z0-9]+)*\\.(edu\\.tr$|edu$|com\\.tr$|com$|net\\.tr$|net$|org\\.tr$|org$)"
        */
        siteSayisi = siteSayisi("^(http:\\/\\/www\\.|https:\\/\\/www\\.|http:\\/\\/|https:\\/\\/)?[A-Za-z0-9]+([\\-\\.]{1}[A-Za-z0-9]+)*\\.(edu\\.tr$|edu$|com\\.tr$|com$|net\\.tr$|net$|org\\.tr$|org$)",kelimeDizisi); 
     
        //elde edilen tamsayı değerleri istatistik() fonksiyonuna parametre olarak gönderiliyor ve ekrana basılıyor.
        istatistik(sesliHarfSayisi,kelimeSayisi,cumleSayisi,mailSayisi,siteSayisi);
    }

    //dosyaOku() fonksiyonu icerik.txt'nin sonuna kadar okur ve icerik değişkenine atanan String değeri geri döndürür.
    public static String dosyaOku(String icerik)
    {    
        //try catch yapısı:
        try
        {
                    Scanner okunan = new Scanner(new File("icerik.txt")); //Scanner sınıfından yeni bir nesne oluşturuyoruz ve yeni bir File ile icerik.txt'yi parametre olarak veriyoruz.
                    while (okunan.hasNext()) //hasNext() ile dosya sonuna kadar döngü devam ediyor.
                    {       
                           icerik += okunan.nextLine(); //nextline seçtim çünkü text satırlara ayrılmış olabilir.    
                           icerik += " "; //bir boşluk bırakarak atama yapıldı çünkü daha sonra boşluk karakterine göre  daha sonrasında split edilecek.
                    }                 
        }
        catch (FileNotFoundException dosyabulunamadi)
                {
                    dosyabulunamadi.printStackTrace(); //dosya bulunamazsa hata mesajını ekrana basar.
                }
       return icerik; //String bir değer içeren icerik değişken değeri geri döndürüldü.
    }
    
    //sesliHarfSayisi() fonksiyonu kullanılacak regex ifadesini ve okunacak String değeri parametre olarak alır.
    public static int sesliHarfSayisi(String regexPar,String icerik)
    {
          int sesliHarfSayisi=0; //ilk atama
          Pattern sesliHarfDeseni = Pattern.compile(regexPar);
          Matcher sesliHarfEsles = sesliHarfDeseni.matcher(icerik); //dizinin her elemanı yani her bir kelime ifade ile eşleşiyor mu diye kontrol edilir.
          while(sesliHarfEsles.find()) //sesli harfi bulamayana kadar aramaya devam eder
          {
              if (sesliHarfEsles.group().length() !=0)
              {
                  sesliHarfSayisi++; //eşleşen sesli harf kadar sesliHarfSayisi artar.
              }
          }
          return sesliHarfSayisi; //toplam sesliHarfSayisi değeri geri döndürülür.
      }
    
    //kelimeDizisi() fonksiyonu String bir değeri parametre olarak alır ve bu değeri;
    public static String[] kelimeDizisi(String icerik) 
    {
        String[] kelimeDizisi = icerik.split(" "); //içeride split ederek bir String diziye aktarır
        return kelimeDizisi; //ve bu String dizisini geri döndürür.
    }
    
    //kelimeSayisi() fonksiyonu bir String dizi değerini parametre olarak alır
    public static int kelimeSayisi(String[] kelimeDizisi) 
    {
        int kelimeSayisi = 0; //ilk atama
        kelimeSayisi = kelimeDizisi.length; //dizinin uzunluğunun değeri bir tamsayı değişkene atandı
        return kelimeSayisi; //ve bu tamsayı değişkenin değeri geri döndürüldü bu da bize kelimeSayisi'ni verdi.
    }
    
    //cumleSayisi() fonksiyonu regex ifadesini ve bir String dizi değerini parametre olarak alır
    public static int cumleSayisi(String regexPar,String[] dizi) 
    {
        int cumleSayisi=0; //ilk atama
        for (int i = 0; i < dizi.length; i++) //dizi uzunluğu kadar bir döngü oluşturulur.
        {
        Pattern cumleDeseni = Pattern.compile(regexPar);
        Matcher cumleEsles = cumleDeseni.matcher(dizi[i]); //dizinin her elemanı yani her bir kelime ifade ile eşleşiyor mu diye kontrol edilir.
        while(cumleEsles.find()) //cümle bulamayana kadar aramaya devam eder.
        {
            if (cumleEsles.group().length() !=0)
            {
                cumleSayisi++; //eşleşen cümle kadar cumleSayisi artar.
            }
        }
        }
        return cumleSayisi; //toplam cumleSayisi değeri geri döndürülür.
    }
    
        //mailSayisi() fonksiyonu regex ifadesini ve bir String dizi değerini parametre olarak alır
        public static int mailSayisi(String regexPar,String[] dizi) 
    {
        int mailSayisi=0; //ilk atama
        for (int i = 0; i < dizi.length; i++) //dizi uzunluğu kadar bir döngü oluşturulur
        {
        Pattern mailDeseni = Pattern.compile(regexPar); 
        Matcher mailEsles = mailDeseni.matcher(dizi[i]); //dizinin her elemanı yani her bir kelime ifade ile eşleşiyor mu diye kontrol edilir.
        while(mailEsles.find()) //mail bulamayana kadar aramaya devam eder.
        {
            if (mailEsles.group().length() !=0)
            {
                mailSayisi++; //eşleşen mail kadar mailSayisi artar.
            }
        }
        }
        return mailSayisi; //toplam mailSayisi değeri geri döndürülür.
    }
        
    //siteSayisi() fonksiyonu regex ifadesini ve bir String dizi değerini parametre olarak alır
    public static int siteSayisi(String regexPar,String[] dizi) 
    {
        int siteSayisi=0; //ilk atama
        for (int i = 0; i < dizi.length; i++)  //dizi uzunluğu kadar bir döngü oluşturulur
        { 
        Pattern siteDeseni = Pattern.compile(regexPar);
        Matcher siteEsles = siteDeseni.matcher(dizi[i]); //dizinin her elemanı yani her bir kelime ifade ile eşleşiyor mu diye kontrol edilir.
        while(siteEsles.find()) //site bulamayana kadar aramaya devam eder.
        {
            if (siteEsles.group().length() !=0)
            {
                siteSayisi++; //eşleşen site kadar siteSayisi artar.
            }
        }
        }
        return siteSayisi; //toplam siteSayisi değeri geri döndürülür.
    }
                 
    //döndürülen tam sayı değerleri istatistik() fonksiyonuna parametre olarak verilir ve sayıların bilgisi ekrana basılır.
    public static void istatistik(int sesliHarfSayisi, int kelimeSayisi, int cumleSayisi, int mailSayisi, int siteSayisi)
    {
        System.out.println("Toplam Sesli Harf Sayısı : " + sesliHarfSayisi);
        System.out.println("Toplam Kelime Sayısı     : " + kelimeSayisi);
        System.out.println("Toplam Cümle Sayısı      : " + cumleSayisi );
        System.out.println("Toplam Mail Sayısı       : " + mailSayisi);
        System.out.println("Toplam Web Sitesi Sayısı : " + siteSayisi);
    }
    
}
