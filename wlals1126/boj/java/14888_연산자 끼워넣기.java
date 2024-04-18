import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[] numbers;
    static int[] operators;
    static int min, max, count;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        count = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());

        numbers = new int[count];

        for (int i = 0; i < count; i++)
            numbers[i] = Integer.parseInt(st.nextToken());

        operators = new int[4];

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < 4; i++)
            operators[i] = Integer.parseInt(st.nextToken());

        max = Integer.MIN_VALUE;
        min = Integer.MAX_VALUE;
        calculateMinMax(0, numbers[0]);
        System.out.print(max + "\n" + min);
    }

    static void calculateMinMax(int index, int result) {
        if (index == count - 1) {
            max = Math.max(result, max);
            min = Math.min(result, min);
            return;
        }

        for (int i = 0; i < 4; i++) {
            if (operators[i] == 0)
                continue;

            operators[i]--;
            int nextResult = applyOperator(result, numbers[index + 1], i);
            calculateMinMax(index + 1, nextResult);
            operators[i]++;
        }
    }

    static int applyOperator(int a, int b, int operatorIndex) {
        switch (operatorIndex) {
            case 0: return a + b;
            case 1: return a - b;
            case 2: return a * b;
            case 3: return a / b;
            default: return 0;
        }
    }
}
