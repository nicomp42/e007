/*
* Two numbers are coprime if they have no common factors except 1.
* The totient φ(n) of a positive integer n greater than 1 is defined to be the number of positive integers less than n that are coprime to n.
*
* Compute the sum of the totients of the first 10000 prime numbers

*/

#include <stdlib.h>
#include <stdio.h>

#include <math.h>

#define true -1;
#define false 0;
#define NUM_OF_PRIMES 10000
int isCoprime(int a, int b);
int getTotient(int a);
int isPrime(int a);
int primes[NUM_OF_PRIMES];
#include "init.h"

	void main(void) {

		int sum = 0;
		for (int i = 0; i < NUM_OF_PRIMES; i++) {
			sum += primes[i] - 1;	// Fermat's Little Theorem. http://www.doc.ic.ac.uk/~mrh/330tutor/ch05s02.html
		}
		printf("\n Sum of totients for the first 10000 primes = %d \n", sum);

		return;

		// Test totient calculation
		/*
		printf("\nTotient of 1 = %d", getTotient(1));
		printf("\nTotient of 2 = %d", getTotient(2));
		printf("\nTotient of 3 = %d", getTotient(3));
		printf("\nTotient of 10 = %d", getTotient(10));
		printf("\nTotient of 15 = %d", getTotient(15));
		return;
		*/
		// Test isCoprime calculation
		/*
		printf("\n isCoprime(1,1) = %d",   isCoprime(1, 1));
		printf("\n isCoprime(1,2) = %d",   isCoprime(1, 2));
		printf("\n isCoprime(10,20) = %d", isCoprime(10, 20));
		printf("\n isCoprime(5,11) = %d",   isCoprime(5, 11));
		printf("\n isCoprime(7,14) = %d",   isCoprime(7, 14));
		return;
		*/

		/* 
		'proof' that there are no prime totients
		int maxTotientSum = 0;

		for (int i = 1000; i < 100000; i++) {
			//if (isPrime(i)) {
			if (i % 1000 == 0) { printf("\ni = %d", i); }
			int totientI = getTotient(i);
			if (isPrime(totientI)) {
				printf("Bingo: i = %d,  totientI = %d", i, totientI);
			}
			//}
		}
		*/
		getc(stdin);
	}

	/**
	* Check the coprime-ness of two numbers
	* @param a First number
	* @param b Second number
	* @return True is a and b are coprime, false otherwise
	*/
	int isCoprime(int a, int b) {
		int result = true;
		int prime;
		if (a > b) { int c; c = a; a = b; b = c; }
		for (int i = 0; i < NUM_OF_PRIMES; i++) {
			prime = primes[i];
			if (prime > a) break;
			if ((a % prime) == 0 && (b % prime) == 0) { result = false; break; }
		}

		/*
		if ((a % 2) == 0 && (b % 2) == 0) {
			result = false;
		} else {
			for (int i = 3; i <= a; i += 2) {
				if ((a % i) == 0 && (b % i) == 0) { result = false; break; }
			}
		}
		*/
		return result;
	}
	int isPrime(int a) {
		int result = true;
		int limit = ((int)sqrt(a)) + 1;
		for (int i = 2; i < limit; i++) {
			if (a % i == 0) { result = false; break; }
		}
		return result;
	}
	/**
	* Compute the totient of an integer
	* @param a The number for which the totient is computed
	* @return The totient of a
	*/
	int getTotient(int a) {
		int totient = 1;
		//System.out.println("Checking coprimes for " + a);
		for (int i = 2; i < a; i++) {
			if (isCoprime(i, a)) {
				//System.out.println("Coprime = " + i);
				totient++;
			}
		}
		return totient;
	}
	