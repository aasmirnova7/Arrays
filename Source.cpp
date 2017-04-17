#include <stdio.h>
#include <conio.h>

int main() {
	char a[16] = {1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,0};
	char b[16] = {1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,0};
	short c[16];
	int count = 0;
	short delit = 3;

	__asm {
	mov cx, 16; // счётчик
	lea ESI, a;
	lea EDI, b;
	lea EBX, c;

	BEG: mov ah, [EDI]; // ah ->элемент из b
	     mov al, [ESI]; // al ->элемент из а
		 cwd;
		 div delit; // AX / delit
	     cmp DX, 0; //сравниваем остаток с 0
	     je CONT; //если равно, то следующие элементы
		 mov[EBX], EDI;
		 inc EBX;
		 inc EBX;
		 inc count; //считаем количество этих элементов

	CONT: inc ESI;
		  inc EDI;
	      LOOP BEG;
	}
	
	printf("\ncount = %d", count);
	_getch();
}