#include <bits/stdc++.h>
using namespace std;

int R, C;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

vector<vector<int> > grid;
vector<vector<int> > visited;
vector<vector<pair<int,int> > > parent;

bool isValid(int r, int c) {
    return (r >= 0 && c >= 0 && r < R && c < C && grid[r][c] != 1);
}

vector<pair<int,int> > reconstructPath(pair<int,int> start, pair<int,int> end) {
    vector<pair<int,int> > path;
    pair<int,int> cur = end;

    if (parent[cur.first][cur.second].first == -1 && !(cur == start))
        return path;

    while (!(cur == start)) {
        path.push_back(cur);
        cur = parent[cur.first][cur.second];
    }

    path.push_back(start);
    reverse(path.begin(), path.end());
    return path;
}

void printGridWithPath(const vector<pair<int,int> >& path,
                       pair<int,int> start, pair<int,int> end) {
    vector<vector<char> > out(R, vector<char>(C, '.'));

    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
            if (grid[r][c] == 1)
                out[r][c] = '#';

    for (int i = 0; i < (int)path.size(); i++) {
        int r = path[i].first;
        int c = path[i].second;
        out[r][c] = '*';
    }

    out[start.first][start.second] = 'S';
    out[end.first][end.second] = 'E';

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++)
            cout << out[r][c] << " ";
        cout << endl;
    }
}

vector<pair<int,int> > BFS(pair<int,int> start, pair<int,int> end) {
    visited.assign(R, vector<int>(C, 0));
    parent.assign(R, vector<pair<int,int> >(C, make_pair(-1,-1)));

    queue<pair<int,int> > q;
    q.push(start);
    visited[start.first][start.second] = 1;

    while (!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();
        int r = cur.first, c = cur.second;

        if (cur == end)
            return reconstructPath(start, end);

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (isValid(nr, nc) && !visited[nr][nc]) {
                visited[nr][nc] = 1;
                parent[nr][nc] = make_pair(r, c);
                q.push(make_pair(nr, nc));
            }
        }
    }

    return vector<pair<int,int> >();
}

vector<pair<int,int> > DFS(pair<int,int> start, pair<int,int> end) {
    visited.assign(R, vector<int>(C, 0));
    parent.assign(R, vector<pair<int,int> >(C, make_pair(-1,-1)));

    stack<pair<int,int> > st;
    st.push(start);

    while (!st.empty()) {
        pair<int,int> cur = st.top();
        st.pop();
        int r = cur.first, c = cur.second;

        if (visited[r][c]) continue;
        visited[r][c] = 1;

        if (cur == end)
            return reconstructPath(start, end);

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (isValid(nr, nc) && !visited[nr][nc]) {
                parent[nr][nc] = make_pair(r, c);
                st.push(make_pair(nr, nc));
            }
        }
    }

    return vector<pair<int,int> >();
}

vector<pair<int,int> > Dijkstra(pair<int,int> start, pair<int,int> end) {
    const int INF = 1e9;

    visited.assign(R, vector<int>(C, 0));
    parent.assign(R, vector<pair<int,int> >(C, make_pair(-1,-1)));

    vector<vector<int> > dist(R, vector<int>(C, INF));
    dist[start.first][start.second] = 0;

    typedef pair<int, pair<int,int> > P;
    priority_queue<P, vector<P>, greater<P> > pq;

    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        P top = pq.top();
        pq.pop();

        int r = top.second.first, c = top.second.second;

        if (visited[r][c]) continue;
        visited[r][c] = 1;

        if (make_pair(r, c) == end)
            return reconstructPath(start, end);

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];

            if (!isValid(nr, nc)) continue;

            int nd = dist[r][c] + 1;

            if (nd < dist[nr][nc]) {
                dist[nr][nc] = nd;
                parent[nr][nc] = make_pair(r, c);
                pq.push(make_pair(nd, make_pair(nr, nc)));
            }
        }
    }

    return vector<pair<int,int> >();
}

int main() {
    cout << "Enter grid size (rows columns): ";
    cin >> R >> C;

    if (R <= 0 || C <= 0) {
        cout << "Invalid size!\n";
        return 0;
    }

    grid.assign(R, vector<int>(C, 0));

    int obs;
    cout << "Enter number of obstacles: ";
    cin >> obs;

    cout << "Enter obstacle positions (r c) 0-indexed:\n";
    for (int i = 0; i < obs; i++) {
        int r, c;
        cin >> r >> c;
        if (r >= 0 && r < R && c >= 0 && c < C)
            grid[r][c] = 1;
    }

    pair<int,int> start, endp;
    cout << "Enter start cell (r c): ";
    cin >> start.first >> start.second;

    cout << "Enter end cell (r c): ";
    cin >> endp.first >> endp.second;

    if (!isValid(start.first, start.second) || !isValid(endp.first, endp.second)) {
        cout << "Start or End is invalid/obstacle!\n";
        return 0;
    }

    cout << "\nChoose algorithm:\n";
    cout << "1. BFS\n2. DFS\n3. Dijkstra\n";
    cout << "Enter choice: ";
    int ch;
    cin >> ch;

    vector<pair<int,int> > path;

    if (ch == 1) path = BFS(start, endp);
    else if (ch == 2) path = DFS(start, endp);
    else if (ch == 3) path = Dijkstra(start, endp);
    else {
        cout << "Invalid choice!\n";
        return 0;
    }

    if (path.empty())
        cout << "\nNo path found.\n";
    else {
        cout << "\nPath found:\n";
        printGridWithPath(path, start, endp);
        cout << "\nPath length: " << path.size() << endl;
    }

    return 0;
}
