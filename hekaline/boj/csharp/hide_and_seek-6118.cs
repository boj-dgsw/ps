using System;

namespace HideAndSeek_6118
{
    class Program
    {
        private static List<List<int>> _arr = Enumerable.Range(0, 20001)
            .Select(x => new List<int>())
            .ToList();
        
        public static void Main(string[] args)
        {
            int[] line = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            int n = line[0], m = line[1];

            for (int i = 0; i < m; i++)
            {
                int[] ab = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
                int a = ab[0], b = ab[1];

                _arr[a].Add(b);
                _arr[b].Add(a);
            }

            var ans = GetAnswer();

            Console.WriteLine(ans.barnNumToHide);
            Console.WriteLine(ans.maxDist);
            Console.WriteLine(ans.sameDistCnt);
        }

        private static (int barnNumToHide, int maxDist, int sameDistCnt) GetAnswer()
        {
            int barnNumToHide = -1;
            int maxDist = 0;
            int sameDistCnt = 0;

            Queue<int> q = new();
            List<int> dist = Enumerable.Repeat(40000, 20001).ToList();

            dist[1] = 0;
            q.Enqueue(1);

            while (q.Count != 0)
            {
                int currIdx = q.Dequeue();
                int currDist = dist[currIdx];

                foreach (int nextIdx in _arr[currIdx])
                {
                    if (dist[nextIdx] > currDist + 1)
                    {
                        dist[nextIdx] = currDist + 1;
                        q.Enqueue(nextIdx);

                        maxDist = Math.Max(maxDist, dist[nextIdx]);
                    }
                }
            } // end of while

            for (int i = 1; i <= 20000; i++)
            {
                if (dist[i] == maxDist)
                {
                    if (barnNumToHide == -1)
                    {
                        barnNumToHide = i;
                    }

                    sameDistCnt += 1;
                }
            }

            return (barnNumToHide, maxDist, sameDistCnt);
        }
    }
}
