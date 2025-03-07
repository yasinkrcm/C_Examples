#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

class BinaryMultiplier {
public:
    string multiply(string, string);
    string addBinary(string, string);
    string shiftLeft(string, int);
    void binaryToDecimal(string);
    
    // Karatsuba çarpan yöntemi
    string karatsubaMultiply(string, string);
    string karatsubaHelper(string, string);
};

string BinaryMultiplier::multiply(string str1, string str2) {
    string result = "0";
    for (int i = str2.length() - 1, shift = 0; i >= 0; --i, ++shift) {
        if (str2[i] == '1') {
            result = addBinary(result, shiftLeft(str1, shift));
        }
    }
    return result;
}

string BinaryMultiplier::karatsubaMultiply(string str1, string str2) {
    // Karatsuba çarpma, uzun sayılar için daha hızlıdır
    return karatsubaHelper(str1, str2);
}

string BinaryMultiplier::karatsubaHelper(string str1, string str2) {
    // Karatsuba algoritmasının temel hali
    int n = max(str1.size(), str2.size());
    if (n == 1) {
        return multiply(str1, str2);  // Küçük boyutlu çarpma, klasik yöntemle yapılır
    }

    n = (n / 2) + (n % 2);  // Çift uzunlukta ayırma

    string a = str1.substr(0, str1.size() - n);
    string b = str1.substr(str1.size() - n);
    string c = str2.substr(0, str2.size() - n);
    string d = str2.substr(str2.size() - n);

    string ac = karatsubaHelper(a, c);
    string bd = karatsubaHelper(b, d);
    string abcd = karatsubaHelper(addBinary(a, b), addBinary(c, d));
    
    string result = addBinary(addBinary(shiftLeft(ac, 2 * n), shiftLeft(addBinary(ac, bd), n)), bd);
    return result;
}

string BinaryMultiplier::addBinary(string a, string b) {
    string result = "";
    int carry = 0, sum;
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || carry) {
        sum = carry + (i >= 0 ? a[i--] - '0' : 0) + (j >= 0 ? b[j--] - '0' : 0);
        result = char(sum % 2 + '0') + result;
        carry = sum / 2;
    }
    return result;
}

string BinaryMultiplier::shiftLeft(string str, int steps) {
    return str + string(steps, '0');
}

void BinaryMultiplier::binaryToDecimal(string result) {
    unsigned long long decimal = 0;
    for (char bit : result) {
        decimal = decimal * 2 + (bit - '0');
    }
    cout << "Decimal: " << decimal << endl;
}

string generateBinary(int length) {
    string binary;
    for (int i = 0; i < length; ++i) {
        binary += (rand() % 2) ? '1' : '0';
    }
    return binary;
}

int main() {
    srand(time(0));
    ofstream outputFile("results.txt");
    if (!outputFile) {
        cerr << "Dosya açma hatası!" << endl;
        return 1;
    }
    
    BinaryMultiplier multiplier;
    for (int i = 1; i <= 20; ++i) {
        int length = 5 + (i * 2);  // Küçükten büyüğe artan uzunlukta rastgele sayılar
        string num1 = generateBinary(length);
        string num2 = generateBinary(length);
        
        cout << "Test " << i << " : " << endl;
        cout << "Num1: " << num1 << endl;
        cout << "Num2: " << num2 << endl;
        outputFile << "Test " << i << " : " << endl;
        outputFile << "Num1: " << num1 << endl;
        outputFile << "Num2: " << num2 << endl;

        // Classical method time
        clock_t start = clock();
        string resultClassical = multiplier.multiply(num1, num2);
        clock_t end = clock();
        double classicalTime = double(end - start) / CLOCKS_PER_SEC;

        // Karatsuba method time
        start = clock();
        string resultKaratsuba = multiplier.karatsubaMultiply(num1, num2);
        end = clock();
        double karatsubaTime = double(end - start) / CLOCKS_PER_SEC;

        // Display results
        cout << "Binary Result (Classical): " << resultClassical << endl;
        multiplier.binaryToDecimal(resultClassical);
        cout << "Classical Execution Time: " << classicalTime << " seconds" << endl;
        
        cout << "Binary Result (Karatsuba): " << resultKaratsuba << endl;
        multiplier.binaryToDecimal(resultKaratsuba);
        cout << "Karatsuba Execution Time: " << karatsubaTime << " seconds" << endl << endl;

        // Save to file
        outputFile << "Binary Result (Classical): " << resultClassical << endl;
        outputFile << "Classical Execution Time: " << classicalTime << " seconds" << endl;
        outputFile << "Binary Result (Karatsuba): " << resultKaratsuba << endl;
        outputFile << "Karatsuba Execution Time: " << karatsubaTime << " seconds" << endl << endl;
    }
    outputFile.close();
    return 0;
}
