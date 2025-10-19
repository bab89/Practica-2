// Created by Miriam on 02/10/2025.
//
// practica2.c
#include <stdio.h>
#include <stdlib.h>
/* Usar la siguiente línea, si con Windows no aparecen
 las vocales acentuadas al imprimir texto por pantalla. */
#include <windows.h>
#include <locale.h>

// DECLARACIONES DE FUNCIONES
int menu(); // declaración de la función "menu"
int desplazar(int, int);
int parImpar(int);
void operacionesLogicasBits();
int ponerACeroBit(int, int);
int obtenerValorBit(int , int);
long factorial(long);
int numeroBits(int);
int cambiarBits(int, int, int);
void intercambiar(double *, double *);

int main ()
{
    // DEFINICIONES DE VARIABLES
    int opcion; // opción elegida del menú
    SetConsoleOutputCP(CP_UTF8); // Usa esta sentencia si trabajas con Windows
    setlocale(LC_ALL, ".UTF8"); // Usa esta sentencia si trabajas con Windows
    /* Usar la línea siguiente si en depuración no muestra el texto de los
    printf por pantalla. */
    setvbuf(stdout, NULL, _IONBF, 0);
    long xl, yl;
    int n, nposbit, resultado, valorBit;
    int nbits;
    int x = 0, y = 0, z = 0;
    int p;

    printf ("PRACTICA 2\n");
    printf ("==========\n");
    opcion = menu(); // llama/invoca a la función "menu"
    while (opcion != 10) // sentencia repetitiva
    {
        switch (opcion) // sentencia condicional
        {
            case 1:
                printf("Ejercicio 1: desplazar\n");
                printf("Ejercicio 1:\n");
                printf("Introduzca un número: ");
                scanf("%d", &y);
                printf("Posiciones a desplazar a la derecha: ");
                scanf("%d",&z);
                x = desplazar(y, z);
                printf("El número desplazado es: %d\n\n", x);
                break;

            case 2:
                printf("Ejercicio 2: par o impar\n");
                printf("Introduzca un número: ");
                scanf("%d",&y);
                x = parImpar(y);
                if (x % 2 != 0)
                    printf("El número %d es impar\n\n", y);
                else
                    printf("El número %d es par\n\n", y);
                break;

            case 3:
                printf("Ejercicio 3: operaciones lógicas y a nivel de bits\n");
                operacionesLogicasBits();
                break;

            case 4:
                printf("Ejercicio 4: poner a cero un bit\n");
                printf("Introduzca un número:");
                scanf("%d", &n);
                printf("Posición de bit:");
                scanf("%d", &nposbit);
                resultado = ponerACeroBit(n, nposbit);
                printf ("resultado = %d\n", resultado);
                break;

            case 5:
                printf("Ejercicio 5: obtener valor bit\n");
                printf ("Elige un número\n");
                scanf("%d", &n);
                printf("Elige una posición de bit:\n");
                scanf("%d", &nposbit);
                resultado = obtenerValorBit(n, nposbit);
                printf ("resultado = %d\n", resultado);
                break;

            case 6:
                printf("Ejercicio 6: factorial\n");
                do
                {
                    printf("Introduzca un número entero positivo: ");
                    scanf("%ld", &yl);
                }
                while (yl < 0);
                xl = factorial(yl);
                if (xl== -1)
                    printf("No es posible calcular el factorial\n");
                else
                    printf("El factorial de %ld es: %ld\n\n", yl, xl);
                break;

            case 7:
                printf("Ejercicio 7: número de bits\n");
                do {
                    printf("Introduzca un número entero positivo: ");
                    scanf("%d", &n);
                } while ( n<= 0);
                nbits = numeroBits(n);
                printf("El número mínimo de bits necesarios para representar %d es: %d\n", n, nbits);
                break;

            case 8:
                printf("Ejercicio 8: cambiar bits\n");
                do {
                    printf("Introduzca un número entero positivo: ");
                    scanf("%d", &n);
                } while (n < 0);
                do {
                    printf("Posición del bit inicial a invertir (0 - 31): ");
                    scanf("%d", &p);
                } while (p < 0 || p > 31);
                do {
                    printf("Número de bits a invertir: ");
                    scanf("%d", &nbits);
                } while (nbits <= 0 || nbits > p + 1);
                resultado = cambiarBits(n, p, nbits);
                printf("\nNúmero original: %d\n", n);
                printf("Número transformado: %d\n", resultado);
                break;

            case 9:
            {
                printf("Ejercicio 9: intercambiar\n");
                double a, b;
                printf("Introduzca el primer número: ");
                scanf("%lf", &a);
                printf("Introduzca el segundo número: ");
                scanf("%lf", &b);
                intercambiar(&a, &b);
                printf("Primer número después del intercambio: %lf\n", a);
                printf("Segundo número después del intercambio: %lf\n", b);
                break;
            }

            default:
                printf ("ERROR: Opción incorrecta.\n");
                break;
        }
        opcion = menu();
    }
    return 0;
}

// DEFINICIONES DE FUNCIONES
int desplazar(int n, int nPos) {
    int nDesplazado = 0;
    nDesplazado = n >> nPos;
    return nDesplazado;
}

int parImpar(int n)
{
    int resultado = 0;
    if (n % 2 != 0) {
        resultado = 1;
    }
    return resultado;
}

void operacionesLogicasBits()
{
    int a = 8, b = 0, c = 15, d = 93, e, r1, r2, r3, r4, r5, r6;
    r1 = a && b || c && !d;
    r2 = !a || b && c || d;
    r3 = a < b || !c > d;
    r4 = a + b > d - c;
    r5 = a && b && !c || !(a && b) && c;
    a = 0x12;
    b = 0x56;
    c = 0x9a;
    d = 0x0f;
    e = 0360;
    r1 = a & b | c;
    r2 = c & 0177;
    r3 = ~a | b ^ c;
    r4 = e & c;
    r5 = r4 & ~077;
    r6 = (a & d) << 4 | (a & e) >> 4;
}

int ponerACeroBit(int n, int nPosBit)
{
    int resultado = 0, mascara;
    mascara = 1 << nPosBit;
    resultado = n & ~(mascara);
    return resultado;
}

int obtenerValorBit(int n, int nPosBit)
{
    int resultado = 0, mascara;
    mascara = 1 << nPosBit;
    int bit = n & mascara;
    resultado = bit >> nPosBit;
    return resultado;
}

long factorial(long n)
{
    long factorial = 1;
    if (n < 0 || n > 16) return -1;
    while (n > 0) {
        factorial = n * factorial;
        n = n - 1;
    }
    return factorial;
}

int numeroBits(int n)
{
    int dosElevadoN = 2, nbits = 1;
    while (dosElevadoN <= n)
    {
        dosElevadoN *= 2;
        nbits++;
    }
    return nbits;
}

int cambiarBits(int numero, int p, int n)
{
    if (n <= 0 || n > p + 1) {
        return -1;
    }
    int mascara = (1 << n) - 1;
    mascara <<= (p - n + 1);
    int resultado = numero ^ mascara;
    return resultado;
}

void intercambiar(double *x, double *y)
{
    double aux = *x;
    *x = *y;
    *y = aux;
}

int menu()
{
    int op;
    do
    {
        printf ("\n"
        "\t01.- Desplazar\n"
        "\t02.- Par o Impar\n"
        "\t03.- Operaciones lógicas y a nivel de bits \n"
        "\t04.- Poner a cero un bit \n"
        "\t05.- Obtener valor bit \n"
        "\t06.- Factorial \n"
        "\t07.- Número de bits \n"
        "\t08.- Cambiar bits \n"
        "\t09.- Intercambiar \n"
        "\t10.- Salir\n"
        "\n"
        "Elija una opción: ");
        scanf ("%d", &op);
        if (op < 1 || op > 10)
        {
            printf("Opci%cn no v%clida\n", 0xA2, 0xA0);
        }
    }
    while (op < 1 || op > 10);
    return op;
}



