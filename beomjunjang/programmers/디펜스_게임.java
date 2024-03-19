import java.util.*;

class Solution {
    public int solution(int n, int k, int[] enemy) {
        int answer = 0;
        boolean flag=false;
        int [] passList = new int[k];
        if(k >= enemy.length) return enemy.length;
        for(int i=0;i<k;i++){
            passList[i]=enemy[i];
        }
        Arrays.sort(passList);
        for(int i=k;i<enemy.length;i++){
            if(passList[0]<enemy[i]){
                n-=passList[0];
                passList[0]=enemy[i];
                for(int j=0;j<k-1;j++){
                    if(passList[j]>passList[j+1]){
                        int temp=passList[j];
                        passList[j]=passList[j+1];
                        passList[j+1]=temp;
                    }else{
                        break;
                    }
                }
            }else{
                n-=enemy[i];
            }
            if(n<0){
                flag=true;
                answer=i;
                break;
            }
        }
        if(flag) return answer;
        else return enemy.length;
    }
}
