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
    NodeStack<T>* pTop; // �������� �� ������� �����

public:
    // ���������� �� �������������
    StackList() { pTop = NULL; }

    // ����������� ���������
    StackList(const StackList& SL)
    {
        NodeStack<T>* p; // �������� ���������
        NodeStack<T>* p2;
        NodeStack<T>* p3;

        // ������������� pTop
        pTop = nullptr;
        p3 = nullptr;

        p = SL.pTop; // �������� p �������� �� ������ SL.pTop->...
        while (p != nullptr)
        {
            // 1. ���������� ����� p2
            try {
                // ������ �������� ���'��
                p2 = new NodeStack<T>;
            }
            catch (bad_alloc e)
            {
                // ���� ���'��� �� �������, �� �����
                cout << e.what() << endl;
                return;
            }

            p2->item = p->item;
            p2->next = nullptr;

            // 2. pTop = pTop + p2
            if (pTop == nullptr) // �������� �����
            {
                pTop = p2;
                p3 = p2;
            }
            else
            {
                p3->next = p2;
                p3 = p3->next;
            }

            // 3. ������� �� ��������� �������
            p = p->next;
        }
    }
    // �������� ������� � ����
    // ������� ��������� �� ������� ������
    void Push(T item)
    {
        NodeStack<T>* p;

        // 1. ���������� �������
        try {
            p = new NodeStack<T>; // ������ ������� ���'���
        }
        catch (bad_alloc e)
        {
            // ���� ���'��� �� ���������, �� �����
            cout << e.what() << endl;
            return;
        }

        p->item = item;
        p->next = pTop; // p ����� �� 1-� �������

        // 2. ������������� pTop �� p
        pTop = p;
    }
    void s_push(NodeStack<T>** pTop, T D) { //������� ���� void(������ �� ����������) ������� ��������� �������� �� ������� ����� � ���������� ������� ����� ������������ � ������
        NodeStack<T>* q; //������� ����� ��������� q ���� ��������� comp. �� ���� ��� � ���� ��� ����� �������
        q = new NodeStack<T>(); //�������� ������ ��� ������ ��������
        q->Data = D; //���������� ����������� �����  � Data ��������
        if (pTop == NULL) { //���� ������� ���, �� ���� ���� ������
            *pTop = q; //�������� ����� ����� ����� �������
        }
        else //���� ���� �� ������
        {
            q->next = *pTop; //�������� ����� �� ������ ��������, � �������. ������ ������ ������ �� ������� ������.
            *pTop = q; //����������, ��� �������� ������ �������� ����� �������
        }
    }

    T Pop()
    {
        // ��������, �� ���� ��������
        if (pTop == NULL)
            return 0;

        NodeStack<T>* p2; // ���������� ��������
        T item;
        item = pTop->item;

        // ������������� ��������� pTop, p2
        p2 = pTop;
        pTop = pTop->next;

        // �������� ���'���, ������� �� 1-� �������
        delete p2;

        // ��������� item
        return item;
    }

    // �-��� �������� � �����
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

    // ����� ���� - ������� �� �������� � �����
    void Empty()
    {
        NodeStack<T>* p; // ���������� ��������
        NodeStack<T>* p2;

        p = pTop;
        while (p != nullptr)
        {
            p2 = p; // ������� ���� � p
            p = p->next; // ������� �� ��������� ������� �����
            delete p2; // �������� ���'���, ������� �� ���������� �������
        }
        pTop = nullptr; // ��������� ������� �����
    }

    // �������� ���������
    StackList<T>& operator=(const StackList<T>& LS)
    {
        // �� � �������� � �����?
        if (pTop != nullptr) Empty();

        NodeStack<T>* p; // ���������� ��������
        NodeStack<T>* p2;
        NodeStack<T>* p3;

        // ������������� pTop
        pTop = nullptr;
        p3 = nullptr;

        p = LS.pTop; // �������� p �������� �� ������ SL.pTop->...
        while (p != nullptr)
        {
            // 1. ���������� ����� p2
            try {
                // ������ ������� ���'���
                p2 = new NodeStack<T>;
            }
            catch (bad_alloc e)
            {
                // ���� ���'��� �� �������, �� �����
                cout << e.what() << endl;
                return *this;
            }
            p2->item = p->item;
            p2->next = nullptr;

            // 2. pTop = pTop + p2
            if (pTop == nullptr) // �������� �����
            {
                pTop = p2;
                p3 = p2;
            }
            else
            {
                p3->next = p2;
                p3 = p3->next;
            }

            // 3. ������� �� ��������� �������
            p = p->next;
        }
        return *this;
    }

    // ���� �����
    void Print(const char* objName)
    {
        cout << "Object: " << objName << endl;

        if (pTop == nullptr)
            cout << "stack is empty." << endl;
        else
        {
            NodeStack<T>* p; // ���������� ��������
            p = pTop;
            while (p != nullptr)
            {
                cout << p->item << "\t";
                p = p->next;
            }
            cout << endl;
        }
    }

    // ����������
    ~StackList()
    {
        Empty();
    }

    // �����, �� ������ ������� � ����� - ������
    
};