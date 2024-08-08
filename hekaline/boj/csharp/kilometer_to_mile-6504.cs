namespace KilometerToMile_6504
{
    class Program
    {
        private static List<int> _pibo = new() {1, 2, 3};

        private static int GetPiboAt(int n)
        {
            if (_pibo.Count > n) 
                return _pibo[n];

            for (int i = _pibo.Count; i <= n; i++)
            {
                _pibo.Add(_pibo[i - 1] + _pibo[i - 2]);
            }

            return _pibo[n];
        }

        private static int IntToPibo(int n)
        {
            int nPibo = 0;
            
            for (int i = 31; i >= 0; i--)
            {
                if (GetPiboAt(i) <= n)
                {
                    nPibo |= (1 << i);
                    n -= GetPiboAt(i);
                }
            }

            nPibo >>= 1;
            int ans = 0;

            for (int i = 31; i >= 0; i--)
            {
                if ((nPibo & (1 << i)) != 0)
                {
                    ans += GetPiboAt(i);
                }
            }

            return ans;
        }
        
        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());

            for (int i = 0; i < n; i++)
            {
                int x = int.Parse(Console.ReadLine());
                Console.WriteLine(IntToPibo(x));
            }
        }
    }
}
