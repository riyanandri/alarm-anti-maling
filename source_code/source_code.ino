/////////////////////////////////////////
//.........Alaram Anti Maling..........//
/////////////////////////////////////////

///// DEKLARASI ///////
int i,x;
boolean gerakan = false;
int buzzer = 7;
int LEDGreen = 8;
int LEDRed = 9;

///// SETUP //////////
void setup() {
    Serial.begin (9600);
    pinMode (buzzer, OUTPUT); //buzzer sebagai output
    pinMode (LEDRed, OUTPUT); //LED sebagai output
    pinMode (LEDGreen, OUTPUT); //LED sebagai output
    pinMode (3, INPUT); //koneksi ke output PIR

    digitalWrite (buzzer, LOW); //Full down, berikan tegangan awal LOW
    digitalWrite (LEDRed, LOW);
    digitalWrite (LEDGreen, LOW);

    //memerlukan waktu 15-30 detik untuk kalibrasi
    Serial.print ("Kalibrasi sensor..");
    for (i=1; i<=15; i++) {
        delay (1000);
        Serial.print (0+i); 
        Serial.print ('.');
        }
    Serial.println ("Sensor siap digunakan");
}

void loop() {
    x=digitalRead (3);
    if (x==HIGH && !gerakan) {
    gerakan = !gerakan;
    Serial.println("Ada gerakan...");
    digitalWrite (buzzer, HIGH);
    digitalWrite (LEDRed, HIGH);
    digitalWrite (LEDGreen, LOW);
    delay (10000); //lama waktu nyala alaram
    }

    if (x==LOW && gerakan) {
    gerakan = !gerakan;
    Serial.println ("Diam...");
    digitalWrite (buzzer, LOW);
    digitalWrite (LEDRed, LOW);
    digitalWrite (LEDGreen, HIGH);
    }
}
