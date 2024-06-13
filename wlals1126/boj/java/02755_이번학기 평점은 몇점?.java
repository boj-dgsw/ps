import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int totalCredits = 0;
        double totalPoints = 0;

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            st.nextToken();
            int credits = Integer.parseInt(st.nextToken());
            String grade = st.nextToken();

            double gradePoints = getGradePoints(grade);
            totalCredits += credits;
            totalPoints += credits * gradePoints;
        }

        double gpa = totalPoints / totalCredits;
        System.out.printf("%.2f", gpa);
    }

    private static double getGradePoints(String grade) {
        double points = 0.0;
        switch (grade.charAt(0)) {
            case 'A':
                points = 4.0;
                break;
            case 'B':
                points = 3.0;
                break;
            case 'C':
                points = 2.0;
                break;
            case 'D':
                points = 1.0;
                break;
            case 'F':
                points = 0.0;
                break;
        }
        if (grade.length() > 1) {
            if (grade.charAt(1) == '+') {
                points += 0.3;
            } else if (grade.charAt(1) == '-') {
                points -= 0.3;
            }
        }
        return points;
    }
}
