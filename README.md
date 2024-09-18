# Pipex

Este proyecto es parte del plan de estudios de la escuela 42. Su objetivo es profundizar en la comprensión de los mecanismos de UNIX, específicamente el concepto de tuberías (pipes), mediante la implementación de un programa que simula el comportamiento de la línea de comandos del shell.

## Tabla de Contenidos
- [Descripción](#descripción)
- [Características](#características)
- [Instalación](#instalación)
- [Uso](#uso)
- [Ejemplos](#ejemplos)

## Descripción

Pipex es un programa que imita la funcionalidad de las tuberías del shell. Toma cuatro argumentos: dos nombres de archivo y dos comandos del shell. El programa lee desde el primer archivo, ejecuta el primer comando, canaliza la salida al segundo comando y luego escribe la salida final en el segundo archivo.

## Características

- Simula el comportamiento de las tuberías del shell
- Maneja la redirección de entrada y salida
- Ejecuta comandos del shell
- Gestión de errores y manejo de memoria

## Instalación

1. Clona el repositorio:

   ```
   git clone https://github.com/tu-usuario/pipex.git
   ```
  
3. Navega al directorio del proyecto:

  ```
  cd pipex
  ```

4. Compila el proyecto:

   ```
   make
   ```

## Uso

Ejecuta el programa con la siguiente sintaxis:

```
./pipex archivo1 comando1 comando2 archivo2
```

Dispones de un archivo en el repositorio can varios comandos para probar.
