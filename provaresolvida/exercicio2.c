int main () {
    char *frase = (char*)malloc(100*sizeof(char));
    scanf(" %[^\n]", frase);
    char carac;
    scanf(" %c", &carac);
    int i = 0;
    while (*(frase + i) != '\0') {
        if (*(frase + i) == carac) *(frase + i) = '*';
        i++;
    }
    printf("%s", frase);
}