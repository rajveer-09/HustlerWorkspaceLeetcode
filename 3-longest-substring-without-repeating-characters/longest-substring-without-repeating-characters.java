class Solution {
    public int lengthOfLongestSubstring(String s) {
        int st = 0;
        int ans = 0;

        HashMap<Character, Integer>mpp =  new HashMap<>(); 
        for (int i = 0; i<s.length(); i++) {
            mpp.put(s.charAt(i) , mpp.getOrDefault(s.charAt(i) , 0) +1);
            while(mpp.get(s.charAt(i)) >1) {
                mpp.put(s.charAt(st), mpp.get(s.charAt(st)) -1);
                if(mpp.get(s.charAt(st)) == 0 ) {
                    mpp.remove(s.charAt(st));
                }
                st++;
            }

            ans = Math.max(ans,i-st+1);

        }
        return ans;
        
    }
}