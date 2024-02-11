#include "fdf.h"

int max(int a, int b) {
    return (a > b) ? a : b;
}

void drawline(t_fdf *fdf, int x0, int y0, int x1, int y1, int startColor, int endColor) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2; // errore di valore doppio dx dy
    int currentColor = startColor;

    // Estrai i componenti RGB dai colori di inizio e fine
    int startR = (startColor >> 16) & 0xFF;
    int startG = (startColor >> 8) & 0xFF;
    int startB = startColor & 0xFF;

    int endR = (endColor >> 16) & 0xFF;
    int endG = (endColor >> 8) & 0xFF;
    int endB = endColor & 0xFF;

    // Calcola il numero di passi e il gradiente di colore
    int steps = max(abs(x1 - x0), abs(y1 - y0));
    float colorStepR = (float)(endR - startR) / steps;
    float colorStepG = (float)(endG - startG) / steps;
    float colorStepB = (float)(endB - startB) / steps;
    float currentR = startR, currentG = startG, currentB = startB;

    for (;;) {
        // Imposta il colore corrente basato sui valori RGB calcolati
        currentColor = ((int)currentR << 16) | ((int)currentG << 8) | (int)currentB;
        my_mlx_pixel_put(&fdf->img, x0, y0, currentColor);

        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }

        // Aggiorna i valori RGB per il prossimo pixel
        currentR += colorStepR;
        currentG += colorStepG;
        currentB += colorStepB;

        // Assicurati che i valori RGB rimangano nei limiti
        currentR = fmax(0, fmin(255, currentR));
        currentG = fmax(0, fmin(255, currentG));
        currentB = fmax(0, fmin(255, currentB));
    }
}
