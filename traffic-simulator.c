#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef enum {
    RED,
    GREEN,
    YELLOW
} State;

void printLight(State state) {
    system("cls"); // limpa o ecrã no Windows

    printf("Traffic Light Simulator\n\n");

    if (state == RED) {
        printf("[🔴]\n[   ]\n[   ]\n");
    }
    else if (state == GREEN) {
        printf("[   ]\n[🟢]\n[   ]\n");
    }
    else if (state == YELLOW) {
        printf("[   ]\n[   ]\n[🟡]\n");
    }
}

int main() {
    State current = RED;

    while (1) {
        printLight(current);

        switch (current) {
            case RED:
                Sleep(5000); // milissegundos
                current = GREEN;
                break;

            case GREEN:
                Sleep(5000);
                current = YELLOW;
                break;

            case YELLOW:
                Sleep(2000);
                current = RED;
                break;
        }
    }

    return 0;
}