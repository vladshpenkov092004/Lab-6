#include <iostream>
#include <cmath>  // Для округлення результату

int main() {
    long x_values[7] = { 1, 2, 3, 4, 5, 6, 7 };  // Значення x для обчислення
    long REZ[7];  // Масив для збереження результатів

    for (int i = 0; i < 7; i++) {
        long x = x_values[i];  // Поточне значення x

        __asm {
            mov EBX, offset REZ  // Завантаження базової адреси масиву REZ в EBX
            add EBX, i * 4       // Додавання зміщення до потрібного індексу (4 байти на кожен елемент)

            mov EAX, 370        // EAX = 370
            imul EAX, x         // EAX = 370 * x
            imul EAX, x         // EAX = 370 * x^2
            sub EAX, 8          // EAX = 370 * x^2 - 8

            mov EDI, 2          // EDI = 2
            imul EDI, x         // EDI = 2 * x
            sub EDI, 40         // EDI = 2 * x - 40

            cdq                 // Розширення EAX в EDX для ділення
            idiv EDI            // Ділення EAX на EDI (EAX / (2 * x - 40))

            mov dword ptr[EBX], EAX  // Пересилання результату в пам'ять
        }
    }

    // Виведення результатів
    std::cout << "Результати обчислень (округлені до цілого):" << std::endl;
    for (int i = 0; i < 7; i++) {
        int rounded_REZ = std::round(REZ[i]);  // Округлення результату
        std::cout << "x = " << x_values[i] << ", y = " << rounded_REZ << std::endl;
    }

    return 0;
}
