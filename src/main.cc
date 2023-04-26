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

int main()
{
    int tree_option;
    AB<long> *tree;
    do
    {
        std::cout << "---Binary Trees---" << std::endl;
        std::cout << "Choose type of tree do you want use" << std::endl;
        std::cout << "[1] Search binary tree (ABB)" << std::endl;
        std::cout << "[2] Balanced binary search tree (AVL)" << std::endl;
        std::cout << "Option: ";
        std::cin >> tree_option;
        
        if (tree_option == 1) {
            std::cout << "ABB" << std::endl; 
            tree = new ABB<long>();
        }
        else if (tree_option == 2) {
            std::cout << "AVL" << std::endl; 
            // tree = new AVL<long>();
        }
        else
            std::cout << "Invalid option, enter option again" << std::endl; 
    }while (tree_option != 1 && tree_option != 2);

    std::cout << std::endl;

    int menu_option;
    do
    {
        std::cout << "\n[1] Insert key" << std::endl;
        std::cout << "[2] Search key" << std::endl;
        std::cout << "[3] Show tree inorden" << std::endl;
        std::cout << "[0] Exit" << std::endl;
        std::cout << "Option: ";
        std::cin >> menu_option;

        switch (menu_option)
        {
        case 1:
            long user_key;
            std::cout << "Enter key: " ;
            std::cin >> user_key; 
            tree->insert(user_key);
            std::cout << "\nTree: " << std::endl;
            std::cout << *tree << std::endl;
            break;
        case 2:
            std::cout << "Search key" << std::endl;
            break;
        case 3:
            std::cout << "Show tree inorden" << std::endl;
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