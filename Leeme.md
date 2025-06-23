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
| **/other**     | 📄 Extra   | Documentación adicional:<br>- Protocolos comunicación<br>- Especificaciones técnicas<br>- Guías de calibración | ❌ Opcional |

## Objetivo del proyecto
El objetivo de este proyecto es diseñar, construir y programar un robot autónomo utilizando hardware de código abierto, toma de decisiones basada en sensores y algoritmos de movimiento adaptativos. Nuestro robot analiza dinámicamente su entorno mediante procesamiento integrado y retroalimentación de sensores, garantizando una navegación eficiente mientras supera obstáculos de forma autónoma.

Objetivos principales:
* Reforzar la resolución de problemas y el trabajo en equipo en la ingeniería del mundo real.
* Aplicar el control de movimiento basado en sensores para una navegación precisa.
* Desarrollar una estrategia de conducción autónoma optimizada para retos de robótica.
* Contribuir a la robótica de código abierto documentando nuestra solución para futuros equipos.

## Quiénes somos
Somos un equipo del Instituto Técnico Jesús Obrero (ITJO) de Venezuela, apasionados por la robótica y la automatización.
Miembros del equipo:

* José Lapeira - Experto en programación, sistemas electrónicos y desarrollo de software.
* Keiner Duran - Especializado en optimización de algoritmos, integración de IA robótica y diseño de lógica de movimiento.
* Mauricio Sánchez - especializado en firmware Arduino, control de motores y aplicaciones electrónicas.

## Componentes Utilizados

Nuestro robot está construido con hardware de precisión para garantizar estabilidad, capacidad de respuesta y optimización energética.

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
    <td>Microcontrolador principal que gestiona la entrada de sensores (I2C, digital) y control de movimiento (PWM).<br>
    <em>Especificaciones:</em> ATmega328P, 16MHz, 32KB flash, 14 E/S digitales</td>
  </tr>

  <tr>
    <td><strong>Puente H L298N</strong></td>
    <td><img src="https://acdn-us.mitiendanube.com/stores/975/836/products/17637-mla20140879523_082014-o-8f0828cf82de8cee6415565106613680-480-0.jpg" width="120" alt="Puente H L298N"></td>
    <td>Controlador de motores de doble canal para dirección y velocidad.<br>
    <em>Especificaciones:</em><br>
    • Voltaje lógico: 5V<br>
    • Voltaje motor: +5V a +35V<br>
    • Corriente pico: 2A por canal<br>
    • Potencia máxima: 25W<br>
    • Protección: Diodos de supresión<br>
    <em>Conexión con Arduino:</em><br>
    • ENA/ENB → Pines PWM (velocidad)<br>
    • IN1/IN2 → Pines digitales (dirección)<br>
    • +12V → Fuente externa 9V<br>
    <em>Uso en el proyecto:</em> Control bidireccional del motor NXT</td>
  </tr>

  
  <tr>
    <td><strong>Adaptador NXT a L298N</strong></td>
    <td><img src="https://bricksandminifigshuntsville.com/cdn/shop/files/53787.png?v=1735750369" width="120" alt="Adaptador NXT"></td>
    <td>Interface de conexión entre motor LEGO y controladores estándar.<br>
    <em>Configuración:</em><br>
    • Cable RJ12 a terminales dupont<br>
    • Mapeo de pines: Negro (-), Rojo (+)<br>
    • Longitud: 50cm<br>
    <em>Modificación requerida:</em> Corte y pelado de cables para conexión directa al L298N</td>
  </tr>

  <tr>
    <td><strong>ESP32 con cámara</strong></td>
    <td><img src="https://asset.conrad.com/media10/isa/160267/c1/-/en/002332111PI00/image.jpg?x=400&y=400&format=jpg&ex=400&ey=400&align=center" width="120" alt="ESP32-CAM"></td>
    <td>Módulo de visión artificial para navegación.<br>
    <em>Capacidades:</em> Dual-core 240MHz, OV2640 (2MP), WiFi/Bluetooth, compatible con OpenCV</td>
  </tr>

  <tr>
    <td><strong>Sensor VL53L0X</strong></td>
    <td><img src="https://naylampmechatronics.com/1620-superlarge_default/sensor-vl53l0x-de-tof.jpg" width="120" alt="VL53L0X"></td>
    <td>Sensor ToF (Time-of-Flight) para detección de obstáculos.<br>
    <em>Rango:</em> 50-1200mm, ±3% precisión, interface I2C</td>
  </tr>

  <tr>
    <td><strong>Protoboard</strong></td>
    <td><img src="https://eloctavobit.com/imagenes/2023/06/64799b86081a2.webp" width="120" alt="Protoboard"></td>
    <td>Plataforma de interconexión para prototipado rápido.<br>
    <em>Configuración:</em> 830 puntos, distribución de buses de alimentación</td>
  </tr>

  <tr>
    <td><strong>Reguladores de voltaje</strong></td>
    <td><img src="https://robot.com.ve/wp-content/uploads/2021/08/AR0202-lm317-_v1.jpg" width="120" alt="Regulador LM7805"></td>
    <td>Sistema de gestión de energía.<br>
    <em>Especificaciones:</em> LM7805 (5V, 1A), LM1117 (3.3V), con disipadores térmicos</td>
  </tr>

  <tr>
    <td><strong>Servomotor SG90</strong></td>
    <td><img src="https://www.aranacorp.com/wp-content/uploads/towerpro-servo-sg90.jpg" width="120" alt="Servo SG90"></td>
    <td>Control de dirección y mecanismos auxiliares.<br>
    <em>Especificaciones:</em> 4.8-6V, 180° rotación, torque 1.8kg/cm</td>
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

