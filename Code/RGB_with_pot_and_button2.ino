//Iliadis Ilias © 2016 Arduino RGB Led Controller /w brightness and 6 modes


int fadeAmount = 3;           // RGB Fade step
int PotBrightness = 0;        // Potentiometer Value for Controled Brightness
int mode6col =9;              // At mode 6 begin from pin 9
int brightness = 0;           // Brightness Value
int potentiometerPin = A0;    // Potentiometer Pin Connected to A0 on Arduino
int button1Pin = 2;           // Button 1 Connected to Digital 2 on Arduino
int button2Pin = 3;           // Button 2 Connected to Digital 3 on Arduino
int BlueLed = 11;             // Blue Led Connected to PWM 11 on Arduino
int GreenLed = 10;            // Green Led Connected to PWM 10 on Arduino
int RedLed = 9;               // Red Led Connected to PWM 9 on Arduino
int RedFade;                  // Red Led Value for program 7
int GreenFade;                // Green Led Value for program 7
int BlueFade;                 // Blue Led Value for program 7
int button1val1;              // Value 1 for Button 1 checking if button is high or low 
int button1val2;              // Value 2 for Button 1 checking if button is high or low
int button1Value;             // Value for Button 1 Keep the value of button 1
int button2val1;              // Value 1 for Button 2 checking if button is high or low 
int button2val2;              // Value 2 for Button 2 checking if button is high or low 
int button2Value;             // Value for Button 2 Keep the value of button 2
int mode = 0;                 // Value for mode
int counter = 0;
int delay7 = 255;
boolean enable7 = true;

void setup() {
  Serial.begin(9600);         // Opens serial port, sets data rate to 9600 bps
  pinMode(BlueLed, OUTPUT);   // Set Pin as output
  pinMode(GreenLed, OUTPUT);  // Set Pin as output
  pinMode(RedLed, OUTPUT);    // Set Pin as output
  pinMode(button1Pin, INPUT); // Set Pin as input
  pinMode(button2Pin, INPUT); // Set Pin as input

}

void loop() 
{
  button1val1 = digitalRead(button1Pin);
  button2val1 = digitalRead(button2Pin);
  delay(20);
  button1val2 = digitalRead(button1Pin);
  button2val2 = digitalRead(button2Pin);
  if (button1val1 == button1val2) {
    if (button1val1 != button1Value) {
      if (button1val1 == LOW) {
        mode++;
        if (mode ==8) mode = 0;
        }
      }
    }
    button1Value = button1val1; 

    if (button2val1 == button2val2) {
        if (button2val1 != button2Value) {
          if (button2val1 == LOW) {
            mode--;
            if (mode ==-1) mode = 7;
            }
          }
        }
        button2Value = button2val1;
  
  PotBrightness = analogRead(potentiometerPin);
  

 /*Serial.print(button1val1);
 Serial.print(" ");

 Serial.print(button2val1);
 Serial.print(" ");
 
 Serial.print(PotBrightness);
 Serial.print(" ");
 
 Serial.print(button1Value);
 Serial.print(" ");

 Serial.print(button2Value);
 Serial.print(" ");
  
 Serial.print(mode);
 Serial.print(" ");

 Serial.print(mode6col);
 Serial.print(" ");*/



    if (mode == 0) { 
  analogWrite(RedLed, 0); 
  analogWrite(GreenLed, 0);
  analogWrite(BlueLed, 0);
  Serial.print(" Mode: ");
  Serial.print(mode);
  Serial.print(" Red Led State: ");
  Serial.print(digitalRead(RedLed));
  Serial.print(" Green Led State: ");
  Serial.print(digitalRead(GreenLed));
  Serial.print(" Blue Led State: ");
  Serial.print(digitalRead(BlueLed));
    } 

    if (mode == 1) {
  analogWrite(RedLed, brightness);
  analogWrite(GreenLed, brightness);
  analogWrite(BlueLed, brightness);
  brightness = brightness + fadeAmount;
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  } else {
    fadeAmount = +fadeAmount ;
    delay(30);
  }
  Serial.print("Brightness: ");
  Serial.print(brightness);
  Serial.print(" Fade = ");
  Serial.print(fadeAmount);
  Serial.print(" Mode:");
  Serial.print (mode);
   }

  if (mode == 2) { 
  analogWrite(RedLed, PotBrightness / 4); 
  analogWrite(GreenLed, PotBrightness / 4);
  analogWrite(BlueLed, PotBrightness / 4);
  Serial.print("PotBrightness: ");
  Serial.print(PotBrightness);
  Serial.print(" Mode: ");
  Serial.print(mode);
  }

  if (mode == 3) { 
  analogWrite(RedLed, PotBrightness / 4); 
  analogWrite(GreenLed, 0);
  analogWrite(BlueLed, 0);  
  Serial.print("PotBrightness: ");
  Serial.print(PotBrightness);
  Serial.print(" Mode: ");
  Serial.print(mode); 
   }

  if (mode == 4) { 
  analogWrite(RedLed, 0); 
  analogWrite(GreenLed, PotBrightness / 4);
  analogWrite(BlueLed, 0);    
  Serial.print("PotBrightness: ");
  Serial.print(PotBrightness);
  Serial.print(" Mode: ");
  Serial.print(mode); 
   }

  if (mode == 5) { 
  analogWrite(RedLed, 0); 
  analogWrite(GreenLed, 0);
  analogWrite(BlueLed, PotBrightness / 4);
  Serial.print("PotBrightness: ");
  Serial.print(PotBrightness);
  Serial.print(" Mode: ");
  Serial.print(mode); 
   }

   if (mode == 6)
   {
    mode6col++;
    if (mode6col ==12) mode6col = 9;

  delay(  random( 50 , 100 ) );
  digitalWrite( mode6col , HIGH );
  delay( 50 );
  digitalWrite( mode6col , LOW );
  Serial.print("Led Select: ");
  Serial.print(mode6col);
  Serial.print(" Mode: ");
  Serial.print(mode);
}
  delay7 = PotBrightness / 100;
  counter++;
  if (counter >= delay7) {
    counter = 0;
    enable7 = true;
  }

if (mode == 7 && enable7) {
  enable7 = false;
  
  RedFade = random(255);
  BlueFade = random(255);
  GreenFade = random(255);
  
  //Now mix the colors 
  
  analogWrite(RedLed,RedFade);
  analogWrite(BlueLed,BlueFade);
  analogWrite(GreenLed,GreenFade);
 
  Serial.print ("Coulor Value - ");
  Serial.print (" Red: ");
  Serial.print (RedFade);
  Serial.print (" Green: ");
  Serial.print (GreenFade);
  Serial.print (" Blue: ");
  Serial.println (BlueFade);
    
  //delay (500);
}
  
   delay(1);
Serial.println();
}
