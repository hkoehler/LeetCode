#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#define LINE 128
#define MAXNODES 64

struct node 
{
	int edges[MAXNODES];
	int num_edges;
} nodes[MAXNODES];
int num_nodes;
int max_nodes;

void load_node(char *buf, struct node *n)
{
	int i;
	int *e = n->edges;
	n->num_edges = sscanf(buf, "%d %d %d %d %d %d %d %d", 
		&i, &e[0], &e[1], &e[2], &e[3], &e[4], &e[5], &e[6]) - 1;
	for (i = 0; i < n->num_edges; i++) {
		e[i] -= 1;
		assert(e[i] >= 0);
	}
}

void pick_edge(int *n1, int *n2)
{
	int edge;
	struct node *n;

	for (;;) {
		*n1 = rand() % max_nodes;
		n = &nodes[*n1];
		if (n->num_edges == 0)
			continue;
		edge = rand() % n->num_edges;
		*n2 = n->edges[edge];
		break;
	}
}

void merge_nodes(int n1, int n2)
{
	int i, e;
	struct node *node1, *node2;
	int edges[MAXNODES];
	int num_edges = 0;

	node1 = &nodes[n1];
	node2 = &nodes[n2];
	for (i = 0; i < node1->num_edges; i++) {
		e = node1->edges[i];
		if (e == n1 || e == n2)
			continue;
		edges[num_edges++] = e;
	}
	for (i = 0; i < node2->num_edges; i++) {
		e = node2->edges[i];
		if (e == n1 || e == n2)
			continue;
		edges[num_edges++] = e;
	}
	node2->num_edges = 0;

	/* check for all other references of node2 */
	for (i = 0; i < max_nodes; i++) {
		for (e = 0; e < nodes[i].num_edges; e++) {
			if (nodes[i].edges[e] == n2) 
				nodes[i].edges[e] = n1;
		}
	}

	num_nodes--;
	node1->num_edges = num_edges;
	memcpy(node1->edges, edges, sizeof(edges));
}

void print_graph()
{
	struct node *node;
	int i, j;

	for (i = 0; i < max_nodes; i++) {
		node = &nodes[i];
		if (node->num_edges == 0)
			continue;
		for (j = 0; j < node->num_edges; j++) {
			printf("%d ", node->edges[j]);
		}
		printf("\n");
	}
	fflush(stdout);
}

int main(int argc, char *argv[])
{
	FILE *f;
	char buf[LINE];
	int n = 0;
	int n1, n2;
	
	srand(time(NULL));
	f = fopen(argv[1], "r");
	if (f == NULL)
		return errno;
	while (fgets(buf, LINE, f)) {
		load_node(buf, &nodes[n]);
		n++;
	}
	fclose(f);
	max_nodes = num_nodes = n;

	while (num_nodes > 2) {
		pick_edge(&n1, &n2);
		merge_nodes(n1, n2);
	}

	print_graph();

	return 0;
}
