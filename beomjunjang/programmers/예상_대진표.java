class Solution{
    public int solution(int n, int a, int b){
        int answer=1;
        for(int i=2;i<n;i*=2){
            answer++;
        }
        int s=1,l=n;
        int m=(s+l)/2;
        boolean flag=true;
        if(a>b){
            int temp=a;
            a=b;
            b=temp;
        }
        while(flag){
            flag=false;
            if(s<=a && m>=b){
                l=m;
                m=(s+l)/2;
                flag=true;
            } else if(m<a && l>=b){
                s=m+1;
                m=(s+l)/2;
                flag=true;
            } 
            if(flag) answer--;
        }

        return answer;
    }
}
