#define SENSOR_PIN  A0
#define MAX_READ    1023.0
#define MAX_V       5.0
#define N           20
#define A           0.5
#define B           100

void setup() {
    // set SENSOR_PIN (A0) as analog input pin and initialize the serial monitor
    pinMode(SENSOR_PIN, INPUT);
    Serial.begin(9600);
}

float         tmp;
int           i = 0;  
unsigned long dt = 0;

void loop() {
    // print the time since the program started
    Serial.print(dt = millis());

    // measure the temperature 20 times and calculate the average
    for (i = 0, tmp = 0; i < N; i++) {      |\label{ln:ard:calc-start}|
        tmp += (((float)analogRead(SENSOR_PIN) / MAX_READ) * MAX_V - A) * B;
    }
    tmp = tmp / N;                          |\label{ln:ard:calc-end}|

    // print the measured temperature next to the corresponding time
    Serial.print(", ");
    Serial.println(tmp);

    // keep waiting until 30 seconds have passed 
    dt = millis() - dt;
    delay(30000 - dt);
}