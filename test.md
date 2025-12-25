Test Kılavuzu

1) Derleme ve testler

```bash
mkdir -p build
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

2) Uygulamayı çalıştırma (interaktif menü)

```bash
./scripts/run.sh
```

Menü adımları:
- 1: Ürünleri listele
- 2: Ürünü sepete ekle (ID ve miktar girin)
- 3: Sepeti göster
- 4: Sepetten çıkar (ürün ID girin)
- 5: Checkout — ödeme yöntemi seçin; ödeme başarılıysa sepet temizlenir
- 6: Sepeti temizle
- 7: Çıkış

3) Birim testleri
- `tests/test_shoppingcart.cpp` temel sepet testlerini içerir.
- Yeni test ekleyip `ctest` ile çalıştırabilirsiniz.

4) Hata ve geri bildirim
- Girdi doğrulama hataları `utils::getInt` tarafından yakalanır.
- Debug için `build` dizininde verbose derleme: `cmake --build build --verbose`.
