#include <stdio.h>
#include <stdbool.h>
#define TAPESIZE 300

int* insertionSorter(int vetor[]) {
    int swapper;

    for (int i = 0; i < TAPESIZE; i++) {
        if (vetor[i] > vetor[i + 1]) {
            swapper = vetor[i];
            vetor[i] = vetor[i + 1];
            vetor[i + 1] = swapper;

            for (int d = i; d > 0 && vetor[d] < vetor[d - 1]; d--) {
                swapper = vetor[d];
                vetor[d] = vetor[d - 1];
                vetor[d - 1] = swapper;
            }
        }
    }
    return vetor;
}

int* bubbleSorter(int vetor[]) {
    int swapper;
    bool isSorted = true;

    do {
        isSorted = true;
        for (int i = 0; i < TAPESIZE; i++) {
            if (vetor[i] > vetor[i + 1]) {
                swapper = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = swapper;
                if (isSorted)
                    isSorted = false;
            }
        }
    } while (!isSorted);

    return vetor;
}

void printVetor(int vetor[]) {
    for (int i = 0; i < TAPESIZE; i++) { 
        printf("\n%d-  %d", i + 1, vetor[i]);
    }
}

bool verifySorting(int vetor[]) {
    for (int i = 0; i < TAPESIZE; i++) {
        if (vetor[i] > vetor[i + 1]) {
            return false;
        }
    }
    return true;
}

void isSorted(int vetor[]) {
    if (verifySorting(vetor)) {
        printf("\n\nSorted.\n\n");
    } else {
        printf("\n\nNot sorted.\n\n");
    }
}

int main() {
    int vetor[] = {
        400, 218, 367, 18, 197, 291, 332, 437, 139, 466, 25, 492, 62, 206, 328, 484, 157, 12, 285, 344, 385, 469, 341, 60, 417, 248, 49, 401, 115, 441, 69, 307, 372, 187, 247, 233, 44, 162, 348, 312, 150, 255, 226, 220, 429, 221, 223, 382, 119, 318, 276, 142, 262, 494, 487, 249, 48, 47, 407, 108, 430, 30, 170, 126, 345, 381, 488, 299, 1, 493, 84, 229, 63, 118, 448, 293, 326, 199, 141, 173, 128, 360, 70, 375, 295, 124, 412, 9, 434, 160, 71, 13, 384, 273, 459, 270, 333, 149, 46, 99, 20, 50, 182, 241, 419, 178, 121, 427, 496, 175, 452, 342, 370, 244, 421, 428, 66, 222, 266, 359, 161, 482, 278, 462, 28, 225, 386, 357, 390, 10, 416, 35, 228, 23, 166, 256, 325, 31, 314, 16, 440, 120, 100, 290, 264, 193, 183, 190, 155, 391, 267, 289, 22, 297, 308, 388, 3, 268, 192, 97, 19, 196, 471, 330, 498, 11, 21, 376, 156, 379, 111, 64, 317, 353, 261, 215, 438, 500, 395, 185, 174, 211, 470, 371, 260, 54, 373, 245, 80, 102, 8, 445, 287, 172, 95, 234, 189, 143, 168, 475, 468, 254, 61, 159, 316, 409, 130, 91, 104, 55, 29, 463, 457, 393, 389, 281, 181, 86, 5, 76, 352, 252, 351, 191, 355, 298, 94, 356, 208, 432, 85, 176, 74, 117, 361, 274, 87, 424, 51, 402, 42, 349, 435, 335, 447, 165, 387, 404, 52, 374, 259, 269, 224, 103, 263, 107, 454, 399, 444, 112, 396, 410, 280, 195, 2, 217, 210, 4, 347, 477, 324, 79, 75, 378, 219, 152, 83, 413, 286, 331, 420, 186, 235, 489, 431, 495, 406, 14, 93, 337, 151, 446, 232, 340, 436, 497, 237, 59, 129, 110
    };
    printf("\n\n\nVetor pré-sorting:  ");
    printVetor(vetor);

    *vetor = *insertionSorter(vetor);

    printf("\n\n\nVetor pós-sorting:  ");
    printVetor(vetor);

    isSorted(vetor);
}
