import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class D {
    static class Edge implements Comparable<Edge>{
        int source;
        int destination;
        int weight;

        public Edge(int source, int destination, int weight) {
            this.source = source;
            this.destination = destination;
            this.weight = weight;
        }
        
        public int compareTo(Edge e){
            return weight - e.weight;
        }
    }

    static class Graph {
        int V;
        ArrayList<Edge> edges = new ArrayList<>();

        Graph(int vertices) {
            V = vertices;
        }

        public void addEgde(int source, int destination, int weight) {
            Edge edge = new Edge(source-1, destination-1, weight);
            edges.add(edge);
        }
        
        public void kruskalMST(){
            PriorityQueue<Edge> pq = new PriorityQueue<Edge>;
            for(int i = 0; i < edges.size(); i++) pq.add(edges.get(i));
            int [] parent = new int[V];
            for (int i = 0; i <V ; i++) parent[i] = i;
            int cost = 0;
            for (int i = 0; i<V; i++){
                Edge edge = pq.remove();
                
                int x_set = find(parent, edge.source);
                int y_set = find(parent, edge.destination);
                if(!(x_set==y_set)){
                    cost+=edge.weight;
                    union(parent,x_set,y_set);
                }
            }
            System.out.println(cost + " ");
         }

        public int find(int[] parent, int vertex){
            if(parent[vertex]!=vertex) {
               int p = find(parent, parent[vertex]);
               parent[vertex] = p;
               return p;
            }
            return vertex;
        }

        public void union(int [] parent, int x, int y){
            int x_set_parent = find(parent, x);
            int y_set_parent = find(parent, y);
            parent[y_set_parent] = x_set_parent;
        }

    }
    public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            int vertices = sc.nextInt();
            int edges = sc.nextInt();
            Graph graph = new Graph(vertices);
            for (int i = 0; i < edges; i++) graph.addEgde(sc.nextInt(), sc.nextInt(), sc.nextInt());
            graph.kruskalMST();
    }
}