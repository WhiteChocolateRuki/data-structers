# Simple Web Browser Navigation Simulator Using Stacks  

This project is a console-based web browser simulator written in C.  
It uses **two stack structures** to emulate the "Back" and "Forward" navigation functionality found in modern browsers.

- One stack (`backStack`) is used to store previously visited pages.
- The other stack (`forwardStack`) is used to store pages you can go forward to.

When you navigate to a new page, the current page is pushed to the back stack.  
When you go back, the current page moves to the forward stack, and the previous page is loaded.  
If you go forward, the process reverses.

A perfect example of how stacks can be used in real-world applications like browser navigation.

###Data Structure Info:
- **Stack (Yığın)** – Two stacks implemented as 2D char arrays
-No linked list, queue, or recursion

### Features:
- Navigate to a new website
- Go back to the previous website
- Move forward to the next website
- Shows current active website at all times
- Simulates real browser navigation logic

---


***Yığın (Stack) Kullanarak Basit Web Tarayıcı Geçmişi Simülasyonu***

Bu proje, C diliyle yazılmış konsol tabanlı bir web tarayıcı geçmişi simülasyonudur.  
Modern tarayıcılarda bulunan “Geri” ve “İleri” işlevlerini taklit etmek için **iki adet yığın (stack)** kullanılır.

- Birinci yığın (`yigin_g`) geçmiş siteleri tutar.
- İkinci yığın (`yigin_i`) ileri gidilebilecek siteleri saklar.

Yeni bir siteye gidildiğinde, mevcut site geri yığına eklenir.  
Geri tuşuna basıldığında, mevcut site ileri yığına eklenir ve bir önceki site yüklenir.  
İleri tuşuna basıldığında bu işlem tersine işler.

Gerçek dünya problemlerinde yığınların nasıl kullanılabileceğine dair güzel bir örnektir.

### Veri Yapısı Bilgisi:
- **Yığın (Stack)** – 2 boyutlu karakter dizileriyle (2D char array) implemente edilmiştir  


### 🔧 Özellikler:
- Yeni bir web sitesine gitme
- Önceki siteye geri dönme
- Sonraki siteye ileri gitme
- Her zaman mevcut siteyi gösterme
- Tarayıcı geçmiş mantığını birebir taklit etme


