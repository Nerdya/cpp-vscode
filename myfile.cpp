#include <bits/stdc++.h>

using namespace std;

#define MAX 50
#define INF 10000000

int n; // Số đỉnh của đồ thị
int s; // Đỉnh đầu
int t; // Đỉnh cuối
char chon;
int p[MAX]; // Mảng đánh dấu đường đi
int d[MAX]; // Mảng đánh dấu khoảng cách
int matran[MAX][MAX]; // Ma trận trọng số
bool conhan[MAX]; // Mảng đánh dấu đỉnh đã được gán nhãn

void Dijkstra() {
	int u, mind;

	// Khởi tạo nhãn tạm thời cho các đỉnh
	for (int v = 1; v <= n; v++) {
		d[v] = matran[s][v];
		p[v] = s;
		conhan[v] = false;
	}
	p[s] = 0;
	d[s] = 0;
	conhan[s] = true;

	while (!conhan[t]) {
		mind = INF;
		// Tìm đỉnh u sao cho d[u] là nhỏ nhất
		for (int v = 1; v <= n; v++) {
			if ((!conhan[v]) && (mind > d[v])) {
				u = v;
				mind = d[v];
			}
		}
		conhan[u] = true; // u là đỉnh có nhãn tạm thời nhỏ nhất

		if (!conhan[t]) {
			// Gán nhãn lại cho các đỉnh.
			for (int v = 1; v <= n; v++) {
				if ((!conhan[v]) && (d[u] + matran[u][v] < d[v])) {
					d[v] = d[u] + matran[u][v];
					p[v] = u;
				}
			}
		}
	}
}

void Result() {
	cout << "Duong di ngan nhat tu " << 'v' << s << " den " << 'v' << t << " la" <<endl;
	cout << 'v' << t << " <= "; // In đỉnh cuối dưới dạng char.
	int i = p[t];
	while (i != s) {
		cout << 'v' << i << " <= "; // In ra kết quả dưới dạng char.
		i = p[i];
	}
	cout << 'v' << s << endl; // In đỉnh đầu dưới dạng char.
	cout << "Do dai duong di la : "<< d[t] << endl << endl;
}

void Input() {
	freopen("dijkstra.inp", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> matran[i][j];
			if (matran[i][j] == 0) matran[i][j] = INF;
		}
	}
	for (int k = 1; k <= n - 1; k++) {
		cin >> s >> t;
		Dijkstra();
		Result();
	}
}

int main() {
	Input();
	return 0;
}
