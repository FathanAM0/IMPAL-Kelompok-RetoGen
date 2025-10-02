#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 5

typedef struct {
    int account_number;
    char status_code[10];
} Account;

Account ACCOUNTS[MAX_ACCOUNTS] = {
    {1001, "valid"},
    {1002, "invalid"},
    {1003, "valid"},
    {1004, "valid"},
    {1005, "suspended"}
};

int isEqual(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;
        }
        i++;
    }
    if (str2[i] == '\0') {
        return 1;
    }
    return 0;
};
int verifyAccount(int account_number) {
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        if (ACCOUNTS[i].account_number == account_number) {
            if (isEqual(ACCOUNTS[i].status_code, "valid")) {
                return 1;
            }
        }
    }
    return 0;
}

void produceInvoice(int account_number, float amount) {
    printf("\n=== INVOICE SERVIS KOMPUTER ===\n");
    printf("Account Number: %d\n", account_number);
    printf("Amount of Sale: $%.2f\n", amount);
    printf("===============================\n");
}

void produceErrorMessage() {
    printf("\n=== ERROR ===\n");
    printf("Akun tidak ditemukan atau tidak valid!\n");
    printf("tolong cek nomor akun atau status akun.\n");
    printf("=============\n");
}

int main() {
    int input_account;
    float service_amount = 150.75;
    printf("Masukan nomor akun: ");
    scanf("%d", &input_account);

    if (verifyAccount(input_account)) {
        produceInvoice(input_account, service_amount);
    } else {
        produceErrorMessage();
    }

    return 0;
}
