#ifndef INC_04_BINARY_SEARCH_TREE_SEARCH_SEQUENCEST_H
#define INC_04_BINARY_SEARCH_TREE_SEARCH_SEQUENCEST_H

#include <iostream>
#include <cassert>

using namespace std;


template<typename Key, typename Value>
class SequenceST{

private:
    
    struct Node{
        Key key;
        Value value;
        Node *next;

        Node(Key key, Value value){
            this->key = key;
            this->value = value;
            this->next = NULL;
        }
    };

    Node* head;
    int count;

public:
    
    SequenceST(){
        head = NULL;
        count = 0;
    }

    ~SequenceST(){
        while( head != NULL){
            Node *node = head;
            head = head->next;
            delete node;
            count --;
        }

        assert( head == NULL && count == 0 );
    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    };

    void insert(Key key, Value value){

        Node *node = head;
        while( node != NULL ){
            if( key == node->key ){
                node->value = value;
                return;
            }
            node = node->next;
        }

        Node *newNode = new Node(key, value);
        newNode->next = head;
        head = newNode;
        count ++;
    }

    bool contain(Key key){

        Node *node = head;
        while( node != NULL ){
            if( key == node->key )
                return true;
            node = node->next;
        }
        return false;
    }

    Value* search(Key key){

        Node *node = head;
        while( node != NULL ){
            if( key == node->key )
                return &(node->value);
            node = node->next;
        }
        return NULL;
    }

    void remove(Key key){

        if( head == NULL )
            return;

        if( key == head->key ){
            Node* delNode = head;
            head = head->next;
            delete delNode;
            count--;
            return;
        }

        Node *node = head;
        while( node->next != NULL && node->next->key != key )
            node = node->next;

        if( node->next != NULL ){
            Node* delNode = node->next;
            node->next = delNode->next;
            delete delNode;
            count --;
            return;
        }
    }
};

#endif