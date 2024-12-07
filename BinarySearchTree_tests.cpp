#include "BinarySearchTree.hpp"
#include "unit_test_framework.hpp"
#include <sstream>
#include <iostream>

using namespace std;

TEST(test_general_1) {
  BinarySearchTree<int> tree;

  tree.insert(5);

  ASSERT_TRUE(tree.size() == 1);
  ASSERT_TRUE(tree.height() == 1);

  ASSERT_TRUE(tree.find(5) != tree.end());

  tree.insert(7);
  tree.insert(3);

  ASSERT_TRUE(tree.check_sorting_invariant());
  ASSERT_TRUE(*tree.max_element() == 7);
  ASSERT_TRUE(*tree.min_element() == 3);
  ASSERT_TRUE(*tree.min_greater_than(5) == 7);

  cout << "cout << tree.to_string()" << endl;
  cout << tree.to_string() << endl << endl;

  cout << "cout << tree" << endl << "(uses iterators)" << endl;
  cout << tree << endl << endl;

  ostringstream oss_preorder;
  tree.traverse_preorder(oss_preorder);
  cout << "preorder" << endl;
  cout << oss_preorder.str() << endl << endl;
  ASSERT_TRUE(oss_preorder.str() == "5 3 7 ");

  ostringstream oss_inorder;
  tree.traverse_inorder(oss_inorder);
  cout << "inorder" << endl;
  cout << oss_inorder.str() << endl << endl;
  ASSERT_TRUE(oss_inorder.str() == "3 5 7 ");
}

TEST(empty_tree) {
    BinarySearchTree<int> tree;
    ASSERT_TRUE(tree.height()==0);
    ASSERT_TRUE(tree.size()==0);
    ASSERT_TRUE(tree.check_sorting_invariant());
    ASSERT_TRUE(tree.find(5) == tree.end());
    ASSERT_TRUE(tree.min_element() == tree.end());
    ASSERT_TRUE(tree.max_element() == tree.end());
    ASSERT_TRUE(tree.min_greater_than(3) == tree.end());
}

TEST(copy_constructor) {
    BinarySearchTree<int> tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);

    ASSERT_TRUE(tree.size()==6);
    ASSERT_TRUE(tree.height()==6);

    BinarySearchTree<int> copy_tree(tree);
    ASSERT_TRUE(copy_tree.size()==6);
    ASSERT_TRUE(copy_tree.height()==6);

    copy_tree.insert(7);
    copy_tree.insert(8);

    ASSERT_TRUE(copy_tree.size()==8);
    ASSERT_TRUE(copy_tree.height()==8);
    ASSERT_TRUE(copy_tree.check_sorting_invariant());

    ASSERT_TRUE(tree.size()==6);
    ASSERT_TRUE(tree.height()==6);

    tree.insert(9);
    tree.insert(10);
    tree.insert(11);

    ASSERT_TRUE(tree.size()==9);
    ASSERT_TRUE(tree.height()==9);
    ASSERT_TRUE(copy_tree.size()==8);
    ASSERT_TRUE(copy_tree.height()==8);

}

TEST_MAIN()
