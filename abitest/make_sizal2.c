int
max3 (int a, int b, int c)
{
    int max = a > b ? a : b;
    return max > c ? max : c;
}

/* This constructs the test for size of structs with three basic types.  */
int
main (int argc, char **argv)
{
    int i, j, k;
    char *types[] = { "char", "short", "int", "long", "long long",
		      "float", "double", "long double" };
    int sizes[] = { 1, 2, 4, 8, 8, 4, 8, 16 };

    for (i=0; i<8; i++)
	for (j=0; j<8; j++)
	    for (k=0; k<8; k++)
		printf("check_struct3(%s, %s, %s, %d);\n", types[i], types[j],
		       types[k], max3(sizes[i], sizes[j], sizes[k]));

    return 0;
}
