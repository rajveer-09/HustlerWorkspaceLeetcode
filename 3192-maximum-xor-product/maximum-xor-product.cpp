class Solution {
public:
     int mod=1e9+7;
    int maximumXorProduct(long long a, long long b, int n) {
        
        //set bits where both a and b are having 0
        for(long long i=0;  i<n ; i++){
            if((((a>>i)&1LL)==0) &&  (((b>>i)&1LL)==0)){
                a|=(1LL<<i);
                b|=(1LL<<i);
            }  
        }
        
        //Now for the minimum of two set all those bits of mini and unset all those bits of maxi where both bits differ(except the first from left and should be valid bit(< n))
        bool chk=true;
        long long mini=min(a,b);
        long long maxi=max(a,b);
        for(long long i=50 ; i>=0 ; i-- ){
            if(i<n){
                if((((mini>>i)&1LL) !=  (((maxi>>i)&1LL)))){
                    if(chk){
                        mini^=(1LL<<i);
                        maxi^=(1LL<<i);
                        long long temp=mini;
                        mini=maxi;
                        maxi=temp;
                        chk=false;
                        continue;
                    }
                    if((mini>>i)&1LL){
                    
                    }
                    else{
                        mini^=(1LL<<i);
                        maxi^=(1LL<<i);
                    }
                } 
            }
            else{
                if((((mini>>i)&1LL) !=  (((maxi>>i)&1LL)))){
                    chk=false;
                }
            }
        }
               
        long long ans=((mini%mod)*(maxi%mod))%mod;
        return ans; 
    }
};