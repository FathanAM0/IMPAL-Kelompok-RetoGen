#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// Fungsi untuk clear screen (cross-platform)
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void determineTriangleInteger(int a, int b, int c, FILE *output) {
    printf("\n=== BILANGAN BULAT ===\n");
    printf("Input: a=%d, b=%d, c=%d\n", a, b, c);
    
    fprintf(output, "\n=== BILANGAN BULAT ===\n");
    fprintf(output, "Input: a=%d, b=%d, c=%d\n", a, b, c);
    
    if (a <= 0 || b <= 0 || c <= 0) {
        printf("Output: TIDAK ADA SEGITIGA (ada bilangan <= 0)\n");
        fprintf(output, "Output: TIDAK ADA SEGITIGA (ada bilangan <= 0)\n");
        return;
    }
    
    int max = a, sum;
    if (b > max) max = b;
    if (c > max) max = c;
    
    sum = a + b + c - max;
    
    if (max >= sum) {
        printf("Output: TIDAK ADA SEGITIGA (tidak memenuhi ketidaksamaan segitiga)\n");
        fprintf(output, "Output: TIDAK ADA SEGITIGA (tidak memenuhi ketidaksamaan segitiga)\n");
        return;
    }
    
    if (a == b && b == c) {
        printf("Output: SEGITIGA SAMA SISI (EQUILATERAL)\n");
        fprintf(output, "Output: SEGITIGA SAMA SISI (EQUILATERAL)\n");
        return;
    }
    
    if (a == b || b == c || a == c) {
        printf("Output: SEGITIGA SAMA KAKI (ISOSCELES)\n");
        fprintf(output, "Output: SEGITIGA SAMA KAKI (ISOSCELES)\n");
        return;
    }
    
    int a2 = a * a;
    int b2 = b * b;
    int c2 = c * c;
    
    if (a2 + b2 == c2 || a2 + c2 == b2 || b2 + c2 == a2) {
        printf("Output: SEGITIGA SIKU-SIKU (RIGHT TRIANGLE)\n");
        fprintf(output, "Output: SEGITIGA SIKU-SIKU (RIGHT TRIANGLE)\n");
        return;
    }
    
    printf("Output: SEGITIGA BEBAS (SCALENE)\n");
    fprintf(output, "Output: SEGITIGA BEBAS (SCALENE)\n");
}

void determineTriangleFloat(double a, double b, double c, FILE *output) {
    printf("\n=== BILANGAN PECAHAN (Toleransi 1%%) ===\n");
    printf("Input: a=%.2f, b=%.2f, c=%.2f\n", a, b, c);
    
    fprintf(output, "\n=== BILANGAN PECAHAN (Toleransi 1%%) ===\n");
    fprintf(output, "Input: a=%.2f, b=%.2f, c=%.2f\n", a, b, c);
    
    if (a <= 0 || b <= 0 || c <= 0) {
        printf("Output: TIDAK ADA SEGITIGA (ada bilangan <= 0)\n");
        fprintf(output, "Output: TIDAK ADA SEGITIGA (ada bilangan <= 0)\n");
        return;
    }
    
    double max = a, sum;
    if (b > max) max = b;
    if (c > max) max = c;
    
    sum = a + b + c - max;
    
    if (max >= sum) {
        printf("Output: TIDAK ADA SEGITIGA (tidak memenuhi ketidaksamaan segitiga)\n");
        fprintf(output, "Output: TIDAK ADA SEGITIGA (tidak memenuhi ketidaksamaan segitiga)\n");
        return;
    }
    
    double tolerance = 0.01;
    
    int isEqual(double x, double y) {
        double larger = (x > y) ? x : y;
        if (larger == 0) return (x == 0 && y == 0);
        return (fabs(x - y) / larger <= tolerance);
    }
    
    int ab_equal = isEqual(a, b);
    int bc_equal = isEqual(b, c);
    int ac_equal = isEqual(a, c);
    
    if (ab_equal && bc_equal) {
        printf("Output: SEGITIGA SAMA SISI (EQUILATERAL)\n");
        fprintf(output, "Output: SEGITIGA SAMA SISI (EQUILATERAL)\n");
        return;
    }
    
    if (ab_equal || bc_equal || ac_equal) {
        printf("Output: SEGITIGA SAMA KAKI (ISOSCELES)\n");
        fprintf(output, "Output: SEGITIGA SAMA KAKI (ISOSCELES)\n");
        return;
    }
    
    double a2 = a * a;
    double b2 = b * b;
    double c2 = c * c;
    
    int isPythagorean1 = isEqual(a2 + b2, c2);
    int isPythagorean2 = isEqual(a2 + c2, b2);
    int isPythagorean3 = isEqual(b2 + c2, a2);
    
    if (isPythagorean1 || isPythagorean2 || isPythagorean3) {
        printf("Output: SEGITIGA SIKU-SIKU (RIGHT TRIANGLE)\n");
        fprintf(output, "Output: SEGITIGA SIKU-SIKU (RIGHT TRIANGLE)\n");
        return;
    }
    
    printf("Output: SEGITIGA BEBAS (SCALENE)\n");
    fprintf(output, "Output: SEGITIGA BEBAS (SCALENE)\n");
}

void printHeader() {
    printf("PROGRAM DETERMINE TRIANGLE\n");
    printf("==========================\n");
}

int main() {
    int choice;
    char continueProgram;
    FILE *output;
    time_t t;
    struct tm *tm_info;
    char timestamp[80];
    
    // Membuka file output
    output = fopen("triangle_results.txt", "a");
    if (output == NULL) {
        printf("Error: Tidak dapat membuka file output!\n");
        return 1;
    }
    
    // Mendapatkan timestamp
    time(&t);
    tm_info = localtime(&t);
    strftime(timestamp, 80, "%Y-%m-%d %H:%M:%S", tm_info);
    
    fprintf(output, "\n========================================\n");
    fprintf(output, "SESI BARU: %s\n", timestamp);
    fprintf(output, "========================================\n");
    
    printHeader();
    
    do {
        printf("\n1. Bilangan Bulat\n");
        printf("2. Bilangan Pecahan (Toleransi 1%%)\n");
        printf("3. Exit\n");
        printf("Pilih mode: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            int a, b, c;
            printf("\nMasukkan 3 bilangan bulat:\n");
            printf("a: ");
            scanf("%d", &a);
            printf("b: ");
            scanf("%d", &b);
            printf("c: ");
            scanf("%d", &c);
            
            determineTriangleInteger(a, b, c, output);
        }
        else if (choice == 2) {
            double a, b, c;
            printf("\nMasukkan 3 bilangan pecahan:\n");
            printf("a: ");
            scanf("%lf", &a);
            printf("b: ");
            scanf("%lf", &b);
            printf("c: ");
            scanf("%lf", &c);
            
            determineTriangleFloat(a, b, c, output);
        }
        else if (choice == 3) {
            printf("\nTerima kasih telah menggunakan program ini!\n");
            fprintf(output, "\nProgram ditutup oleh user\n");
            break;
        }
        else {
            printf("Pilihan tidak valid!\n");
            continue;
        }
        
        printf("\nLanjutkan program? (y/n): ");
        scanf(" %c", &continueProgram);
        
        // Clear screen jika user memilih 'y' atau 'Y'
        if (continueProgram == 'y' || continueProgram == 'Y') {
            clearScreen();
            printHeader();
        }
        
    } while (continueProgram == 'y' || continueProgram == 'Y');
    
    fprintf(output, "========================================\n");
    fclose(output);
    
    printf("\n===========================================\n");
    printf("Hasil telah disimpan di file: triangle_results.txt\n");
    printf("===========================================\n");
    
    return 0;
}