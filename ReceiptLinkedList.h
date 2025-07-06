#ifndef RECEIPTLINKEDLIST_H
#define RECEIPTLINKEDLIST_H

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include "BuyingProductLinkedList.h" // Include your ProductLinkedList header here
using namespace std;

////////////////////// Struct /////////////////////////////

struct Receipt{
    char id[7];
    string customerName;
    float totalBillAmount;
    float billAmountWithoutDis;
    string customerPhoneNumber;
    char date[11];
    int loyaltyStatus;
    BuyingProductLinkedList buyingProducts;

};

class ReceiptNode{
    private:
        Receipt data;
        ReceiptNode* next;
        ReceiptNode* prev;
        
    public:
        void SetData(Receipt data){
            this->data = data;
        }
        void SetNext(ReceiptNode* next){
            this->next = next;
        }
        void SetPrev(ReceiptNode* prev){
            this->prev = prev;
        }
        Receipt GetData(){
            return data;
        }
        ReceiptNode* GetNext(){
            return next;
        }
        ReceiptNode* GetPrev(){
            return prev;
        }
};

class ReceiptLinkedList{
    private:
        ReceiptNode* head;
        int size;
    
    public:
        ReceiptLinkedList(){
            head = NULL;
            size = 0;
        }
        
        bool isEmpty(){ 
            return head == NULL;
        }
    
        void insertAtEnd(Receipt& receipt){
            ReceiptNode* newNode = new ReceiptNode();
            newNode->SetData(receipt);
            if (isEmpty()){
                head = newNode;
                newNode->SetPrev(NULL);
                newNode->SetNext(NULL);
            }
			else{
                ReceiptNode* temp = head;
                while (temp->GetNext() != NULL) {
                    temp = temp->GetNext();
                }
                temp->SetNext(newNode);
                newNode->SetPrev(temp);
            }
            size++;
        }
    
        void removeNode(ReceiptNode* node){
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
    
        ReceiptNode* FindNodeById(string& id){
            ReceiptNode* temp = head;
            while (temp != NULL){
                if (temp->GetData().id==id){
                    return temp;
                }
                temp = temp->GetNext();
            }
            return NULL;
        } 
    
        ReceiptNode* FindByCustomerName(string& customerName){
            ReceiptNode* temp = head;
            while (temp != NULL){
                if (temp->GetData().customerName == customerName){
                    return temp;
                }
                temp = temp->GetNext();
            }
            return NULL;
        }
    
        bool isIdAvailable(string& id){
            return FindNodeById(id) == NULL;
        }
        
        void PrintAllReceipts(){
            if (isEmpty()){
                cout << "No receipt found!!" << endl;
                return;
            }
            ReceiptNode* temp = head;
            while(temp != NULL){
                static int i = 0;
                Receipt tempReceipt = temp->GetData();
                cout << " " << ++i << "\t" << tempReceipt.id << "\t" << tempReceipt.customerName 
                     << "\t" << tempReceipt.totalBillAmount << "\t" << tempReceipt.billAmountWithoutDis 
                     << "\t" << tempReceipt.customerPhoneNumber << "\t" << tempReceipt.date 
                     << "\t" << tempReceipt.loyaltyStatus << endl;
                temp = temp->GetNext();
            }
        }
        
        int getSize(){
            return size;
        }
        
        ReceiptNode* GetHead(){
			return head;
		}
		
		void SetHead(ReceiptNode* head){
			this->head=head;
		}
	
////////////////////// File Handaling /////////////////////////////
	
		void writeReceipts(){
			ofstream outFile("receipts.txt", ios::out);
			if (!outFile){
				cerr << "receipts.txt  could not be Opened for writing";
				pause();
				return;
			}
			ReceiptNode* tempReceipt=head;
			while(tempReceipt!=NULL){
				Receipt receipt=tempReceipt->GetData();
				outFile << "0 " <<receipt.id << "\t" << receipt.customerName << "\t" << receipt.customerPhoneNumber
					<< "\t" << receipt.loyaltyStatus << "\t" << receipt.date << "\t" << receipt.billAmountWithoutDis 
					<< "\t" << receipt.totalBillAmount << "\t";
				
				BuyingProductNode* tempProductNode=receipt.buyingProducts.GetHead();
			
				while(tempProductNode!=NULL){
					BuyingProduct tempProduct = tempProductNode->GetData();
					outFile << "1 " << tempProduct.id << "\t" << tempProduct.name << "\t" << tempProduct.price << "\t" << tempProduct.quantity << "\t";
					tempProductNode=tempProductNode->GetNext();
				}
				outFile << endl;
				tempReceipt=tempReceipt->GetNext();
			}
		}
	
	    // loading Receipts

		void loadReceipt(){
			ifstream inFile("receipts.txt", ios::in);
			if (!inFile){
				cerr << "receipts.txt  could not be Opened for Reading";
				pause();
				return;
			}
			int val;
			Receipt temp;
			bool isFirstPass = false;
			while (inFile >> val){
				if (val == 0){
					if (isFirstPass)
						insertAtEnd(temp);
					inFile >> temp.id >> temp.customerName >> temp.customerPhoneNumber >> temp.loyaltyStatus >> temp.date >> 
						temp.billAmountWithoutDis >> temp.totalBillAmount;
					temp.buyingProducts.SetHead(NULL);
					isFirstPass = true;
				}
				else{
					BuyingProduct tempProduct;
					inFile >> tempProduct.id >> tempProduct.name >> tempProduct.price >> tempProduct.quantity;
					temp.buyingProducts.insertAtEnd(tempProduct);
				}
			} 
			if (isFirstPass)
				insertAtEnd(temp);
			inFile.close();
		}
};

#endif
