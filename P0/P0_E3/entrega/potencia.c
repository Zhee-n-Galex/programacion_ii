//int potencia(int base, int exponente) { 
float potencia(int base, int exponente) {
    //int valor = 1;
    float valor = 1.0;
    int i;
    for (i=1; i <= absoluto(exponente); i++)
        valor = valor * base;
    return (exponente < 0)? 1/valor : valor;
}

int absoluto(int n) {
    //return (n<0) ? n : n;
    return (n < 0) ? -1 * n : n;
}