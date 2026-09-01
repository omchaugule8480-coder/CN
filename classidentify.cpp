#include <iostream>
#include <string>
using namespace std;

int main()
{
    string ip;
    cout << "Enter IPv4 address: ";
    cin >> ip;

    int a, b, c, d;

    // Read four octets
    char dot1, dot2, dot3;

    // Check IPv4 format
    if (sscanf(ip.c_str(), "%d%c%d%c%d%c%d",
               &a, &dot1, &b, &dot2, &c, &dot3, &d) != 7)
    {
        cout << "Invalid IPv4 Address";
        return 0;
    }

    // Check dots
    if (dot1 != '.' || dot2 != '.' || dot3 != '.')
    {
        cout << "Invalid IPv4 Address";
        return 0;
    }

    // Check range of each octet
    if (a < 0 || a > 255 ||
        b < 0 || b > 255 ||
        c < 0 || c > 255 ||
        d < 0 || d > 255)
    {
        cout << "Invalid IPv4 Address";
        return 0;
    }

    cout << "\nValid IPv4 Address" << endl;

    // Display first byte
    cout << "First Byte: " << a << endl;

    // Find IP class
    char ipClass;

    if (a >= 1 && a <= 127)
        ipClass = 'A';
    else if (a >= 128 && a <= 191)
        ipClass = 'B';
    else if (a >= 192 && a <= 223)
        ipClass = 'C';
    else if (a >= 224 && a <= 239)
        ipClass = 'D';
    else
        ipClass = 'E';

    cout << "Class: " << ipClass << endl;

    // Display Net ID, Host ID and Network Address
    if (ipClass == 'A')
    {
        cout << "Net ID: " << a << endl;
        cout << "Host ID: " << b << "." << c << "." << d << endl;
        cout << "Network Address: " << a << ".0.0.0" << endl;
    }
    else if (ipClass == 'B')
    {
        cout << "Net ID: " << a << "." << b << endl;
        cout << "Host ID: " << c << "." << d << endl;
        cout << "Network Address: " << a << "." << b << ".0.0" << endl;
    }
    else if (ipClass == 'C')
    {
        cout << "Net ID: " << a << "." << b << "." << c << endl;
        cout << "Host ID: " << d << endl;
        cout << "Network Address: " << a << "." << b << "." << c << ".0" << endl;
    }
    else
    {
        cout << "Net ID: Not applicable" << endl;
        cout << "Host ID: Not applicable" << endl;
        cout << "Network Address: Not applicable" << endl;
    }

    return 0;
}