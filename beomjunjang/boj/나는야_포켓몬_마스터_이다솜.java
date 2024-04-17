import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        Map<String,Integer> stringToInt = new HashMap<>();
        Map<Integer,String> intToString = new HashMap<>();
        for (int i=0;i<N;i++){
            String pocketMon = br.readLine();
            stringToInt.put(pocketMon,i+1);
            intToString.put(i+1,pocketMon);
        }
        for (int i=0;i<M;i++){
            String quiz = br.readLine();
            try {
                int num = Integer.parseInt(quiz);
                System.out.println(intToString.get(num));
            }catch (NumberFormatException e){
                System.out.println(stringToInt.get(quiz));
            }
        }
    }
}
나는야 포켓몬 마스터 이다솜
