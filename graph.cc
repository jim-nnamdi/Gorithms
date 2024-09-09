
#include <list>

class Graph {
    private:
    int v;
    std::list<int>* adj;
    
    public:
    Graph(int data):v(data){
        this->adj = new std::list<int>[v];
    }
    void addEdges(int from, int to);
    void DFS(int source);
    void DFS_Util(int v, bool vis[]);
};

void Graph::addEdges(int from, int to) {
    this->adj[from].push_back(to);
}

void Graph::DFS(int source) {
    bool* visited = new bool[v];
    for(int i = 0; i < v; ++i){
        visited[i] = false;
    }
    DFS_Util(source, visited);
    delete[] visited;
}

void Graph::DFS_Util(int v, bool vis[]){
    vis[v] = true;
    for(auto i = adj[v].begin(); i != adj[v].end(); ++i){
        if(!vis[*i])
            DFS_Util(*i, vis);
    }
}

int main() {

    Graph g(4);
    g.addEdges(0,1);
}