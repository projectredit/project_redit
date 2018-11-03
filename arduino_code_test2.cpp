#include <HybridObject.h>
HybridObject obj;
 
int counter =0;
 
void setup() {
    obj.developer();
    obj.add("test", "led");
    obj.add("test", "generator");
    obj.add("test","light sensor");
}
 
void loop() {
 
    analogWrite(13, obj.read("test", "led")*255);
 
    counter+=30;
    if(counter>1023)
    {
        counter = 0;
    }
 
    obj.write("test", "generator",(float)obj.map(counter,0,1023));
    obj.write("test", "light sensor",(float)obj.map(counter,0,1023));
 
    delay(30);
}
