#include <stdio.h>

int main() {
    int computer_amount, service_time, is_business_hours, is_willing_dropoff;
    int base_fee, additional_fee, total_base_fee, total_fee;
    int peripheral_count;

    printf("=== SERVIS KOMPUTER ===\n");

    printf("Jumlah komputer: ");
    scanf("%d", &computer_amount);

    printf("Jumlah peripheral: ");
    scanf("%d", &peripheral_count);

    printf("Waktu servis (0 = di luar jam bisnis, 1 = dalam jam bisnis): ");
    scanf("%d", &is_business_hours);

    printf("Pelanggan bersedia drop off & pick up (0 = tidak, 1 = ya): ");
    scanf("%d", &is_willing_dropoff);

    if (computer_amount == 1 || computer_amount == 2) {
        base_fee = 50;
        additional_fee = 0;
    }
    else if (computer_amount >= 3 && computer_amount <= 10) {
        base_fee = 100;
        additional_fee = 10 * peripheral_count;
    }
    else if (computer_amount > 10) {
        base_fee = 500;
        additional_fee = 10 * peripheral_count;
    }
    else {
        printf("Jumlah komputer tidak valid!\n");
        return 1;
    }

    total_base_fee = base_fee;
    if (!is_business_hours) {
        total_base_fee = base_fee * 2;
    }

    if (is_willing_dropoff) {
        total_base_fee = total_base_fee / 2;
    }

    total_fee = total_base_fee + additional_fee;

    printf("\n=== RINCIAN BIAYA SERVIS ===\n");
    printf("Base fee: $%d\n", base_fee);
    printf("Additional fee (peripheral): $%d\n", additional_fee);

    if (!is_business_hours) {
        printf("Biaya diluar jam bisnis: base fee dikalikan 2\n");
    }

    if (is_willing_dropoff) {
        printf("Diskon drop off & pick up: base fee dikurangi 50%%\n");
    }

    printf("Total base fee: $%d\n", total_base_fee);
    printf("Total biaya servis: $%d\n", total_fee);

    return 0;
}
