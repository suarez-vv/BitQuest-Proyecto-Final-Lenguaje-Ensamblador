#include "graficos.h"

#define VIEW_SIZE 20 //Vista de solo 20x20
#define TILE 32 //Tamaño de casilla en pixeles

Texture2D pared;
Texture2D camino;
Texture2D puerta;
Texture2D moneda;
Texture2D jugador;
Texture2D salida;
Texture2D llave;

//Inicializacion de la parte grafica de raylib
void iniciarGraficos(){
    InitWindow(VIEW_SIZE * TILE, VIEW_SIZE * TILE, "BitQuest");
    SetTargetFPS(60);

    //Poner las imagenes de las texturas de cada objet
    pared = LoadTexture("");
    camino = LoadTexture("");
    puerta = LoadTexture("");
    moneda = LoadTexture("");
    jugador = LoadTexture("");
    salida = LoadTexture("");
    llave = LoadTexture("");

    //Comprobar que las imagenes si se carguen correctamente
    if(pared.id == 0) TraceLog(LOG_WARNING, "Textura de 'Pared' no se cargo correctamente");
    if(camino.id == 0) TraceLog(LOG_WARNING, "Textura de 'Camino' no se cargo correctamente");
    if(moneda.id == 0) TraceLog(LOG_WARNING, "Textura de 'Moneda' no se cargo correctamente");
    if(puerta.id == 0) TraceLog(LOG_WARNING, "Textura de 'Puerta' no se cargo correctamente");
    if(jugador.id == 0) TraceLog(LOG_WARNING, "Textura de 'Jugador' no se cargo correctamente");
    if(salida.id == 0) TraceLog(LOG_WARNING, "Textura de 'Salida' no se cargo correctamente");
    if(llave.id == 0) TraceLog(LOG_WARNING, "Textura de 'Llave' no se cargo correctamente");
}

//Mapa
void dibujar_mapa(char *mapActual, int camX, int camY, int mapSize){
    for(int i=0; i<VIEW_SIZE; i++){
        for(int j=0; j<VIEW_SIZE; j++){

            int mapX = camX + j;
            int mapY = camY + i;

            int indice = mapY * mapSize + mapX;

            /*
                # = Pared
                . = Camino
                P = Jugador
                M = Moneda
                K = Llave
                D = Puerta
                E = Salida
            */

            //Cambiar los caracteres por las texturas
            switch(mapActual[indice]){
                case '#': DrawTexture(pared, j*TILE, i*TILE, WHITE);
                    break;
                case '.': DrawTexture(camino, j*TILE, i*TILE, WHITE);
                    break;
                case 'M': DrawTexture(moneda, j*TILE, i*TILE, WHITE);
                    break;
                case 'K': DrawTexture(llave, j*TILE, i*TILE, WHITE);
                    break;
                case 'D': DrawTexture(puerta, j*TILE, i*TILE, WHITE);
                    break;
                case 'E': DrawTexture(salida, j*TILE, i*TILE, WHITE);
                    break;
                default: TraceLog(LOG_WARNING, "Elemento no conocido");
                    break;
            }
        }
    }
}

//Jugador
void dibujarJugador(int jugadorX, int jugadorY, int camX, int camY){
    int posX = (jugadorX - camX) * TILE;
    int posY = (jugadorY - camY) * TILE;
    DrawTexture(jugador, posX, posY, WHITE);
}

//Cerrar y limpiar al finalizar el programa
void finGraficos(){
    //Quitar todas las texturas cargadas
    UnloadTexture(pared);
    UnloadTexture(camino);
    UnloadTexture(puerta);
    UnloadTexture(moneda);
    UnloadTexture(jugador);
    UnloadTexture(salida);
    CloseWindow();
}