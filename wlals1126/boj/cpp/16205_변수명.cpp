#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string toCamel(const string& snake) {
    string camel;
    bool upperNext = false;

    for (char ch : snake) {
        if (ch == '_') {
            upperNext = true;
        } else {
            camel += upperNext ? toupper(ch) : ch;
            upperNext = false;
        }
    }
    return camel;
}

string toPascal(const string& snake) {
    string pascal;
    bool upperNext = true;

    for (char ch : snake) {
        if (ch == '_') {
            upperNext = true;
        } else {
            pascal += upperNext ? toupper(ch) : ch;
            upperNext = false;
        }
    }
    return pascal;
}

string toSnake(const string& str) {
    string snake;
    for (char ch : str) {
        if (isupper(ch)) {
            snake += '_';
            snake += tolower(ch);
        } else {
            snake += ch;
        }
    }
    return snake[0] == '_' ? snake.substr(1) : snake;
}

string camelToPascal(const string& camel) {
    string pascal = camel;
    pascal[0] = toupper(pascal[0]);
    return pascal;
}

string pascalToCamel(const string& pascal) {
    string camel = pascal;
    camel[0] = tolower(camel[0]);
    return camel;
}

int main() {
    int type;
    string var;

    cin >> type >> var;

    string camel, snake, pascal;

    if (type == 1) {
        camel = var;
        snake = toSnake(camel);
        pascal = camelToPascal(camel);
    } else if (type == 2) {
        snake = var;
        camel = toCamel(snake);
        pascal = toPascal(snake);
    } else if (type == 3) {
        pascal = var;
        camel = pascalToCamel(pascal);
        snake = toSnake(pascal);
    }

    cout << camel << endl;
    cout << snake << endl;
    cout << pascal << endl;

    return 0;
}
