import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int gameCount;
    static String[] guesses;
    static int[] strikes;
    static int[] balls;
    static int totalCount = 0;
    static final int MAX_DIGITS = 3;
    static final int MAX_NUMBER = 9;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        gameCount = Integer.parseInt(br.readLine());
        guesses = new String[gameCount];
        strikes = new int[gameCount];
        balls = new int[gameCount];

        for (int i = 0; i < gameCount; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            guesses[i] = st.nextToken();
            strikes[i] = Integer.parseInt(st.nextToken());
            balls[i] = Integer.parseInt(st.nextToken());
        }

        int[] numbers = new int[MAX_NUMBER];
        for (int i = 0; i < MAX_NUMBER; i++) {
            numbers[i] = i + 1;
        }

        int[] permutationOutput = new int[MAX_DIGITS];
        boolean[] visited = new boolean[MAX_NUMBER];

        permutation(numbers, permutationOutput, visited, 0, MAX_NUMBER, MAX_DIGITS);

        System.out.println(totalCount);
    }

    public static void permutation(int[] numbers, int[] output, boolean[] visited, int depth, int n, int r) {
        if (depth == r) {
            StringBuilder result = new StringBuilder();
            for (int i = 0; i < r; i++) {
                result.append(output[i]);
            }
            if (check(result.toString())) {
                totalCount++;
            }
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                output[depth] = numbers[i];
                permutation(numbers, output, visited, depth + 1, n, r);
                visited[i] = false;
            }
        }
    }

    public static boolean check(String result) {
        for (int i = 0; i < gameCount; i++) {
            String guess = guesses[i];
            int strikeCount = 0;
            int ballCount = 0;

            for (int j = 0; j < result.length(); j++) {
                char resultDigit = result.charAt(j);
                char guessDigit = guess.charAt(j);

                if (resultDigit == guessDigit) {
                    strikeCount++;
                } else if (guess.contains(Character.toString(resultDigit))) {
                    ballCount++;
                }
            }

            if (strikeCount != strikes[i] || ballCount != balls[i]) {
                return false;
            }
        }
        return true;
    }
}
