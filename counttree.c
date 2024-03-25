#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} NODE;
NODE *create_bst(NODE *root)
{
    int i, n, num;
    NODE *newnode, *temp, *parent;
    printf("Enter how many nodes you want to create\n");
    scanf("%d", &n);
    printf("Enter data in node\n");
    for (i = 0; i < n; i++)
    {
        newnode = (NODE *)malloc(sizeof(NODE));
        scanf("%d", &num);
        newnode->data = num;
        newnode->left = newnode->right = NULL;
        if (root == NULL)
        {
            root = newnode;
            continue;
        }
        temp = root;
        while (temp != NULL)
        {
            parent = temp;
            if (num < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        if (num < parent->data)
            parent->left = newnode;
        else
            parent->right = newnode;
    }
    return root;
}
int count(NODE *root)
{
    static int cnt = 0;
    NODE *temp = root;
    if (temp != NULL)
    {
        cnt++;
        count(temp->left);
        count(temp->right);
    }
    return cnt;
}
int countLeaf(NODE *root)
{
    static int leaf = 0;
    NODE *temp = root;
    if (temp != NULL)
    {
        if ((temp->left == NULL) && (temp->right == NULL))
            leaf++;
        countLeaf(temp->left);
        countLeaf(temp->right);
    }
    return leaf;
}
void main()
{
    NODE *root = NULL;
    int ch, n, ln;
    do
    {
        printf("1. Create\n2. Total Nodes\n3. Total Leaf Nodes\n4. Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            root = create_bst(root);
            break;
        case 2:
            n = count(root);
            printf("Total Nodes = %d\n", n);
            break;
        case 3:
            ln = countLeaf(root);
            printf("Total Leaf Nodes = %d\n", ln);
            break;
        case 4:
            exit(0);
        }
    } while (ch != 4);
}