class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        Arrays.sort(happiness);
        int dec = 0;
        long max=0;
        int value=0;
        for(int i=happiness.length-1;i>=happiness.length-k;i--){
            value = happiness[i]-dec;
            dec++;
            if(value>0)
            {
                max += value;
            }
        }
        return max;
    }
}