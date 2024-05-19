#include <stdio.h>
#include <stdlib.h>

struct bst
{
    int data;
    struct bst *left;
    struct bst *right;
};

void insert(struct bst **root, int num)
{
    struct bst *temp;
    temp = (struct bst *)malloc(sizeof(struct bst));
    temp->data = num;
    temp->left = NULL;
    temp->right = NULL;

    if (*root == NULL)
    {
        *root = temp;
    }
    else if (num < (*root)->data)
    {
        insert(&(*root)->left, num);
    }
    else if (num > (*root)->data)
    {
        insert(&(*root)->right, num);
    }
    else
    {
        printf("\nDuplicate Entry");
    }
}

void deleteNode(struct bst **root, int num)
{
    if (*root == NULL)
    {
        printf("\nDeletion Unsuccessfull");
        return;
    }

    if (num < (*root)->data)
    {
        deleteNode(&((*root)->left), num);
    }
    else if (num > (*root)->data)
    {
        deleteNode(&((*root)->right), num);
    }
    else
    {
        if ((*root)->left == NULL)
        {
            struct bst *temp = (*root)->right;
            free(*root);
            *root = temp;
            printf("\nDeletion Successfull");
        }
        else if ((*root)->right == NULL)
        {
            struct bst *temp = (*root)->left;
            free(*root);
            *root = temp;
            printf("\nDeletion Successfull");
        }
        else
        {
            struct bst *temp = (*root)->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }

            (*root)->data = temp->data;
            deleteNode(&((*root)->right), temp->data);
            printf("\nDeletion Successfull");
        }
    }
}

void search(struct bst *root, int num)
{
    if (root == NULL)
    {
        printf("Search was Unsuccessfull\n");
    }
    else if (num < (root)->data)
    {
        search((root)->left, num);
    }
    else if (num > (root)->data)
    {
        search((root)->right, num);
    }
    else
    {
        printf("Search was Successfull\n");
    }
}

void preOrder(struct bst *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("\t%d", (root)->data);
        preOrder((root)->left);
        preOrder((root)->right);
    }
}

void postOrder(struct bst *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        postOrder((root)->left);
        postOrder((root)->right);
        printf("\t%d", (root)->data);
    }
}

void inOrder(struct bst *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inOrder((root)->left);
        printf("\t%d", (root)->data);
        inOrder((root)->right);
    }
}

int main()
{
    struct bst *root;
    root = NULL;

    printf("\n1. Insert node in tree\n2. Delete node from tree\n3. Search node in tree\n4. Pre-Order Traversal\n5. In-Order Traversal\n6. Post-Order Traversal\n7.Exit\n");
    int num, ch;
    do
    {
        printf("\nEnter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the number to insert in the node: ");
            scanf("%d", &num);
            insert(&root, num);
            break;
        case 2:
            printf("\nEnter the number to delete in the node: ");
            scanf("%d", &num);
            deleteNode(&root, num);
            break;
        case 3:
            printf("\nEnter the number to search in the node: ");
            scanf("%d", &num);
            search(root, num);
            break;
        case 4:
            preOrder(root);
            break;
        case 5:
            inOrder(root);
            break;
        case 6:
            postOrder(root);
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("\nPlease enter appropriate number choice.");
        }
    } while (ch != 0);
    return 0;
}