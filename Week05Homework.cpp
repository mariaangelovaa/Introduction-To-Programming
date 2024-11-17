#include <iostream>

int absoluteValue(int number)//връща | number |
{
    return number < '0' ? -number : number;
}

bool isDigit(char symbol)//връща дали символът е цифра
{
    return symbol >= '0' && symbol <= '9';
}

char toUpper(char symbol)// ако буквата е малка връща съответната и главна
{
    if (symbol >= 'A' && symbol <= 'Z')
    {
        return symbol + 'a' - 'A';
    }
    return symbol;
}

char toLower(char symbol)//ако буквата е главна връща съответната и малка
{
    if (symbol >= 'a' && symbol <= 'z')
    {
        return symbol + 'A' - 'a';
    }
    return symbol;
}

int toNumber(char symbol)//конвертира от символ в цифра
{
    if (isDigit(symbol))
    {
        return symbol - '0';
    }
    return symbol;
}

char toCharacter(int number)//конвертира от цифра в символ
{
    return number + '0';
}

int power(int base, unsigned int exponent)// връща base^exponent
{
    int result = 1;
    for (int i = 1; i <= exponent; i++)
    {
        result *= base;
    }
    return result;
}

bool isPrime(unsigned int number)//проверява дали дадено число е просто
{
    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}

short getLength(int number)//връща колко цифри има даденото число
{
    int result = 0;
    while (number)
    {
        result++;
        number /= 10;
    }
    return result;
}

unsigned getDigitOccurences(unsigned number, int digit)
{
    int result = 0;
    while (number)
    {
        if (number % 10 == digit)
        {
            result++;
        }
    }
    return result;
}

bool isPermutation(int number1, int number2)
{
    for (int i = 0; i <= 9; i++)
        if (getDigitOccurences(number1, i) != getDigitOccurences(number2, i))
        {
            return false;
        }
    return true;
}

int reversed(int num1)
{
    int result = 0;
    while (num1)
    {
        result = num1 % 10;
        num1 /= 10;
    }
    return result;
}

bool isPalindrom(int num1)
{
    return num1 == reversed(num1);
}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap(unsigned& a, unsigned& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int gcd(unsigned first, unsigned second) {

    if (first < second) {
        swap(first, second);
    }

    while (second > 0) {
        unsigned temp = first % second;
        first = second;
        second = temp;
    }

    return first;
}

int lcm(unsigned first, unsigned second) {
    return (first / gcd(first, second)) * second;
}

void fraction(unsigned numerator, unsigned denominator)
{
    std::cout << (numerator / gcd(numerator, denominator)) << "/" << (denominator / gcd(numerator, denominator));
}

void removeDig(int number, int k) // n = 12345  k = 3 -> 12 45
                             // n = 1234 k = 2 -> 12 4
{
    int result = 0;
    for (size_t i = 1, p = 1; i < k; i++, p *= 10)
    {
        result += (number % 10) * p; // res = 5 +(4 * 10) = 45 
        number /= 10; // num = 1234
    }
    number /= 10;
    std::cout << number << "\n";
    std::cout << result;
}

void readArray(int* arr, const int length)
{
    for (size_t i = 0; i < length; i++)
    {
        int input;
        std::cin >> input;
        arr[i] = input;
    }
}

void printArray(int* arr, const int length)
{
    for (size_t i = 0; i < length; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

void removeDigFromArray(int* arr, const int length,const int n, int* resultArr)
{
    for (size_t i = 0, j = 0; i < length; i++, j++)
    {
        resultArr[j] = arr[i];
        if (i == n)
        {
            j--;
            continue;
        }
    }
}

void ArrayFromAtoB(int* arr, const int length, const int a, const int b, int* resultArr)
{
    for (size_t i = 0, j = 0; i < length; i++, j++)
    {
        if (j >= a - 1 && j < b)
        {
            resultArr[j] = arr[i];
        }
    }
}

bool SymArray(int* arr, const int length)
{
    for (size_t i = 0; i < length / 2; i++)
    {
        if (arr[i] != arr[length - 1 - i])
        {
            return false; 
        }
    }
    return true;
}

void maxElementsInArray(int* arr, const int length)
{
    int sum = 1;
    for (size_t i = 0; i < length; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            sum++;
        }
    }
    std::cout << sum;
}

void filteredArray(int* arr, const int length, int* resArr, int maxlength)
{
    int maxlength = 1;
    int current_length = 1;
    for (int i = 1; i < length; ++i)
    {
        if (arr[i] == arr[i - 1])
        {
            current_length++;
        }
        else
        {
            if (current_length > maxlength)
            {
                maxlength = current_length;
            }
            current_length = 1;
        }
    }
    if (current_length > maxlength)
    {
        maxlength = current_length;
    }

    std::cout << maxlength;
}

void SelectionSort(int* arr, const int length)
{
    
    int minelement;
    for (size_t i = 0; i < length - 1; i++)
    {
        minelement = i;
        for (size_t j = i + 1; j < length; j++)
        {
            if (arr[j] < arr[minelement]) 
                minelement = j;
        }
        if (minelement != i)
            std::swap(arr[minelement], arr[i]);
    }
}

void unionOfTwoArray(int* arr, int* arr2, const int length, const int length2, int* resultArr) {
    int insertIndex = 0;
    for (size_t i = 0; i < length; i++)
    {
        resultArr[insertIndex] = arr[i];
        insertIndex++;
    }

    for (size_t i = 0; i < length2; i++)
    {
        bool found = false;

        for (size_t j = 0; j < insertIndex; j++)
        {
            if (arr2[i] == resultArr[j]) 
            {
                found = true;
                break; 
            }
        }
        if (!found)
        {
            resultArr[insertIndex] = arr2[i];
            insertIndex++;
        }
    }

    SelectionSort(resultArr, insertIndex); 
}

void intersectionOfTwoArrays(int* arr, int* arr2, const int length, const int length2, int* resultArr)
{
    SelectionSort(arr, length);
    SelectionSort(arr2, length2);

    int i = 0, j = 0;
    int resultSize = 0;  
    while (i < length && j < length2) 
    {
        if (arr[i] == arr2[j]) 
        {
            resultArr[resultSize++] = arr[i];
            i++;
            j++;
        }
        else if (arr[i] < arr2[j]) {
            i++;
        }
        else {
            j++;
        }
    }
}


constexpr int SIZE = 1000;

int main()
{
    /*int arr[SIZE], arr2[SIZE], res[SIZE], length, length2;

    std::cout << "Enter valid array length: ";
    std::cin >> length >> length2;

    readArray(arr, length);
    readArray(arr2, length2)*/;

    //int n;
    //int a, b;
    //std::cout << n;
    //std::cin >> a >> b;
    //removeDigFromArray(arr, len, n, res);
    //printArray(arr, len);
    //printArray(res, len - 1);
    //ArrayFromAtoB(arr, lenght, a, b, res);
    //printArray(res, lenght - 1);
    // 
    // 
    //?SymArray(arr, length, res);
    // 
    // 
    //maxElementsInArray(arr, length);
    
    //?filteredArray(arr, length, res);
    
    //Array2IsInArray1(arr, arr2, length, length2);
    //unionOfTwoArray(arr, arr2, length, length2, res);
    //printArray(res, length+length2);


    int one[5] = { 1,2,3,2,1 };

    std::cout << SymArray(one, 5);
}

