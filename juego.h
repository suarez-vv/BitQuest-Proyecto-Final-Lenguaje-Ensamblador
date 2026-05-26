#ifndef JUEGO_H
#define JUEGO_H

#include "mapas.h"

//Inicialización del juego
void iniciarJuego();

//Lógica de como va avanzando el juego
void estadoJuego();

//Llamar la parte gráfica de raylib
void llamarDibujar();

//Limpiar al finalizar
void limpiar();

//Identificar en que nivel del juego se encuentra el jugador
void cambiarNivel(int);

//Función en ensamblador
int contarAcumulables(char*, int, char);

//Actualizar caracteres de mapa
void actualizarMapa(char*, int);

#endif