#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char from[200][30];
char to[200][30];
char s[200][30];

int m;

const char* find(const char *s)
{
    for (int i = 0; i < m; i++)if (strcmp(s, from[i]) == 0)return to[i];
    return s;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int T, TC = 0;
    scanf("%d", &T);
    while (++TC <= T)
    {
        printf("Case #%d:", TC);
        int n;
        scanf("%d %d ", &n, &m);
        for (int i = 0; i < m; i++)
        {
            scanf("%s %s ", from[i], to[i]);
        }
        int tot = 0;
        while (scanf("%[^ \n]%*[ ]", s[tot]) == 1)tot++;
        for (int i = 0; i < tot; i++)
        {
            const char *t = s[i];
            for (int j = 0; j < n - 1; j++)t = find(t);
            printf(" %s", t);
        }
        putchar('\n');
    }
    return 0;
}
