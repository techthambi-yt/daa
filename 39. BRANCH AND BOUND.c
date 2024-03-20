#include <stdio.h>
#include <limits.h>

#define N 10
#define min(a, b) ((a) < (b) ? (a) : (b))

typedef struct { int cost[N], assignedWorker, assigned; } Job;

int calculateCost(Job jobs[], int n) {
    int totalCost = 0;
    for (int i = 0; i < n; i++)
        if (jobs[i].assigned)
            totalCost += jobs[i].cost[jobs[i].assignedWorker];
    return totalCost;
}

void explore(Job jobs[], int n, int i, int cost, int* best) {
    if (i == n) { *best = min(*best, cost); return; }
    for (int j = 0; j < n; j++)
        if (!jobs[j].assigned) {
            jobs[j].assigned = 1;
            jobs[j].assignedWorker = i;
            explore(jobs, n, i + 1, cost + jobs[j].cost[i], best);
            jobs[j].assigned = 0;
        }
}

int bnb(Job jobs[], int n) {
    int best = INT_MAX;
    explore(jobs, n, 0, 0, &best);
    return best;
}

int main() {
    int n;
    printf("Enter the number of jobs or workers: ");
    scanf("%d", &n);

    Job jobs[N];
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter cost for job %d: ", i + 1);
        for (int j = 0; j < n; j++)
            scanf("%d", &jobs[i].cost[j]);
        jobs[i].assigned = 0;
    }

    printf("Minimum cost of assignment: %d\n", bnb(jobs, n));
    return 0;
}
