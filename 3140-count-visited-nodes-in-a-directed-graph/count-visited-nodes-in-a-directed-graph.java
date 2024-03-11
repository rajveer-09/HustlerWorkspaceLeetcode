class Solution {
    private void fillCycle(List<Integer> edges, boolean[] visited, int[] result, int start) {
        int length = 0;
        for (int x = start; !visited[x]; x = edges.get(x)) {
            visited[x] = true;
            length++;
        }
        result[start] = length;
        for (int x = edges.get(start); x != start; x = edges.get(x)) {
            result[x] = length;
        }
    }

    public int[] countVisitedNodes(List<Integer> edges) {
        int n = edges.size();
        int[] indegree = new int[n];
        int[] result = new int[n];
        boolean[] visited = new boolean[n];
        Queue<Integer> q = new LinkedList<>();
        Stack<Integer> s = new Stack<>();
        for (int e : edges) {
            indegree[e]++;
        }
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.add(i);
            }
        }
        while (!q.isEmpty()) {
            int x = q.remove();
            s.push(x);
            visited[x] = true;
            if (--indegree[edges.get(x)] == 0) {
                q.add(edges.get(x));
            }
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                fillCycle(edges, visited, result, i);
            }
        }
        while (!s.isEmpty()) {
            int x = s.pop();
            result[x] = result[edges.get(x)] + 1;
        }
        return result;
    }
}