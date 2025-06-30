<h1 align="center"> Proyecto de robot autónomo para la WRO - Categoría Futuros Ingenieros </h1>

<p align="center"> <img src="https://github.com/DexterTaha/WRO-2024-FUTURE-ENGINEERS/assets/130682580/d9385136-f971-4c95-ba80-ffc14f7c0a4e" alt="banner" width="1500"> </p>

<br>
<h1 align="center"> La Olimpiada de Robótica Mundial </h1>

<p align="center"> <img src="https://www.wroguatemala.org/wp-content/uploads/2023/07/Sticker_100x1006.png" width="300"> </p>
<br>

La Olimpiada Mundial de Robótica (WRO) es una prestigiosa competencia internacional de robótica que estimula la imaginación de estudiantes de todo el mundo. Reta a los participantes a demostrar su creatividad, capacidad para resolver problemas y destreza técnica en el diseño y la programación de robots para diversas tareas y desafíos.

Una de las categorías más dinámicas de WRO es la de Futuros Ingenieros. En ella, los participantes tienen la tarea de desarrollar soluciones innovadoras a problemas reales mediante robótica y automatización. Esta categoría sirve como caldo de cultivo para futuros innovadores, incentivando el pensamiento crítico y creativo de los estudiantes, sentando las bases para una nueva generación de ingenieros y tecnólogos.

Este año, la categoría Futuros Ingenieros presenta un reto apasionante: crear un coche autónomo. Este reto impulsa a los participantes a explorar la vanguardia de la robótica, añadiendo complejidad e innovación a una competición ya de por sí emocionante.

# 📁 Estructura del Repositorio

| Directorio      | Tipo       | Descripción | Requerido |
|----------------|------------|-------------|-----------|
| **/t-photos**  | 📸 Fotos   | - 1 foto oficial del equipo (`equipo_oficial.jpg`)<br>- 1 foto informal grupal (`equipo_divertido.jpg`) | ✅ Obligatorio |
| **/v-photos**  | 🖼️ Fotos  | - 6 vistas técnicas del robot (frontal, lateral, posterior, superior, inferior, detalle)<br>- Resolución mínima: 1920x1080<br>- Formato: `robot_[ángulo].jpg` | ✅ Obligatorio |
| **/video**     | 🎥 Multimedia | Archivo `video.md` con:<br>- Enlace a YouTube (público/unlisted)<br>- 30+ segundos de demostración<br>- Debe mostrar navegación autónoma | ✅ Obligatorio |
| **/schemes**   | 📐 Diagramas | Diagramas en JPEG/PNG/PDF de:<br>- Esquema electrónico<br>- Conexiones<br>- Distribución mecánica | ✅ Obligatorio |
| **/src**       | 💻 Código  | Estructura recomendada:<br>- `/firmware` (código Arduino/ESP32)<br>- `/vision` (procesamiento imágenes)<br>- `/docs` (manuales técnicos) | ✅ Obligatorio |
| **/models**    | 🖨️ 3D/CNC | Archivos opcionales:<br>- Formatos: STL, DXF, STEP<br>- Organizados por componente | ❌ Opcional |
| **/other**     | 📄 Extra   | Documentación adicional:<br>- Protocolos comunicación<br>- Reporte técnico | ❌ Opcional |

## Objetivo del proyecto
El objetivo de este proyecto es diseñar, construir y programar un robot autónomo utilizando hardware de código abierto, toma de decisiones basada en sensores y algoritmos de movimiento adaptativos. Nuestro robot analiza dinámicamente su entorno mediante procesamiento integrado y retroalimentación de sensores, garantizando una navegación eficiente mientras supera obstáculos de forma autónoma.

Objetivos principales:
* Reforzar la resolución de problemas y el trabajo en equipo en la ingeniería del mundo real.
* Aplicar el control de movimiento basado en sensores para una navegación precisa.
* Desarrollar una estrategia de conducción autónoma optimizada para retos de robótica.
* Contribuir a la robótica de código abierto documentando nuestra solución para futuros equipos.


## Componentes Utilizados

Nuestro robot está construido con hardware de precisión para garantizar estabilidad, capacidad de respuesta y optimización energética.

<table>
  <tr>
    <th width="150">Componente</th>
    <th>Imagen</th>
    <th>Descripción Técnica</th>
  </tr>
  
  <tr>
    <td><strong>Arduino Uno</strong></td>
    <td><img src="https://www.videoycomputacion.com.ve/5808-large_default/arduino-uno-r3-atmega-dip-328p-chip-grde.jpg" width="120" alt="Arduino Uno"></td>
    <td>Microcontrolador principal para gestión de sensores (I2C, digital) y control de movimiento (PWM).<br>
    <em>Especificaciones:</em> ATmega328P, 16MHz, 32KB flash, 14 E/S digitales</td>
  </tr>

  <tr>
    <td><strong>Puente H L298N</strong></td>
    <td><img src="https://acdn-us.mitiendanube.com/stores/975/836/products/17637-mla20140879523_082014-o-8f0828cf82de8cee6415565106613680-480-0.jpg" width="120" alt="L298N H-Bridge"></td>
    <td>Controlador dual para motores (dirección y velocidad).<br>
    <em>Especificaciones:</em><br>
    • Voltaje lógico: 5V<br>
    • Voltaje motor: +5V a +35V<br>
    • Corriente pico: 2A por canal<br>
    • Potencia máxima: 25W<br>
    • Protección: Diodos supresores integrados<br>
    <em>Conexión Arduino:</em><br>
    • ENA/ENB → Pines PWM (velocidad)<br>
    • IN1/IN2 → Pines digitales (dirección)<br>
    • +12V → Fuente externa 9V<br>
    <em>Uso en proyecto:</em> Control bidireccional del motor NXT</td>
  </tr>

<tr>
  <td><strong>Motor DC con Caja Reductora</strong></td>
  <td><img src="https://robot.com.ve/wp-content/uploads/2021/08/Motorreductor-con-caja-reductora-6V-1-48-1.jpg" width="120" alt="Motor DC"></td>
  <td>Motor de corriente continua compacto con sistema de reducción de engranajes integrado.<br>
  <em>Especificaciones:</em><br>
  • Voltaje: 6–12 V DC<br>
  • Relación de engranaje: varía según el modelo (ej. 48:1)<br>
  • Eje: tipo D de 6 mm<br>
  • Optimizado para aplicaciones robóticas que requieren torque y control<br>
  <em>Conexión:</em> Dos cables (rojo: +, negro: -) listos para conectarse a un controlador L298N o puente H similar</td>
</tr>
  
  <tr>
    <td><strong>ESP32-WROOM-32D</strong></td>
    <td><img src="http://wiztech.com.ua/wp-content/uploads/2024/04/ESP32-wroom-32D.webp" width="120" alt="ESP32-WROOM-32D"></td>
    <td>Módulo Wi-Fi/Bluetooth para IoT y sistemas embebidos.<br>
    <em>Características:</em><br>
    • Procesador dual-core a 240MHz<br>
    • 4MB Flash, 520KB SRAM<br>
    • Conectividad: Wi-Fi 802.11 b/g/n y Bluetooth 4.2<br>
    • Bajo consumo energético con múltiples modos sleep<br>
    • Interfaces: 34 GPIO, UART, SPI, I2C, ADC<br>
    <em>Uso en proyecto:</em> Comunicación inalámbrica y procesamiento paralelo</td>
  </tr>

  <tr>
    <td><strong>Sensores VL53L0X</strong></td>
    <td><img src="https://naylampmechatronics.com/1620-superlarge_default/sensor-vl53l0x-de-tof.jpg" width="120" alt="VL53L0X"></td>
    <td>Sensor de distancia por Time-of-Flight (ToF).<br>
    <em>Rango:</em> 50-1200mm, precisión ±3%, interfaz I2C<br>
    <em>Uso:</em> Detección de obstáculos y navegación autónoma</td>
  </tr>

  <tr>
    <td><strong>Protoboard</strong></td>
    <td><img src="https://eloctavobit.com/imagenes/2023/06/64799b86081a2.webp" width="120" alt="Breadboard"></td>
    <td>Plataforma de prototipado para conexiones rápidas.<br>
    <em>Configuración:</em> 830 puntos, buses de alimentación distribuidos</td>
  </tr>

  <tr>
    <td><strong>Reguladores de Voltaje</strong></td>
    <td><img src="https://robot.com.ve/wp-content/uploads/2021/08/AR0202-lm317-_v1.jpg" width="120" alt="LM7805 Regulator"></td>
    <td>Sistema de gestión de energía.<br>
    <em>Modelos:</em> LM7805 (5V, 1A), LM1117 (3.3V)<br>
    <em>Accesorios:</em> Disipadores de calor para alta corriente</td>
  </tr>

  <tr>
    <td><strong>Servomotor SG90</strong></td>
    <td><img src="https://www.aranacorp.com/wp-content/uploads/towerpro-servo-sg90.jpg" width="120" alt="SG90 Servo"></td>
    <td>Actuador para control direccional y mecanismos auxiliares.<br>
    <em>Especificaciones:</em> 4.8-6V, rotación 180°, torque 1.8kg/cm<br>
    <em>Conexión:</em> Alimentación + PWM (50Hz)</td>
  </tr>

  <tr>
    <td><strong>Pixy2 Camera</strong></td>
    <td><img src="https://m.media-amazon.com/images/I/71ciGcchSaL.jpg" width="120" alt="Pixy2 Camera"></td>
    <td>Sistema de visión artificial para detección de objetos por color.<br>
    <em>Especificaciones:</em><br>
    • Procesador dual-core NXP LPC4330 (200MHz)<br>
    • Resolución: 1296x976 (RAW), 316x208 (procesada)<br>
    • Firmas de color: 7 simultáneas<br>
    • Interfaces: SPI, I2C, UART, USB<br>
    • Consumo: 140mA @ 5V<br>
    <em>Conexión:</em> SPI (recomendado) + Alimentación 5V<br>
    <em>Uso en proyecto:</em> Detección de objetivos mediante códigos de color</td>
  </tr>
</table>


## Procesamiento de sensores y navegación autónoma
El sensor VL53L0X desempeña un papel crucial en la detección de obstáculos, permitiendo al robot medir la distancia en tiempo real y ajustar su movimiento en consecuencia. El robot sigue un algoritmo de movimiento impulsado por sensores, perfeccionando continuamente la velocidad de su motor y la lógica de navegación.

* Detección de obstáculos: El sensor de distancia identifica objetos y ajusta dinámicamente la trayectoria del robot.
* Entrada de cámara basada en ESP32: Procesa imágenes en tiempo real para el análisis del terreno y las decisiones de movimiento.
* Lógica de control del motor: El Arduino Uno gestiona el control de velocidad mediante señales PWM y ajustes de servo.

## Software y herramientas de desarrollo necesarios
Herramientas de programación y compilación:
* Arduino IDE - Se utiliza para codificar, compilar y cargar firmware.
* Tinkercad - Herramienta de simulación electrónica virtual para la creación de prototipos de circuitos.

Bibliotecas esenciales:
* Wire.h - Soporta la comunicación de sensores y la recopilación de datos.
* Adafruit_VL53L0X.h - Controla las operaciones de medición de distancia.
* Servo.h - Gestiona el posicionamiento del servo motor y la retroalimentación de control.

## Instrucciones de instalación y funcionamiento
Cómo desplegar el firmware del robot:
1. Descarga el IDE de Arduino e instala todos los drivers necesarios para la placa.
2. Conecta el Arduino Uno vía USB y asegúrate de que el IDE lo reconoce correctamente.
3. Instala todas las librerías necesarias (VL53L0X, Servo, Wire, Adafruit Motor Control).
4. Compilar y cargar el firmware, inicializando los algoritmos de movimiento del sensor.
5. Probar el rendimiento del sensor de distancia utilizando las lecturas del Serial Monitor.
6. Ejecutar pruebas de navegación autónoma y afinar las respuestas de movimiento.

## Diagnóstico y evaluación
Pruebas de validación del rendimiento:
* Prueba de precisión del sensor: Confirma la fiabilidad de la detección de obstáculos y la precisión de la distancia.
* Calibración de la velocidad del motor: Garantiza la suavidad de las transiciones de movimiento y los ajustes de velocidad.
* Alineación del servomotor: Evalúa el tiempo de reacción y la precisión de los ángulos para un manejo adicional del movimiento.
* Navegación basada en cámaras: Evalúa las capacidades de reconocimiento del terreno y detección de bordes en tiempo real.

## Estrategia competitiva y adaptabilidad
Nuestro robot está diseñado para reaccionar dinámicamente en entornos de competición, garantizando la máxima precisión y adaptabilidad:

* Información del sensor en tiempo real: El robot ajusta el movimiento al instante en función de las mediciones de distancia entrantes.
* Detección de bordes basada en visión: El ESP32 procesa las entradas de la cámara, determinando rutas seguras y evitando barreras.
* Gestión del movimiento con eficiencia energética: Reduce el exceso de movimiento para optimizar los ciclos de navegación.
* Lógica de control configurable: Ajusta la capacidad de respuesta del servo y la calibración del motor según sea necesario.
Desarrollo futuro y contribución
## Desarrollo futuro y contribución
Nuestra visión a largo plazo para el proyecto incluye:

* Ampliar las capacidades de control del servomotor para una mayor precisión en los ajustes de movimiento.
* Optimizar el seguimiento de objetos basado en visión de ESP32 para escenarios de competición avanzados.
* Desarrollar estrategias de gestión inteligente de la batería para mejorar la longevidad y la eficiencia operativa.
* Publicar documentación de código abierto sobre soluciones de navegación autónoma basadas en sensores.

