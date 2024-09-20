/**
 * @file filesystem.hpp
 * @author Sviatoslav Trenchuk (5677304@stud.nau.edu.ua)
 * @brief Header file that contains all needed information about File system
 * @version 0.1
 * @date 2024-09-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef FILESYSTEM_HPP
#define FILESYSTEM_HPP

#include <string>

namespace file_security {
enum class EncriptionType { Symmetric = 0, Asymmetric };

struct FileSecurity {
  EncriptionType encription_type_;
  std::uint8_t key_length_;
  std::uint8_t encription_time_;
};
}  // namespace file_security

namespace filesystem_info {
class FileSystem {
 public:
  // Default contrustor
  FileSystem() {};

  // User-defined constructor
  explicit FileSystem(std::string file_name, std::string creation_date, std::uint64_t number_of_file_accesses,
                      std::uint64_t file_size, file_security::FileSecurity file_security_info);

  // // Copy Constructor
  // FileSystem(const FileSystem& other)
  //     : file_name_(other.file_name_),
  //       creation_date_(other.creation_date_),
  //       number_of_file_accesses_(other.number_of_file_accesses_),
  //       file_size_(other.file_size_),
  //       file_security_info_(other.file_security_info_) {}

  // // Copy Assignment Operator
  // FileSystem& operator=(const FileSystem& other) {
  //   if (this != &other) {
  //     file_name_ = other.file_name_;
  //     creation_date_ = other.creation_date_;
  //     number_of_file_accesses_ = other.number_of_file_accesses_;
  //     file_size_ = other.file_size_;
  //     file_security_info_ = other.file_security_info_;
  //   }
  //   return *this;
  // }

  // // Move Constructor
  // FileSystem(FileSystem&& other) noexcept {}

  // // Move Assignment Operator
  // FileSystem& operator=(FileSystem&& other) noexcept {
  //   if (this != &other) {
  //     // code here,
  //     // transfer ownership of resources.
  //   }
  //   return *this;
  // }

  ~FileSystem() = default;

  // Getters
  std::string GetFileName() { return file_name_; }
  std::string GetCreationDate() { return creation_date_; }
  std::uint64_t GetNumberOfFileAccesses() { return number_of_file_accesses_; }
  std::uint64_t GetFileSize() { return file_size_; }
  file_security::FileSecurity GetFileSecurityInfo() { return file_security_info_; }

  // Setters
  void SetFileName(const std::string file_name) {
    file_name_ = file_name;
  }
  void SetCreationDate(const std::string creation_date) {
    creation_date_ = creation_date;
  }
  void SetNumberOfFileAccesses(const std::uint64_t number_of_file_accesses) {
    number_of_file_accesses_ = number_of_file_accesses;
  }
  void SetFileSize(const std::uint64_t file_size) {
    file_size_ = file_size;
  }
  void SetFileSecurityInfo(const file_security::FileSecurity file_security_info) {
    file_security_info_ = file_security_info;
  }

 private:
  std::string file_name_;
  std::string creation_date_;
  std::uint64_t number_of_file_accesses_;
  std::uint64_t file_size_;
  file_security::FileSecurity file_security_info_;
};
}  // namespace filesystem_info

#endif  // FILESYSTEM_HPP