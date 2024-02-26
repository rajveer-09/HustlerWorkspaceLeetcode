#define ll long long

class Solution {
public:
    // Binary exponentiation with mod
    ll power_mod(ll x, ll y,ll mod){ 
        ll res = 1ll; 
        while (y > 0ll){ 
            if (y & 1ll) res = (res*x)%mod; 
            y = y >> 1ll; 
            x = (x*x)%mod;
        }
        return res;
    }
    // Storing bits in a vector
    void intToBits(long long num, vector<int> &bits) {
        for (int i = 49; i >= 0; --i) {
            bits[i] = num & 1;
            num >>= 1;
        }
    }
    
    int maximumXorProduct(long long a, long long b, int n) {
        if(a<b) swap(a, b);
        vector<int> bits1(50), bits2(50);
        intToBits(a, bits1);
        intToBits(b, bits2);
        
        int flg=true;

        // Operation on last n bits
        for(int i=0; i<50; i++){
            if(bits1[i]==bits2[i] and i>=50-n) bits1[i]=bits2[i]=1;
            
            else if(bits1[i]!=bits2[i]){
                if(flg==false){
                    if(i>=50-n){ bits1[i]=0; bits2[i]=1;}
                }
                flg=false;
            }
        }

        int mod = 1e9+7;
        long long x=0, y=0;
        for(int i=0; i<50; i++){
            if(bits1[i]) x += power_mod(2, 49-i, mod);
            if(bits2[i]) y += power_mod(2, 49-i, mod);
            x%=mod; y%=mod;
        }
        
        int ans = (x*1ll*y)%mod;
        return ans;
    }
};