// Gold V
// DP
// Data Structures
// Hash Set

namespace InfiniteSequence_1351
{
    class Program
    {
        private static long _n, _p, _q;
        private static Dictionary<long, long> _dict = new();

        private static long GetAnswer(long n)
        {
            if (_dict.TryGetValue(n, out long ans))
            {
                return ans;
            }

            _dict[n] = GetAnswer(n / _p) + GetAnswer(n / _q);
            return _dict[n];
        }
        
        public static void Main(string[] args)
        {
            long[] line = Array.ConvertAll(Console.ReadLine().Split(), long.Parse);

            _n = line[0];
            _p = line[1];
            _q = line[2];

            _dict[0] = 1;
            Console.Write(GetAnswer(_n));
        }
    }
}
