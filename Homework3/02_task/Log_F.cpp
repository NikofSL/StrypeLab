#include <iostream>
#include <vector>

int synthesizeByOnes(int a, int b, int c) {
    return (!a && !b && !c) || (!a && b && !c) || (!a && b && c) || (a && b && c);
}

int synthesizeByZeros(int a, int b, int c) {
    return !(a && !b && !c) && !(a && !b && c) && !(a && b && !c) && !(a && b && c) && !(a || b || c);
}

int minimizedExpression(int a, int b, int c) {
    return (!a && !b) || (b && c) || (a && b && c);
}

int main() {
    int a, b, c;

    std::cout << "Enter three numbers (0 or 1) separated by spaces: ";
    std::cin >> a >> b >> c;

    if ((a != 0 && a != 1) || (b != 0 && b != 1) || (c != 0 && c != 1)) {
        std::cerr << "Invalid input, expected 0 or 1." << std::endl;
        return 1;
    }

    std::cout << "Result for synthesize by ones: " << synthesizeByOnes(a, b, c) << std::endl;
    std::cout << "Result for synthesize by zeros: " << synthesizeByZeros(a, b, c) << std::endl;
    std::cout << "Result for minimized expression: " << minimizedExpression(a, b, c) << std::endl;

    return 0;
}
