#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define STRLEN  1024
#define ME      0.511   /* mass of electron in MeV / c^2 */
#define K       0.307   /* constant K in Bethe--Bloch's formula */
#define I       173.0   /* mean excitation energy in Al */

/* INC = projectile, TAR = target */
#define Z_INC   2.0     /* number of protons in projectile */
#define M_INC   2807.0  /* mass of projectile in MeV / c^2 (4He) */
#define T_INC   5.0     /* kynetic energy of projectile (MeV) */
#define Z_TAR   13.0    /* number of protons in target (Al) */
#define A_TAR   27.0    /* number of nucleons in target (Al) */
#define R_TAR   2.7     /* target density */
#define X_TAR   0.0020  /* target thickness (cm) */

#define FILE_PATH       "path/to/file"
#define MAX(A,B)        (A > B) ? A : B

double wmax(double m_e, double beta2, double gamma, double gamma2, double m, double m2);
double bethe(double k, double m_e, double z_inc, double z_tar, double a_tar, double r_tar, double beta2, double gamma2, double w_max, double i);

int main() {
    double x, dx, E_tot, T, stop;
    double gamma, gamma2, beta2, m, m2;
    int step;
    char buffer[STRLEN];
    FILE *pf;

    printf("Step number: ");
    scanf("%s", buffer);
    
    if (0 >= (step = atoi(buffer))) goto err_step;
    if (NULL == (pf = fopen(FILE_PATH, "w"))) goto err_file;

    dx  = X_TAR / step;
    m   = ME / M_INC;
    m2  = m*m;

    for (T = T_INC, x = 0; (x < X_TAR) && (T >= 0); x += dx) {
        E_tot = T + M_INC;              |\label{ln:bet:T-start}|
        gamma = E_tot / M_INC;
        gamma2 = gamma * gamma;
        beta2 = 1.0 - (1.0 / (gamma2)); |\label{ln:bet:T-end}|

        stop = MAX(bethe(K, M_E, Z_INC, Z_TAR, A_TAR, R_TAR, beta2, gamma2, wmax(ME, beta2, gamma, gamma2, m, m2), I), 0); |\label{ln:bet:bethe-call}|

        fprintf(pf, "%.8f %.8f %.8f\n", x, T, stop);
        T = MAX(T - (stop * dx), 0);
    }

    fclose(pf);
    return EXIT_SUCCESS;

    err_step:
        printf("Step number musts be positive\n");
        return EXIT_FAILURE;

    err_file:
        printf("File at '%s' not found or could not be open\n", FILE_PATH);
        return EXIT_FAILURE;
}

double wmax(double m_e, double beta2, double gamma, double gamma2, double m, double m2) {
    return (2.0 * ME * beta2 * gamma2) / (1.0 + (2.0 * gamma * m) + m2);
}

double bethe(double k, double m_e, double z_inc, double z_tar, double a_tar, double r_tar, double beta2, double gamma2, double w_max, double i) {|\label{ln:bet:bethe-def}|
    return r_tar * (((k * z_inc * z_inc * z_tar) / (a_tar * beta2)) * (0.5 * log((2.0 * m_e * beta2 * gamma2 * w_max) / (i * i * 1.0e-12)) - beta2));
}