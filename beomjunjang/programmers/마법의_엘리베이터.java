class Solution {
    public int solution(int st) {
        int answer = 0;
        while(st!=0){
            int num=st%10;
            st/=10;
            if(num==5){
                if(st%10>=5){
                    st++;
                    answer+=10-num;
                }else{
                    answer+=num;
                }
            }
            else if(num>5){
                st++;
                answer+=10-num;
            }else{
                answer+=num;
            }
        }
        return answer;
    }
}
