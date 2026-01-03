# Otopark Kayıt ve Ücretlendirme Sistemi 🚗

Bu proje, **C programlama dili** kullanılarak geliştirilmiş, araç giriş–çıkış işlemlerini takip eden ve park süresine göre ücret hesaplayan **konsol tabanlı bir otopark otomasyon sistemidir**.

Proje, temel programlama kavramlarını (diziler, koşullar, döngüler, kullanıcıdan veri alma) gerçek hayattaki bir problem üzerinden uygulamak amacıyla hazırlanmıştır.

---

## 🎯 Projenin Amacı

* Otoparka giren araçların bilgilerini kayıt altına almak
* Araçların park süresini hesaplamak
* Park süresine göre ücretlendirme yapmak
* Farklı ödeme yöntemlerini (nakit, kart, borç) yönetmek

---

## ⚙️ Program Özellikleri

* Maksimum **100 araç** kapasitesi
* Araç bilgileri:

  * Plaka
  * Marka
  * Renk
  * Giriş saati ve dakikası
* Saat aralıklarına göre ücretlendirme:

  * 0–1 saat
  * 1–3 saat
  * 3–5 saat
  * 5 saat ve üzeri
* Araç çıkışında:

  * Toplam park süresi hesaplanır
  * Ücret otomatik belirlenir
* Ödeme seçenekleri:

  * Nakit
  * Kart
  * Borç

---

## 🧠 Programın Çalışma Mantığı

1. Program başlatıldığında kullanıcıdan tarife ücretleri alınır
2. Araç girişi sırasında araç bilgileri ve giriş saati kaydedilir
3. Araç çıkışında:

   * Giriş ve çıkış saatleri karşılaştırılır
   * Toplam süre dakika ve saat cinsinden hesaplanır
   * Süreye uygun ücretlendirme yapılır
4. Kullanıcı ödeme yöntemini seçer
5. İşlem tamamlanır ve otopark kaydı güncellenir

---

## 🛠 Kullanılan Teknolojiler

* C Programlama Dili
* Standart C Kütüphanesi (`stdio.h`)

---

## 📌 Notlar

* Program **konsol (terminal) tabanlıdır**
* Eğitim ve öğrenme amaçlı geliştirilmiştir
* Geliştirilmeye açıktır (dosya kaydı, tarih bazlı raporlar vb.)

---

## 👤 Geliştirici

* GitHub: @MrEfectus

---

> Bu proje, temel C programlama becerilerini pekiştirmek amacıyla hazırlanmıştır.
