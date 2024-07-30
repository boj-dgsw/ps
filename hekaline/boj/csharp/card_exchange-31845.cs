// Silver III
// Greedy
// Simulation
// Sorting
// Implementation

namespace Card_Exchange_31845
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string[] firstLine = Console.ReadLine().Split();
            int n = int.Parse(firstLine[0]);
            int m = int.Parse(firstLine[1]);

            string[] secondLine = Console.ReadLine().Split();
            int[] arr = Array.ConvertAll(secondLine, int.Parse);
            Array.Sort(arr);

            int ans = 0;
            int left = 0;
            int turn = 0;
            int right = arr.Length - 1;
            bool canGetEmptyCard = true;
            
            while (left < arr.Length && right >= left && turn++ < m)
            {
                if (arr[right] >= 0 || !canGetEmptyCard)
                {
                    // Console.WriteLine($"Took same one with index {right} : {arr[right]}");
                    ans += arr[right--];
                    if (left > right) break;
                } else if (canGetEmptyCard)
                {
                    // Take empty card
                    // Console.WriteLine("Took empty card");
                    canGetEmptyCard = false;
                }

                if (!canGetEmptyCard)
                {
                    // Console.WriteLine("Gave empty card");
                    canGetEmptyCard = true;
                } else
                {
                    // Console.WriteLine($"Gave card index {left} : {arr[left]}");
                    left++;
                    if (left > right) break;
                }
            }

            Console.Write(ans);
        }
    }
}
