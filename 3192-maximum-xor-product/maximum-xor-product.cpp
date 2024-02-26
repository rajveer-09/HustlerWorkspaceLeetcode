class Solution {
public:
    // Function to convert a number into its binary representation
    vector<int> bits(long long x, int n)
    {
        vector<int> v(50, 0);  // Initialize a vector to store binary bits with a maximum size of 50
        int j = 0;
        while (x > 0)
        {
            v[j] = x % 2;  // Store the remainder of the division (binary digit) in the vector
            x = x / 2;     // Divide the number by 2 to move to the next binary digit
            j++;
        }

        return v;
    }

    // Function to convert binary representation back to decimal
    long long func(vector<int>& bits_x, int n)
    {
        long long ans = 0;
        for (int i = 0; i < 50; i++)
        {
            ans += bits_x[i] * pow(2, i);  // Convert binary bits to decimal using powers of 2
        }
        return ans;
    }

    // Main function to find the maximum XOR product
    int maximumXorProduct(long long a, long long b, int n)
    {
        long long MOD = pow(10, 9) + 7;

        // Base case: If n is 0, return the product of a and b modulo 10^9 + 7
        if (n == 0)
            return ((a % MOD) * (b % MOD)) % MOD;

        // Convert integers a and b to their binary representations
        vector<int> bits_a = bits(a, n);
        vector<int> bits_b = bits(b, n);
        vector<int> bits_x(50, 0);  // Initialize a vector to store the binary representation of x

        long long val_a = 0;
        long long val_b = 0;

        // Iterate from the Most Significant Bit (MSB) to the (n-1)-th bit
        for (int i = 49; i >= n; i--)
        {
            val_a += pow(2, i) * bits_a[i];
            val_b += pow(2, i) * bits_b[i];
        }

        // Iterate from the (n-1)-th bit to the 0-th bit
        for (int i = n - 1; i >= 0; i--)
        {
            if (bits_a[i] == 0 && bits_b[i] == 0)
            {
                bits_x[i] = 1;
                val_a += pow(2, i);
                val_b += pow(2, i);
            }
            else if (bits_a[i] == 1 && bits_b[i] == 1)
            {
                bits_x[i] = 0;
                val_a += pow(2, i);
                val_b += pow(2, i);
            }
            else
            {
                if (val_a < val_b)
                {
                    bits_x[i] = bits_b[i];
                    val_a += pow(2, i);
                }
                else if (val_a >= val_b)
                {
                    bits_x[i] = bits_a[i];
                    val_b += pow(2, i);
                }
            }
        }

        // Convert binary representation of x back to decimal
        long long ans = func(bits_x, n);
        long long val1 = a ^ ans;  // XOR of a and x
        long long val2 = b ^ ans;  // XOR of b and x

        // Calculate the final answer (product of val1 and val2) modulo 10^9 + 7
        long long fin_ans = ((val1 % MOD) * (val2 % MOD)) % MOD;

        return fin_ans;
    }
};