#include <stdio.h>

char s[10000];

int main()
{
	int T,f=0,i;
	scanf("%d",&T);gets(s);
	while(T--)
	{
		if(f)putchar('\n');else f=1;
		while(gets(s) && s[0])
		{
			for(i=0;s[i];i++)
			{
				switch(s[i])
				{
				case '0':
					putchar('O');
					break;
				case '1':
					putchar('I');
					break;
				case '2':
					putchar('Z');
					break;
				case '3':
					putchar('E');
					break;
				case '4':
					putchar('A');
					break;
				case '5':
					putchar('S');
					break;
				case '6':
					putchar('G');
					break;
				case '7':
					putchar('T');
					break;
				case '8':
					putchar('B');
					break;
				case '9':
					putchar('P');
					break;
				default:
					putchar(s[i]);
					break;
				}
			}
			putchar('\n');
		}
	}
	return 0;
}