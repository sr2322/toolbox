#define input A0
int ontime,offtime,duty;
int count = 0;
double freq,period,average,maximum;

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
   if (count < 1) {
    maximum = freq;
    count++;
   }
   else if (count < 20) {
    average += freq/20.0;
    if (freq > maximum)
      maximum = freq;
    Serial.println(count);
    count++;
   }
  
   if (count == 20){
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on
    Serial.print("Average frequency is: "); Serial.println(average,2);
    Serial.print("Maximum frequency is: "); Serial.println(maximum,2);
    count++;
    }
  
   delay(1);
}
