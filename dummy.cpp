// // Online C++ compiler to run C++ program online
// #include <iostream>
// using namespace std;
//   int lengthOfLastWord(string s) {
//         bool lastComplete=true;
//         bool firstLett=true;
//         bool lastLett=true;
//         int i=s.size()-1;
//         int ans=0;
//         while(lastLett && i>=0){
//             if(s[i]==' ' && firstLett){
//                 continue;
//                 }
//             else{
//                  firstLett=false;
//                 if(s[i]==' '){
//                     lastLett=false;
//                 }
//                 if(lastLett){

//                       ans++;
//                 }

//             }
//             i--;

//         }

//        return ans;
//     }
// int main() {
//   cout<<lengthOfLastWord("   fly me   to   the moon  ")<<endl;

//     return 0;
// }

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {

        if (root == NULL)
        {
            return 0;
        }
        // -101 for level completetion
        queue<pair<TreeNode *, int>> bfs;
        bfs.push({root, root->val});
        bfs.push({NULL, -102});
        int maxLen = 0;
        int length = 1;
        while (!bfs.empty())
        {

            auto it = bfs.front();
            bfs.pop();

            if (it.first == NULL && it.second == -102)
            {
                if (bfs.size() == 0)
                {
                    maxLen = max(length, maxLen);
                }
                else
                {
                    bfs.push({NULL, -102});
                    maxLen = max(length, maxLen);
                    length = 0;
                }
            }
            length++;

            else
            {
                if (it.first == NULL && it.second == -101)
                {
                    continue;
                }

                else if (it.first->left != NULL)
                {
                    bfs.push({it.first->left, it.first->left->val});
                }
                else if (it.first->left == NULL)
                {
                    bfs.push({it.first->left, -101});
                }
                else if (it.first->right != NULL)
                {
                    bfs.push({it.first->right, it.first->right->val});
                }
                else if (it.first->right == NULL)
                {
                    bfs.push({it.first->right, -101});
                }
            }
        }
    
    return maxLen;
  }
};