# Maceta Inteligente con Monitor de Humedad de Suelo

Este proyecto utiliza un sensor de humedad y una pantalla LCD I2C para monitorear los niveles de humedad en una maceta. Si la humedad del suelo está por debajo de un umbral predeterminado, la pantalla mostrará un mensaje indicando que es necesario regar la planta. De lo contrario, mostrará que todo está bien.

## Funcionalidad

- **Monitor de humedad:** El sensor mide la humedad del suelo en tiempo real.
- **Pantalla LCD I2C:** Muestra el porcentaje de humedad y mensajes personalizados cuando la planta necesita agua.
- **Indicaciones en pantalla:**
  - "Todo bien :)" si la humedad está en niveles adecuados.
  - "Regame :(" si la humedad es baja y la planta necesita agua.

## Materiales Necesarios
- Arduino (UNO, Nano, etc.)
- Pantalla LCD I2C (dirección 0x27)
- Sensor de humedad de suelo (resistivo o capacitivo)
- Cables jumper

## Esquema de Conexiones

### Pantalla LCD I2C:
- **GND** (LCD) → **GND** (Arduino)
- **VCC** (LCD) → **5V** (Arduino)
- **SDA** (LCD) → **A4** (Arduino UNO)
- **SCL** (LCD) → **A5** (Arduino UNO)

### Sensor de Humedad:
- **VCC** (Sensor) → **5V** (Arduino)
- **GND** (Sensor) → **GND** (Arduino)
- **OUT** o **A0** (Sensor) → **A0** (Arduino)

## Notas
- La dirección I2C de la pantalla LCD es **0x27**. Si usas una pantalla con otra dirección, asegúrate de modificarla en el código.
- El sensor de humedad se conecta al pin **A0** del Arduino para leer los datos analógicos.
