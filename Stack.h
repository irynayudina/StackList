#pragma once
template <typename T>
struct NodeStack
{
	T item;
	NodeStack<T>* next;
};
template <typename T>
class Stack 
{
private:
    NodeStack<T>* pTop; // покажчик на вершину стеку

public:
    // конструкто за замовчуванням
    StackList() { pTop = NULL; }

    // конструктор копіювання
    StackList(const StackList& SL)
    {
        NodeStack<T>* p; // додаткові покажчики
        NodeStack<T>* p2;
        NodeStack<T>* p3;

        // Ініціалізувати pTop
        pTop = nullptr;
        p3 = nullptr;

        p = SL.pTop; // покажчик p рухається по списку SL.pTop->...
        while (p != nullptr)
        {
            // 1. Сформувати вузол p2
            try {
                // спроба виділення пам'яті
                p2 = new NodeStack<T>;
            }
            catch (bad_alloc e)
            {
                // якщо пам'ять не виділена, то вихід
                cout << e.what() << endl;
                return;
            }

            p2->item = p->item;
            p2->next = nullptr;

            // 2. pTop = pTop + p2
            if (pTop == nullptr) // створити чергу
            {
                pTop = p2;
                p3 = p2;
            }
            else
            {
                p3->next = p2;
                p3 = p3->next;
            }

            // 3. Перейти на наступний елемент
            p = p->next;
        }
    }
    // помістити елемент у стек
    // елемент поміщається на початок списку
    void Push(T item)
    {
        NodeStack<T>* p;

        // 1. Сформувати елемент
        try {
            p = new NodeStack<T>; // спроба виділити пам'ять
        }
        catch (bad_alloc e)
        {
            // якщо пам'ять не виділилась, то вихід
            cout << e.what() << endl;
            return;
        }

        p->item = item;
        p->next = pTop; // p вказує на 1-й елемент

        // 2. Перенаправити pTop на p
        pTop = p;
    }
    void s_push(NodeStack<T>** pTop, T D) { //функция типа void(ничего не возвращает) которая принимает указатль на вершину стека и переменную которая будет записываться в ячейку
        NodeStack<T>* q; //Создаем новый указатель q типа структуры comp. По сути это и есть наш новый элемент
        q = new NodeStack<T>(); //выделяем память для нового элемента
        q->Data = D; //Записываем необходимое число  в Data элемента
        if (pTop == NULL) { //Если вершины нет, то есть стек пустой
            *pTop = q; //вершиной стека будет новый элемент
        }
        else //если стек не пустой
        {
            q->next = *pTop; //Проводим связь от нового элемента, к вершине. Тоесть кладем книжку на вершину стопки.
            *pTop = q; //Обозначаем, что вершиной теперь является новый элемент
        }
    }

    T Pop()
    {
        // перевірка, чи стек порожній
        if (pTop == NULL)
            return 0;

        NodeStack<T>* p2; // додатковий покажчик
        T item;
        item = pTop->item;

        // перенаправити покажчики pTop, p2
        p2 = pTop;
        pTop = pTop->next;

        // Звільнити пам'ять, виділену під 1-й елемент
        delete p2;

        // повернути item
        return item;
    }

    // К-сть елементів у стеку
    int Count()
    {
        if (pTop == NULL)
            return 0;
        else
        {
            NodeStack<T>* p = pTop;
            int count = 0;
            while (p != nullptr)
            {
                count++;
                p = p->next;
            }
        }
    }

    // очищує стек - видаляє усі елементи зі стеку
    void Empty()
    {
        NodeStack<T>* p; // додатковий покажчик
        NodeStack<T>* p2;

        p = pTop;
        while (p != nullptr)
        {
            p2 = p; // зробити копію з p
            p = p->next; // перейти на наступний елемент стеку
            delete p2; // видалити пам'ять, виділену під попередній елемент
        }
        pTop = nullptr; // поправити вершину стеку
    }

    // оператор копіювання
    StackList<T>& operator=(const StackList<T>& LS)
    {
        // чи є елементи в стеку?
        if (pTop != nullptr) Empty();

        NodeStack<T>* p; // додатковий покажчик
        NodeStack<T>* p2;
        NodeStack<T>* p3;

        // Ініціалізувати pTop
        pTop = nullptr;
        p3 = nullptr;

        p = LS.pTop; // покажчик p рухається по списку SL.pTop->...
        while (p != nullptr)
        {
            // 1. Сформувати вузол p2
            try {
                // спроба виділити пам'ять
                p2 = new NodeStack<T>;
            }
            catch (bad_alloc e)
            {
                // якщо пам'ять не виділена, то вихід
                cout << e.what() << endl;
                return *this;
            }
            p2->item = p->item;
            p2->next = nullptr;

            // 2. pTop = pTop + p2
            if (pTop == nullptr) // створити чергу
            {
                pTop = p2;
                p3 = p2;
            }
            else
            {
                p3->next = p2;
                p3 = p3->next;
            }

            // 3. Перейти на наступний елемент
            p = p->next;
        }
        return *this;
    }

    // вивід стеку
    void Print(const char* objName)
    {
        cout << "Object: " << objName << endl;

        if (pTop == nullptr)
            cout << "stack is empty." << endl;
        else
        {
            NodeStack<T>* p; // додатковий покажчик
            p = pTop;
            while (p != nullptr)
            {
                cout << p->item << "\t";
                p = p->next;
            }
            cout << endl;
        }
    }

    // деструктор
    ~StackList()
    {
        Empty();
    }

    // метод, що витягує елемент зі стеку - працює
    
};