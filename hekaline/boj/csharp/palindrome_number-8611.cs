using System.Numerics;

namespace PalindromeNumber_8611
{
    class Program
    {
        private static string ChangedSystem(BigInteger n, int system)
        {
            string ans = "";
            BigInteger bigSystem = new(system);

            while (n >= bigSystem * system)
            {
                bigSystem *= system;
            }

            if (bigSystem > n)
                bigSystem /= system;


            for (; bigSystem >= 1; bigSystem /= system)
            {
                ans += n / bigSystem;
                n %= bigSystem;
            }

            return ans;
        }

        private static bool IsPalindrome(string s)
        {
            for (int i = 0; i < s.Length / 2; i++)
            {
                if (s[i] != s[s.Length - 1 - i])
                    return false;
            }

            return true;
        }
        
        public static void Main(string[] args)
        {
            BigInteger n = BigInteger.Parse(Console.ReadLine());

            bool isPrinted = false;
            for (int i = 2; i <= 10; i++)
            {
                string systemNumber = ChangedSystem(n, i);

                if (IsPalindrome(systemNumber))
                {
                    Console.WriteLine(i + " " + systemNumber);
                    isPrinted = true;
                }
            }

            if (!isPrinted)
            {
                Console.WriteLine("NIE");
            }
        }
    }
}
