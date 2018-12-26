#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct elements
{
    int data;
    struct elements *left, *right;
} elements;

elements *node(long n, int *a, long *pi)
{
    if (n <= 0)
        return NULL;
    else
    {
        long nl, nr;
        elements *q;
        nl = n / 2;
        nr = n - nl - 1;
        q = (elements *)malloc(sizeof(elements));
        q->data = a[*pi];
        (*pi)++;
        q->left = node(nl, a, pi);
        q->right = node(nr, a, pi);
        return q;
    }
}

void distruct(elements *q)
{
    if (q)
    {
        distruct(q->left);
        distruct(q->right);
        free(q);
        q = NULL;
    }
}

void print(elements *q, long n)
{
    if (q != NULL)
    {
        long i;
        print(q->right, n + 5);
        for (i = 0; i < n; i++)
            printf(" ");
        printf("%d\n", q->data);
        print(q->left, n + 5);
    }
}

long height(elements *q)
{
    if (q == NULL)
        return -1;
    else
    {
        long i, j;
        i = height(q->left);
        j = height(q->right);
        if (i > j)
            return i + 1;
        return j + 1;
    }
}

int main()
{
    elements **puti;
    int n, counter, x = 1;
    printf("n=");
    scanf("%d", &n);
    elements *root = NULL;
    long i, h;
    int a[n];

    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        a[i] = (long)(rand() % n + 1);
    }
    i = 0;
    root = node(n, a, &i);
    print(root, 0);
    h = height(root);
    printf("\nh = %ld", h + 1);
    distruct(root);
    return 0;
}
