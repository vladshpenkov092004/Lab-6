#include <iostream>
#include <cmath>  // ��� ���������� ����������

int main() {
    long x_values[7] = { 1, 2, 3, 4, 5, 6, 7 };  // �������� x ��� ����������
    long REZ[7];  // ����� ��� ���������� ����������

    for (int i = 0; i < 7; i++) {
        long x = x_values[i];  // ������� �������� x

        __asm {
            mov EBX, offset REZ  // ������������ ������ ������ ������ REZ � EBX
            add EBX, i * 4       // ��������� ������� �� ��������� ������� (4 ����� �� ����� �������)

            mov EAX, 370        // EAX = 370
            imul EAX, x         // EAX = 370 * x
            imul EAX, x         // EAX = 370 * x^2
            sub EAX, 8          // EAX = 370 * x^2 - 8

            mov EDI, 2          // EDI = 2
            imul EDI, x         // EDI = 2 * x
            sub EDI, 40         // EDI = 2 * x - 40

            cdq                 // ���������� EAX � EDX ��� ������
            idiv EDI            // ĳ����� EAX �� EDI (EAX / (2 * x - 40))

            mov dword ptr[EBX], EAX  // ����������� ���������� � ���'���
        }
    }

    // ��������� ����������
    std::cout << "���������� ��������� (�������� �� ������):" << std::endl;
    for (int i = 0; i < 7; i++) {
        int rounded_REZ = std::round(REZ[i]);  // ���������� ����������
        std::cout << "x = " << x_values[i] << ", y = " << rounded_REZ << std::endl;
    }

    return 0;
}
