#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#define SLEEP(ms) Sleep(ms)
#define THREAD_TYPE HANDLE
#else
#include <unistd.h>
#include <pthread.h>
#include <termios.h>
#define SLEEP(ms) usleep(ms * 1000)
#define THREAD_TYPE pthread_t
#endif

typedef enum {
RED,
GREEN,
YELLOW,
PEDESTRIAN // novo estado
} State;

// Flag global para o botão de peão
volatile int pedestrianRequest = 0;

// ---- Thread que escuta o teclado ----
#ifdef _WIN32
DWORD WINAPI inputThread(LPVOID arg) {
#else
void* inputThread(void* arg) {
#endif
while (1) {
char c;
#ifdef _WIN32
c = _getch();
#else
c = getchar();
#endif

if (c == 'p' || c == 'P') {
pedestrianRequest = 1;
}
}
return 0;
}

void printLight(State state) {
system("cls");

printf("Traffic Light Simulator\n");
printf("Press [P] to request pedestrian crossing\n\n");

if (state == RED || state == PEDESTRIAN) {
printf("[🔴]\n[ ]\n[ ]\n");
} else if (state == GREEN) {
printf("[ ]\n[🟢]\n[ ]\n");
} else {
printf("[ ]\n[ ]\n[🟡]\n");
}

if (state == PEDESTRIAN) {
printf("\n🚶 PEDESTRIAN CROSSING - Walk now!\n");
} else if (pedestrianRequest) {
printf("\n⏳ Pedestrian request pending...\n");
}
}

int main() {
State current = RED;

// Inicia a thread de input
#ifdef _WIN32
HANDLE t;
t = CreateThread(NULL, 0, inputThread, NULL, 0, NULL);
#else
pthread_t t;
pthread_create(&t, NULL, inputThread, NULL);
#endif

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
if (pedestrianRequest) {
pedestrianRequest = 0;
current = PEDESTRIAN;
} else {
current = RED;
}
break;

case PEDESTRIAN:
// Vermelho para peões atravessarem
SLEEP(4000);
current = RED;
break;
}
}

return 0;
}
