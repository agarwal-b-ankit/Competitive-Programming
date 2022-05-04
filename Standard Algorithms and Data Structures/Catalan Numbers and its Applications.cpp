#include <bits/stdc++.h>
using namespace std;

/*
	Catalan Numbers
	References: 
		https://cp-algorithms.com/combinatorics/catalan-numbers.html
		https://www.geeksforgeeks.org/applications-of-catalan-numbers/
	
	Cn = nth Catalan number
	Recursive Formula:
		Cn=1, n<2
		Cn = C0*Cn-1 + C1*Cn-2 + .... + Cn-2*C1 + Cn-1*C0, n>=2
	
	Analytical Formula:
		Cn = 2ncn/(n+1), c is binomical coefficient
	
	The first few Catalan numbers for n = 0 to 9 are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862.
	
	The Catalan number Cn is the solution for:
	1. The number of sequences a1,a2...,a2n of 2n terms that can be formed using n copies of 1's and n copies of -1's whose partial sums a1+a2+...+ak >=0 for k=1,2,...,2n.
	2. Number of correct bracket sequence consisting of n pairs of opening and closing brackets.
	3. The number of monotonic lattice paths from point (0,0) to point (n,n) in a square lattice of size n x n, which do not pass above the main diagonal.
	4. Number of Dyck paths of length 2n, which are sequences of equally-spaced northeast and southeast walks starting at the origin, ending on the xx-axis, and never going below the xx-axis. 
	5. The number of structurally different BST with n keys.
	6. The number of rooted full binary trees with n+1 leaves (vertices are not numbered). A rooted binary tree is full if every vertex has either two children or no children.
	7. The number of non-isomorphic full binary trees with n internal nodes (i.e. nodes having at least one son).
	8. The number of ways to completely parenthesize n+1 factors.
	9. The number of triangulations of a convex polygon with n+2 sides (i.e. the number of partitions of polygon into disjoint triangles by using the diagonals).
	10. The number of ways to connect the 2n points on a circle to form n disjoint chords.
	11. Number of permutations of length n that can be stack sorted (i.e. it can be shown that the rearrangement is stack sorted if and only if there is no such index i<j<k, such that ak<ai<aj).
	12. The number of non-crossing partitions of a set of n elements.
	13. The number of ways to cover the ladder(or staircase) 1...n using n rectangles (The ladder consists of n columns, where ith column has a height i).
	14. The Number of permutations of 1 to N such that no three terms of the permutation form an increasing subsequence.
*/

// T: O(n*n)
long catalan_dp(int n){
	long dp[n+1]={0};
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=n;i++)
		for(int j=0;j<i;j++)
			dp[i]+=dp[j]*dp[i-j-1];
	return dp[n];
}

long binomial(int n, int k){
	if(k==0) return 1;
	if(n-k<k) k=n-k;
	long res=1;
	for(int i=0;i<k;i++){
		res*=(n-i);
		res/=(i+1);
	}
	return res;
}

// T: O(n)
// nth catalan number is 2nCn/(n+1)
long catalan_binomial(int n){
    if(n==0) return 1;
	return binomial(2*n,n)/(n+1);
}

int main()
{
	//FastIO
	cout<<binomial(4,2)<<endl;
	for(int i=0;i<10;i++)
		cout<<catalan_dp(i)<<" "<<catalan_binomial(i)<<endl;
	return 0;
}
