int main()
{
	int a = 42;
	int *n = &a;
	int **f = &n;
	int ***j = &f;
	void *z = j;
}