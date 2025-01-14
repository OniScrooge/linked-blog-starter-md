# Summary

# Related
Prev - [[COSC Chapter 21.10 Iterators for BST]]

Next - [[COSC Chapter Summary 21]]
# Content
## Key Point

Huffman coding compresses data by using fewer bits to encode characters that occur more frequently. The codes for the characters are constructed based on the occurrence of the characters in the text using a binary tree, called the Huffman coding tree.

This section serves two purposes. First, it introduces a technique for data compression. Second, it applies binary tree and heap to implement Huffman coding algorithm. 

Compressing data is a common task. There are many utilities available for compressing files. This section introduces Huffman coding, invented by David Huffman in 1952.

In ASCII, every character is encoded in 8 bits. If a text consists of 100 characters, it will take 800 bits to represent the text. The idea of Huffman coding is to use a fewer bits to encode frequently used characters in the text and more bits to encode less frequently used characters to reduce the overall size of the file. In Huffman coding, the characters’ codes are constructed based on the characters’ occurrence in the text using a binary tree, called the _Huffman coding_ tree. Suppose that the text is `Mississippi`. Its Huffman tree can be shown as in **Figure 21.17a**. The left and right edges of a node are assigned a value `0` and `1`, respectively. Each character is a leaf in the tree. The code for the character consists of the edge values in the path from the root to the leaf, as shown in **Figure 21.17b**. Since `i` and `s` appear more than `M` and `p` in the text, they are assigned shorter codes.

## Figure 21.17
![[Pasted image 20241202195744.png]]

The coding tree is also used for decoding a sequence of bits into characters. To do so, start with the first bit in the sequence and determine whether to go to the left or right branch of the tree’s root based on the bit value. Consider the next bit and continue to go down to the left or right branch based on the bit value. When you reach a leaf, you have found a character. The next bit in the stream is the first bit of the next character. For example, the stream `011001` is decoded to `sip`, with `01` matching `s`, `1` matching `i`, and `001` matching `p`.

Based on the coding scheme in **Figure 25.17**,
![[Pasted image 20241202195806.png]]

To construct a _Huffman coding tree_, use the following algorithm:
1.  Begin with a forest of trees. Each tree contains a node for a character. The weight of the node is the frequency of the character in the text.
2. Repeat the following action to combine trees until there is only one tree: Choose two trees with the smallest weight and create a new node as their parent. The weight of the new tree is the sum of the weight of the subtrees.
3. For each interior node, assign its left edge a value `0` and right edge a value `1`. All leaf nodes represent characters in the text.

Here is an example of building a coding tree for the text `Mississippi`. The frequency table for the characters is shown in **Figure 21.18b**. Initially, the forest contains single-node trees, as shown in **Figure 21.18a**. The trees are repeatedly combined to form large trees until only one tree is left, as shown in **Figure 21.18b–d**.

## Figure 21.18
![[jjep7fdu.bmp]]
![[2ikaz5n7.bmp]]
![[djl6k1z7.bmp]]
![[v461qzso.bmp]]

It is worth noting that no code is a prefix of another code. This property ensures that the streams can be decoded unambiguously.

### ALGORITHM DESIGN NOTE

The algorithm used here is an example of a _greedy algorithm_. A greedy algorithm is often used in solving optimization problems. The algorithm makes the choice that is optimal locally in the hope that this choice will lead to a globally optimal solution. In this case, the algorithm always chooses two trees with the smallest weight and creates a new node as their parent. This intuitive optimal local solution indeed leads to a final optimal solution for constructing a Huffman tree. 

As another example of a greedy algorithm, consider changing money into the fewest possible coins. A greedy algorithm would take the largest possible coin first. For example, for 98¢, you would use three quarters to make 75¢, additional two dimes to make 95¢, and additional three pennies to make the 98¢. The greedy algorithm finds an optimal solution for this problem. However, a greedy algorithm is not always going to find the optimal result; see the bin packing problem in **Programming Exercise 18.16**.

**LiveExample 21.5** gives a program that prompts the user to enter a string, displays the frequency table of the characters in the string, and displays the Huffman code for each character.

## **LiveExample 21.5 HuffmanCode.cpp**
```cpp
#include <iostream>
#include <string>
#include <iomanip>
#include "Heap.h"
using namespace std;

/** Get the frequency of the characters in counts */
void getCharacterFrequency(const string& text, vector<int>& counts)
{
  for (int i = 0; i < text.length(); i++)
    counts[static_cast<int>(text[i])]++; // Count the character in text
}

class Node
{
public:
  char element; // Stores the character for a leaf node
  int weight; // weight of the subtree rooted at this node
  Node* left; // Reference to the left subtree
  Node* right; // Reference to the right subtree
  string code = ""; // The code of this node from the root

  /** Create an empty node */
  Node()
  {
  }

  /** Create a node with the specified weight and character */
  Node(int weight, char element)
  {
    this->weight = weight;
    this->element = element;
  }
};

/** Define a Huffman coding tree */
class Tree
{
public:
  Node* root; // The root of the tree

  /** Create a tree with two subtrees */
  Tree(const Tree& t1, const Tree& t2) 
  {
    root = new Node();
    root->left = t1.root;
    root->right = t2.root;
    root->weight = t1.root->weight + t2.root->weight;
  }

  /** Create a tree containing a leaf node */
  Tree(int weight, char element) 
  {
    root = new Node(weight, element);
  }

  int compareTo(const Tree& t) 
  {
    if (root->weight < t.root->weight) // Purposely reverse the order
      return 1;
    else if (root->weight == t.root->weight)
      return 0;
    else
      return -1;
  }
};

bool operator<(Tree& t1, Tree& t2) // Used in the Heap class
{
  return t1.compareTo(t2) < 0;
}

bool operator>(Tree& t1, Tree& t2) // Used in the Heap class
{
  return t1.compareTo(t2) > 0;
}

/** Get a Huffman tree from the codes */
Tree getHuffmanTree(const vector<int>& counts) 
{
  // Create a heap to hold trees
  Heap<Tree>* heap = new Heap<Tree>(); // Defined in Listing 19.9
  for (int i = 0; i < counts.size(); i++) 
    if (counts[i] > 0)
      heap->add(Tree(counts[i], static_cast<char>(i))); // A leaf node tree

  while (heap->getSize() > 1)
  {
    Tree t1 = heap->remove(); // Remove the smallest weight tree
    Tree t2 = heap->remove(); // Remove the next smallest weight 
    heap->add(Tree(t1, t2)); // Combine two trees
  }

  return heap->remove(); // The final tree
}

/* Recursively get codes to the leaf node */
void assignCode(const Node& root, vector<string>& codes)
{
  if (root.left != nullptr) 
  {
    root.left->code = root.code + "0";
    assignCode(*(root.left), codes);

    root.right->code = root.code + "1";
    assignCode(*(root.right), codes);
  }
  else 
    codes[static_cast<int>(root.element)] = root.code;
}

/** Get Huffman codes for the characters
 * This method is called once after a Huffman tree is built
 */
vector<string> getCode(const Node* root) 
{
  vector<string> codes(128);
  assignCode(*root, codes);
  return codes;
}

int main()
{
  cout << "Enter a text: ";
  string text;
  getline(cin, text, '\n');

  vector<int> counts(128); // 128 ASCII characters
  getCharacterFrequency(text, counts); // Count frequency

  cout << setw(15) << "ASCII Code" << setw(15) << "Character"
       << setw(15) << "Frequency" << setw(15) << "Code" << endl;

  Tree tree = getHuffmanTree(counts); // Create a Huffman tree

  vector<string> codes = getCode(tree.root); // Get codes

  for (int i = 0; i < codes.size(); i++)
    if (counts[i] != 0) // static_cast<char>(i )is not in text if counts[i] is 0
      cout << setw(15) << i << setw(15) << static_cast<char>(i) <<
          setw(15) << counts[i] << setw(15) << codes[i] << endl;
  
  return 0;
}
```
```
command>cl HuffmanCode.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>HuffmanCode 
Enter a text: Welcome
     ASCII Code      Character      Frequency           Code
             87              W              1            110
             99              c              1            111
            101              e              2             10
            108              l              1            011
            109              m              1            010
            111              o              1             00

command>
```

The program prompts the user to enter a text string (lines 124–126) and counts the frequency of the characters in the text (line 129). The `getCharacterFrequency` function (lines 8–12) creates an array `counts` to count the occurrences of each of the 128 ASCII characters in the text. If a character appears in the text, its corresponding count is increased by `1` (line 11).

The program obtains a Huffman coding tree based on `counts` (line 134). The tree consists of linked nodes. The `Node` class is defined in lines 14–34. Each node consists of properties `element` (storing character), `weight` (storing weight of the subtree under this node), `left` (linking to the left subtree), `right` (linking to the right subtree), and `code` (storing the Huffman code for the character). The `Tree` class (lines 37–66) contains the `root` property. From the root, you can access all the nodes in the tree. The `operator<` and `operator>` functions (lines 68-76) are defined to compare the trees in the heap using the `compareTo` function. The `compareTo` function compares this `Tree` with another `Tree` (lines 57-65). The compare order is purposely reversed (lines 59–64) so that the smallest-weight tree is removed first from the heap of trees.

The `getHuffmanTree` function returns a Huffman coding tree. Initially, the single-node trees are created and added to the heap (lines 82–85). In each iteration of the `while` loop (lines 87–92), two smallest-weight trees are removed from the heap and are combined to form a big tree and then the new tree is added to the heap. This process continues until the heap contains just one tree, which is our final Huffman tree for the text.

The `assignCode` function assigns the code for each node in the tree (lines 98–110). The `getCode` function gets the code for each character in the leaf node (lines 115–120). The element `codes[i]` contains the code for character `(char)i`, where `i` is from `0` to `127`. 

## Self-Check
### Every internal node in a Huffman tree has two children. Is it true?
Yes.
### What is a greedy algorithm? Give an example.
A greedy algorithm is often used in solving optimization problems. The algorithm makes the choice that is optimal locally in the hope that this choice will lead to a globally optimal solution.
### How do you replace lines 59-64 in LiveExample 21.8 using one line?
```cpp
return root->weight < t.root->weight ? 1 : 
  root->weight == t.root->weight ? 0 : -1; 
```
### What happens if the input is an empty string?
The heap will be empty. It will cause an error in line 94 when performing heap->remove(). You can add an if-statement to test if the heap is empty.
# References
