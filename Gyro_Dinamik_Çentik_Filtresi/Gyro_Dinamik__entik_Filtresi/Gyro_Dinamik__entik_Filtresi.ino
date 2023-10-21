// önceki okuma değerleri
float prevGyroX = 0;
float prevFilteredX = 0;

// çentik filtresi katsayıları
float alpha = 0.8;
float beta = 0.2;

// dinamik çentik filtresi fonksiyonu
float dynamicNotchFilter(float gyroX)
{
  // düşük geçişli filtre
  float filteredX = alpha * (prevFilteredX + gyroX - prevGyroX);

  // yüksek geçişli filtre
  float notchFilteredX = beta * (filteredX - prevFilteredX) + (1 - beta) * prevGyroX;

  // önceki okuma değerlerini güncelle
  prevGyroX = gyroX;
  prevFilteredX = filteredX;

  // filtrelenmiş değeri döndür
  return notchFilteredX;
}

void loop()
{
  // gyro_X değerini oku
  float gyro_X = readGyroX();

  // dinamik çentik filtresi uygula
  float filtered_X = dynamicNotchFilter(gyro_X);

  // işlemlere devam et
  // ...
}
