# Infix to Postfix Expression Converter and Evaluator  
# İnfiks İfadeyi Postfiks'e Çevirme ve Hesaplama Aracı

## 🇬🇧 English Description

This C project takes an infix mathematical expression (like `(2+3)*4`) from a file (`metin.txt`),  
converts it step by step into a **postfix expression** using a stack, and then evaluates the result using a second stack.

The postfix expression is stored in a **singly linked list**, and all operations are printed step by step for clarity.

The program is a great exercise in combining stack logic with linked lists, and understanding operator precedence and expression evaluation.

### Data Structure Info:
- **Stack** (array-based) for postfix conversion and evaluation  
- **Singly linked list** (`Node`) for storing postfix expression  


### Features:
- Reads an infix expression from a file
- Converts it step-by-step into postfix (Reverse Polish Notation)
- Evaluates the result of the postfix expression
- Prints every operation for educational purposes
- Handles basic arithmetic: `+`, `-`, `*`, `/`, and parentheses

---

## 🇹🇷 Türkçe Açıklama

Bu C projesi, `metin.txt` adlı dosyadan aldığı matematiksel infiks ifadeyi (örnek: `(2+3)*4`)  
adım adım **postfiks ifadeye** dönüştürür ve ardından sonucu hesaplar.

Postfiks ifade tek yönlü bağlı liste içinde saklanır, dönüşüm ve değerlendirme işlemleri ise **yığın (stack)** yapısı ile gerçekleştirilir.

Operatör önceliği, yığın kullanımı ve ifade değerlendirme konularını öğrenmek için mükemmel bir projedir.

###  Veri Yapısı Bilgisi:
-  **Yığın (Stack)** – Dizi tabanlı, dönüşüm ve hesaplamada kullanılır  
-  **Tek yönlü bağlı liste** – Postfix ifadeyi saklar  


### Özellikler:
- `metin.txt` dosyasından infiks ifade okur
- İfadeyi adım adım postfiks'e çevirir (ters Lehçe gösterimi)
- Postfiks ifadeyi hesaplar
- Tüm adımları ekrana yazdırarak öğretici deneyim sunar
- `+`, `-`, `*`, `/` ve parantezleri destekler

