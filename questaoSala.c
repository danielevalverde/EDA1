#include <stdio.h>

typedef struct {
	float x, y;
} point;

typedef struct 
{
	point p1, p2; 
} segment;

typedef enum {
	FALSO,
	VERDADEIRO
} Answer;

static char* enumStrings[] = {"FALSO", "VERDADEIRO"};

Answer isParallel (segment s1, segment s2) {

	float a1 = (s1.p2.y - s1.p1.y) / (s1.p2.x - s1.p1.x);
	float a2 = (s2.p2.y - s2.p1.y) / (s2.p2.x - s2.p1.x);

	return a1 == a2;
}

int main(int argc, char const *argv[])
{

	segment s1, s2;

	s1.p1.x = 1;
	s1.p1.y = 1;
	s1.p2.x = 2;
	s1.p2.y = 2;

	s2.p1.x = 4;
	s2.p1.y = 4;
	s2.p2.x = 8;
	s2.p2.y = 8;




	printf("%s\n", enumStrings[isParallel(s1, s2)]);
	
	return 0;
}