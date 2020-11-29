#ifndef _SINGLE_LINKED_LIST_
#define _SINGLE_LINKED_LIST_
#if 0
#define NDEBUG // to disable the assert() funcs
#endif
#include <iostream>
#include <assert.h>

template <typename T = int>
class Node {
public:
    T* data;
    Node* pNode;

    Node() { data = NULL; pNode = NULL; }

    Node(T* val) : data(val) { pNode = NULL; }

    // Node(int val, Node *p): data(val), pNode(p) {}

    ~Node() {}
};

template <typename T =int>
class SingleLinkedList {
private:
    Node<T>* pHead;
    uint32_t size;
public:
    SingleLinkedList() : size(0) {
        this->pHead = NULL;
    }

    void printList() {
        Node<T>* pTmp = this->pHead;
        
        if (pTmp == NULL) {
            std::cout << "Empty List" << std::endl;
        }
        while (pTmp != NULL) {
            std::cout << *pTmp->data << "\t";
            pTmp = pTmp->pNode;
        }
    }

    uint32_t sizeOfList () {
        return this->size;
    }

    void insertFirst(T* val) {
        assert(val);
        Node<T>* pTmp = new Node<T>(val);
        assert(pTmp);
        
        pTmp->pNode = this->pHead;
        this->pHead = pTmp;
        this->size += 1;
    }

    void insertLast(T* val) {
        assert(val);
        Node<T>* pTmp = new Node<T>(val);
        Node<T>* pLast = this->pHead;
        assert(pTmp);
        
        while (pLast->pNode != NULL) {
            // find the last element in the list
            pLast = pLast->pNode;
        }

        pLast->pNode = pTmp;
        this->size += 1;
    }

    void insertMid(T* val, uint32_t pos) {
        assert(val);
        if (pos > this->size) {
            std::cout << "Invalid position" << std::endl;
            return;
        }
        Node<T>* pTmp = new Node<T>(val);
        assert(pTmp);

        Node<T>* pPos = this->pHead;
        Node<T>* pPre = pPos;
        while (pPos->pNode != NULL && pos != 0) {
            pos -= 1;
            // find the element at position pos
            pPre = pPos;
            pPos = pPos->pNode;
        }

        pTmp->pNode = pPos;
        pPre->pNode = pTmp;
        this->size += 1;
    }

    Node<T>* searchNode(T* val) {
        assert(val);
        Node<T>* pPos = this->pHead;

        while (pPos != NULL && pPos->data != val) {
            pPos = pPos->pNode;
        }

        return pPos;
        
    }

    void removeNode(T* val) {
        assert(val);
        Node<T>* pPos = this->pHead;
        Node<T>* pPre = pPos;
        while (pPos != NULL && pPos->data != val) {
            pPre = pPos;
            pPos = pPos->pNode;
        }
        if (pPos == NULL) {
            std::cout << "Element not exist" << std::endl;
            return;
        }
        else {
            if (this->pHead->data == val) {
                this->pHead = this->pHead->pNode;
            }
            else {
                pPre->pNode = pPos->pNode;
                pPos->pNode = NULL;
                delete pPos;
            }
        }
        this->size -= 1;
    }

    void sortList() {

    }

    void freeMemory() {
        Node<T>* pTmp = NULL;
        while (this->pHead != NULL) {
            pTmp = this->pHead;
            this->pHead = this->pHead->pNode;
            pTmp->pNode = NULL;
            delete pTmp;
            this->size -= 1;
        }
    }

    ~SingleLinkedList() {
        freeMemory();
    }

};
#endif