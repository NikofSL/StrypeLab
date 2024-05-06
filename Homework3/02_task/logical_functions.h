int synthesizeByOnes(int a, int b, int c) {
    return ((!a && !b && !c) || (!a && b && !c) || (!a && b && c) || (a && b && c)) ? 1 : 0;
}


int synthesizeByZeros(int a, int b, int c) {
    return (!(!a && !b && c) && !(a && !b && !c) && !(a && !b && c) && !(a && b && !c)) ? 1 : 0;
}


int minimizedExpression(int a, int b, int c) {
    return ((!a && !b) || (b && c) || (a && b && c)) ? 1 : 0;
}
