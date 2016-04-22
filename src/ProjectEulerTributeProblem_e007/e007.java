/*
 * Two numbers are coprime if they have no common factors except 1. 
 * The totient φ(n) of a positive integer n greater than 1 is defined to be the number of positive integers less than n that are coprime to n.
 * 
 * Compute the 
 */

package ProjectEulerTributeProblem_e007;

public class e007 {

	public static void main(String[] args) {
		
		// Test totient calculation
		//System.out.println("Totient of 10 = " + getTotient(10));
		
		
		
		
		int maxTotientSum = 0;
		for (int i = 2; i < 100000; i++) {
			for (int j = 0; j < 100000; j++) {
				if (i != j ) {
					if (isPrime(i) && isPrime(j) && isCoprime(i, j)) {
						int totientI = getTotient(i);
						int totientJ = getTotient(j);
						if ((totientI + totientJ) > maxTotientSum) {
							maxTotientSum = totientI + totientJ;
							System.out.println("new max totient = " + maxTotientSum);
						}
						
						//System.out.println("i = " + i + " j = " + j);
					}
				}
			}
		}
		System.out.println("maxTotientSum = " + maxTotientSum);
	}

	/**
	 * Check the coprime-ness of two numbers
	 * @param a First number
	 * @param b Second number
	 * @return True is a and b are coprime, false otherwise
	 */
	public static boolean isCoprime(int a, int b) {
		boolean result = true;
		
		if (a > b) {int c; c = a; a = b; b = c;} 
		
		for (int i = 2; i <= a; i++) {
			if ((a % i) == 0 && (b % i) == 0) {result = false; break;}
		}
		
		return result;
	}
	public static boolean isPrime(int a) {
		boolean result = true;
		int limit = ((int) Math.sqrt(a)) + 1;
		for (int i = 2; i < limit; i++) {
			if (a % i == 0) {result = false; break;}
		}
		return result;
	}
	/**
	 * Compute the totient of an integer
	 * @param a The number for which the totient is computed
	 * @return The totient of a
	 */
	public static int getTotient(int a) {
		int totient = 0;
		//System.out.println("Checking coprimes for " + a);
		for (int i = 2; i < a; i++) {
			if (isCoprime(i,a)) {
				//System.out.println("Coprime = " + i);
				totient++;
			}
		}
		
		return totient;
	}

}
