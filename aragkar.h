#pragma once
#include<iostream>
using namespace std;
#ifndef ARAGKAR_H
#define ARAGKAR_H
template<typename T>class node{
public:
    T data;
    node *next;
    node(T value);
};

template<typename T> class aditya{
private:
    node<T>* front;
    node<T>* rear;
public:
    aditya();
    
    T peek_front();
    
    T peek_back();

    void pushback(T value);
    
    void pushfront(T value);
    
    void popback();
    
    void popfront();

    void clearall();

    void display();
//PEEK, PUSHBACK, PUSHFRONT, POPBACK, POPFRONT
};
template<typename T> node<T>::node(T value){
    this->data=value;
    this->next=NULL;
}

template<typename T> aditya<T>::aditya(){
    front=NULL;
    rear=NULL;
}
    
template<typename T> T aditya<T>::peek_front(){
    if(front==NULL && rear==NULL){
        return T();
    }
    else{
        return front->data;
    }
}
    
template<typename T> T aditya<T>::peek_back(){
    if(front==NULL && rear==NULL){
        return NULL;
    }
    else{
        return rear->data;
    }
}

template<typename T> void aditya<T>::pushback(T value){
    if(front==NULL && rear==NULL){
        front= new node<T>(value);
        rear=front;
    }
    else{
        rear->next=new node<T>(value);
        rear=rear->next;
    }
}
    
template<typename T> void aditya<T>::pushfront(T value){
    if(front==NULL && rear==NULL){
        front= new node<T>(value);
        rear=front;
    }
    else{
        node<T> *temp=new node<T>(value);
        temp->next=front;
        front=temp;
    }
}
    
template<typename T> void aditya<T>::popback(){
    if(front==NULL && rear==NULL){
        return;
    }
    else if(rear==front){
        node<T> *temp=rear;
        front=NULL;
        rear=NULL;
        delete(temp);
    }
    else{
        node<T> *ptr=front;
        node<T> *temp=NULL;
        while(ptr->next!=rear){
            ptr=ptr->next;
        }
        temp=rear;
        rear=ptr;
        rear->next=NULL;
        delete(temp);
    }
}
    
template<typename T> void aditya<T>::popfront(){
    if(front==NULL && rear==NULL){
        return;
    }
    else if(front==rear){
        node<T> *temp=front;
        front=NULL;
        rear=NULL;
        delete(temp);
    }
    else{
        node<T> *temp=front;
        front=front->next;
        delete(temp);
    }
}

template<typename T> void aditya<T>::clearall(){
    if(front==NULL){
        cout<<"No List\n";
    }
    else{
        while(front!=NULL){
            node<T> *temp=front->next;
            delete front;
            front=temp;
        }
        front=rear=NULL;
    }
}

template<typename T> void aditya<T>::display(){
    if(front==NULL && rear==NULL){
        cout<<"no list";
    }
    else{
        node<T> *temp=front;
        while(temp!=NULL){
            cout<<temp->data<<"  ";
            temp=temp->next;
        }
        cout<<"\n";
    }
}
#endif