#include <SimpleModbusSlave.h>

#define  DgOut1 8
#define  DgOut2 11
#define  DgOut3 12
#define  DgOut4 A2
#define  DgOut5 A3

#define  DgIn1 2
#define  DgIn2 3
#define  DgIn3 4
#define  DgIn4 5
#define  DgIn5 6
#define  DgIn6 7

#define AnOut1 9
#define AnOut2 10

#define AnIn1 A0
#define AnIn2 A1


enum 
{     
  AI0,   
  AI1, 
  AO0, 
  AO1, 
  DI0, 
  DI1, 
  DI2, 
  DI3, 
  DI4, 
  DI5, 
  DO0, 
  DO1, 
  DO2, 
  DO3, 
  DO4, 
  HOLDING_REGS_SIZE
};

unsigned int holdingRegs[HOLDING_REGS_SIZE];

void setup()
{
 modbus_configure(&Serial, 9600, SERIAL_8N2, 1, 2, HOLDING_REGS_SIZE, holdingRegs);

  modbus_update_comms(9600, SERIAL_8N2, 1);
  
  pinMode(DgOut1, OUTPUT);
  pinMode(DgOut2, OUTPUT);
  pinMode(DgOut3, OUTPUT);
  pinMode(DgOut4, OUTPUT);
  pinMode(DgOut5, OUTPUT);
  
  pinMode(AnOut1, OUTPUT);
  pinMode(AnOut2, OUTPUT);
  
  pinMode(AnIn1, INPUT);
  pinMode(AnIn2, INPUT);
  
  pinMode(DgIn1, INPUT);
  pinMode(DgIn2, INPUT);
  pinMode(DgIn3, INPUT);
  pinMode(DgIn4, INPUT);
  pinMode(DgIn5, INPUT);
  pinMode(DgIn6, INPUT);
}

void loop()
{
  modbus_update();
  
  holdingRegs[AI0] = analogRead(AnIn1); 
  holdingRegs[AI1] = analogRead(AnIn2); 

  analogWrite(AnOut1, holdingRegs[AO0]); 
  analogWrite(AnOut2, holdingRegs[AO1]); 
  
  holdingRegs[DI0] = digitalRead(DgIn1); 
  holdingRegs[DI1] = digitalRead(DgIn2); 
  holdingRegs[DI2] = digitalRead(DgIn3); 
  holdingRegs[DI3] = digitalRead(DgIn4); 
  holdingRegs[DI4] = digitalRead(DgIn5); 
  holdingRegs[DI5] = digitalRead(DgIn6); 
  
  digitalWrite(DgOut1, holdingRegs[DO0]); 
  digitalWrite(DgOut2, holdingRegs[DO1]); 
  digitalWrite(DgOut3, holdingRegs[DO2]); 
  digitalWrite(DgOut4, holdingRegs[DO3]); 
  digitalWrite(DgOut5, holdingRegs[DO4]); 
}