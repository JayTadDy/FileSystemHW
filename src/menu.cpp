/**
 * @file menu.cpp
 * @author Sviatoslav Trenchuk (5677304@stud.nau.edu.ua)
 * @brief Header file that contains definition for menu APi for users
 * @version 0.1
 * @date 2024-09-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "menu.hpp"

#include <iostream>

using filesystem_info::FileSystem;

namespace menu {
Menu::Menu() : available_commands() {
  files_container_ = std::make_unique<std::vector<FileSystem>>();
  available_commands = {"list", "add", "fi", "sf", "sio", "update", "rm", "clear"};
}

void Menu::Init() {
  files_container_->push_back(
      FileSystem("text", "21.09.2024", 0, "154 Kb", file_security::EncriptionType::Asymmetric, 64, "0.0001 s"));
  files_container_->push_back(
      FileSystem("passwords", "21.09.2024", 0, "1 Mb", file_security::EncriptionType::Asymmetric, 256, "0.01 s"));
  files_container_->push_back(
      FileSystem("ToDo:", "21.09.2024", 0, "387 Kb", file_security::EncriptionType::Symmetric, 64, "0.005 s"));
  files_container_->push_back(
      FileSystem("list", "21.09.2024", 0, "249 Kb", file_security::EncriptionType::Asymmetric, 128, "0.002 s"));
  files_container_->push_back(
      FileSystem("logs", "21.09.2024", 0, "1.2 Kb", file_security::EncriptionType::Symmetric, 256, "0.1 s"));
  files_container_->push_back(FileSystem("tests", "21.09.2024 15:21", 0, "879 Kb",
                                         file_security::EncriptionType::Symmetric, 128, "0.000087 s"));
  files_container_->push_back(
      FileSystem("123123", "21.09.2024", 0, "0.1 Kb", file_security::EncriptionType::Symmetric, 32, "0.00013 s"));
}

void Menu::StartApp() {
  // Set some file to works with
  Init();
  DisplayMainMenu();
}

void Menu::DisplayMainMenu() {
  std::cout << "Welcome to File System Info application!\nHow to use it you have to enter one of the following "
               "commands:"
            << std::endl;
  DisplayPossibleCommands();
}

void Menu::DisplayPossibleCommands() {
  std::cout << "List of available commands:\n\t1. list - to Show all the existing files\n\t"
               "2. add - to add the info about a file\n\t"
               "3. fi - To show all the info about the file you want to see\n\t"
               "4. sf - to display all the files starting from the needed index\tNOTE."
               "All files are sorted and numbered\n\t"
               "5. sio - To display info in the following order.\n\t"
               "6. update - to update files information\n\t"
               "7. rm - to remove the file\n\t"
               "8. clear - to delete all the information.\n\t"
               "9. exit - to stop the program!"
            << std::endl;
}

void Menu::AddFile() {
  std::string file_name;
  std::cout << "Enter file name: ";
  std::cin >> file_name;
  std::cout << std::endl;

  std::string creation_date;
  std::cout << "Enter creation date in format dd.mm.yyyy: ";
  std::cin >> creation_date;
  std::cout << std::endl;

  std::uint64_t number_of_file_accesses;
  std::cout << "Enter the number of file accesses: ";
  std::cin >> number_of_file_accesses;
  std::cout << std::endl;

  std::string file_size;
  std::cout << "Enter expected file size: ";
  std::cin >> file_size;
  std::cout << std::endl;

  bool encryption_type_command;
  file_security::EncriptionType encription_type;
  std::cout << "Select the encription type for file:\n\t0 - for Symmetric\n\t1 - for Assymetric ";
  std::cin >> encryption_type_command;
  std::cout << std::endl;
  if (encryption_type_command) {
    encription_type = file_security::EncriptionType::Asymmetric;
  } else {
    encription_type = file_security::EncriptionType::Symmetric;
  }

  std::uint16_t key_length;
  std::cout << "Select the expected key size in bits: 32, 64, 128, 256 ";
  std::cin >> key_length;

  std::string encription_time;
  std::cout << "Enter expected encription_time: ";
  std::cin >> encription_time;
  std::cout << std::endl;

  files_container_->push_back(FileSystem(file_name, creation_date, number_of_file_accesses, file_size, encription_type,
                                         key_length, encription_time));
}

bool Menu::IncorrectCommand(std::string input_command) {
  if (std::find(available_commands.begin(), available_commands.end(), input_command) < available_commands.end()) {
    return false;
  } else {
    std::cout << "Command is not correct, be attentive, please!" << std::endl;
    return true;
  }
}

void Menu::RemoveFileInfo(std::uint16_t file_index) {
  if (IsEmpty()) {
    std::cout << "There is no files to remove!" << std::endl << std::endl;
  } else {
    files_container_->erase(files_container_->begin() + file_index);
    std::cout << "File removed!" << std::endl << std::endl;
  }
}

void Menu::ClearAllFilesInfo() {
  if (IsEmpty()) {
    std::cout << "Already clear!" << std::endl;
  } else {
    files_container_->clear();
    std::cout << "Deleted successfully!" << std::endl << std::endl;
    ;
  }
}

void Menu::UpdateFileInfo(std::uint16_t file_index) {
  if (IsEmpty()) {
    std::cout << "There is no files to update!" << std::endl << std::endl;
  } else {
    std::string file_name;
    std::cout << "Enter file name: ";
    std::cin >> file_name;
    std::cout << std::endl;

    std::string creation_date;
    std::cout << "Enter creation date in format dd.mm.yyyy: ";
    std::cin >> creation_date;
    std::cout << std::endl;

    std::uint64_t number_of_file_accesses;
    std::cout << "Enter the number of file accesses: ";
    std::cin >> number_of_file_accesses;
    std::cout << std::endl;

    std::string file_size;
    std::cout << "Enter expected file size: ";
    std::cin >> file_size;
    std::cout << std::endl;

    bool encryption_type_command;
    file_security::EncriptionType encription_type;
    std::cout << "Select the encription type for file:\n\t1.0 - for Symmetric\n\t1. - for Assymetric ";
    std::cin >> encryption_type_command;
    std::cout << std::endl;
    if (encryption_type_command) {
      encription_type = file_security::EncriptionType::Asymmetric;
    } else {
      encription_type = file_security::EncriptionType::Symmetric;
    }

    std::uint16_t key_length;
    std::cout << "Select the expected key size in bits: 32, 64, 128, 256 ";
    std::cin >> key_length;
    std::cout << std::endl;
    while ((key_length != 32) || (key_length != 64) || (key_length != 128) || (key_length != 256)) {
      std::cout << "Enter the correct value which is one of the following: 32, 64, 128, 256: ";
      std::cin >> key_length;
      std::cout << std::endl;
    }

    std::string encription_time;
    std::cout << "Enter expected encription_time: ";
    std::cin >> encription_time;
    std::cout << std::endl;

    files_container_->at(file_index) = FileSystem(file_name, creation_date, number_of_file_accesses, file_size,
                                                  encription_type, key_length, encription_time);
    std::cout << std::endl;
  }
}

void Menu::DisplayAllFilesList() {
  if (IsEmpty()) {
    std::cout << "There is no files!" << std::endl << std::endl;
  } else {
    std::cout << "Files: " << std::endl;
    for (std::uint16_t index = 0; index < files_container_->size(); ++index) {
      std::cout << index << ". " << files_container_->at(index).GetFileName() << std::endl;
    }
    std::cout << std::endl;
  }
}

void Menu::DisplayFileInfo(std::uint16_t file_index) {
  if (IsEmpty()) {
    std::cout << "There is no files!" << std::endl << std::endl;
  } else {
    std::cout << "There is an information about file you are looking for:\n"
                 "File name: "
              << files_container_->at(file_index).GetFileName()
              << "\nCreation date: " << files_container_->at(file_index).GetCreationDate()
              << "\nNumber of file accesses: " << files_container_->at(file_index).GetNumberOfFileAccesses()
              << "\nFile size: " << files_container_->at(file_index).GetFileSize()
              << "\nFile security info:\n\tEncryption type: "
              << static_cast<bool>(files_container_->at(file_index).GetFileSecurityInfo().encription_type_)
              << "\n\tKey length: " << files_container_->at(file_index).GetFileSecurityInfo().key_length_
              << "\n\tEncryption time: " << files_container_->at(file_index).GetFileSecurityInfo().encription_time_
              << std::endl;
    std::cout << std::endl;
  }
}

void Menu::DisplayAllFilesInfo(std::uint16_t start_index) {
  if (IsEmpty()) {
    std::cout << "There is no files" << std::endl << std::endl;
  } else {
    for (; start_index < files_container_->size(); ++start_index) {
      DisplayFileInfo(start_index);
    }
    std::cout << std::endl;
  }
}

void Menu::DisplayInOrder(std::uint16_t order) {
  if (IsEmpty()) {
    std::cout << "There is no files" << std::endl << std::endl;
  } else {
    switch (order) {
      case 0:
        DisplayAllFilesInfo();
        break;
      case 1:
        for (std::uint16_t index = files_container_->size(); index > 0; index--) {
          DisplayFileInfo(index - 1);
        }
        break;
      default:
        std::cout << "Input order is not correct!" << std::endl;
        break;
    }
    std::cout << std::endl;
  }
}

bool Menu::IsEmpty() {
  if (files_container_->size() == 0) {
    return true;
  } else {
    return false;
  }
}

void Menu::RunAppLogic(std::string input_command) {
  std::cout << std::endl;
  if (input_command == "list") {
    DisplayAllFilesList();
    DisplayPossibleCommands();
  } else if (input_command == "add") {
    AddFile();
    DisplayPossibleCommands();
  } else if (input_command == "fi") {
    std::uint16_t file_index;
    std::cout << "File list: " << std::endl;
    DisplayAllFilesList();
    std::cout << "Enter file index you want to see: " << std::endl;
    std::cin >> file_index;
    std::cout << std::endl;
    DisplayPossibleCommands();
    DisplayFileInfo(file_index);
  } else if (input_command == "sf") {
    std::uint16_t file_index;
    std::cout << "File list: " << std::endl;
    DisplayAllFilesList();
    std::cout << "Enter file index you want to start with: " << std::endl;
    std::cin >> file_index;
    std::cout << std::endl;
    DisplayAllFilesInfo(file_index);
    DisplayPossibleCommands();
  } else if (input_command == "sio") {
    std::uint16_t order;
    std::cout << "Enter a number in which order you want to see files info:\n\t0 - direct order;\n\t1 - reverse order"
              << std::endl;
    std::cin >> order;
    std::cout << std::endl;
    DisplayInOrder(order);
    DisplayPossibleCommands();
  } else if (input_command == "update") {
    std::uint16_t file_index;
    std::cout << "File list: " << std::endl;
    DisplayAllFilesList();
    std::cout << "Enter file index you want to update: " << std::endl;
    std::cin >> file_index;
    std::cout << std::endl;
    UpdateFileInfo(file_index);
    DisplayPossibleCommands();
  } else if (input_command == "rm") {
    std::uint16_t file_index;
    std::cout << "File list: " << std::endl;
    DisplayAllFilesList();
    std::cout << "Enter file index you want to remove: " << std::endl;
    std::cin >> file_index;
    std::cout << std::endl;
    RemoveFileInfo(file_index);
    DisplayPossibleCommands();
  } else if (input_command == "clear") {
    ClearAllFilesInfo();
    DisplayPossibleCommands();
  } else if (input_command == "exit") {
    Exit();
  } else if (IncorrectCommand(input_command)) {
    DisplayPossibleCommands();
  }
  std::cout << std::endl;
}

void Menu::Exit() {
  if (IsEmpty()) {
    std::cout << "There is no information to clear!" << std::endl;
  } else {
    // Clear all the information about files
    files_container_->clear();
    std::cout << "Data is cleaned up!" << std::endl;
  }
}
}  // namespace menu