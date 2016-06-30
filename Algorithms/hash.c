#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#define MAXNUM 100000
#define HASHSIZE 100000
#define LINE 128

#define TRUE 1
#define FALSE 0

int nums[MAXNUM];
int n = 0;

struct list
{
	struct list *next;
	int val;
};

struct list *buckets[HASHSIZE];

int lookup(int val, int insert)
{
	struct list *h;
	struct list *l;
	struct list *n;
	
	h = buckets[val % HASHSIZE];
	for (l = h; l; h = l, l = l->next) {
		if (l->val == val)
			return TRUE;
	}
	if (!insert)
		return FALSE;
	n = (struct list *)malloc(sizeof(struct list));
	n->val = val;
	n->next = NULL;
	if (!h) {
		buckets[val % HASHSIZE] = n;
		return TRUE;
	}
	h->next = n;	
	return TRUE;
}

int sum2(int t)
{
	int x, y, i;

	for (i = 0; i < n; i++) {
		x = nums[i];
		y = t - x;
		if (y <= 0)
			continue;
		if (lookup(y, FALSE)) 
			return TRUE;
	}
	return FALSE;
}

int main(int argc, char *argv[])
{
	FILE *f;
	char buf[LINE];
	int val;

	memset(&buckets, 0, sizeof(buckets));

	f = fopen(argv[1], "r");
	if (f == NULL)
		return errno;
	while (fgets(buf, LINE, f)) {
		sscanf(buf, "%d", &val);
		nums[n++] = val;
		lookup(val, TRUE);
	}
	fclose(f);
	printf("num: %d\n", n);

	for (;;) {
		scanf("%d", &val);
		if (sum2(val)) 
			printf("TRUE\n");
	}

	return 0;
}
