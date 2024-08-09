namespace CatCafe_28353
{
    class Program
    {
        public static void Main(string[] args)
        {
            int[] line = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            int n = line[0];
            int k = line[1];

            int[] arr = Array.ConvertAll(Console.ReadLine().Split(), int.Parse).OrderBy(x => x).ToArray();
            int left = 0;
            int right = arr.Length - 1;
            int ans = 0;

            while (left < right)
            {
                if (arr[left] + arr[right] <= k)
                {
                    ans += 1;
                    left += 1;
                    right -= 1;
                }
                else
                {
                    right -= 1;
                }
            } // end of while

            Console.Write(ans);
        }
    }
}
