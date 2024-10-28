import mpmath
from mpmath import zeta, zetazero

# Set the precision for calculations
mpmath.mp.dps = 50  # Decimal places

def find_riemann_zeros(n):
    """
    Find the first n non-trivial zeros of the Riemann zeta function.

    :param n: Number of non-trivial zeros to find
    :return: A list of complex numbers representing the non-trivial zeros
    """
    zeros = [zetazero(k) for k in range(1, n + 1)]
    return zeros

def main():
    n = 10  # Number of non-trivial zeros to find
    zeros = find_riemann_zeros(n)
    
    print(f"The first {n} non-trivial zeros of the Riemann zeta function:")
    for i, zero in enumerate(zeros, 1):
        print(f"Zero {i}: {zero}")

if __name__ == "__main__":
    main()
