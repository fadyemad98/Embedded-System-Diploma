#include<stdio.h>
int main(){
printf("The Alphabets are:\n\n");
char alpha[26];
int i,j;
for(i=65,j=0;i<91,j<26;i++,j++)
{
    alpha[j]=i;
}
char *Ptr_alpha=alpha;
for(i=0;i<26;i++){
    printf("%c ",*Ptr_alpha);
    Ptr_alpha++;
}

return 0;
}
