#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <emscripten/emscripten.h>

#define NUM_STATIONS 101
#define INF 10000


EMSCRIPTEN_KEEPALIVE
int dijkstra(int start, int goal, int *adjs, int *min_weights, int *prev) {
    
    int visited[NUM_STATIONS+1] = {0};
    min_weights[start] = 0;
    while (1) {
        int min_weight = INF;
        int target;
        for (int i = 1; i <= NUM_STATIONS; i++) {
            if (!visited[i] && min_weights[i] < min_weight) {
                target = i;
                min_weight = min_weights[i];
            }
        }
        if (min_weight == INF) {
            printf("This graph isn't connected.");
            exit(1);
        } 

        if (target == goal) {
            return min_weights[goal];
        }

        visited[target] = 1;
        for (int neighbor = 1; neighbor <= NUM_STATIONS; neighbor++) {
            int total_weight = min_weights[target] + adjs[(NUM_STATIONS+1)*target+neighbor];
            if (total_weight < min_weights[neighbor]) {
                min_weights[neighbor] = total_weight;
                prev[neighbor] = target;
            }
        }
    }
}

