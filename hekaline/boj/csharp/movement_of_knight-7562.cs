namespace MovementOfKnight_7562
{
    class Program
    {
        public static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            Solver solver = new();
            
            for (int i = 0; i < t; i++)
            {
                Console.WriteLine(solver.GetAnswer());
            }
        }
    }
    
    class Solver
    {
        private int _l;
        private (int, int) _startCoord;
        private (int, int) _destCoord;

        private bool IsValid(int x, int y)
        {
            return x >= 0 && y >= 0 && x < _l && y < _l;
        }

        private bool IsValid((int, int) tuple)
        {
            return tuple.Item1 >= 0 && tuple.Item2 >= 0 &&
                   tuple.Item1 < _l && tuple.Item2 < _l;
        }

        private void GetInput()
        {
            _l = int.Parse(Console.ReadLine());
            var coord = Console.ReadLine().Split();
            _startCoord = (int.Parse(coord[0]), int.Parse(coord[1]));
            
            coord = Console.ReadLine().Split();
            _destCoord = (int.Parse(coord[0]), int.Parse(coord[1]));
        }
        
        public int GetAnswer()
        {
            GetInput();
            int[][] arr = new int[_l][];
            for (int i = 0; i < _l; i++)
            {
                arr[i] = new int[_l];
            }
            
            arr[_startCoord.Item1][_startCoord.Item2] = 1;
            
            Queue<(int, int)> q = new();
            q.Enqueue(_startCoord);

            while (q.Count != 0)
            {
                var coord = q.Dequeue();
                
                (int, int)[] offsets = 
                    {(-1, 2), (-2, 1), (-2, -1), (-1, -2), (1, -2), (2, -1), (2, 1), (1, 2)};

                foreach (var offset in offsets)
                {
                    var newCoord = (coord.Item1 + offset.Item1, coord.Item2 + offset.Item2);
                    if (!IsValid(newCoord) || arr[newCoord.Item1][newCoord.Item2] != 0) 
                        continue;
                    
                    arr[newCoord.Item1][newCoord.Item2] = arr[coord.Item1][coord.Item2] + 1;
                    q.Enqueue(newCoord);
                }
            }
            
            return arr[_destCoord.Item1][_destCoord.Item2] - 1;
        }
    }
}
