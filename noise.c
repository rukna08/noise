#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    srand(time(NULL));

    FILE* noisePPM = fopen("noise.ppm", "w+");

    const int width = 500;
    const int height = 500;

    fprintf(noisePPM, "%s\n%d %d\n%d\n", "P3", width, height, 255);

    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            if(x == width-1) fprintf(noisePPM, "%d %d %d", rand() % 256, rand() % 256, rand() % 256);
            else fprintf(noisePPM, "%d %d %d ", rand() % 256, rand() % 256, rand() % 256);
        }
        fprintf(noisePPM, "\n");
    }

    return 0;
}