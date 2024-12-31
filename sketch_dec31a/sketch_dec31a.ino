#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display;  

int giris = A1;//A1 giriş olarak tanımladık

void setup()   
  {       
  pinMode(giris,INPUT);//analog girişi tanımlıyoruz 
         
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  Wire.begin();
    delay(3000);
    display.display();
    display.clearDisplay();
  }

void loop() {  


  int okunan = analogRead(giris);//okunan analog değerini onunan değişkenine atıyoruz
  
  if(okunan == 1)
  {
    //kod kafalar altındaki çizgi oluşumu
    display.setTextColor(WHITE);
    display.setTextSize(1);//yazı boyutu 1 
    display.setCursor(0,0);
    display.println("TR DIODA");

    
    display.setCursor(20,23);
     display.display();
     display.clearDisplay();
     delay(100);
     return; //okunan değer sıfır olduğu sürece burada kalıyor
  }

  float R1 = 999;//sabit direnç değerimiz 10 K
  float VT = 10.0;//vın değerimiz 5 v
  float V1 = okunan * VT / 1023; //vout değerimizi bulduk
  float R2 = (R1 * (VT - V1)) / V1;//Formulle takılan direnç değerimizi bulduk
  
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.println("TR DIDA");
  
  display.setCursor(5,10);
  display.println("DHFE =");
  display.setCursor(51,10);
  display.println(R2);
  

  display.display();
   display.clearDisplay();
  delay(100);
  
}