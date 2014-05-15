#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	float coefficiente;
	int esp;
} function;

typedef struct list_function {
	function a;
	struct list_function *next;
} list_f;

static list_f *reclist(list_f *h);
static void libera(list_f *h);
static int check_val(float init, float end, float toll);
static float check_func_val(list_f *h, float x);

int main()
{
	list_f *func = NULL;
	int check;
	float dist, toll, a, b, val_func_a, val_func_b;
	func = reclist(func);
	printf("Insert start point:\n");
	scanf("%f", &a);
	printf("Insert end point:\n");
	scanf("%f", &b);
	val_func_a = check_func_val(func, a);
	val_func_b = check_func_val(func, b);
	if (val_func_a * val_func_b > 0) {
		printf("Bisection method cannot be used.\n");
		return 1;
	}
	printf("Which is the minimum distance between the 2 points?\n");
	scanf("%f", &dist);
	printf("Which is the minimum tolerated value of proximity to 0?\n");
	scanf("%f", &toll);
	check = check_val(val_func_a, val_func_b, toll);
	while ((check == 0) && (fabs(b - a) > dist)) {
		if ((check_func_val(func, (a+b) / 2) * check_func_val(func, b)) < 0)
			a = (a+b) / 2;
		else
			b = (a+b) / 2;
		check = check_val(check_func_val(func, a), check_func_val(func, b), toll);
	}
	if (check == 0)
		printf("Distance between 2 points fell down user set minimum:\n%f < %f\n", fabs(b-a), dist);
	if ((fabs(a) <= fabs(b)) || (check == 1))
		printf("Value is: %f\n", a);
	else
		printf("Value is: %f\n", b);
	libera(func);
	return 0;
}

static list_f *reclist(list_f *h)
{
	int choice;
	h = malloc(sizeof(list_f));
	if (h) {
		do{
			printf("Insert coefficient:\n>");
			scanf("%f",&h->a.coefficiente);
		}while(h->a.coefficiente==0);
		do{
			printf("Insert exponent:\n>");
			scanf("%d",&h->a.esp);
		}while(h->a.esp<0);
		printf("Do you want to add anything? 1 to add.\n");
		scanf("%d", &choice);
		if (choice == 1)
			h->next = reclist(h->next);
	} else {
		printf("Memoria esaurita. Ritorno la lista finora creata.\n");
		h = NULL;
	}
	return h;
}

static void libera(list_f *h){
	if (h) {
		libera(h->next);
		free(h);
	} else {
		return;
	}
}

static int check_val(float init, float end, float toll){
	if ((fabs(init) < toll) && (fabs(init) <= fabs(end)))
		return 1;
	if (fabs(end) < toll)
		return 2;
	return 0;
}

static float check_func_val(list_f *h, float x){
	list_f *tmp;
	float value;
	for (tmp = h, value = 0; tmp; tmp = tmp->next)
		value = value + tmp->a.coefficiente * pow(x, tmp->a.esp);
	return value;
}
