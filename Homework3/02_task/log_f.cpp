#include <iostream>
#include <stdexcept> // За изключения

// Функция за изчисляване на F(a, b, c) по синтез по '1'
int synthesizeByOnes(int a, int b, int c) {
    return ((!a && !b && !c) || (!a && b && !c) || (!a && b && c) || (a && b && c)) ? 1 : 0;
}

// Функция за изчисляване на F(a, b, c) по синтез по '0'
int synthesizeByZeros(int a, int b, int c) {
    return (!(!a && !b && c) && !(a && !b && !c) && !(a && !b && c) && !(a && b && !c)) ? 1 : 0;
}

// Функция за изчисляване на F(a, b, c) с минимизиран израз
int minimizedExpression(int a, int b, int c) {
    return ((!a && b) || (b && c) || (a && b && c) || (!a && !b && !c)) ? 1 : 0;
}

int main() {
    int a, b, c;

    std::cout << "Enter three binary numbers (0 or 1) separated by spaces: ";
    std::cin >> a >> b >> c;

    // Проверка за валидност на входа
    if ((a != 0 && a != 1) || (b != 0 && b != 1) || (c != 0 && c != 1)) {
        std::cerr << "Invalid input. Only 0 or 1 are allowed." << std::endl;
        return 1;
    }

    std::cout << "Result using synthesis by ones: " << synthesizeByOnes(a, b, c) << std::endl;
    std::cout << "Result using synthesis by zeros: " << synthesizeByZeros(a, b, c) << std::endl;
    std::cout << "Result using minimized expression: " << minimizedExpression(a, b, c) << std::endl;

    main();
    return 0;
}
