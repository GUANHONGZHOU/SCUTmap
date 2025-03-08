#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define MAXV 20
#define INF 32767

struct VertexType {
    string name;
    string introduction;
}; // ��������

struct MatGraph {
    int edges[MAXV][MAXV];
    int n, e;
    VertexType vexs[MAXV];
}; // �ڽӾ���

MatGraph g;

// ��ʼ����ͼ
void InitMap(MatGraph &g) {
    g.n = 10;
    g.e = 16;
    for (int i = 0; i < g.n; i++) {
        for (int j = 0; j < g.n; j++) {
            if (i == j)
                g.edges[i][j] = 0;
            else
                g.edges[i][j] = INF;
        }
    }
    g.edges[0][1] = 1; g.edges[0][2] = 4;
    g.edges[1][0] = 1; g.edges[1][2] = 2; g.edges[1][3] = 10;
    g.edges[2][0] = 4; g.edges[2][1] = 2; g.edges[2][3] = 8; g.edges[2][4] = 9;
    g.edges[3][1] = 10; g.edges[3][2] = 8; g.edges[3][6] = 6; g.edges[3][5] = 3;
    g.edges[4][2] = 9; g.edges[4][5] = 9; g.edges[4][7] = 4; g.edges[4][8] = 11; g.edges[4][9] = 6;
    g.edges[5][3] = 3; g.edges[5][4] = 9; g.edges[5][6] = 4; g.edges[5][7] = 7;
    g.edges[6][3] = 6; g.edges[6][5] = 4;
    g.edges[7][5] = 7; g.edges[7][4] = 4; g.edges[7][9] = 5;
    g.edges[8][4] = 11; g.edges[8][9] = 6;
    g.edges[9][7] = 5; g.edges[9][4] = 6; g.edges[9][8] = 6;

    g.vexs[0].name = "��ѧ¥"; g.vexs[0].introduction = "����ѧԺѧ��ƽʱ�Ͽεĵط�����Ư����ӣ��";
    g.vexs[1].name = "����"; g.vexs[1].introduction = "�ܶ����ѧ������ɢ������";
    g.vexs[2].name = "��Уѵʯ"; g.vexs[2].introduction = "�кܶ�Сè";
    g.vexs[3].name = "�ݷ����Ĺ�"; g.vexs[3].introduction = "�ܶཨУ����";
    g.vexs[4].name = "����"; g.vexs[4].introduction = "�����";
    g.vexs[5].name = "У��֮��"; g.vexs[5].introduction = "���Ժȿ���";
    g.vexs[6].name = "ҽԺ"; g.vexs[6].introduction = "ϣ�����ò���";
    g.vexs[7].name = "����ɽ������"; g.vexs[7].introduction = "�������д�";
    g.vexs[8].name = "������Ӿ��"; g.vexs[8].introduction = "������Ӿ�أ��Ƽ�";
    g.vexs[9].name = "ͼ���"; g.vexs[9].introduction = "����֮��ѧ����ѧϰ��";
}

// ������·��
void Display(MatGraph g, int A[][MAXV], int path[][MAXV], int num1, int num2) {
    int apath[MAXV], d, k;
    if (A[num1][num2] != INF && num1 != num2) {
        cout << num1 << "��" << num2 << "�����·��Ϊ��" << endl;
        k = path[num1][num2];
        d = 0; apath[d] = num2;
        while (k != num1) {
            d++;
            apath[d] = k;
            k = path[num1][k];
        }
        d++;
        apath[d] = num1;
        for (int i = d; i >= 1; i--) {
            cout << apath[i] << "-->";
        }
        cout << apath[0];
        cout << endl;
        cout << num1 << "��" << num2 << "���·������Ϊ��" << A[num1][num2] << endl;
    }
}

// Floyd�㷨
void Floyd(MatGraph g) {
    int num1, num2;
    cout << "��������Ҫ���ҵ����������ţ�" << endl;
    cin >> num1 >> num2;
    if (num1 < 0 || num1 >= g.n || num2 < 0 || num2 >= g.n) {
        cout << "����ľ����Ų��Ϸ���" << endl;
        return;
    }

    int A[MAXV][MAXV], path[MAXV][MAXV];
    for (int i = 0; i < g.n; i++) {
        for (int j = 0; j < g.n; j++) {
            A[i][j] = g.edges[i][j];
            if (i != j && g.edges[i][j] != INF) {
                path[i][j] = i;
            } else {
                path[i][j] = -1;
            }
        }
    }

    for (int k = 0; k < g.n; k++) {
        for (int i = 0; i < g.n; i++) {
            for (int j = 0; j < g.n; j++) {
                if (A[i][j] > A[i][k] + A[k][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }

    Display(g, A, path, num1, num2);
}

// ��ҳ
void menu() {
    printf(" ����������������������������������������������������������������������������������������������������������������\n");
	printf(" �� �q �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T �r  ��\n");
	printf(" �� ����        �� ӭ ʹ �� У ԰ �� �� ϵ ͳ          ����  ��\n");
	printf(" �� �t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T �s  ��\n");
	printf(" ��                      ��ӭ����                        ��\n");
	printf(" ��                ��������ѧ��ɽУ��                  ��\n");
	printf(" ��                     �� �� ѡ ��                      ��\n");
	printf(" ��  ****************************************************��\n");
	printf(" ��  * 1.�鿴У԰��ͼ           ** 2.��ѯ��������·�� *��\n");
	printf(" ��  ****************************************************��\n");
	printf(" ��  * 3.��ѯ�����������·�� ** 4.ѧУ�������       *��\n");
	printf(" ��  ****************************************************��\n");
	printf(" ��  * 5.����ͼ��Ϣ             **   0.�˳�             *��\n");
	printf(" ��  *************************************************** ��\n");
	printf(" ����������������������������������������������������������������������������������������������������������������\n");
}

// Dijkstra�㷨
void dijkstra(MatGraph g, int v, int dist[], int path[]) {
    int S[MAXV];
    int mindist, i, j, u;
    for (i = 0; i < g.n; i++) {
        dist[i] = g.edges[v][i]; // ��ʼ������
        S[i] = 0; // ��S�ÿգ�S[i]=1��ʾ�ѱ��
        if (g.edges[v][i] < INF)
            path[i] = v;
        else
            path[i] = -1; // ��ʼ�㿪ʼû��
    }
    S[v] = 1; path[v] = 0;
    for (i = 0; i < g.n - 1; i++) {
        mindist = INF;
        for (j = 0; j < g.n; j++)
            if (S[j] == 0 && dist[j] < mindist) {
                u = j;
                mindist = dist[j];
            }
        S[u] = 1; // ����u����S��
        for (j = 0; j < g.n; j++) // ����δ��ǵĶ�������·��
            if (S[j] == 0)
                if (g.edges[u][j] < INF && dist[u] + g.edges[u][j] < dist[j]) {
                    dist[j] = dist[u] + g.edges[u][j]; // ����
                    path[j] = u; // ����ǰһ��
                }
    }
}

// ���ӵĹ��ܣ����ѡ���ļ�������֮�������ڽ������
void allpath(MatGraph g) {
    int dist[MAXV], path[MAXV];
    int m;
    do {
        cout << "��������Ҫȥ�ľ��������" << endl;
        cin >> m;
        if (m > g.n) cout << "����ֵ���ھ������������������" << endl;
    } while (m > g.n);

    int num[m];
    cout << "������������ʼ�㣺" << endl;
    do {
        cin >> num[0];
        if (num[0] < 0 || num[0] >= g.n) cout << "����ֵ�д�������������" << endl;
    } while (num[0] < 0 || num[0] >= g.n);

    cout << "��������Ҫȥ�ľ����ţ�" << endl;
    for (int i = 1; i < m; i++) {
        do {
            cin >> num[i];
            if (num[i] < 0 || num[i] >= g.n) cout << "����ֵ�д�������������" << endl;
        } while (num[i] < 0 || num[i] >= g.n);
    }

    int visit[g.n], mark[m]; // mark[]���ÿһ��ȥ�ľ���
    memset(visit, 0, sizeof(visit)); // ��ʼ��visit����
    visit[num[0]] = 1;
    mark[0] = num[0]; // ��һ��Ϊ��ʼ��

    for (int j = 1; j < m; j++) {
        dijkstra(g, mark[j - 1], dist, path);
        int min_dist = INF;
        int next_vertex = -1;
        for (int i = 0; i < m; i++) { // �������д�ѡ����
            int vertex = num[i];
            if (!visit[vertex] && dist[vertex] < min_dist) {
                min_dist = dist[vertex];
                next_vertex = vertex;
            }
        }
        if (next_vertex == -1) break; // �޿���·��
        mark[j] = next_vertex;
        visit[next_vertex] = 1;
    }

    cout << "���·��Ϊ��" << endl;
    for (int i = 0; i < m-1; i++) {
        cout << mark[i] << " -->";
    }
    cout << mark[m-1];
    cout << endl;
}

// ���ܾ���
void introduce(MatGraph g) {
    int num;
    cout << "�������ѯ�ľ����ţ�" << endl;
    cin >> num;
    if (num < 0 || num >= g.n) {
        cout << "����ľ����Ų��Ϸ���" << endl;
        return;
    }
    cout << g.vexs[num].name << endl;
    cout << g.vexs[num].introduction << endl;
}

// �鿴��ͼ
void DisplayMap() {
    system("start C:\\Users\\admin\\Desktop\\�ܹں�202330401911ͳ��\\����ϵͳ\\camp_map.png");
}

// ɾ���ڵ�
void DeleteNode(MatGraph &g) {
    int num;
    cout << "��������Ҫɾ���Ľڵ㣺" << endl;
    cin >> num;
    if (num < 0 || num >= g.n) {
        cout << "�þ��㲻����" << endl;
        return;
    }

    // ɾ���ڵ�
    for (int i = num; i < g.n - 1; i++) {
        for (int j = 0; j < g.n; j++) {
            g.edges[i][j] = g.edges[i + 1][j];
        }
    }
    for (int i = 0; i < g.n - 1; i++) {
        for (int j = num; j < g.n - 1; j++) {
            g.edges[i][j] = g.edges[i][j + 1];
        }
    }
    for (int i = num; i < g.n - 1; i++) {
        g.vexs[i] = g.vexs[i + 1];
    }
    g.n--;
    cout << "�ڵ�ɾ���ɹ���" << endl;
}

// ɾ����
void DeleteArc(MatGraph &g) {
    int num1, num2;
    cout << "������Ҫɾ���ıߵ������ڵ㣺" << endl;
    cin >> num1 >> num2;
    if (num1 < 0 || num1 >= g.n || num2 < 0 || num2 >= g.n || num1 == num2) {
        cout << "�����д���" << endl;
        return;
    }
    g.edges[num1][num2] = INF;
    g.edges[num2][num1] = INF;
    cout << "��ɾ���ɹ���" << endl;
}

// ���ӽڵ�
void AddNode(MatGraph &g) {
    if (g.n >= MAXV) {
        cout << "�ڵ������Ѵ����ޣ��޷���ӣ�" << endl;
        return;
    }

    string ADDname, ADDintroduction;
    cout << "��������뾰������֣�" << endl;
    cin >> ADDname;
    cout << "��������뾰��Ľ��ܣ�" << endl;
    cin >> ADDintroduction;

    g.vexs[g.n].name = ADDname;
    g.vexs[g.n].introduction = ADDintroduction;

    cout << "��������뾰�㵽��������ľ��루�ӱ���㿪ʼ��-1��ʾ�����ӣ���" << endl;
    for (int j = 0; j < g.n; j++) {
        int distance;
        cin >> distance;
        if (distance > 0) {
            g.edges[g.n][j] = distance;
            g.edges[j][g.n] = distance;
        } else {
            g.edges[g.n][j] = INF;
            g.edges[j][g.n] = INF;
        }
    }
    g.edges[g.n][g.n] = 0;
    g.n++;
    cout << "�ڵ���ӳɹ���" << endl;
}

// ���ӱ�
void AddArc(MatGraph &g) {
    int num1, num2, distance;
    cout << "��������ӱߵ���ʼ�㣺" << endl;
    cin >> num1;
    cout << "��������ӱߵ��յ㣺" << endl;
    cin >> num2;
    if (num1 < 0 || num1 >= g.n || num2 < 0 || num2 >= g.n || num1 == num2) {
        cout << "�����д���" << endl;
        return;
    }
    if (g.edges[num1][num2] != INF) {
        cout << "��������б�" << endl;
        return;
    }
    cout << "��������ӱߵĳ��ȣ�" << endl;
    cin >> distance;
    g.edges[num1][num2] = distance;
    g.edges[num2][num1] = distance;
    cout << "����ӳɹ���" << endl;
}

// ���ĵ�ͼ
void ChangeMap(MatGraph &g) {
    string key;
    int num;
    cout << "��������Կ��" << endl;
    cin >> key;
    if (key != "2848192063") {
        cout << "����Ȩ���ĵ�ͼ" << endl;
        return;
    }

    while (true) {
        cout << "��ѡ�����Ĳ�����" << endl;
        cout << "0.���ز˵�" << endl;
        cout << "1.ɾ������" << endl;
        cout << "2.ɾ����·" << endl;
        cout << "3.���Ӿ���" << endl;
        cout << "4.���ӵ�·" << endl;
        cin >> num;
        switch (num) {
            case 1: DeleteNode(g); break;
            case 2: DeleteArc(g); break;
            case 3: AddNode(g); break;
            case 4: AddArc(g); break;
            case 0: return;
            default: cout << "δ�ҵ��ù��ܣ���������Чѡ�" << endl; break;
        }
    }
}

int main() {
    int key;
    InitMap(g);
    while (true) {
        menu();
        cout << "��������Ҫѡ��Ĺ��ܣ�" << endl;
        cin >> key;
        switch (key) {
        case 1:system("cls");DisplayMap();break;
		case 2:system("cls");Floyd(g);break;
		case 3:system("cls");allpath(g);break;
		case 4:system("cls");introduce(g);break;
		case 5:system("cls");ChangeMap(g);break;
		case 0:system("cls");cout<<"ллʹ��"<<endl; return 0;
            default: cout << "δ�ҵ��ù��ܣ���������Чѡ�" << endl; break;
        }
    }
}
