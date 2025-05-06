#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STRLEN  1024
#define ME      0.511
#define K       0.307
#define I       173.0

#define Z_INC   2.0
#define M_INC   2807.0
#define Z_TAR   14.0
#define A_TAR   28.0

#define E_MAX   10.0
#define E_MIN   1.0

#define FILE_PATH   "dati-bethe.txt"

int myexit(int code, FILE *pf, double *E);

int main() {
    double dE, E_tot, E;
    double gamma, gamma2, beta, beta2, m ,m2;
    double W_max, stop;
    int step;
    char buffer[STRLEN];
    FILE *pf;

    printf("Numero step: ");
    scanf("%s", buffer);
    
    if (0 >= (step = atoi(buffer))) goto err_step;
    if (NULL == (pf = fopen(FILE_PATH, "w"))) goto err_file;

    fprintf(pf, "Energia dE/dx\n");
    dE = (E_MAX - E_MIN) / step;
    m = ME / M_INC;
    m2 = m*m;
    for (E = E_MIN; E < E_MAX; E += dE) {
        E_tot = E + M_INC;
        gamma = E_tot / M_INC;
        gamma2 = gamma * gamma;
        beta = sqrt(1.0 - (1.0 / (gamma2)));
        beta2 = beta * beta;
        W_max = (2.0 * ME * beta2 * gamma2) / (1.0 + (2.0 * gamma * m) + m2);
        stop = ((K * Z_INC * Z_INC * Z_TAR) / (A_TAR * beta2)) * (0.5 * log((2.0 * ME * beta2 * gamma2 * W_max) / (I * I * 1.0e-12)) - beta2);
        fprintf(pf, "%f %f\n", E, stop);
    }

    fclose(pf);
    return EXIT_SUCCESS;

    err_step:
        printf("Step number musts be positive\n");
        return EXIT_FAILURE;

    err_file:
        printf("File at '%s' not found or impossible to open\n", FILE_PATH);
        return EXIT_FAILURE;
}
