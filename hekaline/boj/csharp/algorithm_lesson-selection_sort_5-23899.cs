// Bronze I
// Implementation
// Sorting
// Simulation

namespace AlgorithmLesson_SelectionSort_5_23899
{
    class Program
    {
        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());

            int[] a = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            int[] b = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            
            if (Enumerable.SequenceEqual(a, b))
            {
                Console.Write(1);
                return;
            }
            
            for (int i = n - 1; i >= 1; i--)
            {
                int biggestIndex = 0;
                for (int j = 0; j <= i; j++)
                {
                    if (a[biggestIndex] < a[j])
                        biggestIndex = j;
                }

                if (i != biggestIndex)
                {
                    (a[i], a[biggestIndex]) = (a[biggestIndex], a[i]);
                }
                if (Enumerable.SequenceEqual(a, b))
                {
                    Console.Write(1);
                    return;
                }
            }
            
            Console.Write(0);
        }
    }
}
