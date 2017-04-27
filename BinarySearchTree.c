#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
}tree;

tree* insert(tree*, int);
void preOrder(tree*);
void inOrder(tree*);
void postOrder(tree*);
tree* maximumElement(tree*);
tree* minimumElement(tree*);
int sizeOfTree(tree*);
int heightOfTree(tree*);
int numExternalNodes(tree*);
tree* delete (tree*, int);

void main()
{
    tree *treeRoot = NULL;
    tree *retTree;
    int input, value;

    while(1)
    {
        printf("1. Insert Element to a Tree.\n2. Pre-Order Display.\n3. In-Order Display.\n4. Post-Order Display.\n5. Maximum Element.\n6. Minimum Element.\n7. Size of the Tree.\n8. Height of the Tree.\n9. Number of External Nodes.\n");
        scanf("%d", &input);

        switch(input)
        {
            case(1):    printf("Enter the value you want to Insert: ");
                        scanf("%d", &value);
                        treeRoot = insert(treeRoot, value);
                        break;
            case(2):    preOrder(treeRoot);
                        printf("\n");
                        break;
            case(3):    inOrder(treeRoot);
                        printf("\n");
                        break;
            case(4):    postOrder(treeRoot);
                        printf("\n");
                        break;
            case(5):    retTree = maximumElement(treeRoot);
                        if(retTree)
                        {
                            printf("The Maximum Element of the tree is: %d.\n", retTree->data);
                        }
                        else
                        {
                            printf("Empty Tree.\n");
                        }
                        break;
            case(6):    retTree = minimumElement(treeRoot);
                        if(retTree)
                        {
                            printf("The Minimum Element of the tree is: %d.\n", retTree->data);
                        }
                        else
                        {
                            printf("Empty Tree.\n");
                        }
                        break;
            case(7):    printf("The Number of Nodes in the Tree are: %d.\n", sizeOfTree(treeRoot));
                        break;
            case(8):    printf("The Height of the Tree is: %d.\n", heightOfTree(treeRoot));
                        break;
            case(9):    printf("The Number of External Nodes in the Tree is: %d.\n", numExternalNodes(treeRoot));
                        break;
        }
    }
}

tree* insert(tree *node, int value)
{
    if (node == NULL)
    {
        tree *link = (tree*)malloc(sizeof(tree));
        link->data = value;
        link->left = link->right = NULL;

        node = link;
    }

    else if (node->data > value)
    {
        node->left = insert(node->left, value);
    }

    else if (node->data < value)
    {
        node->right = insert(node->right, value);
    }

    return node;
}

void preOrder(tree *node)
{
    if (node)
    {
        printf("%d ", node->data);
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(tree *node)
{
    if (node)
    {
        inOrder(node->left);
        printf("%d ", node->data);
        inOrder(node->right);
    }
}

void postOrder(tree *node)
{
    if (node)
    {
        postOrder(node->left);
        postOrder(node->right);
        printf("%d ", node->data);
    }
}

tree* maximumElement(tree *node)
{
    if (node == NULL)
    {
        return NULL;
    }

    else if (node->right != NULL)
    {
        return maximumElement(node->right);
    }

    else if (node->right == NULL)
    {
        return (node);
    }
}

tree* minimumElement(tree *node)
{
    if (node == NULL)
    {
        return NULL;
    }

    else if (node->left != NULL)
    {
        return minimumElement(node->left);
    }

    else if (node->left == NULL)
    {
        return (node);
    }
}

int sizeOfTree(tree *node)
{
    if (node == NULL)
    {
        return 0;
    }

    else
    {
        return (sizeOfTree(node->left) + sizeOfTree(node->right) + 1);
    }
}

int heightOfTree(tree *node)
{
    if (node == NULL)
    {
        return -1;
    }

    int leftHeight = heightOfTree(node->left);
    int rightHeight = heightOfTree(node->right);

    if (leftHeight > rightHeight)
    {
        return (leftHeight + 1);
    }

    else
    {
        return (rightHeight + 1);
    }
}

tree* lowestCommonAncestor(tree *node, int val1, int val2)
{
    if ((node->data > val1) && (node->data > val2))
    {
        return (lowestCommonAncestor(node->left, val1, val2));
    }

    else if((node->data < val1) && (node->data < val2))
    {
        return (lowestCommonAncestor(node->right, val1, val2));
    }

    else
    {
        return node;
    }
}

int numExternalNodes(tree *node)
{
    if (node == NULL)
    {
        return 0;
    }

    else if ((node->left == NULL) && (node->right == NULL))
    {
        return 1;
    }

    else
    {
        return (numExternalNodes(node->left) + numExternalNodes(node->right));
    }
}

tree* delete (tree *root, int value)
{
    if (root == NULL)
    {
        printf("Value not found.\n");
        return;
    }

    else if (root->data > value)
    {
        root->left = delete(root->left, value);
    }

    else if (root->data < value)
    {
        root->right = delete(root->right, value);
    }

    else
    {
        if ((root->left) && (root->right))
        {
            int val = maximumElement(root->left);
            root->data = val;
            root->left = delete(root, val);
        }

        else if (root->left == NULL)
        {
            root = root->right;
        }

        else if (root->right == NULL)
        {
            root = root->left;
        }
    }

    return root;
}
