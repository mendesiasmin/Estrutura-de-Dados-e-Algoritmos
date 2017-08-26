/*

  Universidade de Brasíla - Campus Gama 2017/02
  Estrutura de Dados e Algortimos 2 - Mauricio Serrano

  Lista 01 - Questão 05: Travessias em arvores binarias

  Iasmin Santos Mendes, 14/0041940
  Francisco Wallacy Coutinho Braz, 15/0059329

*/

#include <iostream>

#define SMALLER 0
#define LARGER 1

using namespace std;

typedef struct _node {
  int key;
  struct _node *right;
  struct _node *left;
} node;


node *create_node(int key);
void insert(node **root, int key);
void in_order(node *root);
void pre_order(node *root);
void post_order(node *root);
int compare(node *root, int key);

int main() {

  node * root = NULL;
  int aux;

  while(scanf("%d", &aux) != EOF){
    insert(&root, aux);
  }

  if (system("clear"));
  cout << "Binary Tree Program" << endl << endl;
  cout << "In Order" << endl;
  in_order(root);

  cout << "\n\n\nPre Order" << endl;
  pre_order(root);

  cout << "\n\n\nPost Order" << endl;
  post_order(root);
  cout << endl << endl;

  free(root);

  return 0;
}

void insert(node **root, int key) {

  if ((*root) == NULL) {
    (*root) = create_node(key);
  }
  else if (compare(*root, key) == SMALLER) {
    if ((*root)->left == NULL) {
      (*root)->left = create_node(key);
    } else {
      insert(&(*root)->left, key);
    }
  } else {
    if ((*root)->right == NULL) {
      (*root)->right = create_node(key);
    } else {
      insert(&(*root)->right, key);
    }
  }
}

node *create_node(int key) {
  node * root = (node*) malloc(sizeof(node));
  root->key = key;
  root->left = NULL;
  root->right = NULL;
  return root;
}

void in_order(node* root) {

  if(root == NULL){
    return;
  }

  in_order(root->left);
  cout << root->key << " ";
  in_order(root->right);
}

void pre_order(node* root) {

  if(root == NULL){
    return;
  }

  cout << root->key << " ";
  pre_order(root->left);
  pre_order(root->right);
}

void post_order(node* root) {

  if(root == NULL){
    return;
  }

  post_order(root->left);
  post_order(root->right);
  cout << root->key << " ";
}

int compare(node *root, int key) {
  return root->key > key ? SMALLER : LARGER;
}
