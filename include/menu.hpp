/**
 * @file menu.hpp
 * @author Sviatoslav Trenchuk (5677304@stud.nau.edu.ua)
 * @brief Header file that contains declaration for menu APi for users
 * @version 0.1
 * @date 2024-09-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef MENU_HPP_
#define MENU_HPP_

#include <vector>

#include "filesystem.hpp"

namespace menu {
class Menu {
 public:
  Menu();
  ~Menu() = default;

  /**
   * @brief Method to start the application.
   * Runs Main Menu where all needed information is displayed
   * Runs default initialization of files to work with
   */
  void StartApp();

  /**
   * @brief Methods to control the actions of program
   * Stops when "exit" command is called
   */
  void RunAppLogic(std::string input_command);

  /**
   * @brief Method to exit the aplication
   * Clears all files and info about them
   */
  void Exit();

 private:
  /**
   * @brief Sets initial information about the files to work with
   */
  void Init();

  /**
   * @brief Method to add the file and information about it
   * File will be numbered and added as the last one in the list of existing files
   */
  void AddFile();

  /**
   * @brief Methods to update the info about specific file
   *
   * @param file_idex used to indicate which file to update
   */
  void UpdateFileInfo(std::uint8_t file_index);

  /**
   * @brief Method to display main menu with all needed information
   */
  void DisplayMainMenu();

  /**
   * @brief Method to display the list of all existing files
   */
  void DisplayAllFilesList();

  /**
   * @brief Internal method to display possible commands
   *        Used in main menu and in case of icorrect command is entered
   */
  void DisplayPossibleCommands();

  /**
   * @brief Method to display information about a single file which is indicated by input index
   *
   * @param file_index
   */
  void DisplayFileInfo(std::uint8_t file_index);

  /**
   * @brief Method to display info about all files starting input index
   *
   * @param start_index By default = 0 to show all files if nothing is entered
   */
  void DisplayAllFilesInfo(std::uint8_t start_index = 0);

  /**
   * @brief Method to display file info in order entered by user
   *
   */
  void DisplayInOrder(std::uint8_t order);

  /**
   * @brief Method to infomation for a single file
   *
   * @param file_index used to indicate which file to remove
   */
  void RemoveFileInfo(std::uint8_t file_index);

  /**
   * @brief Method to remove all information for all files
   */
  void ClearAllFilesInfo();

  /**
   * @brief Method to detect if the input command is correct to use
   *
   * @param imput_command - argument to check
   * @return true if command is incorrect
   * @return false  if command if correct
   */
  bool IncorrectCommand(std::string imput_command);

  /**
   * @brief Methods to check if there is any files in array
   *
   * @return true if there is no files
   * @return false owtherwise
   */
  bool IsEmpty();

  std::vector<std::string> available_commands;
  std::unique_ptr<std::vector<filesystem_info::FileSystem>> files_container_;
};
}  // namespace menu

#endif  // MENU_HPP_