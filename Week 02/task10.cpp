//10. �� �� ������ ��������, � ����� �� ������� 4-������o ���������� ����� n. 
// �� ���� ����� �� �������� 2 ���� 2-������� �����. ������� ����� �� ������� �� 
// 1-���� � 4-���� ����� �� n, �, ������� - �� 2-�a�� � 3-���� ����� �� n. �� ������ 
// �� �� ������ ���� 1-�� ���� ����� e ��-�����, ����� ��� ��-������ �� 2-�� �����.

#include <iostream>

int main()
{
    int num;
    std::cin >> num;
    int x = num / 1000 * 10 + num % 10;
    std::cout << x;
    int y = num / 100 % 10 * 10 + num % 100 / 10;
    std::cout << y;
    std::cout << (x > y ? x : y);
}