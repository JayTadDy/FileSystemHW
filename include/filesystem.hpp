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
  FileSecurity() {}
  FileSecurity(file_security::EncriptionType encription_type, std::uint16_t key_length, std::string encription_time)
      : encription_type_(encription_type), key_length_(key_length), encription_time_(encription_time) {}
  EncriptionType encription_type_;
  std::uint16_t key_length_;
  std::string encription_time_;
};
}  // namespace file_security

namespace filesystem_info {
class FileSystem {
 public:
  // Default contrustor
  FileSystem() {}

  // User-defined constructor with arguments
  FileSystem(std::string file_name, std::string creation_date, std::uint64_t number_of_file_accesses,
             std::string file_size, file_security::EncriptionType encription_type, std::uint16_t key_length,
             std::string encription_time)
      : file_name_(file_name),
        creation_date_(creation_date),
        number_of_file_accesses_(number_of_file_accesses),
        file_size_(file_size),
        file_security_info_(file_security::FileSecurity(encription_type, key_length, encription_time)) {}

  ~FileSystem() = default;

  // Getters
  std::string GetFileName() { return file_name_; }
  std::string GetCreationDate() { return creation_date_; }
  std::uint64_t GetNumberOfFileAccesses() { return number_of_file_accesses_; }
  std::string GetFileSize() { return file_size_; }
  file_security::FileSecurity GetFileSecurityInfo() { return file_security_info_; }

  // Setters
  void SetFileName(const std::string file_name) { file_name_ = file_name; }
  void SetCreationDate(const std::string creation_date) { creation_date_ = creation_date; }
  void SetNumberOfFileAccesses(const std::uint64_t number_of_file_accesses) {
    number_of_file_accesses_ = number_of_file_accesses;
  }
  void SetFileSize(const std::string file_size) { file_size_ = file_size; }
  void SetFileSecurityInfo(const file_security::FileSecurity file_security_info) {
    file_security_info_ = file_security_info;
  }

 private:
  std::string file_name_;
  std::string creation_date_;
  std::uint64_t number_of_file_accesses_;
  std::string file_size_;
  file_security::FileSecurity file_security_info_;
};
}  // namespace filesystem_info

#endif  // FILESYSTEM_HPP