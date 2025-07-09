*** City Name Frequency Tracker Using Circular Doubly Linked List ***

This automation reads city names from a plain text file (`sehirler.txt`) and counts the frequency of each word using a **circular doubly linked list**.

Each city name is stored in a node that tracks:
- How many times it appears in the file (frequency)
- The name itself
- Connections to previous and next nodes

The program also provides options to sort alphabetically, sort by frequency, and delete words by exact match or by containing a specific letter.  
It’s a great small-scale project for understanding how circular doubly linked lists work in practice.

### Data Structure Info:
-  **Type:** Circular Doubly Linked List  
-  **Structure:** `struct` with `next` and `prev` pointers (`sonraki`, `onceki`)  

### 🔧 Features:
- Load words from `sehirler.txt`
- Count word frequencies
- Display all city names and their frequencies
- Sort alphabetically
- Sort by frequency
- Delete by exact word
- Delete words containing a certain letter

---


*** Dairesel Çift Yönlü Bağlantılı Liste ile Şehir Adı Frekans Takibi ***


Bu C projesi, `sehirler.txt` adlı dosyadan şehir isimlerini okuyarak her bir ismin kaç kez geçtiğini **dairesel çift yönlü bağlı liste** kullanarak takip eder.

Her şehir ismi bir düğümde saklanır ve bu düğüm:
- Kaç kez geçtiğini (frekans),
- Şehrin kendisini,
- Bir önceki ve bir sonraki düğüme olan bağlantıları içerir.

Program, alfabetik sıralama, frekansa göre sıralama ve belirli bir harf içeren kelimeleri silme gibi gelişmiş işlemler de sunar.  
Bağlantılı liste mantığını uygulamalı olarak kavramak için güzel bir küçük projedir.

###  Veri Yapısı Bilgisi:
- **Tür:** Dairesel Çift Yönlü Bağlantılı Liste  
- **Yapı:** `struct` içinde `sonraki` ve `onceki` işaretçileri  


### 🔧 Otomasyon Özellikleri:
- `sehirler.txt` dosyasından kelime okuma
- Şehir isimlerinin kaç kez geçtiğini sayma
- Tüm kelimeleri ve frekanslarını listeleme
- Alfabetik sıralama
- Frekansa göre sıralama
- Belirli kelimeyi silme
- Belirli harfi içeren kelimeleri topluca silme


