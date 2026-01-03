#include <stdio.h>
#define MAX_ARAC 100
/*
1- BAÞLA 
2- 0-1 saat ücretlendirme deðerini gir. 
3- 1-3 saat ücretlendirme deðerini gir. 
4- 3-5 saat ücretlendirme deðerini gir. 
5- 5 saat ve üzeri ücretlendirme deðerini gir. 
6- Gelen aracýn plakasýný, markasýný ve rengini gir. 
7- Gelen aracýn giriþ yaptýðý tarihi ve saati gir. 
8- Çýkan aracýn plakasýný, markasýný ve rengini gir. 
9- Çýkan aracýn çýkýþ yaptýðý tarihi ve saati gir. 
10- Çýkan aracýn çýkýþ yaptýðý tarihten giriþ yaptýðý tarihi çýkart.
	Eðer deðer 0’dan küçükse, 9. Adýma git. 
	Eðer deðer 0’dan büyükse, 12. Adýma git. 
	Eðer deðer 0’a eþitse, 11. Adýma git. 
11- Çýkan aracýn çýkýþ yaptýðý saatten giriþ yaptýðý saati çýkart. 
	Eðer deðer 1’den küçükse, 15. Adýma git. 
	Eðer deðer 1’den büyük veya eþitse, 3’ten büyük veya eþit mi? 
		Hayýrsa, 14. Adýma git. 
		Evetse, 5’ten büyük veya eþit mi? 
		Hayýrsa, 13. Adýma git. 
		Evetse, 12. Adýma git. 
12- Eðer çýkan saat deðeri 5 veya 5’ten büyük ise 5 saat ve üzeri saat ücretlendirmesi deðerini 
yazdýr. Çýkan deðeri müþterinin tercihine göre nakit veya kartla ödeme al. Borç yazýlmasý 
isteniyorsa Borç seç. 16. Adýma git. 
13- Eðer çýkan saat deðeri 3-5 aralýðýnda ise 3-5 saat ücretlendirmesi deðerini yazdýr. Çýkan deðeri 
müþterinin tercihine göre nakit veya kartla ödeme al. Borç yazýlmasý isteniyorsa Borç seç. 16. 
Adýma git. 
14- Eðer çýkan saat deðeri 1-3 aralýðýnda ise 1-3 saat ücretlendirmesi deðerini yazdýr. Çýkan deðeri 
müþterinin tercihine göre nakit veya kartla ödeme al. Borç yazýlmasý isteniyorsa Borç seç. 16. 
Adýma git. 
15- Eðer çýkan saat deðeri 0-1 saat aralýðýnda ise 0-1 saat ücretlendirmesi deðerini yazdýr. Çýkan 
deðeri müþterinin tercihine göre nakit veya kartla ödeme al. Borç yazýlmasý isteniyorsa Borç 
seç. 16. Adýma git. 
16- BÝTÝR.
*/
int main() 
{
    int secim;
    int i;
    int cikisSaat, cikisDakika;
    int girisToplam, cikisToplam, farkDakika;
    int toplamSaat, toplamDakika;
    int odemeSecim;
    int dolu[MAX_ARAC] = {0};           
    int girisZaman[MAX_ARAC][2];
    int rapor[4][3] = {0};
    char *mesajlar[4] = {"0-1","1-3","3-5","5+"};
    char plaka[MAX_ARAC][10];
    char marka[MAX_ARAC][15];
    char renk[MAX_ARAC][15];
    float tarifeler[4] = {0,0,0,0}; // 0: 0-1 saat, 1: 1-3 saat, 2: 3-5 saat, 3: 5+ saat
    float sureSaat, ucret;
    printf("--OTOPARK KAYIT SISTEMI--\n");
    printf("1- Bilgi girisi icin 1'i tuslayin.\n");
    printf("2- Arac cikisi icin 2'yi tuslayin.\n");
    printf("3- Cikis yapmak icin 3'u tuslayin.\n");
    printf("Seciminizi giriniz: ");
    scanf("%d", &secim);
    while (1)
    {
        if (secim == 1)
        {
            if (tarifeler[0] == 0)
            {
                printf("\n--TARIFE GIRISI--\n");
                for (i = 0; i < 4; i++)
                {
                    printf("%s saat araligi ucretlendirmesini giriniz (TL): ", mesajlar[i]);
                    scanf("%f", &tarifeler[i]);
                }
                printf("Tarifeler kaydedildi!\n");
            }
            int index = -1;
            for (i = 0; i < MAX_ARAC; i++)
            {
                if (dolu[i] == 0)
                {
                    index = i;
                    break;
                }
            }
            if (index == -1)
            {
                printf("Otopark dolu!\n");
            }
            else
            {
                printf("\n--ARAC BILGILERI--\n");
                printf("Plaka(Orn:01AAA001): ");
                scanf("%s", plaka[index]);
                printf("\nMarka(Orn:LandRover): ");
                scanf("%s", marka[index]);
                printf("\nRenk(Orn:AntrasitGri): ");
                scanf("%s", renk[index]);
                
                while (1)
                {
                    printf("%s plakali %s marka %s renk aracin giris yaptigi saat ve dakikayi giriniz(Orn: 12 15): ",
                           plaka[index], marka[index], renk[index]);
                    
                    scanf("%d %d", &girisZaman[index][0], &girisZaman[index][1]);
                    
                    if (girisZaman[index][0] < 0 || girisZaman[index][0] > 23 ||
                        girisZaman[index][1] < 0 || girisZaman[index][1] > 59)
                    {
                        printf("Hatali saat veya dakika girdiniz! Saat 0-23, dakika 0-59 arasinda olmalidir.\n");
                    }
                    else
                    {
                        dolu[index] = 1;    // araç yeri dolu anlaminda kullanildi
                        break;
                    }
                }
                
                printf("\nArac girisi basariyla kaydedildi. (Kayit no: %d)\n", index);
            }
            printf("\n1-Yeni Arac Girisi\n2-Arac Cikisi\n3-Programdan Cikis\nSeciminizi Yapiniz:");
            scanf("%d",&secim);
            continue;
        }
        else if (secim == 2)
        {
            int index;
            printf("\nCikis yapacak aracin kayit numarasini giriniz (0-%d): ", MAX_ARAC-1);
            scanf("%d", &index);
            if (index < 0 || index >= MAX_ARAC || dolu[index] == 0)
            {
                printf("Gecersiz kayit numarasi veya bu numaraya ait arac yok.\n");
                printf("\n1-Yeni Arac Girisi\n2-Arac Cikisi\n3-Programdan Cikis\nSeciminizi Yapiniz:");
                scanf("%d",&secim);
                continue;
            }
            while (1)
            {
                printf("%s plakali %s marka %s renk aracin cikis yaptigi saat ve dakikayi giriniz (Orn: 14 30): ",
                       plaka[index], marka[index], renk[index]);
                scanf("%d %d", &cikisSaat, &cikisDakika);
                if (cikisSaat < 0 || cikisSaat > 23 || cikisDakika < 0 || cikisDakika > 59)
                {
                    printf("Hatali saat veya dakika girdiniz! Saat 0-23, dakika 0-59 arasinda olmalidir.\n");
                    continue;
                }
                girisToplam = girisZaman[index][0]*60 + girisZaman[index][1];
                cikisToplam = cikisSaat*60 + cikisDakika;
                farkDakika = cikisToplam - girisToplam;
                if (farkDakika < 0)
                {
                    printf("Cikis saati giris saatinden once olamaz! Lutfen tekrar deneyiniz.\n");
                }
                else
                {
                    break;
                }
            }
            toplamSaat = farkDakika / 60;
            toplamDakika = farkDakika % 60;
            sureSaat = farkDakika / 60.0f;
            int tarifeIndex;
            if (sureSaat < 1.0f)
            {
                tarifeIndex = 0;
                ucret = tarifeler[0];
                printf("\n0-1 saat araligi ucretlendirmesi: %.2f TL\n", ucret);
            }
            else if (sureSaat < 3.0f)
            {
                tarifeIndex = 1;
                ucret = tarifeler[1];
                printf("\n1-3 saat araligi ucretlendirmesi: %.2f TL\n", ucret);
            }
            else if (sureSaat < 5.0f)
            {
                tarifeIndex = 2;
                ucret = tarifeler[2];
                printf("\n3-5 saat araligi ucretlendirmesi: %.2f TL\n", ucret);
            }
            else
            {
                tarifeIndex = 3;
                ucret = tarifeler[3];
                printf("\n5 saat ve uzeri saat ucretlendirmesi: %.2f TL\n", ucret);
            }
            printf("Toplam sure: %d saat %d dakika\n", toplamSaat, toplamDakika);
            printf("Odenecek tutar: %.2f TL\n", ucret);
            while (1)
            {
                printf("Odeme yontemini seciniz:\n");
                printf("1- Nakit\n");
                printf("2- Kart\n");
                printf("3- Borc\n");
                printf("Seciminiz: ");
                scanf("%d", &odemeSecim);
                
                if (odemeSecim >= 1 && odemeSecim <= 3)
                {
                    if (odemeSecim == 1)
                        printf("Nakit odeme alindi.\n");
                    else if (odemeSecim == 2)
                        printf("Kart ile odeme alindi.\n");
                    else
                        printf("Tutar borc olarak kaydedildi.\n");

                    rapor[tarifeIndex][odemeSecim-1]++;
                    break;
                }
                else
                {
                    printf("Gecersiz odeme secimi yapildi. Tekrar deneyiniz.\n");
                }
            }
            
            dolu[index] = 0; // yer artýk boþ
            printf("Islem tamamlandi.\n");
            
            printf("\n1-Yeni Arac Girisi\n2-Arac Cikisi\n3-Programdan Cikis\nSeciminizi Yapiniz:");
            scanf("%d",&secim);
            continue;
        }
        else if(secim == 3)
        {
            printf("Programdan cikis yapiliyor..\n");
            break;
        }
        else
        {
            printf("Hatali giris yaptiniz! Tekrar deneyiniz.\n");
            printf("\n1-Yeni Arac Girisi\n2-Arac Cikisi\n3-Programdan Cikis\nSeciminizi Yapiniz:");
            scanf("%d",&secim);
            continue;
        }
    }
    
    return 0;
}

