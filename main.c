#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROW_HEIGHT 2

int main() {
    char symbol;
    double a, b, c, apexX, height, minX, maxX, t, xAB, xAC, left, right, x;
    int valid, rows, cols, i, j;

    system("chcp 65001 > nul");

    puts("Введите символ, которым нарисовать треугольник");
    scanf(" %c", &symbol);

    do {
        puts("Введите стороны a, b, c через пробел");
        if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
            puts("Нужно ввести три числа");
            return 1;
        }
        valid = a > 0 && b > 0 && c > 0 && a < b + c && b < a + c && c < a + b;
        if (valid == 0)
            puts("Треугольника с такими сторонами не существует");
    } while (valid == 0);

    apexX = (a * a + c * c - b * b) / (2 * a);
    height = sqrt(c * c - apexX * apexX);
    rows = (int)(height / ROW_HEIGHT + 0.5);
    if (rows < 2)
        rows = 2;
    minX = apexX < 0 ? apexX : 0;
    maxX = apexX > a ? apexX : a;
    cols = (int)(maxX - minX) + 1;

    for (i = 0; i < rows; i++) {
        t = 1 - (i + 0.5) / rows;
        xAB = apexX * t;
        xAC = a + (apexX - a) * t;
        left = xAB < xAC ? xAB : xAC;
        right = xAB < xAC ? xAC : xAB;
        for (j = 0; j < cols; j++) {
            x = minX + j + 0.5;
            printf("%c", left <= x && x <= right ? symbol : ' ');
        }
        printf("\n");
    }

    system("pause");
    return 0;
}
