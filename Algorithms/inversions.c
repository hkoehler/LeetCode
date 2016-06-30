#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

#define LINE 64
int numbers[100000];

int* sort(int *nums, int n, unsigned long long *invs)
{
	int n1 = n/2;
	int n2 = n - n1;
	int *s1, *s2, *s;
	int i;
	int i1 = 0, i2 = 0;
	unsigned long long invs1 = 0, invs2 = 0;
	
	s = (int*)malloc(n * sizeof(int));
	if (n == 1) {
		s[0] = nums[0];
		return s;
	}

	s1 = sort(nums, n1, &invs1);
	s2 = sort(&nums[n1], n2, &invs2);
	*invs = invs1 + invs2;

	for (i = 0; i < n; i++) {
		if (i1 == n1) {
			s[i] = s2[i2];
			i2++;
		}
		else if (i2 == n2) {
			s[i] = s1[i1];
			i1++;
		}
		else if (s1[i1] > s2[i2]) { 
			s[i] = s2[i2];
			i2++;
			*invs += n1 - i1;
		}
		else {
			s[i] = s1[i1];
			i1++;
		}
	}
	assert(n1 + n2 == n);
	free(s1);
	free(s2);

	return s;
}

int main(int argc, char *argv[])
{
	FILE *f;
	char buf[LINE];
	int *s;
	int n = 0;
	int i;
	unsigned long long invs = 0;
	
	f = fopen(argv[1], "r");
	if (f == NULL)
		return errno;
	while (fgets(buf, LINE, f)) {
		numbers[n] = atoi(buf);
		n++;
	}
	fclose(f);

	s = sort(numbers, n, &invs);

	fopen("out.txt", "w");
	for (i = 0; i < n; i++) 
		fprintf(f, "%d\n", s[i]);
	fclose(f);
	printf("number of inversion = %lld\n", invs);

	return 0;
}
