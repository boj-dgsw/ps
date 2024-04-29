class Solution {
    public long solution(int cap, int n, int[] deliveries, int[] pickups) {
        long answer = 0;
        int pick=0,deliver=0;
        for(int i=n-1;i>=0;i--){
            while(true){
                if(deliveries[i]==0 && pickups[i]==0) break;
                if(deliveries[i]>deliver || pickups[i]>pick){
                    deliver+=cap;
                    pick+=cap;
                    answer+=(i+1)*2;
                }
               
                
                if(deliveries[i]<=deliver){
                    deliver-=deliveries[i];
                    deliveries[i]=0;
                }else{
                    deliveries[i]-=deliver;
                    deliver=0;
                }
                
                if(pickups[i]<=pick){
                    pick-=pickups[i];
                    pickups[i]=0;
                }else{
                    pickups[i]-=pick;
                    pick=0;
                }
                
            }
        }
        return answer;
    }
}
