#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

#define LINE 64
int numbers[10000];

int swap(int *nums, int i, int j)
{
	int tmp;
	
	if (i != j) {
		tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}

	return tmp;
}

//#ifdef FIRST_PIVOT 
void pivot(int *nums, int n)
{
	assert(n);
}
//#endif

#ifdef LAST_PIVOT
void pivot(int *nums, int n)
{
	assert(n);
	swap(nums, 0, n-1);
}
#endif

#ifdef MED_PIVOT
void pivot(int *nums, int n)
{
	int p1 = nums[0];
	int p2 = nums[(n-1)/2];
	int p3 = nums[n-1];

	if ((p1 < p2 && p2 < p3) || (p1 > p2 && p2 > p3)) {
		swap(nums, (n-1)/2, 0);
	}
	else if ((p2 < p3 && p3 < p1) || (p2 > p3 && p3 > p1)) {
		swap(nums, n-1, 0);
	}
}
#endif

void quick_sort(int *nums, int n, unsigned long long *comps)
{
	int i = 1, j = 1;
	int pval;

	if (n <= 1) 
		return;

	pivot(nums, n);
	pval = nums[0];
	for (j = 1; j < n; j++) {
		*comps += 1;
		if (nums[j] < pval) {
			swap(nums, i, j);
			i++;
		}
	}
	swap(nums, i-1, 0);

	quick_sort(nums, i-1, comps);
	quick_sort(&nums[i], n - i, comps);
}

int main(int argc, char *argv[])
{
	FILE *f;
	char buf[LINE];
	int n = 0;
	int i;
	unsigned long long comps = 0;
	
	f = fopen(argv[1], "r");
	if (f == NULL)
		return errno;
	while (fgets(buf, LINE, f)) {
		numbers[n] = atoi(buf);
		n++;
	}
	fclose(f);

	quick_sort(numbers, n, &comps);

	fopen("out.txt", "w");
	for (i = 0; i < n; i++) 
		fprintf(f, "%d\n", numbers[i]);
	fclose(f);
	printf("number of comparisons = %lld\n", comps);

	return 0;
}
