#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inicializamos la pantalla LCD con su dirección
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Definir el pin del sensor de humedad
const int sensorPin = A0;  // Pin analógico donde está conectado el sensor

// Definir el umbral de humedad para regar (por debajo de este porcentaje se requiere riego)
const int umbralHumedad = 30;

void setup() {
  lcd.init();  // Inicializa la pantalla LCD
  lcd.backlight();  // Activa la retroiluminación

  // Configurar el pin como entrada
  pinMode(sensorPin, INPUT);

  lcd.setCursor(0, 0);
  lcd.print("Humedad suelo:");  // Texto fijo en la primera línea
}

void loop() {
  // Leer el valor del sensor de humedad
  int valorHumedad = analogRead(sensorPin);

  // Convertir el valor a porcentaje invertido (100% cuando está húmedo, 0% cuando está seco)
  int porcentajeHumedad = map(valorHumedad, 1023, 0, 0, 100);

  // Mostrar el valor de la humedad en la pantalla LCD
  lcd.setCursor(0, 1);  // Posicionar el cursor en la segunda línea
  lcd.print("Humedad: ");
  lcd.print(porcentajeHumedad);
  lcd.print(" %");

  // Revisar si la humedad es menor que el umbral para regar
  if (porcentajeHumedad < umbralHumedad) {
    lcd.setCursor(0, 0);  // Mover el cursor a la primera línea
    lcd.print("Regame :(      ");  // Mensaje de "Regame" con cara triste
  } else {
    lcd.setCursor(0, 0);  // Mover el cursor a la primera línea
    lcd.print("Todo bien :)   ");  // Mensaje de "Todo bien" con cara feliz
  }

  delay(2000);  // Actualizar cada 2 segundos
}
