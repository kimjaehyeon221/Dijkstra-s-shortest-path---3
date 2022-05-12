//// 32200983 영미인문학과 (sw융합경제경영전공) 김재현 
//// dijkstra's algorithm program입니다. 
//// 이 프로그램은 c++로 구현되었습니다. 
//
//#include <stdio.h>
//#include <limits.h> //int_max를 이용할 수 있게 도와주는 헤더파일. 
//
//#define v 9 //그래프의 꼭짓점의 개수
//typedef enum { false, true } bool;
//
////시작점으로 부터 나머지 정점까지 최단거리를 구하는 프로그램입니다. 
//int mindistance(int dist[], bool before_visit[])
//{
//    //이전에 방문한 적 있는 before_visit, distance -> dist 변수 
//
//    int min = int_max, min_index; //자료형의 최대값
//
//    for (int i = 0; i < v; i++) {
//        if (before_visit[i] == false && dist[i] <= min) {
//            //방문한적이 없으면서 이동 거리가 최소값보다 작을 때
//            min = dist[i], min_index = i;
//        }
//    }
//        
//
//    return min_index;
//}
//
////경로를 출력해주는 함수 
//void printpath(int parent[], int j) {
//    if (parent[j] == -1)
//        return;
//
//    printpath(parent, parent[j]);
//
//    printf("%d ", j);
//}
//
//
////거리 배열을 출력해주는 함수 
//void printdistance(int dist[], int n, int parent[])
//{
//    int src = 0;
//    printf("꼭짓점\t시작점으로부터 거리\t경로\n");
//    for (int i = 0; i < v; i++) {
//        printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i], src);
//        printpath(parent, i);
//    }
//}
//
//// dijkstra's algorithm function 
//void dijkstra(int graph[v][v], int src) //src는 시작점을 의미한다. 
//{
//    int dist[v]; // 시작점으로부터  최단거리를 저장하는 배열. 
//    bool before_visit[v]; // 방문 기록 배열
//    int parent[v]; // 부모 노드 기록 배열
//
//   //부모 노드는 -1로 초기화 
//    parent[0] = -1;
//    // 거리는 infinite로 초기화 before_visit[]는 false로 초기화
//    for (int i = 0; i < v; i++)
//        dist[i] = int_max, before_visit[i] = false;
//
//    // 시작점과 시작점과의 거리는 0
//    dist[src] = 0;
//
//    // 모든 꼭짓점에서 최단거리 검색
//    for (int count = 0; count < v - 1; count++) {
//
//        int u = mindistance(dist, before_visit); // 최단 거리의 꼭짓점을 기록한다.  만약 count가 0이면 시작점이다. 
//
//        before_visit[u] = true; //방문 기록
//
//        //값을 갱신
//        for (int v = 0; v < v; v++) {
//            // 방문 기록이 없고 꼭짓점 끼리 edge가 존재하고 edge를 더한 값이 현재 거리보다 작은 경우 값을 계속해서 갱신해나간다. 
//            if (!before_visit[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
//                parent[v] = u;
//                dist[v] = dist[u] + graph[u][v];
//            }
//        }
//
//        // 시작점으로부터 꼭짓점들의 최단거리 출력
//        printdistance(dist, v, parent);
//    }
//}
//
//// 함수를 실행
//int main()
//{
//
//    int graph[v][v] = {
//        {0, 4, 0, 0, 0, 0, 0, 8, 0},
//        {5, 0, 8, 0, 0, 0, 0, 11, 0},
//        {0, 8, 0, 7, 0, 4, 0, 0, 2},
//        {0, 0, 7, 0, 9, 14, 0, 0, 0},
//        {0, 0, 0, 9, 0, 10, 0, 0, 0},
//        {0, 0, 4, 14, 10, 0, 2, 0, 0},
//        {0, 0, 0, 0, 0, 2, 0, 1, 6},
//        {0, 12, 0, 0, 0, 0, 1, 0, 7},
//        {0, 0, 2, 0, 0, 0, 6, 7, 0}
//    };
//
//    dijkstra(graph, 0);
//
//    return 0;
//}