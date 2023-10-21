const int numReadings = 10;    // Okumaların sayısı
int readings[numReadings];     // Okumaları depolamak için dizi
int index = 0;                 // Dizi indeksi
int total = 0;                 // Okumaların toplamı
int average = 0;               // Hareketli ortalama

void setup() {
  // İlgili ayarları yapın
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);  // Okuma yapılacak pin, A0'ı istediğiniz pini değiştirebilirsiniz

  // Hareketli ortalama hesaplaması
  total = total - readings[index];   // En eski okumayı toplamdan çıkar
  readings[index] = sensorValue;     // Yeni okumayı diziye ekle
  total = total + readings[index];   // Yeni okumayı toplama ekle
  index = (index + 1) % numReadings; // Dizi indeksini güncelle

  average = total / numReadings;     // Hareketli ortalama hesapla

  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print("   Moving Average: ");
  Serial.println(average);

  delay(100);  // İstenilen gecikmeyi ayarlayabilirsiniz
}
