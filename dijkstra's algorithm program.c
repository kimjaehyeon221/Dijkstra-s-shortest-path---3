// 32200983 �����ι��а� (SW���հ����濵����) ������ 
// Dijkstra's algorithm Program�Դϴ�. 
// �� ���α׷��� C++�� �����Ǿ����ϴ�. 

#include <stdio.h>
#include <limits.h> //INT_MAX�� �̿��� �� �ְ� �����ִ� �������. 

#define V 9 //�׷����� �������� ����
typedef enum { false, true } bool;

//���������� ���� ������ �������� �ִܰŸ��� ���ϴ� ���α׷��Դϴ�. 
int minDistance(int dist[], bool visited[])
{
    //������ �湮�� �� �ִ� before_visit, distance -> dist ���� 
    int min = INT_MAX, min_index = 0; //�ڷ����� �ִ밪

    for (int v = 0; v < V; v++) {
        //visited[v]�� false�̸鼭 dist[v]�� �ּҰ����� ���� ���
        if (visited[v] == false && dist[v] <= min) { //�湮������ �����鼭 �̵� �Ÿ��� �ּҰ����� ���� ��
            min = dist[v];
            min_index = v;
        }

    }
    return min_index;
}

//��θ� ������ִ� �Լ� 
void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);

    printf("%d ", j);
}


//�Ÿ� �迭�� ������ִ� �Լ� 
void printDistance(int dist[], int n, int parent[])
{
    int src = 0;
    printf("������\t���������κ��� �Ÿ�\t���\n");
    for (int i = 0; i < V; i++) {
        printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i], src);
        printPath(parent, i);
    }
    printf("\n");
}

// dijkstra's algorithm function 
void dijkstra(int graph[V][V], int src) //src�� �������� �ǹ��Ѵ�. 
{
    int dist[V]; // ���������κ���  �ִܰŸ��� �����ϴ� �迭. 
    bool before_visit[V]; // �湮 ��� �迭
    int parent[V]; // �θ� ��� ��� �迭

     // �Ÿ��� infinite�� �ʱ�ȭ before_visit[]�� false�� �ʱ�ȭ
    parent[0] = -1;   //�θ� ���� -1�� �ʱ�ȭ 
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        before_visit[i] = false;
    } 

    // �������� ���������� �Ÿ��� 0
    dist[src] = 0;

    // ��� ���������� �ִܰŸ� �˻�
    for (int count = 0; count < V - 1; count++) {

        int u = minDistance(dist, before_visit); // �ִ� �Ÿ��� �������� ����Ѵ�.  ���� count�� 0�̸� �������̴�. 

        before_visit[u] = true; //�湮 ���

        // ���� update���ش�.
        for (int v = 0; v < V; v++) {
            // �湮 ����� ���� ������ ���� edge�� �����ϰ� edge�� ���� ���� ���� �Ÿ����� ���� ��� ���� ����ؼ� �����س�����. 
            if (!before_visit[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    // ���������κ��� ���������� �ִܰŸ� ���
    printDistance(dist, V, parent);
    printf("\n");
}

// �Լ��� ����
int main()
{
    //test 1
    printf("Test 1\n");
    int graph1[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {5, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {0, 12, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    dijkstra(graph1, 0);


    //test 2
    printf("Test 2\n");
    int graph2[V][V] = {
      { 0, 6, 0, 0, 0, 0, 0, 8, 0 },
      { 6, 0, 8, 0, 0, 0, 0, 13, 0 },
      { 0, 8, 0, 7, 0, 6, 0, 0, 2 },
      { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
      { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
      { 0, 0, 6, 14, 10, 0, 2, 0, 0 },
      { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
      { 8, 13, 0, 0, 0, 0, 1, 0, 7 },
      { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
    };

    dijkstra(graph2, 0);

    //test 3
    printf("Test 3\n");
    int graph3[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 6, 0},
        {4, 0, 8, 0, 0, 0, 0, 1, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 3, 0, 9, 4, 0, 0, 0},
        {0, 0, 0, 9, 0, 1, 0, 0, 0},
        {0, 0, 2, 4, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {0, 2, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 2, 0, 0, 0, 4, 5, 0}
    };

    dijkstra(graph3, 0);

    return 0;
}