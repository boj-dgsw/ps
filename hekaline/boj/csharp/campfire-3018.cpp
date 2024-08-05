namespace Campfire_3018
{
    class Program
    {
        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int e = int.Parse(Console.ReadLine());

            int sunyoungCnt = 0;
            var hashSets = new HashSet<int>[n + 1];
            for (int i = 1; i <= n; i++)
            {
                hashSets[i] = new();
            }

            for (int i = 1; i <= e; i++)
            {
                int[] arr = Array.ConvertAll(Console.ReadLine().Split(), int.Parse)[1..];
                if (arr.Contains(1))
                {
                    // 선영이가 있음
                    foreach (int member in arr)
                    {
                        hashSets[member].Add(i);
                    }

                    sunyoungCnt += 1;
                }
                else
                {
                    // 선영이가 없음
                    // 공유 해시셋
                    HashSet<int> temp = new();
                    foreach (int member in arr)
                    {
                        temp.UnionWith(hashSets[member]);
                    }

                    foreach (int member in arr)
                    {
                        hashSets[member].UnionWith(temp);
                    }
                }
            }

            for (int i = 1; i <= n; i++)
            {
                if (hashSets[i].Count == sunyoungCnt)
                {
                    Console.WriteLine(i);
                }
            }
        }
    }
}
