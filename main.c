#include "juego.h"
#include "raylib.h"

int main(){
    //Iniciar el juego
    iniciarJuego();
    bool status = true;

    //Ciclo para que se mande a llamar la logica de dibujo del mapa y logica del juego
    while(!WindowShouldClose()){
        estadoJuego();
        llamarDibujar(&status);

        if(!status){
            break;
        }
    }

    //Cerrar Juego
    limpiar();
    return 0;
}