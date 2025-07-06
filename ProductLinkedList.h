#ifndef PRODUCTLINKEDLIST_H
#define PRODUCTLINKEDLIST_H
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include "BuyingProductLinkedList.h" 
using namespace std;

////////////////////// Struct /////////////////////////////

struct Product{
    string id;
    string name;
    float price;
    float buyCost;
    int quantity;

};

class ProductNode{
	private:
	    Product data;
	    ProductNode* next;
	    ProductNode* prev;
	    
	public:
	    void SetData(Product data){
	    	this->data=data;
		}
		void SetNext(ProductNode* next){
			this->next=next;
		}
		void SetPrev(ProductNode* prev){
			this->prev=prev;
		}
		Product GetData(){
			return data;
		}
		ProductNode* GetNext(){
			return next;
		}
		ProductNode* GetPrev(){
			return prev;
		}
};

class ProductLinkedList{
	private:
	    ProductNode* head;
	    int size;
	
	public:
		ProductLinkedList(){
			head=NULL;
			size=0;
		}
		
	    bool isEmpty(){ 
			if(head == NULL)	return true;
			return false;
		}
	
	    void insertAtEnd(Product& product){
	        ProductNode* newNode = new ProductNode();
	        newNode->SetData(product);
	        if (isEmpty()){
	            head = newNode;
	            newNode->SetPrev(NULL);
	            newNode->SetNext(NULL);
	        }
			else{
	            ProductNode* temp = head;
	            while (temp->GetNext() != NULL) {
	                temp = temp->GetNext();
	            }
	            temp->SetNext(newNode);
	            newNode->SetPrev(temp);
	        }
	        size++;
	    }
	
	    void removeNode(ProductNode* node){
	        if (node == NULL) return;
	
	        if (node == head){
	            head = head->GetNext();
	            if (head != NULL){
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
	
	    ProductNode* FindNodeById(string& id){
	        ProductNode* temp = head;
	        while (temp != NULL){
	            if (temp->GetData().id == id){
	                return temp;
	            }
	            temp = temp->GetNext();
	        }
	        return NULL;
	    } 
	
	    ProductNode* FindByName(string& name){
	        ProductNode* temp = head;
	        while (temp != NULL){
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
	        ProductNode* temp = head;
	        int i=0;
			while(temp!=NULL){
				Product tempProduct=temp->GetData();
				cout << " " << ++i << "\t" << tempProduct.id << "\t" << tempProduct.name << "\t\t " << tempProduct.price << "\t\t   " 
					 << tempProduct.buyCost << "\t\t    " << tempProduct.quantity << endl;
				temp=temp->GetNext();
			}
		}
		
	    int getSize(){
			return size;
		}
		
////////////////////// File Handaling /////////////////////////////

		// Writing products
		void writeProducts(){
			ofstream outFile("products.txt", ios::out);
			if (!outFile){
				cerr << "products.txt  could not be Opened for writing";
				pause();
				return;
			}
			ProductNode* tempProduct= head;
			while(tempProduct!=NULL){
				outFile << tempProduct->GetData().id << "\t" << tempProduct->GetData().name << "\t" << tempProduct->GetData().price 
					<< "\t" << tempProduct->GetData().buyCost << "\t" << tempProduct->GetData().quantity << endl;
					tempProduct=tempProduct->GetNext();
			}
		}
		
		void loadProduct(){
			ifstream inFile("products.txt", ios::in);
			if (!inFile){
				cerr << "products.txt  could not be Opened for Reading";
				pause();
				return;
			}
			//			inFile.seekg(0);
			Product temp;
			while (inFile >> temp.id >> temp.name >> temp.price >> temp.buyCost >> temp.quantity){
				insertAtEnd(temp);
			}
			inFile.close();
		}
};

#endif
