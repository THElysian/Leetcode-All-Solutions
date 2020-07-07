/* Brute Force
	Iterate each bits of x and y in binary, if there is no match, increase count.
	Time Complexity - O(log(n))
	Space Complexity - O(1) but still take some space to store bits
*/
class solution {
	public :
		int hammingDistance(int x, int y) {
			vector<bool> X(31), Y(31);
			int i = 0;
			while (x) {
				X[i++] = x % 2;
				x >>= 1;
			}
			i = 0;
			while (y) {
				Y[i++] = x % 2;
				y >>= 1;
			}
			int count = 0;
			for (int i = 0; i < 31; i += 1) {
				if (X[i] != Y[i])
					count++;
			}
			return count;
		}
};

// Can we do better with space as well as time ?
//	Yup! We can use bitset insted of vector<bool>
// Any other improvement ?
//   	A little bit observation can lead us to find xor of x and y
//   	Why so ? Because, set bits in x^y is actually our answer
//   	As (1 xor 0) = 1 or (0 xor 1) = 1
//   		else 0;

/* Better Approach	   	 
	Time Complexity - O(log(n))
	Space Complexity - O(1)
*/
class solution {
	public :
		int countBits(int n) {
			unsigned int count = 0;
			while(n) {
				if (n & 1)
					count++;
				n >>= 1;
			}
			return count;
		}
	
		int hammingDistance(int x, int y) {
			return countBits( x^y );
		}
}

// Can we reduce number of iterations ?
//	Yup! We can.

/* Best Approach 
	Used - Brian Kernighan’s Algorithm
	Time Complexity - O(log(n))
	Space Complexity - O(1)
	Total iterations - number of set bits in x ^ y
*/
class solution {
	public :
		int countBits(unsigned int n) {
			unsigned int count = 0;
			while (n) {
				n &= (n-1);
				count++;
			}
			return count;
		}
		
		int hammingDistance(int x, int y) {
			return countBits( x^y );
		}
};
