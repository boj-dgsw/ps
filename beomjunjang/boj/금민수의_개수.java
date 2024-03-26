import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int start = Integer.parseInt(st.nextToken());
        int end = Integer.parseInt(st.nextToken());
        int answer=0;
        boolean flag=true;
        int num;
        for(int i=start;i<=end;i++){
            flag=true;
            num=i;
            while (num!=0){
                if(num%10 !=4 && num%10!=7){
                    flag=false;
                    break;
                }
                num/=10;
            }
            if(flag) answer++;
        }
        System.out.println(answer);
    }
}
