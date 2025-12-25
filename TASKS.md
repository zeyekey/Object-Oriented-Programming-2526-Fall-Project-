## Görev Dağılımı

Ekip üyeleri (eşit paylaşımla):
- Sena Ülkü
- Zeynep Kurt
- Hayri Baran Vural
- Muhammed Mehmet Gökçe
- Yusuf Göç

Projede tamamlanması gereken ana işler ve kişi bazında görevler (eşit paylaşıldı):

1) Proje iskeleti ve CMake
   - Sorumlu: Sena Ülkü
   - Açıklama: `CMakeLists.txt` kurulumu, `scripts/run.sh` doğrulama, derleme akışı.

2) Modeller (Product, Book, Magazine, MusicCD, Customer)
   - Sorumlu: Zeynep Kurt
   - Açıklama: Sınıf tanımları, `info()` metotları, temel alanların doğruluğu.

3) Sepet ve sipariş akışı (ProductToPurchase, ShoppingCart)
   - Sorumlu: Hayri Baran Vural
   - Açıklama: `addItem`, `removeByProductId`, `clear`, toplam hesaplama ve çıktı formatı.

4) Mağaza uygulaması ve menü (Inventory, BookstoreApp)
   - Sorumlu: Muhammed Mehmet Gökçe
   - Açıklama: `seed()`, interaktif menü, kullanıcı girdisi entegrasyonu.

5) Ödeme ve yardımcılar (Payment, CreditCard, Cash, Check, utils)
   - Sorumlu: Yusuf Göç
   - Açıklama: Ödeme sınıfları, `utils::getString/getInt`, `util::formatCurrency` doğrulanması.

6) Birim testleri ve CI entegrasyonu
   - Sorumlu: Sena Ülkü
   - Açıklama: GoogleTest entegrasyonu, temel testler (`tests/`), `ctest` akışı.

7) Hata yönetimi ve giriş doğrulama
   - Sorumlu: Zeynep Kurt
   - Açıklama: `Input` doğrulama genişletme, kullanıcı hataları, sınırlar.

8) Persistans ve ek özellikler
   - Sorumlu: Hayri Baran Vural
   - Açıklama: Inventory kaydet/yükle (JSON), ilave ürün alanları.

9) Dokümantasyon ve kullanım kılavuzu
   - Sorumlu: Muhammed Mehmet Gökçe
   - Açıklama: `README.md`, `docs/` güncellemeleri, test talimatları.

10) Son testler, paketleme ve release hazırlığı
   - Sorumlu: Yusuf Göç
   - Açıklama: `scripts/run.sh` doğrulama, release tag, versiyon güncelleme.

Not: Görev listesi eşit sayıda maddelerle (10 madde) bölünmüştür; gerekirse maddeleri daraltıp her bir kişiye farklı sayıda alt-görev verilebilir.
