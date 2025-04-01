using System;
using System.Collections.Generic;

class Solution {
    public static void bfs(int startX,int startY,int[,]map)
    {
        
        int[] dx = new int[4] { -1, 1, 0, 0 };
        int[] dy = new int[4] { 0, 0, -1, 1 };
        Queue<Tuple<int, int>> q = new Queue<Tuple<int, int>>();
             
        q.Enqueue(new Tuple<int, int>(startX, startY));
        while(q.Count!=0)
        {
             Tuple<int, int> cur = q.Dequeue();
             //int nowX = cur.Item1;
             //int nowY = cur.Item2;
            for(int i=0;i<4;i++)
            {
                  int nextX = cur.Item1 + dx[i];
                  int nextY = cur.Item2 + dy[i];
               
                
             if (0 <= nextX && nextX < map.GetLength(0)&& 0 <= nextY && nextY < map.GetLength(1) && map[nextX, nextY] == 1)
            {
             q.Enqueue(new Tuple<int, int>(nextX, nextY));
                 map[nextX,nextY]=map[cur.Item1,cur.Item2]+1;
            }
                
                
        }
        }
    }
    public int solution(int[,] maps) {
        int a=maps.GetLength(0);
        int b=maps.GetLength(1);
   
        bfs(0,0,maps);
        
        if(maps[a-1,b-1]==1)
            return -1;
        else
            return (maps[a-1,b-1]);
    }
}