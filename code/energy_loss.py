import numpy as np
import matplotlib.pyplot as plt

# Energy loss calculations
# Bethe-Bloch formula according to C.Grupen & B.Shwartz: Particle Detectors, Cambridge
def energy_loss():
    # Projectile and Target Data (Masses in a.m.u.)
    Z, M, ZT, MT = 2.0, 4.0, 13.0, 26.98  # alphas on 13Al
    # Z, M, ZT, MT = 1.0, 1.0, 6.0, 12.0  # Protons on 12C
    
    mc2 = M * 931.494  # Energy at rest in MeV
    
    # Energy limits
    Emin, Emax, nstep = 10.0, 100000.0, 10000  # Energy in MeV
    destep = (Emax - Emin) / nstep
    
    # Array initialization
    E = np.linspace(Emin, Emax, nstep)
    SP = np.zeros(nstep)

    # Loop on energy
    for ie in range(nstep):
        Etot = E[ie] + mc2
        p = np.sqrt(E[ie] ** 2 + 2.0 * E[ie] * mc2)
        beta = p / Etot
        gamma = 1.0 / np.sqrt(1.0 - beta ** 2)
        
        # mean ionization potential (I)
        IPOT = 16.0 * (ZT ** 0.9)
        if ZT == 1:
            IPOT = 21.8
        IPOT *= 1.0e-6  # conversion to MeV
        
        arg = 2.0 * 0.511 * gamma ** 2 * beta ** 2 / IPOT
        phi = np.log(arg) - beta ** 2
        
        # Stopping power (dE/dx)
        SP[ie] = 0.30707 * (ZT / MT) * Z ** 2 * phi / (beta ** 2)
    
    # Plot Stopping Power as a function of E
    plt.figure(figsize=(8, 6))
    plt.plot(E, SP, label="Stopping Power", color='b')
    plt.xlabel("Energy (MeV)")
    plt.ylabel("dE/dX (MeV cm²/g)")
    plt.title("Energy Loss (Bethe-Bloch)")
    plt.grid(True)
    plt.legend()
    plt.show()

# Execute the function
energy_loss()
