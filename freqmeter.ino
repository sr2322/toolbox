#define input A0
int ontime,offtime,duty;
int count = 0;
double freq,period;
   
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off
  pinMode(input,INPUT);
  Serial.begin(115200);
}
void loop()
{
   ontime = pulseIn(input,HIGH);
   offtime = pulseIn(input,LOW);
   period = ontime+offtime;
   freq = 1000000.0/period;
   if (count < 20) {
    Serial.print(freq); Serial.println("");
    count++;
   }
  
   else {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on
   }
  
   delay(1);
}
