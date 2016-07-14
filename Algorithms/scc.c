#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#define LINE 128
#define MAXNODES 1000000 

#define TRUE 1
#define FALSE 0

struct node 
{
	int *edges;
	int num_edges;
	int mark;
	int fin;
	int leader;
} rnodes[MAXNODES], nodes[MAXNODES];

int num_nodes = 0;
/* set to number of nodes */
int label = 0;
/* finishing time */
int t = 0;
/* current source vertex */
int s = 0;
/* count of number of nodes per SCC */
int leaders[MAXNODES];
/* finish time to node mapping */
int fin_to_node_map[MAXNODES];

void load_node(char *buf)
{
	int i, j;
	struct node *n;

	sscanf(buf, "%d %d", &i, &j);
	if (i > num_nodes)
		num_nodes = i;
	--i; 
	--j;

	n = &nodes[i];
	n->num_edges++;
	n->edges = (int*)realloc(n->edges, sizeof(int) * n->num_edges);
	n->edges[n->num_edges-1] = j;

	n = &rnodes[j];
	n->num_edges++;
	n->edges = (int*)realloc(n->edges, sizeof(int) * n->num_edges);
	n->edges[n->num_edges-1] = i;
}

void dfs(struct node *g, int n)
{
	int i;
	int e;
	struct node *node = &g[n];
	
	node->mark = TRUE;
	node->leader = s;
	leaders[s]++;
	for (i = 0; i < node->num_edges; i++) {
		e = node->edges[i];
		if (g[e].mark == FALSE)
			dfs(g, e);
	}
	node->fin = ++t;
}

void dfsloop1()
{
	int i;

	t = 0;
	s = 0;
	for (i = num_nodes-1; i >= 0; i--) {
		if (rnodes[i].mark == FALSE)	{
			s = i;
			dfs(rnodes, i);
		}
	}
}

void dfsloop2()
{
	int i, f;

	t = 0;
	s = 0;
	for (f = num_nodes-1; f >= 0; f--) {
		i = fin_to_node_map[f];
		if (nodes[i].mark == FALSE)	{
			s = i;
			dfs(nodes, i);
		}
	}
}

int main(int argc, char *argv[])
{
	FILE *f;
	char buf[LINE];
	int i;
	int n;
	
	memset(&nodes, 0, sizeof(nodes));
	memset(&rnodes, 0, sizeof(rnodes));
	memset(&leaders, 0, sizeof(leaders));

	f = fopen(argv[1], "r");
	if (f == NULL)
		return errno;
	while (fgets(buf, LINE, f)) {
		load_node(buf);
	}
	fclose(f);

	//printf("number of nodes = %d\n", num_nodes);
	/* run DFS loop on reverse graph */
	dfsloop1();
	/* order nodes by finish time */
	for (i = 0; i < num_nodes; i++) {
		fin_to_node_map[rnodes[i].fin - 1] = i;
	}
	memset(&leaders, 0, sizeof(leaders));
	/* run DFS loop on graph in decreasing order of finish time */
	dfsloop2();
	/* prins SCC sizes */
	for (i = 0; i < num_nodes; i++) 
		if (leaders[i]) {
			n += leaders[i];
			printf("%d\n", leaders[i]);
		}
	//printf("n=%d num_nodes=%d\n", n, num_nodes);

	return 0;
}