#include <iostream>
#include <string>
#include "Vector.h"
#include "StackVector .h"
using namespace std;

string infixToPostfix(string& infix)
{
    int count = 0;//מונה
    char postfix[100];//פה נשמור את התוצאה ואז נשלח
    StackVector<char> stk(infix.size());

    for (int i = 0; i < infix.size(); ++i) {
        if( infix[i] == '(')//case of # ( #
        {
            stk.push(infix[i]);//נשמור במחסנית
        }
        if( infix[i] == ')')//case of # ) #
        {
            while (stk.top() != '(')//כול עוד שלא הגענו לסורג סמאלי נכניס את כול הנתונים שבמחסנית למחרוזת
            {
                postfix[count] = stk.pop();
                count++;
                postfix[count] = ' ';
                count++;
            }
            stk.pop();//נוציא את הסוגרים מהמחרוזת
        }
        if( infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')//case of # oper #
        {
            while (!stk.isEmpty() && stk.top() != '(' )
            {
                if ( (infix[i] == '*' ||  infix[i] == '/') && stk.top() == '+' || stk.top() == '-')//בודק את סדר פעולות המשבון
                {
                    postfix[count] = stk.pop();
                    count++;
                    postfix[count] = ' ';
                    count++;
                }
            }
            stk.push(infix[i]);
        }
        if( infix[i] >= '0' && infix[i] <= '9')//case of # num #
        {
            for (; infix[i] >= '0' && infix[i] <= '9' ; ++i) {//לתפל במקרה שהמספר הוא יותר מ-10
                postfix[count] = infix[i];
                count++;
            }
            i--;//זה כי הלולאה מקודם מעלה את ן את יותר ממנה שצריך
            postfix[count] = ' ';
            count++;
        }
    }
    while (!stk.isEmpty())//מוצא אצ כול מה שנשאר במחסנית
    {
        postfix[count] = stk.pop();
        count++;
    }

    postfix[count] = '\0';//

    return postfix;
}

int calcPostfix(string& postfix)
{
    StackVector<int> stk(postfix.size());

    for (int i = 0; i < postfix.size(); ++i) {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            int num = int(postfix[i]) - 48;
            for (i++; postfix[i] >= '0' && postfix[i] <= '9' ; ++i) {//לתפל במקרה שהמספר הוא יותר מ-10
                num = num * 10 + int (postfix[i]) - 48;
            }
            i--;//זה כי הלולאה מקודם מעלה את ן את יותר ממנה שצריך
            stk.push(num);
        }
        int num1, num2;
        if(postfix[i] == '+'){
            num1 = stk.pop();
            num2 = stk.pop();
            stk.push(num1 + num2);
        }
        if(postfix[i] == '-'){
            num1 = stk.pop();
            num2 = stk.pop();
            stk.push(num2 - num1);
        }
        if(postfix[i] == '*'){
            num1 = stk.pop();
            num2 = stk.pop();
            stk.push(num1 * num2);
        }
        if(postfix[i] == '/'){
            num1 = stk.pop();
            num2 = stk.pop();
            stk.push(num2 / num1);//יש פה בעיה בחילוק צריך לבדוק
        }
    }
    return stk.pop();
}


int main() {
    string exp;
    cout << "enter an infix expression as a string" << endl;
    cin >> exp;
    string postfix = infixToPostfix(exp);
    cout << "in postfix form: " << postfix << endl;

    cout << "calculated value: " << calcPostfix(postfix) << endl;
    return 0;
}
