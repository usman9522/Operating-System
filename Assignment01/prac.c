#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* func(void* arg);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Must pass two file names.\n");
        exit(1);
    }

    pthread_t tid1, tid2;

    // Create threads to process the files
    pthread_create(&tid1, NULL, func, (void*)argv[1]);
    pthread_create(&tid2, NULL, func, (void*)argv[2]);

    // Wait for both threads to finish
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("Bye Bye from main thread\n");
    return 0;
}

// Example function that processes a file
void* func(void* arg) {
    char* filename = (char*)arg;
    printf("Processing file: %s\n", filename);

    // Simulated file processing (could be opening, reading, etc.)
    // Add actual file handling code as needed

    pthread_exit(NULL);
}
