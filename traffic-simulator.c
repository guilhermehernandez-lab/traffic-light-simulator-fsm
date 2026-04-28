#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <windows.h>
    #define SLEEP(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define SLEEP(ms) usleep(ms * 1000)
#endif

typedef enum {
    RED,
    GREEN,
    YELLOW
} State;

void printLight(State state) {
    system("cls"); // funciona no Windows (se não, ignora)

    printf("Traffic Light Simulator\n\n");

    if (state == RED) {
        printf("[🔴]\n[   ]\n[   ]\n");
    }
    else if (state == GREEN) {
        printf("[   ]\n[🟢]\n[   ]\n");
    }
    else {
        printf("[   ]\n[   ]\n[🟡]\n");
    }
}

int main() {
    State current = RED;

    while (1) {
        printLight(current);

        switch (current) {
            case RED:
                SLEEP(5000);
                current = GREEN;
                break;

            case GREEN:
                SLEEP(5000);
                current = YELLOW;
                break;

            case YELLOW:
                SLEEP(2000);
                current = RED;
                break;
        }
    }

    return 0;
}