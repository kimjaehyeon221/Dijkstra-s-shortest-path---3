//// 32200983 �����ι��а� (sw���հ����濵����) ������ 
//// dijkstra's algorithm program�Դϴ�. 
//// �� ���α׷��� c++�� �����Ǿ����ϴ�. 
//
//#include <stdio.h>
//#include <limits.h> //int_max�� �̿��� �� �ְ� �����ִ� �������. 
//
//#define v 9 //�׷����� �������� ����
//typedef enum { false, true } bool;
//
////���������� ���� ������ �������� �ִܰŸ��� ���ϴ� ���α׷��Դϴ�. 
//int mindistance(int dist[], bool before_visit[])
//{
//    //������ �湮�� �� �ִ� before_visit, distance -> dist ���� 
//
//    int min = int_max, min_index; //�ڷ����� �ִ밪
//
//    for (int i = 0; i < v; i++) {
//        if (before_visit[i] == false && dist[i] <= min) {
//            //�湮������ �����鼭 �̵� �Ÿ��� �ּҰ����� ���� ��
//            min = dist[i], min_index = i;
//        }
//    }
//        
//
//    return min_index;
//}
//
////��θ� ������ִ� �Լ� 
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
////�Ÿ� �迭�� ������ִ� �Լ� 
//void printdistance(int dist[], int n, int parent[])
//{
//    int src = 0;
//    printf("������\t���������κ��� �Ÿ�\t���\n");
//    for (int i = 0; i < v; i++) {
//        printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i], src);
//        printpath(parent, i);
//    }
//}
//
//// dijkstra's algorithm function 
//void dijkstra(int graph[v][v], int src) //src�� �������� �ǹ��Ѵ�. 
//{
//    int dist[v]; // ���������κ���  �ִܰŸ��� �����ϴ� �迭. 
//    bool before_visit[v]; // �湮 ��� �迭
//    int parent[v]; // �θ� ��� ��� �迭
//
//   //�θ� ���� -1�� �ʱ�ȭ 
//    parent[0] = -1;
//    // �Ÿ��� infinite�� �ʱ�ȭ before_visit[]�� false�� �ʱ�ȭ
//    for (int i = 0; i < v; i++)
//        dist[i] = int_max, before_visit[i] = false;
//
//    // �������� ���������� �Ÿ��� 0
//    dist[src] = 0;
//
//    // ��� ���������� �ִܰŸ� �˻�
//    for (int count = 0; count < v - 1; count++) {
//
//        int u = mindistance(dist, before_visit); // �ִ� �Ÿ��� �������� ����Ѵ�.  ���� count�� 0�̸� �������̴�. 
//
//        before_visit[u] = true; //�湮 ���
//
//        //���� ����
//        for (int v = 0; v < v; v++) {
//            // �湮 ����� ���� ������ ���� edge�� �����ϰ� edge�� ���� ���� ���� �Ÿ����� ���� ��� ���� ����ؼ� �����س�����. 
//            if (!before_visit[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
//                parent[v] = u;
//                dist[v] = dist[u] + graph[u][v];
//            }
//        }
//
//        // ���������κ��� ���������� �ִܰŸ� ���
//        printdistance(dist, v, parent);
//    }
//}
//
//// �Լ��� ����
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