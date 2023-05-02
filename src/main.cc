/**
 * @file main.cpp
 * @author Fabrizzio Daniell Perilli Martín alu0101138589@ull.edu.es
 * @brief This file contains the main program
 * @version 0.1
 * @date 2023-04-23
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include "../include/AB.h"
#include "../include/ABB.h"
#include "../include/AVL.h"

int main()
{
    int tree_option;
    AB<long> *tree;
    do
    {
        std::cout << "---Binary Trees---" << std::endl;
        std::cout << "Choose type of tree do you want to use" << std::endl;
        std::cout << "[1] Search binary tree (ABB)" << std::endl;
        std::cout << "[2] Balanced binary search tree (AVL)" << std::endl;
        std::cout << "Option: ";
        std::cin >> tree_option;

        if (tree_option == 1)
        {
            std::cout << "You have selected ABB";
            tree = new ABB<long>();
        }
        else if (tree_option == 2)
        {
            std::cout << "You have selected AVL";
            tree = new AVL<long>();
        }
        else
            std::cout << "Invalid option, enter option again" << std::endl;
    } while (tree_option != 1 && tree_option != 2);

    std::cout << std::endl;

    int menu_option;
    do
    {
        std::cout << "\n[1] Insert key" << std::endl;
        std::cout << "[2] Search key" << std::endl;
        std::cout << "[3] Show tree inorder" << std::endl;
        std::cout << "[4] Show tree preorder" << std::endl;
        std::cout << "[0] Exit" << std::endl;
        std::cout << "Option: ";
        std::cin >> menu_option;

        long user_key;
        switch (menu_option)
        {
        case 1:
            std::cout << "Enter key: ";
            std::cin >> user_key;
            tree->insert(user_key);
            std::cout << "\nTree: " << std::endl;
            std::cout << *tree << std::endl;
            break;
        case 2:
            std::cout << "Enter key to search: ";
            std::cin >> user_key;
            if (tree->search(user_key))
                std::cout << "Key found" << std::endl;
            else
                std::cout << "Key not found" << std::endl;
            break;
        case 3:
            std::cout << "\nInorder Tree" << std::endl;
            tree->inorden();
            std::cout << std::endl;
            break;
        case 4:
            std::cout << "\nPreorder Tree" << std::endl;
            tree->preorden();
            std::cout << std::endl;
            break;
        case 0:
            exit(EXIT_SUCCESS);
            break;
        default:
            std::cout << "Invalid option, enter option again" << std::endl;
            break;
        }
    } while (menu_option != 0);

    return 0;
}