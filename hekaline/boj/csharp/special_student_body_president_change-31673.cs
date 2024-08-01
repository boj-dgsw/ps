namespace SpecialStudentBodyPresidentChange_31673
{
    class Program
    {
        public static void Main(string[] args)
        {
            string[] firstLine = Console.ReadLine().Split();
            int n = int.Parse(firstLine[0]);
            int m = int.Parse(firstLine[1]);

            int[] votes = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            Array.Sort(votes);
            
            long left = 0;
            long right = 0;
            int i;

            foreach (var vote in votes)
            {
                left += vote;
            }
            
            for (i = n - 1; i >= 0; i--)
            {
                left -= votes[i];
                right += votes[i];
                
                if (left <= right)
                {
                    break;
                }
            }

            Console.Write(m / (n - i + 1));
        }
    }
}
