#include <stdio.h>
#include <unistd.h>

typedef enum {
    RED,
    GREEN,
    YELLOW
} State;

int main() {
    State current = RED;

    while (1) {
        switch (current) {

            case RED:
                printf("\nRED LIGHT\n");
                sleep(5);
                current = GREEN;
                break;

            case GREEN:
                printf("\nGREEN LIGHT\n");
                sleep(5);
                current = YELLOW;
                break;

            case YELLOW:
                printf("\nYELLOW LIGHT\n");
                sleep(2);
                current = RED;
                break;
        }
    }

    return 0;
}