const uint8_t pinPasoPorCero = 2;
const uint8_t pinDisparo = 5;
const uint8_t duracionDisparo = 700;

uint16_t duracionSemicicloSinDisparo = 7500;
String inputString = "";
bool stringComplete = false;

                                    
void setup()
{
    Serial.begin(115200);

    pinMode(pinDisparo, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(pinPasoPorCero), crucePorCero, RISING);
}


void loop()
{          
  if(stringComplete)
  {
    int Brillo = constrain(inputString.toInt(), 0, 100);
    duracionSemicicloSinDisparo = map(Brillo, 0, 100, 7500, 800);

    inputString = "";
    stringComplete = false;
    }

                       
} 


void crucePorCero()
{

  delayMicroseconds(duracionSemicicloSinDisparo);
  digitalWrite(pinDisparo, HIGH);
  delayMicroseconds(duracionDisparo);
  digitalWrite(pinDisparo, LOW);
  
}

void serialEvent()
{
  while (Serial.available() > 0)
  {
    char inChar = (char)Serial.read();
    if(inChar == '\n')
      stringComplete = true;
    else 
      inputString += inChar;
    }
  
  }
