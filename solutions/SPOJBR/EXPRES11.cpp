#include <stdio.h>

int fila[100001];
int inic=0;

char cadeia[100001];

void processar_cadeia() {
     char c;
     int definida=1;
     gets(cadeia);
     for (int i = 0; cadeia[i]!='\0' && definida; i++) {
           c = cadeia[i];
           
           switch (c) {
                  case '(':
                  case '{':
                  case '[': fila[inic++] = c; break;
                  
                  case ')':
                       if (inic == 0 || fila[--inic] != '(') definida=0;
                       break;
                  case ']':
                       if (inic == 0 || fila[--inic] != '[') definida=0;
                       break;
                  case '}':
                       if (inic == 0 || fila[--inic] != '{') definida=0;
                       break;
           }
     }
     
     if (definida && inic == 0) printf("S\n");
     else printf("N\n");
} 
                 


int main() {
    int T;
    scanf("%d", &T);
    while(getchar() != '\n');
    
    int i;
    for (i=0;i<T;i++) {
        inic = 0;
        processar_cadeia();
    }
    
    return 0;
}

