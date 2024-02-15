#include<stdio.h>
#include<string.h>
void reverse_sentence(char sentence[],int SentLen,int i)
{
    printf("%c",sentence[i]);
    --i;
    if (i>=0)
    reverse_sentence(sentence,SentLen,i);

}

int main()
{
    char sentence[20];
    printf("Enter a sentence: ");
    gets(sentence);
    unsigned int SentLen= strlen(sentence);
    printf("Sentence in reverse is : ");
    int i=SentLen-1;
    reverse_sentence(sentence,SentLen,i);

    return 0;
}
