/**
 * File processing, 2020
 * AVL.cpp
 * implementation of AVL tree
 */

#include <stdio.h>

/**
 * Node represents a single node in AVL tree.
 */
typedef struct Node {
  int         key, bf;
  struct Node *left, *right;
} Node;

typedef Node *Tree;

/**
 * getNode returns a new node.
 * @return a new node
 */
Node *getNode() {
    Node *temp = new Node();
    temp->key = 0;
    temp->bf = 0;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int height(Node *T) {
  return (T == NULL) ? 0 : (height(T->left) >= height(T->right)) ? 1+height(T->left) : 1+height(T->right);
}

int noNodes(Node *T) {
  return (T == NULL) ? 0 : noNodes(T->left) + noNodes(T->right);
}

Node *maxNode(Node *T) {
    return (T->right == NULL) ? T : maxNode(T->right);
}

Node *minNode(Node *T) {
    return (T->left == NULL) ? T : minNode(T->left);
}


/**
 * updateBF updates balancing factors of nodes in T
 * and finds the unbalanced node nearest to y.
 * @param T: an AVL tree
 * @param y: the inserted/deleted node
 * @param x: the unbalanced node nearest to y
 * @param P: parent node of x
 */
void updateBF(Tree *T, Node *y, Node **x, Node **P) {
  Node *p = *T;
  Node *q = NULL;

  while (p != y->left && p != y->right) {
    p->bf = height(p->left) - height(p->right);

    if (p->bf > 1 || p->bf < -1) {
      *x = p;
      *P = q;
    }
    
    q = p;

    if (y->key < p->key) p = p->left;
    else p = p->right;
  }

}

/**
 * rotateLL implements LL rotation in subtree rooted with x.
 * @param T: an AVL tree
 * @param x: root node of subtree
 * @param P: parent node of x
 */
void rotateLL(Tree *T, Node *x, Node *P) {
  Node *x_left = x->left;
  x->left = x_left->right;
  x_left->right = x;

  // root 노드 일 때
  if (P == NULL) *T = x_left;
  // root 노드가 아닐 때
  else if (P->left == x) P->left = x_left;
  else P->right = x_left;

  // 이중 포인터 NULL -> 사용안함
  // T부터 x까지 bf 업데이트
  updateBF(T, x, NULL, NULL);
}

/**
 * rotateRR implements RR rotation in subtree rooted with x.
 * @param T: an AVL tree
 * @param x: root node of subtree
 * @param P: parent node of x
 */
void rotateRR(Tree *T, Node *x, Node *P) {
  Node *x_right = x->right;
  x->right = x_right->left;
  x_right->left = x;

  // root 노드 일 때
  if (P == NULL) *T = x_right;
  // root 노드가 아닐 때
  else if (P->left == x) P->left = x_right;
  else P->right = x_right;

  // 이중 포인터 NULL -> 사용안함
  // T부터 x까지 bf 업데이트
  updateBF(T, x, NULL, NULL);
}

/**
 * rotateLR implements LR rotation in subtree rooted with x.
 * @param T: an AVL tree
 * @param x: root node of subtree
 * @param P: parent node of x
 */
void rotateLR(Tree *T, Node *x, Node *P) {
  Node *x_left = x->left;
  Node *x_left_right = x_left->right;
       
  // 부분RR
  x_left->right = x_left_right->left;
  x->left = x_left_right->right;

  // LL
  x_left_right->left = x_left;
  x_left_right->right = x;

  // root 노드 일 때
  if (P == NULL) *T = x_left_right;
  // root 노드가 아닐 때
  else if (P->left == x) P->left = x_left_right;
  else P->right = x_left_right;

  // 이중 포인터 NULL -> 사용안함
  // T부터 x까지 bf 업데이트
  updateBF(T, x, NULL, NULL);
  // T부터 x까지의 범위에 속하지 않으므로 x_left 노드 하나만 bf 재배치
  updateBF(&x_left, x_left, NULL, NULL);
}

/**
 * rotateRL implements RL rotation in subtree rooted with x.
 * @param T: an AVL tree
 * @param x: root node of subtree
 * @param P: parent node of x
 */
void rotateRL(Tree *T, Node *x, Node *P) {
  Node *x_right = x->right;
  Node *x_right_left = x_right->left;

  // 부분LL
  x->right = x_right_left->left;
  x_right->left = x_right_left->right;

  // RR
  x_right_left->left = x;
  x_right_left->right = x_right;

  // root 노드 일 때
  if (P == NULL) *T = x_right_left;
  // root 노드가 아닐 때
  else if (P->left == x) P->left = x_right_left;
  else P->right = x_right_left;

  // 이중 포인터 NULL -> 사용안함
  // T부터 x까지 bf 업데이트
  updateBF(T, x, NULL, NULL);
  // T부터 x까지의 범위에 속하지 않으므로 x_right 노드 하나만 bf 재배치
  updateBF(&x_right, x_right, NULL, NULL);
}

/**
 * insertBST inserts newKey into T
 * and returns the inserted node.
 * @param T: a binary search tree
 * @param newKey: a key to insert
 * @return the inserted node
 */
Node *insertBST(Tree *T, int newKey) {
  Node *q = NULL;
  Node *p = *T;

  // 삽입 할 위치 찾기
  while (p != NULL) {
    if (newKey == p->key) break;
      q = p;
      if (newKey < p->key) p = p->left;
      else p = p -> right;
  }

  Node *newNode = getNode();
  newNode -> key = newKey;

  if (*T == NULL) *T = newNode;
  else if (newKey < q->key) q->left = newNode;
  else q->right = newNode;

  return newNode;
}

/**
 * insertAVL inserts newKey into T.
 * @param T: an AVL tree
 * @param newKey: a key to insert
 */
void insertAVL(Tree *T, int newKey) {
  /**
   * print "NO" if not rotates
   * print "LL" if rotates LL
   * print "RR" if rotates RR
   * print "LR" if rotates LR
   * print "RL" if rotates RL
   */
  Node *prb = NULL;
  Node *prb_parent = NULL;

  updateBF(T, insertBST(T, newKey), &prb, &prb_parent);

  if (prb != NULL) {
    if (prb->bf > 1) {
      if (prb->left->bf < 0) {
         rotateLR(T, prb, prb_parent);
         printf("LR"); 
      }
      else {
        rotateLL(T, prb, prb_parent);
        printf("LL");
      }
    }
  else {
      if (prb->right->bf > 0) { 
        rotateRL(T, prb, prb_parent);
        printf("RL"); 
      }
      else { 
        rotateRR(T, prb, prb_parent);
        printf("RR");
      }
    }
  }
  else {
    printf("NO");
  }
}

/**
 * deleteBST deletes deleteKey from T
 * and returns the parent node of the deleted node.
 * @param T: a binary search tree
 * @param deleteKey: a key to delete
 * @return the parent node of the deleted node
 */
Node *deleteBST(Tree *T, int deleteKey) {
  Node *p = *T;
  Node *q = NULL;

  // 삭제 할 위치 찾기
  while (p != NULL && p->key != deleteKey)
  {
    q = p;
    if ( p->key > deleteKey) p = p->left;
    else p = p->right;
  }

  // child가 한 개
  if ( p->left == NULL || p->right == NULL ) {

    // 왼쪽 child 존재
    if (p->left != NULL) {
      if (q == NULL) *T = (*T)->left;
      else if (q->left == p) q->left = p->left;
      else q->right = p->left;
    } 
    // 오른쪽 child 존재
    else {
      if (q == NULL) *T = (*T)->right;
      else if (q -> left == p) q->left = p->right;
      else q->right = p->right;
    }

    delete p;
    if (q) { return q;}
  }
  // child가 두 개
  else {
        Node *temp;
        // false = LEFT, true = RIGHT
        bool flag;
        if ( height(p->left) > height(p->right) ) {
            temp = maxNode(p->left);
            flag = false;
        }
        else if ( height(p->left) < height(p->right) ) {
            temp = minNode(p->right);
            flag = true;
        }
        else {
            if ( noNodes(p->left) >= noNodes(p->right) ) {
                temp = maxNode(p->left);
                flag = false;
            }
            else {
                temp = minNode(p->right);
                flag = true;
            }
        }

        p->key = temp->key;

        if(flag == false) deleteBST(&(p->left), temp->key);
        else deleteBST(&(p->right), temp->key);
  }

  return p;
}

/**
 * deleteAVL deletes deleteKey from T.
 * @param T: an AVL tree
 * @param deleteKey: a key to delete
 */
void deleteAVL(Tree *T, int deleteKey) {
  /**
   * print "NO" if not rotates
   * print "LL" if rotates LL
   * print "RR" if rotates RR
   * print "LR" if rotates LR
   * print "RL" if rotates RL
   */

  Node *prb = NULL;
  Node *prb_parent = NULL;

  updateBF(T, deleteBST(T, deleteKey), &prb, &prb_parent);

  if (prb != NULL) {
    if (prb->bf > 1) {
      if (prb->left->bf < 0) {
         rotateLR(T, prb, prb_parent);
         printf("LR"); 
      }
      else {
        rotateLL(T, prb, prb_parent);
        printf("LL");
      }
    }
  else {
      if (prb->right->bf > 0) { 
        rotateRL(T, prb, prb_parent);
        printf("RL"); 
      }
      else { 
        rotateRR(T, prb, prb_parent);
        printf("RR");
      }
    }
  }
  else {
    printf("NO");
  }
}

/**
 * inorderAVL implements inorder traversal in T.
 * @param T: an AVL tree
 */
void inorderAVL(Tree T) {
  if (T) {
      inorderAVL(T->left);
      printf("%d ", T->key);
      inorderAVL(T->right);
   }
}

int main() {
  /* Do not modify the code below */

  const int testcase[] = { 40, 11, 77, 33, 20, 90, 99, 70, 88, 80, 66, 10, 22, 30, 44, 55, 50, 60, 25, 49 };


  Tree T = NULL;

  // insertion
  for (int i=0; i<20; i++) { printf("%d ", testcase[i]); insertAVL(&T, testcase[i]); printf(" : "); inorderAVL(T); printf("\n"); }

  //  deletion
  for (int i=0; i<20; i++) { printf("%d ", testcase[i]); deleteAVL(&T, testcase[i]); printf(" : "); inorderAVL(T); printf("\n"); }

  // T = NULL;

  // reinsertion
  for (int i=0; i<20; i++) { printf("%d ", testcase[i]); insertAVL(&T, testcase[i]); printf(" : "); inorderAVL(T); printf("\n"); }

  //  redeletion
  for (int i=19; 0<=i; i--) { printf("%d ", testcase[i]); deleteAVL(&T, testcase[i]); printf(" : "); inorderAVL(T); printf("\n"); }
}

