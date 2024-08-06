// Silver I
// Implementation
// Simulation

namespace Electing_Candidates_1713
{
    class Program
    {
        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int m = int.Parse(Console.ReadLine());
            int[] arr = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);

            // { 후보 번호, (추천수, 처음 게시한 시간) }
            Dictionary<int, (int recommendCount, int firstPostTime)> dict = new(); 
            
            for (int i = 0; i < m; i++)
            {
                if (dict.ContainsKey(arr[i]))
                {
                    // 이미 arr[i]번 사진틀이 존재하는 경우
                    // 추천수 + 1
                    
                    var value = dict[arr[i]];
                    value.recommendCount += 1;
                    dict[arr[i]] = value;
                } else if (dict.Count < n)
                {
                    // 비어 있는 사진틀이 있음
                    dict.Add(arr[i], (1, i));
                } else
                {
                    // 비어 있는 사진틀도 없고
                    // arr[i]번 후보가 사진틀에 있지도 않음

                    var minKvp = dict.OrderBy(kvp => kvp.Value.Item1)
                        .ThenBy(kvp => kvp.Value.Item2)
                        .First();
                    
                    dict.Remove(minKvp.Key);
                    dict.Add(arr[i], (1, i));
                }
            } // end of for

            foreach (var key in dict.Keys.OrderBy(k => k))
            {
                Console.WriteLine(key);
            }
        }
    }
}
