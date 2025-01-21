/**
* Title: Binary Search Trees
* Author : Berke Kuzey Ardıç
* ID : 22103340
* Section : 001
* Homework : 01
*/
#include "BST.h"

BST::BST(int keys[], int size){
    root = nullptr;
    for(int i=0;i<size;i++){
        insertItem(root,keys[i],false);
    }
    cout<<"BST with size "<<size<<" is created."<<endl;
}

BST::~BST(){
    destroyTree(root);
}

void BST::insertKey(int key){
    insertItem(root,key,true);
}

void BST::deleteKey(int key){
     deleteItem(root,key,true);
}

void BST::displayInorder(){
    cout<<"Inorder display is:";
    inorder(root);
}

void BST::findFullBTLevel(){
    cout<<"Full binary tree level is: ";
    int treeLevel = findFullBTLevel(root);
    cout<<treeLevel<<endl;

}

void BST::lowestCommonAncestor(int A, int B){
    TreeNode* temp = lowestCommonAncestorFinder(A,B,root);
    cout<<"Lowest common ancestor of "<<A<<" and "<<B <<" is: "<<temp->item<<endl;
}

void BST::maximumSumPath(){
    Stack <TreeNode*> nodes;
    Stack < Stack<TreeNode*> > paths;
    int maxSum =0;

    maximumSumPath(root,0,maxSum,nodes,paths);
    Stack<TreeNode*> maxPath = paths.top();   
    Stack<TreeNode*> printingStack;

    cout<<"Maximum sum path is: ";

    while(maxPath.size()!=0){
        TreeNode* temp = maxPath.top();
        printingStack.push(temp);
        maxPath.pop();
    }

    while(printingStack.size()!=0){
        if(printingStack.size()==1){
            TreeNode* temp = printingStack.top();
            cout<<temp->item<<endl;
            printingStack.pop();
        }else{
            TreeNode* temp = printingStack.top();
            cout<<temp->item<<", ";
            printingStack.pop();
        }
    }




}

void BST::maximumWidth(){
    string maxLevel = "";
    if(root==nullptr){
        cout<<"Maximum level is: "<<maxLevel<<endl;
        return;
    }
    Queue <TreeNode*> q ;
    q.push(root);
    int maxWidth = q.size();
    TreeNode* aqw = q.front();
    int currentVal = aqw->item;
    maxLevel += to_string(currentVal);
    

    while(q.size()!=0){

    int qSize = q.size();

    while(qSize){
       TreeNode* temp = q.front();
       q.pop();
       if(temp->leftChildPtr!=nullptr)
       q.push(temp->leftChildPtr);
       if(temp->rightChildPtr!=nullptr)
       q.push(temp->rightChildPtr);  
       qSize--;
    }
    if(q.size()>maxWidth){
        maxWidth = q.size();
        maxLevel = "";
        Queue <TreeNode*> a = q ;
        while(a.size()!=0){
            if(a.size()==1){
                TreeNode* temp = a.front();
                int currentVal = temp->item;
                maxLevel += to_string(currentVal);
                a.pop();
            }else{
                TreeNode* temp = a.front();
                int currentVal = temp->item;
                maxLevel += to_string(currentVal)+", ";
                a.pop();
            }
          
        }
    }
    }
            cout<<"Maximum level is: "<<maxLevel<<endl;



}


void BST::pathFromAtoB(int A, int B){
    if(A==B){
        cout<<"Path from "<<A<<" to "<<B<<" is: "<<A<<endl;
        return;
    }
    
    TreeNode* temp = lowestCommonAncestorFinder(A,B,root);
    Stack<TreeNode*> aToAncestor;
    Stack<TreeNode*> bToAncestor;
    findPathFromAtoB(A,temp,aToAncestor);
    findPathFromAtoB(B,temp, bToAncestor);
    Stack<TreeNode*> bStackForPrinting;

    while(bToAncestor.size()>1){
        TreeNode* temp = bToAncestor.top();
        bStackForPrinting.push(temp);
        bToAncestor.pop();
    }

    cout<<"Path from "<<A<<" to "<<B<<" is: ";


    while(aToAncestor.size()!=0){
        if(aToAncestor.size()==1&&bStackForPrinting.size()==0){
            TreeNode* temp = aToAncestor.top();
            cout<<temp->item<<endl;
            aToAncestor.pop();
        }else{
            TreeNode* temp = aToAncestor.top();
            cout<<temp->item<<", ";
            aToAncestor.pop();
        }
        
    }

    while(bStackForPrinting.size()!=0){
         if(bStackForPrinting.size()==1){
            TreeNode* temp = bStackForPrinting.top();
            cout<<temp->item<<endl;
            bStackForPrinting.pop();
        }else{
            TreeNode* temp = bStackForPrinting.top();
            cout<<temp->item<<", ";
            bStackForPrinting.pop();
        }
    }

}

int BST::heightOfThetree(){

 return findHeight(root);

}

int BST::findHeight(TreeNode* treePtr){
    if(treePtr==nullptr){
        return 0;
    }else{
        if(findHeight(treePtr->leftChildPtr)>findHeight(treePtr->rightChildPtr)){
                return 1+ findHeight(treePtr->leftChildPtr);
        }else{
                return 1+ findHeight(treePtr->rightChildPtr);
        }
    }
}

    void BST::insertKeyWithoutPrint(int key){
        insertItem(root,key,false);
    }



void BST::findPathFromAtoB(int A, TreeNode* treePtr, Stack<TreeNode*>& nodes){
            nodes.push(treePtr);
            if(A<treePtr->item){
                findPathFromAtoB(A,treePtr->leftChildPtr,nodes);
            }else if(A>treePtr->item){
                findPathFromAtoB(A,treePtr->rightChildPtr,nodes);
            }else{
                return;
            }
}

void BST::insertItem(TreeNode*& treePtr, int itemKey,bool org){

    if(treePtr==nullptr){
        treePtr = new TreeNode(itemKey,nullptr,nullptr);
        if(org)
        cout<<"Key "<<itemKey<<" is added."<<endl;
    }else if(itemKey<treePtr->item){
        insertItem(treePtr->leftChildPtr,itemKey,org);
    }else if(itemKey>treePtr->item){
        insertItem(treePtr->rightChildPtr,itemKey,org);
    }else{
        if(org)
        cout<<"Key "<<itemKey<<" is not added. It exists!"<<endl;
    }

}

void BST::deleteItem(TreeNode*& treePtr, int itemKey, bool org){


    if(treePtr==nullptr){
        cout<<"Key "<<itemKey<<" is not deleted. It does not exist!"<<endl;
    }else if(itemKey<treePtr->item){
        deleteItem(treePtr->leftChildPtr,itemKey, org);
    }else if(itemKey>treePtr->item){
        deleteItem(treePtr->rightChildPtr,itemKey, org);
    }else{
        if(treePtr->leftChildPtr==nullptr&&treePtr->rightChildPtr==nullptr){
            delete treePtr;
            treePtr = nullptr;
            if(org)
            cout<<"Key "<<itemKey<<" is deleted."<<endl;
        }else if(treePtr->leftChildPtr==nullptr&&treePtr->rightChildPtr!=nullptr){
            TreeNode* temp = treePtr;
            treePtr = treePtr->rightChildPtr;
            delete temp;
            if(org)
            cout<<"Key "<<itemKey<<" is deleted."<<endl;
        }else if(treePtr->leftChildPtr!=nullptr&&treePtr->rightChildPtr==nullptr){
            TreeNode* temp = treePtr;
            treePtr = treePtr->leftChildPtr;
            delete temp;
            if(org)
            cout<<"Key "<<itemKey<<" is deleted."<<endl;
        }else{
            int smallest = findSmallestElement(treePtr->rightChildPtr);
            treePtr->item = smallest;
            cout<<"Key "<<itemKey<<" is deleted."<<endl;
            org = false;
            deleteItem(treePtr->rightChildPtr,smallest,org);
        }

    }

}


TreeNode* BST::lowestCommonAncestorFinder(int A, int B, TreeNode* treePtr){
        if(A<treePtr->item&&B<treePtr->item){
        return lowestCommonAncestorFinder(A,B,treePtr->leftChildPtr);
        }else if(A>treePtr->item&&B>treePtr->item){
        return lowestCommonAncestorFinder(A,B,treePtr->rightChildPtr);}
        else{
        return treePtr;
       }
}


void BST::maximumSumPath(TreeNode* treePtr, int sum, int& maxSum, Stack<TreeNode*>& nodes, Stack< Stack<TreeNode*> >& paths){
    if(treePtr){
        sum += treePtr->item;
        nodes.push(treePtr);
        if(treePtr->leftChildPtr==nullptr&&treePtr->rightChildPtr==nullptr){
            if(sum>maxSum){
                maxSum = sum;
                paths.push(nodes);
            }
        }
        maximumSumPath(treePtr->leftChildPtr,sum,maxSum,nodes,paths);
        maximumSumPath(treePtr->rightChildPtr,sum,maxSum,nodes,paths);

        nodes.pop();
    }else{
        return;
    }
}


int BST::findFullBTLevel(TreeNode* treePtr){
    if(treePtr->leftChildPtr!=nullptr&&treePtr->rightChildPtr!=nullptr){
   
   
    if(findFullBTLevel(treePtr->leftChildPtr)>
    findFullBTLevel(treePtr->rightChildPtr)){  
        return findFullBTLevel(treePtr->rightChildPtr)+1;
    }else{
        return findFullBTLevel(treePtr->leftChildPtr)+1;
    }
    
    }else{
                return 1;
    }
    }



void BST::destroyTree(TreeNode*& treePtr){
if (treePtr != nullptr){ 
    destroyTree(treePtr->leftChildPtr); 
    destroyTree(treePtr->rightChildPtr); 
    delete treePtr;
    treePtr = nullptr;
}
}

void BST:: inorder(TreeNode* treePtr){
    if(treePtr!=nullptr){
        inorder(treePtr->leftChildPtr);
        if(treePtr->item!=findBiggestElement()){
            cout<<" "<<treePtr->item<<",";
        }else{
            cout<<" "<<treePtr->item<<endl;
        }
        inorder(treePtr->rightChildPtr);
    }
}

int BST:: findBiggestElement(){
    TreeNode* treePtr = root;
    int biggest = treePtr->item;
    while(treePtr!=nullptr){
        biggest = treePtr->item;
        treePtr = treePtr->rightChildPtr;
    }
    return biggest;
}

int BST:: findSmallestElement(TreeNode* treePtr){
    while(treePtr->leftChildPtr!=nullptr){
        treePtr = treePtr->leftChildPtr;
    }
        int smallest = treePtr->item;

    return smallest;
}





