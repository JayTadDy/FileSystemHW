/**
 * @file main.cpp
 * @author Sviatoslav Trenchuk (5677304@stud.nau.edu.ua)
 * @brief Main file to cotrol program flow
 * @version 0.1
 * @date 2024-09-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "menu.hpp"
#include <iostream>

int main() {
  menu::Menu *menu = new menu::Menu;

  // Start the spplication
  menu->StartApp();

  std::string command = {};
  while(command != "exit") {
    std::cout << "Enter a command: ";
    std::cin >> command;
    menu->RunAppLogic(command);
  }

  delete menu;

return 0;
}