#include <iostream>
#include <locale>  // Locale тохиргоо хийхэд
using namespace std;

// Загвар LinkedList класс: дурын төрлийн өгөгдлийг хадгална
template <typename T>
class LinkedList {
private:
    // Дотоод Node бүтэц — нэг элемент болон дараагийн заалт
    struct Node {
        T data;
        Node* next;
        Node(T d) : data(d), next(nullptr) {}
    };
    Node* head;   // жагсаалтын эхний заалт
    int size;     // жагсаалтын одоогийн урт

public:
    LinkedList() : head(nullptr), size(0) {}

    // Жагсаалтын төгсгөлд элемент нэмэх
    void add(T t) {
        Node* newNode = new Node(t);
        if (!head) {
            head = newNode;
        } else {
            Node* cur = head;
            while (cur->next) {
                cur = cur->next;
            }
            cur->next = newNode;
        }
        size++;
    }

    // Тодорхой index-д шинэ элемент оруулах
    void insert(T t, int index) {
        if (index <= 0 || !head) {
            Node* newNode = new Node(t);
            newNode->next = head;
            head = newNode;
        } else {
            Node* cur = head;
            for (int i = 0; i < index - 1 && cur->next; i++) {
                cur = cur->next;
            }
            Node* newNode = new Node(t);
            newNode->next = cur->next;
            cur->next = newNode;
        }
        size++;
    }

    // index-д байгаа элементийг буцаах
    T get(int index) {
        if (index < 0 || index >= size) throw out_of_range("Index out of range");
        Node* cur = head;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        return cur->data;
    }

    // index-д байгаа элементийг устгах
    void removeAt(int index) {
        if (index < 0 || index >= size) return;
        if (index == 0) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
        } else {
            Node* cur = head;
            for (int i = 0; i < index - 1; i++) {
                cur = cur->next;
            }
            Node* toDelete = cur->next;
            cur->next = toDelete->next;
            delete toDelete;
        }
        size--;
    }

    // Жагсаалтын уртыг буцаах
    int length() {
        return size;
    }

    // Деструктор: санах ойг цэвэрлэнэ
    ~LinkedList() {
        Node* cur = head;
        while (cur) {
            Node* next = cur->next;
            delete cur;
            cur = next;
        }
    }
};

