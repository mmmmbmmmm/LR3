#include <iostream>
#include <ctime>
using namespace std;


struct Stack {
    int info;
    Stack* next;
};


Stack* input(Stack* p, int in);
Stack* New_Stack_5(Stack* p, int min);
Stack* pop(Stack* p);
Stack* OutStack(Stack* p, int& out);
void show(Stack* p);
void Clear(Stack** p);
void* Del(Stack* p, int);
int sort(Stack* p);
int unnumericInputProtection();
int main()
{
    Stack* kopf, * kopf1;
    kopf = kopf1 = NULL;
    int min = 0;
    setlocale(LC_ALL, "Russian");
    srand((unsigned)time(NULL));
    int choise, kol, in;
    cout << "\t\t\t*****Добро пожаловать в стеки!*****" << endl;
    while (true)
    {
        cout << "1.Создать стек" << endl << "2.Ввести элемент" << endl << "3.Просмотреть стек" << endl << "4.Удалить элемент" << endl << "5.Стереть данные" << endl
            << "6.Индивидуальное задание" << endl << "0.Выход" << endl;
        choise = unnumericInputProtection();
        switch (choise)
        {
        case 1:
            //system("cls");
            if (choise == 1 && kopf != NULL)
            {
                cout << "*****Почистите память!*****" << endl;
                break;
            }
            cout << "*****Стек создан!*****" << endl;
            cout << "Количество элементов" << endl;
            kol = unnumericInputProtection();
            for (int i = 0; i < kol; i++)
            {
                in = rand() % 20 - 20;
                kopf = input(kopf, in);
            }
            break;
        case 2:
            //system("cls");
            cout << "*****Введите элемент*****" << endl;
            in = unnumericInputProtection();
            kopf = input(kopf, in);
            break;
        case 3:
            if (!kopf)
            {
                cout << "*****Стек пуст!*****" << endl;
                break;
            }
            cout << "**********Стек**********" << endl;
            show(kopf);
            break;
        case 4:
            system("cls");
            if (!kopf)
            {
                cout << "*****Стек пуст!*****" << endl;
                break;
            }
            kopf = pop(kopf);
            break;
        case 5:
            //system("cls");
            Clear(&kopf);
            cout << "**********" << endl;
            cout << "*****Память осовбождена*****" << endl;
            break;
        case 6:
            //system("cls");
            if (!kopf)
            {
                cout << "*****Стек пуст!*****" << endl;
                break;
            }
            min = sort(kopf);
            cout << min << endl;
            kopf1 = New_Stack_5(kopf, min);
            show(kopf1);
            //Del(kopf,MaxElement);
            //kopf = pop(kopf);

            break;
        case 0:
            if (kopf != NULL)
                Clear(&kopf);
            if (kopf1 != NULL)
                Clear(&kopf1);
            return 0;
        }
    }
    return 0;
}
Stack* input(Stack* p, int in)
{
    Stack* a = new Stack;
    a->info = in;
    a->next = p;
    return a;
}
Stack* input1(Stack* a, int in)
{
    Stack* t = new Stack;
    t->info = in;
    t->next = a;
    return t;
}
Stack* pop(Stack* p)
{
    Stack* t;
    t = p;
    p = p->next;
    delete t;
    return p;
}
void* Del(Stack* p, int MaxElement)
{
    cout << "\t\t\tМаксимальный элемент стека: " << MaxElement << endl;
    Stack* previous = p;
    Stack* Sp = p->next;
    while (Sp != NULL)
    {
        if ((Sp->info) == MaxElement)
        {
            previous->next = Sp->next; //Проводим связь от предыдущего элемента к следующему
            delete Sp;
            Sp = previous->next;
        }
        else
        {
            previous = Sp;
            Sp = Sp->next;
        }
    }
    return p;
}
void show(Stack* p)
{

    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}
void Clear(Stack** p)
{
    Stack* t;
    while (*p != NULL)
    {
        t = *p;
        *p = (*p)->next;
        delete t;
    }
}
int sort(Stack* p)
{
    Stack* t = p;
    int min = t->info;
    while (t != NULL)
    {
        if (min > t->info)
        {
            min = t->info;
        }
        t = (t)->next;
    }
    cout << min;
    return min;
}
int unnumericInputProtection() // защита от дурака
{
    int number;
    while (true)
    {
        while (!(cin >> number))
        {
            cout << "Значение должно быть числом!\n";
            cin.clear();
            cin.ignore(256, '\n');
        }
        if (number >= 0)
        {
            break;
        }
        else
        {
            cout << "Число должно быть положительным!" << endl << "Введите снова: ";
            continue;
        }
    }
    return number;
}
Stack* New_Stack_5(Stack* p, int min)
{
    int  inf;
    Stack* new_p = NULL;
    Stack* t = p;
    p = p->next;
    while (p->info >= min) {
        p = OutStack(p, inf);

        new_p = input1(new_p, inf);
        p = p->next;


    }
    return  new_p;
}
Stack* OutStack(Stack* p, int& out) {
    Stack* t = p;
    out = p->info;
    p = p->next;
    delete t;
    return p;
}