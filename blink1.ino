// Baseado no exemplo: http://arduino.cc/en/Tutorial/BlinkWithoutDelay

// Definicao da classe
class myLed
{ 
  private:
  int _pin;
  long _interval;
  int _ledState;
  long _prevTime;
  
  public:
  
  myLed(int pin){
    _pin = pin;
    _interval = 1000;
    _ledState = LOW;
    _prevTime = 0;
  };
  
  void setup(){
    pinMode(_pin, OUTPUT);
  };
  
  void blinkme(){
    
    if(_ledState == LOW)
      _ledState = HIGH;
    else
      _ledState = LOW;  
      
    digitalWrite(_pin, _ledState);
  }  
  
  void process(){
    unsigned long currentTime = millis();
    if(currentTime - _prevTime > _interval){
      _prevTime = currentTime;
      _interval = random(50, 1000);    
      blinkme();
    }
  }
};

// Criando objetos
myLed pin_green(12);
myLed pin_red(13);

void setup(){
  Serial.begin(9600);
  pin_green.setup(); // Configurando variaveis default
  pin_red.setup(); // Configurando variaveis default
}

void loop(){
  // Processos com controle de intervalo independente
  pin_green.process();
  pin_red.process();
}
