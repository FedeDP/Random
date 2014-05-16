#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

typedef struct list_int {
	int x;
	struct list_int *next;
} list_f;

static list_f *reclist(list_f *h);
static void printlist(list_f *h);
static void printlist_inver(list_f *h);
static void freelist(list_f *h);

int i = 0;

int main(void)
{
	list_f *h = NULL;
	srand(time(NULL));
	h = reclist(h);
	printlist(h);
	printlist_inver(h);
	freelist(h);
	return 0;
}

static list_f *reclist(list_f *h)
{
	h = malloc(sizeof(list_f));
	if ((h) && (i != N)) {
		h->x = rand()%N+1;
		i++;
		h->next = reclist(h->next);
	} else {
		h = NULL;
	}
	return h;
}

static void printlist(list_f *h)
{
	if (h) {
		printf("\n%d", h->x);
		return printlist(h->next);
	}
}

static void printlist_inver(list_f *h)
{
	if (h) {
		printlist_inver(h->next);
		printf("\n%d", h->x);
	}
}

static void freelist(list_f *h)
{
	if (h) {
		freelist(h->next);
		free(h);
	}
}
