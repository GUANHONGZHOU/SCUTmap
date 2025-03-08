#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define MAXV 20
#define INF 32767

struct VertexType {
    string name;
    string introduction;
}; // 顶点类型

struct MatGraph {
    int edges[MAXV][MAXV];
    int n, e;
    VertexType vexs[MAXV];
}; // 邻接矩阵

MatGraph g;

// 初始化地图
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

    g.vexs[0].name = "博学楼"; g.vexs[0].introduction = "北区学院学生平时上课的地方，有漂亮的樱花";
    g.vexs[1].name = "北湖"; g.vexs[1].introduction = "很多居民学生在这散步锻炼";
    g.vexs[2].name = "旧校训石"; g.vexs[2].introduction = "有很多小猫";
    g.vexs[3].name = "逸夫人文馆"; g.vexs[3].introduction = "很多建校资料";
    g.vexs[4].name = "西湖"; g.vexs[4].introduction = "有天鹅";
    g.vexs[5].name = "校友之家"; g.vexs[5].introduction = "可以喝咖啡";
    g.vexs[6].name = "医院"; g.vexs[6].introduction = "希望你用不到";
    g.vexs[7].name = "孙中山先生像"; g.vexs[7].introduction = "这里是中大";
    g.vexs[8].name = "道明游泳馆"; g.vexs[8].introduction = "恒温游泳池，推荐";
    g.vexs[9].name = "图书馆"; g.vexs[9].introduction = "北区之外学生的学习地";
}

// 输出最短路径
void Display(MatGraph g, int A[][MAXV], int path[][MAXV], int num1, int num2) {
    int apath[MAXV], d, k;
    if (A[num1][num2] != INF && num1 != num2) {
        cout << num1 << "到" << num2 << "的最短路径为：" << endl;
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
        cout << num1 << "到" << num2 << "最短路径长度为：" << A[num1][num2] << endl;
    }
}

// Floyd算法
void Floyd(MatGraph g) {
    int num1, num2;
    cout << "请输入需要查找的两个景点编号：" << endl;
    cin >> num1 >> num2;
    if (num1 < 0 || num1 >= g.n || num2 < 0 || num2 >= g.n) {
        cout << "输入的景点编号不合法！" << endl;
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

// 主页
void menu() {
    printf(" ┌──────────────────────────────────────────────────────┐\n");
	printf(" │ ╭ ═══════════════════════════════════════════════ ╮  │\n");
	printf(" │ ││        欢 迎 使 用 校 园 导 游 系 统          ││  │\n");
	printf(" │ ╰ ═══════════════════════════════════════════════ ╯  │\n");
	printf(" │                      欢迎来到                        │\n");
	printf(" │                华南理工大学五山校区                  │\n");
	printf(" │                     菜 单 选 择                      │\n");
	printf(" │  ****************************************************│\n");
	printf(" │  * 1.查看校园地图           ** 2.查询景点间最短路径 *│\n");
	printf(" │  ****************************************************│\n");
	printf(" │  * 3.查询多个景点的最短路径 ** 4.学校景点介绍       *│\n");
	printf(" │  ****************************************************│\n");
	printf(" │  * 5.更改图信息             **   0.退出             *│\n");
	printf(" │  *************************************************** │\n");
	printf(" └──────────────────────────────────────────────────────┘\n");
}

// Dijkstra算法
void dijkstra(MatGraph g, int v, int dist[], int path[]) {
    int S[MAXV];
    int mindist, i, j, u;
    for (i = 0; i < g.n; i++) {
        dist[i] = g.edges[v][i]; // 初始化距离
        S[i] = 0; // 将S置空，S[i]=1表示已标记
        if (g.edges[v][i] < INF)
            path[i] = v;
        else
            path[i] = -1; // 初始点开始没边
    }
    S[v] = 1; path[v] = 0;
    for (i = 0; i < g.n - 1; i++) {
        mindist = INF;
        for (j = 0; j < g.n; j++)
            if (S[j] == 0 && dist[j] < mindist) {
                u = j;
                mindist = dist[j];
            }
        S[u] = 1; // 顶点u加入S中
        for (j = 0; j < g.n; j++) // 更新未标记的顶点的最短路径
            if (S[j] == 0)
                if (g.edges[u][j] < INF && dist[u] + g.edges[u][j] < dist[j]) {
                    dist[j] = dist[u] + g.edges[u][j]; // 更新
                    path[j] = u; // 更新前一点
                }
    }
}

// 增加的功能，输出选定的几个顶点之间的最近邻近点策略
void allpath(MatGraph g) {
    int dist[MAXV], path[MAXV];
    int m;
    do {
        cout << "请输入你要去的景点个数：" << endl;
        cin >> m;
        if (m > g.n) cout << "输入值大于景点个数，请重新输入" << endl;
    } while (m > g.n);

    int num[m];
    cout << "请输入您的起始点：" << endl;
    do {
        cin >> num[0];
        if (num[0] < 0 || num[0] >= g.n) cout << "输入值有错误，请重新输入" << endl;
    } while (num[0] < 0 || num[0] >= g.n);

    cout << "请输入你要去的景点编号：" << endl;
    for (int i = 1; i < m; i++) {
        do {
            cin >> num[i];
            if (num[i] < 0 || num[i] >= g.n) cout << "输入值有错误，请重新输入" << endl;
        } while (num[i] < 0 || num[i] >= g.n);
    }

    int visit[g.n], mark[m]; // mark[]存放每一步去的景点
    memset(visit, 0, sizeof(visit)); // 初始化visit数组
    visit[num[0]] = 1;
    mark[0] = num[0]; // 第一步为起始点

    for (int j = 1; j < m; j++) {
        dijkstra(g, mark[j - 1], dist, path);
        int min_dist = INF;
        int next_vertex = -1;
        for (int i = 0; i < m; i++) { // 遍历所有待选景点
            int vertex = num[i];
            if (!visit[vertex] && dist[vertex] < min_dist) {
                min_dist = dist[vertex];
                next_vertex = vertex;
            }
        }
        if (next_vertex == -1) break; // 无可用路径
        mark[j] = next_vertex;
        visit[next_vertex] = 1;
    }

    cout << "最佳路线为：" << endl;
    for (int i = 0; i < m-1; i++) {
        cout << mark[i] << " -->";
    }
    cout << mark[m-1];
    cout << endl;
}

// 介绍景点
void introduce(MatGraph g) {
    int num;
    cout << "请输入查询的景点编号：" << endl;
    cin >> num;
    if (num < 0 || num >= g.n) {
        cout << "输入的景点编号不合法！" << endl;
        return;
    }
    cout << g.vexs[num].name << endl;
    cout << g.vexs[num].introduction << endl;
}

// 查看地图
void DisplayMap() {
    system("start C:\\Users\\admin\\Desktop\\周冠宏202330401911统计\\导游系统\\camp_map.png");
}

// 删除节点
void DeleteNode(MatGraph &g) {
    int num;
    cout << "请输入您要删除的节点：" << endl;
    cin >> num;
    if (num < 0 || num >= g.n) {
        cout << "该景点不存在" << endl;
        return;
    }

    // 删除节点
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
    cout << "节点删除成功！" << endl;
}

// 删除边
void DeleteArc(MatGraph &g) {
    int num1, num2;
    cout << "请输入要删除的边的两个节点：" << endl;
    cin >> num1 >> num2;
    if (num1 < 0 || num1 >= g.n || num2 < 0 || num2 >= g.n || num1 == num2) {
        cout << "输入有错误" << endl;
        return;
    }
    g.edges[num1][num2] = INF;
    g.edges[num2][num1] = INF;
    cout << "边删除成功！" << endl;
}

// 增加节点
void AddNode(MatGraph &g) {
    if (g.n >= MAXV) {
        cout << "节点数量已达上限，无法添加！" << endl;
        return;
    }

    string ADDname, ADDintroduction;
    cout << "请输入加入景点的名字：" << endl;
    cin >> ADDname;
    cout << "请输入加入景点的介绍：" << endl;
    cin >> ADDintroduction;

    g.vexs[g.n].name = ADDname;
    g.vexs[g.n].introduction = ADDintroduction;

    cout << "请输入加入景点到其它景点的距离（从编号零开始，-1表示无连接）：" << endl;
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
    cout << "节点添加成功！" << endl;
}

// 增加边
void AddArc(MatGraph &g) {
    int num1, num2, distance;
    cout << "请输入添加边的起始点：" << endl;
    cin >> num1;
    cout << "请输入添加边的终点：" << endl;
    cin >> num2;
    if (num1 < 0 || num1 >= g.n || num2 < 0 || num2 >= g.n || num1 == num2) {
        cout << "输入有错误" << endl;
        return;
    }
    if (g.edges[num1][num2] != INF) {
        cout << "景点间已有边" << endl;
        return;
    }
    cout << "请输入添加边的长度：" << endl;
    cin >> distance;
    g.edges[num1][num2] = distance;
    g.edges[num2][num1] = distance;
    cout << "边添加成功！" << endl;
}

// 更改地图
void ChangeMap(MatGraph &g) {
    string key;
    int num;
    cout << "请输入密钥：" << endl;
    cin >> key;
    if (key != "2848192063") {
        cout << "您无权更改地图" << endl;
        return;
    }

    while (true) {
        cout << "请选择您的操作：" << endl;
        cout << "0.返回菜单" << endl;
        cout << "1.删除景点" << endl;
        cout << "2.删除道路" << endl;
        cout << "3.增加景点" << endl;
        cout << "4.增加道路" << endl;
        cin >> num;
        switch (num) {
            case 1: DeleteNode(g); break;
            case 2: DeleteArc(g); break;
            case 3: AddNode(g); break;
            case 4: AddArc(g); break;
            case 0: return;
            default: cout << "未找到该功能，请输入有效选项！" << endl; break;
        }
    }
}

int main() {
    int key;
    InitMap(g);
    while (true) {
        menu();
        cout << "请输入您要选择的功能：" << endl;
        cin >> key;
        switch (key) {
        case 1:system("cls");DisplayMap();break;
		case 2:system("cls");Floyd(g);break;
		case 3:system("cls");allpath(g);break;
		case 4:system("cls");introduce(g);break;
		case 5:system("cls");ChangeMap(g);break;
		case 0:system("cls");cout<<"谢谢使用"<<endl; return 0;
            default: cout << "未找到该功能，请输入有效选项！" << endl; break;
        }
    }
}
