<h1 align="center">Informe Técnico</h1>
<h2 align="center">Desarrollo del Robot Autónomo para las Olimpiadas Mundiales de Robótica (WRO)</h2>

<p align="center"><i>Documentación completa del diseño, optimización y resultados de un robot móvil autónomo preparado para superar circuitos cerrados con obstáculos.</i></p>

---

## 🧭 Introducción

Este documento describe de manera detallada el proceso de diseño, ensamblaje, optimización y validación de un robot autónomo creado con el propósito de competir en las Olimpiadas Mundiales de Robótica (WRO). El principal objetivo técnico consistía en lograr que el robot completara tres vueltas dentro de una pista cerrada, evitando con precisión tanto muros como obstáculos intermedios.

A lo largo del proceso se abordaron desafíos en tres áreas fundamentales: mecánica, electrónica y control inteligente. Las iteraciones técnicas permitieron refinar tanto el hardware como el algoritmo de navegación, obteniendo como resultado un sistema robusto y confiable.

> 📷 ![460205220-4385875f-8fb5-4cfd-8109-ed76797ce5a7](https://github.com/user-attachments/assets/7eeb1662-5465-4cd8-8b95-888d35d6f3af)


---

## 🧪 Fase Inicial: Prototipado con LEGO (Marzo)

La etapa inicial se enfocó en la construcción de un prototipo funcional utilizando piezas LEGO Mindstorms, dada su versatilidad modular y facilidad de prueba.

### Diseño Mecánico

Se desarrolló un chasis básico con componentes LEGO, el cual integró:

- Un sistema de dirección diferencial.
- Ruedas delanteras conectadas a una viga dentada impresa en 3D y accionada por un servomotor.
- Ruedas traseras con tracción proporcionada por un motor NXT.

### Circuito Electrónico

El sistema de control y detección en esta fase inicial fue conformado por:

- **Microcontrolador:** Arduino UNO.  
- **Control de motores:** Puente H L298N.  
- **Sensado:** Dos sensores ultrasónicos HC-SR04 ubicados en posiciones frontal y lateral.  
- **Alimentación:** Tres baterías recargables de 4V conectadas en serie (12V total) y distribuida mediante protoboard.  

> 📷 ![IMG_20250425_150937_312](https://github.com/user-attachments/assets/b59a5c2e-5463-4042-b58e-b8d414681b3f)

### Problemas Técnicos Identificados

Durante las primeras pruebas, se identificaron limitaciones relevantes:

- Alta sensibilidad a ruido ultrasónico en los sensores HC-SR04, generando falsas detecciones.
- Precisión limitada en curvas cerradas debido a la flexibilidad estructural del sistema diferencial LEGO.
- Pérdida de torque y vibraciones por sobrecalentamiento del motor NXT a altas velocidades.

---

## 🔧 Optimización: Sensores y Controlador

Con base en los inconvenientes detectados, se planteó una reestructuración del sistema de sensado y control.

### Migración a Sensores VL53L0X

El sistema ultrasónico fue reemplazado por sensores Time-of-Flight VL53L0X. Estos nuevos sensores ofrecieron:

- Resolución milimétrica con alta estabilidad.
- Inmunidad a interferencias acústicas del entorno.
- Rango de detección adaptable de hasta 2 metros.

**Desafíos derivados:**

- El rendimiento de los sensores se veía afectado por iluminación excesiva.
- Las lecturas por protocolo I2C requerían mayor velocidad de procesamiento.

### Adopción del ESP32

Para mejorar la capacidad de lectura y procesamiento paralelo, se integró un ESP32 que ofrecía:

- Doble núcleo para multitarea (lectura de sensores y control de motores en paralelo).
- Comunicación I2C más eficiente y sin congestión en el bus de datos.

---

## ⚙️ Rediseño Mecánico: Chasis DKS-Basic

### Limitaciones del Chasis LEGO

- Baja rigidez estructural ante cargas dinámicas.
- Holgura en las conexiones móviles.
- Elevado peso, reduciendo agilidad y autonomía.

### Ventajas del DKS-Basic

Se optó por migrar a un chasis metálico profesional (DKS-Basic), el cual ofrecía:

- Mayor resistencia gracias al aluminio anodizado.
- Sistema de rodamientos de bolas, reduciendo fricción.
- Geometría más compacta, que optimiza los giros cerrados.
- Compatibilidad con motores DC comerciales.

### Actualización de Tracción

- Sustitución del motor NXT por un motor DC con caja reductora.
- Mejora de torque y control de velocidad con señal PWM.
- Ruedas personalizadas diseñadas en CAD e impresas en 3D para adaptarse a los rodamientos del nuevo chasis.

> 📷 ![left-view](https://github.com/user-attachments/assets/24d5cb4c-50c7-49b2-b633-ab05e7ddc39f)

---

## 🧠 Sistema de Sensado y Control Final

### Configuración de Sensores

La versión final integró una arquitectura híbrida de sensores:

- 1x HC-SR04 (posición frontal) para detección lejana de obstáculos.
- 2x VL53L0X (laterales) para navegabilidad en curvas y evitación precisa.

### Algoritmo de Evasión

Se implementó un firmware basado en lógica determinista mediante una máquina de estados finitos (FSM), que define tres modos de operación:

1. **Avance libre:** sin obstáculos detectados.
2. **Giro lateral:** ante presencia parcial de muros.
3. **Frenado y reversa:** cuando se detecta un muro frontal crítico.

Las lecturas fueron filtradas mediante un algoritmo de mediana para eliminar valores anómalos.

---

## 📈 Evaluación y Resultados

### Métricas de Desempeño

| Parámetro               | Valor alcanzado  |
|-------------------------|------------------|
| Velocidad máxima        | 1.2 m/s          |
| Tiempo promedio por vuelta | 15 segundos   |
| Precisión de giro       | ±2 cm            |
| Precisión de detección  | 98%              |


### Lecciones Aprendidas

- La redundancia sensorial mejora considerablemente la confiabilidad.
- Un chasis profesional contribuye significativamente a la estabilidad dinámica del robot.
- El uso del ESP32 demuestra ser altamente adecuado para sistemas de navegación en tiempo real que requieren múltiples tareas simultáneas.

---

## 🏁 Conclusión

El sistema robótico desarrollado no solo logró cumplir los requerimientos establecidos por la competencia WRO, sino que también superó las expectativas de precisión y estabilidad. La implementación de sensores híbridos, un controlador de alto rendimiento como el ESP32 y un chasis mecánico profesional fueron factores determinantes para el éxito del proyecto.

Más allá de su participación en la competencia, este robot representa una sólida base técnica para el desarrollo de futuras plataformas de navegación autónoma en entornos dinámicos.

---

## 👥 Equipo de Desarrollo

**Autor:** JO SLD  
**Año:** 2025  
**Colaboradores:** *Keiner Duran, Jose Lapeira, Mauricio Sanchez*

---
