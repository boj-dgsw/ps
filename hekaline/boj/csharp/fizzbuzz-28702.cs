namespace FizzBuzz_28702
{
    class Program
    {
        private static string Ans(int n)
        {
            bool divBy3 = n % 3 == 0;
            bool divBy5 = n % 5 == 0;

            return divBy3 && divBy5 ? "FizzBuzz" : divBy3 ? "Fizz" : divBy5 ? "Buzz" : n.ToString();
        }
      
        public static void Main(string[] args)
        {
            for (int i = 0; i < 3; i++)
            {
                string s = Console.ReadLine();
                int si;

                if (int.TryParse(s, out si))
                {
                    Console.Write(Ans(si + 3 - i));
                    return;
                }
            }
        }
    }
}
