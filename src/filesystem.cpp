/**
 * @file filesystem.cpp
 * @author Sviatoslav Trenchuk (5677304@stud.nau.edu.ua)
 * @brief Header file that contains all needed information about File system
 * @version 0.1
 * @date 2024-09-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "filesystem.hpp"
#include <iostream>

namespace filesystem_info{
FileSystem::FileSystem(std::string file_name, std::string creation_date, std::uint64_t number_of_file_accesses,
                       std::uint64_t file_size, file_security::FileSecurity file_security_info)
    : file_name_{file_name},
      creation_date_{creation_date},
      number_of_file_accesses_{number_of_file_accesses},
      file_size_{file_size},
      file_security_info_{file_security_info} {
  std::cout << "File system object has been successfully created!" << std::endl;
}


}  // namespace filesystem_info
