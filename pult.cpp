#include «IRremote.h»
IRrecv irrecv(2); // указываем вывод, к которому подключен приемник
decode_results results;
int Relay = 4;
void setup()
{
pinMode(Relay, OUTPUT);
irrecv.enableIRIn(); // запускаем прием
}
void loop() {
if ( irrecv.decode( &results )) { // если данные пришли
switch ( results.value ) {
case 0x40BF807F:
digitalWrite( Relay, HIGH );
break;
case 0x40BF40BF:
digitalWrite( Relay, LOW );
break;
}
irrecv.resume(); // принимаем следующую команду
}
}
