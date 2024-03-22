import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int change = Integer.parseInt(br.readLine());
        int count5=0, count2=0;
        if(change>=5){
            count5+=change/5;
            change%=5;
        }
        while (true){
            count2+=change/2;
            change%=2;
            if(change==0 || count5==0) break;
            count5--;
            change+=5;
        }
        System.out.println(change==0 ? count2+count5 : -1);
    }
}
