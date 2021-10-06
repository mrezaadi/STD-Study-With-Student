#include <iostream>

using namespace std;

//Node Utama
struct Node{
    char label;
    Node *left, *right, *parent;
};

//Variable global
Node *root, *newNode;

bool isEmpty(){
    if (root == NULL){
        return true;
    } else {
        return false;
    }
}

void createNewTree(char label){
    if (isEmpty() == false){
        cout << "\nTree Sudah Dibuat" << endl;
    } else{
        root = new Node();
        root->label = label;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\nNode" << label << " dengan label " << label << " berhasil dibuat. " << label << " adalah Root" << endl;
    }
}

//Insert left, masukkan node sebagai anak kiri dari parent node
Node *insertLeft(char label, Node *parentNode){
    if (isEmpty() == true){
        cout << "Root belum dibuat, bua Root terlebih dahulu" << endl;
        return NULL;
    } else{
        if (parentNode->left != NULL){
            cout << "Sudah ada anak kiri, yaitu " << parentNode->left->label << endl;
            return NULL;
        } else{
            newNode = new Node();
            newNode->label = label;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->parent = parentNode;
            parentNode->left = newNode;

            cout << "\nNode" << label << " dengan label " << label << " telah dibuat sebagai anak kiri dari " << newNode->parent->label << endl;
            return newNode;
        }
    }
}

//Insert right, masukkan node sebagai anak kanan dari parent node
Node *insertRight(char label, Node *parentNode){
    if (isEmpty() == true){
        cout << "Root belum dibuat, buat Root terlebih dahulu" << endl;
        return NULL;
    } else{
        if (parentNode->right != NULL){
            cout << "Sudah ada anak kanan, yaitu " << parentNode->right->label << endl;
            return NULL;
        } else{
            newNode = new Node();
            newNode->label = label;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->parent = parentNode;
            parentNode->right = newNode;

            cout << "\nNode" << label << " dengan label " << label << " telah dibuat sebagai anak kanan dari " << newNode->parent->label << endl;
            return newNode;
        }
    }
}

//Mengubah label pada node yang dituju
void updateTree(char label, Node *node){
    if (isEmpty() == true){
        cout << "Root belum dibuat, buat Root terlebih dahulu" << endl;
    } else{
        if (!node) {
            cout << "Node yang diupdate tidak ada" << endl;
        } else{
            char temp = node->label;
            node->label = label;
            cout << "\n" << temp << " berhasil diubah menjadi " << node->label << endl;
        }
    }
}

//Hapus sebuah tree, pocedure utama
// void deleteTree(Node *node){ 
//     //Secara default, jika tidak diberikan paramaeter maka otomatis dari root nya
//     if (isEmpty() == true){
//         cout << "Root belum dibuat, bua Root terlebih dahulu" << endl;
//     } else{
//         if (node != NULL){
//             if (node != root){
//                 node->parent->right = NULL; //Menghapus saudaranya
//                 node->parent->left = NULL; //Menghapus saudaranya
//             }
//             //Rekursif sampai ada yang null
//             deleteTree(node->left);
//             deleteTree(node->right);
//             if (node == root){
//                 delete root;
//                 root = NULL;
//             } else{
//                 delete node;
//             }
//         }
//     }
// }

// //Menghapus semua sub dari Node yang ddiberikan
// void deleteSub(Node *node = root){ 
//     //Secara default, jika tidak diberikan paramaeter maka otomatis dari root nya
//     if (isEmpty() == true){
//         cout << "Root belum dibuat, bua Root terlebih dahulu" << endl;
//     } else{
//         if (node != NULL){
//             deleteTree(node->left);
//             deleteTree(node->right);
//             cout << "\nSubtree node " << node->label << "berhasil dihapus" << endl;
//         }
//     }
// }

//Mencetak data label pada node yang dituju
void retriveTree(Node *node){
    if (isEmpty() == true){
        cout << "Root belum dibuat, buat Root terlebih dahulu" << endl;
    } else{
        if (!node) {
            cout << "Node yang ditunjuk tidak ada" << endl;
        } else{
            cout << "\nData pada Node" << node->label << endl;
            cout << "Label : " << node->label << endl;
        }
    }
}   

//Mencetak semua identitas pada node yang dituju. Label, Root, Parent, Left Child, Right Child, Sibling
void findTree(Node *node){
    if (isEmpty() == true){
        cout << "Root belum dibuat, buat Root terlebih dahulu" << endl;
    } else{
        if (!node) {
            cout << "Node yang ditunjuk tidak ada" << endl;
        } else{
            cout << "\nData pada Node" << node->label << endl;
            cout << "Label \t\t: " << node->label << endl;
            cout << "Root \t\t: " << root->label << endl;
            //Cek parent
            if (node->parent != NULL){
                cout << "Parent \t\t: " << node->parent->label << endl;
            } else{
                cout << "Parent \t\t: Tidak punya " << endl; 
            }
            //Cek sibling
            if (node->parent != NULL && node->parent->left != node){
                cout << "Sibling \t: " << node->parent->left->label << endl;
            } else if(node->parent != NULL && node->parent->right != node){
                cout << "Sibling \t: " << node->parent->right->label << endl;
            } else{
                cout << "Sibling \t: Tidak punya " << endl;
            }
            //Cek left child
            if (node->left != NULL){
                cout << "Anak Kiri \t: " << node->left->label << endl;
            } else{
                cout << "Anak Kiri \t: Tidak punya " << endl; 
            }
            //Cek right child
            if (node->right != NULL){
                cout << "Anak Kanan \t: " << node->right->label << endl;  
            } else{
                cout << "Anak Kanan \t: Tidak punya " << endl; 
            }
        }
    }
}

//Transversal PreOrder
void transversePreOrder(Node *node = root){ 
    //Secara default, jika tidak diberikan paramaeter maka otomatis dari root nya
    if (isEmpty() == true){
        cout << "Root belum dibuat, bua Root terlebih dahulu" << endl;
    } else{
        if (node != NULL){
            cout << node->label << " ";
            transversePreOrder(node->left);
            transversePreOrder(node->right);
        }
    }
}

//Transversal InOrder
void transverseInOrder(Node *node = root){ 
    //Secara default, jika tidak diberikan paramaeter maka otomatis dari root nya
    if (isEmpty() == true){
        cout << "Root belum dibuat, bua Root terlebih dahulu" << endl;
    } else{
        if (node != NULL){
            transverseInOrder(node->left);
            cout << node->label << " ";
            transverseInOrder(node->right);
        }
    }
}

//Transversal PostOrder
void transversePostOrder(Node *node = root){ 
    //Secara default, jika tidak diberikan paramaeter maka otomatis dari root nya
    if (isEmpty() == true){
        cout << "Root belum dibuat, bua Root terlebih dahulu" << endl;
    } else{
        if (node != NULL){
            transversePostOrder(node->left);
            transversePostOrder(node->right);
            cout << node->label << " ";
        }
    }
}

int main(){
    Node *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ;

    //Node a sehagai root
    createNewTree('A'); //Parameter1 sebagai root

    //Insert left dari root
    cout << "\n<<<<<<<<<< INSERT LEFT <<<<<<<<<<" << endl;
    nodeB = insertLeft('B', root); 
    cout << "Anak kiri dari Root adalah " << root->left->label << endl;
    nodeC = insertLeft('C', root); 

    
    //Insert right dari troot
    cout << "\n<<<<<<<<<< INSERT RIGHT <<<<<<<<<<" << endl;
    nodeC = insertRight('C', root);
    cout << "Anak kanan dari Root adalah " << root->right->label << endl;
    nodeD = insertRight('D', root); 

    cout << "\n<<<<<<<<<< MASUKKAN SEMUA TREE <<<<<<<<<<" << endl;
    nodeD = insertLeft('D', nodeB);
    nodeE = insertRight('E', nodeB);
    nodeF = insertLeft('F', nodeC);
    nodeG = insertLeft('G', nodeE);
    nodeH = insertRight('H', nodeE);
    nodeI = insertLeft('I', nodeG);
    nodeJ = insertRight('J', nodeG);

    cout << "\n<<<<<<<<<< UPDATE TREE <<<<<<<<<<" << endl;
    updateTree('X', root);

    cout << "\n<<<<<<<<<< RETRIVE TREE <<<<<<<<<<" << endl;
    retriveTree(nodeB);

    cout << "\n<<<<<<<<<< FIND TREE <<<<<<<<<<" << endl;
    findTree(root);
    findTree(nodeC);
    findTree(nodeH);
    findTree(nodeI);

    cout << "\n<<<<<<<<<< TRANSVERSE PREORDER <<<<<<<<<<" << endl;
    cout << "\nTransverse dari Root:" << endl;
    transversePreOrder();
    cout << "\nTransverse dari NodeE:" << endl;
    transversePreOrder(nodeE);

    cout << "\n<<<<<<<<<< TRANSVERSE INORDER <<<<<<<<<<" << endl;
    cout << "\nTransverse dari Root:" << endl;
    transverseInOrder();
    cout << "\nTransverse dari NodeE:" << endl;
    transverseInOrder(nodeE);

    cout << "\n<<<<<<<<<< TRANSVERSE POSTORDER <<<<<<<<<<" << endl;
    cout << "\nTransverse dari Root:" << endl;
    transversePostOrder();
    cout << "\nTransverse dari NodeE:" << endl;
    transversePostOrder(nodeE);
    cout << "\n<<<<<<<<<< DELETE SUB <<<<<<<<<<" << endl;
    // deleteSub(nodeE);
    cout << "\nTransverse dari Root:" << endl;
    transverseInOrder();

}


