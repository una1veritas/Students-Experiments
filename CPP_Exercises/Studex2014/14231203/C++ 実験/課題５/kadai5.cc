
#include <stdio.h>
#include "Vector2p.h"
#include "Matrix.h"

int main(){
		Vector2 a,b;
		Matrix c,d;
		
		printf("a=? vec");
		a.scan();
		a.print();
		printf("\n");
		printf("b=? vec");
		b.scan();
		b.print();
		printf("\n");
		printf("d=? mat");
		c.scan();
		c.print();
		printf("\n");
		printf("a=? mat");
		d.scan();
		d.print();
		printf("\n");
		printf("-----------------\n");
		(a.add(b)).print();
		printf("\n");
		printf("-----------------\n");
		(c.add(d)).print();
		printf("-----------------\n");

		return 0;

	}

