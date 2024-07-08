import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();  
        double totalScore = 0;

        for (int i = 0; i < N; i++) {
            double S = sc.nextDouble();
            int A = sc.nextInt();
            int T = sc.nextInt();
            int M = sc.nextInt();

            double score = (S * (1 + 1.0 / A) * (1 + (double) M / T)) / 4;
            totalScore += score;
        }

        int P = sc.nextInt(); 
        List<Double> scores = new ArrayList<>();

        for (int i = 0; i < P; i++) {
            scores.add(sc.nextDouble());
        }

        scores.add(totalScore);

        Collections.sort(scores, Collections.reverseOrder());

        int rank = scores.indexOf(totalScore) + 1;

        double percentage = rank * 1.0 / (P + 1);
        boolean isTop15Percent = percentage <= 0.15;

        System.out.printf("The total score of Younghoon%s is %.2f.%n",
                isTop15Percent ? " \"The God\"" : "", totalScore);
    }
}
