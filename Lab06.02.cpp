#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

bool Check_same(int a[], int cu_size, int new_num) {
    for (int i = 0; i < cu_size; i++) {
        if (new_num == a[i])
            return true;
    }
    return false;
}

bool valid_size(int a) {
    return ((a >= 1) && (a <= 45)) ? 1 : 0;
}

void luckyTicket(int a[]) {
    int i = 0, new_num = 0;

    cout << "\nNhap 6 so (1..45) khong trung nhau:\n";

    while (i < 6) {
        cin >> new_num;

        if ((!Check_same(a, i, new_num)) && (valid_size(new_num))) {
            a[i] = new_num;
            i++;
        }
        else {
            cout << "So khong hop le xin nhap lai: ";
        }
    }
}

void choose_randTicket(int a[]) {
    int new_num = 0;
    int i = 0;
    while (i < 6) {
        new_num = rand() % 45 + 1;
        if (!Check_same(a, i, new_num)) {
            a[i] = new_num;
            i++;
        }
    }
}

long long prize(int match) {
    if (match == 6)
        return 12000000000LL;
    if (match == 5)
        return 10000000LL;
    if (match == 4)
        return 300000LL;
    if (match == 3)
        return 30000;
    return 0;
}

int Check(int a[], int b[]) {
    int match = 0;
    for (int i = 0; i < 6; i++) {
        int value = a[i];
        if (Check_same(b, 6, value))
            match++;
    }
    return match;
}

int main() {
    int a[6], b[6], n;
    long long totalPaid = 0, totalPrize = 0;
    srand(time(0));

    cout << "Hay chon ra ve trung thuong ";
    luckyTicket(a);

    cout << "\nHay nhap so to ve so de mua ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        choose_randTicket(b);
        totalPaid += 10000;
        totalPrize += prize(Check(a, b));
    }

    if (n == 0)
        cout << "Ket qua khong hop le do khong mua to ve so nao";
    else {
        long double result = (long double)totalPrize / totalPaid * 100;
        cout << "Ket qua la " << result << " %";
    }
}
