#ifndef BUYINGPRODUCTLINKEDLIST_H
#define BUYINGPRODUCTLINKEDLIST_H
#include <conio.h>
#include <iostream>
#include <string>
using namespace std;

/////////////////////// Extra Functions /////////////////////

void cls() {
    system("cls");
}

void pause() {
    cout << "\tPress any key to continue!" << endl << "\t";
    getch();
}

////////////////////// Struct //////////////////////////////

struct BuyingProduct{
    string id;
    string name;
    float price;
    int quantity;

};

class BuyingProductNode{
	private:
	    BuyingProduct data;
	    BuyingProductNode* next;
	    BuyingProductNode* prev;
	    
	public:
	    void SetData(BuyingProduct data){
	    	this->data = data;
		}
		void SetNext(BuyingProductNode* next){
			this->next = next;
		}
		void SetPrev(BuyingProductNode* prev){
			this->prev = prev;
		}
		BuyingProduct GetData(){
			return data;
		}
		BuyingProductNode* GetNext(){
			return next;
		}
		BuyingProductNode* GetPrev(){
			return prev;
		}
};

class BuyingProductLinkedList{
	private:
	    BuyingProductNode* head;
	    int size;
	
	public:
		BuyingProductLinkedList(){
			head = NULL;
			size = 0;
		}
		
	    bool isEmpty(){ 
			return head == NULL;
		}
	
	    void insertAtEnd(BuyingProduct& product){
	        BuyingProductNode* newNode = new BuyingProductNode();
	        newNode->SetData(product);
	        if (isEmpty()){
	            head = newNode;
	            newNode->SetPrev(NULL);
	            newNode->SetNext(NULL);
	        }
			else{
	            BuyingProductNode* temp = head;
	            while (temp->GetNext() != NULL){
	                temp = temp->GetNext();
	            }
	            temp->SetNext(newNode);
	            newNode->SetPrev(temp);
	        }
	        size++;
	    }
	
	    void removeNode(BuyingProductNode* node){
	        if (node == NULL) return;
	
	        if (node == head){
	            head = head->GetNext();
	            if (head != NULL) {
	                head->SetPrev(NULL);
	            }
	        }
			else{
	            if (node->GetPrev() != NULL){
	            	node->GetPrev()->SetNext(node->GetNext());
	            }
	            if (node->GetNext() != NULL){
	            	node->GetNext()->SetPrev(node->GetPrev());
	            }
	        }
	        delete node;
	        size--;
	    }
	
	    BuyingProductNode* FindNodeById(string& id){
	        BuyingProductNode* temp = head;
	        while (temp != NULL){
	            if (temp->GetData().id == id){
	                return temp;
	            }
	            temp = temp->GetNext();
	        }
	        return NULL;
	    } 
	
	    BuyingProductNode* FindByName(string& name){
	        BuyingProductNode* temp = head;
	        while (temp != NULL) {
	            if (temp->GetData().name == name){
	                return temp;
	            }
	            temp = temp->GetNext();
	        }
	        return NULL;
	    }
	
	    bool isIdAvailable(string& id){
	        return FindNodeById(id) == NULL;
	    }

	    void PrintAllProducts(){
	    	if (isEmpty()){
	            cout << "No product found!!" << endl;
	            return;
	        }
	        BuyingProductNode* temp = head;
			while(temp != NULL){
				static int i = 0;
				BuyingProduct tempProduct = temp->GetData();
				cout << " " << ++i << "\t" << tempProduct.id << "\t" << tempProduct.name << "\t\t " 
                     << tempProduct.price << "\t\t    " << tempProduct.quantity << endl;
				temp = temp->GetNext();
			}
		}
		
	    int getSize(){
			return size;
		}
		
		BuyingProductNode* GetHead(){
			return head;
		}
		
		void SetHead(BuyingProductNode* head){
			this->head=head;
		}

};

#endif
