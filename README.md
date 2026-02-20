Softmax Tabanlı İstemci Taraflı Yük Dengeleyici (C Simülasyonu)

Merhaba, bu proje Kırklareli Üniversitesi Yazılım Mühendisliği bölümü Algoritma Analizi ve Tasarımı dersi için hazırladığım bir yük dengeleme simülasyonudur.

Projenin Amacı
Bu projede, performansları (yanıt süreleri) zamanla değişen ve gürültülü veri üreten 5 farklı sunucuya gelen istekleri en verimli şekilde dağıtmayı hedefledim. Klasik Round-Robin veya Random algoritmalar yerine, sunucuların geçmiş performans verilerini analiz ederek karar veren Softmax Action Selection algoritmasını kullandım.

Neden Softmax?
Round-Robin algoritması sunucunun o anki yükünden veya performansından habersizdir; sadece sıradakine geçer. Softmax ise:
Hızlı yanıt veren sunucuyu daha sık seçer (Exploitation).
Diğer sunucuları tamamen unutmaz, performansları düzelirse diye onları da belirli aralıklarla test eder (Exploration).

Teknik Detaylar & Sorun Giderme
Dil: Performans ve düşük seviyeli bellek yönetimi avantajı için C dili tercih edilmiştir.

Nümerik Stabilite: Softmax algoritmasında kullanılan üstel fonksiyonların (exp) sebep olabileceği overflow (taşma) hatasını önlemek için Max-Subtraction tekniğini uyguladım.

Agentic Coding: Geliştirme sürecinde Gemini dil modelini bir yardımcı mühendis gibi kullanarak karşılaştığım derleyici ve kütüphane sorunlarını (özellikle Windows/MinGW ortamındaki PATH problemleri) çözdüm.

Nasıl Çalıştırılır?
Kodu main.c olarak kaydedin.

Terminalden derleyin:

Çalıştırın:

(Not: Eğer yerel derleyicide sorun yaşanırsa OnlineGDB üzerinden de hızlıca test edilebilir.)
