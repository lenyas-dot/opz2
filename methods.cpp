
#include <vector>
#include <cstring>
#include <string>
#include "methods.h"
using namespace std;






/*
 *
 *
 *
 *
 * ЧИСЛА МОЖНО ВВОДИТЬ ОТ 0 ДО 9
 *
 *
 *
 *
 */





void  forOperations(vector<char>& stack, vector<char>& signs, char op)
{
    switch(op)
    {
        case '/':
            signs.push_back(op);
            break;
        case '*':
            while (!signs.empty() && signs.back() == '/')
            {
                stack.push_back(signs.back());
                signs.pop_back();
            }
            signs.push_back(op);
            break;
        case '+':
        case '-':
            while (!signs.empty() && (signs.back() == '/' || signs.back() == '*' || signs.back() == '-' || signs.back() == '+'))
            {
                stack.push_back(signs.back());
                signs.pop_back();
            }
            signs.push_back(op);
            break;

    }
}


float calculate(vector<char> stackInp)
{
    float result = 0;
    vector<char> stack;

    while (!stackInp.empty())
    {
        stack.push_back(stackInp.back());
        stackInp.pop_back();
    }
    vector<int> a;
    for (int i = 0; i < stack.size(); ++i) {
        a.push_back(0);
    }
    int i = 0;
    while (!stack.empty())
    {


        if (stack.back() >= '0' && stack.back() <= '9')
        {
            int b = (int)stack.back() - (int)'0';
            a.push_back(b);
            stack.pop_back();
            i++;
        }
        else
        {
            float temp = 0;
            float temp1 = 0;
            switch (stack.back())
            {
                case '+':
                    temp = a.back();
                    a.pop_back();
                    temp += a.back();
                    result = temp;
                    a.pop_back();
                    stack.pop_back();
                    if (stack.size() != 0)
                    {
                        if (result >= 0 && result <= 9)
                        {
                            stack.push_back(result + '0');
                        }
                        else
                        {
                            a.push_back(result);
                        }
                    }
                    break;
                case '-':
                    temp = a.back();
                    temp *= -1;
                    a.pop_back();
                    temp += a.back();
                    result = temp;
                    //a.erase(a.begin() + i - 1);
                    //a.erase(a.begin() + i - 2);
                    a.pop_back();
                    stack.pop_back();
                    if (stack.size() != 0)
                    {
                        if (result >= 0 && result <= 9)
                        {
                            stack.push_back(result + '0');
                        }
                        else
                        {
                            a.push_back(result);
                        }
                    }
                    break;
                case '*':
                    temp = a.back();
                    a.pop_back();
                    temp *= a.back();
                    result = temp;
                    a.pop_back();

                    //a.erase(a.begin() + i - 1);
                    //a.erase(a.begin() + i - 2);
                    stack.pop_back();

                    if (stack.size() != 0)
                    {
                        if (result >= '0' && result <= '9')
                        {
                            stack.push_back(result + '0');
                        }
                        else
                        {
                            a.push_back(result);
                        }
                    }
                    break;
                case '/':
                    temp = a.back();
                    a.pop_back();
                    temp1 = a.back();
                    temp = temp1 / temp;
                    result = temp;
                    a.pop_back();

                    //a.erase(a.begin() + i - 1);
                    //a.erase(a.begin() + i - 2);
                    stack.pop_back();

                    if (stack.size() != 0)
                    {
                        if (result >= 0 && result <= 9)
                        {
                            stack.push_back(result + '0');
                        }
                        else
                        {
                            a.push_back(result);
                        }
                    }
                    break;
            }
        }


    }
    return result;



}


float mainLogic(const char* str)
{
    vector<char> stack;
    vector<char> signs;
    vector<int> indexBrackets;

    int i = 0;
    while (true)
    {
        if (str[i] == '\0' || i >= strlen(str))
        {
            break;
        }
        switch(str[i])
        {
            case '0'...'9':
                stack.push_back(str[i]);
                break;
            case '*':
                forOperations(stack, signs, str[i]);
                break;
            case '/':
                forOperations(stack, signs, str[i]);
                break;
            case '-':
                forOperations(stack, signs, str[i]);
                break;
            case '+':
                forOperations(stack, signs, str[i]);
                break;
            case '(':
                indexBrackets.push_back(signs.size());
                vector<char> tempStack;
                vector<char> tempSign;
                int j = i;
                while (str[j] != ')') {
                    switch (str[j]) {
                        case '0'...'9':
                            stack.push_back(str[j]);
                            break;
                        case '*':
                        case '/':
                        case '+':
                        case '-':
                            forOperations(tempStack, tempSign, str[j]);
                            break;
                    }
                    j++;
                    i++;
                }
                while (!tempStack.empty())
                {
                    stack.push_back(tempStack.back());
                    tempStack.pop_back();
                }
                while (!tempSign.empty())
                {
                    stack.push_back(tempSign.back());
                    tempSign.pop_back();
                }
                while (!signs.empty())
                {
                    stack.push_back(signs.back());
                    signs.pop_back();
                }
            break;
        }

        i++;
    }
    while (!signs.empty())
    {
        stack.push_back(signs.back());
        signs.pop_back();
    }

    float result = calculate(stack);
    return result;
    return 0;

}
