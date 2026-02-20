#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define K 5
#define TAU 0.5
#define ITERATIONS 1000

typedef struct {
int id;
double total_latency;
double average_reward;
int selection_count;
} Server;

void calculate_probabilities(Server servers[], double probs[]) {
double max_reward = -1.0;
double sum_exp = 0.0;
for (int i = 0; i < K; i++) {
if (servers[i].average_reward > max_reward) max_reward = servers[i].average_reward;
}
for (int i = 0; i < K; i++) {
probs[i] = exp((servers[i].average_reward - max_reward) / TAU);
sum_exp += probs[i];
}
for (int i = 0; i < K; i++) probs[i] /= sum_exp;
}

int select_server(double probs[]) {
double r = (double)rand() / RAND_MAX;
double cumulative = 0.0;
for (int i = 0; i < K; i++) {
cumulative += probs[i];
if (r <= cumulative) return i;
}
return K - 1;
}

double simulate_latency(int server_id) {
double base_latencies[K] = {10.0, 50.0, 100.0, 20.0, 80.0};
double noise = ((double)rand() / RAND_MAX) * 10.0;
return base_latencies[server_id] + noise;
}

int main() {
srand(time(NULL));
Server servers[K];
double probs[K];
for (int i = 0; i < K; i++) {
servers[i].id = i;
servers[i].average_reward = 1.0;
servers[i].selection_count = 0;
servers[i].total_latency = 0;
}
printf("Softmax Load Balancer Simulation Starting...\n\n");
for (int t = 1; t <= ITERATIONS; t++) {
calculate_probabilities(servers, probs);
int selected = select_server(probs);
double latency = simulate_latency(selected);
double reward = 100.0 / latency;
servers[selected].selection_count++;
servers[selected].total_latency += latency;
servers[selected].average_reward += (reward - servers[selected].average_reward) / servers[selected].selection_count;
}
printf("--- Final Results ---\n");
for (int i = 0; i < K; i++) {
printf("Server %d: %d requests, Avg Latency: %.2f ms\n", i, servers[i].selection_count,
servers[i].selection_count > 0 ? servers[i].total_latency / servers[i].selection_count : 0);
}
return 0;
}
