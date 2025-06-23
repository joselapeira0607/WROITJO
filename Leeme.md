## Proyecto de robot autónomo para la WRO - Categoría Futuros Ingenieros

<p align="center"> <img src="https://github.com/DexterTaha/WRO-2024-FUTURE-ENGINEERS/assets/130682580/d9385136-f971-4c95-ba80-ffc14f7c0a4e" alt="banner" width="1500"> </p>

<p align="center"> La Olimpiada de Robótica Mundial </p>


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

## Componentes utilizados
Nuestro robot está construido con hardware de precisión para garantizar su estabilidad, capacidad de respuesta y optimización.

Electrónica y hardware clave:
* Arduino Uno - Microcontrolador principal que gestiona la entrada de sensores y el control de movimiento.
* NXT Motor & H-Bridge - Proporciona movimiento preciso y ajustes de velocidad.
* ESP32 con cámara integrada - Permite la detección de objetos en tiempo real y algoritmos de navegación.
* Sensor de distancia VL53L0X - Soporta la detección de obstáculos de alta precisión y correcciones de movimiento.
* Protoboard y sistema de cableado - Garantiza conexiones eléctricas estructuradas y estabilidad de los componentes.
* Reguladores de voltaje - Mantienen una distribución de energía consistente en todos los sistemas del robot.
* Servomotor: proporciona control de movimiento adicional y funciones interactivas.

## Procesamiento de sensores y navegación autónoma
El sensor VL53L0X desempeña un papel crucial en la detección de obstáculos, permitiendo al robot medir la distancia en tiempo real y ajustar su movimiento en consecuencia. El robot sigue un algoritmo de movimiento impulsado por sensores, perfeccionando continuamente la velocidad de su motor y la lógica de navegación.

* Detección de obstáculos: El sensor de distancia identifica objetos y ajusta dinámicamente la trayectoria del robot.
* Entrada de cámara basada en ESP32: Procesa imágenes en tiempo real para el análisis del terreno y las decisiones de movimiento.
* Lógica de control del motor: El Arduino Uno gestiona el control de velocidad mediante señales PWM y ajustes de servo.

## Medidas
* Anchura: 15 centímetros
* Longitud: 27 centímetros
* Altura: 

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

