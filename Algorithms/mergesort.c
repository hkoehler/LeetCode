#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

#define LINE 64
int numbers[10000];

void swap(int *nums, int i, int j)
{
	if (i != j) {
		int tmp;

		tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
}

void merge_sort(int *nums, int n, unsigned long long *comps)
{
	int nleft, nright;
	int *numsleft, *numsright;

	if (n == 1)
		return;
	if (n == 2) {
		(*comps)++;
		if (nums[0] > nums[1])
				swap(nums, 0, 1);
		return;
	}
	nleft = n / 2;
	nright = n - nleft;
	assert(nleft + nright == n);
	numsleft = malloc(nleft * sizeof(int));
	numsright = malloc(nright * sizeof(int));
	memcpy(numsleft, nums, nleft * sizeof(int));
	memcpy(numsright, &nums[nleft], nright * sizeof(int));
	merge_sort(numsleft, nleft, comps);
	merge_sort(numsright, nright, comps);
	
	int ileft = 0, iright = 0;
	for (int i = 0; i < n; i++) {
		if (ileft >= nleft) {
			nums[i] = numsright[iright++];
			continue;
		}
		if (iright >= nright) {
			nums[i] = numsleft[ileft++];
			continue;
		}
		(*comps)++;
		if (numsleft[ileft] > numsright[iright])
			nums[i] = numsright[iright++];
		else
			nums[i] = numsleft[ileft++];
	}
	assert(ileft == nleft);
	assert(iright == nright);
	free(numsleft);
	free(numsright);
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

	merge_sort(numbers, n, &comps);

	f = fopen("out.txt", "w");
	for (i = 0; i < n; i++) 
		fprintf(f, "%d\n", numbers[i]);
	fclose(f);
	printf("number of comparisons = %lld\n", comps);

	return 0;
}
