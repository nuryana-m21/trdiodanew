#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>           
#include <Adafruit_SH1106.h>        
#define OLED_RESET 4
Adafruit_SH1106 display(OLED_RESET);


// Pin input analog
int analogInput = 3;
float vout = 0.0;
float vin = 0.0;
float R1 = 1000000.0; // resistansi R1 (100K)
float R2 = 100000.0;  // resistansi R2 (10K)
int value = 0;

void setup() {
  
  display.  // initialize with the I2C addr 0x3C (for the 128x32)
  begin(SH1106_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE); 
  display.setCursor(5,5);
  display.print("m21refairs");  
  display.setCursor(10,30);    
  display.print(" elektro"); 
  display.display();
  delay(300);
  
  // Set pin analog sebagai input
  pinMode(analogInput, INPUT);
}

void loop() {
  // Membaca nilai analog
  value = analogRead(analogInput);
  vout = (value * 51.0) / 1024.0; // Mengonversi ke voltase
  vin = vout / (R2 / (R1 + R2)); // Menghitung tegangan input

  // Menyaring noise (bisa sesuaikan ambang batas ini)
  if (vin < 0.09) {
    vin = 0.0;  // Mengatur tegangan menjadi nol jika terlalu rendah (indikasi noise)
  }

  // Menghapus buffer tampilan OLED
  display.clearDisplay();

  // Menampilkan di OLED
  // Menampilkan judul "M21 Volt Meter"
  

  // Menampilkan label "VOLTAGE"
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("VOLTAGE");

  // Menampilkan nilai tegangan dalam ukuran huruf yang lebih besar
  display.setTextSize(1);             // Ukuran teks lebih besar
  display.setCursor(20, 10);
  display.print(vin, 2);              // Menampilkan tegangan dengan 2 angka desimal
  display.print("V");

  // Menyegarkan buffer ke layar
  display.display();

  // Menampilkan nilai di LCD
   display.clearDisplay();
  display.setCursor(0, 0);   // Menempatkan kursor pada baris pertama
  display.print("DIODA:");  // Menampilkan label
  display.setCursor(0, 1);   // Menempatkan kursor pada baris kedua
  display.print(vin, 2);     // Menampilkan nilai tegangan dengan 2 angka desimal
  display.print("hf");       // Menambahkan satuan "V"





  // Delay sebelum memperbarui tampilan
  delay(500);
}
