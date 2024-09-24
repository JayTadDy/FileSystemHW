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
Menu::Menu() : command_{}, is_running_{0}, available_commands{} {
  files_container_ = std::make_unique<std::vector<FileSystem>>(nullptr);
  available_commands = {"list", "file info", "show from", "show sequence", "add", "update", "rm", "clear"};
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
  is_running_ = 1;

  // Set some file to works with
  Init();
  DisplayMainMenu();
  RunAppLogic();
}

void Menu::DisplayMainMenu() {
  std::cout << "Welcome to File System Info application!\nHow to use it you have to enter one of the following "
               "commands:"
            << std::endl;
  DisplayPossibleCommands();
}

void Menu::DisplayPossibleCommands() {
  std::cout << "List of available commands:\n\t1.list - to Show all the existing files\n\t2. file info <file name> - "
               "To show all the info about the file you want to see\n\t3. show all - to display all the info for all "
               "existing files\n\t"
               "4. show from <start_index> - to display all the files starting from the needed index\tNOTE. "
               "All files are sorted and numbered\n\t5.show sequence <indexs...> - To display info in the following "
               "sequence.\tNOTE. You have to enter indexs in range [0;"
            << files_container_->size() << "]\n\t7. add - to add the info about a file" << std::endl;

  // TO DO: Add a back() command to return to main menu
}

void Menu::AddFile(std::string file_name, std::string creation_date, std::uint64_t number_of_file_accesses = 0,
                   std::string file_size, file_security::EncriptionType encription_type, std::uint8_t key_length,
                   std::string encription_time) {
  if (command_ == "add") {
    std::cout << "Enter file name: ";
    std::cin >> file_name;
    std::cout << std::endl;

    std::cout << "Enter creation date in format dd.mm.yyyy: ";
    std::cin >> creation_date;
    std::cout << std::endl;

    std::cout << "Enter the number of file accesses: ";
    std::cin >> number_of_file_accesses;
    std::cout << std::endl;

    std::cout << "Enter expected file size: ";
    std::cin >> file_size;
    std::cout << std::endl;

    bool encryption_type_command{};
    std::cout << "Select the encription type for file:\n\t1.0 - for Symmetric\n\t1. - for Assymetric ";
    std::cin >> encryption_type_command;
    std::cout << std::endl;
    if (encryption_type_command) {
      encription_type = file_security::EncriptionType::Asymmetric;
    } else {
      encription_type = file_security::EncriptionType::Symmetric;
    }

    std::cout << "Select the expected key size in bits: 32, 64, 128, 256 ";
    std::cin >> key_length;
    std::cout << std::endl;
    while ((key_length != 32) || (key_length != 64) || (key_length != 128) || (key_length != 256)) {
      std::cout << "Enter the correct value which is one of the following: 32, 64, 128, 256: ";
      std::cin >> key_length;
      std::cout << std::endl;
    }

    std::cout << "Enter expected encription_time: ";
    std::cin >> encription_time;
    std::cout << std::endl;

    files_container_->push_back(FileSystem(file_name, creation_date, number_of_file_accesses, file_size,
                                           encription_type, key_length, encription_time));
  } else {
    while (IncorrectCommand(command_)) {
      DisplayPossibleCommands();
    }
  }
}

bool Menu::IncorrectCommand(std::string input_command) {
  if (std::find(available_commands.begin(), available_commands.end(), input_command) < available_commands.end()) {
    return false;
  } else {
    std::cout << "Command is not correct, be attentive, please!" << std::endl;
    return true;
  }
}

void Menu::RemoveFileInfo(std::uint8_t file_index) {
  if (IsEmpty()) {
    std::cout << "There is no files to remove!" << std::endl;
  } else {
    files_container_->erase(files_container_->begin() + file_index);
  }
}

void Menu::ClearAllFilesInfo() {
  if (IsEmpty()) {
    std::cout << "Already clear!" << std::endl;
  } else {
    files_container_->clear();
  }
}

void Menu::UpdateFileInfo(std::string file_name, std::string creation_date, std::uint64_t number_of_file_accesses,
                          std::string file_size, file_security::EncriptionType encription_type, std::uint8_t key_length,
                          std::string encription_time, std::uint8_t file_index) {
  if (IsEmpty()) {
    std::cout << "There is not files to update!" << std::endl;
  } else {
    std::cout << "Enter file name: ";
    std::cin >> file_name;
    std::cout << std::endl;

    std::cout << "Enter creation date in format dd.mm.yyyy: ";
    std::cin >> creation_date;
    std::cout << std::endl;

    std::cout << "Enter the number of file accesses: ";
    std::cin >> number_of_file_accesses;
    std::cout << std::endl;

    std::cout << "Enter expected file size: ";
    std::cin >> file_size;
    std::cout << std::endl;

    bool encryption_type_command{};
    std::cout << "Select the encription type for file:\n\t0 - for Symmetric\n\t1. - for Assymetric ";
    std::cin >> encryption_type_command;
    std::cout << std::endl;
    if (encryption_type_command) {
      encription_type = file_security::EncriptionType::Asymmetric;
    } else {
      encription_type = file_security::EncriptionType::Symmetric;
    }

    std::cout << "Select the expected key size in bits: 32, 64, 128, 256 ";
    std::cin >> key_length;
    std::cout << std::endl;
    while ((key_length != 32) || (key_length != 64) || (key_length != 128) || (key_length != 256)) {
      std::cout << "Enter the correct value which is one of the following: 32, 64, 128, 256: ";
      std::cin >> key_length;
      std::cout << std::endl;
    }

    std::cout << "Enter expected encription_time: ";
    std::cin >> encription_time;
    std::cout << std::endl;

    files_container_->at(file_index) = FileSystem(file_name, creation_date, number_of_file_accesses, file_size,
                                                  encription_type, key_length, encription_time);
  }
}

void Menu::DisplayAllFilesList() {
  if (IsEmpty()) {
    std::cout << "There is no files!" << std::endl;
  } else {
    for (std::uint8_t index = 0; index < files_container_->size(); ++index) {
      std::cout << index << ". " << files_container_->at(index).GetFileName() << std::endl;
    }
  }
}

void Menu::DisplayFileInfo(std::uint8_t file_index) {
  if (IsEmpty()) {
    std::cout << "There is no files!" << std::endl;
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
  }
}

void Menu::DisplayAllFilesInfo(std::uint8_t start_index) {
  if (IsEmpty()) {
    std::cout << "There is not files" << std::endl;
  } else {
    for (; start_index < files_container_->size(); ++start_index) {
      DisplayFileInfo(start_index);
    }
  }
}

void Menu::DisplayInOrder(bool order) {
  if (IsEmpty()) {
    std::cout << "There is not files" << std::endl;
  } else {
    switch (order) {
      case 0:
        DisplayAllFilesInfo();
        break;
      case 1:
        for (std::uint8_t index = files_container_->size(); index > 0; --index) {
          DisplayFileInfo(index);
        }
        break;
      default:
        std::cout << "Input order is not correct!" << std::endl;
        break;
    }
  }
}

bool Menu::IsEmpty() {
  if (files_container_->size() == 0) {
    return true;
  } else {
    return false;
  }
}

void Menu::RunAppLogic() {
  
}

void Menu::Exit() {
  // Indicates that programm is not running anymore;
  is_running_ = 0;

  if (!IsEmpty()) {
    // Clear all the information about files
    files_container_->clear();
  }
}
}  // namespace menu