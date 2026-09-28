/**************************************

Mã sinh viên: 202419074
Họ tên: Vũ Thành Lâm
**************************************/

#include "SoftwareEngineer.h"
#include <iostream>
#include <stdexcept>

// Constructor 1
SoftwareEngineer::SoftwareEngineer(
    const std::string& id,
    const std::string& fullName,
    const std::string& primaryLanguage)
    : Employee(id, fullName),
      primaryLanguage(primaryLanguage),
      technicalAllowance(0)
{
    if (primaryLanguage.empty())
    {
        throw std::invalid_argument(
            "Primary programming language cannot be empty."
        );
    }

    std::cout << "SoftwareEngineer constructor 1 called.\n";
}

// Constructor 2
SoftwareEngineer::SoftwareEngineer(
    const std::string& id,
    const std::string& fullName,
    double baseSalary,
    const std::string& primaryLanguage,
    double technicalAllowance)
    : Employee(id, fullName, baseSalary),
      primaryLanguage(primaryLanguage),
      technicalAllowance(technicalAllowance)
{
    if (primaryLanguage.empty())
    {
        throw std::invalid_argument(
            "Primary programming language cannot be empty."
        );
    }

    if (technicalAllowance < 0)
    {
        throw std::invalid_argument(
            "Technical allowance cannot be negative."
        );
    }

    std::cout << "SoftwareEngineer constructor 2 called.\n";
}

// Destructor
SoftwareEngineer::~SoftwareEngineer()
{
    std::cout << "SoftwareEngineer destructor called: "
              << id << " - " << fullName << "\n";
}

// Getter ngôn ngữ lập trình chính
std::string SoftwareEngineer::getPrimaryLanguage() const
{
    return primaryLanguage;
}

// Getter phụ cấp kỹ thuật
double SoftwareEngineer::getTechnicalAllowance() const
{
    return technicalAllowance;
}

// Tính tổng chi phí hàng tháng
double SoftwareEngineer::calculateMonthlyCost() const
{
    return baseSalary + technicalAllowance;
}

// Hiển thị thông tin
void SoftwareEngineer::displayInfo() const
{
    std::cout << "Software Engineer Information\n";
    std::cout << "ID: " << id << "\n";
    std::cout << "Full name: " << fullName << "\n";
    std::cout << "Base salary: " << baseSalary << "\n";
    std::cout << "Primary language: " << primaryLanguage << "\n";
    std::cout << "Technical allowance: " << technicalAllowance << "\n";
    std::cout << "Monthly cost: "
              << calculateMonthlyCost() << "\n";
}
