#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX 100

// Hàm đệ quy và khử đệ quy cho các biểu thức

// 1. Tổng các số nguyên từ 1 đến n
int tongTu1DenN_DeQuy(int n) {
    if (n == 1)
        return 1;
    return n + tongTu1DenN_DeQuy(n - 1);
}

int tongTu1DenN_KhuDeQuy(int n) {
    return n * (n + 1) / 2;
}

// 2. Tổng các căn bậc hai của 5
double tongCan5_DeQuy(int n) {
    if (n == 1)
        return sqrt(5);
    return sqrt(5) + tongCan5_DeQuy(n - 1);
}

double tongCan5_KhuDeQuy(int n) {
    return n * sqrt(5);
}

// 3. Tổng các phân số 1/2 + 2/3 + ... + n/(n+1)
double tongPhanSo_DeQuy(int n) {
    if (n == 1)
        return 1.0 / 2;
    return (double)n / (n + 1) + tongPhanSo_DeQuy(n - 1);
}

double tongPhanSo_KhuDeQuy(int n) {
    double tong = 0;
    for (int i = 1; i <= n; i++) {
        tong += (double)i / (i + 1);
    }
    return tong;
}

// 4. Tổng các phân số 1/1 + 1/3 + ... + 1/(2n+1)
double tongPhanSoLe_DeQuy(int n) {
    if (n == 1)
        return 1.0 / 1;
    return 1.0 / (2 * (n - 1) + 1) + tongPhanSoLe_DeQuy(n - 1);
}

double tongPhanSoLe_KhuDeQuy(int n) {
    double tong = 0;
    for (int i = 1; i <= n; i++) {
        tong += 1.0 / (2 * i - 1);
    }
    return tong;
}

// 5. Tổng các biểu thức 1*2 + 2*3 + ... + n*(n+1)
int tongSanPham_DeQuy(int n) {
    if (n == 1)
        return 1 * 2;
    return n * (n + 1) + tongSanPham_DeQuy(n - 1);
}

int tongSanPham_KhuDeQuy(int n) {
    int tong = 0;
    for (int i = 1; i <= n; i++) {
        tong += i * (i + 1);
    }
    return tong;
}

// 6. Tổng các biểu thức n * (n+1)! / (n+1) + sqrt(n+2)
int factorial(int x) {
    if (x == 0) return 1;
    return x * factorial(x - 1);
}

double tongBieuThuc_DeQuy(int n) {
    if (n == 1)
        return 1.0 / 2 + sqrt(2);
    return (double)n * (factorial(n + 1) / (n + 1)) + sqrt(n + 2) + tongBieuThuc_DeQuy(n - 1);
}

double tongBieuThuc_KhuDeQuy(int n) {
    double tong = 0;
    for (int i = 1; i <= n; i++) {
        int fact = 1;
        for (int j = 1; j <= i + 1; j++)
            fact *= j;
        tong += (double)i * (fact / (i + 1)) + sqrt(i + 2);
    }
    return tong;
}

// 7. Tổng các biểu thức (n + sqrt(n) + n + 1) / (n + 1) + sqrt((n + 2)!)
double tongBieuThucKhac_DeQuy(int n) {
    if (n == 1)
        return 1 + sqrt(1) / 2 + sqrt(2);
    int fact = 1;
    for (int i = 1; i <= n + 2; i++)
        fact *= i;
    return (n + sqrt(n) + n + 1) / (n + 1) + sqrt(fact) + tongBieuThucKhac_DeQuy(n - 1);
}

double tongBieuThucKhac_KhuDeQuy(int n) {
    double tong = 0;
    for (int i = 1; i <= n; i++) {
        int fact = 1;
        for (int j = 1; j <= i + 2; j++)
            fact *= j;
        tong += (i + sqrt(i) + i + 1) / (i + 1) + sqrt(fact);
    }
    return tong;
}

// Bài 2: Tìm UCLN
int ucln_DeQuy(int a, int b) {
    if (b == 0)
        return a;
    return ucln_DeQuy(b, a % b);
}

int ucln_KhuDeQuy(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Bài 3: Tìm giá trị phần tử thứ n của cấp số cộng
int capSoCong_DeQuy(int a, int r, int n) {
    if (n == 1)
        return a;
    return capSoCong_DeQuy(a, r, n - 1) + r;
}

int capSoCong_KhuDeQuy(int a, int r, int n) {
    return a + (n - 1) * r;
}

// Bài 4a: Dãy số An
int dayAn1_DeQuy(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    if (n == 2) return -1;
    return 2 * dayAn1_DeQuy(n - 1) - 3 * dayAn1_DeQuy(n - 2) - dayAn1_DeQuy(n - 3);
}

int dayAn1_KhuDeQuy(int n) {
    int a[MAX] = { 1, 0, -1 };
    for (int i = 3; i <= n; i++) {
        a[i] = 2 * a[i - 1] - 3 * a[i - 2] - a[i - 3];
    }
    return a[n];
}

// Bài 4b: Dãy số An
int dayAn2_DeQuy(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 3;
    return 2 * dayAn2_DeQuy(n - 1) + dayAn2_DeQuy(n - 2) - 3 * dayAn2_DeQuy(n - 3);
}

int dayAn2_KhuDeQuy(int n) {
    int a[MAX] = { 0, 1, 2, 3 };
    for (int i = 4; i <= n; i++) {
        a[i] = 2 * a[i - 1] + a[i - 2] - 3 * a[i - 3];
    }
    return a[n];
}

// Bài 5: Dãy số xn
int xn_DeQuy(int n) {
    if (n == 0) return 1;
    if (n == 1) return 2;
    return n * xn_DeQuy(n - 1) + (n - 1) * xn_DeQuy(n - 2);
}

int xn_KhuDeQuy(int n) {
    int x[MAX] = { 1, 2 };
    for (int i = 2; i <= n; i++) {
        x[i] = i * x[i - 1] + (i - 1) * x[i - 2];
    }
    return x[n];
}

// Hàm chính với menu
int main() {
    int choice, n, a, b, r;

    do {
        printf("\n*** MENU ***\n");
        printf("1. Tính S(n) = 1 + 2 + ... + n (Đệ quy và Khử đệ quy)\n");
        printf("2. Tính S(n) = √5 + √5 + ... + √5 (Đệ quy và Khử đệ quy)\n");
        printf("3. Tính S(n) = 1/2 + 2/3 + ... + n/(n+1) (Đệ quy và Khử đệ quy)\n");
        printf("4. Tính S(n) = 1/1 + 1/3 + ... + 1/(2n+1) (Đệ quy và Khử đệ quy)\n");
        printf("5. Tính S(n) = 1*2 + 2*3 + ... + n*(n+1) (Đệ quy và Khử đệ quy)\n");
        printf("6. Tính S(n) = n*(n+1)!/(n+1) + √(n+2) (Đệ quy và Khử đệ quy)\n");
        printf("7. Tính S(n) = (n + √n + n + 1)/(n + 1) + √((n + 2)!) (Đệ quy và Khử đệ quy)\n");
        printf("8. Tìm UCLN (Đệ quy và Khử đệ quy)\n");
        printf("9. Tính giá trị phần tử thứ n của cấp số cộng (Đệ quy và Khử đệ quy)\n");
        printf("10. Tính số hạng thứ n của dãy An (Bài 4a và 4b, Đệ quy và Khử đệ quy)\n");
        printf("11. Tính số hạng thứ n của dãy xn (Đệ quy và Khử đệ quy)\n");
        printf("0. Thoát\n");
        printf("Nhập lựa chọn: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("Nhập n: ");
            scanf_s("%d", &n);
            printf("S(n) (Đệ quy) = %d\n", tongTu1DenN_DeQuy(n));
            printf("S(n) (Khử đệ quy) = %d\n", tongTu1DenN_KhuDeQuy(n));
            break;
        case 2:
            printf("Nhập n: ");
            scanf_s("%d", &n);
            printf("S(n) (Đệ quy) = %f\n", tongCan5_DeQuy(n));
            printf("S(n) (Khử đệ quy) = %f\n", tongCan5_KhuDeQuy(n));
            break;
        case 3:
            printf("Nhập n: ");
            scanf_s("%d", &n);
            printf("S(n) (Đệ quy) = %f\n", tongPhanSo_DeQuy(n));
            printf("S(n) (Khử đệ quy) = %f\n", tongPhanSo_KhuDeQuy(n));
            break;
        case 4:
            printf("Nhập n: ");
            scanf_s("%d", &n);
            printf("S(n) (Đệ quy) = %f\n", tongPhanSoLe_DeQuy(n));
            printf("S(n) (Khử đệ quy) = %f\n", tongPhanSoLe_KhuDeQuy(n));
            break;
        case 5:
            printf("Nhập n: ");
            scanf_s("%d", &n);
            printf("S(n) (Đệ quy) = %d\n", tongSanPham_DeQuy(n));
            printf("S(n) (Khử đệ quy) = %d\n", tongSanPham_KhuDeQuy(n));
            break;
        case 6:
            printf("Nhập n: ");
            scanf_s("%d", &n);
            printf("S(n) (Đệ quy) = %f\n", tongBieuThuc_DeQuy(n));
            printf("S(n) (Khử đệ quy) = %f\n", tongBieuThuc_KhuDeQuy(n));
            break;
        case 7:
            printf("Nhập n: ");
            scanf_s("%d", &n);
            printf("S(n) (Đệ quy) = %f\n", tongBieuThucKhac_DeQuy(n));
            printf("S(n) (Khử đệ quy) = %f\n", tongBieuThucKhac_KhuDeQuy(n));
            break;
        case 8:
            printf("Nhập a và b: ");
            scanf_s("%d %d", &a, &b);
            printf("UCLN (Đệ quy) = %d\n", ucln_DeQuy(a, b));
            printf("UCLN (Khử đệ quy) = %d\n", ucln_KhuDeQuy(a, b));
            break;

        case 9:
            printf("Nhập a, r và n: ");
            scanf_s("%d %d %d", &a, &r, &n);
            printf("U(n) (Đệ quy) = %d\n", capSoCong_DeQuy(a, r, n));
            printf("U(n) (Khử đệ quy) = %d\n", capSoCong_KhuDeQuy(a, r, n));
            break;
        case 10:
            printf("Nhập n và loại dãy (1: Bài 4a, 2: Bài 4b): ");
            scanf_s("%d %d", &n, &choice);
            if (choice == 1) {
                printf("A(n) (Đệ quy) = %d\n", dayAn1_DeQuy(n));
                printf("A(n) (Khử đệ quy) = %d\n", dayAn1_KhuDeQuy(n));
            }
            else if (choice == 2) {
                printf("A(n) (Đệ quy) = %d\n", dayAn2_DeQuy(n));
                printf("A(n) (Khử đệ quy) = %d\n", dayAn2_KhuDeQuy(n));
            }
            else {
                printf("Lựa chọn không hợp lệ.\n");
            }
            break;
        case 11:
            printf("Nhập n: ");
            scanf_s("%d", &n);
            printf("x(n) (Đệ quy) = %d\n", xn_DeQuy(n));
            printf("x(n) (Khử đệ quy) = %d\n", xn_KhuDeQuy(n));
            break;
        case 0:
            printf("Thoát chương trình.\n");
            break;
        default:
            printf("Lựa chọn không hợp lệ. Vui lòng chọn lại.\n");
            break;
        }
    } while (choice != 0);

    return 0;
}
