//CLASSES:
//CLASS TO CONTROL PISTONS THROUGH RELAYS
class RelayControl{
  public:
  int relay;
  RelayControl(int relay){
    this->relay=relay;
  }
  RelayControl(){
    relay=LED_BUILTIN;
  }
  void Connect(){
    pinMode(relay,OUTPUT);
  }
  void on(){
    digitalWrite(relay,HIGH);
  }
  void off(){
    digitalWrite(relay,LOW);
  }
};


//CLASS TO SETUP AND RECIEVE BLUETOOTH SIGNAL FROM HC-05 MODULE
class Bluetooth{
  public:
  void Start(){
    Serial.begin(9600);
  }
  int getsignal(){
    if(Serial.available()>0){
      return Serial.read();
    }
    return 0;
    
  }
};


//METHODS TO CONTROL:
//TO CONTROL UP AND DOWN MOTION OF SYSTEM
void armcontrol(int blue,int relay){
  if(blue=='U'||blue=='u'){
    digitalWrite(relay,LOW);
  }
  if(blue=='D'||blue=='d'){
    digitalWrite(relay,HIGH);
  }
}

//TO CONTROL OPENING AND CLOSING OF CLAW
void clawcontrol(int blue,int relay){
  if(blue=='P'||blue=='p'){
    digitalWrite(relay,HIGH);
  }
  if(blue=='Q'||blue=='q'){
    digitalWrite(relay,LOW);
  }
}

//OVERALL CONTROL OF THE ENTIRE SYSTEM INCLUDING CLAW AND ARM USING BLUETOOTH SIGNAL
void control(int blue,int clawrelay,int armrelay){
  //blue is the value that has been recieved through hc05 module
  clawcontrol(blue,clawrelay);
  armcontrol(blue,armrelay);
}


//INITIALIZATION OF OBJECTS:
RelayControl armpiston(8);//for up down motion
RelayControl clawpiston(7);//for claw open close
Bluetooth signal;//to recieve bluetooth signals from phone bluetooth terminal app -> "Bluetooth Electronics"
int bval;//to store value recieved using bluetooth

//MAIN PROGRAM
void setup() {
  
  clawpiston.Connect();
  armpiston.Connect();
  signal.Start();
}

void loop() {
  bval=signal.getsignal();
  
   control(bval,clawpiston.relay,armpiston.relay);
  
}
