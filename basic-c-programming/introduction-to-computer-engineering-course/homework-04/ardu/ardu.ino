String veri;
int ledPin = 8; // 8 numaralı pin'e ledi taktık
int buttonPin = 7; // 7 numaralı pin'e button'u taktık
int buttonCounter = 0;  // Button click sayısını başlattık
int buttonFlag = LOW; // Buttonlarda ilk tıklama HIGH olur (anahtarsızlarda) o yüzden counter için gerekli olan kısmı LOW ile başlattıkki ilk arduino açıldığında button tıklamasını saymasın diye LOW'a ayarladık


void setup()
{
    Serial.begin(9600); // 9600'a baund hızını ayarlıyoruz
    pinMode(ledPin, OUTPUT); // Led için pin'e OUTPUT 
    pinMode(buttonPin, INPUT); // Button için pin'i INPUT'a ayarlıyoruz
}

void loop()
{
    // digitalRead ile buttondan gelen LOW/HIGH değerini öğreniyoruz
    if(digitalRead(buttonPin) != buttonFlag)
    {
        buttonFlag = digitalRead(buttonPin);
        buttonCounter++;
    }
   
    String bufferData;
    if (Serial.available()){ // Serial ekranda veri olup olmadığını kontrol ediyoruz
        veri = Serial.readString(); // Ekrana gelen veriyi String olarak okuyoruz

        for (int i = 2; i < 99; i++) // Komut olarak KomutKodu:Data olarak geldiği için 0 ve 1'i atlıyoruz 99'lik kontrolümüzü yapıyoruz 
        {
            if(veri[i] == ' ' || veri[i] == '\n')
            {
                // Veri yok ve satır atlama var ise for'u durdruyuoruz
                break;
            }
            bufferData += veri[i]; //Gelen verileri ilk 2 karakter haricinde yazdırıyoruz
        }

        int converData2Int = (int)veri[0] - '0'; // Gelen ilk verinin ilk karakterini Int'a çeviriyoruz .toInt() kullanmıyoruz çünkü ilk veriyi Char olarak alıyor.
        switch (converData2Int)
        {
            case 1:
                if (bufferData == String("on"))
                {
                    digitalWrite(ledPin, HIGH); // Led'i yakıyoruz
                }
                else if(bufferData == String("off"))
                {
                    digitalWrite(ledPin, LOW); // Led'i kapatıyoruz
                }
                break;
            
            case 3:
                if(bufferData == String("flash"))
                {
                    // 3 defa açıp kapama işlemini yapıyoruz
                    for (int i = 0; i < 3; i++)
                    {
                        digitalWrite(ledPin, HIGH);
                        delay(1000);
                        digitalWrite(ledPin, LOW);
                        delay(1000);
                    }
                }
                break;
            case 4:
                if(bufferData)
                {
                    // Gelen veriden aldığımız data'yı Int'e çeviriyoruz
                    int bufferNum = bufferData.toInt();
                    // Karesini alıp Serial ekrana yazdırıyoruz.
                    Serial.print(bufferNum * bufferNum);
                    // C kodu için sonlandırıcı ekliyoruz
                    Serial.print("|"); // Durdurma işareti
                }
            case 5:
                // Serial ekrana buton tıklama sayısını yazdırıyoruz
                Serial.println(buttonCounter);
                break;
            default:
                break;
       }        
  }
}
