struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


//PreOrder
void preorder(struct TreeNode* node, int** result, int *returnSize, int* size) {
    if (node) {
        (*result)[(*returnSize)++] = node->val;
        if ((*returnSize) == *size) {
            (*size) *= 2;
            (*result) = (int*)realloc(*result, (*size) * sizeof(int));
        }
        preorder(node->left, result, returnSize, size);
        preorder(node->right, result, returnSize, size);
    }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* result = NULL;
    int size = 1;
    if (root != NULL) result = (int*)malloc(sizeof(int));
   
    preorder(root, &result, returnSize, &size);

    return result;
}


//InOrder
void inorder(struct TreeNode* node, int** result, int *returnSize, int* size) {
    if (node) { 
        inorder(node->left, result, returnSize, size);
        (*result)[(*returnSize)++] = node->val;
        if ((*returnSize) == *size) {
            (*size) *= 2;
            (*result) = (int*)realloc(*result, (*size) * sizeof(int));
        }
        inorder(node->right, result, returnSize, size);
    }
}


int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* result = NULL;
    int size = 1;
    if (root != NULL) result = (int*)malloc(sizeof(int));
   
    inorder(root, &result, returnSize, &size);

    return result;
}

//PostOrder
void postorder(struct TreeNode* node, int** result, int *returnSize, int* size) {
    if (node) { 
        postorder(node->left, result, returnSize, size);
        postorder(node->right, result, returnSize, size);
        (*result)[(*returnSize)++] = node->val;
        if ((*returnSize) == *size) {
            (*size) *= 2;
            (*result) = (int*)realloc(*result, (*size) * sizeof(int));
        }
    }
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* result = NULL;
    int size = 1;
    if (root != NULL) result = (int*)malloc(sizeof(int));
   
    postorder(root, &result, returnSize, &size);

    return result;
}

//LevelOrder
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 2000);
    int front = 0, rear = 0;

    queue[rear++] = root;

    int **result = (int**)malloc(sizeof(int*) * 2000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2000);
    int levelCount = 0;

    while (rear > front) {
        int levelSize = rear - front;
        result[levelCount] = (int*)malloc(sizeof(int) * levelSize);
        (*returnColumnSizes)[levelCount] = levelSize;

        for (int i = 0; i < levelSize; ++i) {
            
            struct TreeNode* node = queue[front++];
            result[levelCount][i] = node->val;

            if (node->left) {
                queue[rear++] = node->left;
            }

            if (node->right) {
                queue[rear++] = node->right;
            }

        }

        levelCount++;
    }

    free(queue);

    *returnSize = levelCount;
    return result;
}
